#ifndef __XSESSION_H__
#define __XSESSION_H__
#include <time.h>
#include "xbridge.h"
#include "spt.h"
#include "xtimeval.h"
#include "xportpool.h"

/* PPS_BPS -----------------------------------------------------*/
#define PPS_BPS(t)                                     \
  t->total_pkts++;                                     \
  t->total_bytes += xp->pkt_len;                       \
  t->pkts++;                                           \
  t->bytes += xp->pkt_len;                             \
  dt = xdelta_time_in_seconds(&xp->ts, &t->pkt_time);  \
  if (dt) {                                            \
    t->pps = t->pkts / dt;                             \
    t->bps = (t->bytes * 8) / dt;                      \
    t->pkt_time  = xp->ts;                             \
    t->pkts = 0;                                       \
    t->bytes = 0;                                      \
  }


#define XSESSION_FIN_TIME 1

typedef struct _xsession {
  spt_t   timer;   /* MUST first position */

  ub32    hash;
  struct _xsession *next;

  /* session key */
  ub32 src_ip;
  ub32 dst_ip;
  ub16 src_port;
  ub16 dst_port;

  ub16 protocol;
  ub8  dir;
  ub8  bound; 

  ub8 new;
  ub8 syn;
  ub8 rst;
  ub8 fin_src;
  ub8 fin_dst;

  ub32 xip;   /* vip, rip */
  ub16 xport; /* vport, rport */

  ub64 total_bytes, total_pkts;
  ub64 bytes, pkts;
  ub32 pps, bps;
  struct timeval pkt_time;

  struct timeval htime;
  struct timeval ctime;

  xsport *xsp;
} xsession;

typedef struct _xsession_table {
  xsession   **table;
  ub32        tsize;
  ub32        count;
  xfmem_t    *cache;
  spt_t      *timer;

  ub64 tcp, udp, icmp;
} xsession_table;

#define XSESSION_FROM_SRC  1
#define XSESSION_FROM_DST  2

void xsession_table_create (void);
void xsession_table_destroy (void);

int xsession_count (void);

xsession *xsession_search (xpacket *xp);
xsession *xsession_find (xpacket *xp, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, ub8 protocol, ub8 bound);
xsession *xsession_get (xpacket *xp, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, ub8 protocol, ub8 bound);

void xsession_set_tcp_timeout (int timeout);
void xsession_set_udp_timeout (int timeout);
void xsession_set_icmp_timeout (int timeout);
void xsession_set_table_size (int size);

xsession **xsession_get_table_array (int *cnt);
void xsession_dump (void);

#endif
