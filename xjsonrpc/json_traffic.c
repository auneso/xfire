/*
*/
#include <stdio.h>
#include <string.h>
#include <math.h>


#include "xsys.h"
#include "xpacket.h"
#include "xfire.h"

#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"
#include "json_define.h"
#include "json_traffic.h"

typedef struct _request_para {
  int id;
  Xiptree *server_map;  
} request_para;

static int Rsp_View_Traffic (struct json_object *result, struct json_object *error,  request_para *para)
{
  float cpu_used = 0;
  float mem_used = 0;

  xsys_get_cpu_use(&cpu_used);
  xsys_get_mem_use(&mem_used);

  if (isnan(cpu_used) || isinf(cpu_used)) cpu_used = 0;
  if (isnan(mem_used) || isinf(mem_used)) mem_used = 0;

  xpkt_cnt rx, tx;
  xpacket_get_rx_count(&rx);
  xpacket_get_tx_count(&tx);

  json_object_object_add(result, "total_pkts",      json_object_new_int64(rx.pkts + tx.pkts));
  json_object_object_add(result, "total_bytes",     json_object_new_int64(rx.bytes + tx.bytes));
  json_object_object_add(result, "pps",             json_object_new_int64(rx.pps + tx.pps));
  json_object_object_add(result, "max_pps",         json_object_new_int64(rx.max_pps + tx.max_pps));
  json_object_object_add(result, "bps",             json_object_new_int64(rx.bps + tx.bps));
  json_object_object_add(result, "max_bps",         json_object_new_int64(rx.max_bps + tx.max_bps));

  json_object_object_add(result, "pkts_ipv4",       json_object_new_int64(rx.ipv4_pps + tx.ipv4_pps));
  json_object_object_add(result, "pkts_tcp_p",      json_object_new_int64(rx.tcp_pps + tx.tcp_pps));
  json_object_object_add(result, "pkts_udp_p",      json_object_new_int64(rx.udp_pps + tx.udp_pps));
  json_object_object_add(result, "pkts_icmp_p",     json_object_new_int64(rx.icmp_pps + tx.icmp_pps));
  json_object_object_add(result, "pkts_arp_p",      json_object_new_int64(rx.arp_pps + tx.arp_pps));
  json_object_object_add(result, "pkts_other_p",    json_object_new_int64(rx.other_pps + tx.other_pps));

  json_object_object_add(result, "bytes_ipv4_b",    json_object_new_int64(rx.ipv4_bps + tx.ipv4_bps));
  json_object_object_add(result, "bytes_tcp_b",     json_object_new_int64(rx.tcp_bps + tx.tcp_bps));
  json_object_object_add(result, "bytes_udp_b",     json_object_new_int64(rx.udp_bps + tx.udp_bps));
  json_object_object_add(result, "bytes_icmp_b",    json_object_new_int64(rx.icmp_bps + tx.icmp_bps));
  json_object_object_add(result, "bytes_arp_b",     json_object_new_int64(rx.arp_bps + tx.arp_bps));
  json_object_object_add(result, "bytes_other_b",   json_object_new_int64(rx.other_bps + tx.other_bps));

  json_object_object_add(result, "bytes_p_77",      json_object_new_int64(rx.p_77 + tx.p_77));
  json_object_object_add(result, "bytes_p_110",     json_object_new_int64(rx.p_110 + tx.p_110));
  json_object_object_add(result, "bytes_p_250",     json_object_new_int64(rx.p_250 + tx.p_250));
  json_object_object_add(result, "bytes_p_500",     json_object_new_int64(rx.p_500 + tx.p_500));
  json_object_object_add(result, "bytes_p_1000",    json_object_new_int64(rx.p_1000 + tx.p_1000));
  json_object_object_add(result, "bytes_p_large",   json_object_new_int64(rx.p_large + tx.p_large));
  json_object_object_add(result, "bytes_p_jumbo",   json_object_new_int64(rx.p_jumbo + tx.p_jumbo));


  json_object_object_add(result, "cpu_used", json_object_new_int(cpu_used));
  json_object_object_add(result, "mem_used", json_object_new_int(mem_used));


  return JSON_SUCCESS;
}


 
static int Req_View_Traffic (struct json_object *request, struct json_object *error,  request_para *para)
{
  struct json_object *req_id;
  struct json_object *req_params;
  struct json_object *req_server_ip;

  memset(para, 0, sizeof(request_para)); 

  req_id = json_object_object_get(request, "id");
  if (req_id != NULL) {
    para->id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    return JSON_FAIL;
  }
  req_params = json_object_object_get(request, "params");
  if (req_params != NULL) {
    char *pp;
    if ((req_server_ip = json_object_object_get(req_params, "server_ip"))) {
      pp = (char *)json_object_get_string(req_server_ip);
      if (pp && *pp) {
        para->server_map = xiptree_create();
        xiptree_insert_cmd(para->server_map, pp, NULL);
      }
    }
  }

  return JSON_SUCCESS;
}

void Proc_View_Traffic (struct json_object *request, struct json_object *response, void *info)
{
  int nRet;
  request_para para;

  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();

  nRet = Req_View_Traffic(request, error, &para);
  if (nRet) {
    nRet = Rsp_View_Traffic(result, error, &para);
  }

  if (para.id)
    json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", result);
    json_object_put(error);
  }
  if (para.server_map) xiptree_destroy(para.server_map);
}

