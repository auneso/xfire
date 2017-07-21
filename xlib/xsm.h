#ifndef __XSM_H__
#define __XSM_H__

#include "xtypes.h"


typedef struct xsingle_mem XSM;

XSM   *xsm_create (int mem_size, int mem_num);
void   xsm_destroy (XSM *xsm);
void  *xsm_alloc (XSM *xsm, int size);
void  *xsm_refer (XSM *xsm, void *ptr);
void   xsm_free (XSM *xsm, void *ptr);


#endif

