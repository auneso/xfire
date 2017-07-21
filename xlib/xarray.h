#ifndef __XARRAY_H__
#define __XARRAY_H__

typedef struct {
    int capacity;
    int count;
    void **items;
} xarray;

extern xarray *xarray_create (void);
extern void xarray_init (xarray * s);
extern void xarray_clean (xarray * s);
extern void xarray_destroy (xarray * s);
extern void xarray_append (xarray * s, void *obj);
extern void xarray_insert (xarray * s, void *obj, int position);
extern void xarray_preAppend (xarray * s, int app_count);


#ifndef _MYARRAY_H
#define _MYARRAY_H
#include <string.h>

typedef struct myarray {
    void **elements;
    int len;
    int maxlen;
    int incr;
    int elsize;
    int (*cmpfunc)(void *, void *);
} *MArray;

MArray myarray_new(int, int, int);

#define myarray_append(a,e) _myarray_insert((a), &(e), (a)->len)

#define myarray_insert(a,e,i) _myarray_insert((a), &(e), (i))
void _myarray_insert(MArray, void *, int);

#define myarray_get(a,t,i) (*((t**) (a)->elements)[i])

void myarray_remove_index(MArray, int);
void myarray_reset(MArray);
void myarray_free(MArray);
void myarray_set_cmpfunc(MArray array, int (*cmpfunc)(void *, void *));

#define myarray_insert_sorted(a,e) _myarray_insert_sorted(a, &(e))
void _myarray_insert_sorted(MArray array, void *element);
#endif



#endif


