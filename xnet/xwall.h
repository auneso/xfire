#ifndef __XWALL_H__
#define __XWALL_H__
#include "xbridge.h"
#include "xfilter.h"


void xwall_filter_create (void);
void xwall_filter_destroy (void);

void xwall_filter_add (char *filter_id, char *protocol, char *src_ip, char *src_port, char *dst_ip, char *dst_port,
                       char *priority, char *policy, char *enable, char *stime, char *etime);
void xwall_filter_del (char *filter_id);
void xwall_filter_apply (void);
int  xwall_filter_find (xpacket *xp);

Xftable **xwall_filter_array (int *count);

#endif

