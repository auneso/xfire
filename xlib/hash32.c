#include <string.h>
#include "hash32.h"
#include "hashf.h"
#include "xalloc.h"


/*
 * By Bart Massey, based on Knuth LCG.
 * Do an extra multiply to get the middle 32 bits
 * of the 64 bit product.
 */
static inline unsigned int barthash (unsigned int k)
{
  /* 0x9e375365UL == 40499 * 65543 - both are prime;
     the result is ~0.68*(2^32) --Chuck Lever */

  return (0x9e37 * (k & 0xffff) + 0x5365 * (k >> 16));
}

static void h32grow (h32tab  *t)
{
  int     oldsize = t->tsize; 
  int     newsize = prime_next_size(&t->pindex);
  int     i;
  h32item **oldtab = t->table;
  h32item **newtab = (h32item **)xzalloc(newsize*sizeof(h32item *));

  t->table = newtab;
  t->tsize = newsize;

  /* Walk through old table putting entries in new table */
  for (i = oldsize; i--;) {
    h32item *this, *that, **newplace;
    for (this = oldtab[i]; this;) {
      that = this;
      this = this->next;
      newplace = &newtab[(that->hval %  newsize)];
      that->next = *newplace;
      *newplace = that;
    }
  }
  h32first(t);
  xfree((char *)oldtab);
}

/*
static void h32shrink (hash32  *t)
{
}
*/

h32tab *h32create (int hsize) 
{
  int tsize;
  h32tab *t = (h32tab *)xmalloc(sizeof(h32tab));

  tsize = prime_size(hsize, &t->pindex);
  t->table = (h32item **)xzalloc(sizeof(h32item *)*(ub32)tsize);
  t->tsize   = tsize;
  t->count   = 0;
  t->apos    = (ub32)0;
  t->ipos    = (h32item *)0;
  t->space   = xfmem_create(sizeof(h32item), 0);

#ifdef IHASH_STATS
  t->add   = t->del = t->collisions = 0;
  t->depth = (int *)xzalloc(sizeof(int)*(ub32)tsize);
#endif
  return t;
}

void h32clean (h32tab  *t)
{
  xfmem_destroy(t->space);
  memset(t->table, 0, sizeof(h32item *)*(ub32)t->tsize);
  t->count = 0;
  t->apos    = (ub32)0;
  t->ipos    = (h32item *)0;
  t->space = xfmem_create(sizeof(h32item), 0);
#ifdef IHASH_STATS
  t->add   = t->del = t->collisions = 0;
  memset(t->depth, 0, sizeof(int)*(ub32)t->tsize);
#endif
}

void h32destroy (h32tab  *t)
{
  xfmem_destroy(t->space);
  xfree(t->table);
  xfree(t);
}


int h32find (h32tab *t, ub32 key)
{
  h32item *h;
  ub32  x = barthash(key);
  ub32  y = x % t->tsize;

  for (h = t->table[y]; h; h = h->next) {
    if (key == h->key) {
      t->apos = y;
      t->ipos = h;
      return TRUE;
    }
  }
  return FALSE;
}

int h32add (h32tab *t, ub32 key, void *stuff)
{
  h32item  *h,**hp;
  ub32    x = barthash(key);
  ub32    y = x % t->tsize;

  /* make sure the key is not already there */
  for (h = t->table[y]; h; h = h->next) {
    if (key == h->key) {
      t->apos = y;
      t->ipos = h;
      return FALSE;
    }
  }
#ifdef IHASH_STATS
  if (h) t->collisions++;
  t->add++;
#endif
  /* find space for a new item */
  h = (h32item *)xfmem_malloc(t->space);

  /* make the hash table bigger if it is getting full */
  if (++t->count > t->tsize) {
    h32grow(t);
    y = (x % t->tsize);
  }

  /* add the new key to the table */
  h->key   = key;
  h->hval  = x;
  h->stuff = stuff;
  hp = &t->table[y];
  h->next = *hp;
  *hp = h;
  t->ipos = h;
  t->apos = y;
#ifdef IHASH_STATS
  t->depth[y]++;
#endif
  return TRUE;
}


int h32del_adjust (h32tab *t, int adjust)
{
  h32item  *h;
  h32item **ip;

  /* check for item not existing */
  if (!(h = t->ipos)) return FALSE;

  /* remove item from its list */
  for (ip = &t->table[t->apos]; *ip != h; ip = &(*ip)->next)
    ;
  *ip = (*ip)->next;
  --(t->count);

  /* adjust position to something that exists */
  if (adjust && !(t->ipos = h->next)) h32nbucket(t);

  /* recycle the deleted ihitem node */
  xfmem_remove(t->space, h);
#ifdef IHASH_STATS
  t->del++;
  t->depth[t->apos]--;
#endif
  return TRUE;
}


int h32first (h32tab *t)
{
  t->apos = t->tsize - 1;
  (void)h32nbucket(t);
  return (t->ipos != (h32item *)0);
}

int h32nbucket (h32tab *t)
{
  ub32  oldapos = t->apos;
  ub32  end = t->tsize;
  ub32  i;

  /* see if the element can be found without wrapping around */
  for (i = oldapos + 1; i < end; ++i) {
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

void **h32array (h32tab *t)
{
  int used = t->count;
  void **table, **tptr;

  if (used == 0) return NULL;
  table = (void **) xmalloc(sizeof(void*)*(used));
  tptr = table;
  if (h32first(t)) do {
    *tptr++ = h32stuff(t);
  } while (h32next(t));

  return table;
}

#ifdef IHASH_STATS
int h32ash_stats (h32tab *t, char* stats, int len) 
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
  depth = depth / width;
  effic = (float) t->collisions / ((float) t->count + 0.01) * 100.0;

  snprintf(stats, len, 
    "add: %d  del:%d col: %d (%0.1f%%)  width: %d  depth: %0.1f avg, %d max, %d two, %d one, %d zero\n",
     t->add, t->del, t->collisions, effic, width, depth, max, two, one, zero);
  if (depth >= 2.0) return 1;
  return 0;
}
#endif
