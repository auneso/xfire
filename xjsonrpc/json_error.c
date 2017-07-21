#include <stdio.h>
#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"

const char *get_json_error_string(int code)
{
  switch(code) {
    case JSON_PARSER_ERROR__NOT_WELL_FORMED                    :  return JSON_PARSER_ERR_MSG_NOT_WELL_FORMED;
    case JSON_PARSER_ERROR__UNSUPPORTED_ENCODING               :  return JSON_PARSER_ERR_MSG_UNSUPPORTED_ENCODING;
    case JSON_PARSER_ERROR__INVALID_CHARACTER_FOR_ENCODING     :  return JSON_PARSER_ERR_MSG_INVALID_CHARACTER_FOR_ENCODING;

    case JSON_SERVER_ERROR__INVALID_REQUEST                    :  return JSON_SERVER_ERR_MSG_INVALID_REQUEST;
    case JSON_SERVER_ERROR__REQUEST_METHOD_NOT_FOUND           :  return JSON_SERVER_ERR_MSG_REQUEST_METHOD_NOT_FOUND;
    case JSON_SERVER_ERROR__INVALID_METHOD_PARAMETERS          :  return JSON_SERVER_ERR_MSG_INVALID_METHOD_PARAMETERS;
    case JSON_SERVER_ERROR__INTERNAL_XML_RPC_ERROR             :  return JSON_SERVER_ERR_MSG_INVALID_INTERNAL_XML_RPC_ERROR;

    case JSON_REQ_ERROR_INVALID_ID                             :  return JSON_REQUEST_ERR_MSG_INVALID_ID;
    case JSON_REQ_ERROR_INVALID_PARAMS                         :  return JSON_REQUEST_ERR_MSG_INVALID_PARAMS;
    case JSON_REQ_ERROR_INVALID_PORT_FORMAT                    :  return JSON_REQUEST_ERR_MSG_INVALID_PORT_FORMAT;
    case JSON_REQ_ERROR_INVALID_IP_FORMAT                      :  return JSON_REQUEST_ERR_MSG_INVALID_IP_FORMAT;

    case JSON_REQ_ERROR_INVALID_USER_ID_DUP                    :  return JSON_REQUEST_ERR_MSG_USER_ID_DUP;
    case JSON_REQ_ERROR_INVALID_ADMIN_LEVEL_DUP                :  return JSON_REQUEST_ERR_MSG_ADMIN_LEVEL_DUP;
    case JSON_REQ_ERROR_INVALID_AUTH_LEVEL_ERROR               :  return JSON_REQUEST_ERR_MSG_AUTH_LEVEL_ERROR;

    case JSON_DB_ERROR_DATA_IS_NOT                             :  return JSON_DB_ERR_MSG_DATA_IS_NOT;
    case JSON_DB_ERROR_CURSOR_IS_NOT                           :  return JSON_DB_ERR_MSG_CURSOR_IS_NOT;
    case JSON_DB_ERROR_START_CURSOR_IS_NOT_EQUAL               :  return JSON_DB_ERR_MSG_START_CURSOR_IS_NOT_EQUAL;

    case JSON_LIB_ERROR_BRIDGE_GET                             :  return JSON_LIB_ERR_MSG_BRIDGE_GET;
    case JSON_LIB_ERROR_SYSTEM_STATUS_GET                      :  return JSON_LIB_ERR_MSG_SYSTEM_STATUS_GET;
    case JSON_LIB_ERROR_PORTMAP_INSERT                         :  return JSON_LIB_ERR_MSG_PORTMAP_INSERT;
    case JSON_LIB_ERROR_IPTREE_INSERT                          :  return JSON_LIB_ERR_MSG_IPTREE_INSERT;
    case JSON_LIB_ERROR_BPM_COMPILE                            :  return JSON_LIB_ERR_MSG_BPM_COMPILE;
    case JSON_LIB_ERROR_BPM_PARAMS_LENGTH                      :  return JSON_LIB_ERR_MSG_BPM_PARAMS_LENGTH;
    case JSON_LIB_ERROR_BASE64_DECODE                          :  return JSON_LIB_ERR_MSG_BASE64_DECODE;
  }
  return "Unknown";
}

void set_json_error(struct json_object *error, int code)
{
  json_object_object_add(error, "code", json_object_new_int(code));
  json_object_object_add(error, "message", json_object_new_string((char *)get_json_error_string(code)));
}
