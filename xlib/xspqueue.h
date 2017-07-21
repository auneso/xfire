#ifndef __XSPQUEUE_H__
#define __XSPQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>
#include "xtypes.h"
#include "xfmem.h"
#include "spt.h"


typedef struct xs_pqueue {
  pthread_mutex_t mlock;
  pthread_cond_t  mcond;

  pthread_mutex_t qlock;
  pthread_cond_t  qcond;

  spt_t *root;

  int qcnt, qsize;

  /* cache */
  int  mcnt;
  int  mmax;
  int  msize;
  xfmem_t *cache;
} XSPQ;


#define XSPQ_DROP 1
XSPQ   *xspq_create (int qsize, int dsize);
XSPQ   *xspq_create_clone (XSPQ *xspq);
void   xspq_destroy (XSPQ *xspq);

spt_t *xpsq_pop (XSPQ *xspq);
void   xpsq_push (XSPQ *xspq, spt_t *spt);
spt_t *xpsq_alloc (XSPQ *xspq);
void   xpsq_free (XSPQ *xspq, spt_t *spt);
void   xpsq_info (XSPQ *xspq, int *qcnt, int *qsize);


#endif

