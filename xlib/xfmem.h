#ifndef __XFMEM_H__
#define __XFMEM_H__

#include "xtypes.h"
#include "xalloc.h"

struct xrecycle
{
  struct xrecycle *next;
};
typedef  struct xrecycle  xrecycle;

struct xfmem
{
  xrecycle *list;      /* list of malloced blocks */
  xrecycle *trash;     /* list of deleted items */
  ub32    item_size;   /* size of an item */
  ub32    log_size;    /* log_2 of number of items in a block */
  ub32    num_left;    /* number of items left in this block */
  ub32    init_items;  /* init item num */
  ub32    max_items;   /* mem alloc max num */
  ub32    alloc_items; /* mem alloc num */
};
typedef  struct xfmem  xfmem_t;

void  xfmem_init (xfmem_t *r, int item_size, int items);
void  xfmem_clean (xfmem_t *r);

xfmem_t *xfmem_create (int item_size, int items);
void     xfmem_destroy (xfmem_t *r);

void *xfmem_malloc (xfmem_t *r);
char *xfmem_zalloc (xfmem_t *r);
void xfmem_free(xfmem_t *r, void *item); 

#define xfmem_max_items(root) root->max_items 


#endif 
