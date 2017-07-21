/*
*/

#include <string.h>
#include <net/if_arp.h>

#include <xdpdk.h>

#include "format.h"
#include "xconfig.h"
#include "xvendor.h"
#include "xpint.h"
#include "xpacket.h"
#include "xarp.h"
#include "xroute.h"
#include "xfire.h"
#include "xproto.h"
#include "xnet.h"


/*
**  Address Resolution Protocol
**  Internet Protocol (IPv4) over Ethernet ARP packet
**
**   0  Hardware type (HTYPE) 16         : This field specifies the network protocol type. Example: Ethernet is 1.
**  16  Protocol type (PTYPE) 16         : This field specifies the internetwork protocol for which the ARP request is intended.
**                                         For IPv4, this has the value 0x0800.
**  32  Hardware address length (HLEN) 8 : Length (in octets) of a hardware address. Ethernet addresses size is 6.
**  40  Protocol address length (PLEN) 8 : Length (in octets) of addresses used in the upper layer protocol. IPv4 address size is 4.
**  48  Operation (OPER) 16              : Specifies the operation that the sender is performing: 1 for request, 2 for reply.
**  64  Sender hardware address (SHA) 48 : media address of the sender.
** 112  Sender protocol address (SPA) 32 : internetwork address of the sender.
** 144  Target hardware address (THA) 48 : media address of the intended receiver. This field is ignored in requests.
** 192  Target protocol address (TPA) 32 : internetwork address of the intended receiver.
*/ 

#define XARP_TABLE_SIZE 256

#define POISON_THRESHOLD   10
#define BADNET_THRESHOLD  -10


#ifdef XARP_MAC
static XRBTR64 *mac_table = NULL;
static ub32 mac_update;
#endif

static XRBTR32 *arp_table = NULL;
static XRBTR32 *virtual_table = NULL;

static ub32 arp_update;
static ub32 arp_cache_timeout  = XNET_ARP_CACHE_TIMEOUT;

#define XARP_TIMER_TIME 2
static time_t xarp_timer;


static const ub8 ethnull[6] = {0, 0, 0, 0, 0, 0};

/* Broadcast ethernet addresses */
static const ub8 etherbcast[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };


void xarp_set_cache_timeout (int timeout)
{
  arp_cache_timeout = timeout;
}


void xarp_save_arp_info (void)
{
  FILE *fp;
  XARP *a;
  char ip[IPV4_STR_SIZE];
  char mac[MAC_STR_SIZE];

  if ((fp = fopen(XFIRE_ARP_INFO_FILE, "w+"))) {

    if ((a = (XARP *)xrbt32_first(arp_table))) do {
      if (a->xdev && a->xdev->xdev) 
        fprintf(fp, "port=%d ip=%s mac=%s\n", a->xdev->portid, intoab(a->ip, ip), etheraddr_stringb(a->mac, mac));
    } while ((a = (XARP *)xrbt32_next((XRBTN32 *)a)));

    fclose(fp);
  }
}

void xarp_load_arp_info (void)
{
  FILE *fp;

  if ((fp = fopen(XFIRE_ARP_INFO_FILE, "r"))) {
    char buf[1024], mac[64], ip[32];
    XARP *arp;
    xdevice *xdev;
    int port, new;
    ub32 ipaddr;
    time_t ct = time(NULL);
    
    while (fgets(buf, sizeof(buf), fp)) {
      if (buf[0] == '#'|| buf[0] == '\n') continue;

      if (sscanf(buf, "port=%d ip=%s mac=%s\n", &port, ip, mac) == 3) {

        if ((xdev = xpacket_get_xdevice(port)) == NULL) continue;
        ipaddr = atoin(ip);

        arp = (XARP *)xrbt32_insert(arp_table, ipaddr, &new);
        if (new) {
          arp->ip = ipaddr;
          arp->xdev = xdev;
          rte_memcpy(arp->mac, string_etheraddr((ub8 *)mac), XETHER_ADDR_LEN);
          arp->htime = ct;
        }
      }
    }   
    fclose(fp);
  }
}

#ifdef XARP_MAC
void xarp_save_mac_info (void)
{
  FILE *fp;
  XMAC *m;
  char mac[MAC_STR_SIZE];

  if ((fp = fopen(XFIRE_MAC_INFO_FILE, "w+"))) {

    if ((m = (XMAC *)xrbt64_first(mac_table))) do {
      if (m->xdev && m->xdev->xdev) 
        fprintf(fp, "dev=%s mac=%s\n", m->xdev->xdev, etheraddr_stringb(m->mac, mac));
    } while ((m = (XMAC *)xrbt64_next((XRBTN64 *)m)));

    fclose(fp);
  }
}

void xarp_load_mac_info (void)
{
  FILE *fp;
  if ((fp = fopen(XFIRE_MAC_INFO_FILE, "r"))) {
    char buf[1024],  mac[64], *sm;
    xdevice *xdev;
    XMAC *xmac;
    int port, new;
    ub64 m;
    time_t ct = time(NULL);

    while (fgets(buf, sizeof(buf), fp)) {
      if (buf[0] == '#'|| buf[0] == '\n') continue;

      if (sscanf(buf, "port=%d mac=%s\n", &port, mac) == 2) {
        if ((xdev = xpacket_get_xdevice(port)) == NULL) continue;
        sm = string_etheraddr((ub8 *)mac);
        m = xpntoh48(sm);
        xmac = (XMAC *)xrbt64_insert(mac_table, m, &new);
        if (new) {
          xmac->xdev = xdev;
          rte_memcpy(xmac->mac, sm, XETHER_ADDR_LEN);
          xmac->htime = ct;
        }
      }
    }
    fclose(fp);
  }
}
#endif

static void xarp_check_timeouts (time_t ct)
{
  if (xarp_timer  < ct) {
    XARP *arp;

    if ((arp = (XARP *)xrbt32_first(arp_table))) do {
      if (arp->type == 0 && arp->htime + arp_cache_timeout < ct) {
        xrbt32_remove(arp_table, (XRBTN32 *)arp);
        arp_update++;
      }
    } while ((arp = (XARP *)xrbt32_next((XRBTN32 *)arp)));
    if (arp_update) { xarp_save_arp_info(); arp_update = 0; }

#ifdef XARP_MAC
    XMAC *mac;
    if ((mac = (XMAC *)xrbt64_first(mac_table))) do {
      if (mac->htime + arp_cache_timeout < ct) {
        xrbt64_remove(mac_table, (XRBTN64 *)mac);
        mac_update++;
      }
    } while ((mac = (XMAC *)xrbt64_next((XRBTN64 *)mac)));
    if (mac_update) { xarp_save_mac_info(); mac_update = 0; }
#endif
    xarp_timer = ct + XARP_TIMER_TIME;
  }
}

/* xfire_read_lock, xfree, xfire_read_unlock */
XARP **xarp_get_table_array (int *xarp_cnt)
{
  XARP **table, **tptr, *xp;
  int cnt = 0, mcnt = xrbt32_count(arp_table);
  *xarp_cnt = mcnt;
  if (mcnt == 0) return NULL;

  table = (XARP **)xmalloc(sizeof(XARP *) * mcnt);
  tptr = table;
  if ((xp = (XARP *)xrbt32_first(arp_table))) do {
    *tptr++ = xp; cnt++; 
  } while ((xp = (XARP *)xrbt32_next((XRBTN32 *)xp)));
  *xarp_cnt = cnt;
  return (XARP **)table;
}

#ifdef XARP_MAC
/* xfire_read_lock, xfree, xfire_read_unlock */
XMAC **xarp_get_xmac_table_array (int *xmac_cnt)
{
  XMAC **table, **tptr, *xp;
  int cnt = 0, mcnt = xrbt64_count(mac_table);
  *xmac_cnt = mcnt;
  if (mcnt == 0) return NULL;

  table = (XMAC **)xmalloc(sizeof(XMAC *) * mcnt);
  tptr = table;
  if ((xp = (XMAC *)xrbt64_first(arp_table))) do {
    *tptr++ = xp; cnt++;
  } while ((xp = (XMAC *)xrbt64_next((XRBTN64 *)xp)));
  *xmac_cnt = cnt;
  return (XMAC **)table;
}
#endif


XARP *xarp_find_by_ip (ub32 ipaddr, time_t ct)
{
  XARP *arp;
  arp = (XARP *)xrbt32_search(arp_table, ipaddr);
  if (arp) arp->htime = ct;
  return arp;
}

xdevice *xarp_find_xdev_by_ip (ub32 ipaddr)
{
  XARP *arp = xarp_find_by_ip(ipaddr, time(NULL));
  if (arp) return arp->xdev;
  return NULL;
}

ub8 *xarp_find_mac_by_ip (ub32 ipaddr, time_t ct)
{
  XARP *arp = xarp_find_by_ip(ipaddr, ct);
  arp = (XARP *)xrbt32_search(arp_table, ipaddr);
  if (arp) return arp->mac;
  return NULL;
}

void xarp_add_arp (ub32 ipaddr, ub8 *mac)
{
  XARP *arp;
  int new;
  arp = (XARP *)xrbt32_insert(arp_table, ipaddr, &new);
  if(new) {
    rte_memcpy(arp->mac, mac, XETHER_ADDR_LEN);
    arp->htime = time(NULL);
    xarp_save_arp_info();
  }
}

void xarp_del_arp (ub32 ipaddr)
{
  XARP *arp;

  if ((arp = (XARP *)xrbt32_search(arp_table, ipaddr))) {
    xrbt32_remove(arp_table, (XRBTN32 *)arp);
    xarp_save_arp_info();
  }
}

void xarp_del_arp_type (ub32 ipaddr, ub8 type)
{
  XARP *arp;

  if ((arp = (XARP *)xrbt32_search(arp_table, ipaddr))) {
    if (arp->type == type) {
      xrbt32_remove(arp_table, (XRBTN32 *)arp);
      xarp_save_arp_info();
    } else {
      arp->type |= ~type;
    }
  }
}

void xarp_update_arp (ub32 ipaddr, ub8 *mac)
{
  XARP *arp;
  arp = (XARP *)xrbt32_search(arp_table, ipaddr);
  if (arp) rte_memcpy(arp->mac, mac, XETHER_ADDR_LEN);
  xarp_save_arp_info();
}

void xarp_add_dev_ip (ub32 ip, ub8 *mac, ub8 portid, ub8 type)
{
  XARP *arp;
  xdevice *xdev;
  int new;

  if (!ip || !mac) return;
  if ((xdev = xpacket_get_xdevice(portid)) == NULL) return;
 
  arp = (XARP *)xrbt32_insert(arp_table, ip, &new);
  if (new) {
    arp->ip   = ip;
    arp->xdev = xdev;
    rte_memcpy(arp->mac, mac, XETHER_ADDR_LEN);
  }
  arp->type |= type;
  arp->htime = time(NULL);
  arp_update++;
}

void xarp_put_dev_ip (ub32 ip, ub8 *mac, ub8 portid)
{
  XARP *arp;
  xdevice *xdev;
  int new;

  if (!ip || !mac) return;
  if ((xdev = xpacket_get_xdevice(portid)) == NULL) return;

  arp = (XARP *)xrbt32_insert(arp_table, ip, &new);
  if (new) {
    arp->ip   = ip;
    arp->xdev = xdev;
    rte_memcpy(arp->mac, mac, XETHER_ADDR_LEN);
  }
  arp->htime = time(NULL);
  arp_update++;
}



#ifdef XARP_MAC
xdevice *xarp_find_by_mac (ub8 *macaddr)
{
  XMAC *m;
  ub64 mac = xpntoh48(macaddr);
  m = (XMAC *)xrbt64_search(mac_table, mac);
  if (m) return m->xdev;

  return NULL;
}

void xarp_add_dev_mac (ub8 *xmac, xdevice *xdev, time_t ct)
{
  ub64 mac;
  XMAC *m;
  int new;

  mac = xpntoh48(xmac);
  m = (XMAC *)xrbt64_insert(mac_table, mac, &new);
  if (new) rte_memcpy(m->mac, xmac, XETHER_ADDR_LEN);
  m->xdev = xdev;
  m->htime = ct;
  mac_update++;
}

void xarp_put_dev_mac (ub8 *xmac, xdevice *xdev, time_t ct)
{
  if (!xmac || !xdev) return;

  int new;
  ub64 mac;
  XMAC *m;

  mac = xpntoh48(xmac);
  m = (XMAC *)xrbt64_insert(mac_table, mac, &new);
  if (new) {
    rte_memcpy(m->mac, xmac, XETHER_ADDR_LEN);
    m->xdev = xdev;
    m->htime = ct;
  }
}
#endif

/* tcpdump arp
00:1e:67:12:0d:e8 > ff:ff:ff:ff:ff:ff, ethertype ARP (0x0806), length 42: Ethernet (len 6), IPv4 (len 4), 
Request who-has 192.168.10.222 tell 192.168.10.180, length 28
        0x0000:  0001 0800 0604 0001 001e 6712 0de8 c0a8  ..........g.....
        0x0010:  0ab4 0000 0000 0000 c0a8 0ade            ............

90:2b:34:dd:a0:1a > 00:1e:67:12:0d:e8, ethertype ARP (0x0806), length 60: Ethernet (len 6), IPv4 (len 4), 
Reply 192.168.10.222 is-at 90:2b:34:dd:a0:1a, length 46
        0x0000:  0001 0800 0604 0002 902b 34dd a01a c0a8  .........+4.....
        0x0010:  0ade 001e 6712 0de8 c0a8 0ab4 0000 0000  ....g...........
        0x0020:  0000 0000 0000 0000 0000 0000 0000       ..............
*/

void xarp_make_request_packet (xpacket *xp, ub8 *src_mac, ub32 src_ip, ub32 dst_ip)
{
  printf("xarp_make_request_packet : smac = %s, src_ip = %s, dst_ip = %s\n", etheraddr_string(src_mac), intoa(src_ip), intoa(dst_ip));

  XARP *xarp;
  ub8 smac[XETHER_ADDR_LEN];
  rte_memcpy(smac, src_mac, XETHER_ADDR_LEN);

  xp->p_ethh = (struct x_ethernet_hdr *)xp->frame;
  xp->pkt_ptr = xp->frame;
  xp->pkt_type = XPACKET_ETH | XPACKET_ARP;
  xp->pkt_len =  X_ETH_H  + X_ARP_ETH_IP_H;  /* 14 + 28 */
  xp->data_len = 0;

  memset(xp->frame, 0, xp->pkt_len);

  if ((xarp = xarp_find_by_ip(dst_ip, xp->ts.tv_sec))) {
    rte_memcpy(xp->p_ethh->ether_dhost, xarp->mac, XETHER_ADDR_LEN);
  } else {
    rte_memcpy(xp->p_ethh->ether_dhost, etherbcast, XETHER_ADDR_LEN);
  }
  rte_memcpy(xp->p_ethh->ether_shost, smac, XETHER_ADDR_LEN);

  xp->p_ethh->ether_type = htons(ETHERTYPE_ARP);

  XALIGNPOINTERS_ARP(xp->p_ethh, xp->p_arph);
  xp->p_arph->ar_hrd = htons(ARPHRD_ETHER);
  xp->p_arph->ar_pro = htons(ETHERTYPE_IP);
  xp->p_arph->ar_hln = 6;  /* mac len */
  xp->p_arph->ar_pln = 4;  /* ip len */
  xp->p_arph->ar_op  = htons(ARPOP_REQUEST);

  XALIGNPOINTERS_ARP_BODY(xp->p_arph, xp->p_arp_body);
  rte_memcpy(xp->p_arp_body->arp_sha,  src_mac, XETHER_ADDR_LEN);
  xphtonl(xp->p_arp_body->arp_spa, src_ip);

  rte_memcpy(xp->p_arp_body->arp_tha, ethnull, XETHER_ADDR_LEN);
  xphtonl(xp->p_arp_body->arp_tpa, dst_ip);

  xp->protocol = XNET_ARP_PROTOCOL;
  xp->src_ip = src_ip;
  xp->dst_ip = dst_ip;
  xp->send   = XFIRE_SEND_PACKET;

  xp->mbuf->pkt_len = xp->pkt_len;
}

static void response_xarp_virtual_mac (xpacket *xp, XARP_VIRTUAL *virtual)
{
  char pkt[64];
  xpacket xpt;
  ub32 tmp_ip;

  /*
   * arp packets are sent as 60 bytes packets (sum of structs are 42)
   */
  memset(pkt, 0, 60);
  xpt.pkt_ptr = pkt;
  
  XALIGNPOINTERS_ETH(xpt.pkt_ptr, xpt.p_ethh);
  rte_memcpy(xpt.p_ethh->ether_dhost, xp->p_ethh->ether_shost, XETHER_ADDR_LEN);
  rte_memcpy(xpt.p_ethh->ether_shost, virtual->xdev->xmac, XETHER_ADDR_LEN);
  xpt.p_ethh->ether_type = htons(ETHERTYPE_ARP);

  XALIGNPOINTERS_ARP(xpt.p_ethh, xpt.p_arph);
  xpt.p_arph->ar_hrd = htons(ARPHRD_ETHER);
  xpt.p_arph->ar_pro = htons(ETHERTYPE_IP);
  xpt.p_arph->ar_hln = 6;  /* mac len */
  xpt.p_arph->ar_pln = 4;  /* ip len */
  xpt.p_arph->ar_op  = htons(ARPOP_REPLY);

  XALIGNPOINTERS_ARP_BODY(xpt.p_arph, xpt.p_arp_body);
  rte_memcpy(xpt.p_arp_body->arp_sha,  virtual->xdev->xmac, XETHER_ADDR_LEN);
  xphtonl(xpt.p_arp_body->arp_spa, virtual->ip);

  rte_memcpy(xpt.p_arp_body->arp_tha, xp->p_ethh->ether_shost, XETHER_ADDR_LEN);
  rte_memcpy(xpt.p_arp_body->arp_tpa, xp->p_arp_body->arp_spa, 4);

  rte_memcpy(xp->pkt_ptr, pkt, 60);
  xp->pkt_len = 60;

  tmp_ip = xp->dst_ip;
  xp->dst_ip = xp->src_ip;
  xp->src_ip = tmp_ip;
  xp->send  = XFIRE_SEND_PACKET;

  xp->mbuf->pkt_len = xp->pkt_len;
}

static void xarp_handle_request (xpacket *xp)
{
  XARP_VIRTUAL *virtual;

  struct x_arp_body  *arp_body = xp->p_arp_body;
  struct x_ethernet_hdr *eth = xp->p_ethh;

  xp->src_ip = xpntohl(arp_body->arp_spa); /* we want the sender for a reply, the recipient  for a request*/
  xp->dst_ip = xpntohl(arp_body->arp_tpa);

  if (memcmp(eth->ether_shost, arp_body->arp_sha, XETHER_ADDR_LEN)) {
    return;
  }


#ifdef XARP_DEBUG
  printf("ARP REQ dev = %s, src = %s(%s), dst = %s(%s)\n", xp->xdev->xdev,
        intoa(xp->src_ip), etheraddr_string(eth->ether_shost),
        intoa(xpntohl(arp_body->arp_tpa)), etheraddr_string(eth->ether_dhost));
#endif

  /* virtual host table ---------------------------*/
  if ((virtual = (XARP_VIRTUAL *)xrbt32_search(virtual_table, xp->dst_ip))) {
    xarp_add_dev_ip(xp->src_ip, eth->ether_shost, xp->xdev->portid, 0);

#ifdef XARP_MAC
    xarp_add_dev_mac(virtual->xdev->xmac, virtual->xdev, xp->ts.tv_sec);
#endif
    response_xarp_virtual_mac(xp, virtual);

#ifdef XARP_DEBUG
    printf("$$$ ARP RSP dev = %s, src = %s(%s), dst = %s(%s)\n", xp->xdev->xdev,
        intoa(xp->src_ip), etheraddr_string(eth->ether_shost),
        intoa(xpntohl(arp_body->arp_tpa)), etheraddr_string(eth->ether_dhost));
#endif
    return;
  } 

  /* arp table ---------------------------*/
  xarp_add_dev_ip(xp->src_ip, eth->ether_shost, xp->xdev->portid, 0);

#ifdef XARP_MAC
  /* mac table ---------------------------*/
  xarp_add_dev_mac(eth->ether_shost, xp->xdev, xp->ts.tv_sec);
#endif
}


static void xarp_handle_reply (xpacket *xp)
{ 
  struct x_arp_body *arp_body = (struct x_arp_body *)xp->p_arp_body;
  struct x_ethernet_hdr *eth = xp->p_ethh;

  xp->src_ip = xpntohl(arp_body->arp_spa); /* we want the sender for a reply, the recipient  for a request*/
  xp->dst_ip = xpntohl(arp_body->arp_tpa);


#ifdef XARP_DEBUG
  printf("ARP RSP dev = %s, src = %s(%s), dst = %s(%s)\n", xp->xdev->xdev,
        intoa(xp->src_ip), etheraddr_string(eth->ether_shost),
        intoa(xpntohl(arp_body->arp_tpa)), etheraddr_string(eth->ether_dhost));
#endif


  if (memcmp(eth->ether_dhost, arp_body->arp_tha, XETHER_ADDR_LEN)) {
#ifdef XARP_DEBUG
    printf("Ethernet/ARP mismatch reply %s dst %s(%s) : %s(%s)\n", intoa(xp->src_ip),
           etheraddr_string(eth->ether_dhost), get_oui_info(eth->ether_dhost),
           etheraddr_string(arp_body->arp_tha), get_oui_info(arp_body->arp_tha));
#endif
    return;
  }

  if (memcmp(eth->ether_shost, arp_body->arp_sha, XETHER_ADDR_LEN)) {
#ifdef XARP_DEBUG
    printf("Ethernet/ARP mismatch reply %s src %s(%s) : %s(%s)\n", intoa(xp->src_ip),
           etheraddr_string(eth->ether_shost), get_oui_info(eth->ether_shost),
           etheraddr_string(arp_body->arp_sha), get_oui_info(arp_body->arp_sha));
#endif
    return;
  }

  if (memcmp(eth->ether_dhost, etherbcast, XETHER_ADDR_LEN) == 0) {
#ifdef XARP_DEBUG
    printf("Broadcast reply = %s, [%s] = %s\n", intoa(xp->src_ip),
          etheraddr_string(eth->ether_shost), get_oui_info(eth->ether_shost));
#endif
  }


  /* arp table ---------------------------*/
  xarp_add_dev_ip(xp->src_ip, eth->ether_shost, xp->xdev->portid, 0);

#ifdef XARP_MAC
  /* mac table ---------------------------*/
  xarp_add_dev_mac(eth->ether_shost, xp->xdev, xp->ts.tv_sec);
#endif
}

void xarp_dissect (xpacket *xp)
{
  ub16 ar_op;
  struct x_arp_hdr *arpheader = (struct x_arp_hdr *)xp->p_arph;

  if ((arpheader->ar_hln > MAX_HLN) || (arpheader->ar_pln > MAX_PLN)) {
    xp->drop = XPACKET_DROP;
  } else {
    ar_op = ntohs(arpheader->ar_op);
    if      (ar_op == ARPOP_REQUEST) xarp_handle_request(xp);
    else if (ar_op == ARPOP_REPLY)   xarp_handle_reply(xp);
  }
  xarp_check_timeouts(xp->ts.tv_sec);
}

#ifdef XARP_MAC
void xarp_dump_mac_table (void)
{
  XMAC *m;
  printf("==== mac count = %d ==============\n", xrbt64_count(mac_table));
  if ((m = (XMAC *)xrbt64_first(mac_table))) do {
    printf("dev=[%s], mac=[%s], oui=[%s]\n", m->xdev->xdev, etheraddr_string(m->mac), get_oui_info(m->mac));
  } while ((m = (XMAC *)xrbt64_next((XRBTN64 *)m)));
}

int xarp_mac_count (void)
{
  return xrbt64_count(mac_table);
}

#endif

void xarp_dump_arp_table (void)
{
  XARP *a;
  printf("==== arp count = %d ==============\n", xrbt32_count(arp_table));
  if ((a = (XARP *)xrbt32_first(arp_table))) do {
    printf("dev=[%s], ip=[%s], mac=[%s], oui=[%s]\n", a->xdev->xdev, intoa(a->ip), etheraddr_string(a->mac), get_oui_info(a->mac));
  } while ((a = (XARP *)xrbt32_next((XRBTN32 *)a)));
}

int xarp_arp_count (void)
{
  return xrbt32_count(arp_table);
}

int xarp_get_mac_addr (const char *in, ub32 *n0, ub32 *n1, ub32 *n2, ub32 *n3, ub32 *n4, ub32 *n5)
{
  if (6 == sscanf(in, "%x:%x:%x:%x:%x:%x", n0, n1, n2, n3, n4, n5)) {
    return 1;
  } else
  if (6 == sscanf(in, "%2x%x.%2x%x.%2x%x", n0, n1, n2, n3, n4, n5)) {
    return 1;
  } else
  if (6 == sscanf(in, "%x-%x-%x-%x-%x-%x", n0, n1, n2, n3, n4, n5)) {
    return 1;
  }
  return 0;
}



/* VIRTUAL MAC ---------------------------------------------------------*/
XARP_VIRTUAL *xarp_add_virtual_mac (ub32 ipaddr, ub8 portid, ub8 type)
{
  XARP_VIRTUAL *virtual;
  xdevice *xdev;
  int new;

  if ((xdev = xpacket_get_xdevice(portid)) == NULL) return NULL;

  virtual = (XARP_VIRTUAL *)xrbt32_insert(virtual_table, ipaddr, &new);
  if (new) {
    virtual->ip   = ipaddr;
    virtual->xdev = xdev;
    virtual->type = type;
    virtual->xdev->type |= type;
    return virtual;
  }
  return NULL;
}

void xarp_del_virtual_mac (ub32 ipaddr)
{
  XARP_VIRTUAL *virtual;

  if ((virtual = (XARP_VIRTUAL *)xrbt32_search(virtual_table, ipaddr))) {
    xrbt32_delete(virtual_table, ipaddr);
  }
}

void xarp_del_virtual_mac_type (ub32 ipaddr, ub8 type)
{
  XARP_VIRTUAL *virtual;

  if ((virtual = (XARP_VIRTUAL *)xrbt32_search(virtual_table, ipaddr))) {
    if (virtual->type == type) {
      xrbt32_delete(virtual_table, ipaddr);
    } else {
      virtual->type |= ~type;
      xarp_del_arp_type(ipaddr, type);
    }
  }
}


void xarp_clean_virtual_mac (void)
{
  if (virtual_table) {
    xrbt32_destroy(virtual_table);
    virtual_table = xrbt32_create(sizeof(XARP_VIRTUAL), 0);
  }
}

XARP_VIRTUAL *xarp_find_virtual (ub32 ipaddr)
{
  return (XARP_VIRTUAL *)xrbt32_search(virtual_table, ipaddr);
}

int xarp_find_virtual_mac (ub32 ipaddr)
{
  int ret = 0;
  if (xrbt32_search(virtual_table, ipaddr)) ret = 1;
  return ret;
}

xdevice *xarp_find_virtual_dev (ub32 ipaddr)
{
  XARP_VIRTUAL *virtual;
  xdevice *xdev;

  if ((virtual = (XARP_VIRTUAL *)xrbt32_search(virtual_table, ipaddr))) {
    xdev = virtual->xdev;
  } else xdev = NULL;
  return xdev;
}

void xarp_dump_virtual_mac (void)
{
  XARP_VIRTUAL *virtual;
  printf("==== virtual_table  count = %d ==============\n", xrbt32_count(virtual_table));
  if ((virtual = (XARP_VIRTUAL *)xrbt32_first(virtual_table))) do {
    printf("dev=[%s], type = %d, ip=[%s], mac=[%s], oui=[%s]\n",
          virtual->xdev->xdev, virtual->xdev->type, intoa(virtual->ip),
          etheraddr_string(virtual->xdev->xmac), get_oui_info(virtual->xdev->xmac));
  } while ((virtual = (XARP_VIRTUAL *)xrbt32_next((XRBTN32 *)virtual)));
}


void xarp_create_table (xbridge *xb)
{

  arp_table     = xrbt32_create(sizeof(XARP), XARP_TABLE_SIZE);
  virtual_table = xrbt32_create(sizeof(XARP_VIRTUAL), 0);

#if 0
  load_arp_info();
#endif

  arp_update = 0;
  xarp_timer = time(NULL) + XARP_TIMER_TIME;

#ifdef XARP_MAC
  mac_table     = xrbt64_create(sizeof(XMAC), XARP_TABLE_SIZE);
  load_mac_info();
  mac_update = 0;
#endif

}

void xarp_destroy_table (void)
{
  if (arp_table) {
    xrbt32_destroy(arp_table);
    xrbt32_destroy(virtual_table);
#ifdef XARP_MAC
    xrbt64_destroy(mac_table);
#endif
  }
}
