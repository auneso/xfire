/*
*/
#include <string.h>

#include "format.h"
#include "xtimeval.h"
#include "xpacket.h"
#include "xblack.h"

#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"
#include "json_define.h"
#include "json_black_list.h"

typedef struct _request_para {
  int id;
  int count;
  int sort_order;
  int sort_condition;
  char *ip;
  char ipv4[IPV4_STR_SIZE];
} request_para;


static void make_user_record (xblacklist *b, struct json_object *black_info, time_t ct)
{
  json_object_object_add(black_info, "ip", json_object_new_string(b->ipv4str));
  json_object_object_add(black_info, "drop_cnt", json_object_new_int(b->drop_cnt));
  json_object_object_add(black_info, "create_time", json_object_new_string(convert_date(b->ctime)));
  if (b->etime)
    json_object_object_add(black_info, "end_time", json_object_new_string(convert_date(b->etime)));
  else
    json_object_object_add(black_info, "end_time", json_object_new_string(" "));
}


static int Req_View_Black_List (struct json_object *request, struct json_object *error, request_para *para)
{
  struct json_object *req_id;
  struct json_object *req_params;
  struct json_object *req_count;
  struct json_object *req_sort_order;
  struct json_object *req_sort_condition;

  memset(para, 0, sizeof(request_para));

  req_id = json_object_object_get(request, "id");
  req_params = json_object_object_get(request, "params");

  if (req_id != NULL) {
    para->id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    return JSON_FAIL;
  }

  if (req_params != NULL) {
    if ((req_sort_order = json_object_object_get(req_params, "sort_order")))
      para->sort_order = json_object_get_int(req_sort_order);

    if ((req_sort_condition = json_object_object_get(req_params, "sort_condition")))
      para->sort_condition = json_object_get_int(req_sort_condition);

    if ((req_count = json_object_object_get(req_params, "count")))
      para->count = json_object_get_int(req_count);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
    return JSON_FAIL;
  }

  return JSON_SUCCESS;
}

static int Rsp_View_Black_List (struct json_object *result_array,struct json_object *error, request_para *para)
{
  int black_cnt, i, count;
  xblacklist **black;
  time_t ct = time(NULL);

  xblack_lock();

  black = xblack_get_array(&black_cnt);
  if (black) {
//    qsort_black_user(black, black_cnt, para);
    if (para->count && para->count < black_cnt) count = para->count;
    else                                        count = black_cnt;
    for (i = 0; i < count; i++) {
      struct json_object *black_info = json_object_new_object();
      make_user_record(black[i], black_info, ct);
      json_object_array_add(result_array, black_info);
    }
    xfree(black);
  }

  xblack_unlock();
  return black_cnt;
}

void Proc_View_Black_List (struct json_object *request, struct json_object *response, void *info)
{
  int nRet, nRet_cnt=0;
  struct json_object *error = json_object_new_object();
  struct json_object *result_array = json_object_new_array();
  struct json_object *result = json_object_new_object();
  request_para para;

  nRet = Req_View_Black_List(request, error, &para);
  if (nRet) {
    nRet_cnt = Rsp_View_Black_List(result_array, error, &para);
  }

  if (para.id)
    json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
    json_object_put(result_array);
  }
  else {
    json_object_object_add(result, "total_count", json_object_new_int(nRet_cnt));
    json_object_object_add(result, "list", result_array);
    json_object_object_add(response, "result", result);
    json_object_put(error);
  }
}


static int Req_Black_List (struct json_object *request, struct json_object *error, request_para *para)
{
  struct json_object *req_id;
  struct json_object *req_params;
  struct json_object *req_ip;

  memset(para, 0, sizeof(request_para));

  req_id = json_object_object_get(request, "id");
  req_params = json_object_object_get(request, "params");

  if (req_id != NULL) {
    para->id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    return JSON_FAIL;
  }

  if (req_params != NULL) {
    if ((req_ip = json_object_object_get(req_params, "ip")))
      para->ip = (char *)json_object_get_string(req_ip);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
    return JSON_FAIL;
  }

  return JSON_SUCCESS;
}

void Proc_Add_Black_List (struct json_object *request, struct json_object *response, void *info)
{
  int nRet;
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  nRet = Req_Black_List(request, error, &para);
  if (nRet) {
    xblack_lock();
    xblack_add(para.ip, time(NULL), 0 , 0);
    xblack_apply();
    xblack_unlock();
  }

  if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}

void Proc_Del_Black_List (struct json_object *request, struct json_object *response, void *info)
{
  int nRet;
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  nRet = Req_Black_List(request, error, &para);
  if (nRet) {
    xblack_lock();
    xblack_del(para.ip);
    xblack_apply();
    xblack_unlock();
  }

  if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}

