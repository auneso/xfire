#ifndef __XFIRE_H__
#define __XFIRE_H__

/*
 * Some versioning definition:
 * w.x.y.z
 * `-+-+-+-- "Huge"  changes ---> These only change on overflow of "Minor"
 *   `-+-+-- "Major" changes _/            - x elem of {0, 1, ..., 9}
 *     `-+-- "Minor" changes, new features - y elem of {0, 1, ..., 9}
 *       `-- "Tiny"  changes, bug fixes    - z elem of {0, 1, ...}
 */
/** Linux xfire 2.6.32-220.el6.x86_64 #1 SMP Tue Dec 6 19:48:22 GMT 2011 x86_64 x86_64 x86_64 GNU/Linux **/
/*
*/
#define XFIRE_VERSION    "1.0.0"

#define XFIRE_PRIORITY    (-15) 

#define XFIRE_HOME             "/xfire"
#define XFIRE_EXE              "/xfire/xfire"
#define XFIRE_CONFIG_FILE      "/xfire/xfire.cfg"
#define XFIRE_SERVER_FILE      "/xfire/server.cfg"
#define XFIRE_PID_FILE         "/xfire/xfire.pid"
#define XFIRE_VIRTUAL_CFG_FILE "/xfire/xvirtual.cfg"
#define XFIRE_LOCAL_CFG_FILE   "/xfire/xlocal.cfg"
#define XFIRE_VHOST_CFG_FILE   "/xfire/xvhost.cfg"
#define XFIRE_ROUTE_CFG_FILE   "/xfire/xroute.cfg"
#define XFIRE_FILTER_CFG_FILE  "/xfire/xfilter.cfg"

#define XFIRE_LOG_FILE         "/xfire/xfire.log"
#define XFIRE_WHITE_LIST_FILE  "/xfire/xwhite.list"
#define XFIRE_BLACK_LIST_FILE  "/xfire/xblack.list"
#define XFIRE_ARP_INFO_FILE    "/xfire/xarp.info"
#define XFIRE_MAC_INFO_FILE    "/xfire/xmac.info"
#define XFIRE_HTTP_PATH        "/xfire/www"



#ifdef __XDEBUG__
#define XDEBUG_DIAG(x)      do { printf x; } while(0)
#else
#define XDEBUG_DIAG(x) 
#endif

int xfire_update_expire (void);

char *get_xfire_version (void);
int   get_xfire_spec (void);

void xfire_system_upgrade (void);
void xfire_system_rebuild (void);

void xfire_write_lock (void);
void xfire_write_unlock (void);
void xfire_read_lock (void);
void xfire_read_unlock (void);

extern int xfire_system;

#endif

