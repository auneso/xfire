/*
** 2012-07-04 HDS
** 2015-02-09 HDS  init/max items
** 2017-03-20 HDS  xfmem_malloc0
*/

#include <string.h>
#include "xfmem.h"

#define XFMEM_RESTART    0
#define XFMEM_REMAX      32000

void xfmem_init (xfmem_t *r, int item_size, int items)
{
  r->list      = (xrecycle *)0;
  r->trash     = (xrecycle *)0;
  r->item_size = align(item_size);
  r->log_size  = XFMEM_RESTART;
  r->num_left  = r->alloc_items = 0;
  r->max_items = r->init_items = items;
  xfmem_free(r, xfmem_malloc(r));
}

void xfmem_clean (xfmem_t *r)
{
  xrecycle *temp;
  if (r->list) do {
    temp = r->list->next;
    xfree((char *)r->list);
    r->list = temp;
  } while (r->list);
}

xfmem_t *xfmem_create (int item_size, int items)
{
  xfmem_t *r = (xfmem_t *)xmalloc(sizeof(xfmem_t));
  xfmem_init(r, item_size, items);
  return r;
}

void xfmem_destroy (xfmem_t *r)
{
  xfmem_clean(r);
  xfree((char *)r);
}

static char *_xfmem_new (xfmem_t *r, int zero)
{
  xrecycle *temp;

  if (r->trash) {  /* pull a node off the trash heap */
    temp = r->trash;
    r->trash = temp->next;
  }
  else {         /* allocate a new block of nodes */
    if (r->log_size == XFMEM_RESTART && r->init_items) {
      r->num_left = r->item_size * r->init_items;
      ++r->log_size;
    } else {
      r->num_left = r->item_size * ((ub32)1 << r->log_size);
      if (r->num_left < XFMEM_REMAX) ++r->log_size;
    }
    if (zero) temp = (xrecycle *)xzalloc(sizeof(xrecycle) + r->num_left);
    else      temp = (xrecycle *)xmalloc(sizeof(xrecycle) + r->num_left);
    r->max_items += (r->num_left / r->item_size);

    temp->next = r->list;
    r->list = temp;
    r->num_left -= r->item_size;
    temp = (xrecycle *)((char *)(r->list + 1) + r->num_left);
  }
  return (char *)temp;
}

void *xfmem_malloc (xfmem_t *r) 
{
  void *ptr;
 
  if (r->num_left) ptr = ((char *)(r->list+1) + (r->num_left -= r->item_size));
  else             ptr = _xfmem_new(r, 0);
  r->alloc_items++;
  return ptr;
}

void xfmem_free(xfmem_t *r, void *item) 
{ 
  ((xrecycle *)item)->next = r->trash; 
  r->trash = (xrecycle *)(item);
  r->alloc_items--;
}

char *xfmem_zalloc (xfmem_t *r)
{
  char *temp = xfmem_malloc(r);
  (void)memset((void *)temp, 0, r->item_size);
  return temp;
}
  

