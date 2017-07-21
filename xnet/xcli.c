#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


#include "xtypes.h"
#include "format.h"
#include "xstring.h"
#include "xcli.h"
#include "screen.h"
#include "xvendor.h"
#include "xsession.h"
#include "xbridge.h"
#include "xpacket.h"
#include "xarp.h"
#include "xroute.h"
#include "xwall.h"
#include "xalert.h"
#include "xnat.h"
#include "xdhcp.h"
#include "xfire.h"


static int pidx, cidx;
static char xcli_use = 0;

static void print_line (int x, int y, int n, char c)
{
  int i;

  goto_cursor(x, y);
  for (i = 0; i < n; i++) putchar(c);
  fflush(stdout);
}

static void prompt(void)
{
  goto_cursor(1, 80);
  printf("xfire > ");
  erase_from_line();
}

static void print_title (void)
{
  erase_whole_screen();
  print_line(1, 2, 120, '=');
  goto_cursor(1, 3);
  printf("MENU [1:traffic 2:device 3:xarp 4:xroute 5:xsession, 6:xfilter 7:xalert 8:xnat]\n");
}

static void print_xfilter_title (void)
{
  erase_whole_screen();
  print_line(1, 2, 120, '=');
  goto_cursor(1, 3);
  printf("XFILTER MENU [1:list 2:add 3:del 4:apply 5:quit]\n");
}

static void print_xnat_title (void)
{
  erase_whole_screen();
  print_line(1, 2, 120, '=');
  goto_cursor(1, 3);
  printf("XNAT MENU [1:list 2:virtaulr_add 3:real_add 4:virtaul_del 5:real_del 6:quit]\n");
}


static void xtraffic_print (void)
{
  xpkt_cnt rx, tx;
  
  xpacket_get_rx_count(&rx);
  xpacket_get_tx_count(&tx);

  goto_cursor(1, 5);
  printf("$$$ TRAFFIC $$$\n");

  printf("pps=%ld/%ld ",         rx.pps, tx.pps);
  printf("max_pps=%ld/%ld ",     rx.max_pps, tx.max_pps);
  printf("bps=%ld/%ld ",         rx.bps, tx.bps);
  printf("max_bps=%ld/%ld\n",    rx.max_bps, tx.max_bps);

  printf("ip_pps=%ld/%ld ",      rx.ipv4_pps, tx.ipv4_pps);
  printf("tcp_pps=%ld/%ld ",     rx.tcp_pps, tx.tcp_pps);
  printf("udp_pps=%ld/%ld ",     rx.udp_pps, tx.udp_pps);
  printf("icmp_pps=%ld/%ld ",    rx.icmp_pps, tx.icmp_pps);
  printf("arp_pps=%ld/%ld ",     rx.arp_pps, tx.arp_pps);
  printf("other_pps=%ld/%ld\n",  rx.other_pps, tx.other_pps);

  printf("ip_bps=%ld/%ld ",      rx.ipv4_bps, tx.ipv4_bps);
  printf("tcp_bps=%ld/%ld ",     rx.tcp_bps, tx.tcp_bps);
  printf("udp_bps=%ld/%ld ",     rx.udp_bps, tx.udp_bps);
  printf("icmp_bps=%ld/%ld ",    rx.icmp_bps, tx.icmp_bps);
  printf("arp_bps=%ld/%ld ",     rx.arp_bps, tx.arp_bps);
  printf("other_bps=%ld/%ld\n",   rx.other_bps, tx.other_bps);

  printf("pkt_77=%ld/%ld ",      rx.p_77, tx.p_77);
  printf("pkt_110=%ld/%ld ",     rx.p_110, tx.p_110);
  printf("pkt_250=%ld/%ld ",     rx.p_250, tx.p_250);
  printf("pkt_500=%ld/%ld ",     rx.p_500, tx.p_500);
  printf("pkt_1000=%ld/%ld ",    rx.p_1000, tx.p_1000);
  printf("pkt_large=%ld/%ld ",   rx.p_large, tx.p_large);
  printf("pkt_jumbo=%ld/%ld ",   rx.p_jumbo, tx.p_jumbo);
}

static void xdevice_xdev_print (xdevice *xd)
{
  xpkt_cnt xc;
  struct xbridge_eth_stats stats, tstats;


  xfire_read_lock();

  xpacket_dev_stats(xd, &stats);
  xpacket_stats(&tstats);
  xpacket_get_rx_count_dev(xd, &xc);

  xfire_read_unlock();

  printf("dev=%s ",          xd->xdev);
  printf("alias=%s ",        xd->alias);
  printf("idx=%d ",          xd->portid);
  printf("mac=%s ",          etheraddr_string(xd->xmac));
  printf("oui=%s ",          get_oui_info(xd->xmac));
  printf("link=%s\n",         xd->link ? "down":"up");


  printf("total_pkts= %ld ",   tstats.ipackets + tstats.opackets);
  printf("total_bytes= %ld ",  tstats.ibytes + tstats.obytes);

  printf("dev_pkts=%ld ",     stats.ipackets + stats.opackets);
  printf("dev_drop=%ld\n",    stats.imissed + stats.ierrors + stats.oerrors);


  printf("drop_pkts=%ld ",    xc.drop_p);
  printf("drop_bytes=%ld ",   xc.drop_b);

  printf("error_pkts=%ld ",   xc.error_p);
  printf("error_bytes=%ld\n",  xc.error_b);

  printf("pps=%ld ",          xc.pps);
  printf("max_pps=%ld ",      xc.max_pps);
  printf("bps=%ld ",          xc.bps);
  printf("max_bps=%ld\n",      xc.max_bps);

  printf("ip_pps=%ld ",       xc.ipv4_pps);
  printf("tcp_pps=%ld ",      xc.tcp_pps);
  printf("udp_pps=%ld ",      xc.udp_pps);
  printf("icmp_pps=%ld ",     xc.icmp_pps);
  printf("arp_pps=%ld ",      xc.arp_pps);
  printf("other_pps=%ld\n",    xc.other_pps);

  printf("ip_bps=%ld ",       xc.ipv4_bps);
  printf("tcp_bps=%ld ",      xc.tcp_bps);
  printf("udp_bps=%ld ",      xc.udp_bps);
  printf("icmp_bps=%ld ",     xc.icmp_bps);
  printf("arp_bps=%ld ",      xc.arp_bps);
  printf("other_bps=%ld\n\n",     xc.other_bps);
}


static void xdevices_print (void)
{
  int xdev_list_cnt, i;
  xdevice **xdev_list;

  xdev_list = xpacket_xdev_table_array(&xdev_list_cnt);

  if (xdev_list) {
    goto_cursor(1, 5);
    printf("$$$ DEVICE $$$\n");
    for (i = 0; i < xdev_list_cnt; i++) {
      xdevice_xdev_print(xdev_list[i]);
    }
    xfree(xdev_list);
  }
}

static void xarp_print (void)
{
  XARP **arp;
  int i, cnt;

  goto_cursor(1, 5);
  printf("$$$ XARP $$$\n");
  xfire_read_lock(); 
  
  arp = xarp_get_table_array(&cnt);
  if (cnt) {
    for (i = 0; i < cnt; i++) { 
      printf("dev=[%s], ip=[%s], mac=[%s], oui=[%s]\n", arp[i]->xdev->xdev, intoa(arp[i]->ip), etheraddr_string(arp[i]->mac), get_oui_info(arp[i]->mac));
    }
    xfree(arp);
  }
  xfire_read_unlock();
}

static void xroute_print (void)
{
  goto_cursor(1, 5);
  printf("$$$ XROUTE $$$\n");
  xfire_read_lock();
  xroute_dump();
  xfire_read_unlock();

}

static void xsession_print (void)
{
  xsession **xst, *xs;
  int i, cnt;

  goto_cursor(1, 5);

  xfire_read_lock(); 

  xst = xsession_get_table_array(&cnt);
  printf("$$$ XSESSION : %d $$$\n", cnt);

  if (cnt) {
    if (cnt > 80) cnt = 80; 
    for (i = 0; i < cnt; i++)  {
      xs = xst[i];
      printf("%s src=%s : %u, dst=%s : %u, pkts=%ld, bytes=%ld, pps=%d, bps=%d, avg_pkt_size=%ld\n", 
         xnet_protocol_str(xs->protocol), intoa(xs->src_ip), xs->src_port, intoa(xs->dst_ip), xs->dst_port, xs->total_pkts, xs->total_bytes, xs->pps, xs->bps * 8, xs->total_bytes/xs->total_pkts);
    }
    xfree(xst);
  }
  xfire_read_unlock();
}



static void xfilter_proc (void) 
{
  char buf[1024], *ptr[11];
  int len;

  Xftable **xft, *xf;
  int i, count;

  switch (cidx) {
    case 1: // list
      xfire_read_lock();
      xft = xwall_filter_array(&count);
      if (count) {
        for (i = 0; i < count; i++) {
          xf = xft[i];
          printf("id = %d, protocol = %s src_ip =%s, src_port = %s, dst_ip = %s, dst_port = %s, priority = %d, policy = %c, enable = %c, stime = %ld, etime = %ld\n",
                  xf->filter_id, xf->protocol, xf->src_ip, xf->src_port, xf->dst_ip, xf->dst_port, xf->priority, xf->policy, xf->active, xf->stime, xf->etime);
        }
        xfree(xft);
      }
      xfire_read_unlock();
      break;

    case 2: // add
      printf("ADD  1:filter_id 2:protocol(T/U/I) 3:src_ip 4:src_port 5:dst_ip 6:dst_port 7:priority 8:policy(A/D/R) 9:enable(E/D) 10:state(N/S/C) 11:stime 12:etime");
      prompt(); 
      fgets(buf, sizeof(buf), stdin);
      len = strlen(buf);
      buf[len] = 0;
      if (msplit(buf, ptr, 11, " \t") == 12) {
        xfire_write_lock();
        xwall_filter_add(ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8], ptr[9], ptr[10]);
        xfire_write_unlock();
        printf("xfilter add  OK\n");
      } else {
        printf("xfilter add  para error\n");
      }
      cidx = 0;
      break;
    case 3: // del
      printf("DEL filter_id");  
      prompt(); 
      fgets(buf, sizeof(buf), stdin);
      len = strlen(buf);
      buf[len] = 0;
      xfire_write_lock();
      xwall_filter_del(buf); 
      xfire_write_unlock();
      printf("xfilter del  OK\n");
      cidx = 0;
      break;

    case 4: // apply
      xfire_read_lock();
      xwall_filter_apply();
      xfire_read_unlock();
      printf("xfilter apply  OK\n");
      cidx = 0;
      break;
  }
}

static void xfilter_print (void)
{
  char buf[1024];
  int len;

  while (1) {
    prompt(); 
    if (tty_key_pressed(1)) {
      fgets(buf, sizeof(buf), stdin);
      len = strlen(buf);
      buf[len] = 0;
      cidx = atoi(buf);
      if (cidx == 5) break;
    } else {
      print_xfilter_title();
      xfilter_proc();
    }
  }
  pidx = 0;
}


static void xalert_print (void)
{
  xblack_hole **xbt, *xb;
  int i, cnt;
  goto_cursor(1, 5);

  xfire_read_lock();
  xbt = xalert_get_blackhole_table_array(&cnt);
  printf("$$$ XALERT : %d $$$\n", cnt);

  if (cnt) {
    if (cnt > 20) cnt  = 20;
    for (i = 0; i < cnt; i++)  {
     xb = xbt[i];
     printf("sip = %s, sport = %u, dip = %s, dport = %u, msg = %s\n", intoa(xb->src_ip), xb->src_port, intoa(xb->dst_ip), xb->dst_port, xb->msg);
    }
    xfree(xbt);
  }
  xfire_read_unlock();
}


static void xnat_proc (void)
{
}


static void xnat_print (void)
{
  char buf[1024];
  int len;

  while (1) {
    prompt();
    if (tty_key_pressed(1)) {
      fgets(buf, sizeof(buf), stdin);
      len = strlen(buf);
      buf[len] = 0;
      cidx = atoi(buf);
      if (cidx == 6) break;
    } else {
      print_xnat_title();
      xnat_proc();
    }
  }
  pidx = 0;
}

void cli_proc (void)
{
  cidx = 0;
  switch (pidx) {
    case 1 :
     xtraffic_print();
     break;
    case 2 :
     xdevices_print();
     break;
    case 3 :
     xarp_print();
     break;
    case 4 :
     xroute_print();
     break;
    case 5 :
     xsession_print();
     break;
    case 6 :
     xfilter_print();
     break;
    case 7 :
     xalert_print();
     break;
    case 8 :
     xnat_print();
     break;
  }
}


void *xfire_cmd (void *para)
{
  char buf[1024];
  int len;

  sleep(5);

  erase_whole_screen();
  print_title();

  while (1) {
    prompt();
    if (tty_key_pressed(1)) {
      fgets(buf, sizeof(buf), stdin); 
      len = strlen(buf);
      buf[len] = 0;
      pidx = atoi(buf);
    } else {
      print_title();
      cli_proc();
    }
  }
  return NULL;
}


void xcli_set_use (void)   { xcli_use = 1; }
void xcli_set_unuse (void) { xcli_use = 0; }

void xfire_cli (void)
{
  if (!xcli_use) return;

  pthread_t thread_id;
  pthread_attr_t attr;

  (void) pthread_attr_init(&attr);
  (void) pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  pthread_create(&thread_id, &attr, xfire_cmd, NULL);
  pthread_attr_destroy(&attr);
}

