#ifndef __XFILTER_H__
#define __XFILTER_H__

#include "bpm.h"
#include "cron.h"
#include "mutex.h"
#include "xrbt.h"
#include "xipmap.h"
#include "xportmap.h"

#define XFILTER_MAX_MATCH_SIZE  32
#define XFILTER_MAX_BUFF_SIZE   2048


typedef struct _Xftable {
  XRBTN32 node;  /* MUST first position */

  ub16 filter_id;     
  ub16 priority; /* rule priority */ 
  
  char *src_ip;   /* 1.2.3.4;1.2.3.4-2.3.4.5;1.2.3.4/12 */
  char *src_port; /* 10,20,30-40 */

  char *dst_ip;   /* 1.2.3.4;1.2.3.4-2.3.4.5;1.2.3.4/12 */
  char *dst_port; /* 10,20,30-40 */
  
  char buff[XFILTER_MAX_BUFF_SIZE];

  xportmap *sport;   /* src_ip port map */
  xportmap *dport;   /* dst_ip port map */

#define XFILTER_TCP_PROTOCOL  'T'
#define XFILTER_UDP_PROTOCOL  'U'
#define XFILTER_ICMP_PROTOCOL 'I'
#define XFILTER_ALL_PROTOCOL  '*'
  char *protocol;
  ub8 xprotocol;  /*xnet protocol */

#define XFILTER_ACCEPT  'A'
#define XFILTER_DROP    'D'
#define XFILTER_REJECT  'R' 
  ub8 policy;

#define XFILTER_ENABLE   'E'
#define XFILTER_DISABLE  'D' 
  ub8 active;

  time_t stime, etime;

  ub64 drop_cnt;
  ub64 reject_cnt;
} Xftable;

typedef struct _Xfmatch {
  Xftable *table[XFILTER_MAX_MATCH_SIZE];
  char match[XFILTER_MAX_MATCH_SIZE];
  char mcnt;
} Xfmatch;

typedef XRBTR32 xmatch_t;

typedef struct _Xfilter {
  Xipmap   *smap;   /* ip table (Amoeba RB Tree) */
  Xipmap   *dmap;   /* ip table (Amoeba RB Tree) */
  XRBTR32  *table;  /* Xftable */
  char     active;  /* enable, disable */
  Xfmatch  match;
} Xfilter;


Xfilter *xfilter_create (int table_size);
void     xfilter_destroy (Xfilter *xf);

void     xfilter_add (Xfilter *xf, int filter_id, char *portocol, char *src_ip, char *src_port, char *dst_ip, char *dst_port, char priority, char policy, char enable, time_t start_time, time_t end_time);
void     xfilter_del (Xfilter *xf,  int filter_id);
void     xfilter_apply (Xfilter *xf);

void     xfilter_set_priority_id (Xfilter *xf, int id, int priority);
void     xfilter_enable (Xfilter *xf, int filter_id);
void     xfilter_disable (Xfilter *xf, int filter_id);


void     xfilter_enable_table (Xfilter *xf);
void     xfilter_disable_table (Xfilter *xf);

Xfmatch *xfilter_lookup (Xfilter *xf, char protocol, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, time_t ct);
Xftable *xfilter_find (Xfilter *xf, char protocol, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, time_t ct);
Xftable *xfilter_match_id (Xfmatch *xm, int filter_id);

Xftable *xfilter_get_table_info (Xfilter *xf, int filter_id);
Xftable **xfilter_get_table_array (Xfilter *xf, int *cnt);

char *xfilter_protocol_str (ub8 protocol);

#endif
