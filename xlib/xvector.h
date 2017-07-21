#ifndef __XVECTOR_H__
#define __XVECTOR_H__

#include <stdlib.h>

typedef struct _xvector {
  int lsize;
  int vsize;
  int count;
  int sidx;
  void  **vptr;
} xvector;

xvector *xvector_create (int size);
xvector *xvector_clone (xvector *xv);
void     xvector_insert (xvector *xv, void *item);
void     xvector_append (xvector *xv, void *item);
void     xvector_delete (xvector *xv, void *item);
void     xvector_delete_all (xvector *xv, void *item);
void    *xvector_search (xvector *xv, void *item);
int      xvector_copy (xvector *dxv, xvector *sxv);
void     xvector_destroy (xvector *xv);
void    *xvector_get_at (xvector *xv, int idx);
void    *xvector_put_at (xvector *xv, int idx, void *item);
void    *xvector_remove_at (xvector *xv, int idx);

void    *xvector_first (xvector *xv);
void    *xvector_next (xvector *xv);
int     xvector_size (xvector *xv);
int     xvector_count (xvector *xv);
int     xstrzap (char *str, char *key, char *del);
#endif
