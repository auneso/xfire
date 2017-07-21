/*
** --------------------------------------------------------------------
** By Bob Jenkins.  hash.h
** 
** This implements a hash table.
** * Keys are unique.  Adding an item fails if the key is already there.
** * Keys and items are pointed at, not copied.  If you change the value
**   of the key after it is inserted then hfind will not be able to find it.
** * The hash table maintains a position that can be set and queried.
** * The table length doubles dynamically and never shrinks.  The insert
**   that causes table doubling may take a long time.
** * The table length splits when the table length equals the number of items
**   Comparisons usually take 7 instructions.
**   Computing a hash value takes 35+6n instructions for an n-byte key.
** 
**   hcreate  - create a hash table
**   hdestroy - destroy a hash table
**    hcount  - The number of items in the hash table
**    hkey    - key at the current position
**    hkeyl   - key length at the current position
**    hstuff  - stuff at the current position
**   hfind    - find an item in the table
**    hadd    - insert an item into the table
**    hdel    - delete an item from the table
**   hstat    - print statistics about the table
**    hfirst  - position at the first item in the table
**    hnext   - move the position to the next item in the table
** --------------------------------------------------------------------
*/


#ifndef __HASHTAB__
#define __HASHTAB__
#include "xfmem.h"
#include "xtypes.h"

/* PRIVATE TYPES AND DEFINITIONS */

typedef ub32           (*HashFunc)        (void *key, ub32 len);
typedef int            (*HashCmpFunc)     (void *a, void *b, ub32 len);

struct hitem
{
  ub8          *key;     /* key that is hashed */
  ub32         keyl;     /* length of key */
  void         *stuff;   /* stuff stored in this hitem */
  ub32         hval;     /* hash value */
  struct hitem *next;    /* next hitem in list */
};
typedef  struct hitem  hitem;


struct htab
{
  struct hitem  **table; /* hash table */
  int           pindex;  /* prime table index */
  ub32          tsize;   /* table size */
  ub32          count;   /* how many items in this hash table so far? */
  ub32          apos;    /* position in the array */
  struct hitem  *ipos;   /* current item in the array */
  xfmem_t       *space;  /* space for the hitems */
  HashFunc      hfunc;
  HashCmpFunc   hcmpf;
#ifdef HASH_STATS
  ub32  *depth; 
  ub32  add, del, collisions;
#endif
};
typedef  struct htab  htab;



/* PUBLIC FUNCTIONS */

/* hcreate - create a hash table
 * ARGUMENTS:
 *   hsize -  initial table length
 * RETURNS:
 *   the new table
 */
htab *hcreate3 (int  hsize, HashFunc hfunc, HashCmpFunc hcmpf);
htab *hcreate(int hsize);


/* hdestroy - destroy a hash table
 * ARGUMENTS:
 *   t - the hash table to be destroyed.  Note that the items and keys
 *       will not be freed, the user created them and must destroy
 *       them himself.
 * RETURNS:
 *   nothing
 */
void  hdestroy(htab *t);


/* hcount, hkey, hkeyl, hstuff
 *   ARGUMENTS:
 *   t - the hash table
 * RETURNS:
 *   hcount - (ub32)   The number of items in the hash table
 *   hkey   - (ub8 *)  key for the current item
 *   hkeyl  - (ub32)   key length for the current item
 *   hstuff - (void *) stuff for the current item
 * NOTE:
 *   The current position always has an item as long as there
 *     are items in the table, so hexist can be used to test if the
 *     table is empty.
 *   hkey, hkeyl, and hstuff will crash if hcount returns 0
 */
#define hcount(t) ((t)->count)
#define hkey(t)   ((t)->ipos->key)
#define hkeyl(t)  ((t)->ipos->keyl)
#define hstuff(t) ((t)->ipos->stuff)


/* hfind - move the current position to a given key
 * ARGUMENTS:
 *   t    - the hash table
 *   key  - the key to look for
 *   keyl - length of the key
 * RETURNS:
 *   TRUE if the item exists, FALSE if it does not.
 *   If the item exists, moves the current position to that item.
 */
int  hfind(htab *t, ub8 *key, ub32 keyl);


/* hadd - add a new item to the hash table
 *        change the position to point at the item with the key
 * ARGUMENTS:
 *   t     - the hash table
 *   key   - the key to look for
 *   keyl  - length of the key
 *   stuff - other stuff to be stored in this item
 * RETURNS:
 *   FALSE if the operation fails (because that key is already there).
 */
int  hadd(htab *t, ub8 *key, ub32 keyl, void *stuff);

void *hget (htab *t, ub8 *key, ub32 keyl, void *stuff, int *new);

/* hdel - delete the item at the current position
 *        change the position to the following item
 * ARGUMENTS:
 *   t    - the hash table
 * RETURNS:
 *   FALSE if there is no current item (meaning the table is empty)
 * NOTE:
 *   This frees the item, but not the key or stuff stored in the item.
 *   If you want these then deal with them first.  For example:
 *     if (hfind(tab, key, keyl))
 *     {
 *       free(hkey(tab));
 *       free(hstuff(tab));
 *       hdel(tab);
 *     }
 */
int  hdel_adjust(htab *t, int adjust);
#define hdel(t) hdel_adjust(t, 0)
#define hdelc(t) hdel_adjust(t, 1)


/* hfirst - move position to the first item in the table
 *  ARGUMENTS:
 *    t    - the hash table
 *  RETURNS:
 *    FALSE if there is no current item (meaning the table is empty)
 *  NOTE:
 */
int hfirst(htab *t);


/* hnext - move position to the next item in the table
 *  ARGUMENTS:
 *    t    - the hash table
 *  RETURNS:
 *    FALSE if the position wraps around to the beginning of the table
 *  NOTE:
 *    To see every item in the table, do
 *      if (hfirst(t)) do
 *      {
 *        key   = hkey(t);
 *        stuff = hstuff(t);
 *      }
 *      while (hnext(t));
 */
/* int hnext(htab *t); */
#define hnext(t) \
  ((!(t)->ipos) ? FALSE :  \
   ((t)->ipos=(t)->ipos->next) ? TRUE : hnbucket(t))

/* hnbucket - PRIVATE - move to first item in the next nonempty bucket
 *  ARGUMENTS:
 *    t    - the hash table
 *  RETURNS:
 *    FALSE if the position wraps around to the beginning of the table
 *  NOTE:
 *    This is private to hashtab; do not use it externally.
 */
int hnbucket(htab *t);


void **harray (htab *t);

#endif   /* __HASHTAB __*/

