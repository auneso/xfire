#include "xalloc.h"
#include "xportpool.h"

static int comp (void *a, void *b)
{
  xdport *xa = (xdport *)a;
  xdport *xb = (xdport *)a;
  
  if (xa->src_ip == xb->src_ip) {
    if (xa->dst_ip == xb->dst_ip) {
      if (xa->dst_port == xb->dst_port) {
        return xa->protocol - xb->protocol;
      } else return xa->dst_port - xb->dst_port;
    } else return xa->dst_ip - xb->dst_ip;
  } else return xa->src_ip - xb->src_ip;
}

xportpool *xportpool_create (ub16 sport, ub16 eport)
{
  xportpool *xpp = xmalloc(sizeof(xportpool));
  xpp->dpp   = xrbt_create(comp, sizeof(xdport), 0);
  xpp->sport = sport;  xpp->eport = eport;
  xpp->nport = eport - sport + 1;
  return xpp;
}

void xportpool_destroy (xportpool *xpp)
{
  xdport *xdp;

  if ((xdp = (xdport *)xrbt_first(xpp->dpp))) do {
     if (xdp->pool) xfmem_destroy(xdp->pool);
  } while ((xdp = (xdport *)xrbt_next((XRBTN *)xdp)));

  xrbt32_destroy(xpp->dpp);
  xfree(xpp);
}

xsport *xportpool_pop (xportpool *xpp, ub32 src_ip, ub32 dst_ip, ub16 dst_port, ub8 protocol)
{
  int new;
  xdport *xdp, *key; 
  xsport *xsp = NULL;

  key = xrbt_mem_malloc(xpp->dpp);
  key->src_ip = src_ip;
  key->dst_ip = dst_ip;
  key->dst_port = dst_port;
  key->protocol = protocol;

  xdp = (xdport *)xrbt_insert(xpp->dpp, (XRBTN *)key, &new);
  if (new) {
    xdp->pool = xfmem_create(sizeof(xsport), xpp->eport - xpp->sport + 1);
    xsp = (xsport *)xfmem_malloc0(xdp->pool); 
    xsp->port = xpp->sport;
    xsp->xdp = xdp;
    xdp->nport = 1;
  } else {
    xrbt_mem_free(xpp->dpp, key); 
    if (xdp->nport < xpp->nport) {
      xsp = (xsport *)xfmem_malloc0(xdp->pool); 
      if (xsp->port == 0) xsp->port = xpp->sport + xdp->nport;
      xsp->xdp = xdp;
    xdp->nport++;
    } else {
      xsp = NULL; 
    }
  }
  return xsp;
}

void xportpool_push (xsport *xsp)
{
  if (xsp && xsp->xdp) {
    xdport *xdp = xsp->xdp;
    if (xdp->nport) {
      xfmem_t *pool = xsp->xdp->pool;
      xdp->nport--;
      xfmem_remove(pool, xsp);
    }
  }
}

int xportpool_count (xportpool *xpp, ub32 src_ip, ub32 dst_ip, ub16 dst_port, ub8 protocol)
{
  xdport *xdp, key;
  
  key.src_ip = src_ip;
  key.dst_ip = dst_ip;
  key.dst_port = dst_port;
  key.protocol = protocol;

  if ((xdp = (xdport *)xrbt_search(xpp->dpp, (XRBTN *)&key))) {
    return xdp->nport;
  }
 
  return 0;
}
