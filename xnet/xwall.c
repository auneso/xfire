/*
*/
#include "format.h"
#include "xstring.h"
#include "xiparser.h"
#include "xfilter.h"
#include "xbridge.h"
#include "xsession.h"
#include "xalert.h"
#include "xwall.h"
#include "xfire.h"

#define XWALL_DEFAULT_RULESET_SIZE 1000


#define XWALL_FILTER_FOMAT_NUM 11
// 1:filter_id 2:protocol 3:src_ip 4:src_port 5:dst_ip 6:dst_port 7:priority 8:policy 9:enable 10:stime 11:etime
#define XWALL_FILTER_FOMAT "%d %s %s %s %s %s %d %c %c %ld %ld\n"

static int default_policy = XFILTER_ACCEPT;

static Xfilter *xwall_filter = NULL;

void save_filter (void)
{
  FILE *fp;
  Xftable **xft, *xt;
  int i, cnt;

  if ((fp = fopen(XFIRE_FILTER_CFG_FILE , "w+"))) {
    xft = xfilter_get_table_array(xwall_filter, &cnt);
    fprintf(fp, "# 1:filter_id 2:protocol 3:src_ip 4:src_port 5:dst_ip 6:dst_port 7:priority 8:policy 9:enable 10:stime 11:etime\n");
    if (xft && cnt) {
      for (i = 0; i < cnt; i++) {
        xt = xft[i];
        fprintf(fp, XWALL_FILTER_FOMAT, xt->filter_id, xt->protocol, xt->src_ip, xt->src_port, xt->dst_ip, xt->dst_port, xt->priority, xt->policy, xt->active, xt->stime, xt->etime);
      }
    }
    fclose(fp);
  }
}

static void load_filter (void)
{
  FILE *fp;
  char buf[1024];
  char *bptr[XWALL_FILTER_FOMAT_NUM];
  int scnt;

  if ((fp = fopen(XFIRE_FILTER_CFG_FILE , "r"))) {
    while (fgets(buf, sizeof(buf), fp)) {
      if (buf[0] == '#' || buf[0] == '\n') continue;
      printf("buf = %s\n", buf);
      scnt = msplit(buf, bptr, XWALL_FILTER_FOMAT_NUM, " \t");
      if (scnt == XWALL_FILTER_FOMAT_NUM) {
        xfilter_add(xwall_filter, atoi(bptr[0]), bptr[1], bptr[2], bptr[3], bptr[4], bptr[5], atoi(bptr[6]), *bptr[7], *bptr[8], atol(bptr[9]), atol(bptr[10])); 
      }
    }
    xfilter_apply(xwall_filter);
    fclose(fp);
  } else {
    save_filter();
  }
}

void xwall_filter_create (void)
{
  if (xwall_filter == NULL) {
    xwall_filter = xfilter_create(XWALL_DEFAULT_RULESET_SIZE);
    load_filter();
  }
}

void xwall_filter_destroy (void)
{
  if (xwall_filter) {
    xfilter_destroy(xwall_filter);
    xwall_filter = NULL;
  }
}


//  1:filter_id 2:protocol 3:src_ip 4:src_port 5:dst_ip 6:dst_port 7:priority 8:policy 9:enable 11:stime 12:etime
void xwall_filter_add (char *filter_id, char *protocol, char *src_ip, char *src_port, char *dst_ip, char *dst_port, char *priority,
                       char *policy, char *enable, char *stime, char *etime)
{
  xfilter_add(xwall_filter, atoi(filter_id), protocol, src_ip, src_port, dst_ip, dst_port, atoi(priority), *policy, *enable, atol(stime), atol(etime)); 
}


void xwall_filter_del (char *filter_id)
{
  xfilter_del(xwall_filter, atoi(filter_id));
}

void xwall_filter_apply (void)
{
  xfilter_apply(xwall_filter);
  save_filter();
}


static int check_session (xpacket *xp)
{
  if (xp->protocol == XNET_TCP_PROTOCOL && xp->p_tcph->th_flags == X_TCP_SYN) {
    xalert_put_blackhole(xp->src_ip, xp->dst_ip, xp->src_port, xp->dst_port, xp->protocol, "SYN Drop Rule");
    return XFILTER_DROP;
  }

  if (xsession_search(xp)) return XFILTER_ACCEPT;

  xalert_put_blackhole(xp->src_ip, xp->dst_ip, xp->src_port, xp->dst_port, xp->protocol, "No Session Drop");
  return XFILTER_DROP; 
}

static int check_policy (xpacket *xp, Xftable *xf)
{
  if (xf->policy == XFILTER_DROP) {

    xalert_put_blackhole(xp->src_ip, xp->dst_ip, xp->src_port, xp->dst_port, xp->protocol, 
                    "Drop Rule id = %d, protocol = %s src_ip =%s, src_port = %s, dst_ip = %s, dst_port = %s, priority = %d, policy = %c, enable = %c, stime = %ld, etime = %ld",
                    xf->filter_id, xf->protocol, xf->src_ip, xf->src_port, xf->dst_ip, xf->dst_port, xf->priority, xf->policy, xf->active, xf->stime, xf->etime);

    xf->drop_cnt++;
    return XFILTER_DROP; 
  }
  if (xf->policy == XFILTER_REJECT) {

    xalert_put_blackhole(xp->src_ip, xp->dst_ip, xp->src_port, xp->dst_port, xp->protocol, 
                    "Reject Rule id = %d, protocol = %s src_ip =%s, src_port = %s, dst_ip = %s, dst_port = %s, priority = %d, policy = %c, enable = %c, stime = %ld, etime = %ld",
                    xf->filter_id, xf->protocol, xf->src_ip, xf->src_port, xf->dst_ip, xf->dst_port, xf->priority, xf->policy, xf->active, xf->stime, xf->etime);

    xf->reject_cnt++;
    return XFILTER_REJECT;
  }
  return default_policy;
}

int xwall_filter_find (xpacket *xp)
{
  Xftable *xft;

  if (xp->protocol == XNET_ARP_PROTOCOL || xp->send == XFIRE_SEND_PACKET) return XFILTER_ACCEPT;

  xft = xfilter_find(xwall_filter,  xp->protocol, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port,  xp->ts.tv_sec);
  if (xft) {
    if (xft->policy == XFILTER_ACCEPT) {
      if (xp->protocol == XNET_TCP_PROTOCOL) {
        if (xp->p_tcph->th_flags == X_TCP_SYN) {
          return XFILTER_ACCEPT;
        } else 
        if (xsession_search(xp)) {
          return XFILTER_ACCEPT;
        } else {
          xalert_put_blackhole(xp->src_ip, xp->dst_ip, xp->src_port, xp->dst_port, xp->protocol, "No Session Drop");
          return XFILTER_DROP;
        }
      } else  { 
        return XFILTER_ACCEPT;
      }
    } 
    return check_policy(xp, xft);
  } else {
    return check_session(xp);
  }
}


Xftable **xwall_filter_array (int *count)
{
  return xfilter_get_table_array(xwall_filter, count);
}
