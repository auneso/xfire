#ifndef __XIPORT_H__
#define __XIPORT_H__

#include "xfmem.h"
#include "hashtab.h"
#include "mutex.h"
#include "xipmap.h"
#include "xportmap.h"

typedef struct _Xipt {
  int pidx;
  int cidx;
  
  char *ipv4str;
  xportmap *xp;
} Xipt;

typedef struct _Xiport {
  Xipmap       *xmap;   /* ip table */

  struct htab  *htab;   /* filter table */
  xfmem_t      *space;
} Xiport;



Xiport  *xiport_create (void);
int      xiport_insert2 (Xiport *xf, int pidx, int cidx,  char *ip, char *port);
int      xiport_insert (Xiport *xf,  int cidx,  char *ip, char *port);

int      xiport_delete2 (Xiport *xf,  int pidx, int cidx);
int      xiport_delete (Xiport *xf,  int cidx);
void     xiport_compile (Xiport *xf);
int      xiport_find (Xiport *xf, unsigned int ip, unsigned short port);
int      xiport_search (Xiport *xf, unsigned int ip, unsigned short port);
xvector *xiport_lookup (Xiport *xf, unsigned int ip, unsigned short port);
void     xiport_destroy (Xiport *xf);

int xiport_match (xvector *xv, int pidx);
void xiport_match_free (xvector *xv);

#endif
