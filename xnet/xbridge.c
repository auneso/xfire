/*
** 2016-12-22  HDS xbridge_generic_receive_offload_off
*/

/* cat /proc/sys/net/ipv4/tcp_fin_timeout */
/* echo 10 > /proc/sys/net/ipv4/tcp_fin_timeout */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "xstring.h"
#include "xbridge.h"
#include "xpacket.h"
#include "xsession.h"
#include "xdpdk.h"

#include "xinline.h"
#include "xl3sw.h"
#include "xnat.h"


xbridge *xbridge_create (void)
{
  xbridge *xb = xzalloc(sizeof(xbridge));
  return xb;
}

void xbridge_destroy (xbridge *xb)
{
  if (xb) xfree(xb);
}


int xbridge_set_xdevice (xbridge *xb, ub8 portid , char *dev, char *alias, ub8 *mac, ub32 speed)
{
  xdevice *xd;

  if (xb->xdev_num >= XDEV_MAX_NUMS) {
    printf("\nToo many open interface %s: %d\n", dev, xb->xdev_num);
    return -1;
  }

  xd = &xb->xdev[xb->xdev_num];
  memset(xd, 0,  sizeof(xdevice));
  xd->xb  = xb;
  xd->portid = portid;
  xd->speed = speed;
  xstrlcpy(xd->xdev, dev, XDEV_NAME_LEN);
  xstrlcpy(xd->alias, alias, XDEV_ALIAS_LEN);
  memcpy(xd->xmac, mac, XETHER_ADDR_LEN);

  xb->xdev_num++;
  return 0;
}

xdevice *xbridge_get_xdevice (xbridge *xb, int portid)
{
  if (xb) {
    int i;
    for (i = 0; i < xb->xdev_num; i++) {
      if (xb->xdev[i].portid == portid) return &xb->xdev[i];
    }
  }
  return NULL;
}


void xbridge_dev_stats (xbridge *xb, xdevice *xdev, struct xbridge_eth_stats *stats)
{
  struct rte_eth_stats port_statistics;
  rte_eth_stats_get(xdev->portid, &port_statistics);

  stats->ipackets = port_statistics.ipackets;  /**< Total number of successfully received packets. */
  stats->opackets = port_statistics.opackets;  /**< Total number of successfully transmitted packets.*/
  stats->ibytes   = port_statistics.ibytes;    /**< Total number of successfully received bytes. */
  stats->obytes   = port_statistics.obytes;    /**< Total number of successfully transmitted bytes. */
  stats->imissed  = port_statistics.imissed;   /**< Total of RX packets dropped by the HW */
  stats->ierrors  = port_statistics.ierrors;   /**< Total number of erroneous received packets. */
  stats->oerrors  = port_statistics.oerrors;   /**< Total number of failed transmitted packets. */
}

void xbridge_stats (xbridge *xb, struct xbridge_eth_stats *stats)
{
  int i;

  memset(stats, 0, sizeof(struct xbridge_eth_stats));
  for (i = 0; i < xb->xdev_num; i++) {
    struct rte_eth_stats port_statistics;
    rte_eth_stats_get(xb->xdev[i].portid, &port_statistics);
   
    stats->ipackets += port_statistics.ipackets;  /**< Total number of successfully received packets. */
    stats->opackets += port_statistics.opackets;  /**< Total number of successfully transmitted packets.*/
    stats->ibytes   += port_statistics.ibytes;    /**< Total number of successfully received bytes. */
    stats->obytes   += port_statistics.obytes;    /**< Total number of successfully transmitted bytes. */
    stats->imissed  += port_statistics.imissed;   /**< Total of RX packets dropped by the HW */
    stats->ierrors  += port_statistics.ierrors;   /**< Total number of erroneous received packets. */
    stats->oerrors  += port_statistics.oerrors;   /**< Total number of failed transmitted packets. */
  }
}         

void xbridge_reset_stats (xbridge *xb)
{
  int i;

  for (i = 0; i < xb->xdev_num; i++) {
    rte_eth_stats_reset(xb->xdev[i].portid);
  }
}

void xbridge_set_rtx_mode (xbridge *xb, int mode)
{
  switch (mode) {
    case X_NAT_MODE :  xnat_create(xb);    break;
    case X_L3SW_MODE : xl3sw_create(xb);   break;
    default :          xinline_create(xb); break;
  }
}
