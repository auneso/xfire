#ifndef __XNAT_H__
#define __XNAT_H__
#include "xportpool.h"
#include "xrbt.h"

#define XNAT_ENABLE   0
#define XNAT_DISABLE  1

#define XNAT_NONE        0
#define XNAT_INBOUND     1
#define XNAT_OUTBOUND    2

#define XNAT_ALIAS_SIZE       64
#define XNAT_IP_SIZE         256

#define XNAT_DEFAULT_WEIGHT  1

typedef struct _xnat_virtual xnat_virtual;
typedef struct _xnat_local   xnat_local;
typedef struct _xnat_table   xnat_table;


/* virtual ip */
struct _xnat_virtual {
  XRBTN32 node;  /* MUST first position */
  ub16 virtual_id;
  ub16 local_id;
  
  ub8  port_id;

  char alias[XNAT_ALIAS_SIZE];
  char ipaddrs[XNAT_IP_SIZE]; /* virtual ip */

  ub16 weight;
  XRBTR32 *virtual_ip_table;
  xvector *weight_table;

  xnat_local *local;
};

/* unicast real ip */
struct _xnat_local {
  XRBTN32 node;  /* MUST first position */
  ub16 local_id;
  ub16 virtual_id;

#define XNONE_TYPE 0
#define XDNAT_TYPE 1
#define XSNAT_TYPE 2
#define XBOTH_TYPE 3
  char nat_type;

  char alias[XNAT_ALIAS_SIZE];
  char local_ips[XNAT_IP_SIZE];  
  char dst_ips[XNAT_IP_SIZE]; 


  ub16 weight;
  XRBTR32 *local_ip_table;
  xvector *weight_table;

  Xiptree *dst_ip_table;

  xnat_virtual *virtual;
}; 

struct _xnat_table {
  Xiptree *virtual; 
  Xiptree *local; 
}; 


void xnat_create (xbridge *xb);
void xnat_destroy (void);

void xnat_virtual_add (ub16 virtual_id, char *ips, ub8 port_id, char *alias);
void xnat_virtual_del (ub16 virtual_id);

void xnat_local_add (ub16 local_id, char *src_ips, char *dst_ips, char *alias, ub8 nat_type, ub16 virtual_id);
void xnat_local_del (ub16 local_id);


#endif
