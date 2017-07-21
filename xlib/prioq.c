#include "xalloc.h"
#include "prioq.h"

struct prioqueue {
  void **qt;
  int size;
  int count;
  int (*cmp)(void *, void *);
};

prioq_t *prioq_new (int size, int (*cmp)(void *, void *))
{
  prioq_t *pq = xmalloc(sizeof(*pq));

  pq->qt    = xmalloc(size * sizeof(*pq->qt));
  pq->size  = size;
  pq->count = 1;
  pq->cmp   = cmp;

  return pq;
}

int prioq_add (prioq_t *pq, void *data)
{
  int i;

  if (pq->count == pq->size) {
    pq->qt = xrealloc(pq->qt, (pq->size *= 2) * sizeof(*pq->qt));
  }

  i = pq->count;
  pq->qt[i] = data;

  while (i > 1 && pq->cmp(pq->qt[i/2], pq->qt[i]) > 0) {
    void *tmp = pq->qt[i];
    pq->qt[i] = pq->qt[i/2];
    pq->qt[i/2] = tmp;
    i /= 2;
  }
  pq->count++;
  return 0;
}

void *prioq_get (prioq_t *pq)
{
  if (pq->count > 1) {
    int i;
    void *r;

    r = pq->qt[1];
    pq->qt[1] = pq->qt[pq->count-1];
    pq->count--;

    i = 1;
    while ((2*i < pq->count   && pq->cmp(pq->qt[i], pq->qt[2*i]) > 0) ||
           (2*i < pq->count-1 && pq->cmp(pq->qt[i], pq->qt[2*i+1]) > 0))
    {
      void *tmp = pq->qt[i];
      i = (2*i < pq->count-1 && pq->cmp(pq->qt[2*i], pq->qt[2*i+1]) > 0)
        ? 2*i+1 : 2*i;
      pq->qt[i/2] = pq->qt[i];
      pq->qt[i] = tmp;
    }
    return r;
  }
  return NULL;
}

int prioq_items (prioq_t *pq)
{
  return pq->count - 1;
}

void prioq_free (prioq_t *pq)
{
  xfree(pq->qt);
  xfree(pq);
}
