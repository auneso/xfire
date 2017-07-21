#include <string.h>
#include "hash64.h"
#include "hashf.h"
#include "xalloc.h"


static ub32 hash6432shift (ub64 key)
{
  key = (~key) + (key << 18); // key = (key << 18) - key - 1;
  key = key ^ (key >> 31);
  key = key * 21;            // key = (key + (key << 2)) + (key << 4);
  key = key ^ (key >> 11);
  key = key + (key << 6);
  key = key ^ (key >> 22);
  return (ub32) key;
}

static void h64grow (h64tab  *t)
{
  int     oldsize = t->tsize; 
  int     newsize = prime_next_size(&t->pindex);
  int     i;
  h64item **oldtab = t->table;
  h64item **newtab = (h64item **)xzalloc(newsize*sizeof(h64item *));

  t->table = newtab;
  t->tsize = newsize;

  /* Walk through old table putting entries in new table */
  for (i = oldsize; i--;) {
    h64item *this, *that, **newplace;
    for (this = oldtab[i]; this;) {
      that = this;
      this = this->next;
      newplace = &newtab[(that->hval %  newsize)];
      that->next = *newplace;
      *newplace = that;
    }
  }
  h64first(t);
  xfree((char *)oldtab);
}

/*
static void h64shrink (hash64  *t)
{
}
*/

h64tab *h64create (int hsize) 
{
  int tsize;
  h64tab *t = (h64tab *)xmalloc(sizeof(h64tab));

  tsize = prime_size(hsize, &t->pindex);
  t->table = (h64item **)xzalloc(sizeof(h64item *)*(ub32)tsize);
  t->tsize   = tsize;
  t->count   = 0;
  t->apos    = (ub32)0;
  t->ipos    = (h64item *)0;
  t->space   = xfmem_create(sizeof(h64item), 0);
#ifdef IHASH_STATS
  t->add   = t->del = t->collisions = 0;
  t->depth = (int *)xzalloc(sizeof(int)*(ub32)tsize);
#endif
  return t;
}

void h64clean (h64tab  *t)
{
  xfmem_destroy(t->space);
  memset(t->table, 0, sizeof(h64item *)*(ub32)t->tsize);
  t->count = 0;
  t->apos    = (ub32)0;
  t->ipos    = (h64item *)0;
  t->space = xfmem_create(sizeof(h64item), 0);
#ifdef IHASH_STATS
  t->add   = t->del = t->collisions = 0;
  memset(t->depth, 0, sizeof(int)*(ub32)t->tsize);
#endif
}

void h64destroy (h64tab  *t)
{
  xfmem_destroy(t->space);
  xfree(t->table);
  xfree(t);
}

int h64find (h64tab *t, ub64 key)
{
  h64item *h;
  ub32  x = hash6432shift(key);
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

int h64add (h64tab *t, ub64 key, void *stuff)
{
  h64item  *h,**hp;
  ub32    x = hash6432shift(key);
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
  h = (h64item *)xfmem_malloc(t->space);

  /* make the hash table bigger if it is getting full */
  if (++t->count > t->tsize) {
    h64grow(t);
    y = (x % t->tsize);
  }

  /* add the new key to the table */
  h->key   = key;
  h->stuff = stuff;
  h->hval  = x;
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

int h64del_adjust (h64tab *t, int adjust)
{
  h64item  *h;
  h64item **ip;

  /* check for item not existing */
  if (!(h = t->ipos)) return FALSE;

  /* remove item from its list */
  for (ip = &t->table[t->apos]; *ip != h; ip = &(*ip)->next)
    ;
  *ip = (*ip)->next;
  --(t->count);

  /* adjust position to something that exists */
  if (adjust && !(t->ipos = h->next)) h64nbucket(t);

  /* recycle the deleted ihitem node */
  xfmem_free(t->space, h);
#ifdef IHASH_STATS
  t->del++;
  t->depth[t->apos]--;
#endif
  return TRUE;
}


int h64first (h64tab *t)
{
  t->apos = t->tsize - 1;
  (void)h64nbucket(t);
  return (t->ipos != (h64item *)0);
}

int h64nbucket (h64tab *t)
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

void **h64array (h64tab *t)
{
  int used = t->count;
  void **table, **tptr;

  if (used == 0) return NULL;
  table = (void **) xmalloc(sizeof(void*)*(used));
  tptr = table;
  if (h64first(t)) do {
    *tptr++ = h64stuff(t);
  } while (h64next(t));

  return table;
}

#ifdef IHASH_STATS
int h64hash_stats (h64tab *t, char* stats, int len) 
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
