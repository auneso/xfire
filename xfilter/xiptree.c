/*
** 2011/05/12 - HDS
** 2011/11/23 - HDS  xiptree_search ip_count check
** 2013/09/09 - HDS  xiptree_remove_ip
** 2015/12/18 - HDS  xiptree_ip_count
** 2017/04/03 - HDS  xiptree_make_weight_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "xtypes.h"
#include "xprintf.h"
#include "format.h"
#include "xvector.h"
#include "xstring.h"
#include "xiparser.h"
#include "xiptree.h"


static int netcmp (void *a, void *b, void *user)
{
  unsigned int c1 = ((Xipnode*)a)->ns.min;
  unsigned int c2 = ((Xipnode*)b)->ns.min;
  if (c1 < c2) return -1;
  if (c1 > c2) return +1;
  return 0;
}

static Xiptnode *ip_create (Xiptree *xit, unsigned int min,  unsigned int max, void *user)
{
  Xiptnode *new;

  new = (Xiptnode *)xfmem_malloc(xit->mem);
  new->ns.min = min;
  new->ns.max = max;
  new->user   = user;
  rbtree_insert(xit->root, (RBTreeNode *)new);
  xit->ip_count += (max - min + 1);
  return new;
}

Xiptree *xiptree_create (void)
{
  Xiptree *xit = xmalloc(sizeof(Xiptree));
  xit->root = rbtree_create(netcmp, 0, NULL);
  xit->mem = xfmem_create(sizeof(Xiptnode), 0);
  xit->ip_count = 0;
  return xit;
}

void xiptree_destroy (Xiptree *xit)
{
  xfmem_destroy(xit->mem);
  rbtree_destroy(xit->root);
  xfree(xit);
}

ub32 xiptree_insert_ip (Xiptree *xit, ub32 start_ip, ub32 end_ip,  void *user)
{
  Xiptnode *xip, new;

  new.ns.min = start_ip;
  new.ns.max = end_ip;

  xip = (Xiptnode *)rbtree_lookup(xit->root, (RBTreeNode *)&new, RBTREE_LTEQ);
  if (xip && ((start_ip >= xip->ns.min && start_ip <= xip->ns.max)
  || (end_ip >= xip->ns.min && end_ip <= xip->ns.max))) return 0;

  ip_create(xit, start_ip, end_ip, user);
  return (end_ip - start_ip + 1);
}

int xiptree_remove_ip (Xiptree *xit, ub32 start_ip, ub32 end_ip)
{
  Xiptnode *xip, old;

  old.ns.min = start_ip;
  old.ns.max = end_ip;

  xip = (Xiptnode *)rbtree_lookup(xit->root, (RBTreeNode *)&old, RBTREE_LTEQ);
  if (xip && start_ip == xip->ns.min && end_ip == xip->ns.max) {
    rbtree_remove(xit->root, (RBTreeNode *)&old);
    xfmem_remove(xit->mem, xip);
    return 1;
  }
  return 0;
}

static xvector *get_ip_vec (const char *cmd, xfmem_t *mem)
{
  char *p, *t, *str;
  xvector *xvec;
  xnetspec *ns;
  int eol = 0;

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
      if (xip_parser (t, ns)) { /* OK */
        xvector_append(xvec, ns);
      } else  {                   /* Error */
        xvector_destroy(xvec);
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

/* valid OK return 1, Error 0 */
int xiptree_valid_cmd (const char *cmd)
{
  int rv = 1;
  char *p, *t, *str;
  int eol = 0;
  xnetspec ns;

  str = xstrdup((char *)cmd);
  p = rmallws(str);
  while (!eol) {
    t = p;
    while (*p && *p != ',') p++;
    if (*p == 0) eol = 1;
    if (t != p) {
      *p = 0;
      if (!xip_parser(t, &ns)) { /* error */
        rv = 0;
        break;
      }
      if (eol) break;
      t = ++p;
    }
  }
  xfree(str);
  return rv;
}

/* insert OK return ip_cnt , Error 0 */
ub32 xiptree_insert_cmd (Xiptree *xit, const char *cmd,  void *user)
{
  xvector *xvec;
  xnetspec *ns;
  xfmem_t *mem;
  ub32 ip_cnt = 0;

  if (!xit || !cmd  || !*cmd) return 0;

  mem = xfmem_create(sizeof(xnetspec), 0);
  xvec = get_ip_vec(cmd, mem);
  if (xvec) {
    if ((ns = (xnetspec *)xvector_first(xvec))) do {
      if (xiptree_insert_ip(xit, ns->min, ns->max, user) == 0) {
        ip_cnt = 0;
        break;
      }
      ip_cnt += (ns->max - ns->min + 1); 
    } while ((ns = (xnetspec *)xvector_next(xvec)));
    xvector_destroy(xvec);
  } else ip_cnt = 0;
  xfmem_destroy(mem);
  return ip_cnt;
}

int xiptree_check_cmd (Xiptree *xit, const char *cmd)
{
  xvector *xvec;
  xnetspec *ns;
  Xiptnode *xip, new;
  xfmem_t *mem;
  int rv = 0;

  if (!xit || !cmd  || !*cmd) return 0;

  mem = xfmem_create(sizeof(xnetspec), 0);
  xvec  = get_ip_vec(cmd, mem);
  if (xvec) {
    if ((ns = (xnetspec *)xvector_first(xvec))) do {
      new.ns.min = ns->min;
      new.ns.max = ns->max;
      xip = (Xiptnode *)rbtree_lookup(xit->root, (RBTreeNode *)&new, RBTREE_LTEQ);
      if (xip && ((ns->min >= xip->ns.min && ns->min <= xip->ns.max)
      ||  (ns->max >= xip->ns.min && ns->max <= xip->ns.max))) {
        rv = 1; break;
      }
    } while ((ns = (xnetspec *)xvector_next(xvec)));
    xvector_destroy(xvec);
  }
  xfmem_destroy(mem);
  return rv;
}

int xiptree_search (Xiptree *xit, unsigned int ip)
{
  if (xit) {
    Xiptnode *xip, new;

    new.ns.min = ip;
    new.ns.max = ip;
    xip = (Xiptnode *)rbtree_lookup(xit->root, (RBTreeNode *)&new, RBTREE_LTEQ);
    if (xip && ip >= xip->ns.min && ip <= xip->ns.max) return 1;
  }
  return 0;
}

void *xiptree_lookup (Xiptree *xit, unsigned int ip)
{
  if (xit) {
    Xiptnode *xip, new;

    new.ns.min = ip;
    new.ns.max = ip;
    xip = (Xiptnode *)rbtree_lookup(xit->root, (RBTreeNode *)&new, RBTREE_LTEQ);
    if (xip && ip >= xip->ns.min && ip <= xip->ns.max) return xip->user;
  }
  return NULL;
}

int xiptree_table_count (Xiptree *xit)
{
  if (!xit) return 0;
  return rbtree_count(xit->root);
}

int xiptree_ip_count (Xiptree *xit)
{
  if (!xit) return 0;
  return xit->ip_count;
}


int xiptree_dump (Xiptree *xit)
{
  if (!xit) return 0;

  Xiptnode *xn;
  int count = 0;

  printf("\nxiptree_dump\n");
  if ((xn = (Xiptnode *)rbtree_first(xit->root))) do {
    count++;
    printf("idx = %d, min = %s(%x), max = %s(%x)\n", count, intoa(xn->ns.min), xn->ns.min, intoa(xn->ns.max), xn->ns.max);
  } while ((xn = (Xiptnode *)rbtree_next((RBTreeNode *)xn)));
  printf("\n");
  return(count);
}


XRBTR32 *xiptree_make_table (const char *cmd)
{
  xvector *xvec;
  xnetspec *ns;
  xfmem_t *mem;
  ub32 ip;
  XRBTR32 *ip_table;
  
  if (!cmd  || !*cmd) return 0;
  
  ip_table = xrbt32_create(sizeof(XRBTN32), 10);
  mem = xfmem_create(sizeof(xnetspec), 0);
  xvec = get_ip_vec(cmd, mem);
  if (xvec) {
    if ((ns = (xnetspec *)xvector_first(xvec))) do {
      for (ip = ns->min; ip <= ns->max; ip++) {
        xrbt32_insert(ip_table, ip, NULL);
      }      
    } while ((ns = (xnetspec *)xvector_next(xvec)));
    xvector_destroy(xvec);
  }
  xfmem_destroy(mem);
  return ip_table;
}
