/*
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#include <time.h>
#include "xtimeval.h"
#include "xstring.h"
#include "htst.h"
#include "format.h"
#include "xalloc.h"
#include "xprintf.h"
#include "xiptree.h"
#include "spt.h"

#include "xbridge.h"
#include "xhttpd.h"
#include "xsession.h"
#include "xpacket.h"
#include "xarp.h"
#include "xalert.h"
#include "xfire.h"
#include "xcli.h"
#include "xconfig.h"

static int xfire_config_error = 0;


typedef struct _Xconfig {
  char   *config;
  int    type;                 
} Xconfig;



typedef enum {

  XFIRE_MANAGER_CORE_CFG,
  XFIRE_MANAGER_PORT_CFG,
  XFIRE_MANAGER_THREADS_CFG,

  XFIRE_LOCAL_GATEWAY_CFG, 

  XFIRE_MODE_CFG,

  XFIRE_TCP_TIMEOUT_CFG,
  XFIRE_UDP_TIMEOUT_CFG,
  XFIRE_ICMP_TIMEOUT_CFG,
  XFIRE_ARP_CACHE_TIMEOUT_CFG,

  XFIRE_BLACKHOLE_TIME_CFG,

  XFIRE_SESSION_TABLE_SIZE_CFG,

  XFIRE_USE_ALERT,
  XFIRE_USE_CLI,

} xconfig_type;

static Xconfig XC[] = {
  { "manager_core = ",            XFIRE_MANAGER_CORE_CFG }, 
  { "manager_port = ",            XFIRE_MANAGER_PORT_CFG }, 
  { "manager_threads = ",         XFIRE_MANAGER_THREADS_CFG },

  { "local_gateway = ",           XFIRE_LOCAL_GATEWAY_CFG }, 

  { "xfire_mode = ",              XFIRE_MODE_CFG },

  { "tcp_timeout = ",             XFIRE_TCP_TIMEOUT_CFG },
  { "udp_timeout = ",             XFIRE_UDP_TIMEOUT_CFG },
  { "icmp_timeout = ",            XFIRE_ICMP_TIMEOUT_CFG },
  { "arp_cache_timeout = ",       XFIRE_ARP_CACHE_TIMEOUT_CFG },

  { "blackhole_time = ",          XFIRE_BLACKHOLE_TIME_CFG },

  { "session_table_size = ",      XFIRE_SESSION_TABLE_SIZE_CFG },

  { "use_alert = ",               XFIRE_USE_ALERT },
  { "use_cli = ",                 XFIRE_USE_CLI },
  { NULL, 0 }
};


void disable_core_debug (void)
{
  struct rlimit rl;

  getrlimit(RLIMIT_CORE, &rl);
  rl.rlim_cur = 0;
  setrlimit(RLIMIT_CORE, &rl);
}

void enable_core_debug (void)
{
  struct rlimit rl;

  getrlimit(RLIMIT_CORE, &rl);
  rl.rlim_cur = rl.rlim_max;
  setrlimit(RLIMIT_CORE, &rl);
}

#ifdef XFIRE_SET_MAX_FD
static void enable_fd_max (void)
{
  struct rlimit limit;

  limit.rlim_cur = limit.rlim_max = 0;
  getrlimit(RLIMIT_NOFILE, &limit);
  limit.rlim_cur = limit.rlim_max = 60000;

  setrlimit(RLIMIT_NOFILE, &limit);

  limit.rlim_cur = limit.rlim_max = 0;
  getrlimit(RLIMIT_NOFILE, &limit);
}
#endif

/* Xconfig ----------------------------------*/

static int xconfig_match (htst_pat_t *pat, ub8 **data, int dlen, void *user)
{
  char *ap, *ptr, *sptr = (char *)user;
  char *dptr = (char *)*data;
 
  /* comment */
  if (dptr > sptr && *(dptr - 1) == '#') {
    while (*dptr && *dptr != '\n') dptr++;
    *data = (ub8 *)dptr + 1;
    return HTST_CONTINUE_MATCH;
  }

  ap = ptr = (char *)dptr + pat->len;
  while (*ptr && *ptr != '\n') ptr++;
  if (*ptr) *ptr = 0;

  switch (pat->id) {

    case XFIRE_MANAGER_CORE_CFG :
      xhttpd_set_core(atoi(ap)); 
      break;
    case XFIRE_MANAGER_PORT_CFG :
      xhttpd_set_port(atoi(ap)); 
      break;
    case XFIRE_MANAGER_THREADS_CFG :
      xhttpd_set_threads(atoi(ap));
      break;

    case XFIRE_LOCAL_GATEWAY_CFG :
      // ip mask portid 
      xnet_set_gateway_info(ap); 
      break;

    case XFIRE_MODE_CFG :
      xpacket_set_rtx_mode(ap);
      break;

    case XFIRE_TCP_TIMEOUT_CFG :
      xsession_set_tcp_timeout(atoi(ap));
      break;
    case XFIRE_UDP_TIMEOUT_CFG :
      xsession_set_udp_timeout(atoi(ap));
      break;
    case XFIRE_ICMP_TIMEOUT_CFG :
      xsession_set_icmp_timeout(atoi(ap));
      break;
    case XFIRE_ARP_CACHE_TIMEOUT_CFG :
      xarp_set_cache_timeout(atoi(ap));
      break;

    case XFIRE_BLACKHOLE_TIME_CFG :
      xalert_set_blackhole_time(atoi(ap));
      break;

    case XFIRE_SESSION_TABLE_SIZE_CFG :
      xsession_set_table_size(atoi(ap));
      break;

    case XFIRE_USE_ALERT :
      if (strcmp(ap, "yes") == 0) xalert_set_use(); 
      else if (strcmp(ap, "no") == 0) xalert_set_unuse();
      break;

    case XFIRE_USE_CLI :
      if (strcmp(ap, "yes") == 0) xcli_set_use();
      else if (strcmp(ap, "no") == 0) xcli_set_unuse();
      break;
  }
  *data = (ub8 *)ptr + 1;
  return HTST_CONTINUE_MATCH;
}


void print_error_msg ()
{
  printf("\n*** XFIRE configure ERROR = %d ***\n", xfire_config_error);
}

int xfire_configure (char *config_file)
{
  htst_t *xconfig_table = NULL;
  struct stat sb;

  if (stat(config_file, &sb) == -1 && errno == ENOENT) {
    printf("Skipping configuration file: %s\n", XFIRE_CONFIG_FILE);
    return 0;
  }
  
  xfire_config_error = 0;

  if ((xconfig_table = htst_create()) == NULL) return -1;

  int i = 0;
  FILE *fp = fopen(config_file, "r");
  char *cfg_mem = xmalloc(sb.st_size + 1);
  fread(cfg_mem, 1, sb.st_size, fp);
  cfg_mem[sb.st_size] = 0;
  fclose(fp);
 
  while (XC[i].config) {
    htst_add_pattern (xconfig_table, (unsigned char *)XC[i].config, strlen(XC[i].config), XC[i].type, HTST_F_WORD, &XC[i]);
    i++;
  }
  htst_compile(xconfig_table);
  htst_search(xconfig_table, (ub8 *)cfg_mem, sb.st_size, xconfig_match, cfg_mem);
  htst_destroy(xconfig_table);
  xfree(cfg_mem);   

  if (xfire_config_error) {
    print_error_msg ();
    return -1;
  }

  return 0;
}

