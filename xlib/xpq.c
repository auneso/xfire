/*
** 2012-05-30 HDS
*/
#include "xalloc.h"
#include "xpq.h"

int xpq_init (xpq_t *pq, xpq_compar compar)
{
  pq->capacity = 4096;
  pq->q = xmalloc(pq->capacity * sizeof(void*));
  pq->length = 0;
  pq->compar = compar;
  return 0;
}

void xpq_free (xpq_t *pq)
{
  xfree(pq->q);
  pq->q = NULL;
}

static void swap (xpq_t *pq, size_t i, size_t j)
{
  void *t = pq->q[i];
  pq->q[i] = pq->q[j];
  pq->q[j] = t;
}

static void bubble_up (xpq_t *pq, size_t index)
{
  if (index == 0) {
    return;
  } else {
    size_t parent = (index-1)/2;
    if (pq->compar(pq->q[parent], pq->q[index]) > 0) {
      swap(pq, parent, index);
      bubble_up(pq, parent);
    }
  }
}

int xpq_push (xpq_t *pq, void *item)
{
  if (pq->capacity <= pq->length) {
    void *nq;
    nq = xrealloc(pq->q, (pq->capacity*2) * sizeof(void*));
    pq->capacity *= 2;
    pq->q = nq;
  }
  pq->q[pq->length] = item;
  ++pq->length;
  bubble_up(pq, pq->length-1);
  return 0;
}

void* xpq_top (xpq_t *pq)
{
  if (pq->length == 0) {
    return NULL;
  } else {
    return pq->q[0];
  }
}

static void bubble_down (xpq_t *pq, size_t index)
{
  size_t lchild = index*2+1;
  size_t minindex = index;
  size_t i, j;
  for (i = 0; i < 2; ++i) {
    j = lchild+i;
    if (j >= pq->length) {
      break;
    }
    if (pq->compar(pq->q[minindex], pq->q[j]) > 0) {
      minindex = j;
    }
  }
  if (minindex != index) {
    swap(pq, index, minindex);
    bubble_down(pq, minindex);
  }
}

void xpq_pop (xpq_t *pq)
{
  if (pq->length > 0) {
    pq->q[0] = pq->q[pq->length-1];
    --pq->length;
    bubble_down(pq, 0);
  }
}

int xpq_empty (xpq_t *pq)
{
  return pq->length == 0;
}

size_t xpq_size (xpq_t *pq)
{
  return pq->length;
}
