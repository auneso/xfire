/*
** 2016-12-21 HDS
*/

/*
** pcap snaplen mtu 
** inline set : ifconfig eth0 mtu 1500 ~ 64000
*/
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "xfire.h"
#include "xalloc.h"
#include "xstring.h"
#include "xtimeval.h"
#include "thread.h"
#include "xhttpd.h"
#include "xroute.h"
#include "xpacket.h"
#include "xpint.h"
#include "xtraffic.h"
#include "xwhite.h"
#include "xblack.h"
#include "xconfig.h"
#include "xvendor.h"
#include "xarp.h"
#include "xicmp.h"
#include "xcksum.h"
#include "xwall.h"
#include "format.h"
#include "xlog.h"
#include "xalert.h"
#include "xdhcp.h"
#include "xvhost.h"
#include "xnet.h"
#include "xroute.h"
#include "xdpdk.h"

#define LINK_CHECK_TIME  1

static xbridge *xbp = NULL;
static char vlan_on = 0;
static time_t link_check_time = 0;

/* $$$$$$$$$$$$$$$$$$$$$$ DHCP TEST $$$$$$$$$$$$$$$$$$$$$*/
char xdhcp_req = 1;
char xdhcp_port = 0;
void xpacket_dhcp_req (ub8 portid)
{
  xdhcp_req  = 1;
  xdhcp_port = portid;
}


int xpacket_get_dev_num (void)
{
  return xbp->xdev_num;
}

void xpacket_vlan_on (void)
{
  vlan_on = 1;
}

void unmarshal_vlan_pkt (xpacket *xp)
{
  char eth[12];

  rte_memcpy(eth, xp->frame, ETH_HEADER_LEN);
  rte_memcpy(xp->frame, xp->frame + ETH_HEADER_LEN, VLAN_HEADER_LEN);
  xp->pkt_ptr = xp->frame + VLAN_HEADER_LEN;
  rte_memcpy(xp->pkt_ptr, eth, ETH_HEADER_LEN);     /* overwrite the 4 bytes of vlan tag */
  xp->pkt_len -= VLAN_HEADER_LEN;
}

void marshal_vlan_pkt (xpacket *xp)
{
  char vlan[4];
  rte_memcpy(vlan, xp->frame, VLAN_HEADER_LEN);
  rte_memcpy(xp->frame, xp->pkt_ptr, ETH_HEADER_LEN);
  rte_memcpy(xp->frame+ETH_HEADER_LEN, vlan, VLAN_HEADER_LEN);

  xp->pkt_ptr = xp->frame;
  xp->pkt_len += VLAN_HEADER_LEN;
}

/* 
 802.3 Ethernet packet and frame structure (SFD:Start of frame delimiter)
Preamble SFD     MAC dst  MAC src  802.1Q tag(optional) Ethertype Payload            CRC      IPG
7 octets 1 octet 6 octets 6octets  (4 octets)           2 octets  46(42)-1500 octets 4 octets 12 octets 
*/

void xpacket_dissect (xpacket *xp, ub8 portid, struct timeval *ts)
{
  xp->xb = xbp;
  xp->xdev = xpacket_get_xdevice(portid);
  xp->ts = *ts;
  xp->pkt_len = xp->mbuf->pkt_len;
  xp->frame = xp->pkt_ptr = rte_pktmbuf_mtod(xp->mbuf, char *);

  xpkt_cnt *rx_tpn = &xp->xb->rx_pn;
  xpkt_cnt *rx_dpn = &xp->xdev->rx_pn;
  int plen = xp->pkt_len;

  if (link_check_time < ts->tv_sec) {
    xpacket_dev_link_check(); 
    link_check_time =  ts->tv_sec + LINK_CHECK_TIME;
  }

#if 0
/* $$$$$$$$$$$$$$$$$$$$$$ DHCP TEST $$$$$$$$$$$$$$$$$$$$$*/
  if (xdhcp_req) {
    xdhcp_req =0;    
    printf("$$$$$$$$$$ Send DHCP REQ $$$$$$$$$$$$$$$$$\n");
    xdhcp_discovery(xdhcp_port);
  }
#endif


#ifdef XPACKET_RAW_FRAME
  /* The standard minimum interframe gap is 96(12 bytes) "bit times" */
  plen += 24; /* 8 Preamble + 4 CRC + 12 IFG(Interframe gap, IPG:interpacket gap ) */;
#endif

  rx_tpn->total_pkts++; rx_tpn->total_bytes += plen;
  rx_dpn->total_pkts++; rx_dpn->total_bytes += plen;

  rx_tpn->pkts++; rx_tpn->bytes += plen;
  rx_dpn->pkts++; rx_dpn->bytes += plen;


  xp->pkt_type = 0;
  xp->protocol = 0;
  xp->error    = 0;
  xp->drop     = 0;
  xp->send     = 0;
  xp->vlan_id  = 0;
  

ethertype_vlan:

  if (plen < 14) { xp->error = XPACKET_PACKET_ERROR; xp->drop = XPACKET_DROP; return; }
  XALIGNPOINTERS_ETH(xp->pkt_ptr, xp->p_ethh);
  xp->pkt_type |= XPACKET_ETH;
  

  switch (ntohs(xp->p_ethh->ether_type)) {
    case ETHERTYPE_VLAN:  //ETHERNET_TYPE_8021Q
      rx_tpn->vlan_p++; rx_tpn->vlan_b += plen;
      rx_dpn->vlan_p++; rx_dpn->vlan_b += plen;

      unmarshal_vlan_pkt(xp);
      xp->pkt_type |= XPACKET_VLAN;
      xp->p_vlanh = (struct x_vlan_hdr *)xp->frame;
      if (vlan_on) xp->vlan_id = VTH_VLAN(xp->p_vlanh); 

#if 0
      printf("Vlan traffic:\n");
      printf("   Priority: %d(0x%X)\n", VTH_PRIORITY(xp->p_vlanh), VTH_PRIORITY(xp->p_vlanh));
      printf("   CFI: %d\n", VTH_CFI(xp->p_vlanh));
      printf("   Vlan ID: %d(0x%04X)\n", VTH_VLAN(xp->p_vlanh), VTH_VLAN(xp->p_vlanh));
      printf("   Vlan Proto: 0x%04X\n", ntohs(xp->p_vlanh->h_vlan_proto));
#endif

      goto ethertype_vlan;
 
    case ETHERTYPE_IP:
      rx_tpn->ipv4_p++; rx_tpn->ipv4_b += plen;
      rx_dpn->ipv4_p++; rx_dpn->ipv4_b += plen;

      if (xp->pkt_len < 14 + 20) {
        xp->error = XPACKET_IP_ERROR; xp->drop = XPACKET_DROP; return;
      }
      XALIGNPOINTERS_IP(xp->p_ethh, xp->p_iph);
      xp->pkt_type |= XPACKET_IP;
      
      
      xp->src_ip = ntohl(xp->p_iph->ip_src);
      xp->dst_ip = ntohl(xp->p_iph->ip_dst);
      

#ifdef USE_IP_CHECKSUM
      if (in_xcksum((unsigned short *)xp->p_iph, XIP_HDR_LENGTH(xp->p_iph)) != 0) { 
        xp->error = XPACKET_IP_SUM_ERROR;
        xp->drop = XPACKET_DROP;
        return; 
      }
#endif

      /* drop IP fragments and ip packet len > p_raw_len */
      if ((ntohs(xp->p_iph->ip_off) & IP_OFFMASK) != 0 ||
            (ntohs(xp->p_iph->ip_off) & IP_MF) ||
            (XIP_HDR_LENGTH(xp->p_iph) + XIP_DATA_LENGTH(xp->p_iph)) > xp->pkt_len) {
        xp->drop = XPACKET_DROP;
        return;
      }

      switch (xp->p_iph->ip_p) {
        case IPPROTO_TCP:
          rx_tpn->tcp_p++; rx_tpn->tcp_b += plen;
          rx_dpn->tcp_p++; rx_dpn->tcp_b += plen;

          if (xp->pkt_len < 14 + XIP_HDR_LENGTH(xp->p_iph) + 20) {
            xp->error = XPACKET_TCP_ERROR; xp->drop = XPACKET_DROP; return;
          }
          XALIGNPOINTERS_TCP(xp->p_iph, xp->p_tcph, xp->data_ptr);
          xp->data_len = XTCP_DATA_LENGTH(xp->p_iph, xp->p_tcph);
          xp->pkt_type |= XPACKET_TCP;
          
          xp->protocol = XNET_TCP_PROTOCOL;
          xp->src_port = ntohs(xp->p_tcph->th_sport);
          xp->dst_port = ntohs(xp->p_tcph->th_dport);

         if (xp->src_ip == xp->dst_ip && xp->src_port == xp->dst_port) {
            xp->error = XPACKET_TCP_ERROR; xp->drop = XPACKET_DROP; return; 
          }

#ifdef USE_TCP_CHECKSUM
          if (ip_in_xcksum(xp->p_iph, (unsigned short *)xp->p_tcph, XIP_DATA_LENGTH(xp->p_iph)) != 0) {
            xp->error = XPACKET_TCP_SUM_ERROR;
            xp->drop = XPACKET_DROP;
            return; 
          }
#endif
          break;


        case IPPROTO_UDP:
          rx_tpn->udp_p++; rx_tpn->udp_b += plen;
          rx_dpn->udp_p++; rx_dpn->udp_b += plen;

          if (xp->pkt_len < 14 + XIP_HDR_LENGTH(xp->p_iph) + 8) {
            xp->error = XPACKET_UDP_ERROR; xp->drop = XPACKET_DROP; return;
          }
          XALIGNPOINTERS_UDP(xp->p_iph, xp->p_udph, xp->data_ptr);
          xp->data_len = ntohs(xp->p_udph->uh_ulen);
          xp->pkt_type |= XPACKET_UDP;

          xp->protocol = XNET_UDP_PROTOCOL;
          xp->src_port = ntohs(xp->p_udph->uh_sport);
          xp->dst_port = ntohs(xp->p_udph->uh_dport);

          /* check the UDP checksum */

          /* dhcp server response  */
          if (xp->src_port == DHCP_SERVER_PORT) {
            xdhcp_dissect_rsp (xp);
          } 
          break;

        case IPPROTO_ICMP:
          rx_tpn->icmp_p++; rx_tpn->icmp_b += plen;
          rx_dpn->icmp_p++; rx_dpn->icmp_b += plen;

          if (xp->pkt_len < 14 + XIP_HDR_LENGTH(xp->p_iph) + 8) { xp->error = XPACKET_ICMP_ERROR; xp->drop = XPACKET_DROP; return; }
          XALIGNPOINTERS_ICMP(xp->p_iph, xp->p_icmph, xp->data_ptr);
          xp->data_len = XIP_DATA_LENGTH(xp->p_iph);
          xp->pkt_type |= XPACKET_ICMP;

          xp->protocol = XNET_ICMP_PROTOCOL;
          xp->src_port = 0;
          xp->dst_port = 0;

#if 0
          if (xp->p_icmph->icmp_type == ICMP_ECHOREPLY) {
            xp->src_port = 0;
            xp->dst_port = ICMP_ECHO;
          } else {
            xp->src_port = xp->p_icmph->icmp_type;
            xp->dst_port = 0;
          }
#endif
          
#ifdef USE_ICMP_CHECKSUM
          if (in_xcksum((unsigned short *)xp->p_icmph, XIP_DATA_LENGTH(xp->p_iph)) != 0) {
            xp->error = XPACKET_ICMPSUM__ERROR;
            xp->drop = XPACKET_DROP;
            return; 
          }
#endif
          xicmp_dissect(xp);

          break;
        default:
          break;
      }
      break;

    case ETHERTYPE_ARP:
      rx_tpn->arp_p++; rx_tpn->arp_b += plen;
      rx_dpn->arp_p++; rx_dpn->arp_b += plen;

      if (xp->pkt_len < 14 + 28) { xp->error = XPACKET_ARP_ERROR; xp->drop = XPACKET_DROP; return; }

      XALIGNPOINTERS_ARP(xp->p_ethh, xp->p_arph);
      XALIGNPOINTERS_ARP_BODY(xp->p_arph, xp->p_arp_body);
      xp->pkt_type |= XPACKET_ARP;
      xp->protocol = XNET_ARP_PROTOCOL;

      xarp_dissect(xp);
      break;

    case ETHERTYPE_REVARP:
    case ETHERTYPE_PPPOED:
    case ETHERTYPE_PPPOES:
    case ETHERTYPE_IP6:
    case ETHERTYPE_MPLS:
    default:
      xp->src_ip = xp->dst_ip = 0;
      xp->pkt_type |= XPACKET_OTHER;
      rx_tpn->other_p++; rx_tpn->other_b += plen;
      rx_dpn->other_p++; rx_dpn->other_b += plen;
      break;
  }

  packet_calc_rx_count(xp);
}


void xpacket_align (xpacket *xp)
{
  xp->pkt_ptr = xp->frame;

ethertype_vlan:
  XALIGNPOINTERS_ETH(xp->pkt_ptr, xp->p_ethh);

  switch (ntohs(xp->p_ethh->ether_type)) {
    case ETHERTYPE_VLAN: 
      unmarshal_vlan_pkt(xp);
      xp->p_vlanh = (struct x_vlan_hdr *)xp->frame;
      goto ethertype_vlan;
 
    case ETHERTYPE_IP:
      XALIGNPOINTERS_IP(xp->p_ethh, xp->p_iph);
      switch (xp->p_iph->ip_p) {
        case IPPROTO_TCP:
          XALIGNPOINTERS_TCP(xp->p_iph, xp->p_tcph, xp->data_ptr);
          break;

        case IPPROTO_UDP:
          XALIGNPOINTERS_UDP(xp->p_iph, xp->p_udph, xp->data_ptr);
          break;

        case IPPROTO_ICMP:
          XALIGNPOINTERS_ICMP(xp->p_iph, xp->p_icmph, xp->data_ptr);
          break;
      }
      break;
  }
}

void xpacket_calc_tx_count (xpacket *xp)
{
  xpkt_cnt *tx_tpn = &xp->xb->tx_pn;
  xpkt_cnt *tx_dpn = &xp->xdev->tx_pn;
  int plen = xp->pkt_len;

  tx_tpn->total_pkts++; tx_tpn->total_bytes += plen;
  tx_dpn->total_pkts++; tx_dpn->total_bytes += plen;

  tx_tpn->pkts++; tx_tpn->bytes += plen;
  tx_dpn->pkts++; tx_dpn->bytes += plen;

  if (xp->pkt_type & ETHERTYPE_VLAN) {
    tx_tpn->vlan_p++; tx_tpn->vlan_b += plen;
    tx_dpn->vlan_p++; tx_dpn->vlan_b += plen;
  }

  if (xp->pkt_type & XPACKET_IP) {
    tx_tpn->ipv4_p++; tx_tpn->ipv4_b += plen;
    tx_dpn->ipv4_p++; tx_dpn->ipv4_b += plen;

    if (xp->pkt_type & XPACKET_TCP) {
      tx_tpn->tcp_p++; tx_tpn->tcp_b += plen;
      tx_dpn->tcp_p++; tx_dpn->tcp_b += plen;
    } else
    if (xp->pkt_type & XPACKET_UDP) {
      tx_tpn->udp_p++; tx_tpn->udp_b += plen;
      tx_dpn->udp_p++; tx_dpn->udp_b += plen;
    } else
    if (xp->pkt_type & XPACKET_ICMP) {
      tx_tpn->icmp_p++; tx_tpn->icmp_b += plen;
      tx_dpn->icmp_p++; tx_dpn->icmp_b += plen;
    }
  } else
  if (xp->pkt_type & XPACKET_ARP) {
    tx_tpn->arp_p++; tx_tpn->arp_b += plen;
    tx_dpn->arp_p++; tx_dpn->arp_b += plen;
  } else
  if (xp->pkt_type & XPACKET_OTHER) {
    tx_tpn->other_p++; tx_tpn->other_b += plen;
    tx_dpn->other_p++; tx_dpn->other_b += plen;
  }
  xp->drop = 0;
  packet_calc_tx_count(xp);
}

void xpacket_error (xpacket *xp)
{
  if (xp->error || xp->drop) {
    xpkt_cnt *xpnb = &xp->xb->rx_pn;
    xpkt_cnt *xpnp = &xp->xdev->rx_pn;
    int plen = xp->pkt_len;

    if (xp->error) {
      xpnb->error_p++; xpnb->error_b += plen;
      xpnp->error_p++; xpnp->error_b += plen;
    } 
    if (xp->drop) { 
      xpnb->drop_p++; xpnb->drop_b += plen;
      xpnp->drop_p++; xpnp->drop_b += plen;
    }
  }
}


xpacket *xpacket_pkt_alloc (xdevice *xdev, xpacket *xp)
{
  xp->xb   = xbp;
  xp->xdev = xdev;
  xp->mbuf = xdpdk_pktmbuf_alloc();
  xp->frame = rte_pktmbuf_mtod(xp->mbuf, char *);
  return xp;
}


void xpacket_send_request_arp (ub32 dst_ip)
{
  xpacket *xp, xpkt;
  xdevice *xdev;

  int plen = X_ETH_H  + X_ARP_ETH_IP_H;  /* 14 + 28 */
  
  if (!(xdev = xarp_find_xdev_by_ip(xnet_my_ip()))) { return; }

  xp = xpacket_pkt_alloc(xdev, &xpkt);
  
  xarp_make_request_packet (xp, xdev->xmac, xnet_my_ip(), dst_ip);
  xp->mbuf->pkt_len  = xp->mbuf->data_len = plen;

  xdpdk_send_single_packet (xp->mbuf, xdev->portid);
}


void xpacket_send_request_arp_dev (xdevice *xdev, ub8 *src_mac, ub32 src_ip)
{
  xpacket *xp, xpkt;
  int plen = X_ETH_H  + X_ARP_ETH_IP_H;  /* 14 + 28 */
  ub32 dst_ip;
  
  dst_ip = xroute_get_gateway(src_ip);

  xp = xpacket_pkt_alloc(xdev, &xpkt);

  xarp_make_request_packet(xp, src_mac, src_ip, dst_ip);
  xp->mbuf->pkt_len  = xp->mbuf->data_len = plen;

  /* send direct dev tx queue */
  xdpdk_send_single_packet (xp->mbuf, xdev->portid);
}


/* network order */
void xpacket_send_tcp (ub8 *src_mac, ub8 *dst_mac, ub32 src_ip, ub32 dst_ip, ub16 sport, ub16 dport,
                       ub32 seqn, ub32 ackn, ub32 window, ub16 id, ub8 flags, char *vlan)
{
  xpacket *xp, xpkt;
  xdevice *xdev;
  int plen  = X_ETH_H  + X_IPV4_H + X_TCP_H + VLAN_HEADER_LEN;

  if (!(xdev = xarp_find_xdev_by_ip(dst_ip))) { return; }

  xp = xpacket_pkt_alloc(xdev, &xpkt);
  xp->mbuf->pkt_len  = xp->mbuf->data_len = plen;

  if (vlan) {
    rte_memcpy(xp->frame, vlan, VLAN_HEADER_LEN);
    xp->p_ethh = (struct x_ethernet_hdr *)&xp->frame[VLAN_HEADER_LEN];
    xp->pkt_ptr = &xp->frame[VLAN_HEADER_LEN];
    xp->pkt_type = XPACKET_ETH | XPACKET_VLAN | XPACKET_IP | XPACKET_TCP;
    xp->pkt_len = X_ETH_H  + X_IPV4_H + X_TCP_H + VLAN_HEADER_LEN;
  } else {
    xp->p_ethh = (struct x_ethernet_hdr *)xp->frame;
    xp->pkt_ptr = xp->frame;
    xp->pkt_type = XPACKET_ETH | XPACKET_IP | XPACKET_TCP;
    xp->pkt_len = X_ETH_H  + X_IPV4_H + X_TCP_H;
  }
  xp->data_len = 0;
  memset(xp->frame, 0, xp->pkt_len);

  rte_memcpy(xp->p_ethh->ether_dhost, dst_mac, ETHER_ADDR_LEN);
  rte_memcpy(xp->p_ethh->ether_shost, src_mac, ETHER_ADDR_LEN);
  xp->p_ethh->ether_type = htons(ETHERTYPE_IP);
  
  xp->p_iph  = (struct x_ipv4_hdr *)(xp->p_ethh + 1);
  xp->p_tcph = (struct x_tcp_hdr  *)(xp->p_iph + 1);

  xp->p_tcph->th_seq = seqn;
  xp->p_tcph->th_ack = ackn;

  xp->p_tcph->th_sport = sport;
  xp->p_tcph->th_dport = dport;
  xp->p_tcph->th_off   = 5;
  xp->p_tcph->th_flags = flags;
  xp->p_tcph->th_win   = window;

  xp->p_iph->ip_v   = 4;
  xp->p_iph->ip_hl  = 5;
  xp->p_iph->ip_len = htons(X_IPV4_H + X_TCP_H); /* 16-bit Total length */
  xp->p_iph->ip_ttl = 64;                        /* 8-bit Time To Live */
  xp->p_iph->ip_p   = IPPROTO_TCP;               /* 8-bit Protocol */
  xp->p_iph->ip_off = htons(IP_DF);              /* 16-bit Fragment */
  xp->p_iph->ip_src = src_ip;                    /* 32-bit Source Address */
  xp->p_iph->ip_dst = dst_ip;                    /* 32-bit Destination Address */
  xp->p_iph->ip_id  = id;

  xp->p_iph->ip_sum = 0;
  xp->p_iph->ip_sum = in_xcksum((unsigned short *)xp->p_iph, X_IPV4_H);

  xp->p_tcph->th_sum = 0;
  xp->p_tcph->th_sum = ip_in_xcksum(xp->p_iph, (unsigned short *)xp->p_tcph, sizeof(struct x_tcp_hdr));

  xp->protocol = XNET_TCP_PROTOCOL;
  xp->src_ip   = ntohl(xp->p_iph->ip_src);
  xp->dst_ip   = ntohl(xp->p_iph->ip_dst);
  xp->src_port = ntohs(xp->p_tcph->th_sport);
  xp->dst_port = ntohs(xp->p_tcph->th_dport);

  xp->mbuf->pkt_len  = xp->mbuf->data_len = plen;
  xdpdk_send_single_packet (xp->mbuf, xdev->portid);
}

void xpacket_reject_source (xpacket *xp)
{
  char *vlan = NULL;
  if (xp->pkt_type & XPACKET_VLAN) vlan = xp->frame;
  
  xpacket_send_tcp (xp->p_ethh->ether_dhost, xp->p_ethh->ether_shost,
                    xp->p_iph->ip_dst, xp->p_iph->ip_src, xp->p_tcph->th_dport, xp->p_tcph->th_sport,
                    xp->p_tcph->th_ack, htonl(ntohl(xp->p_tcph->th_seq) + xp->data_len + (xp->p_tcph->th_flags & TH_SYN ? 1 : 0)),
                    xp->p_tcph->th_win, 0, TH_RST, vlan);
}


/* network order */
void xpacket_set_tcp (xpacket *xp, ub8 *src_mac, ub8 *dst_mac, ub32 src_ip, ub32 dst_ip, ub16 sport, ub16 dport,
                      ub32 seqn, ub32 ackn, ub32 window, ub16 id, ub8 flags, char *vlan)
{
  if (vlan) {
    rte_memcpy(xp->frame, vlan, VLAN_HEADER_LEN);
    xp->p_ethh = (struct x_ethernet_hdr *)&xp->frame[VLAN_HEADER_LEN];
    xp->pkt_ptr = &xp->frame[VLAN_HEADER_LEN];
    xp->pkt_type = XPACKET_ETH | XPACKET_VLAN | XPACKET_IP | XPACKET_TCP;
    xp->pkt_len = X_ETH_H  + X_IPV4_H + X_TCP_H + VLAN_HEADER_LEN;
    
  } else {
    xp->p_ethh = (struct x_ethernet_hdr *)xp->frame;
    xp->pkt_ptr = xp->frame;
    xp->pkt_type = XPACKET_ETH | XPACKET_IP | XPACKET_TCP;
    xp->pkt_len = X_ETH_H  + X_IPV4_H + X_TCP_H;
  }
  xp->data_len = 0;

  rte_memcpy(xp->p_ethh->ether_dhost, dst_mac, ETHER_ADDR_LEN);
  rte_memcpy(xp->p_ethh->ether_shost, src_mac, ETHER_ADDR_LEN);
  xp->p_ethh->ether_type = htons(ETHERTYPE_IP);

  xp->p_iph  = (struct x_ipv4_hdr *)(xp->p_ethh + 1);
  xp->p_tcph = (struct x_tcp_hdr  *)(xp->p_iph + 1);

  xp->p_tcph->th_seq = seqn;
  xp->p_tcph->th_ack = ackn;

  xp->p_tcph->th_sport = sport;
  xp->p_tcph->th_dport = dport;
  xp->p_tcph->th_off   = 5;
  xp->p_tcph->th_flags = flags;
  xp->p_tcph->th_win   = window;

  xp->p_iph->ip_v   = 4;
  xp->p_iph->ip_hl  = 5;
  xp->p_iph->ip_len = htons(X_IPV4_H + X_TCP_H); /* 16-bit Total length */
  xp->p_iph->ip_ttl = 64;                        /* 8-bit Time To Live */
  xp->p_iph->ip_p   = IPPROTO_TCP;               /* 8-bit Protocol */
  xp->p_iph->ip_off = htons(IP_DF);              /* 16-bit Fragment */
  xp->p_iph->ip_src = src_ip;                    /* 32-bit Source Address */
  xp->p_iph->ip_dst = dst_ip;                    /* 32-bit Destination Address */
  xp->p_iph->ip_id  = id;

  xp->p_iph->ip_sum = 0;
  xp->p_iph->ip_sum = in_xcksum((unsigned short *)xp->p_iph, X_IPV4_H);

  xp->p_tcph->th_sum = 0;
  xp->p_tcph->th_sum = ip_in_xcksum(xp->p_iph, (unsigned short *)xp->p_tcph, sizeof(struct x_tcp_hdr));


  xp->protocol = XNET_TCP_PROTOCOL;
  xp->src_ip   = ntohl(xp->p_iph->ip_src);
  xp->dst_ip   = ntohl(xp->p_iph->ip_dst);
  xp->src_port = ntohs(xp->p_tcph->th_sport);
  xp->dst_port = ntohs(xp->p_tcph->th_dport);

  xp->mbuf->pkt_len  = xp->mbuf->data_len = xp->pkt_len;
  xp->send = XFIRE_SEND_PACKET;
}

void xpacket_set_reject_source (xpacket *xp)
{
  char vlan[VLAN_HEADER_LEN];
  ub8 smac[ETH_HEADER_LEN];
  ub8 dmac[ETH_HEADER_LEN];

  if (xp->pkt_type & XPACKET_VLAN) rte_memcpy(vlan, xp->frame, VLAN_HEADER_LEN);
  rte_memcpy(smac, xp->p_ethh->ether_shost, ETH_HEADER_LEN);
  rte_memcpy(dmac, xp->p_ethh->ether_dhost, ETH_HEADER_LEN);

  xpacket_set_tcp (xp, dmac, smac,
                   xp->p_iph->ip_dst, xp->p_iph->ip_src, xp->p_tcph->th_dport, xp->p_tcph->th_sport,
                   xp->p_tcph->th_ack, htonl(ntohl(xp->p_tcph->th_seq) + xp->data_len + (xp->p_tcph->th_flags & TH_SYN ? 1 : 0)),
                   xp->p_tcph->th_win, 0, TH_RST, NULL);
}



xbridge *xpacket_get_xbridge (void)
{ return xbp; }

int xpacket_create (void)
{
  xbp = xbridge_create();
  if (!xbp) return -1;
  return 0;
}

static int rtx_mode = X_L3SW_MODE;
void xpacket_set_rtx_mode (char *mode)
{
  if (strcmp(XINLIE_MODE, mode) == 0) { rtx_mode = X_INLINE_MODE; } else 
  if (strcmp(XL3SW_MODE, mode) == 0)  { rtx_mode = X_L3SW_MODE; }   else 
  if (strcmp(XPLB_MODE, mode) == 0)   { rtx_mode = X_PLB_MODE; }    else 
  if (strcmp(XSLB_MODE, mode) == 0)   { rtx_mode = X_SLB_MODE; }    else 
  if (strcmp(XNAT_MODE, mode) == 0)   { rtx_mode = X_NAT_MODE; }
}

/* call from xdpdk.c */
void  xpacket_setup (void)
{
  create_oui_table();
  xarp_create_table(xbp);

  xnet_set_gateway();

  xwhite_create();
  xblack_create();
  xwall_filter_create();

  xvhost_create();
  xwall_filter_create();
  xroute_create();
  xalert_create();
 
  xbridge_set_rtx_mode(xbp, rtx_mode); 

  xhttpd_thread();
}   

/* dev@alias */
static char *dev_alias (char *xdev)
{
  char *ptr;

  if ((ptr = strchr(xdev, '@'))) {
    *ptr++ = 0;
    return ptr;
  } else {
    return xdev;
  }
}

int xpacket_set_xdevice (ub8 portid, char *dev, ub8 *mac, ub32 speed)
{
  return xbridge_set_xdevice(xbp, portid, dev, dev_alias(dev), mac, speed);
}

xdevice *xpacket_get_xdevice (int port)
{
  return xbridge_get_xdevice(xbp, port);
}

xdevice *xpacket_set_xdevice_type (int port, ub8 type)
{
  xdevice *xdev = xbridge_get_xdevice(xbp, port);
  if (xdev)  xdev->type |= type;
  return xdev;
}

char *xpacket_get_xdevice_name (int port)
{
  xdevice *xdev = xbridge_get_xdevice(xbp, port);
  if (xdev ) return xdev->alias;
  return " ";
}

void xpacket_get_rx_count_dev (xdevice *xdev, xpkt_cnt *pcnt)
{
  return get_packet_rx_count_dev (xbp, xdev, pcnt);
}

void xpacket_get_tx_count_dev (xdevice *xdev, xpkt_cnt *pcnt)
{
  return get_packet_tx_count_dev (xbp, xdev, pcnt);
}

void xpacket_get_rx_count (xpkt_cnt *total)
{
  return get_packet_rx_count(xbp, total);
}

void xpacket_get_tx_count (xpkt_cnt *total)
{
  return get_packet_tx_count(xbp, total);
}

void xpacket_reset_count (void)
{
  reset_packet_rx_count(xbp);
  reset_packet_tx_count(xbp);
}

void xpacket_stats (struct xbridge_eth_stats *stats)
{
  xbridge_stats(xbp, stats);
}

void xpacket_reset_stats (void)
{
  xbridge_reset_stats(xbp);
}

void xpacket_dev_stats (xdevice *xdev, struct xbridge_eth_stats *stats)
{
  xbridge_dev_stats(xbp, xdev, stats);
}

void xpacket_dev_link_check (void)
{
  int i;

  struct rte_eth_link link;

  for (i = 0; i < xbp->xdev_num; i++) {
    memset(&link, 0, sizeof(link));
    rte_eth_link_get_nowait(xbp->xdev[i].portid, &link);

    if (link.link_status == ETH_LINK_DOWN) {
      if (xbp->xdev[i].link == XDEV_LINK_UP) {
        xfire_logging("Link Down Dev = [%s]\n", xbp->xdev[i].xdev);
        xbp->xdev[i].link = XDEV_LINK_DOWN;
        xbp->xdev[i].speed = link.link_speed;
        xroute_port_del(xbp->xdev[i].portid);
      }
    } else {
      if (xbp->xdev[i].link == XDEV_LINK_DOWN) {
        xfire_logging("Link UP Dev = [%s]\n", xbp->xdev[i].xdev);
        xbp->xdev[i].link = XDEV_LINK_UP;
        xroute_reload();
      }
    }
  }
}

int xpacket_link_down (ub8 portid)
{
  struct rte_eth_link link;
  memset(&link, 0, sizeof(link));
  rte_eth_link_get_nowait(portid, &link);
  if (link.link_status == ETH_LINK_DOWN)  return 1;
  return 0;
}

xdevice **xpacket_xdev_table_array (int *cnt)
{
  int i;
  xdevice **xd = xmalloc(sizeof(xdevice *) * xbp->xdev_num);

  for (i = 0; i < xbp->xdev_num; i++) {
    xd[i] = &xbp->xdev[i]; 
  } 
  *cnt = xbp->xdev_num;
  return xd;
}



