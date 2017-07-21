#ifndef __XIPFIND_H__
#define __XIPFIND_H__


#include "xfmem.h"
#include "hashtab.h"
#include "mutex.h"
#include "xipmap.h"

typedef struct _Xftab {
  int pidx;       /* hash key */
  int cidx;

  char *ipv4str;  /* 1.2.3.4;1.2.3.4-2.3.4.5;1.2.3.4/12 */
  short  flags;   /* hash item flags */
#define XFTAB_ACTIVE 0
#define XFTAB_UPDATE 1
#define XFTAB_DELETE 2
} Xftab;

typedef struct _Xfip {
  Xipmap       *xmap;   /* ip table (Amoeba RB Tree) */

  struct htab  *htab;   /* active filter (Hash table) */
  xfmem_t      *space;

  short         dorun;  /* active, disable */
#define XFIP_ENABLE  0
#define XFIP_DISABLE 1
} Xfip;


Xfip    *xfip_create (void);
void     xfip_destroy (Xfip *xf);
int      xfip_insert (Xfip *xf, int pidx, int cidx,  char *ip);
int      xfip_delete (Xfip *xf,  int pidx, int cidx);
void     xfip_compile (Xfip *xf);
xvector *xfip_search (Xfip *xf, unsigned int ip);
xvector *xfip_check (Xfip *xf, char *ip);

void     xfip_enable (Xfip *xf);
void     xfip_disable (Xfip *xf);

int      xfip_match (xvector *xv, int pidx);

#endif
