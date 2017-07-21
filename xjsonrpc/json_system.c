/*
*/
#include <stdio.h>
#include <math.h>

#include "format.h"
#include "xstring.h"
#include "tdate.h"
#include "xtimeval.h"
#include "xpacket.h"
#include "xnet.h"
#include "xsys.h"
#include "xfire.h"

#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"
#include "json_define.h"
#include "json_system.h"


void Proc_System_Info (struct json_object *request, struct json_object *response, void *info)
{
  struct json_object *req_id;
  struct json_object *error = json_object_new_object();
  int id;
  char ipv4[IPV4_STR_SIZE];

  if (!(req_id = json_object_object_get(request, "id"))) {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    json_object_object_add(response, "error", error);
    return;
  }
  id = json_object_get_int(req_id);
  if (id) json_object_object_add(response, "id", json_object_new_int(id));

  struct json_object *result = json_object_new_object();

  json_object_object_add(result, "version", json_object_new_string(get_xfire_version()));
  json_object_object_add(result, "ip",      json_object_new_string(intoab(xnet_my_ip(), ipv4)));
  json_object_object_add(result, "gateway", json_object_new_string(intoab(xnet_my_gateway(), ipv4)));
  json_object_object_add(result, "cpu",     json_object_new_int(xsys_get_cpu_num()));
  json_object_object_add(result, "memory",  json_object_new_int64(xsys_mem_size()));
  
  json_object_object_add(response, "result", result);
  json_object_put(error);
}

