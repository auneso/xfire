/*
** 2013/06/04 HDS
** 2013/12/09 HDS mem 
*/

#include "xalloc.h"
#include "xspqueue.h"


static void xspq_init (XSPQ *xspq, int qsize)
{
  pthread_mutex_init(&xspq->mlock, 0);
  pthread_cond_init(&xspq->mcond, NULL);
  xspq->mmax  = qsize;
  xspq->mcnt  = 0;

  pthread_mutex_init(&xspq->qlock, NULL);
  pthread_cond_init(&xspq->qcond, NULL);
  xspq->qsize = qsize;
  xspq->qcnt  = 0;
}

XSPQ *xspq_create (int qsize, int dsize)
{
  XSPQ *xspq;

  xspq = xzalloc(sizeof(XSPQ));
  xspq->cache = xfmem_create(sizeof(spt_t) + dsize, qsize);
  xspq_init(xspq, qsize);
  return xspq;
}

XSPQ *xspq_create_clone (XSPQ *xspq)
{
  XSPQ *xspqc;

  xspqc = xzalloc(sizeof(XSPQ));
  xspq_init(xspqc, xspq->qsize);
  return xspqc;
}

void xspq_destroy (XSPQ *xspq)
{
  if (xspq) {
    if (xspq->cache) xfmem_destroy(xspq->cache);
    xfree(xspq);
  }
}

spt_t *xspq_alloc (XSPQ *xspq)
{
  spt_t *rmem;

  pthread_mutex_lock(&xspq->mlock);
retry:
  if (xspq->mcnt < xspq->mmax) {
    rmem = (spt_t *)xfmem_malloc(xspq->cache);
    xspq->mcnt++;
  } else {
    while (xspq->mcnt == xspq->mmax) {
      pthread_cond_wait(&xspq->mcond, &xspq->mlock);
    }
    goto retry;
  }
  pthread_mutex_unlock(&xspq->mlock);
  return rmem;
}

void xspq_free (XSPQ *xspq, spt_t *spt)
{
  pthread_mutex_lock(&xspq->mlock);
  if (xspq->mcnt) {
    xspq->mcnt--;
    xfmem_free(xspq->cache, spt);
    if (xspq->mcnt == xspq->mmax - 1) {
      pthread_cond_signal(&xspq->mcond);
    }
  } 
  pthread_mutex_unlock(&xspq->mlock);
}


void xspq_push (XSPQ *xspq,  spt_t *spt)
{
  if (spt) {
    pthread_mutex_lock(&xspq->qlock); 
    spt_enqueue(&xspq->root, spt);  
    if (++xspq->qcnt == 1) {
      pthread_cond_signal(&xspq->qcond);
    }
    pthread_mutex_unlock(&xspq->qlock);
  }
}

spt_t *xspq_pop (XSPQ *xspq)
{
  spt_t *spt;
  
  pthread_mutex_lock(&xspq->qlock);
  while (xspq->qcnt == 0) {
    pthread_cond_wait(&xspq->qcond, &xspq->qlock);
  }
  spt = spt_dequeue(&xspq->root);
  --xspq->qcnt;
  pthread_mutex_unlock(&xspq->qlock);

  return spt;
}

void xspq_info (XSPQ *xspq, int *qcnt, int *qsize)
{
  pthread_mutex_lock(&xspq->qlock); 
  *qcnt  = xspq->mcnt;
  *qsize = xspq->qsize;
  pthread_mutex_unlock(&xspq->qlock);
}


