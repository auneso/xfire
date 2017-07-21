#ifndef __XARP_H__
#define __XARP_H__

#include "xrbt.h"
#include "xproto.h"
#include "xpacket.h"

//#define XARP_FAST_MAC_UPDATE

#define XARP_HEALTH_TIME         (3)  /* 3 sec */

/* Protocol and hardware address sizes */
#define MAX_PLN   16  /* to accommodate up to ipv6 (128bit) */
#define MAX_HLN   6

typedef struct _XARP {
  XRBTN32 node;
  
  ub32 ip; 
  ub8  mac[ETHER_ADDR_LEN];  
  xdevice *xdev;

  // GW_DEV_TYPE,XNAT_DEV_TYPE
  ub8  type;

  time_t htime;
} XARP;


void xarp_save_arp_info (void);
void xarp_load_arp_info (void);

void xarp_set_cache_timeout (int timeout);

void xarp_create_table (xbridge *xb);
void xarp_destroy_table (void);
void xarp_dissect (xpacket *xp);
XARP **xarp_get_table_array (int *xarp_cnt);

void xarp_add_dev_ip (ub32 ip, ub8 *mac, ub8 portid, ub8 type);
void xarp_put_dev_ip (ub32 ip, ub8 *mac, ub8 portid);

XARP *xarp_find_by_ip (ub32 ipaddr, time_t ct);
ub8  *xarp_find_mac_by_ip (ub32 ipaddr, time_t ct);
xdevice *xarp_find_xdev_by_ip (ub32 ipaddr);

void xarp_add_arp (ub32 ipaddr, ub8 *mac);
void xarp_update_arp (ub32 ipaddr, ub8 *mac);
void xarp_del_arp (ub32 ipaddr);
int  xarp_arp_count (void);
void xarp_del_arp_type (ub32 ipaddr, ub8 type);

void xarp_dump_arp_table (void);

int  xarp_get_mac_addr (const char *in, ub32 *n0, ub32 *n1, ub32 *n2, ub32 *n3, ub32 *n4, ub32 *n5);
void xarp_make_request_packet (xpacket *xp, ub8 *src_mac, ub32 src_ip, ub32 dst_ip);
void xarp_process_ip (xpacket *xp, int arp_op);

#ifdef XARP_MAC
typedef struct _XMAC {
  XRBTN64 node;

  ub8  mac[ETHER_ADDR_LEN];
  xdevice *xdev;

  // GW_DEV_TYPE,XNAT_DEV_TYPE
  ub8  type;

  time_t htime;
} XMAC;

int xarp_mac_count (void);
void xarp_put_dev_mac (ub8 *xmac, xdevice *xdev, time_t ct);
void xarp_add_dev_mac (ub8 *xmac, xdevice *xdev, time_t ct);
xdevice *xarp_find_by_mac (ub8 *macaddr);
void xarp_dump_mac_table (void);
#endif


typedef struct _XARP_VIRTUAL {
  XRBTN32 node;

  ub32 ip;
  xdevice *xdev;

  ub8  type;
} XARP_VIRTUAL;

XARP_VIRTUAL *xarp_add_virtual_mac (ub32 ip, ub8 portid, ub8 vmode);
XARP_VIRTUAL *xarp_find_virtual (ub32 ipaddr);

void xarp_del_virtual_mac (ub32 ip);
void xarp_clean_virtual_mac (void);
int  xarp_find_virtual_mac (ub32 ipaddr);
xdevice *xarp_find_virtual_dev (ub32 ipaddr);
void xarp_dump_virtual_mac (void);

void xarp_del_virtual_mac_type (ub32 ipaddr, ub8 type);
#endif
