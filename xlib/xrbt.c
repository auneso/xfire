
/*
** Red-black tree (symmetric binary B-trees)
**
** A red-black tree is a binary tree where each node has color as an extra
** attribute, either red or black. By constraining the coloring of the nodes it
** is ensured that the longest path from the root to a leaf is no longer than
** twice the length of the shortest path. This means that the tree is balanced.
** A red-black tree must satisfy these properties: 
** http://web.mit.edu/~emin/www/source_code/red_black_tree/index.html
**
** - The root is black 
** - All leaves are black. 
** - Red nodes can only have black children. 
** - All paths from a node to its leaves contain the same number of black nodes.
**
** 2011/12/28 HDS - add
** 2012/04/23 HDS - str, mem
** 2012/06/24 HDS - change xrbt_insert  return value
** 2012/07/24 HDS - cache alloc
** 2013/05/29 HDS - xrbt_delete
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "xalloc.h"
#include "xrbt.h"

/* desend order */
static inline int xrbt32_comp (void *a, void *b)
{
  ub32 c1 = ((XRBTN32 *)a)->key;
  ub32 c2 = ((XRBTN32 *)b)->key;
  if (c1 < c2) return -1;
  if (c1 > c2) return +1;
  return 0;
}

static inline int xrbt64_comp (void *a, void *b)
{
  ub64 c1 = ((XRBTN64 *)a)->key;
  ub64 c2 = ((XRBTN64 *)b)->key;
  if (c1 < c2) return -1;
  if (c1 > c2) return +1;
  return 0;
}

static inline int xrbtptr_comp (void *a, void *b)
{
  void *c1 = ((XRBTNPTR *)a)->key;
  void *c2 = ((XRBTNPTR *)b)->key;
  if (c1 < c2) return -1;
  if (c1 > c2) return +1;
  return 0;
}

static inline int xrbtstr_comp (void *a, void *b)
{
  char *c1 = ((XRBTNSTR *)a)->key;
  char *c2 = ((XRBTNSTR *)b)->key;
  return strcmp(c1, c2);
}

static inline int xrbtmem_comp (void *a, void *b)
{
  XRBTNMEM *c1 = (XRBTNMEM *)a;
  XRBTNMEM *c2 = (XRBTNMEM *)b;
  if (c1->klen == c1->klen) return memcmp(c1->key, c2->key, c1->klen);
  return c1->klen - c2->klen;
}

/*
 * This is a "safe" test for the red-ness of a child which may be NULL; 
 * NULL is considered "black".
 */
#define IS_RED(node)        (((node) != NULL) && ((node)->is_red))

static void rotate_left (XRBTR *t, XRBTN *x)
{
  XRBTN *y = x->right;

  if ((x->right = y->left))
    y->left->parent = x;

  if ((y->parent = x->parent)) {
    if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
  } else 
    t->root = y;

  y->left   = x;
  x->parent = y;
}

static void rotate_right (XRBTR *t, XRBTN *x)
{
  XRBTN *y = x->left;

  if ((x->left = y->right))
    y->right->parent = x;

  if ((y->parent = x->parent)) {
    if (x == x->parent->right)
      x->parent->right = y;
    else
      x->parent->left = y;
  } else 
    t->root = y;

  y->right  = x;
  x->parent = y;
}

static void delete_fixup (XRBTR *t, XRBTN *node, XRBTN *node_parent)
{
  XRBTN *w, *x, *x_parent;

  x = node;
  x_parent = node_parent;

  while ((x != t->root) && (!IS_RED(x))) {
    if (x == x_parent->left) {
      w = x_parent->right;
      if (w->is_red) {
        w->is_red = 0;
        x_parent->is_red = 1;
        rotate_left(t, x_parent);
        w = x_parent->right;
      }
      if (!IS_RED(w->left) && !IS_RED(w->right)) {
        w->is_red = 1;
        x = x_parent;
      } else {
        if (!IS_RED(w->right)) {
          w->left->is_red = 0;
          w->is_red = 1;
          rotate_right(t, w);
          w = x_parent->right;
        }
        w->is_red = x_parent->is_red;
        x_parent->is_red = 0;
        if (w->right)
          w->right->is_red = 0;
        rotate_left(t, x_parent);
        x = t->root;
      }
    } else {
      w = x_parent->left;
      if (w->is_red) {
        w->is_red = 0;
        x_parent->is_red = 1;
        rotate_right(t, x_parent);
        w = x_parent->left;
      }
      if (!IS_RED(w->right) && !IS_RED(w->left)) {
        w->is_red = 1;
        x = x_parent;
      } else {
        if (!IS_RED(w->left)) {
          w->right->is_red = 0;
          w->is_red = 1;
          rotate_left(t, w);
          w = x_parent->left;
        }
        w->is_red = x_parent->is_red;
        x_parent->is_red = 0;
        if (w->left)
          w->left->is_red = 0;
        rotate_right(t, x_parent);
        x = t->root;
      }
    }
    x_parent = x->parent;
  }
  if (x)
    x->is_red = 0;
}

void xrbt_init (XRBTR *xr, xrbt_comp_f compare, int dsize, int rnum)
{
  memset(xr, 0, sizeof(XRBTR));
  xr->compare = compare;
  xr->count   = 0;
  xr->max_cnt = 0;
  xr->int_cnt = rnum;
  xr->dsize   = dsize;
  xr->root    = NULL;
  xfmem_init(&xr->cache, dsize, rnum);
}
void xrbt32_init (XRBTR32 *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbt32_comp, dsize, rnum); }
void xrbt64_init (XRBTR64 *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbt64_comp, dsize, rnum); }
void xrbtptr_init (XRBTRPTR *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbtptr_comp, dsize, rnum); }
void xrbtstr_init (XRBTRSTR *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbtstr_comp, dsize, rnum); }
void xrbtmem_init (XRBTRMEM *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbtmem_comp, dsize, rnum); }

void xsrbt32_init (XSRBTR32 *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbt32_comp, dsize, rnum); }
void xsrbt64_init (XSRBTR64 *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbt64_comp, dsize, rnum); }
void xsrbtptr_init (XSRBTRPTR *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbtptr_comp, dsize, rnum); }
void xsrbtstr_init (XSRBTRSTR *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbtstr_comp, dsize, rnum); }
void xsrbtmem_init (XSRBTRMEM *xr, int dsize, int rnum)
{ xrbt_init(xr, xrbtmem_comp, dsize, rnum); }

void xrbt_clean (XRBTR *xr)
{
  xfmem_clean(&xr->cache);
  xr->count = 0;
  xr->max_cnt = 0;
  xr->root  = NULL;
}
void xrbt32_clean (XRBTR32 *xr)
{ xrbt_clean(xr); }
void xrbt64_clean (XRBTR64 *xr)
{ xrbt_clean(xr); }
void xrbtptr_clean (XRBTRPTR *xr)
{ xrbt_clean(xr); }
void xrbtstr_clean (XRBTRSTR *xr)
{ xrbt_clean(xr); }
void xrbtmem_clean (XRBTRMEM *xr)
{ xrbt_clean(xr); }

void xsrbt32_clean (XSRBTR32 *xr)
{ xrbt_clean(xr); }
void xsrbt64_clean (XSRBTR64 *xr)
{ xrbt_clean(xr); }
void xsrbtptr_clean (XSRBTRPTR *xr)
{ xrbt_clean(xr); }
void xsrbtstr_clean (XSRBTRSTR *xr)
{ xrbt_clean(xr); }
void xsrbtmem_free (XSRBTRMEM *xr)
{ xrbt_clean(xr); }


XRBTR *xrbt_create (xrbt_comp_f compare, int dsize, int rnum)
{
  XRBTR *xr;
  xr = xmalloc(sizeof(XRBTR));
  xrbt_init(xr, compare, dsize, rnum); 
  return xr;
}
XRBTR32 *xrbt32_create (int dsize, int rnum)
{ return xrbt_create (xrbt32_comp, dsize, rnum); }
XRBTR64 *xrbt64_create (int dsize, int rnum)
{ return xrbt_create (xrbt64_comp, dsize, rnum); }
XRBTRPTR *xrbtptr_create (int dsize, int rnum)
{ return xrbt_create (xrbtptr_comp, dsize, rnum); }
XRBTRSTR *xrbtstr_create (int dsize, int rnum)
{ return xrbt_create (xrbtstr_comp, dsize, rnum); }
XRBTRMEM *xrbtmem_create (int dsize, int rnum)
{ return xrbt_create (xrbtmem_comp, dsize, rnum); }

XSRBTR32 *xsrbt32_create (int dsize, int rnum)
{ return xrbt_create (xrbt32_comp, dsize, rnum); }
XSRBTR64 *xsrbt64_create (int dsize, int rnum)
{ return xrbt_create (xrbt64_comp, dsize, rnum); }
XSRBTRPTR *xsrbtptr_create (int dsize, int rnum)
{ return xrbt_create (xrbtptr_comp, dsize, rnum); }
XSRBTRSTR *xsrbtstr_create (int dsize, int rnum)
{ return xrbt_create (xrbtstr_comp, dsize, rnum); }
XSRBTRMEM *xsrbtmem_create (int dsize, int rnum)
{ return xrbt_create (xrbtmem_comp, dsize, rnum); }


void xrbt_destroy (XRBTR *xr)
{ xrbt_free(xr); xfree(xr); }
void xrbt32_destroy (XRBTR32 *xr)
{ xrbt_free(xr); xfree(xr); }
void xrbt64_destroy (XRBTR64 *xr)
{ xrbt_free(xr); xfree(xr); }
void xrbtptr_destroy (XRBTRPTR *xr)
{ xrbt_free(xr); xfree(xr); }
void xrbtstr_destroy (XRBTRSTR *xr)
{ xrbt_free(xr); xfree(xr); }
void xrbtmem_destroy (XRBTRMEM *xr)
{ xrbt_free(xr); xfree(xr); }

void xsrbt32_destroy (XSRBTR32 *xr)
{ xrbt_free(xr); xfree(xr); }
void xsrbt64_destroy (XSRBTR64 *xr)
{ xrbt_free(xr); xfree(xr); }
void xsrbtptr_destroy (XSRBTRPTR *xr)
{ xrbt_free(xr); xfree(xr); }
void xsrbtstr_destroy (XSRBTRSTR *xr)
{ xrbt_free(xr); xfree(xr); }
void xsrbtmem_destroy (XSRBTRMEM *xr)
{ xrbt_free(xr); xfree(xr); }

XRBTN *xrbt_search (XRBTR *t, XRBTN *n)
{
  XRBTN *walk;
  int stat = 0;

  walk = t->root;
  while (walk) {
    stat = t->compare(n, walk);
    if (stat == 0) {
      return walk;
    } else if (stat < 0) {
      walk = walk->left;
    } else {
      walk = walk->right;
    }
  }
  return NULL;
}
XRBTN32 *xrbt32_search (XRBTR32 *t, ub32 key) {  
  XRBTN32 n; n.key = key;
  return (XRBTN32 *)xrbt_search(t, &n.node);
}
XRBTN64 *xrbt64_search (XRBTR64 *t, ub64 key)
{ XRBTN64 n; n.key = key;
  return (XRBTN64 *)xrbt_search(t, &n.node);
}
XRBTNPTR *xrbtptr_search (XRBTRPTR *t, void *key)
{ XRBTNPTR n; n.key = key;
  return (XRBTNPTR *)xrbt_search(t, &n.node);
}
XRBTNSTR *xrbtstr_search (XRBTRSTR *t, char *key)
{ XRBTNSTR n; n.key = key;
  return (XRBTNSTR *)xrbt_search(t, &n.node);
}
XRBTNMEM *xrbtmem_search (XRBTRMEM *t, void *key, int klen)
{ XRBTNMEM n; n.key = key; n.klen = klen;
  return (XRBTNMEM *)xrbt_search(t, &n.node);
}


XSRBTN32 *xsrbt32_search (XSRBTR32 *t, ub32 key)
{ XSRBTN32 *ptr, n; n.key = key;
  ptr = (XSRBTN32 *)xrbt_search(t, &n.node);
  if (ptr) return (XSRBTN32 *)((char *)ptr - sizeof(spt_t));
  return ptr;
}
XSRBTN64 *xsrbt64_search (XSRBTR64 *t, ub64 key)
{ XSRBTN64 *ptr,n; n.key = key;
  ptr = (XSRBTN64 *)xrbt_search(t, &n.node);
  if (ptr) return (XSRBTN64 *)((char *)ptr - sizeof(spt_t));
  return ptr;
}
XSRBTNPTR *xsrbtptr_search (XSRBTRPTR *t, void *key)
{ XSRBTNPTR *ptr,n; n.key = key;
  ptr = (XSRBTNPTR *)xrbt_search(t, &n.node);
  if (ptr) return (XSRBTNPTR *)((char *)ptr - sizeof(spt_t));
  return ptr;
}
XSRBTNSTR *xsrbtstr_search (XSRBTRSTR *t, char *key)
{ XSRBTNSTR *ptr,n; n.key = key;
  ptr = (XSRBTNSTR *)xrbt_search(t, &n.node);
  if (ptr) return (XSRBTNSTR *)((char *)ptr - sizeof(spt_t));
  return ptr;
}
XSRBTNMEM *xsrbtmem_search (XSRBTRMEM *t, void *key, int klen)
{ XSRBTNMEM *ptr,n; n.key = key; n.klen = klen;
  ptr = (XSRBTNMEM *)xrbt_search(t, &n.node);
  if (ptr) return (XSRBTNMEM *)((char *)ptr - sizeof(spt_t));
  return ptr;
}


XRBTN *xrbt_first (const XRBTR *t)
{
  XRBTN *walk;

  walk = t->root;
  if (walk)
    while (walk->left) 
      walk = walk->left;

  return walk;
}
XRBTN32 *xrbt32_first (const XRBTR32 *t)
{ return (XRBTN32 *)xrbt_first(t); }
XRBTN64 *xrbt64_first (const XRBTR64 *t)
{ return (XRBTN64 *)xrbt_first(t); }
XRBTNPTR *xrbtptr_first (const XRBTRPTR *t)
{ return (XRBTNPTR *)xrbt_first(t); }
XRBTNSTR *xrbtstr_first (const XRBTRSTR *t)
{ return (XRBTNSTR *)xrbt_first(t); }
XRBTNMEM *xrbtmem_first (const XRBTRMEM *t)
{ return (XRBTNMEM *)xrbt_first(t); }


XSRBTN32 *xsrbt32_first (const XSRBTR32 *t)
{ XSRBTN32 *ptr =  (XSRBTN32 *)xrbt_first(t);
  if (ptr) return (XSRBTN32 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTN64 *xsrbt64_first (const XSRBTR64 *t)
{ XSRBTN64 *ptr = (XSRBTN64 *)xrbt_first(t);
  if (ptr) return (XSRBTN64 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNPTR *xsrbtptr_first (const XSRBTRPTR *t)
{ XSRBTNPTR *ptr = (XSRBTNPTR *)xrbt_first(t);
  if (ptr) return (XSRBTNPTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNSTR *xsrbtstr_first (const XSRBTRSTR *t)
{ XSRBTNSTR *ptr = (XSRBTNSTR *)xrbt_first(t);
  if (ptr) return (XSRBTNSTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNMEM *xsrbtmem_first (const XSRBTRMEM *t)
{ XSRBTNMEM *ptr = (XSRBTNMEM *)xrbt_first(t);
  if (ptr) return (XSRBTNMEM *)((char *)ptr - sizeof(spt_t)); return ptr;
}



XRBTN *xrbt_last (const XRBTR *t)
{
  XRBTN *walk;

  walk = t->root;
  if (walk)
    while (walk->right) 
      walk = walk->right;

  return walk;
}
XRBTN32 *xrbt32_last (const XRBTR32 *t)
{ return (XRBTN32 *)xrbt_last(t); }
XRBTN64 *xrbt64_last (const XRBTR64 *t)
{ return (XRBTN64 *)xrbt_last(t); }
XRBTNPTR *xrbtptr_last (const XRBTRPTR *t)
{ return (XRBTNPTR *)xrbt_last(t); }
XRBTNSTR *xrbtstr_last (const XRBTRSTR *t)
{ return (XRBTNSTR *)xrbt_last(t); }
XRBTNMEM *xrbtmem_last (const XRBTRMEM *t)
{ return (XRBTNMEM *)xrbt_last(t); }

XSRBTN32 *xsrbt32_last (const XSRBTR32 *t)
{ XSRBTN32 *ptr =  (XSRBTN32 *)xrbt_last(t);
  if (ptr) return (XSRBTN32 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTN64 *xsrbt64_last (const XSRBTR64 *t)
{ XSRBTN64 *ptr = (XSRBTN64 *)xrbt_last(t);
  if (ptr) return (XSRBTN64 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNPTR *xsrbtptr_last (const XSRBTRPTR *t)
{ XSRBTNPTR *ptr = (XSRBTNPTR *)xrbt_last(t);
  if (ptr) return (XSRBTNPTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNSTR *xsrbtstr_last (const XSRBTRSTR *t)
{ XSRBTNSTR *ptr = (XSRBTNSTR *)xrbt_last(t);
  if (ptr) return (XSRBTNSTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNMEM *xsrbtmem_last (const XSRBTRMEM *t)
{ XSRBTNMEM *ptr = (XSRBTNMEM *)xrbt_last(t);
  if (ptr) return (XSRBTNMEM *)((char *)ptr - sizeof(spt_t)); return ptr;
}

XRBTN *xrbt_prev (const XRBTN *node)
{
  XRBTN *walk;

  if (node->left) {
    walk = node->left;
    while (walk->right) 
      walk = walk->right;
  } else {
    const XRBTN *walk2 = node;

    walk = walk2->parent;
    while (walk && (walk2 == walk->left)) {
      walk2 = walk;
      walk = walk->parent;
    }
  }
  return walk;
}
XRBTN32 *xrbt32_prev (const XRBTN32 *n)
{ return (XRBTN32 *)xrbt_prev(&n->node); }
XRBTN64 *xrbt64_prev (const XRBTN64 *n)
{ return (XRBTN64 *)xrbt_prev(&n->node); }
XRBTNPTR *xrbtptr_prev (const XRBTNPTR *n)
{ return (XRBTNPTR *)xrbt_prev(&n->node); }
XRBTNSTR *xrbtstr_prev (const XRBTNSTR *n)
{ return (XRBTNSTR *)xrbt_prev(&n->node); }
XRBTNMEM *xrbtmem_prev (const XRBTNMEM *n)
{ return (XRBTNMEM *)xrbt_prev(&n->node); }

XSRBTN32 *xsrbt32_prev (const XSRBTN32 *n)
{ XSRBTN32 *ptr = (XSRBTN32 *)xrbt_prev(&n->node);
  if (ptr) return (XSRBTN32 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTN64 *xsrbt64_prev (const XSRBTN64 *n)
{ XSRBTN64 *ptr = (XSRBTN64 *)xrbt_prev(&n->node);
  if (ptr) return (XSRBTN64 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNPTR *xsrbtptr_prev (const XSRBTNPTR *n)
{ XSRBTNPTR *ptr = (XSRBTNPTR *)xrbt_prev(&n->node);
  if (ptr) return (XSRBTNPTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNSTR *xsrbtstr_prev (const XSRBTNSTR *n)
{ XSRBTNSTR *ptr = (XSRBTNSTR *)xrbt_prev(&n->node);
  if (ptr) return (XSRBTNSTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNMEM *xsrbtmem_prev (const XSRBTNMEM *n)
{ XSRBTNMEM *ptr = (XSRBTNMEM *)xrbt_prev(&n->node);
  if (ptr) return (XSRBTNMEM *)((char *)ptr - sizeof(spt_t)); return ptr;
}


XRBTN *xrbt_next (const XRBTN *node)
{
  XRBTN *walk;

  if (node->right) {
    walk = node->right;
    while (walk->left) 
      walk = walk->left;
  } else {
    const XRBTN *walk2 = node;

    walk = walk2->parent;
    while (walk && (walk2 == walk->right)) {
      walk2 = walk;
      walk = walk->parent;
    }
  }
  return walk;
}
XRBTN32 *xrbt32_next (const XRBTN32 *n)
{ return (XRBTN32 *)xrbt_next(&n->node); }
XRBTN64 *xrbt64_next (const XRBTN64 *n)
{ return (XRBTN64 *)xrbt_next(&n->node); }
XRBTNPTR *xrbtptr_next (const XRBTNPTR *n)
{ return (XRBTNPTR *)xrbt_next(&n->node); }
XRBTNSTR *xrbtstr_next (const XRBTNSTR *n)
{ return (XRBTNSTR *)xrbt_next(&n->node); }
XRBTNMEM *xrbtmem_next (const XRBTNMEM *n)
{ return (XRBTNMEM *)xrbt_next(&n->node); }

XSRBTN32 *xsrbt32_next (const XSRBTN32 *n)
{ XSRBTN32 *ptr = (XSRBTN32 *)xrbt_next(&n->node);
  if (ptr) return (XSRBTN32 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTN64 *xsrbt64_next (const XSRBTN64 *n)
{ XSRBTN64 *ptr = (XSRBTN64 *)xrbt_next(&n->node);
  if (ptr) return (XSRBTN64 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNPTR *xsrbtptr_next (const XSRBTNPTR *n)
{ XSRBTNPTR *ptr = (XSRBTNPTR *)xrbt_next(&n->node);
  if (ptr) return (XSRBTNPTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNSTR *xsrbtstr_next (const XSRBTNSTR *n)
{ XSRBTNSTR *ptr = (XSRBTNSTR *)xrbt_next(&n->node);
  if (ptr) return (XSRBTNSTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNMEM *xsrbtmem_next (const XSRBTNMEM *n)
{ XSRBTNMEM *ptr = (XSRBTNMEM *)xrbt_next(&n->node);
  if (ptr) return (XSRBTNMEM *)((char *)ptr - sizeof(spt_t)); return ptr;
}

XRBTN *xrbt_lookup (XRBTR *t, XRBTN *n, int mode)
{
  XRBTN *lastwalk = NULL, *walk, *found = NULL;
  int stat = 0;
  
  walk = t->root;
  while (walk) {
    stat = t->compare(n, walk);
    if (stat == 0) {
      found = walk;
      break;
    } else if (stat < 0) {
      lastwalk = walk;
      walk = walk->left;
    } else {
      lastwalk = walk;
      walk = walk->right;
    }
  }

  if (found) {
    if (mode == XRBT_GTEQ || mode == XRBT_LTEQ) return(found);
    else
    if (mode == XRBT_GREAT) return(xrbt_next(walk));
    else 
    if (mode == XRBT_LESS) return(xrbt_prev(walk));
  }
  else {
    if (mode == XRBT_GTEQ || mode == XRBT_GREAT) {
      if (stat > 0) return(xrbt_next(lastwalk));
      else return(lastwalk);
    }

    if (mode == XRBT_LTEQ || mode == XRBT_LESS) {
      if (stat < 0) return(xrbt_prev(lastwalk));
      else return(lastwalk);
    }
  }
  return(NULL);
}

XRBTN32 *xrbt32_lookup (XRBTR32 *t, ub32 key, int mode)
{ XRBTN32 n; n.key = key;
  return (XRBTN32 *)xrbt_lookup(t, &n.node, mode);
}
XRBTN64 *xrbt64_lookup (XRBTR64 *t, ub64 key, int mode)
{ XRBTN64 n; n.key = key;
  return (XRBTN64 *)xrbt_lookup(t, &n.node, mode);
}
XRBTNPTR *xrbtptr_lookup (XRBTRPTR *t, void *key, int mode)
{ XRBTNPTR n; n.key = key;
  return (XRBTNPTR *)xrbt_lookup(t, &n.node, mode);
}
XRBTNSTR *xrbtstr_lookup (XRBTRSTR *t, char *key, int mode)
{ XRBTNSTR n; n.key = key;
  return (XRBTNSTR *)xrbt_lookup(t, &n.node, mode);
}
XRBTNMEM *xrbtmem_lookup (XRBTRMEM *t, void *key, int klen, int mode)
{ XRBTNMEM n; n.key = key; n.klen = klen;
  return (XRBTNMEM *)xrbt_lookup(t, &n.node, mode);
}


XSRBTN32 *xsrbt32_lookup (XSRBTR32 *t, ub32 key, int mode)
{ XSRBTN32 *ptr, n; n.key = key;
  ptr = (XSRBTN32 *)xrbt_lookup(t, &n.node, mode);
  if (ptr) return (XSRBTN32 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTN64 *xsrbt64_lookup (XSRBTR64 *t, ub64 key, int mode)
{ XSRBTN64 *ptr, n; n.key = key;
  ptr = (XSRBTN64 *)xrbt_lookup(t, &n.node, mode);
  if (ptr) return (XSRBTN64 *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNPTR *xsrbtptr_lookup (XSRBTRPTR *t, void *key, int mode)
{ XSRBTNPTR *ptr, n; n.key = key;
  ptr = (XSRBTNPTR *)xrbt_lookup(t, &n.node, mode);
  if (ptr) return (XSRBTNPTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNSTR *xsrbtstr_lookup (XSRBTRSTR *t, char *key, int mode)
{ XSRBTNSTR *ptr, n; n.key = key;
  ptr = (XSRBTNSTR *)xrbt_lookup(t, &n.node, mode);
  if (ptr) return (XSRBTNSTR *)((char *)ptr - sizeof(spt_t)); return ptr;
}
XSRBTNMEM *xsrbtmem_lookup (XSRBTRMEM *t, void *key, int klen, int mode)
{ XSRBTNMEM *ptr, n; n.key = key; n.klen = klen;
  ptr = (XSRBTNMEM *)xrbt_lookup(t, &n.node, mode);
  if (ptr) return (XSRBTNMEM *)((char *)ptr - sizeof(spt_t)); return ptr;
}

static XRBTN *_xrbt_insert (XRBTR *t, XRBTN *n, int *new)
{
  XRBTN *x, *y;
  int stat = 0;
  
  n->left = n->right = n->parent = NULL;

  x = t->root;
  y = NULL;
  while (x) {
    y = x;
    stat = t->compare(n, x);
    if (stat == 0) {
      if (new) *new = 0;
      return x;
    } else if (stat < 0) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  n->parent = y;
  if (y == NULL)
    t->root = n;
  else if (stat < 0)
    y->left = n;
  else
    y->right = n;

  x = n;
  y = NULL;
  x->is_red = 1;
  while ((x != t->root) && (x->parent->is_red)) {
    if (x->parent == x->parent->parent->left) {
      y = x->parent->parent->right;
      if (IS_RED(y)) {
        x->parent->is_red = 0;
        y->is_red = 0;
        x->parent->parent->is_red = 1;
        x = x->parent->parent;
      } else {
        if (x == x->parent->right) {
          x = x->parent;
          rotate_left(t, x);
        }
        x->parent->is_red = 0;
        x->parent->parent->is_red = 1;
        rotate_right(t, x->parent->parent);
      }
    } else {
      y = x->parent->parent->left;
      if (IS_RED(y)) {
        x->parent->is_red = 0;
        y->is_red = 0;
        x->parent->parent->is_red = 1;
        x = x->parent->parent;
      } else {
        if (x == x->parent->left) {
          x = x->parent;
          rotate_right(t, x);
        }
        x->parent->is_red = 0;
        x->parent->parent->is_red = 1;
        rotate_left(t, x->parent->parent);
      }
    }
  }
  t->root->is_red = 0;
  t->count++;
  t->max_cnt++;
  if (new) *new = 1;
  return NULL;
}

XRBTN *xrbt_insert (XRBTR *t, XRBTN *n, int *new)
{ XRBTN *o;
  if ((o = (XRBTN *)_xrbt_insert(t, n, new))) return o;
  return n;
}
XRBTN32  *xrbt32_insert (XRBTR32 *t, ub32 key,  int *new)
{ XRBTN32 *o, *n = (XRBTN32 *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XRBTN32 *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return o;
  }
  memset((char *)n + sizeof(XRBTN32), 0, t->dsize - sizeof(XRBTN32));
  return n;
}
XRBTN64 *xrbt64_insert (XRBTR64 *t, ub64 key, int *new)
{ XRBTN64 *o, *n = (XRBTN64 *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XRBTN64 *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return o;
  }
  memset((char *)n + sizeof(XRBTN64), 0, t->dsize - sizeof(XRBTN64));
  return n;
}
XRBTNPTR *xrbtptr_insert (XRBTRPTR *t, void *key, int *new)
{ XRBTNPTR *o, *n = (XRBTNPTR *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XRBTNPTR *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return o;
  }
  memset((char *)n+sizeof(XRBTNPTR), 0, t->dsize - sizeof(XRBTNPTR));
  return n;
}
XRBTNSTR *xrbtstr_insert (XRBTRSTR *t, char *key, int *new)
{ XRBTNSTR *o, *n = (XRBTNSTR *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XRBTNSTR *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return o;
  }
  memset((char *)n+sizeof(XRBTNSTR), 0, t->dsize - sizeof(XRBTNSTR));
  return n;
} 
XRBTNMEM *xrbtmem_insert (XRBTRMEM *t, void *key, int klen, int *new)
{ XRBTNMEM *o, *n = (XRBTNMEM *)xfmem_malloc(&t->cache);
  n->key = key; n->klen = klen;
  if ((o = (XRBTNMEM *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return o;
  }
  memset((char *)n+sizeof(XRBTNMEM), 0, t->dsize - sizeof(XRBTNMEM));
  return n;
} 


XSRBTN32 *xsrbt32_insert (XSRBTR32 *t, ub32 key, int *new)
{ XSRBTN32 *o, *n = (XSRBTN32 *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XSRBTN32 *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return (XSRBTN32 *)((char *)o - sizeof(spt_t));
  }
  memset((char *)n+sizeof(XSRBTN32), 0, t->dsize - sizeof(XSRBTN32));
  return n;
}
XSRBTN64 *xsrbt64_insert (XSRBTR64 *t, ub64 key, int *new)
{ XSRBTN64 *o, *n = (XSRBTN64 *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XSRBTN64 *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return (XSRBTN64 *)((char *)o - sizeof(spt_t));
  }
  memset((char *)n+sizeof(XSRBTN64), 0, t->dsize - sizeof(XSRBTN64));
  return n;
}
XSRBTNPTR *xsrbtptr_insert (XSRBTRPTR *t, void *key, int *new)
{ XSRBTNPTR *o, *n = (XSRBTNPTR *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XSRBTNPTR *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return (XSRBTNPTR *)((char *)o - sizeof(spt_t));
  }
  memset((char *)n+sizeof(XSRBTNPTR), 0, t->dsize - sizeof(XSRBTNPTR));
  return n;
}
XSRBTNSTR *xsrbtstr_insert (XSRBTRSTR *t, char *key, int *new)
{ XSRBTNSTR *o, *n = (XSRBTNSTR *)xfmem_malloc(&t->cache);
  n->key = key;
  if ((o = (XSRBTNSTR *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return (XSRBTNSTR *)((char *)o - sizeof(spt_t));
  }
  memset((char *)n+sizeof(XSRBTNSTR), 0, t->dsize - sizeof(XSRBTNSTR));
  return n;
}
XSRBTNMEM *xsrbtmem_insert (XSRBTRMEM *t, void *key, int klen, int *new)
{ XSRBTNMEM *o, *n = (XSRBTNMEM *)xfmem_malloc(&t->cache);
  n->key = key; n->klen = klen;
  if ((o = (XSRBTNMEM *)_xrbt_insert(t, &n->node, new))) {
    xfmem_free(&t->cache, n);
    return (XSRBTNMEM *)((char *)o - sizeof(spt_t));
  }
  memset((char *)n+sizeof(XSRBTNMEM), 0, t->dsize - sizeof(XSRBTNMEM));
  return n;
}


void xrbt_remove (XRBTR *t, XRBTN *node)
{
  XRBTN *x, *y, *z = node;

  if (!z->left || !z->right) y = z;
  else                       y = xrbt_next(z);

  if (y->left) x = y->left;
  else         x = y->right;

  if (x) x->parent = y->parent;

  if (!y->parent) t->root = x;
  else if (y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;

  if (!y->is_red) delete_fixup(t, x, y->parent);

  if (y != z) {
    y->left = z->left;
    if (y->left) y->left->parent = y;

    y->right = z->right;
    if (y->right) y->right->parent = y;

    y->parent = z->parent;
    if (!z->parent) t->root = y;
    else if (z->parent->left == z) y->parent->left = y;
    else y->parent->right = y;

    y->is_red = z->is_red;
  }
  t->count--;
}

void xrbt32_remove (XRBTR32 *t, XRBTN32 *node)
{ xrbt_remove(t, &node->node); 
  xfmem_free(&t->cache, node);
}
void xrbt64_remove (XRBTR64 *t, XRBTN64 *node)
{ xrbt_remove(t, &node->node); 
  xfmem_free(&t->cache, node);
}
void xrbtptr_remove (XRBTRPTR *t, XRBTNPTR *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}
void xrbtstr_remove (XRBTRSTR *t, XRBTNSTR *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}
void xrbtmem_remove (XRBTRMEM *t, XRBTNMEM *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}


void xsrbt32_remove (XSRBTR32 *t, XSRBTN32 *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}
void xsrbt64_remove (XSRBTR64 *t, XSRBTN64 *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}
void xsrbtptr_remove (XSRBTRPTR *t, XSRBTNPTR *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}
void xsrbtstr_remove (XSRBTRSTR *t, XSRBTNSTR *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}
void xsrbtmem_remove (XSRBTRMEM *t, XSRBTNMEM *node)
{ xrbt_remove(t, &node->node);
  xfmem_free(&t->cache, node);
}


void xrbt32_delete (XRBTR32 *t, ub32 key)
{ XRBTN32 *node = xrbt32_search(t, key);
  if (node) xrbt32_remove(t, node);
}
void xrbt64_delete (XRBTR64 *t, ub64 key)
{ XRBTN64 *node = xrbt64_search(t, key);
  if (node) xrbt64_remove(t, node);
}
void xrbtptr_delete (XRBTRPTR *t, void *key) 
{ XRBTNPTR *node = xrbtptr_search(t, key);
  if (node) xrbtptr_remove(t, node);
}
void xrbtstr_delete (XRBTRSTR *t, char *key)
{ XRBTNSTR *node = xrbtstr_search(t, key);
  if (node) xrbtstr_remove(t, node);
}
void xrbtmem_delete (XRBTRMEM *t, void *key, int klen)
{ XRBTNMEM *node = xrbtmem_search(t, key, klen);
  if (node) xrbtmem_remove(t, node);
}

void xsrbt32_delete (XSRBTR32 *t, ub32 key)
{ XSRBTN32 *node = xsrbt32_search(t, key);
  if (node) xsrbt32_remove(t, node);
}
void xsrbt64_delete (XSRBTR64 *t, ub64 key)
{ XSRBTN64 *node = xsrbt64_search(t, key);
  if (node) xsrbt64_remove(t, node);
}
void xsrbtptr_delete (XSRBTRPTR *t, void *key)
{ XSRBTNPTR *node = xsrbtptr_search(t, key);
  if (node) xsrbtptr_remove(t, node);
}
void xsrbtstr_delete (XSRBTRSTR *t, char *key)
{ XSRBTNSTR *node = xsrbtstr_search(t, key);
  if (node) xsrbtstr_remove(t, node);
}
void xsrbtmem_delete (XSRBTRMEM *t, void *key, int klen)
{ XSRBTNMEM *node = xsrbtmem_search(t, key, klen);
  if (node) xsrbtmem_remove(t, node);
}

void *xrbt_mem_malloc (XRBTR *r)
{
  return xfmem_malloc(&r->cache);
}
void *xrbt_mem_zalloc (XRBTR *r)
{
  return xfmem_zalloc(&r->cache);
}
void xrbt_mem_free (XRBTR *r, void *ptr)
{
  xfmem_free(&r->cache, ptr);
}
