#ifndef __XWHITE_H__
#define __XWHITE_H__

#include "xtypes.h"
#include "xiptree.h"

/* Black List --------------------*/
typedef struct _xwhitelist {
  char *ipv4str;  /* 1.2.3.4;1.2.3.4-2.3.4.5;1.2.3.4/12 */
} xwhitelist;

typedef struct _xwhitelist_table {
  Xiptree      *xtree;

  struct htab  *htab;
  xfmem_t      *space;

} xwhitelist_table;


void xwhite_lock (void);
void xwhite_unlock (void);

void xwhite_create (void); 
void xwhite_destroy (void);
void xwhite_add (char *ip);
void xwhite_del (char *ip);
void xwhite_apply (void);

xwhitelist *xwhite_find (ub32 ip);
xwhitelist **xwhite_get_array (int *bu_cnt);


#endif

