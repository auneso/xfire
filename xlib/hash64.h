
#ifndef __HASH64_H__
#define __HASH64_H__
#include "xfmem.h"
#include "xtypes.h"

/* PRIVATE TYPES AND DEFINITIONS */

struct h64item
{
  ub64         key;      /*  key */
  void         *stuff;   /* stuff stored in this ihitem */
  ub32         hval;     /* hash value */
  struct h64item *next;   /* next ihitem in list */
};
typedef  struct h64item  h64item;


struct h64tab
{
  struct h64item **table;  /* hash table */
  int              pindex; /* prime number index */
  ub32             tsize;  /* hash table size */
  ub32             count;  /* how many items in this hash table so far? */
  ub32             apos;   /* position in the array */
  struct h64item  *ipos;   /* current item in the array */
  xfmem_t         *space;  /* space for the ihitems */
#ifdef IHASH_STATS
  int          *depth;
  int add, del, collisions;
#endif
};
typedef  struct h64tab  h64tab;


h64tab *h64create(int hsize);
void   h64destroy(h64tab *t);
void   h64clean(h64tab  *t);

#define h64count(t) ((t)->count)
#define h64key(t)   ((t)->ipos->key)
#define h64stuff(t) ((t)->ipos->stuff)


int h64find(h64tab *t, ub64 key);
int h64add(h64tab *t, ub64 key, void *stuff);
int h64del_adjust(h64tab *t, int adjust);

#define h64del(t) h64del_adjust(t,0)
#define h64delc(t) h64del_adjust(t,1)

int h64first(h64tab *t);

#define h64next(t) \
  ((!(t)->ipos) ? FALSE :  \
   ((t)->ipos = (t)->ipos->next) ? TRUE : h64nbucket(t))

int h64nbucket(h64tab *t);

void **h64array (h64tab *t);

#ifdef IHASH_STATS
int h64ash_stats (h64tab *t, char* stats, int len);
#endif
#endif   /* __HASH64_H__*/

