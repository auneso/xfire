#ifndef __MTQUEUE_H__
#define __MTQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>
#include "spt.h"

typedef struct circle_queue {
  pthread_mutex_t lock;
  pthread_cond_t  cond;
  void **queue;
  int qsize;
  int qcnt;
  int didx;
  int eidx;
  int qmax;
  ub32 qdrop;
} CQ;

#define CQ_DROP 1
CQ   *cq_create (int qsize);
void  cq_destroy (CQ *cq);

void *cq_pop (CQ *cq);
void *cq_peek (CQ *cq);
int   cq_push (CQ *cq, void *data);
int   cq_push_try (CQ *cq, void *data);
int   cq_percent (CQ *cq);
int   cq_is_full (CQ *cq);
void  cq_info (CQ *cq, int *qcnt, int *qmax, int *qsize, ub32 *qdrop);

#define cq_size(cq) (cq->qsize)
#define cq_count(cq) (cq->qcnt)

/* Splay Priority Queue -----------------------------*/

#define SPQ_DROP 1

typedef struct splay_prio_queue {
  spt_t *root;
 
  pthread_mutex_t lock;
  pthread_cond_t  cond;
  int             qcnt;
  int             qsize;
  int             qmax;
  ub32            qdrop;
} SPQ;

SPQ   *spq_create (void);
void   spq_destroy (SPQ *spq);
spt_t *spq_pop (SPQ *spq);
spt_t *spq_peek (SPQ *spq);
spt_t *spq_remove (SPQ *spq, double prio);
int    spq_push (SPQ *spq, spt_t *spt);

#define spq_size(cq) (spq->qsize)
#define spq_count(spq) (spq->qcnt)


#endif

