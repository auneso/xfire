/*
** 2003/10/17 - HDS add
** 2009/03/31 - HDS  hashf.h
** 2011/03/04 - HDS  t&mask -> t%tize (prime table)
** 2013/12/04 - HDS  xxhash
** 2015/10/14 - HDS  hash fun, cmp
**
*/
/*
**--------------------------------------------------------------------
** By Bob Jenkins, 1996.  hashtab.c.  Public Domain.
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
**   hcount   - The number of items in the hash table
**   hkey     - key at the current position
**   hkeyl    - key length at the current position
**   hstuff   - stuff at the current position
**   hfind    - find an item in the table
**   hadd     - insert an item into the table
**   hdel     - delete an item from the table
**   hfirst   - position at the first item in the table
**   hnext    - move the position to the next item in the table
**   http://burtleburtle.net/bob/hash/hashtab.html
**   http://burtleburtle.net/bob/hash/perfect.html
** --------------------------------------------------------------------
*/
//#define HASH_STATS
#include <string.h>
#include "hashf.h"
#include "xxhash.h"
#include "hashtab.h"
#include "xalloc.h"


static ub32 hash_lookup (void *key, ub32 len)
{  return xxhash32(key, len); }

static int hash_cmp (void *key1, void *key2, ub32 len)
{  return !memcmp(key1, key2, len); }

#ifdef HSANITY
/* sanity check -- make sure ipos, apos, and count make sense */
static void  hsanity (htab *t)
{
  ub32    i, end, counter;
  hitem *h;

  /* test that apos makes sense */
  end = t->tsize;
  if (end < t->apos)
    printf("error:  end %ld  apos %ld\n", end, t->apos);

  /* test that ipos is in bucket apos */
  if (t->ipos) {
    for (h = t->table[t->apos];  h && h != t->ipos;  h = h->next)
      ;
    if (h != t->ipos)
      printf("error:ipos not in apos, apos is %ld\n", t->apos);
  }

  /* test that t->count is the number of elements in the table */
  counter = 0;
  for (counter = 0, i = 0;  i < end;  ++i)
    for (h = t->table[i]; h; h = h->next)
      ++counter;
  if (counter != t->count)
    printf("error: counter %ld  t->count %ld\n", counter, t->count);
}
#endif


static void hgrow (htab  *t)
{
  int     oldsize = t->tsize;
  int     newsize = prime_next_size(&t->pindex);
  int     i;
  hitem **oldtab = t->table;
  hitem **newtab = (hitem **)xzalloc(newsize*sizeof(hitem *));

  /* make sure newtab is cleared */
  t->table = newtab;
  t->tsize = newsize;

  /* Walk through old table putting entries in new table */
  for (i = oldsize; i--;) {
    hitem *this, *that, **newplace;
    for (this = oldtab[i]; this;) {
      that = this;
      this = this->next;
      newplace = &newtab[(that->hval % newsize)];
      that->next = *newplace;
      *newplace = that;
    }
  }
  hfirst(t);
  xfree((char *)oldtab);
}

/* hcreate - create a hash table initially of size prime number */
htab *hcreate3 (int  hsize, HashFunc hfunc, HashCmpFunc hcmpf) 
{
  int tsize;
  htab *t = (htab *)xmalloc(sizeof(htab));

  tsize = prime_size(hsize, &t->pindex);
  t->table = (hitem **)xzalloc(sizeof(hitem *) * (ub32)tsize);
  t->tsize = tsize;
  t->count = 0;
  t->apos  = (ub32)0;
  t->ipos  = (hitem *)0;
  t->space = xfmem_create(sizeof(hitem), 0);

  t->hfunc = hfunc;
  t->hcmpf = hcmpf;

#ifdef HASH_STATS
  t->depth = (ub32 *)xzalloc(sizeof(ub32) * (ub32)tsize);
  t->add = t->del = t->collisions = 0;
#endif
  return t;
}

htab *hcreate (int  hsize)
{
  return hcreate3(hsize, hash_lookup, hash_cmp);
}

/* hdestroy - destroy the hash table and free all its memory */
void hdestroy (htab  *t)
{
  xfmem_destroy(t->space);
  xfree(t->table);
  xfree(t);
}

/* hcount() is a macro, see hashtab.h */
/* hkey()   is a macro, see hashtab.h */
/* hkeyl()  is a macro, see hashtab.h */
/* hstuff() is a macro, see hashtab.h */

/* hfind - find an item with a given key in a hash table */
int hfind (htab *t, ub8 *key, ub32 keyl)
{
  hitem *h;
  ub32  x = t->hfunc(key, keyl);
  ub32  y = x % t->tsize;

  for (h = t->table[y]; h; h = h->next) {
    if ((x == h->hval) && (keyl == h->keyl) && t->hcmpf(key, h->key, keyl)) {
      t->apos = y;
      t->ipos = h;
      return TRUE;
    }
  }
  return FALSE;
}

/*
 * hadd - add an item to a hash table.
 * return FALSE if the key is already there, otherwise TRUE.
 */
int hadd (htab *t, ub8 *key, ub32 keyl, void *stuff)
{
  hitem  *h,**hp;
  ub32    x = t->hfunc(key, keyl);
  ub32    y = x % t->tsize;

  /* make sure the key is not already there */
  for (h = t->table[y]; h; h = h->next) {
    if ((x == h->hval) && (keyl == h->keyl) && t->hcmpf(key, h->key, keyl)) {
      t->apos = y;
      t->ipos = h;
      return FALSE;
    }
  }
#ifdef HASH_STATS
  if (h) t->collisions++;
  t->add++;
#endif
  /* find space for a new item */
  h = (hitem *)xfmem_malloc(t->space);

  /* make the hash table bigger if it is getting full */
  if (++t->count > t->tsize) {
    hgrow(t);
    y = (x % t->tsize);
  }

  /* add the new key to the table */
  h->key   = key;
  h->keyl  = keyl;
  h->stuff = stuff;
  h->hval  = x;
  hp = &t->table[y];
  h->next = *hp;
  *hp = h;
  t->ipos = h;
  t->apos = y;

#ifdef HASH_STATS
  t->depth[y]++;
#endif

#ifdef HSANITY
  hsanity(t);
#endif  /* HSANITY */

  return TRUE;
}

void *hget (htab *t, ub8 *key, ub32 keyl, void *stuff, int *new)
{
  hitem  *h,**hp;
  ub32    x = t->hfunc(key, keyl);
  ub32    y = x % t->tsize;

  /* make sure the key is not already there */
  for (h = t->table[y]; h; h = h->next) {
    if ((x == h->hval) && (keyl == h->keyl) && t->hcmpf(key, h->key, keyl)) {
      t->apos = y;
      t->ipos = h;
      if (new) *new = 0;
      return h->stuff;
    }
  }
#ifdef HASH_STATS
  if (h) t->collisions++;
  t->add++;
#endif
  /* find space for a new item */
  h = (hitem *)xfmem_malloc(t->space);

  /* make the hash table bigger if it is getting full */
  if (++t->count > t->tsize) {
    hgrow(t);
    y = (x % t->tsize);
  }

  /* add the new key to the table */
  h->key   = key;
  h->keyl  = keyl;
  h->stuff = stuff;
  h->hval  = x;
  hp = &t->table[y];
  h->next = *hp;
  *hp = h;
  t->ipos = h;
  t->apos = y;

#ifdef HASH_STATS
  t->depth[y]++;
#endif

#ifdef HSANITY
  hsanity(t);
#endif  /* HSANITY */
  if (new) *new = 1;
  return stuff;
}


/* hdel - delete the item at the current position */
int  hdel_adjust (htab *t, int adjust)
{
  hitem  *h;
  hitem **ip;

  /* check for item not existing */
  if (!(h = t->ipos)) return FALSE;

  /* remove item from its list */
  for (ip = &t->table[t->apos]; *ip != h; ip = &(*ip)->next)
    ;
  *ip = (*ip)->next;
  --(t->count);

  /* adjust position to something that exists */
  if (adjust && !(t->ipos = h->next)) hnbucket(t);

  xfmem_free(t->space, h);

#ifdef HASH_STATS
  t->depth[t->apos]--;
  t->del++;
#endif

#ifdef HSANITY
  hsanity(t);
#endif  /* HSANITY */
  return TRUE;
}

/* hfirst - position on the first element in the table */
int hfirst (htab *t)
{
  t->apos = t->tsize - 1;
  (void)hnbucket(t);
  return (t->ipos != (hitem *)0);
}

/* hnext() is a macro, see hashtab.h */

/*
 * hnbucket - Move position to the first item in the next bucket.
 * Return TRUE if we did not wrap around to the beginning of the table
 */
int hnbucket (htab *t)
{
  ub32  oldapos = t->apos;
  ub32  end = t->tsize;
  ub32  i;

  /* see if the element can be found without wrapping around */
  for (i = oldapos+1; i < end; ++i) {
    if (t->table[i % t->tsize]) {
      t->apos = i;
      t->ipos = t->table[i];
      return TRUE;
    }
  }

  /* must have to wrap around to find the last element */
  for (i = 0; i <= oldapos; ++i) {
    if (t->table[i]) {
      t->apos = i;
      t->ipos = t->table[i];
      return FALSE;
    }
  }
  return FALSE;
}

void **harray (htab *t)
{
  int used = t->count;
  void **table, **tptr;

  if (used == 0) return NULL;
  table = (void **) xmalloc(sizeof(void*)*(used));
  tptr = table;
  if (hfirst(t)) do {
    *tptr++ = hstuff(t);
  } while (hnext(t));

  return table;
}

#ifdef HASH_STATS
int hash_stats (htab *t, char* stats, size_t len) 
{
  int i, zero = 0, one = 0, two = 0, max = 0, width = t->tsize;
  float depth = 0, effic = 0;

  for (i = 0; i < width; i++) {
    if (t->depth[i] == 0) zero++; 
    if (t->depth[i] == 1) one++;
    if (t->depth[i] == 2) two++;
    if (t->depth[i] > max) max = t->depth[i];
    depth += t->depth[i];
  }
  depth = depth / t->tsize;
  effic = (float) t->collisions / ((float) t->add + 0.01) * 100.0;

  snprintf(stats, len, 
    "add: %d  del: %d  col: %d (%0.1f%%)  width: %d  depth: %0.1f avg, %d max, %d two, %d one, %d zero\n",
    t->add, t->del, t->collisions, effic, width, depth, max, two, one, zero);
  if (depth >= 2.0) return 1;
  return 0;
}

int hash_stats_print (htab *t) 
{
  int val;
  char stats[1024];

  val = hash_stats(t, stats, sizeof(stats));
  printf("%s\n", stats);
  if (val != 0) {
    printf("increase HASH_WIDTH in prefs.h and recompile to lower depth (improve efficiency)\n");
  }
  return val;
}
#endif
