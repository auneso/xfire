#include "xpint.h"
#include "xbridge.h"
#include "xnet.h"
#include "xarp.h"
#include "xroute.h"
#include "xsession.h"
#include "xdpdk.h"
#include "xwall.h"

static ub64 rx_cnt = 0;
static time_t rx_time = 0;

static int xinline_rx_packet (xpacket *xp)
{
  if (xp->ts.tv_sec > rx_time) {
    rx_time =  xp->ts.tv_sec;
    printf("inline rx pkts = %lu\n", rx_cnt);
  }
  rx_cnt++;

  return XNET_ACCEPT;
}

static int xinline_tx_packet (xpacket *xp)
{
  xdpdk_send_single_packet(xp->mbuf, xp->xdev->portid ^ 1);
  return XNET_ACCEPT;
}


void xinline_create (xbridge *xb)
{
  xb->rx_packet = xinline_rx_packet;
  xb->tx_packet = xinline_tx_packet;
  xb->vmode = X_INLINE_MODE;
  printf("\n$$$$$ INLINE_MODE $$$$$\n");
}
