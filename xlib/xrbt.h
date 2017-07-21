#ifndef __XRBT_H__
#define __XRBT_H__

#include "xtypes.h"
#include "spt.h"
#include "xfmem.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct XRBTR XRBTR;
typedef struct XRBTR XRBTR32;
typedef struct XRBTR XRBTR64;
typedef struct XRBTR XRBTRPTR;
typedef struct XRBTR XRBTRSTR;
typedef struct XRBTR XRBTRMEM;

typedef struct XRBTR XSRBTR;
typedef struct XRBTR XSRBTR32;
typedef struct XRBTR XSRBTR64;
typedef struct XRBTR XSRBTRPTR;
typedef struct XRBTR XSRBTRSTR;
typedef struct XRBTR XSRBTRMEM;

typedef struct XRBTN    XRBTN;
typedef struct XRBTN32  XRBTN32;
typedef struct XRBTN64  XRBTN64;
typedef struct XRBTNPTR XRBTNPTR;
typedef struct XRBTNSTR XRBTNSTR;
typedef struct XRBTNMEM XRBTNMEM;

typedef struct XSRBTN    XSRBTN;
typedef struct XSRBTN32  XSRBTN32;
typedef struct XSRBTN64  XSRBTN64;
typedef struct XSRBTNPTR XSRBTNPTR;
typedef struct XSRBTNSTR XSRBTNSTR;
typedef struct XSRBTNMEM XSRBTNMEM;

typedef int (*xrbt_comp_f)(void *, void *);

struct XRBTN {
  XRBTN *left, *right, *parent;
  unsigned is_red;
};

struct XRBTN32 {
  XRBTN node;
  ub32 key;
};
struct XRBTN64 {
  XRBTN node;
  ub64 key;
};
struct XRBTNPTR {
  XRBTN node;
  void *key;
};
struct XRBTNSTR {
  XRBTN node;
  char *key;
};
struct XRBTNMEM {
  XRBTN node;
  void *key;
  int klen;
};


struct XSRBTN {
  spt_t time;
  XRBTN node;
};
struct XSRBTN32 {
  spt_t time;
  XRBTN node;
  ub32 key;
};
struct XSRBTN64 {
  spt_t time;
  XRBTN node;
  ub64 key;
};
struct XSRBTNPTR {
  spt_t time;
  XRBTN node;
  void *key;
};
struct XSRBTNSTR {
  spt_t time;
  XRBTN node;
  char *key;
};
struct XSRBTNMEM {
  spt_t time;
  XRBTN node;
  void *key;
  int klen;
};


struct XRBTR {
  XRBTN *root;
  xrbt_comp_f  compare;
  ub32 count;
  ub32 dsize;
  ub32 int_cnt;
  ub32 max_cnt;
  xfmem_t cache; 
};

XRBTR    *xrbt_create (xrbt_comp_f compare, int dsize, int rnum);
XRBTR32  *xrbt32_create (int dsize, int rnum);
XRBTR64  *xrbt64_create (int dsize, int rnum);
XRBTRPTR *xrbtptr_create (int dsize, int rnum);
XRBTRSTR *xrbtstr_create (int dsize, int rnum);
XRBTRMEM *xrbtmem_create (int dsize, int rnum);

XSRBTR32  *xsrbt32_create (int dsize, int rnum);
XSRBTR64  *xsrbt64_create (int dsize, int rnum);
XSRBTRPTR *xsrbtptr_create (int dsize, int rnum);
XSRBTRSTR *xsrbtstr_create (int dsize, int rnum);
XSRBTRMEM *xsrbtmem_create (int dsize, int rnum);

void   xrbt_destroy (XRBTR *xrbtr);
void   xrbt32_destroy (XRBTR32 *xrbtr);
void   xrbt64_destroy (XRBTR64 *xrbtr);
void   xrbtptr_destroy (XRBTRPTR *xrbtr);
void   xrbtstr_destroy (XRBTRSTR *xrbtr);
void   xrbtmem_destroy (XRBTRMEM *xrbtr);

void   xsrbt32_destroy (XSRBTR32 *xrbtr);
void   xsrbt64_destroy (XSRBTR64 *xrbtr);
void   xsrbtptr_destroy (XSRBTRPTR *xrbtr);
void   xsrbtstr_destroy (XSRBTRSTR *xrbtr);
void   xsrbtmem_destroy (XSRBTRMEM *xrbtr);

void   xrbt_init (XRBTR *xr, xrbt_comp_f compare, int dsize, int rnum);
void   xrbt32_init (XRBTR32 *xr, int dsize, int rnum);
void   xrbt64_init (XRBTR64 *xr, int dsize, int rnum);
void   xrbtptr_init (XRBTRPTR *xr, int dsize, int rnum);
void   xrbtstr_init (XRBTRSTR *xr, int dsize, int rnum);
void   xrbtmem_init (XRBTRMEM *xr, int dsize, int rnum);

void   xsrbt32_init (XSRBTR32 *xr, int dsize, int rnum);
void   xsrbt64_init (XSRBTR64 *xr, int dsize, int rnum);
void   xsrbtptr_init (XSRBTRPTR *xr, int dsize, int rnum);
void   xsrbtstr_init (XSRBTRSTR *xr, int dsize, int rnum);
void   xsrbtmem_init (XSRBTRMEM *xr, int dsize, int rnum);

void   xrbt_free (XRBTR *xr);
void   xrbt32_free (XRBTR32 *xr);
void   xrbt64_free (XRBTR64 *xr);
void   xrbtptr_free (XRBTRPTR *xr);
void   xrbtstr_free (XRBTRSTR *xr);
void   xrbtmem_free (XRBTRMEM *xr);

void   xsrbt32_free (XSRBTR32 *xr);
void   xsrbt64_free (XSRBTR64 *xr);
void   xsrbtptr_free (XSRBTRPTR *xr);
void   xsrbtstr_free (XSRBTRSTR *xr);
void   xsrbtmem_free (XSRBTRMEM *xr);

XRBTN    *xrbt_search (XRBTR *xr, XRBTN *n);
XRBTN32  *xrbt32_search (XRBTR32 *xr, ub32 key);
XRBTN64  *xrbt64_search (XRBTR64 *xr, ub64 key);
XRBTNPTR *xrbtptr_search (XRBTRPTR *xr, void *key);
XRBTNSTR *xrbtstr_search (XRBTRSTR *xr, char *key);
XRBTNMEM *xrbtmem_search (XRBTRMEM *xr, void *key, int klen);

XSRBTN32 *xsrbt32_search (XSRBTR32 *xr, ub32 key);
XSRBTN64 *xsrbt64_search (XSRBTR64 *xr, ub64 key);
XSRBTNPTR *xsrbtptr_search (XSRBTRPTR *xr, void *key);
XSRBTNSTR *xsrbtstr_search (XSRBTRSTR *xr, char *key);
XSRBTNMEM *xsrbtmem_search (XSRBTRMEM *xr, void *key, int klen);

/* Modes for xrbt_lookup */
#define XRBT_GTEQ  1    /* Exact match or greater */
#define XRBT_LTEQ  2    /* Exact match or less */
#define XRBT_LESS  3    /* Less than key (not equal to) */
#define XRBT_GREAT 4    /* Greater than key (not equal to) */

XRBTN    *xrbt_lookup (XRBTR *xr, XRBTN *n, int mode);
XRBTN32  *xrbt32_lookup (XRBTR32 *xr, ub32 key, int mode);
XRBTN64  *xrbt64_lookup (XRBTR64 *xr, ub64 key, int mode);
XRBTNPTR *xrbtptr_lookup (XSRBTRPTR *xr, void *key, int mode);
XRBTNSTR *xrbtstr_lookup (XSRBTRSTR *xr, char *key, int mode);
XRBTNMEM *xrbtmem_lookup (XSRBTRMEM *xr, void *key, int klen, int mode);

XSRBTN32  *xsrbt32_lookup (XSRBTR32 *xr, ub32 key, int mode);
XSRBTN64  *xsrbt64_lookup (XSRBTR64 *xr, ub64 key, int mode);
XSRBTNPTR *xsrbtptr_lookup (XSRBTRPTR *xr, void *key, int mode);
XSRBTNSTR *xsrbtstr_lookup (XSRBTRSTR *xr, char *key, int mode);
XSRBTNMEM *xsrbtmem_lookup (XSRBTRMEM *xr, void *key, int klen, int mode);

XRBTN    *xrbt_insert (XRBTR *xr, XRBTN *n, int *new);
XRBTN32  *xrbt32_insert (XRBTR32 *xr, ub32 key, int *new);
XRBTN64  *xrbt64_insert (XRBTR64 *xr, ub64 key, int *new);
XRBTNPTR *xrbtptr_insert (XRBTRPTR *xr, void *key, int *new);
XRBTNSTR *xrbtstr_insert (XRBTRSTR *xr, char *key, int *new);
XRBTNMEM *xrbtmem_insert (XRBTRMEM *xr, void *key, int klen, int *new);

XSRBTN32  *xsrbt32_insert (XSRBTR32 *xr, ub32 key, int *new);
XSRBTN64  *xsrbt64_insert (XSRBTR64 *xr, ub64 key, int *new);
XSRBTNPTR *xsrbtptr_insert (XSRBTRPTR *xr, void *key, int *new);
XSRBTNSTR *xsrbtstr_insert (XSRBTRSTR *xr, char *key, int *new);
XSRBTNMEM *xsrbtmem_insert (XSRBTRMEM *xr, void *key, int klen, int *new);

void xrbt_remove (XRBTR *xr, XRBTN *xn); 
void xrbt32_remove (XRBTR32 *xr, XRBTN32 *xn); 
void xrbt64_remove (XRBTR64 *xr, XRBTN64 *xn); 
void xrbtptr_remove (XRBTRPTR *xr, XRBTNPTR *xn); 
void xrbtstr_remove (XRBTRSTR *xr, XRBTNSTR *xn); 
void xrbtmem_remove (XRBTRMEM *xr, XRBTNMEM *xn); 

void xsrbt32_remove (XSRBTR32 *xr, XSRBTN32 *xn); 
void xsrbt64_remove (XSRBTR64 *xr, XSRBTN64 *xn); 
void xsrbtptr_remove (XSRBTRPTR *xr, XSRBTNPTR *xn); 
void xsrbtstr_remove (XSRBTRPTR *xr, XSRBTNSTR *xn); 
void xsrbtmem_remove (XSRBTRPTR *xr, XSRBTNMEM *xn); 

void xrbt32_delete (XRBTR32 *xr, ub32 key);
void xrbt64_delete (XRBTR64 *xr, ub64 key);
void xrbtptr_delete (XRBTRPTR *xr, void *key);
void xrbtstr_delete (XRBTRSTR *xr, char *key);
void xrbtmem_delete (XRBTRMEM *xr, void *key, int klen);

void xsrbt32_delete (XRBTR32 *xr, ub32 key);
void xsrbt64_delete (XRBTR64 *xr, ub64 key);
void xsrbtptr_delete (XRBTRPTR *xr, void *key);
void xsrbtstr_delete (XRBTRSTR *xr, char *key);
void xsrbtmem_delete (XRBTRMEM *xr, void *key, int klen);

XRBTN    *xrbt_first(const XRBTR *xr);
XRBTN32  *xrbt32_first(const XRBTR32 *xr);
XRBTN64  *xrbt64_first(const XRBTR64 *xr);
XRBTNPTR *xrbtptr_first(const XRBTRPTR *xr);
XRBTNSTR *xrbtstr_first(const XRBTRSTR *xr);
XRBTNMEM *xrbtmem_first(const XRBTRMEM *xr);

XSRBTN32  *xsrbt32_first(const XSRBTR32 *xr);
XSRBTN64  *xsrbt64_first(const XSRBTR64 *xr);
XSRBTNPTR *xsrbtptr_first(const XSRBTRPTR *xr);
XSRBTNSTR *xsrbtstr_first(const XSRBTRSTR *xr);
XSRBTNMEM *xsrbtmem_first(const XSRBTRMEM *xr);

XRBTN    *xrbt_last(const XRBTR *xr);
XRBTN32  *xrbt32_last(const XRBTR32 *xr);
XRBTN64  *xrbt64_last(const XRBTR64 *xr);
XRBTNPTR *xrbtptr_last(const XRBTRPTR *xr);
XRBTNSTR *xrbtstr_last(const XRBTRSTR *xr);
XRBTNMEM *xrbtmem_last(const XRBTRMEM *xr);

XSRBTN32  *xsrbt32_last(const XSRBTR32 *xr);
XSRBTN64  *xsrbt64_last(const XSRBTR64 *xr);
XSRBTNPTR *xsrbtptr_last(const XSRBTRPTR *xr);
XSRBTNSTR *xsrbtstr_last(const XSRBTRSTR *xr);
XSRBTNMEM *xsrbtmem_last(const XSRBTRMEM *xr);

XRBTN    *xrbt_prev(const XRBTN *xn);
XRBTN32  *xrbt32_prev(const XRBTN32 *xn);
XRBTN64  *xrbt64_prev(const XRBTN64 *xn);
XRBTNPTR *xrbtptr_prev(const XRBTNPTR *xn);
XRBTNSTR *xrbtstr_prev(const XRBTNSTR *xn);
XRBTNMEM *xrbtmem_prev(const XRBTNMEM *xn);

XSRBTN32  *xsrbt32_prev(const XSRBTN32 *xn);
XSRBTN64  *xsrbt64_prev(const XSRBTN64 *xn);
XSRBTNPTR *xsrbtptr_prev(const XSRBTNPTR *xn);
XSRBTNSTR *xsrbtstr_prev(const XSRBTNSTR *xn);
XSRBTNMEM *xsrbtmem_prev(const XSRBTNMEM *xn);

XRBTN    *xrbt_next(const XRBTN *xn);
XRBTN32  *xrbt32_next(const XRBTN32 *xn);
XRBTN64  *xrbt64_next(const XRBTN64 *xn);
XRBTNPTR *xrbtptr_next(const XRBTNPTR *xn);
XRBTNSTR *xrbtstr_next(const XRBTNSTR *xn);
XRBTNMEM *xrbtmem_next(const XRBTNMEM *xn);

XSRBTN32  *xsrbt32_next(const XSRBTN32 *xn);
XSRBTN64  *xsrbt64_next(const XSRBTN64 *xn);
XSRBTNPTR *xsrbtptr_next(const XSRBTNPTR *xn);
XSRBTNSTR *xsrbtstr_next(const XSRBTNSTR *xn);
XSRBTNMEM *xsrbtmem_next(const XSRBTNMEM *xn);

void *xrbt_mem_malloc (XRBTR *r);
void *xrbt_mem_zalloc (XRBTR *r);
void xrbt_mem_free (XRBTR *r, void *ptr);

#define xrbt_count(t)    ((const ub32) (t)->count)
#define xrbt32_count(t)  ((const ub32) (t)->count)
#define xrbt64_count(t)  ((const ub32) (t)->count)
#define xrbtptr_count(t) ((const ub32) (t)->count)
#define xrbtstr_count(t) ((const ub32) (t)->count)
#define xrbtmem_count(t) ((const ub32) (t)->count)

#define xsrbt32_count(t)  ((const ub32) (t)->count)
#define xsrbt64_count(t)  ((const ub32) (t)->count)
#define xsrbtptr_count(t) ((const ub32) (t)->count)
#define xsrbtstr_count(t) ((const ub32) (t)->count)
#define xsrbtmem_count(t) ((const ub32) (t)->count)

#define xrbt_max_mem_size(t)    ((const ub32) (t)->cache.max_items)
#define xrbt32_max_mem_size(t)  ((const ub32) (t)->cache.max_items)
#define xrbt64_max_mem_size(t)  ((const ub32) (t)->cache.max_items)
#define xrbtptr_max_mem_size(t) ((const ub32) (t)->cache.max_items)
#define xrbtstr_max_mem_size(t) ((const ub32) (t)->cache.max_items)
#define xrbtmem_max_mem_size(t) ((const ub32) (t)->cache.max_items)

#define xsrbt32_max_mem_size(t)  ((const ub32) (t)->cache.max_items)
#define xsrbt64_max_mem_size(t)  ((const ub32) (t)->cache.max_items)
#define xsrbtptr_max_mem_size(t) ((const ub32) (t)->cache.max_items)
#define xsrbtstr_max_mem_size(t) ((const ub32) (t)->cache.max_items)
#define xsrbtmem_max_mem_size(t) ((const ub32) (t)->cache.max_items)


#define xrbt_mem_count(t)    ((const ub32) (t)->cache.alloc_items)
#define xrbt32_mem_count(t)  ((const ub32) (t)->cache.alloc_items)
#define xrbt64_mem_count(t)  ((const ub32) (t)->cache.alloc_items)
#define xrbtptr_mem_count(t) ((const ub32) (t)->cache.alloc_items)
#define xrbtstr_mem_count(t) ((const ub32) (t)->cache.alloc_items)
#define xrbtmem_mem_count(t) ((const ub32) (t)->cache.alloc_items)

#define xsrbt32_mem_count(t)  ((const ub32) (t)->cache.alloc_items)
#define xsrbt64_mem_count(t)  ((const ub32) (t)->cache.alloc_items)
#define xsrbtptr_mem_count(t) ((const ub32) (t)->cache.alloc_items)
#define xsrbtstr_mem_count(t) ((const ub32) (t)->cache.alloc_items)
#define xsrbtmem_mem_count(t) ((const ub32) (t)->cache.alloc_items)

#ifdef __cplusplus
}
#endif

#endif  /* XRBT_H */
