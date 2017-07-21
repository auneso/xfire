/*
*/
#include <stdio.h>
#include <string.h>

#include "format.h"
#include "xfire.h"
#include "xpacket.h"
#include "xlb.h"
#include "xwall.h"

#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"
#include "json_define.h"

#include "json_slb_config.h"

typedef struct _request_para {
  ub32 id;

  ub32 vidx, ridx;
  ub32 new_vidx;

  ub32 rip;
  ub16 rport; 

  ub32 gateway;
  ub32 vip;
  ub16 vport; 
  char *vdev; 
  
  ub16 protocol;
  ub16 service;
  ub16 server_type;

  char *alias;
  char *snat;

  ub32 weight;
  ub32 balance;

  ub32  view_type;
} request_para;

void json_make_slb_vitual_server_info (struct json_object *server_info, slb_virtual_server *vs, int type)
{
  char ipv4[IPV4_STR_SIZE];

  json_object_object_add(server_info, "xlb_server_type", json_object_new_int(type));
  json_object_object_add(server_info, "virtual_server_alias", json_object_new_string(vs->alias));
  json_object_object_add(server_info, "virtual_server_dev", json_object_new_string(vs->xdev->xdev));
  json_object_object_add(server_info, "virtual_server_ip", json_object_new_string(intoab(vs->vip, ipv4)));
  json_object_object_add(server_info, "virtual_server_port", json_object_new_int(vs->vport));
  json_object_object_add(server_info, "virtual_server_service", json_object_new_string(slb_get_service_str(vs->service)));
  json_object_object_add(server_info, "virtual_server_protocol", json_object_new_string(slb_get_protocol_str(vs->protocol)));
  json_object_object_add(server_info, "virtual_server_balance", json_object_new_int(vs->balance));
  json_object_object_add(server_info, "virtual_server_gateway", json_object_new_string(intoab(vs->gw_ip, ipv4)));
}

void json_make_slb_real_server_info (struct json_object *server_info, slb_real_server *rs)
{
  char ipv4[IPV4_STR_SIZE];

  json_object_object_add(server_info, "real_server_alias", json_object_new_string(rs->alias));
  json_object_object_add(server_info, "real_server_ip", json_object_new_string(intoab(rs->rip, ipv4)));
  json_object_object_add(server_info, "real_server_port", json_object_new_int(rs->rport));
  json_object_object_add(server_info, "real_server_weight", json_object_new_int(rs->weight));
  json_object_object_add(server_info, "real_server_down", json_object_new_int(rs->service_down));
  json_object_object_add(server_info, "real_service_down", json_object_new_int(rs->service_down));
}

static void Rsp_SLB_Proc (struct json_object *request, struct json_object *error, request_para *para, int action)
{
  struct json_object *req_id;
  struct json_object *req_params;

  struct json_object *req_server_type;
  struct json_object *req_gateway;
  struct json_object *req_server_dev;
  struct json_object *req_server_ip;
  struct json_object *req_server_port;
  struct json_object *req_server_protocol;
  struct json_object *req_server_service;
  struct json_object *req_server_idx;

  struct json_object *req_alias;
  
  struct json_object *req_balance;
  struct json_object *req_weight;
  xbridge *xb = xpacket_get_xbridge();
  
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

    if (!(req_server_type = json_object_object_get(req_params, "xlb_server_type"))) goto error_req;
      para->server_type = json_object_get_int(req_server_type);

    switch (para->server_type) {

      case JSON_SLB_VIRTUAL_SERVER :
      case JSON_SLB_REDIRECT_SERVER :
        switch (action) {
          case JSON_SLB_INSERT:
          case JSON_SLB_UPDATE:
            if (xb->xlb_mode == XLB_NAT_MODE || para->server_type == JSON_SLB_REDIRECT_SERVER) {
              if (!(req_server_dev = json_object_object_get(req_params, "virtual_server_dev"))) goto error_req;
              para->vdev = (char *)json_object_get_string(req_server_dev);
              if (xpacket_get_xdevice(para->vdev) == NULL) goto error_req;
            }
            if (xb->xlb_mode == XLB_NAT_MODE) {
              if (!(req_gateway = json_object_object_get(req_params, "virtual_server_gateway"))) goto error_req;
              para->gateway = atoin((char *)json_object_get_string(req_gateway));
            }

            if (!(req_alias = json_object_object_get(req_params, "virtual_server_alias"))) goto error_req;
            para->alias = (char *)json_object_get_string(req_alias);

            if (!(req_server_ip = json_object_object_get(req_params, "virtual_server_ip"))) goto error_req;
            para->vip = atoin((char *)json_object_get_string(req_server_ip));

            if (!(req_server_port = json_object_object_get(req_params, "virtual_server_port"))) goto error_req;
            para->vport = json_object_get_int(req_server_port);

            if (!(req_server_protocol = json_object_object_get(req_params, "virtual_server_protocol"))) goto error_req;
            para->protocol = slb_get_protocol_id((char *)json_object_get_string(req_server_protocol));

            if (!(req_server_service = json_object_object_get(req_params, "virtual_server_service"))) goto error_req;
            para->service = slb_get_service_id((char *)json_object_get_string(req_server_service));

            if (!(req_balance = json_object_object_get(req_params, "virtual_server_balance"))) goto error_req;
            para->balance = json_object_get_int(req_balance);

            if (action == JSON_SLB_INSERT) {
              if (para->server_type == JSON_SLB_VIRTUAL_SERVER) {
                slb_virtual_server_insert(para->vdev, para->vip, para->vport, para->protocol, para->service, para->balance, para->alias, para->gateway);
              } else { 
                slb_redirect_server_insert(para->vdev, para->vip, para->vport, para->protocol, para->service, para->balance, para->alias);
              }
            } else  {
              if (!(req_server_idx = json_object_object_get(req_params, "virtual_server_idx"))) goto error_req;
              para->vidx = json_object_get_int(req_server_idx);

              if (para->server_type == JSON_SLB_VIRTUAL_SERVER) {
                slb_virtual_server_update(para->vdev, para->vip, para->vport, para->protocol, para->service, para->balance, para->alias,
                                          para->gateway, para->vidx);
              } else {
                slb_redirect_server_update(para->vdev, para->vip, para->vport,  para->protocol, para->service, para->balance, para->alias, para->vidx);
              }
            }
            break;

          case JSON_SLB_REMOVE:
            if (!(req_server_idx = json_object_object_get(req_params, "virtual_server_idx"))) goto error_req;
            para->vidx = json_object_get_int(req_server_idx);

            if (para->server_type == JSON_SLB_VIRTUAL_SERVER)
              slb_virtual_server_remove(para->vidx);
            else 
              slb_redirect_server_remove(para->vidx);
            break;
        }
        break;

      case JSON_SLB_VIRTUAL_REAL_SERVER :
      case JSON_SLB_REDIRECT_REAL_SERVER :

        switch (action) {
          case JSON_SLB_INSERT:

            if (!(req_server_idx = json_object_object_get(req_params, "virtual_server_idx"))) goto error_req;
            para->vidx = json_object_get_int(req_server_idx);

            if (!(req_alias = json_object_object_get(req_params, "real_server_alias"))) goto error_req;
            para->alias = (char *)json_object_get_string(req_alias);

            if (!(req_server_ip = json_object_object_get(req_params, "real_server_ip"))) goto error_req;
            para->rip = atoin((char *)json_object_get_string(req_server_ip));
   
            if (!(req_server_port = json_object_object_get(req_params, "real_server_port"))) goto error_req;
            para->rport = json_object_get_int(req_server_port);

            if (!(req_weight = json_object_object_get(req_params, "weight"))) goto error_req;
            para->weight = json_object_get_int(req_weight);

            if (para->server_type == JSON_SLB_VIRTUAL_REAL_SERVER)
              slb_virtual_real_server_insert(para->rip, para->rport, para->weight, para->alias, para->vidx);
            else
              slb_redirect_real_server_insert(para->rip, para->rport, para->weight, para->alias, para->vidx);
            break;

          case JSON_SLB_UPDATE:

            if (!(req_alias = json_object_object_get(req_params, "real_server_alias"))) goto error_req;
            para->alias = (char *)json_object_get_string(req_alias);

            if (!(req_server_ip = json_object_object_get(req_params, "real_server_ip"))) goto error_req;
            para->rip = atoin((char *)json_object_get_string(req_server_ip));
  
            if (!(req_server_port = json_object_object_get(req_params, "real_server_port"))) goto error_req;
            para->rport = json_object_get_int(req_server_port);
          
            if (!(req_weight = json_object_object_get(req_params, "weight"))) goto error_req;
            para->weight = json_object_get_int(req_weight);

            if (!(req_server_idx = json_object_object_get(req_params, "virtual_server_idx"))) goto error_req;
            para->vidx = json_object_get_int(req_server_idx);

            if (!(req_server_idx = json_object_object_get(req_params, "virtual_server_new_idx"))) goto error_req;
            para->new_vidx = json_object_get_int(req_server_idx);


            if (!(req_server_idx = json_object_object_get(req_params, "real_server_idx"))) goto error_req;
            para->ridx = json_object_get_int(req_server_idx);

            if (para->server_type == JSON_SLB_VIRTUAL_REAL_SERVER)
              slb_virtual_real_server_update(para->rip, para->rport, para->weight, para->alias, para->vidx, para->new_vidx, para->ridx);
            else
              slb_redirect_real_server_update(para->rip, para->rport, para->weight, para->alias, para->vidx, para->new_vidx, para->ridx);
            break;

          case JSON_SLB_REMOVE:
            if (!(req_server_idx = json_object_object_get(req_params, "real_server_idx"))) goto error_req;
            para->ridx = json_object_get_int(req_server_idx);

            if (para->server_type == JSON_SLB_VIRTUAL_REAL_SERVER)
              slb_virtual_real_server_remove(para->ridx);
            else
              slb_redirect_real_server_remove(para->ridx);
            break;
        }
        break;

      default :
        goto error_req;
    }
  } else {
error_req:
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
  }
}


void Proc_SLB_Config_Insert (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  Rsp_SLB_Proc(request, error, &para, JSON_SLB_INSERT);

 if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}

void Proc_SLB_Config_Remove (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  Rsp_SLB_Proc(request, error, &para, JSON_SLB_REMOVE);

  if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}

void Proc_SLB_Config_Update (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  request_para para;

  Rsp_SLB_Proc(request, error, &para, JSON_SLB_UPDATE);

 if (para.id) json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}


static int slb_virtual_server_view (xbridge *xb, struct json_object *result_array)
{
  struct json_object *server_info;
  slb_virtual_server *vs;
  xlb_t *xlb = xb->xlb;
  int count = 0;

  xlb_lock(); 
  if ((vs = (slb_virtual_server *)xrbt64_first(&xlb->vs_table))) do {
    server_info = json_object_new_object();
    count++; vs->idx = count;
    json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_VIRTUAL_SERVER);
    json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));
    
    json_object_array_add(result_array, server_info);
  } while ((vs = (slb_virtual_server *)xrbt64_next((XRBTN64 *)vs)));
  xlb_unlock();
 
  return count;
}

static int slb_redirect_server_view (xbridge *xb, struct json_object *result_array)
{
  struct json_object *server_info;
  slb_virtual_server *vs;
  xlb_t *xlb = xb->xlb;
  int count = 0;

  xlb_lock(); 
  if ((vs = (slb_virtual_server *)xrbt64_first(&xlb->rs_table))) do {
    server_info = json_object_new_object();
    count++; vs->idx = count;
    json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_REDIRECT_SERVER);
    json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));

    json_object_array_add(result_array, server_info);
  } while ((vs = (slb_virtual_server *)xrbt64_next((XRBTN64 *)vs)));
  xlb_unlock();

  return count;
}

static int slb_virtual_real_server_view (xbridge *xb, struct json_object *result_array)
{
  struct json_object *server_info;
  slb_virtual_server *vs;
  slb_real_server *rs;
  int count = 0;
  XRBTR64 *vs_table = slb_get_vitual_table();

   
  xlb_lock(); 
  if ((vs = (slb_virtual_server *)xrbt64_first(vs_table))) do {
    count++; vs->idx = count;
    if ((rs = (slb_real_server *)xrbt64_first(&vs->rs_table))) do {
      server_info = json_object_new_object();
      json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_VIRTUAL_REAL_SERVER);
      json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));

      count++; rs->idx = count;
      json_make_slb_real_server_info(server_info, rs);
      json_object_object_add(server_info, "real_server_idx", json_object_new_int(rs->idx));

      json_object_array_add(result_array, server_info);
    } while ((rs = (slb_real_server *)xrbt64_next((XRBTN64 *)rs)));
  } while ((vs = (slb_virtual_server *)xrbt64_next((XRBTN64 *)vs)));
  xlb_unlock();
  return count;
}

static int slb_redirect_real_server_view (xbridge *xb, struct json_object *result_array)
{
  struct json_object *server_info;
  slb_virtual_server *vs;
  slb_real_server *rs;
  int count = 0;
  XRBTR64 *rs_table = slb_get_redirect_table();

  
  xlb_lock();
  if ((vs = (slb_virtual_server *)xrbt64_first(rs_table))) do {
    count++; vs->idx = count;
    if ((rs = (slb_real_server *)xrbt64_first(&vs->rs_table))) do {
      server_info = json_object_new_object();
      json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_REDIRECT_REAL_SERVER);
      json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));

      count++; rs->idx = count;
      json_make_slb_real_server_info(server_info, rs);
      json_object_object_add(server_info, "real_server_idx", json_object_new_int(rs->idx));

      json_object_array_add(result_array, server_info);
    } while ((rs = (slb_real_server *)xrbt64_next((XRBTN64 *)rs)));
  } while ((vs = (slb_virtual_server *)xrbt64_next((XRBTN64 *)vs)));
  xlb_unlock();
  return count;
}

static int slb_all_server_view (xbridge *xb, struct json_object *result_array)
{
  struct json_object *server_info;
  slb_virtual_server *vs;
  slb_real_server *rs;
  int count = 0;
  XRBTR64 *vs_table = slb_get_vitual_table();
  XRBTR64 *rs_table = slb_get_redirect_table();

  xlb_lock();

  if ((vs = (slb_virtual_server *)xrbt64_first(vs_table))) do {
    server_info = json_object_new_object();
    count++; vs->idx = count;
    json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_VIRTUAL_SERVER);
    json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));

    json_object_array_add(result_array, server_info);

    if ((rs = (slb_real_server *)xrbt64_first(&vs->rs_table))) do {
      server_info = json_object_new_object();
      count++; rs->idx = count;
      json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_VIRTUAL_REAL_SERVER);
      json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));
      
      json_make_slb_real_server_info (server_info, rs);
      json_object_object_add(server_info, "real_server_idx", json_object_new_int(rs->idx));

      json_object_array_add(result_array, server_info);
    } while ((rs = (slb_real_server *)xrbt64_next((XRBTN64 *)rs)));
  } while ((vs = (slb_virtual_server *)xrbt64_next((XRBTN64 *)vs)));

  if ((vs = (slb_virtual_server *)xrbt64_first(rs_table))) do {
    server_info = json_object_new_object();
    count++; vs->idx = count;
    json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_REDIRECT_SERVER);
    json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));

    json_object_array_add(result_array, server_info);

    if ((rs = (slb_real_server *)xrbt64_first(&vs->rs_table))) do {
      server_info = json_object_new_object();
      count++; rs->idx = count;
      json_make_slb_vitual_server_info (server_info, vs, JSON_SLB_REDIRECT_REAL_SERVER);
      json_object_object_add(server_info, "virtual_server_idx", json_object_new_int(vs->idx));
      json_make_slb_real_server_info (server_info, rs);
      json_object_object_add(server_info, "real_server_idx", json_object_new_int(rs->idx));

      json_object_array_add(result_array, server_info);
    } while ((rs = (slb_real_server *)xrbt64_next((XRBTN64 *)rs)));
  } while ((vs = (slb_virtual_server *)xrbt64_next((XRBTN64 *)vs)));

  xlb_unlock();

  return count;
}


static int Rsp_SLB_Server_View (struct json_object *result_array, struct json_object *error, request_para *para)
{
  xbridge *xb = xpacket_get_xbridge();

  switch (para->view_type) {
    case JSON_SLB_VIRTUAL_SERVER :
      return slb_virtual_server_view(xb, result_array);
    case JSON_SLB_VIRTUAL_REAL_SERVER :
      return slb_virtual_real_server_view(xb, result_array);
    case JSON_SLB_REDIRECT_SERVER :
      return slb_redirect_server_view(xb, result_array);
    case JSON_SLB_REDIRECT_REAL_SERVER :
      return slb_redirect_real_server_view(xb, result_array);
    case JSON_SLB_ALL_SERVER :
      return slb_all_server_view(xb, result_array);
  }
  set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
  return 0;
}

void Proc_SLB_Config_Apply (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *req_id;
  struct json_object *error = json_object_new_object();
  struct json_object *result = json_object_new_object();
  int id = 0;
  
  req_id = json_object_object_get(request, "id");

  if (req_id != NULL) {
    id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
  }
  slb_apply_configure();

  if (id) json_object_object_add(response, "id", json_object_new_int(id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
  } else {
    json_object_object_add(response, "result", json_object_new_string("OK"));
    json_object_put(error);
  }
}

void Proc_SLB_Config_Upload (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *req_id;
  struct json_object *req_mode;
  struct json_object *req_config;
  struct json_object *req_params;
  struct json_object *result = json_object_new_object();
  struct json_object *error = json_object_new_object();
  int id = 0, mode;
  char *buf;

  if (!(req_id = json_object_object_get(request, "id"))) goto error_req;
  id = json_object_get_int(req_id);

  if (!(req_params = json_object_object_get(request, "params"))) goto error_req;

  if (!(req_mode = json_object_object_get(req_params, "mode"))) goto error_req;
  mode = json_object_get_int(req_mode);

  if (mode == JSON_SLB_CONFIG_VIEW) {
    if (!(buf = slb_config_view())) goto error_req;
    json_object_object_add(result, "config", json_object_new_string(buf));
    xfree(buf);
  } else if (mode == JSON_SLB_CONFIG_UPLOAD) {
    if (!(req_config = json_object_object_get(req_params, "config"))) goto error_req;
    buf = (char *)json_object_get_string(req_config);
    slb_config_upload(buf);
    json_object_object_add(result, "result", json_object_new_string("OK"));
  } else {
    goto error_req;
  }
  json_object_object_add(response, "id", json_object_new_int(id));

  if (0) {
error_req:
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
    json_object_object_add(response, "error", error);
    json_object_put(result);
    return;
  }
  json_object_object_add(response, "result", result);
  json_object_put(error);
}

static int Req_SLB_Server_View (struct json_object *request, struct json_object *error, request_para *para)
{
  struct json_object *req_id;
  struct json_object *req_params;
  struct json_object *req_view;

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
    if (!(req_view = json_object_object_get(req_params, "view_type"))) goto error_req;
      para->view_type = json_object_get_int(req_view);
  } else {
error_req:
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
    return JSON_FAIL;
  }

  return JSON_SUCCESS;
}

void Proc_SLB_Config_View (struct json_object *request, struct json_object *response, void *info)
{
  int nRet = 0;
  struct json_object *error = json_object_new_object();
  struct json_object *result_array = json_object_new_array();
  struct json_object *result = json_object_new_object();
  request_para para;

  if (Req_SLB_Server_View(request, error, &para)) {
    nRet = Rsp_SLB_Server_View(result_array, error, &para);
  }

  if (para.id)
    json_object_object_add(response, "id", json_object_new_int(para.id));

  if (json_object_object_get(error, "code")) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
    json_object_put(result_array);
  } else {
    json_object_object_add(result, "total_count", json_object_new_int(nRet));
    json_object_object_add(result, "list", result_array);
    json_object_object_add(response, "result", result);
    json_object_put(error);
  }
}


