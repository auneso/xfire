#ifndef __XALERT_H__
#define __XALERT_H__
#include "xrbt.h"

#define XALERT_MSG_SIZE 256

typedef struct _xblack_hole {
  XRBTN node; /* MUST first position */

  ub32   src_ip;
  ub32   dst_ip;
  ub16   src_port;
  ub16   dst_port;
  ub8    protocol;

  char   msg[XALERT_MSG_SIZE];

#define XDOS_BLACKHOLE_ALERT  0x01
#define XDOS_BLACKHOLE_REJECT 0x02
#define XDOS_BLACKHOLE_DROP   0x04
#define XDOS_BLACKHOLE_AUTO   0x08
  ub8   action;

  ub64  hit_cnt;

  time_t stime, etime, btime;
  int    timer;
} xblack_hole;

typedef struct _xalert_table {
  XRBTR    root;
  time_t  ctime;      /* create time */
} xalert_table;


void xalert_create (void);
void xalert_destroy (void);

void xalert_set_blackhole_time (int time);
int xalert_count (void);

void xalert_put_blackhole (ub32 src_ip, ub32 dst_ip, ub16 src_port, ub16 dst_port, ub8 protocol, char *msg, ...);
void xalert_check_blackhole_timer (void);

xblack_hole **xalert_get_blackhole_table_array (int *bh_cnt);

void xalert_set_use (void);
void xalert_set_unuse (void);

#endif
