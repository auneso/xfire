#include "xpint.h"
#include "xbridge.h"
#include "xnet.h"
#include "xarp.h"
#include "xroute.h"
#include "xsession.h"
#include "xdpdk.h"
#include "xwall.h"
#include "format.h"

static int xl3sw_rx_packet (xpacket *xp)
{
  if (xp->protocol & XNET_SESS_PROTOCOL) { /* tcp, udp, icmp */
    xsession_get(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_INBOUND);
  }
  return XNET_ACCEPT;
}

static const ub8 etherbcast[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
static int xl3sw_tx_packet (xpacket *xp)
{
  xdevice *xdev;
  XARP *arp;

  xpacket_calc_tx_count(xp);


  if (memcmp(etherbcast, xp->p_ethh->ether_dhost, 6) == 0) {
    xdpdk_broadcast_send(xp);
    return XNET_ACCEPT;
  } else
  if ((xdev = xroute_find_dev(xp->dst_ip))) {
    if ((arp = xarp_find_by_ip(xp->dst_ip, xp->ts.tv_sec))) {
      rte_memcpy(xp->p_ethh->ether_dhost, arp->mac, XETHER_ADDR_LEN);
      xdpdk_send_single_packet(xp->mbuf, xdev->portid);
      return XNET_ACCEPT;
    } 
  } else
  if ((arp = xarp_find_by_ip(xp->dst_ip, xp->ts.tv_sec))) {
    rte_memcpy(xp->p_ethh->ether_dhost, arp->mac, XETHER_ADDR_LEN);
    xdpdk_send_single_packet(xp->mbuf, arp->xdev->portid);
    return XNET_ACCEPT;
  } 
  return XNET_DROP;

/*
  if (memcmp(etherbcast, xp->p_ethh->ether_dhost, 6) == 0) {
    xdpdk_broadcast_send(xp);
  } else
  if ((xdev = xroute_find_dev(xp->dst_ip))) {
    if ((arp = xarp_find_by_ip(xp->dst_ip, xp->ts.tv_sec))) {
      rte_memcpy(xp->p_ethh->ether_dhost, arp->mac, XETHER_ADDR_LEN);
      xdpdk_send_single_packet(xp->mbuf, xdev->portid);
    } else return XNET_DROP; // drop
  } else
  if ((arp = xarp_find_by_ip(xp->dst_ip, xp->ts.tv_sec))) {
    rte_memcpy(xp->p_ethh->ether_dhost, arp->mac, XETHER_ADDR_LEN);
    xdpdk_send_single_packet(xp->mbuf, arp->xdev->portid);
  } else return XNET_DROP; // drop
  return XNET_ACCEPT;
*/
}

void xl3sw_create (xbridge *xb)
{
  xb->rx_packet = xl3sw_rx_packet;
  xb->tx_packet = xl3sw_tx_packet;
  xsession_table_create();
  xb->vmode = X_L3SW_MODE;
  printf("\n$$$$$ L3SW_MODE $$$$$\n");
}
