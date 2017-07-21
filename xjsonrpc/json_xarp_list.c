/*
*/
#include <stdio.h>

#include "format.h"
#include "xstring.h"

#include "xfire.h"
#include "xarp.h"
#include "xproto.h"
#include "xvendor.h"

#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"
#include "json_define.h"
#include "json_xarp_list.h"

typedef struct _request_para {
  int id;
  ub32 arp_ip;
  ub8  arp_mac[8];
  
  char ipv4[IPV4_STR_SIZE];
  char mac[MAC_STR_SIZE];
} request_para;


static void make_record (XARP *xp, struct json_object *xarp_info, request_para *para)
{
  json_object_object_add(xarp_info, "ip",   json_object_new_string(intoab(xp->ip, para->ipv4)));
  json_object_object_add(xarp_info, "mac",  json_object_new_string(etheraddr_stringb(xp->mac, para->mac)));
  json_object_object_add(xarp_info, "oui",  json_object_new_string(get_oui_info(xp->mac)));
  json_object_object_add(xarp_info, "dev",  json_object_new_string(xp->xdev->xdev));
}

static int Rsp_View_XARP_List (struct json_object *result_array,struct json_object *error, request_para *para)
{
  int xarp_list_cnt, i;
  XARP **xarp_list;

  xfire_read_lock();

  xarp_list = xarp_get_table_array(&xarp_list_cnt);
  if (xarp_list) {
    for (i = 0; i < xarp_list_cnt; i++) {
      struct json_object *xarp_info = json_object_new_object();
      make_record (xarp_list[i], xarp_info, para);
      json_object_array_add(result_array, xarp_info);
    }
    xfree(xarp_list);
  }

  xfire_read_unlock();
  return xarp_list_cnt;
}


static int Req_View_XARP_List (struct json_object *request, struct json_object *error, request_para *para)
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


void Proc_View_XARP_List (struct json_object *request, struct json_object *response, void *info)
{
  int nRet_cnt=0;
  struct json_object *error = json_object_new_object();
  struct json_object *result_array = json_object_new_array();
  struct json_object *result = json_object_new_object();
  request_para para;

  if (Req_View_XARP_List(request,error, &para)) {
    nRet_cnt = Rsp_View_XARP_List(result_array, error, &para);
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

static void Rsp_XARP_Proc (struct json_object *request, struct json_object *error, request_para *para, int action)
{
  struct json_object *req_id;
  struct json_object *req_params;

  struct json_object *req_arp_ip;
  struct json_object *req_arp_mac;
 
  memset(para, 0, sizeof(request_para));
  req_id = json_object_object_get(request, "id");
  req_params = json_object_object_get(request, "params");
 
  if (req_id != NULL) {
    para->id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    return;
  }

  if (req_params != NULL) {
    if (!(req_arp_ip = json_object_object_get(req_params, "arp_ip"))) goto error_req;
      para->arp_ip = atoin((char *)json_object_get_string(req_arp_ip));

    switch (action) {

      case JSON_XARP_INSERT:
        if (!(req_arp_mac = json_object_object_get(req_params, "arp_mac"))) goto error_req;
        memcpy(para->arp_mac, string_etheraddr((ub8 *)json_object_get_string(req_arp_mac)), ETHER_ADDR_LEN);
        xarp_add_arp(para->arp_ip, para->arp_mac);
        break;

      case JSON_XARP_REMOVE:
        xarp_del_arp(para->arp_ip);
        break;

      case JSON_XARP_UPDATE:
        if (!(req_arp_mac = json_object_object_get(req_params, "arp_mac"))) goto error_req;
        memcpy(para->arp_mac, string_etheraddr((ub8 *)json_object_get_string(req_arp_mac)), ETHER_ADDR_LEN);
        xarp_update_arp(para->arp_ip, para->arp_mac);
        break;
    }
  } else {
error_req:
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
  }
}


void Proc_XARP_Insert (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  Rsp_XARP_Proc(request, error, &para, JSON_XARP_INSERT);

  if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}

void Proc_XARP_Remove (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  Rsp_XARP_Proc(request, error, &para, JSON_XARP_REMOVE);

  if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}

void Proc_XARP_Update (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  Rsp_XARP_Proc(request, error, &para, JSON_XARP_UPDATE);

 if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}
