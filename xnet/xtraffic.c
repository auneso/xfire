/*
*/
#include "xdpdk.h"


#include <math.h>
#include "xtimeval.h"
#include "xbridge.h"
#include "xpacket.h"
#include "xalert.h"
#include "xnet.h"

/*
 SI prefixes  

Factor Name  Symbol
10^24  yotta  Y 
10^21  zetta  Z 
10^18  exa    E 
10^15  peta   P 
10^12  tera   T 
10^9   giga   G 
10^6   mega   M 
10^3   kilo   k 
10^2   hecto  h 
10^1   deka   da 
   
Factor Name  Symbol 
10^-1  deci   d 
10^-2  centi  c 
10^-3  milli  m 
10^-6  micro  µ 
10^-9  nano   n 
10^-12 pico   p 
10^-15 femto  f 
10^-18 atto   a 
10^-21 zepto  z 
10^-24 yocto  y 
*/ 


#define XPPS(x) (x / xtime)
#define XBPS(x) ((x * 8) / xtime)


static void packet_calc_device_count (xpacket *xp, xpkt_cnt *xpn, xpkt_cnt *xpd, int plen, struct timeval *ct)
{
  ub64 xtime;

  /* network  -------------------------------------------*/
  if      (plen < 78)   { xpn->p_77++;    xpd->p_77++;    }  
  else if (plen < 111)  { xpn->p_110++;   xpd->p_110++;   }  
  else if (plen < 251)  { xpn->p_250++;   xpd->p_250++;   }  
  else if (plen < 501)  { xpn->p_500++;   xpd->p_500++;   }  
  else if (plen < 1001) { xpn->p_1000++;  xpd->p_1000++;  }  
  else if (plen < 1519) { xpn->p_large++; xpd->p_large++; } 
  else                  { xpn->p_jumbo++; xpd->p_jumbo++; }

  xtime = xdelta_time_in_seconds(ct, &xpn->ts);

  if (xtime) {
    xalert_check_blackhole_timer();
    
    
    xpn->pps = XPPS(xpn->pkts);  xpn->pkts = 0;
    if (xpn->pps > xpn->max_pps) xpn->max_pps = xpn->pps;

    xpn->bps = XBPS(xpn->bytes); xpn->bytes = 0;
    if (xpn->bps > xpn->max_bps) xpn->max_bps = xpn->bps;

    xpn->vlan_pps = XPPS(xpn->vlan_p); xpn->vlan_p = 0;
    xpn->vlan_bps = XBPS(xpn->vlan_b); xpn->vlan_b = 0;

    xpn->ipv4_pps = XPPS(xpn->ipv4_p); xpn->ipv4_p = 0;
    xpn->ipv4_bps = XBPS(xpn->ipv4_b); xpn->ipv4_b = 0;

    xpn->tcp_pps = XPPS(xpn->tcp_p); xpn->tcp_p = 0;
    xpn->tcp_bps = XBPS(xpn->tcp_b); xpn->tcp_b = 0;

    xpn->udp_pps = XPPS(xpn->udp_p); xpn->udp_p = 0;
    xpn->udp_bps = XBPS(xpn->udp_b); xpn->udp_b = 0;

    xpn->icmp_pps = XPPS(xpn->icmp_p); xpn->icmp_p = 0;
    xpn->icmp_bps = XBPS(xpn->icmp_b); xpn->icmp_b = 0;

    xpn->arp_pps = XPPS(xpn->arp_p); xpn->arp_p = 0;
    xpn->arp_bps = XBPS(xpn->arp_b); xpn->arp_b = 0;

    xpn->other_pps = XPPS(xpn->other_p); xpn->other_p = 0;
    xpn->other_bps = XBPS(xpn->other_b); xpn->other_b = 0;

    xpn->p_77   = xpn->p_110 = xpn->p_250  = xpn->p_500 =
    xpn->p_1000 = xpn->p_large = xpn->p_jumbo =  0;
    
    xpn->ts = *ct;
  }

  /* device ----------------------------------------*/
  xtime = xdelta_time_in_seconds(ct, &xpd->ts);
  if (xtime) {
    xpd->pps = XPPS(xpd->pkts);  xpd->pkts = 0;
    xpd->bps = XBPS(xpd->bytes); xpd->bytes = 0;

    if (xpd->pps > xpd->max_pps) xpd->max_pps = xpd->pps;
    if (xpd->bps > xpd->max_bps) xpd->max_bps = xpd->bps;

    xpd->vlan_pps = XPPS(xpd->vlan_p); xpd->vlan_p = 0;
    xpd->vlan_bps = XBPS(xpd->vlan_b); xpd->vlan_b = 0;

    xpd->ipv4_pps = XPPS(xpd->ipv4_p); xpd->ipv4_p = 0;
    xpd->ipv4_bps = XBPS(xpd->ipv4_b); xpd->ipv4_b = 0;

    xpd->tcp_pps = XPPS(xpd->tcp_p); xpd->tcp_p = 0;
    xpd->tcp_bps = XBPS(xpd->tcp_b); xpd->tcp_b = 0;

    xpd->udp_pps = XPPS(xpd->udp_p); xpd->udp_p = 0;
    xpd->udp_bps = XBPS(xpd->udp_b); xpd->udp_b = 0;

    xpd->icmp_pps = XPPS(xpd->icmp_p); xpd->icmp_p = 0;
    xpd->icmp_bps = XBPS(xpd->icmp_b); xpd->icmp_b = 0;

    xpd->arp_pps = XPPS(xpd->arp_p); xpd->arp_p = 0;
    xpd->arp_bps = XBPS(xpd->arp_b); xpd->arp_b = 0;

    xpd->other_pps = XPPS(xpd->other_p); xpd->other_p = 0;
    xpd->other_bps = XBPS(xpd->other_b); xpd->other_b = 0;

    xpd->p_77   = xpd->p_110 = xpd->p_250  = xpd->p_500 =
    xpd->p_1000 = xpd->p_large = xpd->p_jumbo = 0;
    
    xpd->ts = *ct;
  }
}


void packet_calc_rx_count (xpacket *xp)
{
  packet_calc_device_count(xp, &xp->xb->rx_pn, &xp->xdev->rx_pn, xp->pkt_len, &xp->ts);
}

void packet_calc_tx_count (xpacket *xp)
{
  packet_calc_device_count(xp, &xp->xb->tx_pn, &xp->xdev->tx_pn, xp->pkt_len, &xp->ts);
}



void get_packet_rx_count_dev (xbridge *xb,  xdevice *xdev, xpkt_cnt *pcnt)
{
  xfire_read_lock();
  rte_memcpy(pcnt, &xdev->rx_pn, sizeof(xpkt_cnt));
  xfire_read_unlock();
}

void get_packet_tx_count_dev (xbridge *xb,  xdevice *xdev, xpkt_cnt *pcnt)
{
  xfire_read_lock();
  rte_memcpy(pcnt, &xdev->tx_pn, sizeof(xpkt_cnt));
  xfire_read_unlock();
}

void get_packet_rx_count (xbridge *xb, xpkt_cnt *total)
{
  xfire_read_lock();
  rte_memcpy(total, &xb->rx_pn, sizeof(xpkt_cnt));
  xfire_read_unlock();
}

void get_packet_tx_count (xbridge *xb, xpkt_cnt *total)
{
  xfire_read_lock();
  rte_memcpy(total, &xb->tx_pn, sizeof(xpkt_cnt));
  xfire_read_unlock();
}

void reset_packet_rx_count (xbridge *xb)
{
  int i;

  xfire_write_lock();
  xpacket_reset_stats();
  memset(&xb->rx_pn, 0, sizeof(xpkt_cnt));
  for (i = 0; i < xb->xdev_num; i++) {
    memset(&xb->xdev[i].rx_pn, 0, sizeof(xpkt_cnt));
  }
  xfire_write_unlock();
}

void reset_packet_tx_count (xbridge *xb)
{
  int i;

  xfire_write_lock();
  memset(&xb->tx_pn, 0, sizeof(xpkt_cnt));
  for (i = 0; i < xb->xdev_num; i++) {
    memset(&xb->xdev[i].tx_pn, 0, sizeof(xpkt_cnt));
  }
  xfire_write_unlock();
}

