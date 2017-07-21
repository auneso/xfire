/*
** 2010/06/29 - HDS  add 
*/

#include <string.h>
#include "xipfind.h"
#include "xalloc.h"
#include "xvector.h"

typedef struct _xkey {
  int pidx;
  int cidx;
} xkey;


Xfip *xfip_create (void)
{
  Xfip *xf;

  xf = xzalloc(sizeof(Xfip));
  xf->xmap = xipmap_create();

  xf->htab  = hcreate(128);
  xf->space = xfmem_create(sizeof(Xftab), 0);

  return xf;
}

static void cmd_free (Xfip *xf)
{
  Xftab *xt;

 if (hfirst(xf->htab)) do {
    xt = hstuff(xf->htab);
    if (xt->ipv4str) xfree(xt->ipv4str);
  } while (hnext(xf->htab));
}

void xfip_destroy (Xfip *xf)
{
  if (xf) {
    xipmap_destroy(xf->xmap);
    cmd_free(xf);
    hdestroy(xf->htab);
    xfmem_destroy(xf->space);
    xfree(xf);
  }
}


int xfip_insert (Xfip *xf, int pidx, int cidx,  char *ip)
{
  xkey key;
  Xftab *xt;

  key.pidx = pidx;
  key.cidx = cidx;

  if (hfind(xf->htab, (ub8 *)&key, sizeof(xkey))) {
    xt = hstuff(xf->htab);

    xt->flags = XFTAB_UPDATE;

    if (ip) {
      if (xt->ipv4str) xfree(xt->ipv4str);
      xt->ipv4str = xstrdup(ip);   
    }
    return 1;
  } else {

    xt = (Xftab *)xfmem_malloc(xf->space);
    xt->pidx = pidx;   
    xt->cidx = cidx;   

    if (ip) xt->ipv4str = xstrdup(ip);   

    return hadd(xf->htab, (ub8 *)xt, sizeof(xkey), xt);
  }
}

int xfip_delete (Xfip *xf, int pidx, int cidx)
{
  xkey key;
  Xftab *xt;

  key.pidx = pidx;
  key.cidx = cidx;
  
  if (hfind(xf->htab, (ub8 *)&key, sizeof(xkey))) {
    xt = hstuff(xf->htab);

    xt->flags = XFTAB_DELETE;

    return 1;
  }
  return 0;
}

void  xfip_compile (Xfip *xf)
{
  Xftab *xt;
  Xipmap *xmap, *oldxmap;

  if (hcount(xf->htab) == 0) return;

  xmap = xipmap_create();

  if (hfirst(xf->htab)) do {
    xt = hstuff(xf->htab);
    if (xt->flags == XFTAB_DELETE) continue;

    if (xt->ipv4str) xipmap_insert_cmd(xmap, xt->ipv4str, xt);
  } while (hnext(xf->htab));    


  oldxmap = xf->xmap;
  xf->xmap = xmap;

  if (hfirst(xf->htab)) do {
    xt = hstuff(xf->htab);
    if (xt->flags == XFTAB_UPDATE)
      xt->flags = XFTAB_ACTIVE;
  } while (hnext(xf->htab));    
  
  
  if (hfirst(xf->htab)) do {
    xt = hstuff(xf->htab);
    if (xt->flags == XFTAB_DELETE) {
      if (xt->ipv4str) xfree(xt->ipv4str);
      xfmem_remove(xf->space, xt);
      hdel(xf->htab);
    }
  } while (hnext(xf->htab));    
  
  xipmap_destroy(oldxmap);
}

void  xfip_enable (Xfip *xf)
{
  xf->dorun = XFIP_ENABLE;
}

void  xfip_disable (Xfip *xf)
{
  xf->dorun = XFIP_DISABLE;;
}


/* don't free xvector */
xvector *xfip_search (Xfip *xf, unsigned int ip)
{
  return xipmap_lookup(xf->xmap, ip);
}


/* return value - found cidx, not found -1 */
int xfip_match (xvector *xv, int pidx)
{
  Xftab *xt;

  if (!xv) return -1;
  if ((xt = (Xftab *)xvector_first(xv))) do {
    if (xt->pidx == pidx) return xt->cidx;
  } while ((xt = (Xftab *)xvector_next(xv)));
  return -1;
}


