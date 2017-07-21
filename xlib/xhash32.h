
#ifndef __XHASH32_H__
#define __XHASH32_H__
#include "xfmem.h"
#include "xtypes.h"


struct xh32item
{
  ub32         key;       /*  key */
  ub32         hval;      /* hash value */
  struct xh32item *next;   /* next ihitem in list */
  char         stuff[1];  /* stuff stored in this ihitem */
};
typedef  struct xh32item  xh32item;


struct xh32tab
{
  struct xh32item **table;  /* hash table */
  int              pindex; /* prime number index */
  ub32             tsize;  /* hash table size */
  ub32             dsize;  /* data size */
  ub32             count;  /* how many items in this hash table so far? */
  ub32             apos;   /* position in the array */
  struct xh32item  *ipos;   /* current item in the array */
  xfmem_t         *space;  /* space for the ihitems */
#ifdef XHASH32_STATS
  int add, del, collisions;
#endif
};
typedef  struct xh32tab  xh32tab;


void xh32init (xh32tab *t, int hsize, int dsize);
void xh32free (xh32tab *t);
xh32tab *xh32create (int hsize, int dsize);
void   xh32destroy (xh32tab *t);
void   xh32clean (xh32tab  *t);
void   xh32renew (xh32tab *t, int hsize);

#define xh32size(t) ((t)->tsize)
#define xh32count(t) ((t)->count)
#define xh32key(t)   ((t)->ipos->key)
#define xh32stuff(t) ((t)->ipos->stuff)

int xh32find (xh32tab *t, ub32 key);
void *xh32search (xh32tab *t, ub32 key);
void *xh32get (xh32tab *t, ub32 key, int *new);
int xh32del_adjust (xh32tab *t, int adjust);

#define xh32del(t) xh32del_adjust(t,0)
#define xh32delc(t) xh32del_adjust(t,1)

int xh32first(xh32tab *t);
#define xh32next(t) \
  ((!(t)->ipos) ? FALSE :  \
   ((t)->ipos = (t)->ipos->next) ? TRUE : xh32nbucket(t))

int xh32nbucket (xh32tab *t);

void **xh32array (xh32tab *t);

#ifdef XHASH32_STATS
int xh32ash_stats (xh32tab *t, char* stats, int len);
#endif
#endif   /* __XHASH32_H__*/

