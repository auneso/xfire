/*
** 2008/09/16 add HDS 
** 2008/10/08 add HDS  prio queue
** 2009/11/09 add HDS  qcnt, spq_remove 
** 2009/11/13 add HDS  CQ, SPQ struct change !!!
** 2009/11/19 add HDS  CQ drop
** 2013/04/03 add HDS  CQ info
** 2013/04/04 add HDS  SPQ info
*/

#include "xalloc.h"
#include "xalloc.h"
#include "mtqueue.h"

/* ---------- CIRCULAR QUEUE --------------*/
/*
 * create connection queue.
 */
CQ *cq_create (int qsize)
{
  CQ *cq;
  cq = xmalloc(sizeof(CQ));

  pthread_mutex_init(&cq->lock, NULL);
  pthread_cond_init(&cq->cond, NULL);
  cq->queue = xmalloc(sizeof(void *) * qsize);
  cq->qsize = qsize;
  cq->qcnt  = 0;
  cq->didx  = 0;
  cq->eidx  = 0;
  cq->qmax  = 0;
  cq->qdrop = 0;
  return cq;
}

void cq_destroy (CQ *cq)
{
  if (cq) {
    xfree(cq->queue);
    xfree(cq);
  }
}

/*
 * Waits for work on a connection queue.
 */
void *cq_pop (CQ *cq)
{
  void *data;

  pthread_mutex_lock(&cq->lock);

  while (cq->qcnt == 0) pthread_cond_wait(&cq->cond, &cq->lock);
  data = cq->queue[cq->didx];
  if (++cq->didx == cq->qsize) cq->didx = 0;
  cq->qcnt--;

  pthread_mutex_unlock(&cq->lock);
  return data;
}

/*
 * Looks for an item on a connection queue, but doesn't block if there isn't
 * one.
 */
void *cq_peek (CQ *cq)
{
  void *data = NULL;

  pthread_mutex_lock(&cq->lock);

  if (cq->qcnt > 0) {
    data = cq->queue[cq->didx];
    if (++cq->didx == cq->qsize) cq->didx = 0;
    cq->qcnt--;
  }

  pthread_mutex_unlock(&cq->lock);
  return data;
}

/*
 * Adds an item to a connection queue.
 */
int cq_push (CQ *cq, void *data)
{
  int drop = 0;
  pthread_mutex_lock(&cq->lock);

  if (cq->qcnt < cq->qsize) {
    cq->queue[cq->eidx] = data;

    if (++cq->eidx == cq->qsize) cq->eidx = 0;
    cq->qcnt++;
    if (cq->qcnt > cq->qmax) cq->qmax = cq->qcnt;
    pthread_cond_signal(&cq->cond);
  } else {
    cq->qmax = 0;
    cq->qdrop++;
    drop = CQ_DROP;
  }
  pthread_mutex_unlock(&cq->lock);
  return drop;
}

int cq_push_try (CQ *cq, void *data)
{
  if (pthread_mutex_trylock(&cq->lock))  return CQ_DROP;
  int drop = 0;

  if (cq->qcnt < cq->qsize) {
    cq->queue[cq->eidx] = data;

    if (++cq->eidx == cq->qsize) cq->eidx = 0;
    cq->qcnt++;
    pthread_cond_signal(&cq->cond);
  } else {
    cq->qmax = 0;
    cq->qdrop++;
    drop = CQ_DROP;
  }
  pthread_mutex_unlock(&cq->lock);
  return drop;
}

int cq_percent (CQ *cq)
{
  int percent;
  pthread_mutex_lock(&cq->lock);
  percent =  (int)((double)cq->qcnt / (double)cq->qsize * 100.0);
  pthread_mutex_unlock(&cq->lock);
  return percent;
}

int cq_is_full (CQ *cq)
{
  int rv = 1;
  pthread_mutex_lock(&cq->lock);
  if (cq->qcnt < cq->qsize) rv = 0;
  pthread_mutex_unlock(&cq->lock);
  return rv;
}

void cq_info (CQ *cq,  int *qcnt, int *qmax, int *qsize, ub32 *qdrop)
{
  pthread_mutex_lock(&cq->lock);
  *qcnt  = cq->qcnt;
  *qmax  = cq->qmax;
  *qsize = cq->qsize;
  *qdrop = cq->qdrop;
  pthread_mutex_unlock(&cq->lock);
}

/*------------- SPLAY  PRIORITY QUEUE -----------*/
/*
** prio value low is high priority
*/
/*
 * create connection priority queue.
 */
SPQ *spq_create (void)
{
  SPQ *spq;

  spq = xmalloc(sizeof(SPQ));

  pthread_mutex_init(&spq->lock, NULL);
  pthread_cond_init(&spq->cond, NULL);
  spq->root = NULL;
  spq->qcnt = 0;
  return spq;
}

void spq_destroy (SPQ *spq)
{
  if (spq) {
    xfree(spq);
  }
}

/*
 * Waits for work on a connection priority queue.
 */
spt_t *spq_pop (SPQ *spq)
{
  spt_t *spt;

  pthread_mutex_lock(&spq->lock);

  while (NULL == (spt = spt_dequeue(&spq->root)))
    pthread_cond_wait(&spq->cond, &spq->lock);
  spq->qcnt--;
  pthread_mutex_unlock(&spq->lock);
  return spt;
}

/*
 * Looks for an item on a connection priority queue, but doesn't block if there isn't
 * one.
 * Returns the data, or NULL if no data is available
 */
spt_t *spq_peek (SPQ *spq)
{
  spt_t *spt;

  pthread_mutex_lock(&spq->lock);

  spt = spt_dequeue(&spq->root);
  if (NULL != spt) 
    spq->qcnt--;

  pthread_mutex_unlock(&spq->lock);
  return spt;
}

/* if low proirityi(high value) then remove */
spt_t *spq_remove (SPQ *spq, double prio)
{
  spt_t *spt;

  pthread_mutex_lock(&spq->lock);

  spt = spt_last(spq->root);
  if (NULL != spt) {
    if (spt->prio >  prio) {
      spt_remove (&spq->root, spt);
      spq->qcnt--;
    } else spt = NULL;
  } 

  pthread_mutex_unlock(&spq->lock);
  return spt;
}

/*
 * Adds an item to a connection priority queue.
 */
int spq_push (SPQ *spq, spt_t *spt)
{
  int drop = 0;

  pthread_mutex_lock(&spq->lock);
  if (spq->qcnt < spq->qsize) {
    spt_enqueue(&spq->root, spt);
    spq->qcnt++;
    if (spq->qcnt > spq->qmax) spq->qmax = spq->qcnt;
    pthread_cond_signal(&spq->cond);
  } else {
    spq->qmax = 0;
    spq->qdrop++;
    drop = SPQ_DROP;
  }
  pthread_mutex_unlock(&spq->lock);
  return drop;
}

void spq_info (SPQ *spq,  int *qcnt, int *qmax, int *qsize, ub32 *qdrop)
{ 
  pthread_mutex_lock(&spq->lock);
  *qcnt  = spq->qcnt;
  *qmax  = spq->qmax;
  *qsize = spq->qsize;
  *qdrop = spq->qdrop; 
  pthread_mutex_unlock(&spq->lock);
}   
