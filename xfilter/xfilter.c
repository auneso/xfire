/*
** 2009/01/22 - HDS  add 
** 2009/01/30 - HDS  xfilter_search, xfilter_match, xfilter_match_fee
** 2009/02/03 - HDS  parameter NULL check
** 2009/02/04 - HDS  llist -> xvector
** 2009/05/19 - HDS  xfiletr_insert, flags check  XTABLE_ACTIVE, UPDATE, DELETE 
** 2009/05/22 - HDS  xfilter_enable, xfilter_disable
** 2009/07/25 - HDS  xfilter_check
** 2017/03/07 - HDS  src,dst, priority
** 2017/03/30 - HDS  wide ip, port ("*'), protocol (TUI) == A
*/

 #include <string.h>
#include "xfilter.h"
#include "xalloc.h"
#include "format.h"
#include "xvector.h"
#include "xnet.h"


Xfilter *xfilter_create (int table_size)
{
  Xfilter *xf;

  xf = xzalloc(sizeof(Xfilter));
  xf->smap = xipmap_create();
  xf->dmap = xipmap_create();

  xf->table  = xrbt32_create(sizeof(Xftable), table_size);
  xf->active = XFILTER_ENABLE;

  return xf;
}

static void xportmap_free (Xfilter *xf)
{
  Xftable *xt;

 if ((xt = ( Xftable *)xrbt32_first(xf->table))) do {
    if (xt->sport) xportmap_destroy(xt->sport);
    if (xt->dport) xportmap_destroy(xt->dport);
  } while ((xt = (Xftable *)xrbt32_next((XRBTN32 *)xt)));
}

void xfilter_destroy (Xfilter *xf)
{
  if (xf) {
    xipmap_destroy(xf->smap);
    xipmap_destroy(xf->dmap);
    xportmap_free(xf);
    xrbt32_destroy(xf->table);
    xfree(xf);
  }
}

void  xfstrcpy (Xftable *xt, char *protocol, char *src_ip, char *src_port, char *dst_ip, char *dst_port) 
{
  xt->protocol = xt->buff;
  strcpy(xt->protocol, protocol); 

  xt->src_ip = xt->protocol + strlen(protocol) + 1;
  strcpy(xt->src_ip, src_ip); 

  xt->src_port = xt->src_ip + strlen(src_ip) + 1;
  strcpy(xt->src_port, src_port); 

  xt->dst_ip = xt->src_port + strlen(src_port) + 1;
  strcpy(xt->dst_ip, dst_ip); 

  xt->dst_port = xt->dst_ip + strlen(dst_ip) + 1;
  strcpy(xt->dst_port, dst_port); 
}

static void cvt_protocol (Xftable *xt)
{
  char *ptr = xt->protocol;

  xt->xprotocol = 0; 
  while (*ptr) {
    switch (*ptr) {
      case XFILTER_TCP_PROTOCOL  : xt->xprotocol |= XNET_TCP_PROTOCOL;  break;
      case XFILTER_UDP_PROTOCOL  : xt->xprotocol |= XNET_UDP_PROTOCOL;  break;
      case XFILTER_ICMP_PROTOCOL : xt->xprotocol |= XNET_ICMP_PROTOCOL; break;
      case XFILTER_ALL_PROTOCOL  : xt->xprotocol = XNET_SESS_PROTOCOL;  break;
      default : return;
    }
    ptr++; 
  }
}

char *xfilter_protocol_str (ub8 protocol)
{
  switch (protocol) {
    case XNET_TCP_PROTOCOL  :  return "tcp";
    case XNET_UDP_PROTOCOL  :  return "udp";
    case XNET_ICMP_PROTOCOL :  return "icmp";
    case XNET_SESS_PROTOCOL :  return "*";
    default : return "error";
  }
}

void xfilter_add (Xfilter *xf, int filter_id, char *protocol, char *src_ip, char *src_port, char *dst_ip, char *dst_port, char priority,
                  char policy, char active, time_t start_time, time_t end_time)
{
  if (!src_ip || !src_port || !dst_ip || !dst_port) return;

  Xftable *xt;

  xt = (Xftable *)xrbt32_insert(xf->table, filter_id, NULL);

  xt->filter_id   = filter_id;
  xt->policy      = policy;
  xt->active      = active;
  xt->priority    = priority;
  xt->stime       = start_time;
  xt->etime       = end_time;

  xfstrcpy(xt, protocol, src_ip, src_port, dst_ip, dst_port); 
}

void xfilter_del (Xfilter *xf, int filter_id)
{
  xrbt32_delete(xf->table, filter_id);
}

void xfilter_set_priority (Xfilter *xf, int filter_id, int priority)
{
  Xftable *xt;

  if ((xt = (Xftable *)xrbt32_search(xf->table, filter_id))) {
    xt->priority = priority;
  }
}

void xfilter_enable (Xfilter *xf, int filter_id)
{
  Xftable *xt;

  if ((xt = (Xftable *)xrbt32_search(xf->table, filter_id))) 
    xt->active = XFILTER_ENABLE;
}

void xfilter_disable (Xfilter *xf, int filter_id)
{
  Xftable *xt;

  if ((xt = (Xftable *)xrbt32_search(xf->table, filter_id))) 
    xt->active = XFILTER_DISABLE;
}

void  xfilter_apply (Xfilter *xf)
{
  Xftable *xt;

  if (xrbt32_count(xf->table) == 0) return;

  if (xf->smap) xipmap_destroy(xf->smap);
  xf->smap = xipmap_create();

  if (xf->dmap) xipmap_destroy(xf->dmap);
  xf->dmap = xipmap_create();
  
  if ((xt = (Xftable *)xrbt32_first(xf->table))) do {
    if (xt->active == XFILTER_DISABLE) continue;

    cvt_protocol(xt);

    xipmap_insert_cmd(xf->smap, xt->src_ip, xt);
    if (xt->sport) xportmap_destroy(xt->sport);
    xt->sport = xportmap_create();
    xportmap_insert_cmd_one (xt->sport, xt->src_port);

    xipmap_insert_cmd(xf->dmap, xt->dst_ip, xt);
    if (xt->dport) xportmap_destroy(xt->dport);
    xt->dport = xportmap_create();
    xportmap_insert_cmd_one (xt->dport, xt->dst_port);
    
  } while ((xt = (Xftable *)xrbt32_next((XRBTN32 *)xt)));    
}

void  xfilter_enable_table (Xfilter *xf)
{ xf->active = XFILTER_ENABLE; }

void  xfilter_disable_table (Xfilter *xf)
{ xf->active = XFILTER_DISABLE;; }

static void set_match (Xfilter *xf,  Xftable *xt)
{
  int i;

  if (xf->match.mcnt < XFILTER_MAX_MATCH_SIZE) {
    for (i = 0; i < xf->match.mcnt; i++) {
      if (xf->match.table[i] == xt)  return; 
    }
    xf->match.table[i] = xt;
    xf->match.match[i] = 0;
    xf->match.mcnt++;
  }
}
static void update_match (Xfilter *xf,  Xftable *xt)
{
  int i;

  for (i = 0; i < xf->match.mcnt; i++) {
    if (xf->match.table[i] == xt) {
      xf->match.match[i] = 1;
      break;
    }
  }
}

static int priority_sort (const void *a, const void *b)
{
  Xftable **ac = (Xftable **)a;
  Xftable **bc = (Xftable **)b;
  return (*ac)->priority - (*bc)->priority;
}

static void check_match (Xfilter *xf, time_t ct, char protocol)
{
  int i, j;
  Xfmatch *xm = &xf->match;
  Xftable *xt;

  for (i = 0, j = 0; i < xm->mcnt; i++) {
    xt =xm->table[i]; 

    if (xm->match[i] == 1 && xt->active == XFILTER_ENABLE && (xt->xprotocol & protocol)
    && (xt->stime == 0 || ct >= xt->stime) && (xt->etime == 0 || ct <= xt->etime)) {
      xm->table[j] = xt; j++;
    } 
  }
  xm->mcnt = j;

  if (xm->mcnt > 1) qsort((Xftable **)xm->table, xm->mcnt, sizeof(Xftable *), priority_sort);
}

Xfmatch *xfilter_lookup (Xfilter *xf, char protocol, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, time_t ct)
{
  if (xf->active == XFILTER_DISABLE || xrbt32_count(xf->table) == 0) return NULL;

  Xftable  *st, *dt;
  xvector *sv, *dv; 

  xf->match.mcnt = 0; 

  /* src ----*/
  if ((sv = xipmap_lookup(xf->smap, src_ip))) {
    if ((st = (Xftable *)xvector_first(sv))) do {
      if (xportmap_search(st->sport, src_port))  {
        set_match(xf, st);
      }
    } while ((st = (Xftable *)xvector_next(sv)));
  }

  /* dst ----*/
  if ((dv = xipmap_lookup(xf->dmap, dst_ip))) { 
    if ((dt = (Xftable *)xvector_first(dv))) do {
      if (xportmap_search(dt->dport, dst_port)) {
        update_match(xf, dt);
      }
    } while ((dt = (Xftable *)xvector_next(dv)));
  }

  if (xf->match.mcnt) check_match(xf, ct, protocol);
  if (xf->match.mcnt) return &xf->match;
  return NULL;
}

Xftable *xfilter_find (Xfilter *xf, char protocol, ub32 src_ip, ub16 src_port, ub32 dst_ip, ub16 dst_port, time_t ct)
{
  Xfmatch *xm;

  if ((xm  = xfilter_lookup(xf, protocol, src_ip,src_port, dst_ip, dst_port, ct)))
    return xm->table[0];
  return NULL;
}

Xftable *xfilter_match_id (Xfmatch *xm, int id)
{
  int i;
  for (i = 0; i < xm->mcnt; i++) {
    if (xm->table[i]->filter_id == id) return xm->table[i];
  } 
  return NULL;
}

Xftable *xfilter_get_table_info (Xfilter *xf, int filter_id)
{
  return (Xftable *)xrbt32_search(xf->table, filter_id);
}

/* must call xfree after used */
Xftable **xfilter_get_table_array (Xfilter *xf, int *cnt)
{
   Xftable **xtt, **xtp, *xt;
  int count;

  *cnt = 0;
  if ((count = xrbt32_count(xf->table)) == 0) return NULL;
  
  xtt = xtp = (Xftable **)xmalloc(sizeof(Xftable *) * count);
  
  if ((xt = (Xftable *)xrbt32_first(xf->table))) do {
    *xtp++ = xt;
  } while ((xt = (Xftable *)xrbt32_next((XRBTN32 *)xt)));

  *cnt = count;
  return xtt;
}

