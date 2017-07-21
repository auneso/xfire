/*
** 2016/04/01 HDS 
** 2016/07/28 HDS XSM
*/

#include <pthread.h>
#include <malloc.h>

#include "xalloc.h"
#include "xsm.h"

#define XMM_ALLOC_CACHE   1
#define XMM_ALLOC_XMALLOC 2

struct xsm_mem {
  ub8  dynamic;
  char mem[1];
};

struct xsingle_mem {
  pthread_mutex_t mutex;
  int mem_size;
  int mem_num;
  int top;
  void **cache;
};



XSM *xsm_create (int mem_size, int mem_num)
{
  XSM *xsm;
  int i;

  xsm = xzalloc(sizeof(XSM));
  xsm->top = 0;
  xsm->mem_num = mem_num;
  xsm->mem_size  = mem_size + sizeof(struct xsm_mem);
  pthread_mutex_init(&xsm->mutex, 0);

  xsm->cache = (void **)xmalloc(sizeof(void *) * mem_num);
  for (i = 0; i < mem_num; i++) {
    xsm->cache[i] = xzalloc(xsm->mem_size);
  }
  return xsm;
}


void xsm_destroy (XSM *xsm)
{
  int i;
  for (i = 0; i < xsm->mem_num; i++) xfree(xsm->cache[i]);
  xfree(xsm->cache);
  xfree(xsm);
}


void *xsm_alloc (XSM *xsm, int size)
{
  struct xsm_mem *xm;

  if (size > xsm->mem_size - sizeof(struct xsm_mem)) {
    xm = xmalloc(size + sizeof(struct xsm_mem)); 
    xm->dynamic = XMM_ALLOC_XMALLOC;
  } else {
    pthread_mutex_lock(&xsm->mutex);
    if (xsm->top == xsm->mem_num) {
      xm = (struct xsm_mem *)xmalloc(size + sizeof(struct xsm_mem)); 
      xm->dynamic = XMM_ALLOC_XMALLOC;
    } else {
      xm = (struct xsm_mem *)xsm->cache[xsm->top++];
      xm->dynamic = XMM_ALLOC_CACHE;
    }
    pthread_mutex_unlock(&xsm->mutex);
  }

  return (void *)((char *)xm + sizeof(struct xsm_mem));
}


void xsm_free (XSM *xsm,  void *ptr)
{
  struct xsm_mem *xm = (struct xsm_mem *)((char *)ptr - sizeof(struct xsm_mem));
  if (xm->dynamic == XMM_ALLOC_CACHE) {
    pthread_mutex_lock(&xsm->mutex);
    xsm->cache[--xsm->top] = xm;
    pthread_mutex_unlock(&xsm->mutex);
  } else
  if (xm->dynamic == XMM_ALLOC_XMALLOC) {
    xfree(xm);
  } else {
    printf("xsq_free Error = %p\n", xm);
  }
}


