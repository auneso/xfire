/*
 * 2016-03-30  HDS JSON_ACTIVE_COUNT 3 sec -> 5 sec
 */
#ifndef __JSON_DEFINE_H__
#define __JSON_DEFINE_H__

#define  JSON_SUCCESS                    1
#define  JSON_FAIL                       0

#define JSON_MAX_IP_LEN                        1024
#define JSON_MAX_URL_LEN                       1024
#define JSON_MAX_COUNTRY_LEN                   12

#define JSON_SORT_ENABLE                       1

#define JSON_SORT_ASCEND                       0
#define JSON_SORT_DSCEND                       1

#define JSON_DIR_REQUEST                       1
#define JSON_DIR_RESPONSE                      2

#define JSON_ACTIVE_COUNT(a,b) if (tran_idle > 5000000) b = 0; else b = a

/* Session ------------------------------------*/
#define JSON_SESSION_SORT_TYPE_CLIENT_IP       1
#define JSON_SESSION_SORT_TYPE_SERVER_IP       2
#define JSON_SESSION_SORT_TYPE_METHOD          3
#define JSON_SESSION_SORT_TYPE_URL             4
#define JSON_SESSION_SORT_TYPE_TRANS_CNT       5
#define JSON_SESSION_SORT_TYPE_REQ_PKTS        6
#define JSON_SESSION_SORT_TYPE_RSP_PKTS        7
#define JSON_SESSION_SORT_TYPE_REQ_BYTES       8
#define JSON_SESSION_SORT_TYPE_RSP_BYTES       9
#define JSON_SESSION_SORT_TYPE_COUNTRY        10
#define JSON_SESSION_SORT_TYPE_BPS            11
#define JSON_SESSION_SORT_TYPE_PPS            12
#define JSON_SESSION_SORT_TYPE_IDLE           13
#define JSON_SESSION_SORT_TYPE_RSP_CODE       14
#define JSON_SESSION_SORT_TYPE_DIRECTION      15
#define JSON_SESSION_SORT_TYPE_ISP            16
#define JSON_SESSION_SORT_TYPE_ORG            17
#define JSON_SESSION_SORT_TYPE_SERVER_RTT     18
#define JSON_SESSION_SORT_TYPE_CLIENT_RTT     19
#define JSON_SESSION_SORT_TYPE_URL_LATENCY    20
#define JSON_SESSION_SORT_TYPE_OS             21
#define JSON_SESSION_SORT_TYPE_BROWSER        22
#define JSON_SESSION_SORT_TYPE_MOBILE         23
#define JSON_SESSION_SORT_TYPE_USE_TIME       24
#define JSON_SESSION_SORT_TYPE_GXID           25
#define JSON_SESSION_SORT_TYPE_TABLET         26
#define JSON_SESSION_SORT_TYPE_REQ_BPS        27
#define JSON_SESSION_SORT_TYPE_RSP_BPS        28
#define JSON_SESSION_SORT_TYPE_REQ_PPS        29
#define JSON_SESSION_SORT_TYPE_RSP_PPS        30
#define JSON_SESSION_SORT_TYPE_DEV_NAME       31

/* Black Hole ---------------------------------*/
#define JSON_BLACKHOLE_SORT_TYPE_CLIENT_IP     1
#define JSON_BLACKHOLE_SORT_TYPE_SERVER_IP     2
#define JSON_BLACKHOLE_SORT_TYPE_ATTACK_COUNT  3
#define JSON_BLACKHOLE_SORT_TYPE_START_TIME    4
#define JSON_BLACKHOLE_SORT_TYPE_END_TIME      5
#define JSON_BLACKHOLE_SORT_TYPE_DURING_TIME   6
#define JSON_BLACKHOLE_SORT_TYPE_MSG_TYPE      7
#define JSON_BLACKHOLE_SORT_TYPE_REJECT_COUNT  8
#define JSON_BLACKHOLE_SORT_TYPE_DROP_COUNT    9

/* Black List ---------------------------------*/
#define JSON_BLACKLIST_SORT_TYPE_CLIENT_IP     1
#define JSON_BLACKLIST_SORT_TYPE_DROP_COUNT    2
#define JSON_BLACKLIST_SORT_TYPE_CTIME         3
#define JSON_BLACKLIST_SORT_TYPE_ETIME         4


/* SLB ---------------------------------------*/
#define JSON_SLB_INSERT                       1
#define JSON_SLB_UPDATE                       2
#define JSON_SLB_REMOVE                       3

#define JSON_SLB_VIRTUAL_SERVER               1
#define JSON_SLB_VIRTUAL_REAL_SERVER          2
#define JSON_SLB_REDIRECT_SERVER              3
#define JSON_SLB_REDIRECT_REAL_SERVER         4
#define JSON_SLB_ALL_SERVER                   5

#define JSON_SLB_CONFIG_VIEW                  1
#define JSON_SLB_CONFIG_UPLOAD                2

/* XARP ---------------------------------------*/
#define JSON_XARP_INSERT                      1
#define JSON_XARP_UPDATE                      2
#define JSON_XARP_REMOVE                      3

/* XDEV ---------------------------------------*/
#define JSON_XDEV_INSERT                      1
#define JSON_XDEV_UPDATE                      2
#define JSON_XDEV_REMOVE                      3

#endif
