#include <time.h>

#include "xalloc.h"
#include "xstring.h"
#include "xalert.h"

#define XALERT_BLACKHOLE_TIME 10


static xalert_table *xat;
static int xalert_bh_time = XALERT_BLACKHOLE_TIME;

static char xalert_use = 1;
void xalert_set_use () { xalert_use = 1; }
void xalert_set_unuse () { xalert_use = 0; }



static int black_comp (void *a, void *b)
{
  xblack_hole *ka = (xblack_hole *)a;
  xblack_hole *kb = (xblack_hole *)b;

  if (ka->src_ip == kb->src_ip) {
    if (ka->dst_ip == kb->dst_ip) {
      if (ka->src_port == kb->src_port) {
        if (ka->dst_port == kb->dst_port) {
          return ka->protocol - kb->protocol;
        } else return ka->dst_port - kb->dst_port;
      } else return ka->src_port - kb->src_port; 
    } else return ka->dst_ip - kb->dst_ip;
  } else return ka->src_ip - kb->src_ip;
}


void xalert_create (void)
{
  xat = xzalloc(sizeof(xalert_table));
  xrbt_init(&xat->root, black_comp, sizeof(xblack_hole), 0);
  xat->ctime = time(NULL);
}


void xalert_destroy (void)
{
  if (xat) {
    xrbt_free(&xat->root);
    xfree(xat);
    xat = NULL;
  }
}

void xalert_set_blackhole_time (int time)
{
  xalert_bh_time = time;
}

int xalert_count (void)
{
  return xrbt_count(&xat->root);
}

void xalert_put_blackhole (ub32 src_ip, ub32 dst_ip, ub16 src_port, ub16 dst_port, ub8 protocol, char *msg, ...)
{
  if (!xalert_use) return;
  
  int new;
  xblack_hole *bh;
  va_list vp;
  time_t ct = time(NULL);
  xblack_hole *key = xrbt_mem_zalloc(&xat->root);

  key->src_ip   = src_ip;
  key->dst_ip   = dst_ip;
  key->src_port = src_port;
  key->dst_port = dst_port;
  key->protocol = protocol;

  bh = (xblack_hole *)xrbt_insert(&xat->root, (XRBTN *)key, &new);
  if (new) {
    bh->stime = bh->etime = ct;
    bh->btime = ct + xalert_bh_time;
    bh->hit_cnt = 1; 

    // Send alert ==========================
  } else {
    xrbt_mem_free(&xat->root, key);

    bh->etime = ct;
    bh->btime = ct + xalert_bh_time;
    bh->hit_cnt++;
  }
  va_start(vp, msg);
  vsprintf(bh->msg, msg, vp);
}

static void out_blackhole (xblack_hole *bh)
{
  // Send alert ==========================

  xrbt_remove(&xat->root, (XRBTN *)bh);
  xrbt_mem_free(&xat->root, bh);
}

void xalert_check_blackhole_timer (void)
{
  xblack_hole *bh;
  time_t ct = time(NULL);

  if ((bh = (xblack_hole *)xrbt_first(&xat->root))) do {
    if (bh->btime < ct) out_blackhole(bh);
  } while ((bh = (xblack_hole *)xrbt_next((XRBTN *)bh)));
}

xblack_hole **xalert_get_blackhole_table_array (int *bh_cnt)
{
  xblack_hole **table, **tptr, *bh;
  int bcnt = xrbt_count(&xat->root);

  *bh_cnt = bcnt;
  if (bcnt == 0) return NULL;
  table = (xblack_hole **)xmalloc(sizeof(xblack_hole *) * bcnt);
  tptr = table;
  if ((bh = (xblack_hole *)xrbt_first(&xat->root))) do {
    *tptr++ = bh;
  } while ((bh = (xblack_hole *)xrbt_next((XRBTN *)bh)));
  return table;
}
