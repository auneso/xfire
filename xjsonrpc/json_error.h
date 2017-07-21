#ifndef __JSON_ERROR_H__
#define __JSON_ERROR_H__


/* error code */
#define JSON_PARSER_ERROR__NOT_WELL_FORMED                          -32700
#define JSON_PARSER_ERROR__UNSUPPORTED_ENCODING                     -32701
#define JSON_PARSER_ERROR__INVALID_CHARACTER_FOR_ENCODING           -32702

#define JSON_SERVER_ERROR__INVALID_REQUEST                          -32600
#define JSON_SERVER_ERROR__REQUEST_METHOD_NOT_FOUND                 -32601
#define JSON_SERVER_ERROR__INVALID_METHOD_PARAMETERS                -32602
#define JSON_SERVER_ERROR__INTERNAL_XML_RPC_ERROR                   -32603

//-32099 ~ -32000 Server Error

#define JSON_REQ_ERROR_INVALID_ID                                   -50001
#define JSON_REQ_ERROR_INVALID_PARAMS                               -50002
#define JSON_REQ_ERROR_INVALID_PORT_FORMAT                          -50003
#define JSON_REQ_ERROR_INVALID_IP_FORMAT                            -50004

#define JSON_REQ_ERROR_INVALID_USER_ID_DUP                          -50101
#define JSON_REQ_ERROR_INVALID_ADMIN_LEVEL_DUP                      -50102
#define JSON_REQ_ERROR_INVALID_AUTH_LEVEL_ERROR                     -50103

#define JSON_DB_ERROR_DATA_IS_NOT                                   -60001
#define JSON_DB_ERROR_CURSOR_IS_NOT                                 -60002
#define JSON_DB_ERROR_START_CURSOR_IS_NOT_EQUAL                     -60003

#define JSON_LIB_ERROR_BRIDGE_GET                                   -70001
#define JSON_LIB_ERROR_SYSTEM_STATUS_GET                            -70002
#define JSON_LIB_ERROR_PORTMAP_INSERT                               -70003
#define JSON_LIB_ERROR_IPTREE_INSERT                                -70004
#define JSON_LIB_ERROR_BPM_COMPILE                                  -70005
#define JSON_LIB_ERROR_BPM_PARAMS_LENGTH                            -70006
#define JSON_LIB_ERROR_BASE64_DECODE                                -70007






/* error message */
#define JSON_PARSER_ERR_MSG_NOT_WELL_FORMED                         "Json Parser Error. Not Well Formed"
#define JSON_PARSER_ERR_MSG_UNSUPPORTED_ENCODING                    "Json Parser Error. Unsupported Encoding"
#define JSON_PARSER_ERR_MSG_INVALID_CHARACTER_FOR_ENCODING          "Json Parser Error. Invalid Character For Encoding"

#define JSON_SERVER_ERR_MSG_INVALID_REQUEST                         "Json Server Error. Invalid Request"
#define JSON_SERVER_ERR_MSG_REQUEST_METHOD_NOT_FOUND                "Json Server Error. Request Method Not Found"
#define JSON_SERVER_ERR_MSG_INVALID_METHOD_PARAMETERS               "Json Server Error. Invalid Method Parameters"
#define JSON_SERVER_ERR_MSG_INVALID_INTERNAL_XML_RPC_ERROR          "Json Server Error. Invalid Internal XML-RPC Error"

#define JSON_REQUEST_ERR_MSG_INVALID_ID                             "Json Request Error. Invalid ID."
#define JSON_REQUEST_ERR_MSG_INVALID_PARAMS                         "Json Request Error. Invalid Params."
#define JSON_REQUEST_ERR_MSG_INVALID_PORT_FORMAT                    "Json Request Error. Invalid Port Format."
#define JSON_REQUEST_ERR_MSG_INVALID_IP_FORMAT                      "Json Request Error. Invalid IP Format."

#define JSON_REQUEST_ERR_MSG_USER_ID_DUP                            "Json Request Error. User ID Duplication."
#define JSON_REQUEST_ERR_MSG_ADMIN_LEVEL_DUP                        "Json Request Error. ADMIN Level Duplication(ADMIN Level is only one)."
#define JSON_REQUEST_ERR_MSG_AUTH_LEVEL_ERROR                       "Json Request Error. Invalid Auth Level."

#define JSON_DB_ERR_MSG_DATA_IS_NOT                                 "Json DB Error. Data is Not"
#define JSON_DB_ERR_MSG_CURSOR_IS_NOT                               "Json DB Error. Cursor is Not"
#define JSON_DB_ERR_MSG_START_CURSOR_IS_NOT_EQUAL                   "Json DB Error. Start Cursor is Not Equal"

#define JSON_LIB_ERR_MSG_BRIDGE_GET                                 "Json LIB ERROR. Bridge Structure Not Get"
#define JSON_LIB_ERR_MSG_SYSTEM_STATUS_GET                          "Json LIB ERROR. System Status Information Not Get"
#define JSON_LIB_ERR_MSG_PORTMAP_INSERT                             "Json LIB ERROR. Portmap Insert Error"
#define JSON_LIB_ERR_MSG_IPTREE_INSERT                              "Json LIB ERROR. IPTree Insert Error"
#define JSON_LIB_ERR_MSG_BPM_COMPILE                                "Json LIB ERROR. BPM Compile Error"
#define JSON_LIB_ERR_MSG_BPM_PARAMS_LENGTH                          "Json LIB ERROR. BPM Parameters Length Error"
#define JSON_LIB_ERR_MSG_BASE64_DECODE                              "Json LIB ERROR. Base64 Decode Error"


const char *get_json_error_string(int code);
void set_json_error(struct json_object *error, int code);

#endif

