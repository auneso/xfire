/* 
** 2009/02/04 - HDS add
** 2009/02/05 - HDS xvector_first bug fixed
** 2009/07/25 - HDS xvector_insert, xvector_copy add
** 2009/08/19 - HDS xstrzap
** 2009/11/01 - HDS xvector_get_at, xvector_put_at, xvector_remove_at
** 2011/02/14 - HDS xvector_search
** 2013/05/29 - HDS xvector_delete_all
*/
#include <stdio.h>
#include <string.h>

#include "xvector.h"
#include "xalloc.h"


xvector *xvector_create (int size)
{
  int logsize = 3; /* default 4 (1 << 3) */
  xvector *xv = xmalloc(sizeof(xvector));

  while ((1 << logsize) < size) logsize++;
  size       = ((unsigned int)1 << logsize);
  xv->vptr   = xzalloc(sizeof(void *) * size);
  xv->lsize  = logsize;
  xv->vsize  = size;
  xv->count  = 0;
  return xv;
}

void xvector_destroy (xvector *xv)
{
  xfree(xv->vptr);
  xfree(xv);
}

void xvector_append (xvector *xv, void *item)
{
  if (xv->count >= xv->vsize) {
    void **tmp;
    int i, size;
    size = (unsigned int)1 << (++xv->lsize);
    tmp = xzalloc((sizeof(void *) * size));
    for (i = 0; i < xv->vsize; i++) tmp[i] = xv->vptr[i];
    xv->vsize = size;
    xfree(xv->vptr);
    xv->vptr = tmp;
  }
  xv->vptr[xv->count++] = item;
}

void xvector_insert (xvector *xv, void *item)
{
  int i;
  
  for (i = 0; i < xv->count; i++) {
    if (item == xv->vptr[i]) return;
  } 
  xvector_append(xv, item);
}

void *xvector_search (xvector *xv, void *item)
{
  int i;
  
  for (i = 0; i < xv->count; i++) {
    if (item == xv->vptr[i]) return item; 
  } 
  return NULL;
}

void xvector_delete (xvector *xv, void *item)
{
  int i;

  for (i = 0; i < xv->count; i++) {
    if (item == xv->vptr[i]) {
      while (i < xv->count - 1) xv->vptr[i] = xv->vptr[i+1];
      xv->count--; 
      break;
    }
  }
}

void xvector_delete_all (xvector *xv, void *item)
{
  int i, j, count = xv->count;

  for (i = 0; i < xv->count; i++) {
    if (item == xv->vptr[i]) {
      xv->vptr[i] = NULL;
      count--;
    }
  }
  if (xv->count != count) {
    void  **vptr = xzalloc(sizeof(void *) * xv->vsize);
    
    for (i = 0, j = 0; i < xv->count; i++) {
      if (xv->vptr[i]) vptr[j++] = xv->vptr[i];
    }
    xv->count = count;
    xfree(xv->vptr);
    xv->vptr = vptr;
  }
}

void *xvector_get_at (xvector *xv, int idx)
{
  if (idx >= 0 && idx < xv->count) return xv->vptr[idx];
  return NULL;
}

void *xvector_put_at (xvector *xv, int idx, void *item)
{
  void *retval;
  
  if (idx < 0 || xv->count < idx) 
    return NULL;
  else {
    retval = xv->vptr[idx];
    xv->vptr[idx] = item;
  }
  return retval;
}

void *xvector_remove_at (xvector *xv, int idx)
{
  void *ptr = xvector_get_at (xv, idx);
  xvector_delete(xv, ptr);
  return ptr;
}


void *xvector_first (xvector *xv)
{
  xv->sidx = 0;
  if (xv->count == 0) return NULL;
  return xv->vptr[xv->sidx];
}

void *xvector_next (xvector *xv)
{
  xv->sidx++;
  if (xv->sidx >= xv->count) return NULL;
  return xv->vptr[xv->sidx];
}

xvector *xvector_clone (xvector *xv)
{
  xvector *cxv = xvector_create (xv->vsize);
  
  cxv->lsize = xv->lsize;
  cxv->vsize = xv->vsize;
  cxv->count = xv->count;
  memcpy(cxv->vptr, xv->vptr, sizeof(void *) * xv->count);
    
  return cxv;
}

int xvector_copy (xvector *dxv, xvector *sxv)
{
  void *item;
  int cnt = 0;

  if ((item = xvector_first(sxv)))  do {
    xvector_insert(dxv, item);
    cnt++;
  } while ((item = xvector_next(sxv)));
  return cnt;
}


int xvector_size (xvector *xv)
{
  return xv->vsize;
}

int xvector_count (xvector *xv)
{
  return xv->count;
}


int xstrzap (char *str, char *key, char *del)
{
  int i, one = 0;
  char *p, *q;

  if (!str || !*str) return 0;
  if (*(del+1) == 0) one = 1;

  p = str;
  xvector *xv = xvector_create (10);
append:   
  if (one) while (*p == *del) p++;
  else while (strchr(del, *p)) p++;
  q = p;
  if (*p) xvector_append (xv, p);
  if (one) while (*q && *q != *del) q++;
  else while (*q && !strchr(del, *q)) q++;
  if (*q) {
     *q++ = 0;
     p = q; 
     goto append;
  }
  i = 0; q = str;
  if ((p = xvector_first(xv))) do {
    if (strcmp(p, key) != 0) {
      while (*p) *q++ = *p++; 
      *q++ = *del; 
    } else i++;
  } while ((p = xvector_next(xv)));
  if (i == 1 && i == xvector_count(xv)) *str = 0; 
  else *(q-1) = 0;

  xvector_destroy(xv);
  return i;
}

