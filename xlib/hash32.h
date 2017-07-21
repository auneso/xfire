
#ifndef __HASH32_H__
#define __HASH32_H__
#include "xfmem.h"
#include "xtypes.h"

/* PRIVATE TYPES AND DEFINITIONS */

struct h32item
{
  ub32         key;       /*  key */
  ub32         hval;      /* hash value */
  void         *stuff;  /* stuff stored in this ihitem */
  struct h32item *next;   /* next ihitem in list */
};
typedef  struct h32item  h32item;


struct h32tab
{
  struct h32item **table;  /* hash table */
  int              pindex; /* prime number index */
  ub32             tsize;  /* hash table size */
  ub32             count;  /* how many items in this hash table so far? */
  ub32             apos;   /* position in the array */
  struct h32item  *ipos;   /* current item in the array */
  xfmem_t         *space;  /* space for the ihitems */
#ifdef IHASH_STATS
  int          *depth;
  int add, del, collisions;
#endif
};
typedef  struct h32tab  h32tab;


h32tab *h32create(int hsize);
void   h32destroy(h32tab *t);
void   h32clean(h32tab  *t);

#define h32count(t) ((t)->count)
#define h32key(t)   ((t)->ipos->key)
#define h32stuff(t) ((t)->ipos->stuff)

int h32find(h32tab *t, ub32 key);
int h32add(h32tab *t, ub32 key, void *stuff);
int h32del_adjust(h32tab *t, int adjust);

#define h32del(t) h32del_adjust(t,0)
#define h32delc(t) h32del_adjust(t,1)

int h32first(h32tab *t);
#define h32next(t) \
  ((!(t)->ipos) ? FALSE :  \
   ((t)->ipos = (t)->ipos->next) ? TRUE : h32nbucket(t))

int h32nbucket(h32tab *t);

void **h32array (h32tab *t);

#ifdef IHASH_STATS
int h32ash_stats (h32tab *t, char* stats, int len);
#endif
#endif   /* __HASH32_H__*/

