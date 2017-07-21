#ifndef __XROUTE_H__
#define __XROUTE_H__

#include "xbridge.h"

typedef struct _xroute_ipv4
{
  XRBTN node;

  ub32 dst_ip;
  ub32 netmask;
  ub32 gateway;
  ub32 metric;
  ub8  portid;
  xdevice *xdev;
} xroute_ipv4;


void xroute_create (void);
void xroute_destroy (void);

xroute_ipv4 *xroute_find (ub32 addr);
ub32 xroute_get_gateway (ub32 addr);
ub8 xroute_find_portid (ub32 dst);
xdevice *xroute_find_dev (ub32 dst);

int xroute_ipv4_add (ub32 dst_ip, ub32 netmask, ub32 gateway, ub32 metric, ub8 portid);
int xroute_ipv4_del (ub32 dst_ip, ub32 netmask, ub32 metric);
xroute_ipv4 ** xroute_table_array(int *cnt);

void xroute_port_del (ub8 portid);
void xroute_reload (void);

void xroute_dump (void);
#endif
