/*
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>
#include <xdpdk.h>

#include "xtypes.h"
#include "hashf.h"
#include "format.h"
#include "xstring.h"
#include "xpacket.h"
#include "xarp.h"
#include "xwall.h"
#include "xipmap.h"
#include "xnet.h"
#include "xportpool.h"
#include "xalert.h"
#include "xnat.h"
#include "xsession.h"

static xsession_table *session_table = NULL;
static int tcp_session_timeout  = XNET_TCP_TIMEOUT;
static int udp_session_timeout  = XNET_UDP_TIMEOUT;
static int icmp_session_timeout = XNET_ICMP_TIMEOUT;
static int session_table_size   = 100000;

void xsession_set_tcp_timeout (int timeout)
{ tcp_session_timeout = timeout; }

void xsession_set_udp_timeout (int timeout)
{ udp_session_timeout = timeout; }

void xsession_set_icmp_timeout (int timeout)
{ icmp_session_timeout = timeout; }

void xsession_set_table_size (int size)
{ session_table_size = size; }



#define SESSION_TIMER_TIME 1
static time_t session_timer;

void xsession_table_create (void)
{
  int tsize, pidx;

  tsize = prime_size(session_table_size * 4, &pidx);
  session_table = (xsession_table *)xzalloc(sizeof(xsession_table));
  session_table->table = (xsession **)xzalloc(sizeof(xsession *) * tsize);
  session_table->tsize = tsize;
  session_table->cache = xfmem_create(sizeof(xsession), session_table_size);
  session_timer = time(NULL) + SESSION_TIMER_TIME;
}

void xsession_table_destroy (void)
{
  if (session_table) {
    xfmem_destroy(session_table->cache);
    xfree(session_table->table);
    xfree(session_table);
    session_table = NULL;
  }
}

int xsession_count (void)
{
  return session_table->count;
}

/* Hash function. Hashes to the same value even when source
   and destinations are inverted */
static ub32 xsession_hashfn (ub32 server_ip, ub16 server_port, ub32 client_ip, ub16 client_port, ub8 protocol, ub8 bound)
{
  ub32 h = ((server_ip ^ server_port) ^ (client_ip ^ client_port)) + protocol + bound;
  h ^= h >> 16;
  h ^= h >> 8;

  /* 0x9e375365UL == 40499 * 65543 - both are prime;
     the result is ~0.68*(2^32) --Chuck Lever */

  return (0x9e37 * (h & 0xffff) + 0x5365 * (h >> 16));
}

static void xsession_remove (xsession *sess)
{
  xsession **s;
  ub32 hash = xsession_hashfn(sess->dst_ip, sess->dst_port, sess->src_ip, sess->src_port, sess->protocol, sess->bound);
  ub32 hkey = hash % session_table->tsize;

  /* $$$$ End Session log $$$$ */
  xalert_put_blackhole (sess->src_ip, sess->dst_ip, sess->src_port, sess->dst_port, sess->protocol,
                   "%s-%s %s src=%s:%u, dst=%s:%u  pkts=%ld, bytes=%ld, pps=%d, bps=%d", asctime(localtime(&sess->ctime.tv_sec)), asctime(localtime(&sess->htime.tv_sec)),
                   xnet_protocol_str(sess->protocol), intoa(sess->src_ip), sess->src_port, intoa(sess->dst_ip), sess->dst_port, sess->total_pkts, sess->total_bytes, sess->pps, sess->bps * 8);

  s = &session_table->table[hkey];
  while ((*s) &&  (*s) != sess) s = &(*s)->next;

  if (*s) {
    (*s) = (*s)->next;

    switch  (sess->protocol) {
      case XNET_TCP_PROTOCOL  : session_table->tcp--;  break;
      case XNET_UDP_PROTOCOL  : session_table->udp--;  break;
      case XNET_ICMP_PROTOCOL : session_table->icmp--; break;
    }
    if (sess->xsp) xportpool_push(sess->xsp);  
    xfmem_remove(session_table->cache, sess);
    session_table->count--;
  }
}

static int xsession_get_timeout (xsession *sess, time_t ct)
{
 int timeout = 0;

 switch  (sess->protocol) {
  case XNET_TCP_PROTOCOL :
    if (ct < sess->htime.tv_sec + tcp_session_timeout) timeout = sess->htime.tv_sec + tcp_session_timeout - ct;
    break;
  case XNET_UDP_PROTOCOL :
    if (ct < sess->htime.tv_sec + udp_session_timeout) timeout = sess->htime.tv_sec + udp_session_timeout - ct;
    break;
  case XNET_ICMP_PROTOCOL :
    if (ct < sess->htime.tv_sec + icmp_session_timeout) timeout = sess->htime.tv_sec + icmp_session_timeout - ct;
    break;
  }
  return timeout;
}

static void xsession_check_timeout (time_t ct)
{
  if (session_timer > ct) return;

  xsession *sess;
  spt_t *tmp = NULL;
  int t;

  while ((sess = (xsession *)spt_dequeue(&session_table->timer))) {
    if (ct >= (time_t)sess->timer.prio) {
      if ((t = xsession_get_timeout(sess, ct))) {
        sess->timer.prio = ct + t;
        spt_enqueue(&tmp, (spt_t *)sess);
      } else {
        xsession_remove(sess);
      }
    } else  {
      spt_enqueue(&tmp, (spt_t *)sess);
      break;
    }
  }
  if (tmp) {
    while ((sess = (xsession *)spt_dequeue(&tmp)))
      spt_enqueue(&session_table->timer, (spt_t *)sess);
  }
  session_timer = ct + SESSION_TIMER_TIME;
}

static void xsession_check_fin (xpacket *xp, xsession *sess)
{
  ub8 flags = xp->p_tcph->th_flags;
 
  if (flags & X_TCP_SYN) sess->syn = 1;
  if (flags & X_TCP_RST) sess->rst = 1;
  if (flags & X_TCP_FIN) {
    if      (sess->dir == XSESSION_FROM_SRC) sess->fin_src = 1;
    else if (sess->dir == XSESSION_FROM_DST) sess->fin_dst = 1;
  }

  if (sess->rst || (sess->fin_src && sess->fin_dst)) {
    spt_remove(&session_table->timer, (spt_t *)sess);
    xsession_remove(sess);
  }
}

static xsession *_xsession_find (xpacket *xp, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, ub8 protocol, ub8 bound)
{
  xsession *sess;
  ub32 hash = xsession_hashfn(dst_ip, dst_port, src_ip, src_port, protocol, bound);
  ub32 hkey = hash % session_table->tsize;

  /* find the session in the table */
  for (sess = session_table->table[hkey]; sess; sess = sess->next) {
    if (sess->hash == hash && sess->protocol == xp->protocol && sess->bound == bound) {

      if (sess->src_ip == src_ip && sess->src_port == src_port
      &&  sess->dst_ip == dst_ip && sess->dst_port == dst_port) {
        sess->dir = XSESSION_FROM_SRC;
        return sess;
     } else
     if (sess->src_ip == dst_ip && sess->src_port == dst_port
     &&  sess->dst_ip == src_ip && sess->dst_port == src_port) {
       sess->dir = XSESSION_FROM_DST;
       return sess;
     }
    }
  }
  return NULL;
}

xsession *xsession_find (xpacket *xp, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, ub8 protocol, ub8 bound)
{
  xsession *sess;
  int dt;

  if ((sess = _xsession_find(xp, src_ip, src_port, dst_ip, dst_port, protocol, bound))) {
    PPS_BPS(sess);
    sess->htime = xp->ts;
    if (xp->protocol == XNET_TCP_PROTOCOL) xsession_check_fin(xp, sess); 
  }
  return sess;
}

static void xsession_set_timer (xpacket *xp, xsession *sess)
{
  switch  (xp->protocol) {
  case XNET_TCP_PROTOCOL :
    sess->timer.prio = xp->ts.tv_sec + tcp_session_timeout; session_table->tcp++;
    break;
  case XNET_UDP_PROTOCOL :
    sess->timer.prio = xp->ts.tv_sec + udp_session_timeout; session_table->udp++;
    break;
  case XNET_ICMP_PROTOCOL :
    sess->timer.prio = xp->ts.tv_sec + icmp_session_timeout; session_table->icmp++;
    break;
  default :
    printf("xsession_get error protocol = %d\n", xp->protocol);
    return;
  }
  spt_enqueue(&session_table->timer, (spt_t *)sess);
}

xsession *xsession_get (xpacket *xp, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, ub8 protocol, ub8 bound)
{
  xsession_check_timeout(xp->ts.tv_sec); 

  xsession *sess;
  int dt;
  ub32 hash = xsession_hashfn(dst_ip, dst_port, src_ip, src_port, protocol, bound);
  ub32 hkey = hash % session_table->tsize;

  /* find the session in the table */
  for (sess = session_table->table[hkey]; sess; sess = sess->next) {
    sess->new = 0;

    if (sess->hash == hash && sess->protocol == xp->protocol && sess->bound == bound) {
      if (sess->src_ip == src_ip && sess->src_port == src_port
      &&  sess->dst_ip == dst_ip && sess->dst_port == dst_port) {
        sess->dir = XSESSION_FROM_SRC;    
         goto find;
     } else 
     if (sess->src_ip == dst_ip && sess->src_port == dst_port
     &&  sess->dst_ip == src_ip && sess->dst_port == src_port) {
       sess->dir = XSESSION_FROM_DST;
       goto find;
     }
    }
  }

  sess = (xsession *)xfmem_zalloc(session_table->cache);
  sess->hash = hash;

  sess->src_ip  = src_ip; sess->src_port = src_port;
  sess->dst_ip  = dst_ip; sess->dst_port = dst_port;
  sess->protocol = xp->protocol;
  sess->dir = XSESSION_FROM_SRC;    
  sess->bound = bound;
  sess->new = 1;
  sess->ctime = xp->ts;

  sess->next = session_table->table[hkey];
  session_table->table[hkey] = sess;
  session_table->count++;

  xsession_set_timer(xp, sess);

  /* $$$$ New Session log $$$$ */
  xalert_put_blackhole (sess->src_ip, sess->dst_ip, sess->src_port, sess->dst_port, sess->protocol,
                 "%s-%s %s src=%s : %u, dst=%s : %u  pkts=%ld, bytes=%ld, pps=%d, bps=%d", asctime(localtime(&sess->ctime.tv_sec)), asctime(localtime(&sess->htime.tv_sec)),
                  xnet_protocol_str(sess->protocol), intoa(sess->src_ip), sess->src_port, intoa(sess->dst_ip), sess->dst_port, sess->total_pkts, sess->total_bytes, sess->pps, sess->bps * 8);
  
find :
  PPS_BPS(sess);
  sess->htime = xp->ts;
  if (xp->protocol == XNET_TCP_PROTOCOL)  xsession_check_fin(xp, sess);
  return sess;
}

xsession **xsession_get_table_array (int *cnt)
{
  xsession **xst = NULL, **ptr, *sess;
  int i = 0;

  *cnt = 0;
  if (session_table->count) {
    *cnt = session_table->count;
    xst = xmalloc(sizeof(xsession *) * session_table->count);
    ptr = xst;
  
    if ((sess = (xsession *)spt_first(session_table->timer))) do {
      *ptr++ = sess;
      i++;
    } while ((sess = (xsession *)spt_next((spt_t *)sess)));
  }
  return xst;
}



xsession *xsession_search (xpacket *xp)
{
  xsession *sess;

  if ((sess = _xsession_find(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_DIRECT)))
    return sess;

  if ((sess = _xsession_find(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_INBOUND))) 
    return sess;

  sess = _xsession_find(xp, xp->src_ip, xp->src_port, xp->dst_ip, xp->dst_port, xp->protocol, XNET_OUTBOUND);
  return sess;
}

void xsession_dump (void)
{
  xsession *sess;

  if (session_table->count) {
    if ((sess = (xsession *)spt_first(session_table->timer))) do {
      if (sess->protocol == XNET_TCP_PROTOCOL)  {
       printf("TCP sip = %s, sport = %u, dip = %s,  dport = %u\n", intoa(sess->src_ip), sess->src_port, intoa(sess->dst_ip), sess->dst_port);
     } else
     if (sess->protocol == XNET_UDP_PROTOCOL)  {
       printf("UDP sip = %s, sport = %u, dip = %s,  dport = %u\n", intoa(sess->src_ip), sess->src_port, intoa(sess->dst_ip), sess->dst_port);
     } else
     if (sess->protocol == XNET_ICMP_PROTOCOL)  {
       printf("ICMP sip = %s, sport = %u, dip = %s,  dport = %u\n", intoa(sess->src_ip), sess->src_port, intoa(sess->dst_ip), sess->dst_port);
     }
    } while ((sess = (xsession *)spt_next((spt_t *)sess)));
  }
}
