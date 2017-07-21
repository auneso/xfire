#ifndef __BRIDGE_H__
#define __BRIDGE_H__

/*
*/

#include "xfire.h"
#include "xproto.h"
#include "xiport.h"
#include "xiptree.h"
#include "xtypes.h"
#include "xnet.h"
#include "xrbt.h"

/*
Frame type   MTU	Layer 1 overhead            Layer 2 overhead                 Layer 3 overhead   Layer 4 overhead  Payload size  Total transmitted[9]  Efficiency[10]
Standard    1500       preamble 8byte IPG 12byte  frame header 14byte FCS 4byte    IPv4 header 20byte   TCP header 20byte  1460 byte    1538 byte             94.93%
Jumbo       9000       preamble 8byte IPG 12byte  frame header 14byte FCS 4byte    IPv4 header 20byte   TCP header 20byte  8960 byte    9038 byte             99.14%
IEEE 802.11 793        PLCP preamble&header 24byte IPG varies frame header & security ovhd 52byte FCS 4byte IPv4 header 20byte TCP header 20byte 7895 byte 8015 + IPG size byte	< 98.5%
*/


/* TCP flags */
#define X_TCP_FIN 0x01u
#define X_TCP_SYN 0x02u
#define X_TCP_RST 0x04u
#define X_TCP_PSH 0x08u
#define X_TCP_ACK 0x10u
#define X_TCP_URG 0x20u
#define X_TCP_ECN 0x40u
#define X_TCP_CWR 0x80u

#define X_TCP_SYNACK    (X_TCP_SYN | X_TCP_ACK)
#define X_TCP_PSHACK    (X_TCP_PSH | X_TCP_ACK)
#define X_TCP_FINACK    (X_TCP_FIN | X_TCP_ACK)
#define X_TCP_FINPSHACK (X_TCP_FIN | X_TCP_PSH | X_TCP_ACK)
#define X_TCP_RSTACK    (X_TCP_RST | X_TCP_ACK)

/* 802.1Q VLAN                              */ 
/* dst_mac(6), src_mac(6), vlan(4), data... */
/* 0       3   4                        15  */
/* +-------+---+------------------------+   */
/* |  pri  | c |         vlan-id        |   */
/* +-------+---+------------------------+   */
/* [priority = 3bits] [Canonical Format Flag = 1bit] [vlan-id = 12 bits] */
#define VLAN_HEADER_LEN  4
#define ETH_HEADER_LEN  12


/*===================================================================
Ethernet_II Layout:
   
    0                   1                   2                   3   
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Dest.     |   Source  |ETH| Network Protocol Packet           |
   | MAC Addr. | MAC Addr. |type                                   |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   6 bytes      6 bytes    2 bytes   Up to 1500 bytes
 

Internet Protocol Header Format
    0                   1                   2                   3   
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |Version|  IHL  |Type of Service|          Total Length         |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |         Identification        |Flags|      Fragment Offset    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  Time to Live |    Protocol   |         Header Checksum       |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                       Source Address                          |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Destination Address                        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Options                    |    Padding    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  

TCP Header Format
    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |          Source Port          |       Destination Port        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                        Sequence Number                        | 
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Acknowledgment Number                      |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  Data |       |C|E|U|A|P|R|S|F|                               |
   | Offset| Reserv|W|C|R|C|S|S|Y|I|            Window             |
   |       |       |R|E|G|K|H|T|N|N|                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |           Checksum            |         Urgent Pointer        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Options                    |    Padding    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                             data                              |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
===================================================================*/
/* These macros should be calculated by the preprocessor and are used
   with compile-time constants only (so that there is no little-endian
   overhead at runtime). */
#define PP_HTONS(x) ((((x) & 0xff) << 8) | (((x) & 0xff00) >> 8))
#define PP_NTOHS(x) PP_HTONS(x)
#define PP_HTONL(x) ((((x) & 0xff) << 24) | \
                     (((x) & 0xff00) << 8) | \
                     (((x) & 0xff0000UL) >> 8) | \
                     (((x) & 0xff000000UL) >> 24))
#define PP_NTOHL(x) PP_HTONL(x)


#define PUBLIC_IP     0
#define PRIVATE_IP    1
#define MULTICAST_IP  2
#define BROADCAST_IP  3

/** 255.255.255.255 */
#define IPADDR_NONE         ((ub32)0xffffffffUL)

/** 127.0.0.1 */
#define IPADDR_LOOPBACK     ((ub32)0x7f000001UL)

/** 0.0.0.0 */
#define IPADDR_ANY          ((ub32)0x00000000UL)

/** 255.255.255.255 */
#define IPADDR_BROADCAST    ((ub32)0xffffffffUL)


/* Definitions of the bits in an Internet address integer.

   On subnets, host and network parts are found according to
   the subnet mask, not these masks.  */
#define IP_CLASSA(a)        ((((ub32)(a)) & 0x80000000UL) == 0)
#define IP_CLASSA_NET       0xff000000
#define IP_CLASSA_NSHIFT    24
#define IP_CLASSA_HOST      (0xffffffff & ~IP_CLASSA_NET)
#define IP_CLASSA_MAX       128

#define IP_CLASSB(a)        ((((ub32)(a)) & 0xc0000000UL) == 0x80000000UL)
#define IP_CLASSB_NET       0xffff0000
#define IP_CLASSB_NSHIFT    16
#define IP_CLASSB_HOST      (0xffffffff & ~IP_CLASSB_NET)
#define IP_CLASSB_MAX       65536

#define IP_CLASSC(a)        ((((ub32)(a)) & 0xe0000000UL) == 0xc0000000UL)
#define IP_CLASSC_NET       0xffffff00
#define IP_CLASSC_NSHIFT    8
#define IP_CLASSC_HOST      (0xffffffff & ~IP_CLASSC_NET)

#define IP_CLASSD(a)        (((ub32)(a) & 0xf0000000UL) == 0xe0000000UL)
#define IP_CLASSD_NET       0xf0000000          /* These ones aren't really */
#define IP_CLASSD_NSHIFT    28                  /*   net and host fields, but */
#define IP_CLASSD_HOST      0x0fffffff          /*   routing needn't know. */
#define IP_MULTICAST(a)     IP_CLASSD(a)

#define IP_EXPERIMENTAL(a)  (((ub32)(a) & 0xf0000000UL) == 0xf0000000UL)
#define IP_BADCLASS(a)      (((ub32)(a) & 0xf0000000UL) == 0xf0000000UL)

#define IP_LOOPBACKNET      127                 /* official! */

/** Get the network address by combining host address with netmask */
#define ip_addr_get_network(target, host, netmask) (target = host & netmask)

#define ip_addr_ismulticast(addr1) ((addr1 & PP_HTONL(0xf0000000UL)) == PP_HTONL(0xe0000000UL))
#define ip_addr_islinklocal(addr1) ((addr1 & PP_HTONL(0xffff0000UL)) == PP_HTONL(0xa9fe0000UL))

#define ip_addr_netcmp(addr1, addr2, mask) ((addr1 & mask) == (addr2 & mask))
#define ip_addr_cmp(addr1, addr2) (addr1 == addr2)
#define ip_addr_isany(addr1) (addr1 == IPADDR_ANY)


#define XALIGNPOINTERS_ETH(packet, ethh) { \
  (ethh) = (struct x_ethernet_hdr *)(packet); \
}

#define XALIGNPOINTERS_IP(ethh, iph) { \
  (iph) = (struct x_ipv4_hdr *) ((char *)ethh + sizeof(struct x_ethernet_hdr)); \
}

#define XALIGNPOINTERS_ARP(ethh, arph) { \
  (arph) = (struct x_arp_hdr *) ((char *)ethh + sizeof(struct x_ethernet_hdr)); \
}

#define XALIGNPOINTERS_ARP_BODY(arph, arpb) { \
  (arpb) = (struct x_arp_body *) ((char *)arph + sizeof(struct x_arp_hdr)); \
}


#define XALIGNPOINTERS_TCP(iph, tcph, pdata) { \
  (tcph) = (struct x_tcp_hdr *) (((char *) iph) + (iph->ip_hl << 2)); \
  (pdata) = ((char *) tcph) + (tcph->th_off << 2); \
}

#define XALIGNPOINTERS_UDP(iph, udph, pdata) { \
  (udph) = (struct x_udp_hdr *) (((char *) iph) + (iph->ip_hl << 2)); \
  (pdata) = ((char *) udph) + sizeof(struct x_udp_hdr); \
}

#define XALIGNPOINTERS_ICMP(iph, icmph, pdata) { \
  (icmph) = (struct x_icmpv4_hdr *) (((char *) iph) + (iph->ip_hl << 2)); \
  (pdata) = ((char *) icmph) + sizeof(struct x_icmpv4_hdr); \
}

#define XIP_DATA_LENGTH(iph) (ntohs((iph)->ip_len) - ((iph)->ip_hl << 2))
#define XTCP_DATA_LENGTH(iph, tcph) (XIP_DATA_LENGTH(iph) - ((tcph)->th_off << 2))
#define XIP_HDR_LENGTH(iph)   ((iph)->ip_hl << 2)
#define XTCP_HDR_LENGTH(tcph) ((tcph)->th_off << 2)

#define XPKT_TCP_SEQ(p) ntohl((p)->p_tcph->th_seq)
#define XPKT_TCP_ACK(p) ntohl((p)->p_tcph->th_ack)
#define XPKT_TCP_DPORT(p) ntohs((p)->p_tcph->th_dport)
#define XPKT_TCP_SPORT(p) ntohs((p)->p_tcph->th_sport)
#define XPKT_HAS_TCP_ACK(p) (p->tcph->p_th_flags & TH_ACK)

#define XPKT_TCP_PAYLOAD(p) ((u_char*)((p)->tcph) + XTCP_HDR_LEN((p)->tcph))


//#define DEFAULT_MTU 1500         /* Max Transmission Unit of standard ethernet */
//#define MAX_FRAME_LENGTH 1514    /* don't forget *frames* are MTU + L2 header! */
//#define JUMBO_FRAME 9000         /* Max Transmission Unit of  Jumbo Frame */ 
//#define JUMBO_FRAME 64000        /* Max Transmission Unit of  Jumbo Frame */ 

#define XPACKET_MAX_SNAPLEN 65535    /* capture the entire packet ether(14) + vlan(4) + mtu(1500) */

#define XPACKET_BURST_SIZE 32

#define  XPACKET_ETH    0x0001
#define  XPACKET_VLAN   0x0002
#define  XPACKET_IP     0x0004
#define  XPACKET_TCP    0x0010
#define  XPACKET_UDP    0x0020
#define  XPACKET_ICMP   0x0040
#define  XPACKET_ARP    0x0080

#define  XPACKET_OTHER  0x8000


enum XPACKET_DEFENSE {
  XPACKET_DROP    = 0x01,
  XPACKET_REJECT  = 0x02,
  XPACKET_OUT     = 0x04
};

/* packet flow control */
#define  XPACKET_ADMIN_PRIO   10000
#define  XPACKET_WEB_PRIO     20000
#define  XPACKET_TCP_PRIO     30000
#define  XPACKET_ICMP_PRIO    40000
#define  XPACKET_UDP_PRIO     50000
#define  XPACKET_OTHER_PRIO   60000

typedef struct _xpkt_cnt {
  ub64 total_pkts, total_bytes;

  ub64 pkts,  pps, max_pps;
  ub64 bytes, bps, max_bps;

  ub64 vlan_b,  vlan_p,  vlan_bps,  vlan_pps;
  ub64 ipv4_b,  ipv4_p,  ipv4_bps,  ipv4_pps;
  ub64 tcp_b,   tcp_p,   tcp_bps,   tcp_pps;
  ub64 udp_b,   udp_p,   udp_bps,   udp_pps;
  ub64 icmp_b,  icmp_p,  icmp_bps,  icmp_pps;
  ub64 arp_b,   arp_p,   arp_bps,   arp_pps;
  ub64 other_b, other_p, other_bps, other_pps;

  ub64 error_b, error_p;
  ub64 drop_b,  drop_p;

  ub64 p_77, pps_77, p_110, p_250, p_500, p_1000, p_large, p_jumbo;

  struct timeval ts;
} xpkt_cnt;


#define XETHER_ADDR_LEN      0x6
#define XDEV_NAME_LEN         32
#define XDEV_ALIAS_LEN        32
#define XDEV_OFFLINE_LEN     128
#define XDEV_MAX_NUMS        256 

typedef struct _xbridge xbridge;
typedef struct _xpacket xpacket;

typedef struct _xdevice {
  char  xdev[XDEV_NAME_LEN+1];
  char  alias[XDEV_ALIAS_LEN+1];
  /* store the mac address of each interface here to prevent loops */
  ub8   xmac[XETHER_ADDR_LEN];
  ub32  ipaddr;
  ub16  speed;
  ub8   portid;

#define XDEV_LINK_UP      0
#define XDEV_LINK_DOWN    1
#define XDEV_LINK_NOT_UP  2
  ub8   link;

#define XGW_DEV_TYPE      0x01
#define XNAT_DEV_TYPE     0x02
#define XVIRTUAL_DEV_TYPE 0x04
  ub8   type; 
  
  ub16  mtu;

  xbridge  *xb; 
  xpkt_cnt rx_pn;    /* in/out count : passive mode, in count : inline mode */
  xpkt_cnt tx_pn;    /* out count : inline mode */
} xdevice;

typedef struct _xpacket {
  struct timeval ts;

  char   *pkt_ptr;
  int     pkt_len;

  char   *data_ptr;
  int     data_len;
  ub8     pkt_type;

  xdevice  *xdev;
  xbridge  *xb; 

  ub32 src_ip,   dst_ip;
  ub16 src_port, dst_port;
  ub16 vlan_id;
  
  ub8 protocol;
  ub8  drop;

#define XPACKET_PACKET_ERROR     1
#define XPACKET_IP_ERROR         2
#define XPACKET_TCP_ERROR        3
#define XPACKET_UDP_ERROR        4
#define XPACKET_ICMP_ERROR       5
#define XPACKET_ARP_ERROR        6
#define XPACKET_IP_SUM_ERROR     7
#define XPACKET_TCP_SUM_ERROR    8
#define XPACKET_UDP_SUM_ERROR    9
#define XPACKET_ICMP_SUM_ERROR  10
#define XPACKET_IP_BYPASS       11
#define XPACKET_PKT_SIZE_ERROR  12
  ub8     error;

#define XFIRE_SEND_PACKET 0x01
  ub8  send;  /* xfire send */

  /* pointers to p_raw */
  struct x_ethernet_hdr *p_ethh;
  struct x_vlan_hdr     *p_vlanh;
  struct x_ipv4_hdr     *p_iph;
  struct x_ipv6_hdr     *p_ipv6h;
  struct x_arp_hdr      *p_arph;

  struct x_tcp_hdr      *p_tcph;
  struct x_udp_hdr      *p_udph;
  struct x_icmpv4_hdr   *p_icmph;
  struct x_icmpv6_hdr   *p_icmpv6h;
  struct x_arp_body     *p_arp_body;
  
  struct rte_mbuf *mbuf;

  char *frame; 
} _xpacket;

#define XBRIDGE_PF_RING_DEFAULT_WATERMARK  (12)
#define XBRIDGE_PF_POLL_DEFAULT_WATERMARK  (12)
#define XBRIDGE_PCAP_RING_DEFAULT_BUF_SIZE (1024 * 1024 * 1024) // 1 Mega


#define XINLIE_MODE  "inline"
#define XL3SW_MODE   "l3sw"
#define XPLB_MODE    "plb"
#define XSLB_MODE    "slb"
#define XNAT_MODE    "nat"

typedef struct _xbridge {
  xdevice xdev[XDEV_MAX_NUMS];
  ub8 xdev_num;

#define X_INLINE_MODE   0x00
#define X_L3SW_MODE     0x01
#define X_PLB_MODE      0x02
#define X_SLB_MODE      0x04
#define X_NAT_MODE      0x08
  ub8 vmode;

  xpkt_cnt rx_pn;        /* in/out count : passive mode, in count : inline mode */
  xpkt_cnt tx_pn;    /* out count : inline mode */
  
  int (*rx_packet)(xpacket *xp);
  int (*tx_packet)(xpacket *xp);

} _xbridge;


struct xbridge_eth_stats {
  uint64_t ipackets;  /**< Total number of successfully received packets. */
  uint64_t opackets;  /**< Total number of successfully transmitted packets.*/
  uint64_t ibytes;    /**< Total number of successfully received bytes. */
  uint64_t obytes;    /**< Total number of successfully transmitted bytes. */
  uint64_t imissed;
  /**< Total of RX packets dropped by the HW,
  * because there are no available buffer (i.e. RX queues are full).
  */
  uint64_t ierrors;   /**< Total number of erroneous received packets. */
  uint64_t oerrors;   /**< Total number of failed transmitted packets. */
};

#define XPACKET_DEFAULT_PACKET_SIZE  1518
#define XPACKET_MAX_PACKET_SIZE  XFIRE_MAX_SNAPLEN

#define XPACKET_DEFAULT_QUEUE_SIZE  64000
#define XPACKET_MAX_QUEUE_SIZE     640000

#define XPACKET_DEFAULT_BUFFER_SIZE  (sizeof(xpacket) + XPACKET_DEFAULT_PACKET_SIZE)
#define XPACKET_MAX_BUFFER_SIZE  (sizeof(xpacket) + XPACKET_MAX_PACKET_SIZE)

xbridge *xbridge_create (void);
void xbridge_close (xbridge *xb);
void xbridge_destroy (xbridge *xb);


void xbridge_stats (xbridge *xb, struct xbridge_eth_stats *stats);
void xbridge_dev_stats (xbridge *xb, xdevice *xdev, struct xbridge_eth_stats *stats);
void xbridge_reset_stats (xbridge *xb);

int      xbridge_set_xdevice (xbridge *xb, ub8 portid , char *dev, char *alias, ub8 *mac, ub32 speed);
xdevice *xbridge_get_xdevice (xbridge *xb, int port);


void xbridge_set_rtx_mode (xbridge *xb, int mode);

#endif


