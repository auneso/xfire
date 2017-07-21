#ifndef __XTRAFFIC_H__
#define __XTRAFFIC_H__

#include "xbridge.h"

void xtraffic_write_lock (void);
void xtraffic_write_unlock (void);
void xtraffic_read_lock (void);
void xtraffic_read_unlock (void);

void packet_calc_rx_count (xpacket *xp);
void reset_packet_rx_count (xbridge *xb);

void get_packet_rx_count_dev (xbridge *xb,  xdevice *xdev, xpkt_cnt *pcnt);
void get_packet_rx_count (xbridge *xb, xpkt_cnt *total);

void packet_calc_tx_count (xpacket *xp);
void reset_packet_tx_count (xbridge *xb);

void get_packet_tx_count_dev (xbridge *xb,  xdevice *xdev, xpkt_cnt *pcnt);
void get_packet_tx_count (xbridge *xb, xpkt_cnt *total);

#endif
