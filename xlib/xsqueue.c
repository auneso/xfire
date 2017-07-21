/*
** 2014/12/01 HDS new version
** 2014/12/03 HDS cache pthread_spinlock
** 2015/01/23 HDS cache pthread_mutex_lock, xsq_alloc_n
** 2015/12/14 HDS multi cache - xsq_create_n, mem refer - xsq_set_refer
** 2015/12/21 HDS if (xq->top == xq->mcnt || size > xsq->msz) {
** 2015-12-05 HDS passive thread, inline thread
** 2015/12/22 HDS xsq_put return void *
** 2016/01/15 HDS void *xsq_alloc_n (XSQ *xsq, int size, ub8 cache_idx)
** 2016/02/12 HDS remove refer
*/

#include "xalloc.h"
#include "xsqueue.h"


struct xs_queue {
  void **queue;

  ub64 qok, qdrop;
  int qsz, qcnt;
  int in, out;
  pthread_mutex_t mutex;
  pthread_cond_t notempty;
  pthread_cond_t notfull;
};


XSQ *xsq_create (int qsize)
{
  XSQ *xsq;

  xsq = xzalloc(sizeof(XSQ));
  xsq->queue = xmalloc(qsize * sizeof(void *)); 
  pthread_mutex_init(&xsq->mutex, NULL);
  pthread_cond_init(&xsq->notempty, NULL);
  pthread_cond_init(&xsq->notfull, NULL);
  xsq->qsz  = qsize;
  xsq->qcnt = 0;
  xsq->in   = 0;
  xsq->out  = 0;

  return xsq;
}

void xsq_destroy (XSQ *xsq)
{
  xsq = xsq;
}

void xsq_put_wait (XSQ *xsq,  void *item)
{
  pthread_mutex_lock(&xsq->mutex);

  while (xsq->qcnt == xsq->qsz) {
    pthread_cond_wait(&xsq->notfull, &xsq->mutex);
  }
  xsq->queue[xsq->in++] = item;
  xsq->in %= xsq->qsz;
  xsq->qcnt++;
  xsq->qok++;

  pthread_mutex_unlock(&xsq->mutex);
  pthread_cond_signal(&xsq->notempty);
}

void *xsq_put_nowait (XSQ *xsq,  void *item)
{
  pthread_mutex_lock(&xsq->mutex);
  while (xsq->qcnt == xsq->qsz) {
    xsq->qdrop++;
    pthread_mutex_unlock(&xsq->mutex);
    return NULL;
  }
  xsq->queue[xsq->in++] = item;
  xsq->in %= xsq->qsz;
  xsq->qcnt++;
  xsq->qok++;
  pthread_mutex_unlock(&xsq->mutex);
  pthread_cond_signal(&xsq->notempty);
  return item;
}


void *xsq_get_wait (XSQ *xsq)
{
  void *item;

  pthread_mutex_lock(&xsq->mutex);
  while (xsq->qcnt == 0) {
    pthread_cond_wait(&xsq->notempty, &xsq->mutex);
  }
  item = xsq->queue[xsq->out++];
  xsq->out %= xsq->qsz;
  xsq->qcnt--;
  pthread_mutex_unlock(&xsq->mutex);
  pthread_cond_signal(&xsq->notfull);
  return item;
}

void *xsq_get_nowait (XSQ *xsq)
{
  void *item;

  pthread_mutex_lock(&xsq->mutex);
  while (xsq->qcnt == 0) {
    pthread_mutex_unlock(&xsq->mutex);
    return NULL;
  }
  item = xsq->queue[xsq->out++];
  xsq->out %= xsq->qsz;
  xsq->qcnt--;
  pthread_mutex_unlock(&xsq->mutex);
  pthread_cond_signal(&xsq->notfull);
  return item;
}

void xsq_info (XSQ *xsq, int *qsize, int *qcnt)
{
  pthread_mutex_lock(&xsq->mutex);
  *qsize  = xsq->qsz;
  *qcnt   = xsq->qcnt; 
  pthread_mutex_unlock(&xsq->mutex);
}

void xsq_counter (XSQ *xsq, ub64 *ok, ub64 *drop)
{
  pthread_mutex_lock(&xsq->mutex);
  *ok   = xsq->qok;
  *drop = xsq->qdrop;
  pthread_mutex_unlock(&xsq->mutex);
}
