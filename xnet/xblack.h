#ifndef __XBLACK_H__
#define __XBLACK_H__

#include "xtypes.h"
#include "xiptree.h"

/* Black List --------------------*/
typedef struct _xblacklist {
  char *ipv4str;  /* 1.2.3.4;1.2.3.4-2.3.4.5;1.2.3.4/12 */
} xblacklist;

typedef struct _xblacklist_table {
  Xiptree      *xtree;

  struct htab  *htab;
  xfmem_t      *space;

} xblacklist_table;


void xblack_lock (void);
void xblack_unlock (void);

void xblack_create (void); 
void xblack_destroy (void);
void xblack_add (char *ip);
void xblack_del (char *ip);
void xblack_apply (void);

xblacklist *xblack_find (ub32 ip);
xblacklist **xblack_get_array (int *bu_cnt);


#endif

