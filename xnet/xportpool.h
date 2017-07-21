#ifndef __XPORTPOOL_H__
#define __XPORTPOOL_H__
#include "xrbt.h"
#include "xfmem.h"

    
typedef struct _xdport {
  XRBTN node;

  ub32 src_ip;
  ub32 dst_ip;
  ub16 dst_port;
  ub8 protocol;

  ub16 nport;
  xfmem_t *pool;
} xdport;

typedef struct _xsport{
   xdport  *xdp;
   ub16 port;
} xsport;

typedef struct _xportpool {
  XRBTR *dpp;
  ub16 sport, eport, nport;
} xportpool; 


xportpool *xportpool_create (ub16 sport, ub16 eport);
void       xportpool_destroy (xportpool *xpp);

xsport *xportpool_pop (xportpool *xpp, ub32 src_ip, ub32 dst_ip, ub16 dst_port, ub8 protocol);
void    xportpool_push(xsport *xsp);

int xportpool_count (xportpool *xpp, ub32 src_ip, ub32 dst_ip, ub16 dst_port, ub8 protocol);
#endif
