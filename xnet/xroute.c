/*
*/
#include <stdio.h>

#include "xtypes.h"
#include "xstring.h"
#include "format.h"
#include "xrbt.h"
#include "xnet.h"
#include "xpacket.h"
#include "xroute.h"
#include "xfire.h"


static xroute_ipv4 default_bcast_route = {
  .dst_ip   = XNET_IP4_BCAST,
  .netmask  = XNET_IP4_BCAST,
  .gateway  = 0,
  .metric   = 100,
  .portid   = 0
};

static XRBTR *xroute_table = NULL;

void xroute_save (void)
{
  FILE *fp;
  xroute_ipv4 *xr;

  if ((fp = fopen(XFIRE_ROUTE_CFG_FILE, "w+"))) {
    fprintf(fp, "#Destination  Gateway Genmask Metric PortID\n");
    if ((xr = (xroute_ipv4 *)xrbt_first(xroute_table))) do {
      fprintf(fp, "%s %s %s %u %u\n", intoa(xr->dst_ip), intoa(xr->gateway), intoa(xr->netmask), xr->metric, xr->portid);
    } while ((xr = (xroute_ipv4 *)xrbt_next((XRBTN *)xr)));

    fclose(fp);
  }
}

void xroute_load (void)
{
  FILE *fp;

  printf("xroute_load = %s\n", XFIRE_ROUTE_CFG_FILE);
  if ((fp = fopen(XFIRE_ROUTE_CFG_FILE, "r"))) {
    char buf[1024], *bptr[5];
    xroute_ipv4 *xr;
    int new, portid;
    xdevice *xdev;

    while (fgets(buf, sizeof(buf), fp)) {
      if (buf[0] == '#' || buf[0] == '\n') continue;
  
      if (msplit(buf, bptr, 5, " \t") == 5) {
        portid = atoi(bptr[4]);
        if ((xdev = xpacket_get_xdevice(portid)) == NULL) continue;
          
        xr = xrbt_mem_malloc(xroute_table);
        xr->dst_ip  = atoin(bptr[0]);
        xr->gateway = atoin(bptr[1]);
        xr->netmask = atoin(bptr[2]);
        xr->metric  = atoi(bptr[3]);
        xr->xdev    = xdev;
          
        xr = (xroute_ipv4 *)xrbt_insert(xroute_table, (XRBTN *)xr, &new);
        if (new) {
          xr->portid = portid;
        } else {
          xrbt_mem_free(xroute_table, xr);
        }
      }
    }
    fclose(fp);
  } else {
    xroute_save();
  }
}

static int xroute_compare (void *ka, void *kb)
{
  xroute_ipv4 *a = ka, *b = kb;

  /* Routes are sorted by (host side) netmask len, then by addr, then by metric. */
  if (a->netmask < b->netmask) return -1;
  if (b->netmask < a->netmask) return 1;

  if (a->dst_ip < b->dst_ip) return -1;
  if (b->dst_ip < a->dst_ip) return 1;

  if (a->metric < b->metric) return 1;
  if (a->metric > b->metric) return -1;

  return 0;
}

void xroute_create (void)
{
  xroute_table = xrbt_create(xroute_compare, sizeof(xroute_ipv4), 10);
  xroute_load();

  xroute_dump();
}

void xroute_destroy (void)
{
  xrbt_destroy(xroute_table);
}

xroute_ipv4 *xroute_find (ub32 addr)
{
  xroute_ipv4 *xr;

  
  if (addr == XNET_IP4_ANY) { 
    return NULL;
  } 

  if (addr != XNET_IP4_BCAST) {
    if ((xr = (xroute_ipv4 *)xrbt_last(xroute_table))) do {
      if ((addr & xr->netmask) == xr->dst_ip && xr->xdev->link == XDEV_LINK_UP) return xr;
    } while ((xr = (xroute_ipv4 *)xrbt_prev((XRBTN *)xr)));   
    return NULL;
  } 

  return &default_bcast_route;
}

ub32 xroute_get_gateway (ub32 addr)
{
  xroute_ipv4 *xr;

  if (!addr) return 0;

  xr = xroute_find(addr);
  if (!xr) return 0;
  return xr->gateway;
}

xdevice *xroute_find_dev (ub32 dst)
{
  if (!dst) return NULL;

  xdevice *xdev = NULL;
  xroute_ipv4 *xr;

  xr = xroute_find(dst);
  if (xr && xr->xdev) {
    xdev = xr->xdev;
  } 
  return xdev;
}

ub8 xroute_find_portid (ub32 dst)
{
  if (!dst) return 0;

  ub8 portid = 0;
  xroute_ipv4 *xr;

  xr = xroute_find(dst);
  if (xr && xr->xdev) {
    portid = xr->portid;
  }
  return portid;
}

int xroute_ipv4_add (ub32 dst_ip, ub32 netmask, ub32 gateway, ub32 metric, ub8 portid)
{
  xroute_ipv4 *xr;
  xdevice *xdev;
  int new;

  if ((xdev = xpacket_get_xdevice(portid)) == NULL) return -1;

  xr = xrbt_mem_malloc(xroute_table);

  xr->dst_ip  = dst_ip;
  xr->netmask = netmask;
  xr->metric  = metric;

  xr = (xroute_ipv4 *)xrbt_insert(xroute_table, (XRBTN *)xr, &new); 
  if (!new) { 
    xrbt_mem_free(xroute_table, xr);
    return -1;
  }

  xr->gateway = gateway;
  if (gateway == 0) {
    /* No gateway provided, use the link */
    xr->portid = portid;
    xr->xdev   = xdev;
  } else {
    xroute_ipv4 *r = xroute_find(gateway);
    if (!r) { /* Specified Gateway is unreachable */
      xrbt_remove(xroute_table, (XRBTN *)xr);
      xrbt_mem_free(xroute_table, xr);
      return -1;
    }

    if (r->gateway) { /* Specified Gateway is not a neighbor */
      xrbt_remove(xroute_table, (XRBTN *)xr);
      xrbt_mem_free(xroute_table, xr);
      return -1;
    }
    xr->portid = r->portid;
    xr->xdev    = r->xdev;
  }

  if (!xr->xdev) {
    xrbt_remove(xroute_table, (XRBTN *)xr);
    xrbt_mem_free(xroute_table, xr);
    return -1;
  }
  xroute_save();

  return 0;
}

int xroute_ipv4_del (ub32 dst_ip, ub32 netmask, ub32 metric)
{
  xroute_ipv4 key, *found;

  key.dst_ip  = dst_ip;
  key.netmask = netmask;
  key.metric  = metric;

  found = (xroute_ipv4 *)xrbt_search(xroute_table, (XRBTN *)&key);
  if (found) {
    xrbt_remove(xroute_table, (XRBTN *)found);
    xrbt_mem_free(xroute_table, found);

    xroute_save();
    return 0;
  }

  return -1;
}

void xroute_port_del (ub8 portid)
{
  xroute_ipv4 *xr;
  int cnt = 0, i;

  if ((xr = (xroute_ipv4 *)xrbt_last(xroute_table))) do {
    if (xr->portid == portid)  cnt++;
  } while ((xr = (xroute_ipv4 *)xrbt_prev((XRBTN *)xr)));

  for (i = 0; i < cnt; i++) {
    if ((xr = (xroute_ipv4 *)xrbt_last(xroute_table))) do {
      if (xr->portid == portid) {
        xrbt_remove(xroute_table, (XRBTN *)xr);
        xrbt_mem_free(xroute_table, xr);
        break;
      }
    } while ((xr = (xroute_ipv4 *)xrbt_prev((XRBTN *)xr)));
  } 
}


void xroute_reload (void)
{
  xrbt_destroy(xroute_table);
  xroute_table = xrbt_create(xroute_compare, sizeof(xroute_ipv4), 10);
  xroute_load();
}


void xroute_dump (void)
{
  xroute_ipv4 *xr;
  
  printf("==== route table count = %d ==============\n", xrbt_count(xroute_table));
  printf("#Destination  Gateway Genmask Metric PortID\n");
  if ((xr = (xroute_ipv4 *)xrbt_last(xroute_table))) do {
    printf("%s %s %s %u %u\n", intoa(xr->dst_ip), intoa(xr->gateway), intoa(xr->netmask), xr->metric, xr->portid);
  } while ((xr = (xroute_ipv4 *)xrbt_prev((XRBTN *)xr)));
}


