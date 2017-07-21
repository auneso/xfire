#include <stdlib.h>
#include "xfilter.h"
#include "xnet.h"
#include "xfire.h"
  
struct xf_data {
  int filter_id;
  char *protocol;
  char *src_ip;
  char *src_port;
  char *dst_ip;
  char *dst_port;

  time_t start_time;
  time_t end_time;

  char priority;
  char policy;
  char enable;
  char state; 
} xfp [] = {
/*
{
  1, "T",
  "0.0.0.10-0.0.0.50, 0.0.0.100-0.0.0.170",  
  "*",
  "0.0.0.20-0.0.0.80, 0.0.0.100-0.0.0.200",
  "80,100-300",
  10, 
  20,
  5,
  XFILTER_ACCEPT,
  XFILTER_ENABLE,
  XFILTER_NON_STATE
},
{
  2, "T",
  "0.0.0.1-0.0.0.20, 0.0.0.21-0.0.0.255",
  "25,70-80,100,300",
  "*",
  "100,1000,4000",
  30, 
  60,
  10,
  XFILTER_ACCEPT,
  XFILTER_ENABLE,
  XFILTER_NON_STATE
},
{
  3, "TU",
  "0.0.0.40-0.0.0.100, 0.0.0.120-0.0.0.255",
  "100,150-200,210,500",
  "0.0.0.15-0.0.0.120, 0.0.0.210-0.0.0.220",  
  "1502,220,100-500",
  50, 
  100,
  1,
  XFILTER_ACCEPT,
  XFILTER_ENABLE,
  XFILTER_NON_STATE
}, 
*/
{
  4, "I",
  "*",
  "*",
  "20.0.1.10",
  "*",
  0,
  0,
  10,
  XFILTER_DROP,
  XFILTER_ENABLE,
  XFILTER_NON_STATE
},
{
  0, "I",
  "*",
  "*",
  "20.0.1.10",
  "*",
  0,
  0,
  10,
  XFILTER_DROP,
  XFILTER_ENABLE,
  XFILTER_NON_STATE
}
};
 
struct xf_key {
  char *src_ip;
  int src_port;
  char *dst_ip;
  int dst_port;
  time_t ct;
} xfk [] = {
//  { "0.0.0.50",  100, "0.0.0.215", 100, 21 }, // filter id 3
//  { "0.0.0.50",  100, "0.0.0.100", 100, 21 }, // filter id 1,3
  { "0.0.0.100", 0, "20.0.1.10",  0, 21 },  // filter id 1,2,3
  { NULL, 100, "20.0.1.10",  100, 21 }  // filter id 1,2,3
};

int main (int argc, char *argv[])
{
  Xfilter *xf;
  int i, j, cnt;

  ub32 sip = 0, dip = 0;
  ub16 sport = 0, dport = 0;

  Xftable *xt, **xtt;
  Xfmatch *xm;
  time_t ct, stime, etime;
  int time_check = 0;

  if (argc != 2 && argc != 5) {
    printf("Usage : xfilter time_check(y/n), xfilter src_ip src_port dst_ip dst_port\n");
    return 1;
  } 
  if (argc == 2) {
    if (argv[1][0] == 'y') time_check = 1; 
    xf = xfilter_create(3);

    for (i = 0; xfp[i].filter_id; i++) {
      stime = etime = 0;
      if (time_check) { stime = xfp[i].start_time; etime = xfp[i].end_time; }
      xfilter_add(xf, xfp[i].filter_id, xfp[i].protocol, xfp[i].src_ip, xfp[i].src_port, xfp[i].dst_ip, xfp[i].dst_port, xfp[i].priority, xfp[i].policy, xfp[i].enable, xfp[i].state, stime, etime);
    }
    xfilter_apply(xf);
 
    ct = 30;
    for (i = 0; xfk[i].src_ip; i++) {
      sip = atoin(xfk[i].src_ip);
      dip = atoin(xfk[i].dst_ip);
      sport = xfk[i].src_port;
      dport = xfk[i].dst_port;

      if ((xm = xfilter_lookup(xf, XNET_ICMP_PROTOCOL, sip, sport, dip, dport, ct))) {

        printf("\n\n match num = %d\n", xm->mcnt);
        for (j = 0; j < xm->mcnt; j++) {
          xt = xm->table[j];
          printf("ICMP match id = %d, src_ip = %s, src_port = %s, dst_ip = %s, dst_port = %s, priority = %d\n\n", xt->filter_id, xt->src_ip, xt->src_port, xt->dst_ip, xt->dst_port, xt->priority);
        }
      } 
      
      if ((xm = xfilter_lookup(xf, XNET_UDP_PROTOCOL, sip, sport, dip, dport, ct))) {

        printf("\n\nUDP match num = %d\n", xm->mcnt);
        for (j = 0; j < xm->mcnt; j++) {
          xt = xm->table[j];
          printf("UDP match id = %d, src_ip = %s, src_port = %s, dst_ip = %s, dst_port = %s, priority = %d\n\n", xt->filter_id, xt->src_ip, xt->src_port, xt->dst_ip, xt->dst_port, xt->priority);
        }
      }
    }
    printf("\n\n");

    xfilter_destroy(xf);

  } else {
    if (argc != 5) {
      printf("Usage : %s src_ip src_port dst_ip dst_port\n", argv[0]);
      return 1;
    }

    sip   = atoin(argv[1]);
    sport = atoi(argv[2]);
    dip   = atoin(argv[3]);
    dport = atoi(argv[4]);


    xf = xfilter_create(3);

    for (i = 0; xfp[i].filter_id; i++) {
      xfilter_add(xf, xfp[i].filter_id, xfp[i].protocol, xfp[i].src_ip, xfp[i].src_port, xfp[i].dst_ip, xfp[i].dst_port, xfp[i].priority, xfp[i].policy, xfp[i].enable, xfp[i].state, xfp[i].start_time, xfp[i].end_time);
    }
    xfilter_apply(xf);
  
    xtt = xfilter_get_table_array(xf, &cnt);
 
    if (cnt) {
      for (i = 0; i < cnt; i++) {
        xt = xtt[i];
        printf("id = %d, src_ip =%s, src_port = %s, dst_ip = %s, dst_port = %s, priority = %d\n", xt->filter_id, xt->src_ip, xt->src_port, xt->dst_ip, xt->dst_port, xt->priority);
      }
      xfree(xtt);
    }
    printf("\n\n");
  
    ct = 30;
    if ((xm = xfilter_lookup(xf, XNET_TCP_PROTOCOL, sip, sport, dip, dport, ct))) { 
      for (i = 0; i < xm->mcnt; i++) {
        xt = xm->table[i];
        printf("match id = %d, src_ip = %s, src_port = %s, dst_ip = %s, dst_port = %s, priority = %d\n", xt->filter_id, xt->src_ip, xt->src_port, xt->dst_ip, xt->dst_port, xt->priority);
      }
    }
    printf("\n\n");


    xfilter_destroy(xf);
  }
  return 0;
}

