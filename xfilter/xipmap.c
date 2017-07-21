/*
** 2008/10/17 - HDS add
** 2008/10/29 - HDS VALID_IP modify
** 2209/02/22 - HDS Amoeba RB Tree
** 2209/02/28 - HDS ip_create, ip_clone
** 2209/02/29 - HDS xipmap_lookup
** 2009/02/04 - HDS llist -> xvector
** 2013/02/22 - HDS xipmap_first, next
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "xtypes.h"
#include "format.h"
#include "xalloc.h"
#include "xstring.h"
#include "xprintf.h"
#include "xrbt.h"
#include "xvector.h"
#include "format.h"
#include "xiparser.h"
 

static int netcmp (void *a, void *b, void *user)
{
  unsigned int c1 = ((Xipnode*)a)->ns.min;
  unsigned int c2 = ((Xipnode*)b)->ns.min;
  if (c1 < c2) return -1;
  if (c1 > c2) return +1;
  return 0;
}

static void _create (Xipmap *map)
{
  map->root = rbtree_create(netcmp, 0, NULL);
}

void _destroy (Xipmap *map)
{
  rbtree_destroy(map->root);
}

static void _insert (Xipmap *map,  Xipnode *new)
{
  rbtree_insert(map->root, (RBTreeNode *)new);
}

static Xipnode * _first (Xipmap *map)
{
  return (Xipnode *)rbtree_first(map->root);
}

static Xipnode * _next (Xipnode *xip)
{
  return (Xipnode *)rbtree_next((RBTreeNode *)xip);
}

static Xipnode *_lookup (Xipmap *map, Xipnode *xip)
{
  return (Xipnode *)rbtree_lookup(map->root, (RBTreeNode *)xip, RBTREE_LTEQ);
}


static Xipnode *ip_create (Xipmap *map, unsigned int min,  unsigned int max, void *user)
{
  Xipnode *new;

  new = (Xipnode *)xfmem_malloc(map->mem);
  new->ns.min = min;
  new->ns.max = max;
  new->xvec = xvector_create(0);
  xvector_append(new->xvec, user);
  _insert(map, new);
  return new;
}

static Xipnode *ip_clone (Xipmap *map, unsigned int min,  unsigned int max, xvector *src)
{
  Xipnode *new;

  new = (Xipnode *)xfmem_malloc(map->mem);
  new->ns.min = min;
  new->ns.max = max;
  new->xvec = xvector_clone(src);
  _insert(map, new);
  return new;
}

Xipmap *xipmap_create (void)
{
  Xipmap *map = xmalloc(sizeof(Xipmap));
  _create(map);
  map->mem = xfmem_create(sizeof(Xipnode), 0);
  ip_create (map, 0,  0, NULL);                   /* begin ip */
  ip_create (map, 0xffffffff,  0xffffffff, NULL); /* end ip */
  return map;
}

void xipmap_destroy (Xipmap *map)
{
  Xipnode *xip;

  xip = _first(map);
  while (xip) {
    xvector_destroy(xip->xvec);
    xip = _next(xip);
  }

  _destroy(map);
  xfmem_destroy(map->mem);
  xfree(map);
}


/*== Amoeba RB Tree ==========================================================*/
void xipmap_insert (Xipmap *map, xnetspec *ns, void *user)
{
  Xipnode *old, *next, new;

  new.ns.min = ns->min;
  new.ns.max = ns->max;

next_map:
  old = _lookup(map, &new);

  /* old.min == new.min -----------------------------------------------------------*/
  if (old->ns.min == new.ns.min) {
    if (old->ns.max == new.ns.max) {                        /* case 1              */
      xvector_append(old->xvec, user);                      /* old  ============   */
      return;                                               /* new  ============   */
    }

    if (old->ns.max > new.ns.max) {                         /* case 2             */
      ip_clone(map, new.ns.max+1, old->ns.max, old->xvec);  /* old  ============  */
      old->ns.max = new.ns.max;                             /* new  =====         */
      xvector_append(old->xvec, user);
      return;
    }

    if (old->ns.max < new.ns.max) {                         /* case 3             */
      xvector_append(old->xvec, user);                      /* old =====          */
                                                            /* new ============   */
      new.ns.min = old->ns.max+1;
      goto next_map;
    }
  } else
  /* old.min < new.min -----------------------------------------------------------*/
  if (old->ns.max >= new.ns.min) {                          /* case 4             */
    unsigned int omax = old->ns.max;                        /* old  ============  */
    old->ns.max = new.ns.min-1;                             /* new    =======     */

    old = ip_clone(map, new.ns.min, omax, old->xvec);
    goto next_map;
  } else  /* old.max < new.ns.min  -----------------------------------------------*/
  {
    next = _next(old);
    if (next->ns.min > new.ns.max) {                        /* case 5              */
      ip_create(map, new.ns.min, new.ns.max, user);         /* old  ===      ===   */
      return;                                               /*  new     ====       */
    } else { /* next.min <= new.ns.max --------------------------------------------*/
      ip_create(map, new.ns.min, next->ns.min-1, user);     /* case 6              */
      new.ns.min = next->ns.min;                            /* old  ===    ===     */
      goto next_map;                                        /*  new     ====       */
    }
  }
}

static xvector *get_ip_vec (const char *cmd, xfmem_t *mem, int *ip_cnt)
{
  char *p, *t, *str;
  xvector *xvec;
  xnetspec *ns;
  int eol = 0;
  int cnt;
  
  *ip_cnt = 0;
  xvec = xvector_create(0);
  str = xstrdup((char *)cmd);
  p = rmallws(str);
  while (!eol) {
    t = p;
    while (*p && *p != ',') p++;
    if (*p == 0) eol = 1;
    if (t != p) {
      *p = 0;
      ns = (xnetspec *)xfmem_malloc(mem);
      if ((cnt = xip_parser (t, ns))) { /* OK */
        *ip_cnt += cnt; 
        xvector_append(xvec, ns);
      } else  {                   /* Error */
        xvector_destroy(xvec);
        *ip_cnt = 0;
        xvec = NULL;
        break;
      }
      if (eol) break;
      t = ++p;
    }
  }
  xfree(str);
  return xvec;
}

ub32 xipmap_insert_ip (Xipmap *map, ub32 start_ip, ub32 end_ip, void *user)
{
  xnetspec ns;
  ns.min = start_ip;
  ns.max = end_ip;

  xipmap_insert(map, &ns, user);
  return (end_ip - start_ip + 1); 
}

/* insert OK return ip_cnt, Error 0 */
ub32 xipmap_insert_cmd (Xipmap *map, const char *cmd,  void *user)
{
  xvector *xvec;
  xnetspec *ns;
  xfmem_t *mem;
  int ip_cnt = 0;

  if (!cmd  || !*cmd) return 0;

  mem = xfmem_create(sizeof(xnetspec), 0);
  xvec = get_ip_vec(cmd, mem, &ip_cnt);
  if (xvec) {
    if ((ns = (xnetspec *)xvector_first(xvec))) do {
      xipmap_insert(map, ns, user);
    } while ((ns = (xnetspec *)xvector_next(xvec)));
    xvector_destroy(xvec);
  } 

  xfmem_destroy(mem);
  return ip_cnt;
}

/* use after must free xvector */
xvector *xipmap_check_cmd (Xipmap *map, const char *cmd)
{
  xvector *xvec, *dvec;
  xnetspec *ns;
  Xipnode *xip, new;
  xfmem_t *mem;
  int ip_cnt = 0;

  mem = xfmem_create(sizeof(xnetspec), 0);
  xvec  = get_ip_vec(cmd, mem, &ip_cnt);
  if (xvec == NULL) {
    xfmem_destroy(mem);
    return NULL;
  }
  dvec = xvector_create(0);

  if ((ns = (xnetspec *)xvector_first(xvec))) do {
    new.ns.min = ns->min;
    new.ns.max = ns->max;
    xip = _lookup(map, &new);
    if (xip && ns->min >= xip->ns.min && ns->min <= xip->ns.max) {
      xvector_copy(dvec, xip->xvec);
      if (ns->min != ns->max &&  ns->max > xip->ns.max) {
        while ((xip = _next(xip)) && xip->ns.max <= ns->max) {
          xvector_copy(dvec, xip->xvec);
        }
      }
    }
  } while ((ns = (xnetspec *)xvector_next(xvec)));

  xvector_destroy(xvec);
  xfmem_destroy(mem);
  if (xvector_count(dvec)) return dvec;
  xvector_destroy(dvec);
  return NULL;
}


int xipmap_search (Xipmap *map, unsigned int ip)
{
  Xipnode *xip, new;

  new.ns.min = ip;
  new.ns.max = ip;
  xip = _lookup(map, &new);
  if (xip && ip >= xip->ns.min && ip <= xip->ns.max) return 1;
  return 0;
}

/* don't free xvector */
xvector *xipmap_lookup (Xipmap *map, unsigned int ip)
{
  Xipnode *xip, new;

  new.ns.min = ip;
  new.ns.max = ip;
  xip = _lookup(map, &new);
  if (xip && ip >= xip->ns.min && ip <= xip->ns.max) return xip->xvec;
  return NULL;
}

Xipnode *xipmap_first (Xipmap *map)
{
  Xipnode *xip;

  xip = _first(map);
  if (xip) return xip;
  return NULL;
}

Xipnode *xipmap_next (Xipnode *xip)
{
  Xipnode *nxip;
  nxip = _next(xip);
  if (xip) return nxip;
  return NULL;
}

ub32 xipmap_count (Xipmap *map)
{
  return rbtree_count(map->root);
}

int xipmap_dump (Xipmap *map)
{
  Xipnode *xn;
  int count = 0;

  printf("\nxipmap_dump\n");
  xn = _first(map);
  while (xn) {
    count++;
    printf("idx = %d, min = %s(%x), max = %s(%x), nodes = %d\n",
           count, intoa(xn->ns.min), xn->ns.min,
           intoa(xn->ns.max), xn->ns.max,
           xvector_count(xn->xvec));
    xn = _next(xn);
  }
  printf("\n");
  return(count);
}
