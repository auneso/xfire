/*
*/ 
#include <string.h>

#include "xpint.h"
#include "xrbt.h"
#include "xalloc.h"
#include "format.h"
#include "xstring.h"
#include "xstring.h"
#include "xbridge.h"
#include "xiptree.h"
#include "xportpool.h"
#include "xnet.h"
#include "xcksum.h"
#include "xarp.h"
#include "xroute.h"
#include "xdpdk.h"
#include "xnat.h"
#include "xwall.h"
#include "xsession.h"

#define XWALL_START_PORT 1025
#define XWALL_END_PORT  65535

static xnat_table *nat_table  = NULL;

static XRBTR32    *virtual_table = NULL;
static XRBTR32    *local_table   = NULL;

static xportpool  *port_pool = NULL;

struct _xnat_type {
  char *name;
  ub8  type;
} xnat_type[] = {
  { "none", XNONE_TYPE },
  { "dnat", XDNAT_TYPE },
  { "snat", XSNAT_TYPE },
  { "both", XBOTH_TYPE },
  { NULL, 0  }
};

static ub8 get_nat_type (char *nat_type)
{
  int i;
  for (i = 0; xnat_type[i].name; i++) {
    if (strcmp(nat_type, xnat_type[i].name) == 0) return xnat_type[i].type;
  }
  return 0;
}

static char *get_nat_name (ub8 nat_type)
{
  int i;
  for (i = 0; xnat_type[i].name; i++) {
    if (nat_type == xnat_type[i].type) return xnat_type[i].name;
  }
  return 0;
}

static int xnat_save_virtual (void)
{
  xnat_virtual *virtual;
  FILE *fp = fopen(XFIRE_VIRTUAL_CFG_FILE, "w+");
  if (fp == NULL) return -1;

  if ((virtual = (xnat_virtual *)xrbt32_first(virtual_table))) do {
    fprintf(fp, "%d %s %d %s\n", virtual->virtual_id,  virtual->ipaddrs, virtual->port_id, virtual->alias);
  } while ((virtual = (xnat_virtual *)xrbt32_next((XRBTN32 *)virtual)));

  fclose(fp);

  return 0;
}

static int xnat_load_virtual (void)
{
  FILE *fp;
  if (!(fp = fopen(XFIRE_VIRTUAL_CFG_FILE, "r"))) return -1;

  char buf[1024], *ptr[4];

  while (fgets(buf, sizeof(buf), fp)) {
    if (buf[0] == '#' || buf[0] == '\n') continue;
    //  1:virtual_id 2:ipaddrs 3:port_id 3:alias
    if (msplit(buf, ptr, 4, " \t") == 4) {
      xnat_virtual_add(atoi(ptr[0]), ptr[1], atoi(ptr[2]), ptr[3]);
    }
  }
  fclose(fp);
  return 0;
}

static int xnat_save_local (void)
{
  xnat_local *local;
  FILE *fp = fopen(XFIRE_LOCAL_CFG_FILE, "w+");
  if (fp == NULL) return -1;

  if ((local = (xnat_local *)xrbt32_first(local_table))) do {
    fprintf(fp, "%d %s %s, %s %s %d\n", local->local_id, local->local_ips, local->dst_ips, local->alias, get_nat_name(local->nat_type), local->virtual_id); 
  } while ((local = (xnat_local *)xrbt32_next((XRBTN32 *)local)));
  fclose(fp);

  return 0;
}

static int xnat_load_local (void)
{
  FILE *fp;
  if (!(fp = fopen(XFIRE_LOCAL_CFG_FILE, "r"))) return -1;

  char buf[1024], *ptr[6];

  while (fgets(buf, sizeof(buf), fp)) {
    if (buf[0] == '#' || buf[0] == '\n') continue;
    //  1:local_id 2:src_ip 3:dst_ip 4:alias 5:net_TYPE 6:virtual_id
    if (msplit(buf, ptr, 6, " \t") == 6) {
      xnat_local_add(atoi(ptr[0]), ptr[1], ptr[2], ptr[3], get_nat_type(ptr[4]), atoi(ptr[5]));
    }
  }
  fclose(fp);
  return 0;

}

void xnat_virtual_add (ub16 virtual_id, char *virtual_ipaddrs, ub8 port_id, char *alias)
{
  int new;
  xnat_virtual *virtual;
  
  virtual = (xnat_virtual *)xrbt32_insert(virtual_table, virtual_id, &new);
  if (new) {
    virtual->virtual_id = virtual_id;
    virtual->port_id    = port_id;
    xstrlcpy(virtual->ipaddrs, virtual_ipaddrs, XNAT_IP_SIZE);
    xstrlcpy(virtual->alias, alias, XNAT_ALIAS_SIZE);
  }
}

void xnat_virtual_del (ub16 virtual_id)
{
  xnat_virtual *virtual;

  if ((virtual = (xnat_virtual *)xrbt32_search(virtual_table, virtual_id))) {
    xrbt32_remove(virtual_table, (XRBTN32 *)virtual);
  }
}

void xnat_local_add (ub16 local_id, char *local_ips, char *dst_ips, char *alias, ub8 nat_type, ub16 virtual_id)
{
  int new;
  xnat_local *local;

  local = (xnat_local *)xrbt32_insert(local_table, local_id, &new);

  if (new) {
    local->local_id    = local_id;
    local->virtual_id  = virtual_id;
    local->nat_type    = nat_type;
    xstrlcpy(local->local_ips, local_ips, XNAT_IP_SIZE);
    xstrlcpy(local->dst_ips, dst_ips, XNAT_IP_SIZE);
    xstrlcpy(local->alias, alias, XNAT_ALIAS_SIZE);
  } 
}

void xnat_local_del (ub16 local_id)
{
  xnat_local *local;

  if ((local = (xnat_local *)xrbt32_search(local_table, local_id))) {
    xrbt32_remove(local_table, (XRBTN32 *)local);
  }
}


void xnat_clean (void)
{
  xnat_local *local;
  xnat_virtual *virtual;
  XRBTN32 *ip;
 
  if (nat_table->virtual == NULL || nat_table->local == NULL) return;

  if ((virtual = (xnat_virtual *)xrbt32_first(virtual_table))) do {
     if (virtual->virtual_ip_table) {
       if ((ip = xrbt32_first(virtual->virtual_ip_table))) do {
         xarp_del_virtual_mac_type(ip->key, XNAT_DEV_TYPE); 
       } while ((ip = xrbt32_next(ip))); 
       xrbt32_destroy(virtual->virtual_ip_table);;
     }
     xvector_destroy(virtual->weight_table);;
  } while ((virtual = (xnat_virtual *)xrbt32_next((XRBTN32 *)virtual)));

  if ((local = (xnat_local *)xrbt32_first(local_table))) do {
    xrbt32_destroy(local->local_ip_table);;
    xiptree_destroy(local->dst_ip_table);;
    xvector_destroy(local->weight_table);
  } while ((local = (xnat_local *)xrbt32_next((XRBTN32 *)local)));

  xiptree_destroy(nat_table->local); 
  xiptree_destroy(nat_table->virtual);

  nat_table->local = nat_table->virtual = NULL;
}

static void set_virtual_table (xnat_virtual *virtual, xnat_local *local)
{
  XRBTN32 *ip;

  if (xiptree_check_cmd(nat_table->virtual, virtual->ipaddrs)) {
    printf("$$$$$$$$$$$ set_virtual_table DUP ip address = %s\n",  virtual->ipaddrs);
    return; 
  }

  if (xiptree_insert_cmd(nat_table->virtual, virtual->ipaddrs, local)) {
    virtual->virtual_ip_table = xiptree_make_table(virtual->ipaddrs);
    
    virtual->weight_table = xvector_create(xrbt32_count(virtual->virtual_ip_table));   
    if ((ip = xrbt32_first(virtual->virtual_ip_table))) do {
       xarp_add_virtual_mac (ip->key, virtual->port_id, XNAT_DEV_TYPE);
       xvector_append(virtual->weight_table, ip);
    } while ((ip = xrbt32_next(ip)));
  }
}

static void set_local_table (xnat_local *local, xnat_virtual *virtual)
{
  XRBTN32 *ip;

  if (xiptree_check_cmd(nat_table->local, local->local_ips)) {
    printf("$$$$$$$$$$$ set_local_table DUP ip address = %s\n", local->local_ips);
    return; 
  }

  if (xiptree_insert_cmd(nat_table->local, local->local_ips, virtual)) {
    local->local_ip_table = xiptree_make_table(local->local_ips);
    local->dst_ip_table = xiptree_create();
    xiptree_insert_cmd(local->dst_ip_table, local->dst_ips, local);

    local->weight_table = xvector_create(xrbt32_count(local->local_ip_table));   
    if ((ip = xrbt32_first(local->local_ip_table))) do {

printf("weight_table = %s\n", intoa(ip->key));

      xvector_append(local->weight_table, ip);
    } while ((ip = xrbt32_next(ip)));
  }
}

void xnat_apply (int save)
{
  xnat_local *local;
  xnat_virtual *virtual;
  
  xfire_write_lock();

  if (save) xnat_clean();

  nat_table->local   = xiptree_create();
  nat_table->virtual = xiptree_create();

  if ((local = (xnat_local *)xrbt32_first(local_table))) do {
    if ((virtual = (xnat_virtual *)xrbt32_search(virtual_table, local->virtual_id))) {
      set_virtual_table(virtual, local); virtual->local = local; 
      set_local_table(local, virtual);   local->virtual = virtual;
    }   
  } while ((local = (xnat_local *)xrbt32_next((XRBTN32 *)local)));

  xfire_write_unlock();

  if (save) { xnat_save_virtual(); xnat_save_local(); }
}


static xnat_local *xnat_get_dnat (xpacket *xp, ub32 dst_ip)
{
  xnat_local *local;

  local = (xnat_local *)xiptree_lookup (nat_table->virtual, dst_ip);
  return local;
}

static ub32 xnat_get_balance_dst (xpacket *xp, xnat_local *local)
{
  int idx, cnt;
  XRBTN32 *ip;

  if ((cnt = xvector_count(local->weight_table))) {
    idx = xp->src_ip % cnt;
    ip = (XRBTN32 *)xvector_get_at(local->weight_table, idx);
    return ip->key;
  }
  return 0;
}


static xnat_virtual *xnat_get_snat (xpacket *xp, ub32 src_ip)
{
  xnat_virtual *virtual;

  virtual = (xnat_virtual *)xiptree_lookup (nat_table->local, src_ip);
  return virtual;
}

static ub32 xnat_get_balance_src (xpacket *xp, xnat_virtual *virtual)
{
  int idx, cnt;
  XRBTN32 *ip;

  if ((cnt = xvector_count(virtual->weight_table))) {
    idx = xp->src_ip % cnt;
    ip = (XRBTN32 *)xvector_get_at(virtual->weight_table, idx);
    return ip->key;
  }
  return 0;
}


static void xnat_route_dst (xpacket *xp, ub32 ip, ub16 port)
{
  xp->dst_ip   = ip;
  xp->dst_port = port;

  xp->p_iph->ip_dst = htonl(ip);
  xp->p_iph->ip_sum = 0;
  xp->p_iph->ip_sum = in_xcksum((unsigned short *)xp->p_iph, XIP_HDR_LENGTH(xp->p_iph));

  switch (xp->protocol) {
  case XNET_TCP_PROTOCOL :
    xp->p_tcph->th_dport = htons(port);
    xp->p_tcph->th_sum = 0;
    xp->p_tcph->th_sum = ip_in_xcksum(xp->p_iph, (unsigned short *)xp->p_tcph, XIP_DATA_LENGTH(xp->p_iph));
    break;
  case XNET_UDP_PROTOCOL :
    xp->p_udph->uh_dport = htons(port);
    xp->p_udph->uh_sum = 0;
    xp->p_udph->uh_sum = ip_in_xcksum(xp->p_iph, (unsigned short *)xp->p_udph, XIP_DATA_LENGTH(xp->p_iph));
    break;
  case XNET_ICMP_PROTOCOL :
    break;
  }
}

static void xnat_route_src (xpacket *xp, ub32 ip, ub16 port)
{
  xp->src_ip   = ip;
  xp->src_port = port;

  xp->p_iph->ip_src = htonl(ip);
  xp->p_iph->ip_sum = 0;
  xp->p_iph->ip_sum = in_xcksum((unsigned short *)xp->p_iph, XIP_HDR_LENGTH(xp->p_iph));

  switch (xp->protocol) {
  case XNET_TCP_PROTOCOL :
    xp->p_tcph->th_sport = htons(port);
    xp->p_tcph->th_sum = 0;
    xp->p_tcph->th_sum = ip_in_xcksum(xp->p_iph, (unsigned short *)xp->p_tcph, XIP_DATA_LENGTH(xp->p_iph));
    break;
  case XNET_UDP_PROTOCOL :
    xp->p_udph->uh_sport = htons(port);
    xp->p_udph->uh_sum = 0;
    xp->p_udph->uh_sum = ip_in_xcksum(xp->p_iph, (unsigned short *)xp->p_udph, XIP_DATA_LENGTH(xp->p_iph));
    break;
  case XNET_ICMP_PROTOCOL :
    break;
  }
}

static int inbound (xpacket *xp, xnat_local *local)
{
  xsession *sess1, *sess2;
  ub32 local_ip;
   
  /* $$$ SNAT OUTBOUND  IN : out server -> virtaul client  => out server -> real client */
  /* out-virtual session : outbound  */
  sess1 = xsession_find(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_OUTBOUND);
  if (sess1) {
    /* out-in session */
    sess2 = xsession_find(xp, xp->src_ip, xp->src_port, sess1->xip, sess1->xport, xp->protocol, XNET_OUTBOUND);
    if (sess2) {
      xnat_route_dst(xp, sess1->xip, sess1->xport);
      return XNET_ACCEPT;
    }
  } 

  /* $$$ DNAT INBOUND IN : out src -> vitual dst(rip,rport)  =>  out src -> in dst(vip, vpoer) */
  /* out -> virtual  session : inbound */
  if (local->nat_type & XDNAT_TYPE) {
    sess1 = xsession_get(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_INBOUND);
    if (sess1->new) {
      /* get balance in dst */
      if ((local_ip = xnat_get_balance_dst(xp, local))) {
        /* out src -> vitual dst(rip, rport) */
        sess1->xip = local_ip; sess1->xport = xp->dst_port;

        /* out -> in  session */
        sess2 = xsession_get(xp, xp->src_ip, xp->src_port, sess1->xip, sess1->xport, xp->protocol, XNET_INBOUND);
        if (sess2->new) {
          /* out src -> in dst(vip, vpoer) */
          sess2->xip = xp->dst_ip; sess2->xport = xp->dst_port;

          /* cvt virtaul server to real server : dst cvt */
          xnat_route_dst(xp, sess1->xip, sess1->xport); 
          return XNET_ACCEPT;
        } 
      }
    } else { 
      /* out-in session */
      sess2 = xsession_find(xp, xp->src_ip, xp->src_port, sess1->xip, sess1->xport, xp->protocol, XNET_INBOUND);
      if (sess2) {
        /* cvt virtaul server to real server : dst cvt */
        xnat_route_dst(xp, sess1->xip, sess1->xport); 
        return XNET_ACCEPT;
      } 
    }
  }
  return XNET_DROP;
}

static int outbound (xpacket *xp, xnat_virtual *virtual)
{
  xsession *sess1, *sess2;
  ub32 virtual_ip;
  xnat_local *local;

  /* $$$ DNAT INBOUND OUT: in src -> out dst => virtual src -> out dst  */
  /* in -> out session : inbound */
  if ((sess1 = xsession_find(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_INBOUND))) {
    /* virtual -> out */
    sess2 = xsession_find(xp, sess1->xip, sess1->xport, xp->dst_ip, xp->dst_port, xp->protocol, XNET_INBOUND);
    if (sess2) {
      /* real src -> virtaul src */
      xnat_route_src(xp, sess1->xip, sess1->xport);
      return XNET_ACCEPT;
    } 
  }

  /* $$$ SNAT OUTBOUND OUT : in client -> out server => virtaul client -> out serve r*/
  /* in -> out session : outbound */
  local = virtual->local;
  if (local && local->nat_type & XSNAT_TYPE && xiptree_search(local->dst_ip_table, xp->dst_ip)) {
    sess1 = xsession_get(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_OUTBOUND);
    if (sess1->new) {
      if ((virtual_ip = xnat_get_balance_src(xp, virtual))) {
        sess1->xip = virtual_ip;

        if (xp->protocol == XNET_ICMP_PROTOCOL) {
          sess1->xsp = NULL;
          sess1->xport = xp->src_port;
        } else {
          sess1->xsp = xportpool_pop(port_pool, virtual_ip, xp->dst_ip, xp->dst_port, xp->protocol);
          sess1->xport = sess1->xsp->port;
        }
        
        /* in - >virtual session */
        sess2 = xsession_get(xp, sess1->xip, sess1->xport, xp->dst_ip, xp->dst_port, xp->protocol, XNET_OUTBOUND);
        if (sess2->new) {
          sess2->xip = xp->src_ip; sess2->xport = xp->src_port;           
          xnat_route_src(xp, sess1->xip, sess1->xport);
          return XNET_ACCEPT;
        }
      }
    } else {
      sess2 = xsession_find(xp, sess1->xip, sess1->xport, xp->dst_ip, xp->dst_port, xp->protocol, XNET_OUTBOUND);
      if (sess2) {
        xnat_route_src(xp, sess1->xip, sess1->xport);
        return XNET_ACCEPT;
      } 
    }
  }

  return XNET_DROP;
}

static int xnat_rx_packet (xpacket *xp)
{
  xnat_virtual *virtual;
  xnat_local *local;
   
  if (xp->send == XFIRE_SEND_PACKET) return XNET_ACCEPT;
  if (!(xp->protocol & XNET_SESS_PROTOCOL)) return XNET_ACCEPT;
  
  if (xnet_is_broadcast(xp->dst_ip)) return XNET_ACCEPT;
  if (xnet_is_multicast(xp->dst_ip)) return XNET_ACCEPT;

//printf("RX  dst = %s:%u(%s), src = %s:%u(%s)\n", intoa(xp->dst_ip), xp->dst_port, etheraddr_string(xp->p_ethh->ether_dhost), intoa(xp->src_ip), xp->src_port, etheraddr_string(xp->p_ethh->ether_shost));

  if ((local = xnat_get_dnat(xp, xp->dst_ip)) && inbound(xp, local) == XNET_ACCEPT) {
    return XNET_ACCEPT;
  } else 
  if ((virtual = xnat_get_snat(xp, xp->src_ip)) && outbound(xp, virtual) == XNET_ACCEPT) {
    return XNET_ACCEPT;
  } 
  /* none NAT */
  xsession_get(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_DIRECT);
  return XNET_ACCEPT;
}

/* req arp -----------*/
static int xnat_req_arp (xpacket *xp, ub32 gw_ip)
{
  return XNET_DROP;

/*
  xdevice *xdev;
  xarp_make_request_packet(xpacket, xp->xdev->xmac, ub32 src_ip, ub32 gw_ip);
  xdpdk_broadcast_send(xp);
  return XNET_ACCEPT;
*/
}


static const ub8 etherbcast[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
static int xnat_tx_packet (xpacket *xp)
{
  XARP *arp;
  ub32 gw_ip;

//printf("TX  dst = %s:%u(%s), src = %s:%u(%s)\n", intoa(xp->dst_ip), xp->dst_port, etheraddr_string(xp->p_ethh->ether_dhost), intoa(xp->src_ip), xp->src_port, etheraddr_string(xp->p_ethh->ether_shost));
  xpacket_calc_tx_count(xp);

  if (memcmp(etherbcast, xp->p_ethh->ether_dhost, 6) == 0) {
    xdpdk_broadcast_send(xp);
    return XNET_ACCEPT;
  } else 
  if ((gw_ip = xroute_get_gateway(xp->dst_ip))) {
    if ((arp = xarp_find_by_ip(gw_ip, xp->ts.tv_sec))) {
      rte_memcpy(xp->p_ethh->ether_dhost, arp->mac, XETHER_ADDR_LEN);
      rte_memcpy(xp->p_ethh->ether_shost, arp->xdev->xmac, XETHER_ADDR_LEN);
      xdpdk_send_single_packet(xp->mbuf, arp->xdev->portid);
//printf("Route  dst = %s:%u(%s), src = %s:%u(%s)\n", intoa(xp->dst_ip), xp->dst_port, etheraddr_string(xp->p_ethh->ether_dhost), intoa(xp->src_ip), xp->src_port, etheraddr_string(xp->p_ethh->ether_shost));
      return XNET_ACCEPT;
    } 
//printf("Not found Route  dst = %s:%u(%s), src = %s:%u(%s)\n", intoa(xp->dst_ip), xp->dst_port, etheraddr_string(xp->p_ethh->ether_dhost), intoa(xp->src_ip), xp->src_port, etheraddr_string(xp->p_ethh->ether_shost));
    return xnat_req_arp(xp, gw_ip); 
  } else
  if ((arp = xarp_find_by_ip(xp->dst_ip, xp->ts.tv_sec))) {
    rte_memcpy(xp->p_ethh->ether_dhost, arp->mac, XETHER_ADDR_LEN);
    rte_memcpy(xp->p_ethh->ether_shost, arp->xdev->xmac, XETHER_ADDR_LEN);

//printf("ARP  dst = %s:%u(%s), src = %s:%u(%s)\n", intoa(xp->dst_ip), xp->dst_port, etheraddr_string(xp->p_ethh->ether_dhost), intoa(xp->src_ip), xp->src_port, etheraddr_string(xp->p_ethh->ether_shost));

    xdpdk_send_single_packet(xp->mbuf, arp->xdev->portid);
    return XNET_ACCEPT;
  } 
//printf("ARP DROP  dst = %s:%u(%s), src = %s:%u(%s)\n", intoa(xp->dst_ip), xp->dst_port, etheraddr_string(xp->p_ethh->ether_dhost), intoa(xp->src_ip), xp->src_port, etheraddr_string(xp->p_ethh->ether_shost));
  return XNET_DROP;
}

void xnat_create (xbridge *xb)
{
  xb->rx_packet = xnat_rx_packet;
  xb->tx_packet = xnat_tx_packet;
  xb->vmode = X_NAT_MODE;

  xsession_table_create();
  nat_table = xzalloc(sizeof(xnat_table));

  local_table   = xrbt32_create(sizeof(xnat_local), 0);
  virtual_table = xrbt32_create(sizeof(xnat_virtual), 0);

  port_pool = xportpool_create(XWALL_START_PORT, XWALL_END_PORT);

  xnat_load_local();
  xnat_load_virtual();

  xnat_apply(0);
  printf("\n$$$$$ NAT_MODE $$$$$\n");
}

void xnat_destroy (void)
{
  xnat_clean();
  if (port_pool) xportpool_destroy(port_pool);
  xfree(nat_table);
  xsession_table_destroy();
}

