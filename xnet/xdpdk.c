#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <string.h>
#include <sys/queue.h>
#include <stdarg.h>
#include <errno.h>
#include <getopt.h>

#include "xdpdk.h"
#include "format.h"
#include "xtimeval.h"
#include "xpacket.h"
#include "xvendor.h"
#include "xvhost.h"
#include "xtraffic.h"
#include "xarp.h"
#include "xnat.h"
#include "xfilter.h"
#include "xroute.h"
#include "xwhite.h"
#include "xblack.h"
#include "xalert.h"
#include "xsession.h"
#include "xwall.h"
#include "xcli.h"

extern int xfire_run;

#if 0
eal_short_options[] =
  "b:" /* pci-blacklist */
  "c:" /* coremask */
  "d:" /* driver */
  "h"  /* help */
  "l:" /* corelist */
  "m:" /* memory size */
  "n:" /* memory channels */
  "r:" /* memory ranks */
  "v"  /* version */
  "w:" /* pci-whitelist */
#endif


/*
 *  When set to zero, simple forwaring path is eanbled.
 *  When set to one, optimized forwarding path is enabled.
 *  Note that LPM optimisation path uses SSE4.1 instructions.
 */
#define ENABLE_MULTI_BUFFER_OPTIMIZE  1

#define RTE_LOGTYPE_XFIRE RTE_LOGTYPE_USER1

#define MAX_JUMBO_PKT_LEN  9600

#define MEMPOOL_CACHE_SIZE 256

/*
 * This expression is used to calculate the number of mbufs needed depending on user input, taking
 *  into account memory for rx and tx hardware rings, cache per lcore and mtable per port per lcore.
 *  RTE_MAX is used to ensure that NB_MBUF never goes below a minimum value of 8192
 */

#define NB_MBUF RTE_MAX  (                                  \
        (nb_ports*nb_rx_queue*RTE_TEST_RX_DESC_DEFAULT +    \
        nb_ports*nb_lcores*MAX_PKT_BURST +                  \
        nb_ports*n_tx_queue*RTE_TEST_TX_DESC_DEFAULT +      \
        nb_lcores*MEMPOOL_CACHE_SIZE),                      \
        (unsigned)8192)

#define MAX_PKT_BURST     32
#define BURST_TX_DRAIN_US 100 /* TX drain every ~100us */

/*
 * Try to avoid TX buffering if we have at least MAX_TX_BURST packets to send.
 */
#define  MAX_TX_BURST  (MAX_PKT_BURST / 2)

#define NB_SOCKETS 8

/* Configure how many packets ahead to prefetch, when reading packets */
#define PREFETCH_OFFSET  3

/* Used to mark destination port as 'invalid'. */
#define  BAD_PORT  ((uint16_t)-1)

#define FWDSTEP  4

/*
 * Configurable number of RX/TX ring descriptors
 */
#define RTE_TEST_RX_DESC_DEFAULT 2048
#define RTE_TEST_TX_DESC_DEFAULT 2048
static uint16_t nb_rxd = RTE_TEST_RX_DESC_DEFAULT;
static uint16_t nb_txd = RTE_TEST_TX_DESC_DEFAULT;


/* mask of enabled ports */
static uint32_t enabled_port_mask = 0;
static int promiscuous_on = 1; /**< Ports set in promiscuous mode on by default. */
static int numa_on = 1;        /**< NUMA is enabled by default. */

struct mbuf_table {
  uint16_t len;
  struct rte_mbuf *m_table[MAX_PKT_BURST];
};

struct lcore_rx_queue {
  uint8_t port_id;
  uint8_t queue_id;
} __rte_cache_aligned;

#define MAX_RX_QUEUE_PER_LCORE 16
#define MAX_TX_QUEUE_PER_PORT RTE_MAX_ETHPORTS
#define MAX_RX_QUEUE_PER_PORT 128

#define MAX_LCORE_PARAMS 1024
struct lcore_params {
  uint8_t port_id;
  uint8_t queue_id;
  uint8_t lcore_id;
} __rte_cache_aligned;

static struct lcore_params lcore_params_array[MAX_LCORE_PARAMS];

static struct lcore_params lcore_params_array_default[] = {
  {0, 0, 2},
  {0, 1, 2},
  {0, 2, 2},
  {1, 0, 2},
  {1, 1, 2},
  {1, 2, 2},
  {2, 0, 2},
  {3, 0, 3},
  {3, 1, 3},
};

static struct lcore_params * lcore_params = lcore_params_array_default;
static uint16_t nb_lcore_params = sizeof(lcore_params_array_default) /
        sizeof(lcore_params_array_default[0]);

static struct rte_eth_conf port_conf = {
  .rxmode = {
    .mq_mode = ETH_MQ_RX_RSS,
    .max_rx_pkt_len = ETHER_MAX_LEN,
    .split_hdr_size = 0,
    .header_split   = 0, /**< Header Split disabled */
    .hw_ip_checksum = 1, /**< IP checksum offload enabled */
    .hw_vlan_filter = 0, /**< VLAN filtering disabled */
    .jumbo_frame    = 0, /**< Jumbo Frame Support disabled */
    .hw_strip_crc   = 0, /**< CRC stripped by hardware */
  },
  .rx_adv_conf = {
    .rss_conf = {
      .rss_key = NULL,
      .rss_hf = ETH_RSS_IP,
    },
  },
  .txmode = {
    .mq_mode = ETH_MQ_TX_NONE,
  },
};

static struct rte_mempool *pktmbuf_pool[NB_SOCKETS];
static struct rte_mempool *pktmbuf_mem = NULL;


struct lcore_conf {
  uint16_t n_rx_queue;
  struct lcore_rx_queue rx_queue_list[MAX_RX_QUEUE_PER_LCORE];
  uint16_t tx_queue_id[RTE_MAX_ETHPORTS];
  struct mbuf_table tx_mbufs[RTE_MAX_ETHPORTS];
} __rte_cache_aligned;

static struct lcore_conf lcore_conf[RTE_MAX_LCORE];



/* Send burst of packets on an output interface */
static inline int
send_burst (struct lcore_conf *qconf, uint16_t n, uint8_t port)
{
  struct rte_mbuf **m_table;
  int ret;
  uint16_t queueid;

  queueid = qconf->tx_queue_id[port];
  m_table = (struct rte_mbuf **)qconf->tx_mbufs[port].m_table;

  ret = rte_eth_tx_burst(port, queueid, m_table, n);
  if (unlikely(ret < n)) {
    do {
      rte_pktmbuf_free(m_table[ret]);
    } while (++ret < n);
  }

  return 0;
}

/* Enqueue a single packet, and send burst if queue is filled */
inline int
xdpdk_send_single_packet (struct rte_mbuf *m, uint8_t port)
{
  uint32_t lcore_id;
  uint16_t len;
  struct lcore_conf *qconf;

  lcore_id = rte_lcore_id();
  qconf = &lcore_conf[lcore_id];
  len = qconf->tx_mbufs[port].len;
  qconf->tx_mbufs[port].m_table[len] = m;
  len++;

  /* enough pkts to be sent */
  if (unlikely(len == MAX_PKT_BURST)) {
    send_burst(qconf, MAX_PKT_BURST, port);
    len = 0;
  }

  qconf->tx_mbufs[port].len = len;
  return 0;
}

struct rte_mbuf *xdpdk_pktmbuf_alloc (void)
{
  return rte_pktmbuf_alloc(pktmbuf_mem);
}

void xdpdk_broadcast_send (xpacket *xp)
{
  int idx;
  ub16 rcnt;
  xdevice *xdev;
  xbridge *xb = xp->xb;
  ub8 portid = xp->xdev->portid;

  for (idx = 0, rcnt = 0; idx < xb->xdev_num; idx++) {
    xdev = &xb->xdev[idx];
    if (xdev != xp->xdev) {
      rcnt++; portid = xdev->portid;
    }
  }

  if (rcnt > 1) {
    rcnt = rte_mbuf_refcnt_update(xp->mbuf, (uint16_t)rcnt);
    for (idx = 0; idx < xb->xdev_num; idx++) {
      xdev = &xb->xdev[idx];
      if (xdev != xp->xdev) {
        rte_memcpy(xp->p_ethh->ether_shost, xdev->xmac, XETHER_ADDR_LEN);
        xdpdk_send_single_packet(xp->mbuf, xdev->portid);
      }
    }
  } else if (rcnt == 1) {
    xdpdk_send_single_packet(xp->mbuf, portid);
  } else {
    rte_pktmbuf_free(xp->mbuf);
  } 
}

static int rx_packet (xpacket *xp, uint8_t portid, struct timeval *ts)
{
  int action;
  
  xpacket_dissect(xp, portid, ts);
  if (xp->drop) { return XNET_DROP; }

  if (xwhite_find(xp->src_ip) || xwhite_find(xp->dst_ip)) 
    return XNET_ACCEPT;

  if (xblack_find(xp->src_ip) || xblack_find(xp->dst_ip)) {
    xalert_put_blackhole(xp->src_ip, xp->dst_ip, xp->src_port, xp->dst_port, xp->protocol, "Black List Drop");
    return XNET_DROP;
  }

  action = xwall_filter_find(xp);
  
  if (action == XFILTER_DROP) {
    return XNET_DROP;
  }

  if (action == XFILTER_REJECT) {
    if (xp->protocol == XNET_TCP_PROTOCOL) {
//printf("XFILTER_REJECT  src = %s : %u, dst = %s : %u\n", intoa(xp->src_ip), xp->src_port, intoa(xp->dst_ip), xp->dst_port);
      xpacket_set_reject_source(xp);
    } else {
      return XNET_DROP;
    }
  }
  return xp->xb->rx_packet(xp);
}

static int tx_packet (xpacket *xp)
{
  return xp->xb->tx_packet(xp);
}


/* main processing loop */
static int
main_loop (__attribute__((unused)) void *dummy)
{
  struct rte_mbuf *pkts_burst[MAX_PKT_BURST];
  unsigned lcore_id;
  uint64_t prev_tsc, diff_tsc, cur_tsc;
  int i, j, nb_rx;
  uint8_t portid, queueid;
  struct lcore_conf *qconf;
  struct timeval ts;
  xpacket xp;

  const uint64_t drain_tsc = (rte_get_tsc_hz() + US_PER_S - 1) / US_PER_S * BURST_TX_DRAIN_US;

  prev_tsc = 0;

  lcore_id = rte_lcore_id();
  qconf = &lcore_conf[lcore_id];

  if (qconf->n_rx_queue == 0) {
    RTE_LOG(INFO, XFIRE, "lcore %u has nothing to do\n", lcore_id);
    return 0;
  }

  RTE_LOG(INFO, XFIRE, "entering main loop on lcore %u\n", lcore_id);

  for (i = 0; i < qconf->n_rx_queue; i++) {
    portid = qconf->rx_queue_list[i].port_id;
    queueid = qconf->rx_queue_list[i].queue_id;
    RTE_LOG(INFO, XFIRE, " -- lcoreid=%u portid=%hhu rxqueueid=%hhu\n", lcore_id, portid, queueid);
  }

  while (xfire_run) {

    cur_tsc = rte_rdtsc();
    /*
     * TX burst queue drain
     */
    diff_tsc = cur_tsc - prev_tsc;

    if (unlikely(diff_tsc > drain_tsc)) {
      /*
       * This could be optimized (use queueid instead of
       * portid), but it is not called so often
       */
      for (portid = 0; portid < RTE_MAX_ETHPORTS; portid++) {
        if (qconf->tx_mbufs[portid].len == 0) continue;

        send_burst(qconf, qconf->tx_mbufs[portid].len, portid);
        qconf->tx_mbufs[portid].len = 0;
      }
      prev_tsc = cur_tsc;
    }

    /*
     * Read packet from RX queues
     */

    for (i = 0; i < qconf->n_rx_queue; ++i) {
      portid = qconf->rx_queue_list[i].port_id;
      queueid = qconf->rx_queue_list[i].queue_id;

      nb_rx = rte_eth_rx_burst(portid, queueid, pkts_burst, MAX_PKT_BURST);
      if (nb_rx == 0) continue;
              
//===== xfire rx/tx proc
      xgettimeofday(&ts);

      xfire_write_lock();

      for (j = 0; j < nb_rx ; j++) {
        xp.mbuf = pkts_burst[j]; 
        if (rx_packet(&xp, portid, &ts) == XNET_DROP) {
          rte_pktmbuf_free(xp.mbuf);
        } else 
        if (tx_packet(&xp) == XNET_DROP) {
          rte_pktmbuf_free(xp.mbuf); 
        }
      }

      xfire_write_unlock();
//===== xfire rx/tx proc
    }
  }
  return 1;
}


static int
check_lcore_params (void)
{
  uint8_t queue, lcore;
  uint16_t i;
  int socketid;

  for (i = 0; i < nb_lcore_params; ++i) {
    queue = lcore_params[i].queue_id;
    if (queue >= MAX_RX_QUEUE_PER_PORT) {
      printf("invalid queue number: %hhu\n", queue);
      return -1;
    }
    lcore = lcore_params[i].lcore_id;
    if (!rte_lcore_is_enabled(lcore)) {
      printf("error: lcore %hhu is not enabled in lcore mask\n", lcore);
      return -1;
    }
    if ((socketid = rte_lcore_to_socket_id(lcore) != 0) && (numa_on == 0)) {
      printf("warning: lcore %hhu is on socket %d with numa off \n", lcore, socketid);
    }
  }
  return 0;
}

static int
check_port_config (const unsigned nb_ports)
{
  unsigned portid;
  uint16_t i;

  for (i = 0; i < nb_lcore_params; ++i) {
    portid = lcore_params[i].port_id;
    if ((enabled_port_mask & (1 << portid)) == 0) {
      printf("port %u is not enabled in port mask\n", portid);
      return -1;
    }
    if (portid >= nb_ports) {
      printf("port %u is not present on the board\n", portid);
      return -1;
    }
  }
  return 0;
}

static uint8_t
get_port_n_rx_queues (const uint8_t port)
{
  int queue = -1;
  uint16_t i;

  for (i = 0; i < nb_lcore_params; ++i) {
    if (lcore_params[i].port_id == port && lcore_params[i].queue_id > queue)
      queue = lcore_params[i].queue_id;
  }
  return (uint8_t)(++queue);
}

static int
init_lcore_rx_queues (void)
{
  uint16_t i, nb_rx_queue;
  uint8_t lcore;

  for (i = 0; i < nb_lcore_params; ++i) {
    lcore = lcore_params[i].lcore_id;
    nb_rx_queue = lcore_conf[lcore].n_rx_queue;
    if (nb_rx_queue >= MAX_RX_QUEUE_PER_LCORE) {
      printf("error: too many queues (%u) for lcore: %u\n", (unsigned)nb_rx_queue + 1, (unsigned)lcore);
      return -1;
    } else {
      lcore_conf[lcore].rx_queue_list[nb_rx_queue].port_id = lcore_params[i].port_id;
      lcore_conf[lcore].rx_queue_list[nb_rx_queue].queue_id = lcore_params[i].queue_id;
      lcore_conf[lcore].n_rx_queue++;
    }
  }
  return 0;
}

/* display usage */
static void
print_usage(const char *prgname)
{
  printf ("%s [EAL options] -- -p PORTMASK -P"
    "  [--config (port,queue,lcore)[,(port,queue,lcore]]"
    "  [--enable-jumbo [--max-pkt-len PKTLEN]]\n"
    "  -p PORTMASK: hexadecimal bitmask of ports to configure\n"
    "  -P : disable promiscuous mode\n"
    "  --config (port,queue,lcore): rx queues configuration\n"
    "  --eth-dest=X,MM:MM:MM:MM:MM:MM: optional, ethernet destination for port X\n"
    "  --no-numa: optional, disable numa awareness\n"
    "  --enable-jumbo: enable jumbo frame"
    " which max packet len is PKTLEN in decimal (64-9600)\n",
    prgname);
}

static int parse_max_pkt_len(const char *pktlen)
{
  char *end = NULL;
  unsigned long len;

  /* parse decimal string */
  len = strtoul(pktlen, &end, 10);
  if ((pktlen[0] == '\0') || (end == NULL) || (*end != '\0'))
    return -1;

  if (len == 0)
    return -1;

  return len;
}

static int
parse_portmask(const char *portmask)
{
  char *end = NULL;
  unsigned long pm;

  /* parse hexadecimal string */
  pm = strtoul(portmask, &end, 16);
  if ((portmask[0] == '\0') || (end == NULL) || (*end != '\0'))
    return -1;

  if (pm == 0)
    return -1;

  return pm;
}

static int
parse_config (const char *q_arg)
{
  char s[256];
  const char *p, *p0 = q_arg;
  char *end;
  enum fieldnames {
    FLD_PORT = 0,
    FLD_QUEUE,
    FLD_LCORE,
    _NUM_FLD
  };
  unsigned long int_fld[_NUM_FLD];
  char *str_fld[_NUM_FLD];
  int i;
  unsigned size;

  nb_lcore_params = 0;

  while ((p = strchr(p0,'(')) != NULL) {
    ++p;
    if((p0 = strchr(p,')')) == NULL)
      return -1;

    size = p0 - p;
    if(size >= sizeof(s))
      return -1;

    snprintf(s, sizeof(s), "%.*s", size, p);
    if (rte_strsplit(s, sizeof(s), str_fld, _NUM_FLD, ',') != _NUM_FLD)
      return -1;
    for (i = 0; i < _NUM_FLD; i++){
      errno = 0;
      int_fld[i] = strtoul(str_fld[i], &end, 0);
      if (errno != 0 || end == str_fld[i] || int_fld[i] > 255)
        return -1;
    }
    if (nb_lcore_params >= MAX_LCORE_PARAMS) {
      printf("exceeded max number of lcore params: %hu\n", nb_lcore_params);
      return -1;
    }
    lcore_params_array[nb_lcore_params].port_id  = (uint8_t)int_fld[FLD_PORT];
    lcore_params_array[nb_lcore_params].queue_id = (uint8_t)int_fld[FLD_QUEUE];
    lcore_params_array[nb_lcore_params].lcore_id = (uint8_t)int_fld[FLD_LCORE];
    ++nb_lcore_params;
  }
  lcore_params = lcore_params_array;
  return 0;
}

#define CMD_LINE_OPT_CONFIG "config"
#define CMD_LINE_OPT_NO_NUMA "no-numa"
#define CMD_LINE_OPT_ENABLE_JUMBO "enable-jumbo"

/* Parse the argument given in the command line of the application */
static int
parse_args (int argc, char **argv)
{
  int opt, ret;
  char **argvopt;
  int option_index;
  char *prgname = argv[0];
  static struct option lgopts[] = {
    {CMD_LINE_OPT_CONFIG, 1, 0, 0},
    {CMD_LINE_OPT_NO_NUMA, 0, 0, 0},
    {NULL, 0, 0, 0}
  };

  argvopt = argv;

  while ((opt = getopt_long(argc, argvopt, "p:P", lgopts, &option_index)) != EOF) {

    switch (opt) {
    /* portmask */
    case 'p':
      enabled_port_mask = parse_portmask(optarg);
      if (enabled_port_mask == 0) {
        printf("invalid portmask\n");
        print_usage(prgname);
        return -1;
      }
      break;
    case 'P':
      promiscuous_on = 0;
      break;

    /* long options */
    case 0:
      if (!strncmp(lgopts[option_index].name, CMD_LINE_OPT_CONFIG,
        sizeof (CMD_LINE_OPT_CONFIG))) {
        ret = parse_config(optarg);
        if (ret) {
          printf("invalid config\n");
          print_usage(prgname);
          return -1;
        }
      }

      if (!strncmp(lgopts[option_index].name, CMD_LINE_OPT_NO_NUMA, sizeof(CMD_LINE_OPT_NO_NUMA))) {
        printf("numa is disabled \n");
        numa_on = 0;
      }

      if (!strncmp(lgopts[option_index].name, CMD_LINE_OPT_ENABLE_JUMBO, sizeof (CMD_LINE_OPT_ENABLE_JUMBO))) {
        struct option lenopts = {"max-pkt-len", required_argument, 0, 0};

        printf("jumbo frame is enabled - disabling simple TX path\n");
        port_conf.rxmode.jumbo_frame = 1;

        /* if no max-pkt-len set, use the default value ETHER_MAX_LEN */
        if (0 == getopt_long(argc, argvopt, "", &lenopts, &option_index)) {
          ret = parse_max_pkt_len(optarg);
          if ((ret < 64) || (ret > MAX_JUMBO_PKT_LEN)){
            printf("invalid packet length\n");
            print_usage(prgname);
            return -1;
          }
          port_conf.rxmode.max_rx_pkt_len = ret;
        }
        printf("set jumbo frame max packet length to %u\n", (unsigned int)port_conf.rxmode.max_rx_pkt_len);
      }
      break;

    default:
      print_usage(prgname);
      return -1;
    }
  }

  if (optind >= 0)
    argv[optind-1] = prgname;

  ret = optind-1;
  optind = 0; /* reset getopt lib */
  return ret;
}


static int
init_mem (unsigned nb_mbuf)
{
  int socketid;
  unsigned lcore_id;
  char s[64];

  if (pktmbuf_mem == NULL) pktmbuf_mem = rte_pktmbuf_pool_create("mbuf_mem", nb_mbuf, MEMPOOL_CACHE_SIZE, 0, RTE_MBUF_DEFAULT_BUF_SIZE, rte_socket_id());

  for (lcore_id = 0; lcore_id < RTE_MAX_LCORE; lcore_id++) {
    if (rte_lcore_is_enabled(lcore_id) == 0)
      continue;

    if (numa_on)
      socketid = rte_lcore_to_socket_id(lcore_id);
    else
      socketid = 0;

    if (socketid >= NB_SOCKETS) {
      rte_exit(EXIT_FAILURE, "Socket %d of lcore %u is out of range %d\n", socketid, lcore_id, NB_SOCKETS);
    }
    if (pktmbuf_pool[socketid] == NULL) {
      snprintf(s, sizeof(s), "mbuf_pool_%d", socketid);
      pktmbuf_pool[socketid] = rte_pktmbuf_pool_create(s, nb_mbuf, MEMPOOL_CACHE_SIZE, 0, RTE_MBUF_DEFAULT_BUF_SIZE, socketid);
      if (pktmbuf_pool[socketid] == NULL)
        rte_exit(EXIT_FAILURE, "Cannot init mbuf pool on socket %d\n", socketid);
      else
        printf("Allocated mbuf pool on socket %d\n", socketid);
    }
  }
  
  return 0;
}

/* Check the link status of all ports in up to 9s, and print them finally */
static void
check_all_ports_link_status (uint8_t port_num, uint32_t port_mask)
{
#define CHECK_INTERVAL 100 /* 100ms */
#define MAX_CHECK_TIME 90 /* 9s (90 * 100ms) in total */
  uint8_t portid, count, all_ports_up, print_flag = 0;
  struct rte_eth_link link;

  printf("\nChecking link status");
  fflush(stdout);

  for (count = 0; count <= MAX_CHECK_TIME; count++) {
    all_ports_up = 1;
    for (portid = 0; portid < port_num; portid++) {
      if ((port_mask & (1 << portid)) == 0) continue;

      memset(&link, 0, sizeof(link));
      rte_eth_link_get_nowait(portid, &link);
      /* print link status if flag set */
      if (print_flag == 1) {
        if (link.link_status)
          printf("Port %d Link Up - speed %u Mbps - %s\n", (uint8_t)portid, (unsigned)link.link_speed, (link.link_duplex == ETH_LINK_FULL_DUPLEX) 
                ?  ("full-duplex") : ("half-duplex\n"));
        else
          printf("Port %d Link Down\n", (uint8_t)portid);
        continue;
      }
      /* clear all_ports_up flag if any link down */
      if (link.link_status == 0) {
        all_ports_up = 0;
        break;
      }
    }
    /* after finally printing all link status, get out */
    if (print_flag == 1)
      break;

    if (all_ports_up == 0) {
      printf(".");
      fflush(stdout);
      rte_delay_ms(CHECK_INTERVAL);
    }

    /* set the print_flag if all ports up or timeout */
    if (all_ports_up == 1 || count == (MAX_CHECK_TIME - 1)) {
      print_flag = 1;
      printf("done\n");
    }
  }
}

int
xdpdk_run_proc (int argc, char **argv)
{
  struct lcore_conf *qconf;
  struct rte_eth_dev_info dev_info;
  struct rte_eth_txconf *txconf;
  struct rte_eth_link link;
  struct ether_addr ports_eth_addr;

  int ret;
  unsigned nb_ports;
  uint16_t queueid;
  unsigned lcore_id;
  uint32_t n_tx_queue, nb_lcores;
  uint8_t portid, nb_rx_queue, queue, socketid;
  char s[64];

  /* init EAL */
  ret = rte_eal_init(argc, argv);
  if (ret < 0)
    rte_exit(EXIT_FAILURE, "Invalid EAL parameters\n");
  argc -= ret;
  argv += ret;

  
  /* parse application arguments (after the EAL ones) */
  ret = parse_args(argc, argv);
  if (ret < 0)
    rte_exit(EXIT_FAILURE, "Invalid XFIRE parameters\n");

  if (check_lcore_params() < 0)
    rte_exit(EXIT_FAILURE, "check_lcore_params failed\n");

  ret = init_lcore_rx_queues();
  if (ret < 0)
    rte_exit(EXIT_FAILURE, "init_lcore_rx_queues failed\n");

  nb_ports = rte_eth_dev_count();
  if (nb_ports > RTE_MAX_ETHPORTS)
    nb_ports = RTE_MAX_ETHPORTS;

  if (check_port_config(nb_ports) < 0)
    rte_exit(EXIT_FAILURE, "check_port_config failed\n");

  nb_lcores = rte_lcore_count();

  /* initialize all ports */
  for (portid = 0; portid < nb_ports; portid++) {
    /* skip ports that are not enabled */
    if ((enabled_port_mask & (1 << portid)) == 0) {
      printf("\nSkipping disabled port %d\n", portid);
      continue;
    }

    /* init port */
    printf("Initializing port %d ... ", portid );
    fflush(stdout);

    nb_rx_queue = get_port_n_rx_queues(portid);
    n_tx_queue = nb_lcores;
    if (n_tx_queue > MAX_TX_QUEUE_PER_PORT)
      n_tx_queue = MAX_TX_QUEUE_PER_PORT;

    printf("Creating queues: nb_rxq=%d nb_txq=%u... ", nb_rx_queue, (unsigned)n_tx_queue );

    ret = rte_eth_dev_configure(portid, nb_rx_queue, (uint16_t)n_tx_queue, &port_conf);
    if (ret < 0)
      rte_exit(EXIT_FAILURE, "Cannot configure device: err=%d, port=%d\n", ret, portid);

    rte_eth_macaddr_get(portid, &ports_eth_addr);

    memset(&link, 0, sizeof(link));
    rte_eth_link_get(portid, &link);

    sprintf(s, "port-%d@dpdk-%d", portid, portid);
    xpacket_set_xdevice(portid, s, ports_eth_addr.addr_bytes, link.link_speed);


    /* init memory */
    ret = init_mem(NB_MBUF);
    if (ret < 0) rte_exit(EXIT_FAILURE, "init_mem failed\n");

    /* init one TX queue per couple (lcore,port) */
    queueid = 0;
    for (lcore_id = 0; lcore_id < RTE_MAX_LCORE; lcore_id++) {
      if (rte_lcore_is_enabled(lcore_id) == 0)
        continue;

      if (numa_on)
        socketid = (uint8_t)rte_lcore_to_socket_id(lcore_id);
      else
        socketid = 0;

      printf("txq=%u,%d,%d ", lcore_id, queueid, socketid);
      fflush(stdout);

      rte_eth_dev_info_get(portid, &dev_info);
      txconf = &dev_info.default_txconf;
      if (port_conf.rxmode.jumbo_frame)
        txconf->txq_flags = 0;
      ret = rte_eth_tx_queue_setup(portid, queueid, nb_txd, socketid, txconf);
      if (ret < 0) rte_exit(EXIT_FAILURE, "rte_eth_tx_queue_setup: err=%d, port=%d\n", ret, portid);

      qconf = &lcore_conf[lcore_id];
      qconf->tx_queue_id[portid] = queueid;
      queueid++;
    }
    printf("\n");
  }

  for (lcore_id = 0; lcore_id < RTE_MAX_LCORE; lcore_id++) {
    if (rte_lcore_is_enabled(lcore_id) == 0) continue;

    qconf = &lcore_conf[lcore_id];

    printf("\nInitializing rx queues on lcore %u ... ", lcore_id );
    fflush(stdout);

    /* init RX queues */
    for (queue = 0; queue < qconf->n_rx_queue; ++queue) {
      portid = qconf->rx_queue_list[queue].port_id;
      queueid = qconf->rx_queue_list[queue].queue_id;

      if (numa_on)
        socketid = (uint8_t)rte_lcore_to_socket_id(lcore_id);
      else
        socketid = 0;

      printf("rxq=%d,%d,%d ", portid, queueid, socketid);
      fflush(stdout);

      ret = rte_eth_rx_queue_setup(portid, queueid, nb_rxd, socketid, NULL, pktmbuf_pool[socketid]);
      if (ret < 0) rte_exit(EXIT_FAILURE, "rte_eth_rx_queue_setup: err=%d, port=%d\n", ret, portid);
    }
  }

  printf("\n");


  /* start ports */
  for (portid = 0; portid < nb_ports; portid++) {
    if ((enabled_port_mask & (1 << portid)) == 0) {
      continue;
    }
    /* Start device */
    ret = rte_eth_dev_start(portid);
    if (ret < 0) rte_exit(EXIT_FAILURE, "rte_eth_dev_start: err=%d, port=%d\n", ret, portid);

    /*
     * If enabled, put device in promiscuous mode.
     * This allows IO forwarding mode to forward packets
     * to itself through 2 cross-connected  ports of the
     * target machine.
     */
    
    if (promiscuous_on)
      rte_eth_promiscuous_enable(portid);
  }


  check_all_ports_link_status((uint8_t)nb_ports, enabled_port_mask);

//========== xfire ==============
  xpacket_setup();

  xfire_cli ();
//========== xfire ==============

  /* launch per-lcore init on every lcore */
  rte_eal_mp_remote_launch(main_loop, NULL, CALL_MASTER);

  RTE_LCORE_FOREACH_SLAVE(lcore_id) {
    if (rte_eal_wait_lcore(lcore_id) < 0)
      return -1;
  }

  return 0;
}

