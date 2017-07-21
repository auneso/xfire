#if 0

#include <stdio.h>

#include "format.h"

#include "bpm.h"
#include "hspc.h"
#include "xvector.h"
#include "xtimeval.h"

#include "xiptree.h"
#include "xportmap.h"
#include "xtable.h"
#include "xsession.h"

#include "xnw.h"
#include "xalert_log.h"

#include "json.h"
#include "jsonrpc.h"
#include "json_error.h"
#include "json_define.h"
#include "json_alert_data.h"

/* XNW Attack Log Search */
#define ALERT_LOG_SEARCH_TYPE_ALL        0x01
#define ALERT_LOG_SEARCH_TYPE_INCLUDE    0x02
#define ALERT_LOG_SEARCH_TYPE_EXCLUDE    0x04

typedef struct _request_para {
  int    id;

  Xiptree *client_iptree;
  Xiptree *server_iptree;
  xportmap *logtype_portmap;
  xportmap *country_portmap;
  bpm_t *bpm;

  char   cTimeType;
  ub32   nStartTime;
  ub32   nEndTime;
  
  char   cLogType;
  char   *sLogMsgType;
  
  char   cCountryType;
  char   *sCountryList;
  
  char   cCIPListType;
  char   *sCIPList;
  
  char   cSIPListType;
  char   *sSIPList;
  
  char   cStringType;
  char   *sSting;
  
  int    nStart;
  int    nCount;

  char  ipv4[IPV4_STR_SIZE];
} request_para;

static void search_lib_create (request_para *para)
{
  para->client_iptree   = xiptree_create();
  para->server_iptree   = xiptree_create();
  para->logtype_portmap = xportmap_create();
  para->country_portmap = xportmap_create();
  para->bpm = bpm_create();
}

static void search_lib_destroy (request_para *para)
{
  xportmap_destroy(para->logtype_portmap);
  xportmap_destroy(para->country_portmap);
  xiptree_destroy(para->client_iptree);
  xiptree_destroy(para->server_iptree);
  bpm_destroy(para->bpm);
}

static int search_lib_insert (struct json_object *error,  request_para *para)
{
  /* ipmap insert */
  if (para->cCIPListType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (!xiptree_insert_cmd(para->client_iptree, para->sCIPList, NULL)) {
      if (error != NULL) set_json_error(error, JSON_LIB_ERROR_IPTREE_INSERT);
      return JSON_FAIL;
    }
  }
  if (para->cSIPListType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (!xiptree_insert_cmd(para->server_iptree, para->sSIPList, NULL)) {
      if (error != NULL) set_json_error(error, JSON_LIB_ERROR_IPTREE_INSERT);
      return JSON_FAIL;
    }
  }

  /* portmap insert and compile */
  if (para->cLogType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (xportmap_insert_cmd(para->logtype_portmap, para->sLogMsgType)) {
      xportmap_compile(para->logtype_portmap);
    } else {
      if (error != NULL) set_json_error(error, JSON_LIB_ERROR_PORTMAP_INSERT);
      return JSON_FAIL;
    }
  }
  if (para->cCountryType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (xportmap_insert_cmd(para->country_portmap, para->sCountryList)) {
      xportmap_compile(para->country_portmap);
    } else {
      if (error != NULL) set_json_error(error, JSON_LIB_ERROR_PORTMAP_INSERT);
      return JSON_FAIL;
    }
  }

  /* bpm pattern add and compile */
  if (para->cStringType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (bpm_add_pattern(para->bpm, (unsigned char*)para->sSting, strlen(para->sSting), 1, 1, 0,  NULL, NULL)
    ||  bpm_compile(para->bpm)) {
      if (error != NULL) set_json_error(error, JSON_LIB_ERROR_BPM_COMPILE);
      return JSON_FAIL;
    }
  }

  return JSON_SUCCESS;
}

static int search_lib_check (struct AlertLogInfo *info, request_para *para)
{
  if (para->cTimeType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (para->cTimeType == ALERT_LOG_SEARCH_TYPE_INCLUDE) {
      if (info->nStartSec < para->nStartTime || info->nStartSec >= para->nEndTime) {
        return JSON_FAIL;
      }
    } else {
      if (info->nStartSec >= para->nStartTime && info->nStartSec < para->nEndTime) {
        return JSON_FAIL;
      }
    }
  }

  if (para->cLogType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (para->cLogType == ALERT_LOG_SEARCH_TYPE_INCLUDE) {
      if (!xportmap_search(para->logtype_portmap, info->usLogType)) {
        return JSON_FAIL;
      }
    } else {
      if (xportmap_search(para->logtype_portmap, info->usLogType)) {
        return JSON_FAIL;
      }
    }
  }

  if (para->cCountryType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (para->cCountryType == ALERT_LOG_SEARCH_TYPE_INCLUDE) {
      if (!xportmap_search(para->country_portmap, info->usClientCountry)) {
        return JSON_FAIL;
      }
    } else {
      if (xportmap_search(para->country_portmap, info->usClientCountry)) {
        return JSON_FAIL;
      }
    }
  }

  if (para->cCIPListType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (para->cCIPListType == ALERT_LOG_SEARCH_TYPE_INCLUDE) {
      if (!xiptree_search (para->client_iptree, info->ipClient)) {
        return JSON_FAIL;
      }
    } else {
      if (xiptree_search (para->client_iptree, info->ipClient)) {
        return JSON_FAIL;
      }
    }
  }

  if (para->cSIPListType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (para->cSIPListType == ALERT_LOG_SEARCH_TYPE_INCLUDE) {
      if (!xiptree_search (para->server_iptree, info->ipServer)) {
        return JSON_FAIL;
      }
    } else {
      if (xiptree_search (para->server_iptree, info->ipServer)) {
        return JSON_FAIL;
      }
    }
  }

  if (para->cStringType != ALERT_LOG_SEARCH_TYPE_ALL) {
    if (para->cStringType == ALERT_LOG_SEARCH_TYPE_INCLUDE) {
      if (!bpm_find(para->bpm, (unsigned char*)info->sMsg, strlen(info->sMsg))) {
        return JSON_FAIL;
      }
    } else {
      if (bpm_find(para->bpm, (unsigned char*)info->sMsg, strlen(info->sMsg))) {
        return JSON_FAIL;
      }
    }
  }
  return JSON_SUCCESS;
}



static int Attack_List_Search_Count (request_para *para)
{
  XCUR *cursor;
  struct AlertLogInfo  *info;
  int nRecordLegth, count=0;

  search_lib_create(para);
  if (!search_lib_insert(NULL, para)) {
    search_lib_destroy(para);
    return JSON_FAIL;
  }

  cursor = xdb_cur_new(alert_db_get());
  xdb_cur_last(cursor);

  do {
    if ((info = (struct AlertLogInfo *)xdb_cur_val(cursor, &nRecordLegth))) {
      if (search_lib_check(info, para)) count++;
      xfree(info);
    } else break;
  } while (xdb_cur_prev(cursor));
  xdb_cur_free(cursor);
  search_lib_destroy(para);
  return count;
}


static int Search_Alert_Cursor_Next (XCUR *cursor, request_para *para)
{
  int nRecordLegth=0, nAttackCnt=0;
  struct AlertLogInfo *info;

  do {
    if ((info = (struct AlertLogInfo*)xdb_cur_val(cursor, &nRecordLegth))) {
      if (search_lib_check(info, para)) nAttackCnt++;
      xfree(info);
      if (para->nStart+1 == nAttackCnt) break;
    } else break;
  } while (xdb_cur_prev(cursor));
  return nAttackCnt;
}

static int Alert_Cursor_Next (XCUR *cursor, int nCount)
{
  int i, cnt;

  for (i = 0, cnt= 0; i < nCount; i++) {
    if (!xdb_cur_prev(cursor)) break;
    cnt++;
  }
  return cnt;
}

static void make_record (struct json_object *alert_info, struct AlertLogInfo *info, request_para *para)
{
  Black_Info *bi = &info->Info;

  json_object_object_add(alert_info, "index", json_object_new_int(0xffffffff - ntohl(info->nKey) + 1));
  json_object_object_add(alert_info, "start_time", json_object_new_string(convert_date(info->nStartSec)));
  json_object_object_add(alert_info, "code", json_object_new_int(info->usLogType));
  json_object_object_add(alert_info, "country", json_object_new_string((char *)geoip_country_code_by_ip(info->ipClient)));
  json_object_object_add(alert_info, "attacker", json_object_new_string(intoab(info->ipClient, para->ipv4)));
  json_object_object_add(alert_info, "victim", json_object_new_string(intoab(info->ipServer, para->ipv4)));
  json_object_object_add(alert_info, "victim_domain", json_object_new_string(info->Info.domain));
  json_object_object_add(alert_info, "message_type", json_object_new_string((char *)get_alert_log_string(info->usLogType)));
  json_object_object_add(alert_info, "end_time", json_object_new_string(convert_date(info->nEndSec)));
  json_object_object_add(alert_info, "attack_cnt", json_object_new_int(info->nAttackCount));
  json_object_object_add(alert_info, "attack_time", json_object_new_string(fmt_second(info->nEndSec - info->nStartSec)));
  json_object_object_add(alert_info, "reject_cnt", json_object_new_int(info->nRejectCount));
  json_object_object_add(alert_info, "drop_cnt", json_object_new_int(info->nDropCount));
  json_object_object_add(alert_info, "message", json_object_new_string(info->sMsg));

  /* Server */
  json_object_object_add(alert_info, "srv_act_user_cnt", json_object_new_int(bi->srv_act_user_cnt));
  json_object_object_add(alert_info, "srv_act_user_max", json_object_new_int(bi->srv_act_user_max));
  json_object_object_add(alert_info, "srv_act_sess_cnt", json_object_new_int(bi->srv_act_sess_cnt));
  json_object_object_add(alert_info, "srv_act_sess_max", json_object_new_int(bi->srv_act_sess_max));
  json_object_object_add(alert_info, "srv_act_tran_cnt", json_object_new_int(bi->srv_act_tran_cnt));
  json_object_object_add(alert_info, "srv_act_tran_max", json_object_new_int(bi->srv_act_tran_max));
  json_object_object_add(alert_info, "srv_act_uri_cnt", json_object_new_int(bi->srv_act_uri_cnt));
  json_object_object_add(alert_info, "srv_act_uri_max", json_object_new_int(bi->srv_act_uri_max));
  json_object_object_add(alert_info, "srv_wait_sess", json_object_new_int(bi->srv_wait_sess));
  json_object_object_add(alert_info, "srv_max_wait_sess", json_object_new_int(bi->srv_max_wait_sess));
  json_object_object_add(alert_info, "srv_req_head_cnt", json_object_new_int(bi->srv_req_head_cnt));
  json_object_object_add(alert_info, "srv_req_data_cnt", json_object_new_int(bi->srv_req_data_cnt));
  json_object_object_add(alert_info, "srv_tot_conn_cnt", json_object_new_int(bi->srv_tot_conn_cnt));
  json_object_object_add(alert_info, "srv_tot_tran_cnt", json_object_new_int(bi->srv_tot_tran_cnt));
  json_object_object_add(alert_info, "srv_tot_rsp_tran_cnt", json_object_new_int(bi->srv_tot_rsp_tran_cnt));
  json_object_object_add(alert_info, "srv_tot_error_cnt", json_object_new_int(bi->srv_tot_error_cnt));
    
  json_object_object_add(alert_info, "srv_conn_ups", json_object_new_int(bi->srv_conn_ups));
  json_object_object_add(alert_info, "srv_max_ups", json_object_new_int(bi->srv_max_ups));
  json_object_object_add(alert_info, "srv_conn_cps", json_object_new_int(bi->srv_conn_cps));
  json_object_object_add(alert_info, "srv_max_cps", json_object_new_int(bi->srv_max_cps));
  json_object_object_add(alert_info, "srv_tran_tps", json_object_new_int(bi->srv_tran_tps));
  json_object_object_add(alert_info, "srv_max_tps", json_object_new_int(bi->srv_max_tps));
  json_object_object_add(alert_info, "srv_uri_hps", json_object_new_int(bi->srv_uri_hps));
  json_object_object_add(alert_info, "srv_max_hps", json_object_new_int(bi->srv_max_hps));
  json_object_object_add(alert_info, "srv_avg_RTT", json_object_new_int(bi->srv_curt_RTT));
  json_object_object_add(alert_info, "srv_max_RTT", json_object_new_int(bi->srv_max_RTT));
  json_object_object_add(alert_info, "srv_blackhole", json_object_new_int(bi->srv_blackhole));


  /* User */
  json_object_object_add(alert_info, "usr_act_srv_cnt", json_object_new_int(bi->usr_act_srv_cnt));
  json_object_object_add(alert_info, "usr_act_srv_max", json_object_new_int(bi->usr_act_srv_max));
  json_object_object_add(alert_info, "usr_act_sess_cnt", json_object_new_int(bi->usr_act_sess_cnt));
  json_object_object_add(alert_info, "usr_act_sess_max", json_object_new_int(bi->usr_act_sess_max));
  json_object_object_add(alert_info, "usr_act_tran_cnt", json_object_new_int(bi->usr_act_tran_cnt));
  json_object_object_add(alert_info, "usr_act_tran_max", json_object_new_int(bi->usr_act_tran_max));
  json_object_object_add(alert_info, "usr_act_uri_cnt", json_object_new_int(bi->usr_act_uri_cnt));
  json_object_object_add(alert_info, "usr_act_uri_max", json_object_new_int(bi->usr_act_uri_max));
  json_object_object_add(alert_info, "usr_wait_sess", json_object_new_int(bi->usr_wait_sess));
  json_object_object_add(alert_info, "usr_max_wait_sess", json_object_new_int(bi->usr_max_wait_sess));
  json_object_object_add(alert_info, "usr_req_head_cnt", json_object_new_int(bi->usr_req_head_cnt));
  json_object_object_add(alert_info, "usr_req_data_cnt", json_object_new_int(bi->usr_req_data_cnt));
  json_object_object_add(alert_info, "usr_tot_conn_cnt", json_object_new_int(bi->usr_tot_conn_cnt));
  json_object_object_add(alert_info, "usr_tot_tran_cnt", json_object_new_int(bi->usr_tot_tran_cnt));
  json_object_object_add(alert_info, "usr_tot_rsp_tran_cnt", json_object_new_int(bi->usr_tot_rsp_tran_cnt));
  json_object_object_add(alert_info, "usr_tot_error_cnt", json_object_new_int(bi->usr_tot_error_cnt));
  json_object_object_add(alert_info, "usr_tot_srv_cnt", json_object_new_int(bi->usr_tot_srv_cnt));
  json_object_object_add(alert_info, "usr_tot_uri_cnt", json_object_new_int(bi->usr_tot_uri_cnt));

  json_object_object_add(alert_info, "usr_conn_sps", json_object_new_int(bi->usr_conn_sps));
  json_object_object_add(alert_info, "usr_max_sps", json_object_new_int(bi->usr_max_sps));
  json_object_object_add(alert_info, "usr_conn_cps", json_object_new_int(bi->usr_conn_cps));
  json_object_object_add(alert_info, "usr_max_cps", json_object_new_int(bi->usr_max_cps));
  json_object_object_add(alert_info, "usr_tran_tps", json_object_new_int(bi->usr_tran_tps));
  json_object_object_add(alert_info, "usr_max_tps", json_object_new_int(bi->usr_max_tps));
  json_object_object_add(alert_info, "usr_uri_hps", json_object_new_int(bi->usr_uri_hps));
  json_object_object_add(alert_info, "usr_max_hps", json_object_new_int(bi->usr_max_hps));
  json_object_object_add(alert_info, "usr_avg_RTT", json_object_new_int(bi->usr_curt_RTT));
  json_object_object_add(alert_info, "usr_max_RTT", json_object_new_int(bi->usr_max_RTT));
  json_object_object_add(alert_info, "usr_black_cnt", json_object_new_int(bi->usr_black_cnt));

  /* URL */
  json_object_object_add(alert_info, "url_act_user_cnt", json_object_new_int(bi->url_act_user_cnt));
  json_object_object_add(alert_info, "url_act_user_max", json_object_new_int(bi->url_act_user_max));
  json_object_object_add(alert_info, "url_act_sess_cnt", json_object_new_int(bi->url_act_sess_cnt));
  json_object_object_add(alert_info, "url_act_sess_max", json_object_new_int(bi->url_act_sess_max));
  json_object_object_add(alert_info, "url_wait_sess", json_object_new_int(bi->url_wait_sess));
  json_object_object_add(alert_info, "url_max_wait_sess", json_object_new_int(bi->url_max_wait_sess));
  json_object_object_add(alert_info, "url_tot_conn_cnt", json_object_new_int(bi->url_tot_conn_cnt));
  json_object_object_add(alert_info, "url_tot_tran_cnt", json_object_new_int(bi->url_tot_tran_cnt));

  json_object_object_add(alert_info, "url_conn_cps", json_object_new_int(bi->url_conn_cps));
  json_object_object_add(alert_info, "url_max_cps", json_object_new_int(bi->url_max_cps));
  json_object_object_add(alert_info, "url_tran_tps", json_object_new_int(bi->url_tran_tps));
  json_object_object_add(alert_info, "url_max_tps", json_object_new_int(bi->url_max_tps));
  json_object_object_add(alert_info, "url_conn_ups", json_object_new_int(bi->url_conn_ups));
  json_object_object_add(alert_info, "url_max_ups", json_object_new_int(bi->url_max_ups));
  json_object_object_add(alert_info, "url_risk", json_object_new_int(bi->url_risk));

  /* Country */
  json_object_object_add(alert_info, "country_name", json_object_new_string(geoip_country_code_by_ip(info->ipClient)));
  json_object_object_add(alert_info, "country_act_user_cnt", json_object_new_int(bi->country_act_user_cnt));
  json_object_object_add(alert_info, "country_act_user_max", json_object_new_int(bi->country_act_user_max));
  json_object_object_add(alert_info, "country_act_sess_cnt", json_object_new_int(bi->country_act_sess_cnt));
  json_object_object_add(alert_info, "country_act_sess_max", json_object_new_int(bi->country_act_sess_max));
  json_object_object_add(alert_info, "country_wait_sess", json_object_new_int(bi->country_wait_sess));
  json_object_object_add(alert_info, "country_max_wait_sess", json_object_new_int(bi->country_max_wait_sess));

  json_object_object_add(alert_info, "country_conn_ups", json_object_new_int(bi->country_conn_ups));
  json_object_object_add(alert_info, "country_max_ups", json_object_new_int(bi->country_max_ups));
  json_object_object_add(alert_info, "country_conn_cps", json_object_new_int(bi->country_conn_cps));
  json_object_object_add(alert_info, "country_max_cps", json_object_new_int(bi->country_max_cps));
  json_object_object_add(alert_info, "country_tran_tps", json_object_new_int(bi->country_tran_tps));
  json_object_object_add(alert_info, "country_max_tps", json_object_new_int(bi->country_max_tps));
  json_object_object_add(alert_info, "country_avg_RTT", json_object_new_int(bi->country_curt_RTT));
  json_object_object_add(alert_info, "country_max_RTT", json_object_new_int(bi->country_max_RTT));
  json_object_object_add(alert_info, "country_risk", json_object_new_int(bi->country_risk));

  /* City */
  json_object_object_add(alert_info, "location_id", json_object_new_int(bi->location));
  json_object_object_add(alert_info, "city_name", json_object_new_string(geoip_city_name_by_ip(info->ipClient))); 
  json_object_object_add(alert_info, "city_act_rtt", json_object_new_int(bi->city_act_rtt));
  json_object_object_add(alert_info, "city_tot_sess_cnt", json_object_new_int(bi->city_tot_sess_cnt));
  json_object_object_add(alert_info, "city_tot_tran_cnt", json_object_new_int(bi->city_tot_tran_cnt));
  json_object_object_add(alert_info, "city_act_user_cnt", json_object_new_int(bi->city_act_user_cnt));
  json_object_object_add(alert_info, "city_max_user_cnt", json_object_new_int(bi->city_max_user_cnt));
  json_object_object_add(alert_info, "city_act_sess_cnt", json_object_new_int(bi->city_act_sess_cnt));
  json_object_object_add(alert_info, "city_max_sess_cnt", json_object_new_int(bi->city_max_sess_cnt));
  json_object_object_add(alert_info, "city_act_tran_cnt", json_object_new_int(bi->city_act_tran_cnt));
  json_object_object_add(alert_info, "city_max_tran_cnt", json_object_new_int(bi->city_max_tran_cnt));
  json_object_object_add(alert_info, "city_wait_sess_cnt", json_object_new_int(bi->city_wait_sess_cnt));
  json_object_object_add(alert_info, "city_wait_max_sess_cnt", json_object_new_int(bi->city_wait_max_sess_cnt));
  json_object_object_add(alert_info, "city_risk", json_object_new_int(bi->city_risk));


  /* ISP */
  json_object_object_add(alert_info, "isp_id", json_object_new_int(bi->isp_id));
  json_object_object_add(alert_info, "isp_name", json_object_new_string(geoip_isp_name_by_ip(info->ipClient))); 
  json_object_object_add(alert_info, "isp_act_rtt", json_object_new_int(bi->isp_act_rtt));
  json_object_object_add(alert_info, "isp_tot_sess_cnt", json_object_new_int(bi->isp_tot_sess_cnt));
  json_object_object_add(alert_info, "isp_tot_tran_cnt", json_object_new_int(bi->isp_tot_tran_cnt));
  json_object_object_add(alert_info, "isp_act_user_cnt", json_object_new_int(bi->isp_act_user_cnt));
  json_object_object_add(alert_info, "isp_max_user_cnt", json_object_new_int(bi->isp_max_user_cnt));
  json_object_object_add(alert_info, "isp_act_sess_cnt", json_object_new_int(bi->isp_act_sess_cnt));
  json_object_object_add(alert_info, "isp_max_sess_cnt", json_object_new_int(bi->isp_max_sess_cnt));
  json_object_object_add(alert_info, "isp_act_tran_cnt", json_object_new_int(bi->isp_act_tran_cnt));
  json_object_object_add(alert_info, "isp_max_tran_cnt", json_object_new_int(bi->isp_max_tran_cnt));
  json_object_object_add(alert_info, "isp_wait_sess_cnt", json_object_new_int(bi->isp_wait_sess_cnt));
  json_object_object_add(alert_info, "isp_wait_max_sess_cnt", json_object_new_int(bi->isp_wait_max_sess_cnt));
  json_object_object_add(alert_info, "isp_risk", json_object_new_int(bi->isp_risk));
}

static int Rsp_View_Alert_List_Search (struct json_object *result_array, struct json_object *error, request_para *para)
{
  XCUR *cursor;
  struct AlertLogInfo  *info;
  int nRecordLegth, count=0;

  struct json_object *alert_info;

  search_lib_create(para);

  if (!search_lib_insert(error, para)) {
    search_lib_destroy(para);
    return JSON_FAIL;
  }
  cursor = xdb_cur_new(alert_db_get());
  xdb_cur_last(cursor);

  if (para->nStart > 1) {
    if (para->nStart + 1 != Search_Alert_Cursor_Next(cursor, para)) {
      set_json_error(error, JSON_DB_ERROR_START_CURSOR_IS_NOT_EQUAL);
      xdb_cur_free(cursor);
      search_lib_destroy(para);
      return JSON_FAIL;
    }
  }

  do {
    if ((info = (struct AlertLogInfo *)xdb_cur_val(cursor, &nRecordLegth))) {
      if (search_lib_check(info, para)) {
        alert_info = json_object_new_object();
        make_record (alert_info, info, para);
        json_object_array_add(result_array, alert_info);
        count++;
      }
    } else break;
    xfree(info);
    if (para->nCount == count) break;
  } while (xdb_cur_prev(cursor));

  xdb_cur_free(cursor);
  search_lib_destroy(para);
  return count;
}


static int Rsp_View_Alert_List (struct json_object *result_array, struct json_object *error, request_para *para)
{
  XCUR *cursor;
  struct AlertLogInfo   *info;
  int nRecordLegth, i, count;
  struct json_object *alert_info;

  cursor = xdb_cur_new(alert_db_get());
  xdb_cur_last(cursor);

  if (para->nStart) {
    if (para->nStart != Alert_Cursor_Next(cursor,para->nStart)) {
      set_json_error(error, JSON_DB_ERROR_START_CURSOR_IS_NOT_EQUAL);
      xdb_cur_free(cursor);
      return JSON_FAIL;
    }
  }

  for (i = para->nStart, count = 0; i < (para->nStart + para->nCount); i++) {
    if ((info = (struct AlertLogInfo *)xdb_cur_val(cursor, &nRecordLegth))) {
      alert_info = json_object_new_object();
      make_record(alert_info, info, para); 
      json_object_array_add(result_array, alert_info);
      count++;
      xfree(info);
    }
    if (!xdb_cur_prev(cursor)) break;
  }

  xdb_cur_free(cursor);
  return xdb_num(alert_db_get());
}

static int Req_View_Alert_List_Search (struct json_object *request, struct json_object *error, request_para *para)
{
  struct json_object *req_id;
  struct json_object *req_params;

  struct json_object *req_time_type;
  struct json_object *req_time_start;
  struct json_object *req_time_end;
  struct json_object *req_log_type;
  struct json_object *req_log_msg;
  struct json_object *req_country_type;
  struct json_object *req_country_code_list;
  struct json_object *req_client_ip_type;
  struct json_object *req_client_ip_list;
  struct json_object *req_server_ip_type;
  struct json_object *req_server_ip_list;
  struct json_object *req_string_type;
  struct json_object *req_string;
  struct json_object *req_start;
  struct json_object *req_count;

  req_id = json_object_object_get(request, "id");
  req_params = json_object_object_get(request, "params");

  if (req_id != NULL) {
    para->id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    return JSON_FAIL;
  }

  if (req_params != NULL) {
    req_time_type  = json_object_object_get(req_params, "time_type");
    req_log_type = json_object_object_get(req_params, "log_type");
    req_country_type = json_object_object_get(req_params, "country_type");
    req_client_ip_type = json_object_object_get(req_params, "client_ip_type");
    req_server_ip_type = json_object_object_get(req_params, "server_ip_type");
    req_string_type = json_object_object_get(req_params, "string_type");
    req_start = json_object_object_get(req_params, "start");
    req_count = json_object_object_get(req_params, "count");

    if (req_time_type != NULL) {
      para->cTimeType = json_object_get_int(req_time_type);

      if (para->cTimeType != ALERT_LOG_SEARCH_TYPE_ALL) {
        req_time_start = json_object_object_get(req_params, "time_start");
        req_time_end = json_object_object_get(req_params, "time_end");

        if ((req_time_start != NULL) && (req_time_end != NULL)) {
          para->nStartTime = json_object_get_int(req_time_start);
          para->nEndTime = json_object_get_int(req_time_end);
        } else {
          set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
          return JSON_FAIL;
        }
      }
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }

    if (req_log_type != NULL) {
      para->cLogType = json_object_get_int(req_log_type);

      if (para->cLogType != ALERT_LOG_SEARCH_TYPE_ALL) {
        req_log_msg = json_object_object_get(req_params, "log_msg");

        if (req_log_msg != NULL) {
          if (xportmap_valid_cmd(json_object_get_string(req_log_msg))) {
            para->sLogMsgType = (char *)json_object_get_string(req_log_msg);
          } else {
            set_json_error(error, JSON_REQ_ERROR_INVALID_PORT_FORMAT);
            return JSON_FAIL;
          }
        } else {
          set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
          return JSON_FAIL;
        }
      }
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }

    if (req_country_type != NULL) {
      para->cCountryType = json_object_get_int(req_country_type);

      if (para->cCountryType != ALERT_LOG_SEARCH_TYPE_ALL) {
        req_country_code_list = json_object_object_get(req_params, "country_code_list");

        if (req_country_code_list != NULL) {
          if (xportmap_valid_cmd(json_object_get_string(req_country_code_list))) {
            para->sCountryList = (char *)json_object_get_string(req_country_code_list);
          } else {
            set_json_error(error, JSON_REQ_ERROR_INVALID_PORT_FORMAT);
            return JSON_FAIL;
          }
        } else {
          set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
          return JSON_FAIL;
        }
      }
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }

    if (req_client_ip_type != NULL) {
      para->cCIPListType = json_object_get_int(req_client_ip_type);

      if (para->cCIPListType != ALERT_LOG_SEARCH_TYPE_ALL) {
        req_client_ip_list = json_object_object_get(req_params, "client_ip_list");

        if (req_client_ip_list != NULL) {
          if (xiptree_valid_cmd(json_object_get_string(req_client_ip_list))) {
            para->sCIPList = (char *)json_object_get_string(req_client_ip_list);
          } else {
            set_json_error(error, JSON_REQ_ERROR_INVALID_IP_FORMAT);
            return JSON_FAIL;
          }
        } else {
          set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
          return JSON_FAIL;
        }
      }
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }

    if (req_server_ip_type != NULL) {
      para->cSIPListType = json_object_get_int(req_server_ip_type);

      if (para->cSIPListType != ALERT_LOG_SEARCH_TYPE_ALL) {
        req_server_ip_list = json_object_object_get(req_params, "server_ip_list");

        if (req_server_ip_list != NULL) {
          if (xiptree_valid_cmd(json_object_get_string(req_server_ip_list))) {
            para->sSIPList = (char *)json_object_get_string(req_server_ip_list);
          } else {
            set_json_error(error, JSON_REQ_ERROR_INVALID_IP_FORMAT);
            return JSON_FAIL;
          }
        } else {
          set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
          return JSON_FAIL;
        }
      }
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }

    if (req_string_type != NULL) {
      para->cStringType = json_object_get_int(req_string_type);

      if (para->cStringType != ALERT_LOG_SEARCH_TYPE_ALL) {
        req_string = json_object_object_get(req_params, "string");

        if (req_string != NULL) {
          para->sSting  = (char *)json_object_get_string(req_string);
        } else {
          set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
          return JSON_FAIL;
        }
      }
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }

    if (req_start != NULL) {
      para->nStart = json_object_get_int(req_start);
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }

    if (req_count != NULL) {
      para->nCount = json_object_get_int(req_count);
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }
  }  else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
    return JSON_FAIL;
  }

  return JSON_SUCCESS;
}

static int Req_View_Alert_List (struct json_object *request, struct json_object *error, request_para *para)
{
  struct json_object *req_id;
  struct json_object *req_params;

  req_id = json_object_object_get(request, "id");
  req_params = json_object_object_get(request, "params");

  if (req_id != NULL) {
    para->id = json_object_get_int(req_id);
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_ID);
    return JSON_FAIL;
  }

  if (req_params != NULL) {
    if (json_object_array_length(req_params) == 2) {
      para->nStart = json_object_get_int(json_object_array_get_idx(req_params, 0));
      para->nCount = json_object_get_int(json_object_array_get_idx(req_params, 1));
    } else {
      set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
      return JSON_FAIL;
    }
  } else {
    set_json_error(error, JSON_REQ_ERROR_INVALID_PARAMS);
    return JSON_FAIL;
  }

  return JSON_SUCCESS;
}

void Proc_View_Alert_List_Search (struct json_object *request, struct json_object *response, void *info)
{
  int nRet; 
  request_para para;

  struct json_object *error = json_object_new_object();
  struct json_object *result_array = json_object_new_array();
  struct json_object *result = json_object_new_object();

  memset(&para, 0x00, sizeof(request_para));

  nRet = Req_View_Alert_List_Search(request, error, &para);
  if (nRet) {
    nRet = Rsp_View_Alert_List_Search(result_array, error, &para);
  }

  if (para.id)
    json_object_object_add(response, "id", json_object_new_int(para.id));

  if ((json_object_object_get(error, "code"))
  && (JSON_DB_ERROR_CURSOR_IS_NOT != json_object_get_int(json_object_object_get(error, "code")))) {
    json_object_object_add(response, "error", error);
    json_object_put(result);
    json_object_put(result_array);
  } else {
    json_object_object_add(result, "total_count", json_object_new_int(Attack_List_Search_Count(&para)));
    json_object_object_add(result, "list", result_array);
    json_object_object_add(response, "result", result);
    json_object_put(error);
  }
}

void Proc_View_Alert_List (struct json_object *request, struct json_object *response, void *info)
{
  int nRet;
  request_para para;

  struct json_object *error = json_object_new_object();
  struct json_object *result_array = json_object_new_array();
  struct json_object *result = json_object_new_object();

  memset(&para, 0x00, sizeof(request_para));
  nRet = Req_View_Alert_List(request, error, &para);
  if (nRet) {
    nRet = Rsp_View_Alert_List(result_array, error, &para);
  }

  if (para.id)
    json_object_object_add(response, "id", json_object_new_int(para.id));

  if ((json_object_object_get(error, "code"))
  && (JSON_DB_ERROR_CURSOR_IS_NOT != json_object_get_int(json_object_object_get(error, "code")))) {
    json_object_object_add(response, "error", error); 
    json_object_put(result_array);
  } else {
    json_object_object_add(result, "total_count", json_object_new_int(nRet));
    json_object_object_add(response, "result", result_array);
    json_object_put(error);
  }
}

#endif
