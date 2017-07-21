#ifndef __XPACKET_H__
#define __XPACKET_H__
/*
*/

#include <errno.h>
#include <sys/types.h>
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#include "xbridge.h"

#define XFIRE_WEB_SERVICE        1
#define XFIRE_SSL_SERVICE        2
#define XFIRE_FORMS_SERVICE      3
#define XFIRE_SAP_SERVICE        4
#define XFIRE_AJP_SERVICE        5
#define XFIRE_JEUS_WT_SERVICE    6
#define XFIRE_DTS_SERVICE        7
#define XFIRE_HTS_SERVICE        8

#define XFIRE_SIP_SERVICE       10
#define XFIRE_RTSP_SERVICE      11
#define XFIRE_RTMP_SERVICE      12

#define XFIRE_MAIL_SERVICE      20
#define XFIRE_SSH_SERVICE       21
#define XFIRE_DNS_SERVICE       22

#define XFIRE_TNS_SERVICE       23
#define XFIRE_TDS_SERVICE       24
#define XFIRE_MYSQL_SERVICE     25
#define XFIRE_PGSQL_SERVICE     26
#define XFIRE_SYBASE_SERVICE    27
#define XFIRE_DB2_SERVICE       28

#define XFIRE_MAX_DISSECT_SERVICE  240

#define XFIRE_SET_TCP_REVERSE  248
#define XFIRE_SET_UDP_REVERSE  249

#define XFIRE_SET_TCP_SERVICE  250
#define XFIRE_SET_UDP_SERVICE  251
#define XFIRE_SET_ICMP_SERVICE 252

#define XFIRE_TCP_SERVICE      253
#define XFIRE_UDP_SERVICE      254
#define XFIRE_ICMP_SERVICE     255


int is_rfc1918 (uint32_t iph4);

int  xpacket_create (void);
void xpacket_setup (void);
void xpacket_run_proc (void);
void xpacket_shutdown(void);

xbridge *xpacket_get_xbridge (void);

void xpacket_dissect(xpacket *xp, ub8 portid, struct timeval *ts);

void xpacket_stats (struct xbridge_eth_stats *stats);
void xpacket_reset_stats (void);
void xpacket_dev_stats (xdevice *xdev, struct xbridge_eth_stats *stats);

void xpacket_calc_tx_count (xpacket *xp);

void xpacket_get_rx_count_dev (xdevice *xdev, xpkt_cnt *pcnt);
void xpacket_get_tx_count_dev (xdevice *xdev, xpkt_cnt *pcnt);
void xpacket_get_rx_count (xpkt_cnt *total);
void xpacket_get_tx_count (xpkt_cnt *total);
void xpacket_reset_count (void);

int      xpacket_set_xdevice (ub8 portid, char *dev, ub8 *mac, ub32 speed);
xdevice *xpacket_get_xdevice (int port);
xdevice *xpacket_set_xdevice_type (int port, ub8 type);
char    *xpacket_get_xdevice_name (int port);

void xpacket_reject_source (xpacket *xp);
void xpacket_send_tcp (ub8 *src_mac, ub8 *dst_mac, ub32 src_ip, ub32 dst_ip, ub16 sport, ub16 dport,
                       ub32 seqn, ub32 ackn, ub32 window, ub16 id, ub8 flags, char *vlan);

void xpacket_set_reject_source (xpacket *xp);
 
void xpacket_send_request_arp (ub32 dst_ip);
void xpacket_send_request_arp_dev (xdevice *xdev, ub8 *src_mac, ub32 src_ip);

void unmarshal_vlan_pkt (xpacket *xp);
void marshal_vlan_pkt (xpacket *xp);

void xpacket_align (xpacket *xp);

void xpacket_dev_link_check (void);
int xpacket_link_down (ub8 portid);

xdevice **xpacket_xdev_table_array (int *cnt);

void xpacket_vlan_on (void);
int xpacket_get_dev_num (void);

void xpacket_set_rtx_mode (char *mode);

xpacket *xpacket_pkt_alloc (xdevice *xdev, xpacket *xp);

int xpacket_tx_packet (xpacket *xp);

void xpacket_dhcp_req (ub8 portid);

#endif /* __XPACKET_H__ */
