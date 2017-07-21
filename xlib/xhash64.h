
#ifndef __XHASH64_H__
#define __XHASH64_H__
#include "xfmem.h"
#include "xtypes.h"

struct xh64item
{
  ub64         key;      /*  key */
  ub32         hval;     /* hash value */
  struct xh64item *next;   /* next ihitem in list */
  char         stuff[1];  /* stuff stored in this ihitem */
};
typedef  struct xh64item  xh64item;


struct xh64tab
{
  struct xh64item **table;  /* hash table */
  int              pindex; /* prime number index */
  ub32             tsize;  /* hash table size */
  ub32             dsize;  /* data size */
  ub32             count;  /* how many items in this hash table so far? */
  ub32             apos;   /* position in the array */
  struct xh64item  *ipos;   /* current item in the array */
  xfmem_t         *space;  /* space for the ihitems */
#ifdef XHASH64_STATS
  int add, del, collisions;
#endif
};
typedef  struct xh64tab  xh64tab;


void   xh64init (xh64tab *t, int hsize, int dsize);
xh64tab *xh64create(int hsize, int dsize);
void   xh64destroy(xh64tab *t);
void   xh64renew(xh64tab *t, int hsize);
void   xh64free(xh64tab *t);
void   xh64clean(xh64tab *t);

#define xh64count(t) ((t)->count)
#define xh64key(t)   ((t)->ipos->key)
#define xh64stuff(t) ((t)->ipos->stuff)


int xh64find(xh64tab *t, ub64 key);
void *xh64search(xh64tab *t, ub64 key);
void *xh64get(xh64tab *t, ub64 key, int *new);
int xh64del_adjust(xh64tab *t, int adjust);

#define xh64del(t) xh64del_adjust(t,0)
#define xh64delc(t) xh64del_adjust(t,1)

int xh64first(xh64tab *t);

#define xh64next(t) \
  ((!(t)->ipos) ? FALSE :  \
   ((t)->ipos = (t)->ipos->next) ? TRUE : xh64nbucket(t))

int xh64nbucket(xh64tab *t);

void **xh64array (xh64tab *t);

#ifdef XHASH64_STATS
int xh64ash_stats (xh64tab *t, char* stats, int len);
#endif
#endif   /* __XHASH64_H__*/

