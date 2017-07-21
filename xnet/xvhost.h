#ifndef __XVHOST_H__
#define __XVHOST_H__

typedef struct _XVHOST {
  XRBTN32 node;

  ub32 my_ip;
  ub8  portid;

  ub32 netmask;
  ub32 router;
  ub32 dns_ip;
  ub32 lease_time;
} XVHOST;


void xvhost_create (void);
void xvhost_destroy (void);

void xvhost_add (xpacket *xp, ub32 ipaddr, ub32 netmask, ub32 router, ub32 dns, ub32 lease_time);
void xvhost_del (ub32 ipaddr);
int xvhost_find (ub32 ipaddr);

#endif
