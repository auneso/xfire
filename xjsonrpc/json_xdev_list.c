/*
*/
#include <stdio.h>

#include "format.h"
#include "xstring.h"

#include "xarp.h"
#include "xpacket.h"
#include "xbridge.h"
#include "xvendor.h"

#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"
#include "json_define.h"
#include "json_xdev_list.h"

typedef struct _request_para {
  int id;
  char *dev;
  ub64 bps;
  ub64 pps;

  char mac[MAC_STR_SIZE];
} request_para;


static void make_record (xdevice *xd, struct json_object *xdev_info, request_para *para)
{
  xpkt_cnt xc;
  struct xbridge_eth_stats stats, tstats;
  

  xpacket_dev_stats(xd, &stats);
  xpacket_stats(&tstats);
  xpacket_get_rx_count_dev(xd, &xc);

  json_object_object_add(xdev_info, "dev",          json_object_new_string(xd->xdev));
  json_object_object_add(xdev_info, "alias",        json_object_new_string(xd->alias));
  json_object_object_add(xdev_info, "idx",          json_object_new_int(xd->portid));
  json_object_object_add(xdev_info, "mac",          json_object_new_string(etheraddr_stringb(xd->xmac, para->mac)));
  json_object_object_add(xdev_info, "oui",          json_object_new_string(get_oui_info(xd->xmac)));
  json_object_object_add(xdev_info, "link_down",    json_object_new_int(xd->link));


  json_object_object_add(xdev_info, "dev_pkts",     json_object_new_int64(stats.ipackets + stats.opackets));
  json_object_object_add(xdev_info, "dev_drop",     json_object_new_int64(stats.imissed + stats.ierrors + stats.oerrors));

  json_object_object_add(xdev_info, "total_pkts",   json_object_new_int64(tstats.ipackets + tstats.opackets));
  json_object_object_add(xdev_info, "total_bytes",  json_object_new_int64(tstats.ibytes + tstats.obytes));

  json_object_object_add(xdev_info, "drop_pkts",    json_object_new_int64(xc.drop_p));
  json_object_object_add(xdev_info, "drop_bytes",   json_object_new_int64(xc.drop_b));

  json_object_object_add(xdev_info, "error_pkts",   json_object_new_int64(xc.error_p));
  json_object_object_add(xdev_info, "error_bytes",  json_object_new_int64(xc.error_b));

  json_object_object_add(xdev_info, "pps",          json_object_new_int64(xc.pps));
  json_object_object_add(xdev_info, "max_pps",      json_object_new_int64(xc.max_pps));
  json_object_object_add(xdev_info, "bps",          json_object_new_int64(xc.bps));
  json_object_object_add(xdev_info, "max_bps",      json_object_new_int64(xc.max_bps));

  json_object_object_add(xdev_info, "ipv4_pps",     json_object_new_int64(xc.ipv4_pps));
  json_object_object_add(xdev_info, "tcp_pps",      json_object_new_int64(xc.tcp_pps));
  json_object_object_add(xdev_info, "udp_pps",      json_object_new_int64(xc.udp_pps));
  json_object_object_add(xdev_info, "icmp_pps",     json_object_new_int64(xc.icmp_pps));
  json_object_object_add(xdev_info, "arp_pps",      json_object_new_int64(xc.arp_pps));
  json_object_object_add(xdev_info, "other_pps",    json_object_new_int64(xc.other_pps));

  json_object_object_add(xdev_info, "ipv4_bps",     json_object_new_int64(xc.ipv4_bps));
  json_object_object_add(xdev_info, "tcp_bps",      json_object_new_int64(xc.tcp_bps));
  json_object_object_add(xdev_info, "udp_bps",      json_object_new_int64(xc.udp_bps));
  json_object_object_add(xdev_info, "icmp_bps",     json_object_new_int64(xc.icmp_bps));
  json_object_object_add(xdev_info, "arp_bps",      json_object_new_int64(xc.arp_bps));
  json_object_object_add(xdev_info, "other_bps",    json_object_new_int64(xc.other_bps));
}

static int Rsp_View_Xdev_List (struct json_object *result_array,struct json_object *error, request_para *para)
{
  int xdev_list_cnt, i;
  xdevice **xdev_list;

  xfire_read_lock();

  xdev_list = xpacket_xdev_table_array(&xdev_list_cnt);
 
  if (xdev_list) {
    for (i = 0; i < xdev_list_cnt; i++) {
      struct json_object *xdev_info = json_object_new_object();
      make_record(xdev_list[i], xdev_info, para);
      json_object_array_add(result_array, xdev_info);
    }
    xfree(xdev_list);
  }
  xfire_read_unlock();

  return xdev_list_cnt;
}


static int Req_View_Xdev_List (struct json_object *request, struct json_object *error, request_para *para)
{
  struct json_object *req_id;

  memset(para, 0, sizeof(request_para));

  req_id = json_object_object_get(request, "id");

  if (req_id != NULL) {
    para->id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    return JSON_FAIL;
  }

  return JSON_SUCCESS;
}


void Proc_View_Xdev_List (struct json_object *request, struct json_object *response, void *info)
{
  int nRet, nRet_cnt=0;
  struct json_object *error = json_object_new_object();
  struct json_object *result_array = json_object_new_array();
  struct json_object *result = json_object_new_object();
  request_para para;

  nRet = Req_View_Xdev_List(request,error, &para);
  if (nRet) {
    nRet_cnt = Rsp_View_Xdev_List(result_array, error, &para);
  }

  if (para.id)
    json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
    json_object_put(result_array);
  } else {
    json_object_object_add(result, "total_count", json_object_new_int(nRet_cnt));
    json_object_object_add(result, "list", result_array);
    json_object_object_add(response, "result", result);
    json_object_put(error);
  }
}

