/* 
** 2015-02-04 HDS
** 2015/04/13 HDS - xh64search
** 2015/11/18 HDS - xh64renew
*/
#include <string.h>
#include "xhash64.h"
#include "hashf.h"
#include "xalloc.h"


static ub32 xhash6432shift (ub64 key)
{
  key = (~key) + (key << 18); // key = (key << 18) - key - 1;
  key = key ^ (key >> 31);
  key = key * 21;            // key = (key + (key << 2)) + (key << 4);
  key = key ^ (key >> 11);
  key = key + (key << 6);
  key = key ^ (key >> 22);
  return (ub32) key;
}

static void xh64grow (xh64tab  *t)
{
  int     oldsize = t->tsize; 
  int     newsize = prime_next_size(&t->pindex);
  int     i;
  xh64item **oldtab = t->table;
  xh64item **newtab = (xh64item **)xzalloc(newsize*sizeof(xh64item *));

  t->table = newtab;
  t->tsize = newsize;

  /* Walk through old table putting entries in new table */
  for (i = oldsize; i--;) {
    xh64item *this, *that, **newplace;
    for (this = oldtab[i]; this;) {
      that = this;
      this = this->next;
      newplace = &newtab[(that->hval %  newsize)];
      that->next = *newplace;
      *newplace = that;
    }
  }
  xh64first(t);
  xfree((char *)oldtab);
}


void xh64init (xh64tab *t, int hsize, int dsize) 
{
  int tsize;

  tsize = prime_size(hsize, &t->pindex);
  t->table = (xh64item **)xzalloc(sizeof(xh64item *)*(ub32)tsize);
  t->tsize  = tsize;
  t->dsize  = dsize;
  t->count  = 0;
  t->apos   = (ub32)0;
  t->ipos   = (xh64item *)0;
  t->space  = xfmem_create(sizeof(xh64item) + dsize, hsize);

#ifdef XHASH64_STATS
  t->add   = t->del = t->collisions = 0;
#endif
}

xh64tab *xh64create (int hsize, int dsize)
{
  xh64tab *t = (xh64tab *)xmalloc(sizeof(xh64tab));
  xh64init(t, hsize, dsize);
  return t;
}

void xh64clean (xh64tab  *t)
{
  int new_space = xfmem_max_items(t->space) / 2;
  xfmem_destroy(t->space);

  memset(t->table, 0, sizeof(xh64item *)*(ub32)t->tsize);
  t->count = 0;
  t->apos  = (ub32)0;
  t->ipos  = (xh64item *)0;
  t->space = xfmem_create(sizeof(xh64item), new_space);

#ifdef XHASH64_STATS
  t->add   = t->del = t->collisions = 0;
#endif
}

void xh64renew (xh64tab  *t, int hsize)
{
  xh64free(t);
  xh64init(t, hsize, t->dsize);
}

void xh64free (xh64tab  *t)
{
  xfmem_destroy(t->space);
  xfree(t->table);
}

void xh64destroy (xh64tab  *t)
{
  xh64free(t);
  xfree(t);
}

int xh64find (xh64tab *t, ub64 key)
{
  xh64item *h;
  ub32  x = xhash6432shift(key);
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

void *xh64search (xh64tab *t, ub64 key)
{
  xh64item *h;
  ub32  x = xhash6432shift(key);
  ub32  y = x % t->tsize;

  for (h = t->table[y]; h; h = h->next) {
    if (key == h->key) {
      t->apos = y;
      t->ipos = h;
      return h->stuff;
    }
  }
  return NULL;
}

void *xh64get (xh64tab *t, ub64 key, int *new)
{
  xh64item  *h,**hp;
  ub32    x = xhash6432shift(key);
  ub32    y = x % t->tsize;

  /* make sure the key is not already there */
  for (h = t->table[y]; h; h = h->next) {
    if (key == h->key) {
      t->apos = y;
      t->ipos = h;
      *new = 0;
      return h->stuff;
    }
  }
#ifdef XHASH64_STATS
  if (h) t->collisions++;
  t->add++;
#endif
  /* find space for a new item */
  h = (xh64item *)xfmem_malloc(t->space);

  /* make the hash table bigger if it is getting full */
  if (++t->count > t->tsize) {
    xh64grow(t);
    y = (x % t->tsize);
  }

  /* add the new key to the table */
  h->key   = key;
  h->hval  = x;
  hp = &t->table[y];
  h->next = *hp;
  *hp = h;
  t->ipos = h;
  t->apos = y;
  *new = 1;
  return h->stuff;
}

int xh64del_adjust (xh64tab *t, int adjust)
{
  xh64item  *h;
  xh64item **ip;

  /* check for item not existing */
  if (!(h = t->ipos)) return FALSE;

  /* remove item from its list */
  for (ip = &t->table[t->apos]; *ip != h; ip = &(*ip)->next)
    ;
  *ip = (*ip)->next;
  --(t->count);

  /* adjust position to something that exists */
  if (adjust && !(t->ipos = h->next)) xh64nbucket(t);

  xfmem_free(t->space, h);
#ifdef XHASH64_STATS
  t->del++;
#endif
  return TRUE;
}

int xh64first (xh64tab *t)
{
  t->apos = t->tsize - 1;
  (void)xh64nbucket(t);
  return (t->ipos != (xh64item *)0);
}

int xh64nbucket (xh64tab *t)
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

void **xh64array (xh64tab *t)
{
  int used = t->count;
  void **table, **tptr;

  if (used == 0) return NULL;
  table = (void **) xmalloc(sizeof(void*)*(used));
  tptr = table;
  if (xh64first(t)) do {
    *tptr++ = xh64stuff(t);
  } while (xh64next(t));

  return table;
}

#ifdef XHASH64_STATS
int xh64hash_stats (xh64tab *t, char* stats, int len) 
{
  float effic =  (float) t->collisions / ((float) t->count + 0.01) * 100.0;

  return snprintf(stats, len, "add:%d,  del:%d, col:%d (%0.1f%%)\n", t->add, t->del, t->collisions, effic);
}
#endif
