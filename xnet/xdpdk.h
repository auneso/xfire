#ifndef __XDPDK_H__
#define __XDPDK_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>

#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/queue.h>

#include <rte_version.h>
#include <rte_config.h>

#include <rte_log.h>
#include <rte_tailq.h>
#if defined(RTE_VER_MAJOR) && (RTE_VER_MAJOR < 2)
#include <rte_tailq_elem.h>
#endif
#include <rte_common.h>
#include <rte_memory.h>
#include <rte_memcpy.h>
#include <rte_memzone.h>
#include <rte_malloc.h>
#include <rte_eal.h>
#include <rte_per_lcore.h>
#include <rte_launch.h>
#include <rte_atomic.h>
#include <rte_rwlock.h>
#include <rte_cycles.h>
#include <rte_prefetch.h>
#include <rte_lcore.h>
#include <rte_per_lcore.h>
#include <rte_branch_prediction.h>
#include <rte_pci.h>
#include <rte_random.h>
#include <rte_timer.h>
#include <rte_debug.h>
#include <rte_ether.h>
#include <rte_ethdev.h>
#include <rte_ring.h>
#include <rte_mempool.h>
#include <rte_mbuf.h>
#include <rte_hash.h>
#include <rte_lpm.h>
#include <rte_string_fns.h>
#include <rte_byteorder.h>
#include <rte_errno.h>


#include <cmdline_rdline.h>
#include <cmdline_parse.h>
#include <cmdline_parse_num.h>
#include <cmdline_parse_string.h>
#include <cmdline_parse_ipaddr.h>
#include <cmdline_parse_etheraddr.h>
#include <cmdline_socket.h>
#include <cmdline.h>

#include "xbridge.h"

int xdpdk_run_proc (int argc, char **argv);

inline int xdpdk_send_single_packet (struct rte_mbuf *m, uint8_t port);

struct rte_mbuf *xdpdk_pktmbuf_alloc (void);
struct rte_mbuf *xdpdk_pktmbuf_clone (struct rte_mbuf *pkt);

void xdpdk_broadcast_send (xpacket *xp);

#endif /*__XDPDK_H__*/
