#ifndef __XSQUEUE_H__
#define __XSQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>
#include "xtypes.h"


#define XSQ_WAIT     0
#define XSQ_NOWAIT   1

typedef struct xs_queue XSQ;


XSQ  *xsq_create (int qsize);
void  xsq_destroy (XSQ *xsq);

void  *xsq_get_wait (XSQ *xsq);
void  *xsq_get_nowait (XSQ *xsq);
void  xsq_put_wait (XSQ *xsq, void *ptr);
void  *xsq_put_nowait (XSQ *xsq, void *ptr);

void xsq_info (XSQ *xsq, int *qsize, int *qcnt);
void xsq_counter (XSQ *xsq, ub64 *ok, ub64 *drop);

#endif

