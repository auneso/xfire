/*
** 2009/02/17 - HDS  add
*/

 #include <string.h>
#include "xiport.h"
#include "format.h"
#include "xalloc.h"
#include "xvector.h"

typedef struct _xkey {
  int pidx;
  int cidx;
} xkey;


Xiport *xiport_create (void)
{
  Xiport *xf;

  xf = xzalloc(sizeof(Xiport));
  xf->xmap = xipmap_create();

  xf->htab  = hcreate(128);
  xf->space = xfmem_create(sizeof(Xipt), 0);

  return xf;
}

static void cmd_free (Xiport *xf)
{
  Xipt *xt;

 if (hfirst(xf->htab)) do {
    xt = hstuff(xf->htab);
    if (xt->ipv4str) xfree(xt->ipv4str);
    xportmap_destroy(xt->xp);
  } while (hnext(xf->htab));
}

void xiport_destroy (Xiport *xf)
{
  if (xf) {
    xipmap_destroy(xf->xmap);
    cmd_free(xf);
    hdestroy(xf->htab);
    xfmem_destroy(xf->space);
    xfree(xf);
  }
}

int xiport_insert2 (Xiport *xf, int pidx, int cidx,  char *ip, char *port)
{
  Xipt *xt;

  xt = (Xipt *)xfmem_malloc(xf->space);
  xt->pidx = pidx;
  xt->cidx = cidx;

  if (ip) xt->ipv4str = xstrdup(ip);
  if (port) {
    xt->xp = xportmap_create();
    xportmap_insert_cmd_one (xt->xp, port);
  }
  return hadd(xf->htab, (ub8 *)xt, sizeof(xkey), xt);
}

int xiport_insert (Xiport *xf, int cidx,  char *ip, char *port)
{
   return xiport_insert2 (xf, 0, cidx,  ip, port);
}

int xiport_delete2 (Xiport *xf, int pidx, int cidx)
{
  xkey key;
  Xipt *xt;

  key.pidx = pidx;
  key.cidx = cidx;

  if (hfind(xf->htab, (ub8 *)&key, sizeof(xkey))) {
    xt = hstuff(xf->htab);
    if (xt->ipv4str) xfree(xt->ipv4str);
    xportmap_destroy(xt->xp);
    xfmem_remove(xf->space, xt);
    hdel(xf->htab);
    return 1;
  }
  return 0;
}

int xiport_delete (Xiport *xf, int cidx)
{
  return xiport_delete2 (xf, 0, cidx);
}

void  xiport_compile (Xiport *xf)
{
  Xipt *xt;
  Xipmap *xmap, *oldxmap;

  if (hcount(xf->htab) == 0) return;

  xmap = xipmap_create();

  if (hfirst(xf->htab)) do {
    xt = hstuff(xf->htab);
    if (xt->ipv4str) xipmap_insert_cmd(xmap, xt->ipv4str, xt);
  } while (hnext(xf->htab));

  oldxmap = xf->xmap;

  xf->xmap = xmap;

  xipmap_destroy(oldxmap);
}


int xiport_search (Xiport *xf, unsigned int ip, unsigned short port)
{
  xvector *ixv;
  Xipt  *ixt;

  if (hcount(xf->htab) == 0) return -1;


  ixv = xipmap_lookup(xf->xmap, ip);
  if (!ixv) goto end_find;

  ixt = (Xipt *)xvector_first(ixv);
  while (ixt) {
    if (xportmap_search(ixt->xp, port)) {
      return ixt->cidx;
    }
    ixt = (Xipt *)xvector_next(ixv);
  }
end_find:
  return -1;

}

int xiport_find (Xiport *xf, unsigned int ip, unsigned short port)
{
  if (xiport_search (xf, ip, port) == -1) return 0;
  return 1;
}

xvector *xiport_lookup (Xiport *xf, unsigned int ip, unsigned short port)
{
  xvector *match;
  xvector *ixv;
  Xipt  *ixt;

  match = xvector_create(0);


  ixv = xipmap_lookup(xf->xmap, ip);
  if (!ixv) goto end_search;

  ixt = (Xipt *)xvector_first(ixv);
  while (ixt) {
    if (xportmap_search(ixt->xp, port)) {
      xvector_append(match, ixt);
    }
    ixt = (Xipt *)xvector_next(ixv);
  }
end_search:
  return match;
}

/* return value - found cidx, not found -1 */
int xiport_match (xvector *xv, int pidx)
{
  Xipt *xt;

  xt = (Xipt *)xvector_first(xv);
  while (xt) {
    if (xt->pidx == pidx) return xt->cidx;
    xt = (Xipt *)xvector_next(xv);
  }
  return -1;
}

/* must free -  xiport_search, xiport_match */
void xiport_match_free (xvector *xv)
{
  xvector_destroy(xv);
}

