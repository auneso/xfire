
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>

#ifndef __XPROTO_H__
#define __XPROTO_H__

#ifndef   ETHER_ADDR_LEN
#define   ETHER_ADDR_LEN      6
#endif
#define   FDDI_ADDR_LEN       6
#define   TOKEN_RING_ADDR_LEN 6
#define   X_ORG_CODE_SIZE     3


/**
 * Libnet defines header sizes for every builder function exported.
 */
#define X_802_1Q_H         0x12    /**< 802.1Q header:       18 bytes */
#define X_802_1X_H         0x04    /**< 802.1X header:        4 bytes */
#define X_802_2_H          0x03    /**< 802.2 LLC header:     3 bytes */
#define X_802_2SNAP_H      0x08    /**< 802.2 LLC/SNAP header:8 bytes */
#define X_802_3_H          0x0e    /**< 802.3 header:        14 bytes */
#define X_ARP_H            0x08    /**< ARP header w/o addrs: 8 bytes */
#define X_ARP_ETH_IP_H     0x1c    /**< ARP w/ ETH and IP:   28 bytes */
#define X_BGP4_HEADER_H    0x13    /**< BGP header:          19 bytes */
#define X_BGP4_OPEN_H      0x0a    /**< BGP open header:     10 bytes */
#define X_BGP4_UPDATE_H    0x04    /**< BGP open header:      4 bytes */
#define X_BGP4_NOTIFICATION_H 0x02 /**< BGP notif. header:    2 bytes */
#define X_CDP_H            0x08    /**< CDP header base:      8 bytes */
#define X_DHCPV4_H         0xf0    /**< DHCP v4 header:     240 bytes */
#define X_UDP_DNSV4_H      0x0c    /**< UDP DNS v4 header:   12 bytes */
#define X_TCP_DNSV4_H      0x0e    /**< TCP DNS v4 header:   14 bytes */
#define X_ETH_H            0x0e    /**< Ethernet header:     14 bytes */
#define X_ETH_MTU          1500    /**< Ethernet MTU size: 1500 bytes */
#define X_FDDI_H           0x15    /**< FDDI header:         21 bytes */
#define X_ICMPV4_H         0x04    /**< ICMP header base:     4 bytes */
#define X_ICMPV4_ECHO_H    0x08    /**< ICMP_ECHO header:     8 bytes */
#define X_ICMPV4_MASK_H    0x0c    /**< ICMP_MASK header:    12 bytes */
#define X_ICMPV4_UNREACH_H  0x08   /**< ICMP_UNREACH header:  8 bytes */
#define X_ICMPV4_TIMXCEED_H 0x08   /**< ICMP_TIMXCEED header: 8 bytes */
#define X_ICMPV4_REDIRECT_H 0x08   /**< ICMP_REDIRECT header: 8 bytes */
#define X_ICMPV4_TS_H      0x14    /**< ICMP_TIMESTAMP headr:20 bytes */
#define X_ICMPV6_H         0x08    /**< ICMP6 header base:    8 bytes */
#define X_IGMP_H           0x08    /**< IGMP header:          8 bytes */
#define X_IPV4_H           0x14    /**< IPv4 header:         20 bytes */
#define X_IPV6_H           0x28    /**< IPv6 header:         40 bytes */
#define X_IPV6_FRAG_H      0x08    /**< IPv6 frag header:     8 bytes */
#define X_IPV6_ROUTING_H   0x04    /**< IPv6 frag header base:4 bytes */
#define X_IPV6_DESTOPTS_H  0x02    /**< IPv6 dest opts base:  2 bytes */
#define X_IPV6_HBHOPTS_H   0x02    /**< IPv6 hop/hop opt base:2 bytes */
#define X_IPSEC_ESP_HDR_H  0x0c    /**< IPSEC ESP header:    12 bytes */
#define X_IPSEC_ESP_FTR_H  0x02    /**< IPSEC ESP footer:     2 bytes */
#define X_IPSEC_AH_H       0x10    /**< IPSEC AH header:     16 bytes */
#define X_ISL_H            0x1a    /**< ISL header:          26 bytes */
#define X_GRE_H            0x04    /**< GRE header:           4 bytes */
#define X_GRE_SRE_H        0x04    /**< GRE SRE header:       4 bytes */
#define X_MPLS_H           0x04    /**< MPLS header:          4 bytes */
#define X_OSPF_H           0x10    /**< OSPF header:         16 bytes */
#define X_OSPF_HELLO_H     0x18    /**< OSPF hello header:   24 bytes */
#define X_OSPF_DBD_H       0x08    /**< OSPF DBD header:      8 bytes */
#define X_OSPF_LSR_H       0x0c    /**< OSPF LSR header:     12 bytes */
#define X_OSPF_LSU_H       0x04    /**< OSPF LSU header:      4 bytes */
#define X_OSPF_LSA_H       0x14    /**< OSPF LSA header:     20 bytes */
#define X_OSPF_AUTH_H      0x08    /**< OSPF AUTH header:     8 bytes */
#define X_OSPF_CKSUM       0x10    /**< OSPF CKSUM header:   16 bytes */
#define X_OSPF_LS_RTR_H    0x10    /**< OSPF LS RTR header:  16 bytes */
#define X_OSPF_LS_NET_H    0x08    /**< OSPF LS NET header:   8 bytes */
#define X_OSPF_LS_SUM_H    0x0c    /**< OSPF LS SUM header:  12 bytes */
#define X_OSPF_LS_AS_EXT_H 0x10    /**< OSPF LS AS header:   16 bytes */
#define X_NTP_H            0x30    /**< NTP header:          48 bytes */
#define X_RIP_H            0x18    /**< RIP header base:     24 bytes */
#define X_RPC_CALL_H       0x28    /**< RPC header:          40 bytes
                                     * (assuming 8 byte auth header)
                                     */
#define X_RPC_CALL_TCP_H   0x2c    /**< RPC header:          44 bytes
                                     * (with record marking)
                                     */
#define X_SEBEK_H          0x30    /* sebek header:          48 bytes */   
#define X_STP_CONF_H       0x23    /**< STP conf header:     35 bytes */
#define X_STP_TCN_H        0x04    /**< STP tcn header:       4 bytes */
#define X_TOKEN_RING_H     0x16    /**< Token Ring header:   22 bytes */
#define X_TCP_H            0x14    /**< TCP header:          20 bytes */
#define X_UDP_H            0x08    /**< UDP header:           8 bytes */
#define X_VRRP_H           0x08    /**< VRRP header:          8 bytes */
#define X_HSRP_H           0x14    /**< HSRP header:          8 bytes */

/**
 * IEEE 802.1Q (Virtual Local Area Network) VLAN header, static header 
 * size: 8 bytes
 */
struct x_802_1q_hdr
{
    u_int8_t vlan_dhost[ETHER_ADDR_LEN];  /**< destination ethernet address */
    u_int8_t vlan_shost[ETHER_ADDR_LEN];  /**< source ethernet address */
    u_int16_t vlan_tpi;                   /**< tag protocol ID */
    u_int16_t vlan_priority_c_vid;        /**< priority | VLAN ID */
#define X_802_1Q_PRIMASK   0x0007    /**< priority mask */
#define X_802_1Q_CFIMASK   0x0001    /**< CFI mask */
#define X_802_1Q_VIDMASK   0x0fff    /**< vid mask */
    u_int16_t vlan_len;                   /**< length or type (802.3 / Eth 2) */
};  

/**
 * IEEE 802.1X EAP (Extensible Authentication Protocol) header, static header
 * size: 4 bytes
 */
struct x_802_1x_hdr
{
    u_int8_t dot1x_version;               /**< protocol version */
    u_int8_t dot1x_type;                  /**< frame type */
#define X_802_1X_PACKET    0x00      /**< 802.1x packet */
#define X_802_1X_START     0x01      /**< 802.1x start */
#define X_802_1X_LOGOFF    0x02      /**< 802.1x logoff */
#define X_802_1X_KEY       0x03      /**< 802.1x key */
#define X_802_1X_ENCASFAL  0x04      /**< 802.1x encasfal */
    u_int16_t dot1x_length;               /**< total frame length */
};  

/*
 *  IEEE 802.2 LLC header
 *  Link Layer Control
 *  static header size: 4 bytes
 */
struct x_802_2_hdr
{
    u_int8_t llc_dsap;            /* destination service access point */
    u_int8_t llc_ssap;            /* source service access point */
#define X_SAP_STP          0x42
#define X_SAP_SNAP         0xaa
    u_int16_t llc_control;         /* control field */
};


/*
 *  IEEE 802.2 LLC/SNAP header
 *  SubNetwork Attachment Point
 *  static header size: 8 bytes
 */
struct x_802_2snap_hdr
{
    u_int8_t snap_dsap;           /* destination service access point */
    u_int8_t snap_ssap;           /* destination service access point */
    u_int8_t snap_control;        /* control field */
    u_int8_t snap_oui[3];         /* OUI */
    u_int16_t snap_type;          /* type */
};


/*
 *  802.3 header
 *  IEEE Ethernet
 *  Static header size: 14 bytes
 */
struct x_802_3_hdr
{
    u_int8_t  _802_3_dhost[ETHER_ADDR_LEN];/* destination ethernet address */
    u_int8_t  _802_3_shost[ETHER_ADDR_LEN];/* source ethernet address */
    u_int16_t _802_3_len;                 /* packet type ID */
};


/* 
 *  ARP header
 *  Address Resolution Protocol
 *  Base header size: 8 bytes
 */
struct x_arp_hdr
{
    u_int16_t ar_hrd;       /* format of hardware address */
#define ARPHRD_NETROM   0   /* from KA9Q: NET/ROM pseudo */
#define ARPHRD_ETHER    1   /* Ethernet 10Mbps */
#define ARPHRD_EETHER   2   /* Experimental Ethernet */
#define ARPHRD_AX25     3   /* AX.25 Level 2 */
#define ARPHRD_PRONET   4   /* PROnet token ring */
#define ARPHRD_CHAOS    5   /* Chaosnet */
#define ARPHRD_IEEE802  6   /* IEEE 802.2 Ethernet/TR/TB */
#define ARPHRD_ARCNET   7   /* ARCnet */
#define ARPHRD_APPLETLK 8   /* APPLEtalk */
#define ARPHRD_LANSTAR  9   /* Lanstar */
#define ARPHRD_DLCI     15  /* Frame Relay DLCI */
#define ARPHRD_ATM      19  /* ATM */
#define ARPHRD_METRICOM 23  /* Metricom STRIP (new IANA id) */
#define ARPHRD_IPSEC    31  /* IPsec tunnel */
    u_int16_t ar_pro;         /* format of protocol address */
    u_int8_t  ar_hln;         /* length of hardware address */
    u_int8_t  ar_pln;         /* length of protocol addres */
    u_int16_t ar_op;          /* operation type */
#define ARPOP_REQUEST    1  /* req to resolve address */
#define ARPOP_REPLY      2  /* resp to previous request */
#define ARPOP_REVREQUEST 3  /* req protocol address given hardware */
#define ARPOP_REVREPLY   4  /* resp giving protocol address */
#define ARPOP_INVREQUEST 8  /* req to identify peer */
#define ARPOP_INVREPLY   9  /* resp identifying peer */
    /* address information allocated dynamically */
};

/*
 * Ethernet Address Resolution Protocol.
 *
 * See RFC 826 for protocol description.  Structure below is adapted
 * to resolving internet addresses.  Field names used correspond to
 * RFC 826.
 */
struct  x_arp_body {
  u_int8_t arp_sha[ETHER_ADDR_LEN];  /* sender hardware address */
  u_int8_t arp_spa[4];               /* sender protocol address */
  u_int8_t arp_tha[ETHER_ADDR_LEN];  /* target hardware address */
  u_int8_t arp_tpa[4];               /* target protocol address */
};


/*
 * BGP4 header
 * Border Gateway Protocol 4
 * Base header size : 19 bytes
 */
struct x_bgp4_header_hdr
{
#define X_BGP4_MARKER_SIZE   16
    u_int8_t marker[X_BGP4_MARKER_SIZE];
    u_int16_t len;
    u_int8_t type;
#define X_BGP4_OPEN          1
#define X_BGP4_UPDATE        2
#define X_BGP4_NOTIFICATION  3
#define X_BGP4_KEEPALIVE     4
};

/*
 * BGP4 open header
 * Border Gateway Protocol 4
 * Base header size : 10 bytes
 */
struct x_bgp4_open_hdr
{
    u_int8_t version;
    u_int16_t src_as;
    u_int16_t hold_time;
    u_int32_t bgp_id;
    u_int8_t opt_len;
};

/*
 * BGP4 notification message
 *
 * Border Gateway Protocol 4
 * Base header size : 2 bytes
 *
 * Use payload if you need data
 */
struct x_bgp4_notification_hdr
{
#define X_BGP4_MESSAGE_HEADER_ERROR  1
#define X_BGP4_OPEN_MESSAGE_ERROR    2
#define X_BGP4_UPDATE_MESSAGE_ERROR  3
#define X_BGP4_HOLD_TIMER_EXPIRED    4
#define X_BGP4_FINITE_STATE__ERROR   5
#define X_BGP4_CEASE                 6
    u_int8_t err_code;

/* Message Header Error subcodes */
#define X_BGP4_CONNECTION_NOT_SYNCHRONIZED    1
#define X_BGP4_BAD_MESSAGE_LENGTH             2
#define X_BGP4_BAD_MESSAGE_TYPE               3
/* OPEN Message Error subcodes */
#define X_BGP4_UNSUPPORTED_VERSION_NUMBER     1
#define X_BGP4_BAD_PEER_AS                    2
#define X_BGP4_BAD_BGP_IDENTIFIER             3
#define X_BGP4_UNSUPPORTED_OPTIONAL_PARAMETER 4
#define X_BGP4_AUTHENTICATION_FAILURE         5
#define X_BGP4_UNACCEPTABLE_HOLD_TIME         6
/* UPDATE Message Error subcodes */
#define X_BGP4_MALFORMED_ATTRIBUTE_LIST
#define X_BGP4_UNRECOGNIZED_WELL_KNOWN_ATTRIBUTE
#define X_BGP4_MISSING_WELL_KNOWN_ATTRIBUTE
#define X_BGP4_ATTRIBUTE_FLAGS_ERROR
#define X_BGP4_ATTRIBUTE_LENGTH_ERROR
#define X_BGP4_INVALID_ORIGIN_ATTRIBUTE
#define X_BGP4_AS_ROUTING_LOOP
#define X_BGP4_INVALID_NEXT_HOP_ATTRIBUTE
#define X_BGP4_OPTIONAL_ATTRIBUTE_ERROR
#define X_BGP4_INVALID_NETWORK_FIELD
#define X_BGP4_MALFORMED_AS_PATH
    u_int8_t err_subcode;
};



/*
 *  CDP header
 *  Cisco Discovery Protocol
 *  Base header size: 8 bytes
 */

/*
 *  For checksum stuff -- IANA says 135-254 is "unassigned" as of 12.2001.
 *  Let's hope this one stays that way for a while!
 */
#define X_PROTO_CDP    200
struct x_cdp_hdr
{
    u_int8_t cdp_version;     /* version (should always be 0x01) */
    u_int8_t cdp_ttl;         /* time reciever should hold info in this packet */
    u_int16_t cdp_sum;        /* checksum */
    u_int16_t cdp_type;       /* type */
#define X_CDP_DEVID    0x1 /* device id */
#define X_CDP_ADDRESS  0x2 /* address */
#define X_CDP_PORTID   0x3 /* port id */
#define X_CDP_CAPABIL  0x4 /* capabilities */
#define X_CDP_VERSION  0x5 /* version */
#define X_CDP_PLATFORM 0x6 /* platform */
#define X_CDP_IPPREFIX 0x7 /* ip prefix */
    u_int16_t cdp_len;        /* type + length + value */
    /* value information done dynamically */

/* CDP capabilities */
#define X_CDP_CAP_L3R   0x01 /* performs level 3 routing */
#define X_CDP_CAP_L2B   0x02 /* performs level 2 transparent bridging */
#define X_CDP_CAP_L2SRB 0x04 /* performs level 2 sourceroute bridging */
#define X_CDP_CAP_L2S   0x08 /* performs level 2 switching */
#define X_CDP_CAP_SR    0x10 /* sends and recieves packets on a network */
#define X_CDP_CAP_NOI   0x20 /* does not forward IGMP on non-router ports */
#define X_CDP_CAP_L1F   0x40 /* provides level 1 functionality */
};


/*
 *  Used as an overlay for type/len/values
 */
struct x_cdp_value_hdr
{
    u_int16_t cdp_type;
    u_int16_t cdp_len;
};


/*
 *  DHCP header
 *  Dynamic Host Configuration Protocol
 *  Static header size: f0 bytes
 */
struct x_dhcpv4_hdr
{
    u_int8_t dhcp_opcode;     /* opcode */
#define X_DHCP_REQUEST 0x1
#define X_DHCP_REPLY   0x2
    u_int8_t dhcp_htype;      /* hardware address type */
    u_int8_t dhcp_hlen;       /* hardware address length */
    u_int8_t dhcp_hopcount;   /* used by proxy servers */
    u_int32_t dhcp_xid;       /* transaction ID */
    u_int16_t dhcp_secs;      /* number of seconds since trying to bootstrap */
    u_int16_t dhcp_flags;     /* flags for DHCP, unused for BOOTP */
    u_int32_t dhcp_cip;       /* client's IP */
    u_int32_t dhcp_yip;       /* your IP */
    u_int32_t dhcp_sip;       /* server's IP */
    u_int32_t dhcp_gip;       /* gateway IP */
    u_int8_t dhcp_chaddr[16]; /* client hardware address */
    u_int8_t dhcp_sname[64];  /* server host name */
    u_int8_t dhcp_file[128];  /* boot file name */
    u_int32_t dhcp_magic;     /* BOOTP magic header */
#define DHCP_MAGIC                  0x63825363
#define X_BOOTP_MIN_LEN        0x12c
#define X_DHCP_PAD             0x00
#define X_DHCP_SUBNETMASK      0x01
#define X_DHCP_TIMEOFFSET      0x02
#define X_DHCP_ROUTER          0x03
#define X_DHCP_TIMESERVER      0x04
#define X_DHCP_NAMESERVER      0x05
#define X_DHCP_DNS             0x06
#define X_DHCP_LOGSERV         0x07
#define X_DHCP_COOKIESERV      0x08
#define X_DHCP_LPRSERV         0x09
#define X_DHCP_IMPSERV         0x0a
#define X_DHCP_RESSERV         0x0b
#define X_DHCP_HOSTNAME        0x0c
#define X_DHCP_BOOTFILESIZE    0x0d
#define X_DHCP_DUMPFILE        0x0e
#define X_DHCP_DOMAINNAME      0x0f
#define X_DHCP_SWAPSERV        0x10
#define X_DHCP_ROOTPATH        0x11
#define X_DHCP_EXTENPATH       0x12
#define X_DHCP_IPFORWARD       0x13
#define X_DHCP_SRCROUTE        0x14
#define X_DHCP_POLICYFILTER    0x15
#define X_DHCP_MAXASMSIZE      0x16
#define X_DHCP_IPTTL           0x17
#define X_DHCP_MTUTIMEOUT      0x18
#define X_DHCP_MTUTABLE        0x19
#define X_DHCP_MTUSIZE         0x1a
#define X_DHCP_LOCALSUBNETS    0x1b
#define X_DHCP_BROADCASTADDR   0x1c
#define X_DHCP_DOMASKDISCOV    0x1d
#define X_DHCP_MASKSUPPLY      0x1e
#define X_DHCP_DOROUTEDISC     0x1f
#define X_DHCP_ROUTERSOLICIT   0x20
#define X_DHCP_STATICROUTE     0x21
#define X_DHCP_TRAILERENCAP    0x22
#define X_DHCP_ARPTIMEOUT      0x23
#define X_DHCP_ETHERENCAP      0x24
#define X_DHCP_TCPTTL          0x25
#define X_DHCP_TCPKEEPALIVE    0x26
#define X_DHCP_TCPALIVEGARBAGE 0x27
#define X_DHCP_NISDOMAIN       0x28
#define X_DHCP_NISSERVERS      0x29
#define X_DHCP_NISTIMESERV     0x2a
#define X_DHCP_VENDSPECIFIC    0x2b
#define X_DHCP_NBNS            0x2c
#define X_DHCP_NBDD            0x2d
#define X_DHCP_NBTCPIP         0x2e
#define X_DHCP_NBTCPSCOPE      0x2f
#define X_DHCP_XFONT           0x30
#define X_DHCP_XDISPLAYMGR     0x31
#define X_DHCP_DISCOVERADDR    0x32
#define X_DHCP_LEASETIME       0x33
#define X_DHCP_OPTIONOVERLOAD  0x34
#define X_DHCP_MESSAGETYPE     0x35
#define X_DHCP_SERVIDENT       0x36
#define X_DHCP_PARAMREQUEST    0x37
#define X_DHCP_MESSAGE         0x38
#define X_DHCP_MAXMSGSIZE      0x39
#define X_DHCP_RENEWTIME       0x3a
#define X_DHCP_REBINDTIME      0x3b
#define X_DHCP_CLASSSID        0x3c
#define X_DHCP_CLIENTID        0x3d
#define X_DHCP_NISPLUSDOMAIN   0x40
#define X_DHCP_NISPLUSSERVERS  0x41
#define X_DHCP_MOBILEIPAGENT   0x44
#define X_DHCP_SMTPSERVER      0x45
#define X_DHCP_POP3SERVER      0x46
#define X_DHCP_NNTPSERVER      0x47
#define X_DHCP_WWWSERVER       0x48
#define X_DHCP_FINGERSERVER    0x49
#define X_DHCP_IRCSERVER       0x4a
#define X_DHCP_STSERVER        0x4b
#define X_DHCP_STDASERVER      0x4c
#define X_DHCP_END             0xff

#define X_DHCP_MSGDISCOVER     0x01
#define X_DHCP_MSGOFFER        0x02
#define X_DHCP_MSGREQUEST      0x03
#define X_DHCP_MSGDECLINE      0x04
#define X_DHCP_MSGACK          0x05
#define X_DHCP_MSGNACK         0x06
#define X_DHCP_MSGRELEASE      0x07
#define X_DHCP_MSGINFORM       0x08
};


/*
 *  Base DNSv4 header
 *  Domain Name System
 *  Base header size: 12/14 bytes
 */
struct x_dnsv4_hdr
{
    u_int16_t h_len;          /* length of the packet - only used with TCP */
    u_int16_t id;             /* DNS packet ID */
    u_int16_t flags;          /* DNS flags */
    u_int16_t num_q;          /* Number of questions */
    u_int16_t num_answ_rr;    /* Number of answer resource records */
    u_int16_t num_auth_rr;    /* Number of authority resource records */
    u_int16_t num_addi_rr;    /* Number of additional resource records */
};

#define X_DNS_H X_UDP_DNSV4_H
struct x_dnsv4udp_hdr
{
    u_int16_t id;             /* DNS packet ID */
    u_int16_t flags;          /* DNS flags */
    u_int16_t num_q;          /* Number of questions */
    u_int16_t num_answ_rr;    /* Number of answer resource records */
    u_int16_t num_auth_rr;    /* Number of authority resource records */
    u_int16_t num_addi_rr;    /* Number of additional resource records */
};

#define VTH_PRIORITY(vh)  ((ntohs((vh)->h_vlan_TCI) & 0xe000) >> 13)
#define VTH_CFI(vh)       ((ntohs((vh)->h_vlan_TCI) & 0x1000) >> 12)
#define VTH_VLAN(vh)      ((uint16_t)(ntohs((vh)->h_vlan_TCI) & 0x0FFF))

struct x_vlan_hdr {
  uint16_t h_vlan_TCI;
  uint16_t h_vlan_proto;
}; 

/*
 *  Ethernet II header
 *  Static header size: 14 bytes
 */
struct x_ethernet_hdr
{
    u_int8_t  ether_dhost[ETHER_ADDR_LEN];/* destination ethernet address */
    u_int8_t  ether_shost[ETHER_ADDR_LEN];/* source ethernet address */
    u_int16_t ether_type;                 /* protocol */
};

#ifndef ETHERTYPE_PUP
#define ETHERTYPE_PUP           0x0200  /* PUP protocol */
#endif

#ifndef ETHERTYPE_IP
#define ETHERTYPE_IP            0x0800  /* IP protocol */
#endif

#ifndef ETHERTYPE_ARP
#define ETHERTYPE_ARP           0x0806  /* addr. resolution protocol */
#endif

#ifndef ETHERTYPE_REVARP
#define ETHERTYPE_REVARP        0x8035  /* reverse addr. resolution protocol */
#endif

#ifndef ETHERTYPE_VLAN
#define ETHERTYPE_VLAN          0x8100  /* IEEE 802.1Q VLAN tagging */
#endif

#ifndef ETHERTYPE_VLAN2
#define ETHERTYPE_VLAN2         0x88a8  /* IEEE 802.1ad, double-tagging */
#endif

#ifndef ETHERTYPE_EAP
#define ETHERTYPE_EAP           0x888e  /* IEEE 802.1X EAP authentication */
#endif

#ifndef ETHERTYPE_MPLS
#define ETHERTYPE_MPLS          0x8847  /* MPLS */
#endif

#ifndef ETHERTYPE_LOOPBACK
#define ETHERTYPE_LOOPBACK      0x9000  /* used to test interfaces */
#endif

#ifndef ETHERTYPE_IP6
#define ETHERTYPE_IP6           0x86DD /* IPv6 */
#endif

/* see:
        http://en.wikipedia.org/wiki/IEEE_802.1Q
    and http://en.wikipedia.org/wiki/QinQ
*/
#ifndef ETHERTYPE_8021Q9100
#define ETHERTYPE_8021Q9100     0x9100
#endif
#ifndef ETHERTYPE_8021Q9200
#define ETHERTYPE_8021Q9200     0x9200
#endif
#ifndef ETHERTYPE_8021QinQ
#define ETHERTYPE_8021QinQ      0x88a8
#endif
#ifndef ETHERTYPE_IPX
#define ETHERTYPE_IPX           0x8137
#endif
#ifndef ETHERTYPE_IPV6
#define ETHERTYPE_IPV6          0x86dd
#endif
#ifndef ETHERTYPE_PPP
#define ETHERTYPE_PPP           0x880b
#endif
#ifndef ETHERTYPE_MPCP
#define ETHERTYPE_MPCP          0x8808
#endif
#ifndef ETHERTYPE_SLOW
#define ETHERTYPE_SLOW          0x8809
#endif
#ifndef ETHERTYPE_MPLS
#define ETHERTYPE_MPLS          0x8847
#endif
#ifndef ETHERTYPE_MPLS_MULTI
#define ETHERTYPE_MPLS_MULTI    0x8848
#endif
#ifndef ETHERTYPE_PPPOED
#define ETHERTYPE_PPPOED        0x8863
#endif
#ifndef ETHERTYPE_PPPOES
#define ETHERTYPE_PPPOES        0x8864
#endif
#ifndef ETHERTYPE_PPPOED2
#define ETHERTYPE_PPPOED2       0x3c12
#endif
#ifndef ETHERTYPE_PPPOES2
#define ETHERTYPE_PPPOES2       0x3c13
#endif
#ifndef ETHERTYPE_MS_NLB_HB
#define ETHERTYPE_MS_NLB_HB     0x886f /* MS Network Load Balancing Heartbeat */
#endif
#ifndef ETHERTYPE_JUMBO
#define ETHERTYPE_JUMBO         0x8870
#endif
#ifndef ETHERTYPE_LLDP
#define ETHERTYPE_LLDP          0x88cc
#endif
#ifndef ETHERTYPE_EAPOL
#define ETHERTYPE_EAPOL         0x888e
#endif
#ifndef ETHERTYPE_RRCP
#define ETHERTYPE_RRCP          0x8899
#endif
#ifndef ETHERTYPE_LOOPBACK
#define ETHERTYPE_LOOPBACK      0x9000
#endif
#ifndef ETHERTYPE_VMAN
#define ETHERTYPE_VMAN          0x9100 /* Extreme VMAN Protocol */
#endif
#ifndef ETHERTYPE_CFM_OLD
#define ETHERTYPE_CFM_OLD       0xabcd /* 802.1ag depreciated */
#endif
#ifndef ETHERTYPE_CFM
#define ETHERTYPE_CFM           0x8902 /* 802.1ag */
#endif
#ifndef ETHERTYPE_ISO
#define ETHERTYPE_ISO           0xfefe  /* nonstandard - used in Cisco HDLC encapsulation */
#endif
#ifndef ETHERTYPE_CALM_FAST
#define ETHERTYPE_CALM_FAST     0x1111  /* ISO CALM FAST */
#endif
#ifndef ETHERTYPE_GEONET_OLD
#define ETHERTYPE_GEONET_OLD    0x0707  /* ETSI GeoNetworking (before Jan 2013) */
#endif
#ifndef ETHERTYPE_GEONET
#define ETHERTYPE_GEONET        0x8947  /* ETSI GeoNetworking (Official IEEE registration from Jan 2013) */
#endif



struct x_ether_addr
{
    u_int8_t  ether_addr_octet[6];        /* Ethernet address */
};

/*
 *  Fiber Distributed Data Interface header
 *
 *  Static header size: 21 bytes (LLC and 48-bit address addr only)
 *
 *  Note: Organization field is 3 bytes which throws off the
 *        alignment of type.  Therefore fddi_type (19 bytes in) 
 *        is specified as two u_int8_ts.
 */
struct x_fddi_hdr
{
    u_int8_t  fddi_frame_control;                      /* Class/Format/Priority */
#define X_FDDI_LLC_FRAME  0x10
#define X_FDDI_48BIT_ADDR 0x40
#define X_FDDI_FC_REQD    X_FDDI_LLC_FRAME | X_FDDI_48BIT_ADDR 
    u_int8_t  fddi_dhost[FDDI_ADDR_LEN];               /* destination fddi address */
    u_int8_t  fddi_shost[FDDI_ADDR_LEN];               /* source fddi address */
    u_int8_t  fddi_llc_dsap;                           /* DSAP */
    u_int8_t  fddi_llc_ssap;                           /* SSAP */
    u_int8_t  fddi_llc_control_field;                  /* Class/Format/Priority */
    u_int8_t  fddi_llc_org_code[X_ORG_CODE_SIZE]; /* Organization Code 3-bytes */
    u_int8_t  fddi_type;                               /* Protocol Type */
    u_int8_t  fddi_type1;                              /* see note above. */
#define FDDI_TYPE_IP            0x0800  /* IP protocol */
#define FDDI_TYPE_ARP           0x0806  /* addr. resolution protocol */
#define FDDI_TYPE_REVARP        0x8035  /* reverse addr. resolution protocol */
};


struct x_fddi_addr
{
    u_int8_t  fddi_addr_octet[6];        /* FDDI address */
};


/*
 * GRE header - RFC 1701 & 2637
 * Generic Routing Encapsulation (GRE) 
 * Base header size: 4 bytes
 */
struct x_gre_hdr
{
    u_int16_t flags_ver;
#define GRE_CSUM	                        0x8000
#define GRE_ROUTING	                        0x4000
#define GRE_KEY		                        0x2000
#define GRE_SEQ		                        0x1000
#define GRE_STRICT	                        0x0800
#define GRE_REC		                        0x0700
#define GRE_ACK		                        0x0080

#define GRE_FLAGS_MASK	                        0x00F8
#define GRE_VERSION_MASK                        0x0007

#define GRE_VERSION_0                           0x0000
#define GRE_VERSION_1                           0x0001

    u_int16_t type;
#define GRE_SNA                                 0x0004
#define GRE_OSI_NETWORK_LAYER                   0x00FE
#define GRE_PUP                                 0x0200
#define GRE_XNS                                 0x0600
#define GRE_IP                                  0x0800
#define GRE_CHAOS                               0x0804
#define GRE_RFC_826_ARP                         0x0806
#define GRE_FRAME_RELAY_ARP                     0x0808
#define GRE_VINES                               0x0BAD
#define GRE_VINES_ECHO                          0x0BAE
#define GRE_VINES_LOOPBACK                      0x0BAF
#define GRE_DECNET                              0x6003
#define GRE_TRANSPARENT_ETHERNET_BRIDGING       0x6558
#define GRE_RAW_FRAME_RELAY                     0x6559
#define GRE_APOLLO_DOMAIN                       0x8019
#define GRE_ETHERTALK                           0x809B
#define GRE_NOVELL_IPX                          0x8137
#define GRE_RFC_1144_TCP_IP_COMPRESSION         0x876B
#define GRE_IP_AUTONOMOUS_SYSTEMS               0x876C
#define GRE_SECURE_DATA                         0x876D
#define GRE_PPP                                 0x880b /* taken from RFC 2637 */

    union {
	struct {
	    u_int16_t sum;       /* optional */
	    u_int16_t offset;    /* optional */
	    u_int32_t key;       /* optional */
	    u_int32_t seq;       /* optional */
	} _gre;

	struct {
	    u_int16_t payload_s; /* optional */
	    u_int16_t callID;    /* optional */
	    u_int32_t seq;       /* optional */
	    u_int32_t ack;       /* optional */
	} _egre;
    }_data;

#define gre_sum _data._gre.sum
#define gre_offset _data._gre.offset
#define gre_key _data._gre.key
#define gre_seq _data._gre.seq

#define egre_payload_s _data._egre.payload_s
#define egre_callID _data._egre.callID
#define egre_seq _data._egre.seq
#define egre_ack _data._egre.ack
};


#ifndef IPPROTO_GRE
#define IPPROTO_GRE 47
#endif

/*
 * Source Route Entries (SRE)
 * This is used for GRE as the Routing field is a list of SREs - RFC 1701
 * Base header size: 4 bytes
 */
struct x_gre_sre_hdr
{
    u_int16_t af;  /* address familly */
    u_int8_t sre_offset;
    u_int8_t sre_length;
    u_int8_t *routing;
};

#define XIN_CLASSA(a)            ((((u_int32_t)(a)) & 0x80000000) == 0)
#define XIN_CLASSA_NET           0xff000000
#define XIN_CLASSA_NSHIFT        24
#define XIN_CLASSA_HOST          (0xffffffff & ~XIN_CLASSA_NET)
#define XIN_CLASSA_MAX           128

#define XIN_CLASSB(a)            ((((u_int32_t)(a)) & 0xc0000000) == 0x80000000)
#define XIN_CLASSB_NET           0xffff0000
#define XIN_CLASSB_NSHIFT        16
#define XIN_CLASSB_HOST          (0xffffffff & ~XIN_CLASSB_NET)
#define XIN_CLASSB_MAX           65536

#define XIN_CLASSC(a)            ((((u_int32_t)(a)) & 0xe0000000) == 0xc0000000)
#define XIN_CLASSC_NET           0xffffff00
#define XIN_CLASSC_NSHIFT        8
#define XIN_CLASSC_HOST          (0xffffffff & ~XIN_CLASSC_NET)

#define XIN_CLASSD(a)            ((((u_int32_t)(a)) & 0xf0000000) == 0xe0000000)
#define XIN_MULTICAST(a)         XIN_CLASSD(a)

/*
 *  IPv4 header
 *  Internet Protocol, version 4
 *  Static header size: 20 bytes
 */
struct x_ipv4_hdr
{
#ifdef WORDS_BIGENDIAN
    u_int8_t ip_v:4,        /* version */
             ip_hl:4;       /* header length */
#else
    u_int8_t ip_hl:4,       /* header length */
             ip_v:4;        /* version */
#endif

    u_int8_t ip_tos;        /* type of service */
#ifndef IPTOS_LOWDELAY
#define IPTOS_LOWDELAY      0x10
#endif
#ifndef IPTOS_THROUGHPUT
#define IPTOS_THROUGHPUT    0x08
#endif
#ifndef IPTOS_RELIABILITY
#define IPTOS_RELIABILITY   0x04
#endif
#ifndef IPTOS_LOWCOST
#define IPTOS_LOWCOST       0x02
#endif
    u_int16_t ip_len;         /* total length */
    u_int16_t ip_id;          /* identification */
    u_int16_t ip_off;
#ifndef IP_RF
#define IP_RF 0x8000        /* reserved fragment flag */
#endif
#ifndef IP_DF
#define IP_DF 0x4000        /* dont fragment flag */
#endif
#ifndef IP_MF
#define IP_MF 0x2000        /* more fragments flag */
#endif 
#ifndef IP_OFFMASK
#define IP_OFFMASK 0x1fff   /* mask for fragmenting bits */
#endif
    u_int8_t  ip_ttl;         /* time to live */
    u_int8_t  ip_p;           /* protocol */
    u_int16_t ip_sum;         /* checksum */
    u_int32_t ip_src, ip_dst; /* source and dest address */
};

/*
 *  IP options
 */
#ifndef IPOPT_EOL
#define IPOPT_EOL       0   /* end of option list */
#endif
#ifndef IPOPT_NOP
#define IPOPT_NOP       1   /* no operation */
#endif   
#ifndef IPOPT_RR
#define IPOPT_RR        7   /* record packet route */
#endif
#ifndef IPOPT_TS
#define IPOPT_TS        68  /* timestamp */
#endif
#ifndef IPOPT_SECURITY
#define IPOPT_SECURITY  130 /* provide s,c,h,tcc */   
#endif
#ifndef IPOPT_LSRR
#define IPOPT_LSRR      131 /* loose source route */
#endif
#ifndef IPOPT_SATID
#define IPOPT_SATID     136 /* satnet id */
#endif
#ifndef IPOPT_SSRR
#define IPOPT_SSRR      137 /* strict source route */
#endif


/*
 * Type of service (ip_tos), RFC 1349 ("obsoleted by RFC 2474")
 */
#define IP_TOS_DEFAULT          0x00    /* default */
#define IP_TOS_LOWDELAY         0x10    /* low delay */
#define IP_TOS_THROUGHPUT       0x08    /* high throughput */
#define IP_TOS_RELIABILITY      0x04    /* high reliability */
#define IP_TOS_LOWCOST          0x02    /* low monetary cost - XXX */
#define IP_TOS_ECT              0x02    /* ECN-capable transport */
#define IP_TOS_CE               0x01    /* congestion experienced */

/*
 * IP precedence (high 3 bits of ip_tos), hopefully unused
 */
#define IP_TOS_PREC_ROUTINE             0x00
#define IP_TOS_PREC_PRIORITY            0x20
#define IP_TOS_PREC_IMMEDIATE           0x40
#define IP_TOS_PREC_FLASH               0x60
#define IP_TOS_PREC_FLASHOVERRIDE       0x80
#define IP_TOS_PREC_CRITIC_ECP          0xa0
#define IP_TOS_PREC_INTERNETCONTROL     0xc0
#define IP_TOS_PREC_NETCONTROL          0xe0

/*
 * Time-to-live (ip_ttl), seconds
 */
#define IP_TTL_DEFAULT  64              /* default ttl, RFC 1122, RFC 1340 */
#define IP_TTL_MAX      255             /* maximum ttl */

/*
 * Protocol (ip_p) - http://www.iana.org/assignments/protocol-numbers
 */
#define IP_PROTO_IP             0               /* dummy for IP */
#define IP_PROTO_HOPOPTS        IP_PROTO_IP     /* IPv6 hop-by-hop options */
#define IP_PROTO_ICMP           1               /* ICMP */
#define IP_PROTO_IGMP           2               /* IGMP */
#define IP_PROTO_GGP            3               /* gateway-gateway protocol */
#define IP_PROTO_IPIP           4               /* IP in IP */
#define IP_PROTO_ST             5               /* ST datagram mode */
#define IP_PROTO_TCP            6               /* TCP */
#define IP_PROTO_CBT            7               /* CBT */
#define IP_PROTO_EGP            8               /* exterior gateway protocol */
#define IP_PROTO_IGP            9               /* interior gateway protocol */
#define IP_PROTO_BBNRCC         10              /* BBN RCC monitoring */
#define IP_PROTO_NVP            11              /* Network Voice Protocol */
#define IP_PROTO_PUP            12              /* PARC universal packet */
#define IP_PROTO_ARGUS          13              /* ARGUS */
#define IP_PROTO_EMCON          14              /* EMCON */
#define IP_PROTO_XNET           15              /* Cross Net Debugger */
#define IP_PROTO_CHAOS          16              /* Chaos */
#define IP_PROTO_UDP            17              /* UDP */
#define IP_PROTO_MUX            18              /* multiplexing */
#define IP_PROTO_DCNMEAS        19              /* DCN measurement */
#define IP_PROTO_HMP            20              /* Host Monitoring Protocol */
#define IP_PROTO_PRM            21              /* Packet Radio Measurement */
#define IP_PROTO_IDP            22              /* Xerox NS IDP */
#define IP_PROTO_TRUNK1         23              /* Trunk-1 */
#define IP_PROTO_TRUNK2         24              /* Trunk-2 */
#define IP_PROTO_LEAF1          25              /* Leaf-1 */
#define IP_PROTO_LEAF2          26              /* Leaf-2 */
#define IP_PROTO_RDP            27              /* "Reliable Datagram" proto */
#define IP_PROTO_IRTP           28              /* Inet Reliable Transaction */
#define IP_PROTO_TP             29              /* ISO TP class 4 */
#define IP_PROTO_NETBLT         30              /* Bulk Data Transfer */
#define IP_PROTO_MFPNSP         31              /* MFE Network Services */
#define IP_PROTO_SEP            33              /* Sequential Exchange proto */
#define IP_PROTO_3PC            34              /* Third Party Connect proto */
#define IP_PROTO_IDPR           35              /* Interdomain Policy Route */
#define IP_PROTO_XTP            36              /* Xpress Transfer Protocol */
#define IP_PROTO_DDP            37              /* Datagram Delivery Proto */
#define IP_PROTO_CMTP           38              /* IDPR Ctrl Message Trans */
#define IP_PROTO_TPPP           39              /* TP++ Transport Protocol */
#define IP_PROTO_IL             40              /* IL Transport Protocol */
#define IP_PROTO_IPV6           41              /* IPv6 */
#define IP_PROTO_SDRP           42              /* Source Demand Routing */
#define IP_PROTO_ROUTING        43              /* IPv6 routing header */
#define IP_PROTO_FRAGMENT       44              /* IPv6 fragmentation header */
#define IP_PROTO_RSVP           46              /* Reservation protocol */
#define IP_PROTO_GRE            47              /* General Routing Encap */
#define IP_PROTO_MHRP           48              /* Mobile Host Routing */
#define IP_PROTO_ENA            49              /* ENA */
#define IP_PROTO_ESP            50              /* Encap Security Payload */
#define IP_PROTO_AH             51              /* Authentication Header */
#define IP_PROTO_INLSP          52              /* Integated Net Layer Sec */
#define IP_PROTO_SWIPE          53              /* SWIPE */
#define IP_PROTO_NARP           54              /* NBMA Address Resolution */
#define IP_PROTO_MOBILE         55              /* Mobile IP, RFC 2004 */
#define IP_PROTO_TLSP           56              /* Transport Layer Security */
#define IP_PROTO_SKIP           57              /* SKIP */
#define IP_PROTO_ICMPV6         58              /* ICMP for IPv6 */
#define IP_PROTO_NONE           59              /* IPv6 no next header */
#define IP_PROTO_DSTOPTS        60              /* IPv6 destination options */
#define IP_PROTO_ANYHOST        61              /* any host internal proto */
#define IP_PROTO_CFTP           62              /* CFTP */
#define IP_PROTO_ANYNET         63              /* any local network */
#define IP_PROTO_EXPAK          64              /* SATNET and Backroom EXPAK */
#define IP_PROTO_KRYPTOLAN      65              /* Kryptolan */
#define IP_PROTO_RVD            66              /* MIT Remote Virtual Disk */
#define IP_PROTO_IPPC           67              /* Inet Pluribus Packet Core */
#define IP_PROTO_DISTFS         68              /* any distributed fs */
#define IP_PROTO_SATMON         69              /* SATNET Monitoring */
#define IP_PROTO_VISA           70              /* VISA Protocol */
#define IP_PROTO_IPCV           71              /* Inet Packet Core Utility */
#define IP_PROTO_CPNX           72              /* Comp Proto Net Executive */
#define IP_PROTO_CPHB           73              /* Comp Protocol Heart Beat */
#define IP_PROTO_WSN            74              /* Wang Span Network */
#define IP_PROTO_PVP            75              /* Packet Video Protocol */
#define IP_PROTO_BRSATMON       76              /* Backroom SATNET Monitor */
#define IP_PROTO_SUNND          77              /* SUN ND Protocol */
#define IP_PROTO_WBMON          78              /* WIDEBAND Monitoring */
#define IP_PROTO_WBEXPAK        79              /* WIDEBAND EXPAK */
#define IP_PROTO_EON            80              /* ISO CNLP */
#define IP_PROTO_VMTP           81              /* Versatile Msg Transport*/
#define IP_PROTO_SVMTP          82              /* Secure VMTP */
#define IP_PROTO_VINES          83              /* VINES */
#define IP_PROTO_TTP            84              /* TTP */
#define IP_PROTO_NSFIGP         85              /* NSFNET-IGP */
#define IP_PROTO_DGP            86              /* Dissimilar Gateway Proto */
#define IP_PROTO_TCF            87              /* TCF */
#define IP_PROTO_EIGRP          88              /* EIGRP */
#define IP_PROTO_OSPF           89              /* Open Shortest Path First */
#define IP_PROTO_SPRITERPC      90              /* Sprite RPC Protocol */
#define IP_PROTO_LARP           91              /* Locus Address Resolution */
#define IP_PROTO_MTP            92              /* Multicast Transport Proto */
#define IP_PROTO_AX25           93              /* AX.25 Frames */
#define IP_PROTO_IPIPENCAP      94              /* yet-another IP encap */
#define IP_PROTO_MICP           95              /* Mobile Internet Ctrl */
#define IP_PROTO_SCCSP          96              /* Semaphore Comm Sec Proto */
#define IP_PROTO_ETHERIP        97              /* Ethernet in IPv4 */
#define IP_PROTO_ENCAP          98              /* encapsulation header */
#define IP_PROTO_ANYENC         99              /* private encryption scheme */
#define IP_PROTO_GMTP           100             /* GMTP */
#define IP_PROTO_IFMP           101             /* Ipsilon Flow Mgmt Proto */
#define IP_PROTO_PNNI           102             /* PNNI over IP */
#define IP_PROTO_PIM            103             /* Protocol Indep Multicast */
#define IP_PROTO_ARIS           104             /* ARIS */
#define IP_PROTO_SCPS           105             /* SCPS */
#define IP_PROTO_QNX            106             /* QNX */
#define IP_PROTO_AN             107             /* Active Networks */
#define IP_PROTO_IPCOMP         108             /* IP Payload Compression */
#define IP_PROTO_SNP            109             /* Sitara Networks Protocol */
#define IP_PROTO_COMPAQPEER     110             /* Compaq Peer Protocol */
#define IP_PROTO_IPXIP          111             /* IPX in IP */
#define IP_PROTO_VRRP           112             /* Virtual Router Redundancy */
#define IP_PROTO_PGM            113             /* PGM Reliable Transport */
#define IP_PROTO_ANY0HOP        114             /* 0-hop protocol */
#define IP_PROTO_L2TP           115             /* Layer 2 Tunneling Proto */
#define IP_PROTO_DDX            116             /* D-II Data Exchange (DDX) */
#define IP_PROTO_IATP           117             /* Interactive Agent Xfer */
#define IP_PROTO_STP            118             /* Schedule Transfer Proto */
#define IP_PROTO_SRP            119             /* SpectraLink Radio Proto */
#define IP_PROTO_UTI            120             /* UTI */
#define IP_PROTO_SMP            121             /* Simple Message Protocol */
#define IP_PROTO_SM             122             /* SM */
#define IP_PROTO_PTP            123             /* Performance Transparency */
#define IP_PROTO_ISIS           124             /* ISIS over IPv4 */
#define IP_PROTO_FIRE           125             /* FIRE */
#define IP_PROTO_CRTP           126             /* Combat Radio Transport */
#define IP_PROTO_CRUDP          127             /* Combat Radio UDP */
#define IP_PROTO_SSCOPMCE       128             /* SSCOPMCE */
#define IP_PROTO_IPLT           129             /* IPLT */
#define IP_PROTO_SPS            130             /* Secure Packet Shield */
#define IP_PROTO_PIPE           131             /* Private IP Encap in IP */
#define IP_PROTO_SCTP           132             /* Stream Ctrl Transmission */
#define IP_PROTO_FC             133             /* Fibre Channel */
#define IP_PROTO_RSVPIGN        134             /* RSVP-E2E-IGNORE */
#define IP_PROTO_RAW            255             /* Raw IP packets */
#define IP_PROTO_RESERVED       IP_PROTO_RAW    /* Reserved */
#define IP_PROTO_MAX            255


#define IP6_ADDR_LEN    16
#define IP6_ADDR_BITS   128

#define IP6_HDR_LEN     40              /* IPv6 header length */
#define IP6_LEN_MIN     IP6_HDR_LEN
#define IP6_LEN_MAX     65535           /* non-jumbo payload */

#define IP6_MTU_MIN     1280            /* minimum MTU (1024 + 256) */

typedef struct ip6_addr {
  uint8_t         data[IP6_ADDR_LEN];
} ip6_addr_t;

/*
 * IPv6 header
 */
struct ip6_hdr {
  union {
    struct ip6_hdr_ctl {
      uint32_t        ip6_un1_flow; /* 20 bits of flow ID */
      uint16_t        ip6_un1_plen; /* payload length */
      uint8_t         ip6_un1_nxt;  /* next header */
      uint8_t         ip6_un1_hlim; /* hop limit */
    } ip6_un1;
    uint8_t ip6_un2_vfc;    /* 4 bits version, top 4 bits class */
  } ip6_ctlun;
  ip6_addr_t      ip6_src;
  ip6_addr_t      ip6_dst;
} __attribute__((__packed__));

#define ip6_vfc         ip6_ctlun.ip6_un2_vfc
#define ip6_flow        ip6_ctlun.ip6_un1.ip6_un1_flow
#define ip6_plen        ip6_ctlun.ip6_un1.ip6_un1_plen
#define ip6_nxt         ip6_ctlun.ip6_un1.ip6_un1_nxt   /* IP_PROTO_* */
#define ip6_hlim        ip6_ctlun.ip6_un1.ip6_un1_hlim


/*
 * Preferred extension header order from RFC 2460, 4.1:
 *
 * IP_PROTO_IPV6, IP_PROTO_HOPOPTS, IP_PROTO_DSTOPTS, IP_PROTO_ROUTING,
 * IP_PROTO_FRAGMENT, IP_PROTO_AH, IP_PROTO_ESP, IP_PROTO_DSTOPTS, IP_PROTO_*
 */

/*
 * Routing header data (IP_PROTO_ROUTING)
 */
struct ip6_ext_data_routing {
        uint8_t  type;                  /* routing type */
        uint8_t  segleft;               /* segments left */
        /* followed by routing type specific data */
} __attribute__((__packed__));

struct ip6_ext_data_routing0 {
        uint8_t  type;                  /* always zero */
        uint8_t  segleft;               /* segments left */
        uint8_t  reserved;              /* reserved field */
        uint8_t  slmap[3];              /* strict/loose bit map */
        ip6_addr_t  addr[1];            /* up to 23 addresses */
} __attribute__((__packed__));

/*
 * Fragment header data (IP_PROTO_FRAGMENT)
 */
struct ip6_ext_data_fragment {
        uint16_t  offlg;                /* offset, reserved, and flag */
        uint32_t  ident;                /* identification */
} __attribute__((__packed__));

/*
 * Extension header (chained via {ip6,ext}_nxt, following IPv6 header)
 */
struct ip6_ext_hdr {
  uint8_t  ext_nxt;       /* next header */
  uint8_t  ext_len;       /* following length in units of 8 octets */
  union {
    struct ip6_ext_data_routing     routing;
    struct ip6_ext_data_fragment    fragment;
  } ext_data;
} __attribute__((__packed__));

struct x_in6_addr
{
    union
    {
        u_int8_t   __u6_addr8[16];
        u_int16_t  __u6_addr16[8];
        u_int32_t  __u6_addr32[4];
    } __u6_addr;            /* 128-bit IP6 address */
};
#define x_s6_addr __u6_addr.__u6_addr8

/*
 *  IPv6 header
 *  Internet Protocol, version 6
 *  Static header size: 40 bytes
 */
struct x_ipv6_hdr
{
    u_int8_t ip_flags[4];     /* version, traffic class, flow label */
    u_int16_t ip_len;         /* total length */
    u_int8_t ip_nh;           /* next header */
    u_int8_t ip_hl;           /* hop limit */
    struct x_in6_addr ip_src, ip_dst; /* source and dest address */

};

/*
 *  IPv6 frag header
 *  Internet Protocol, version 6
 *  Static header size: 8 bytes
 */
#define X_IPV6_NH_FRAGMENT 44
struct x_ipv6_frag_hdr
{
    u_int8_t ip_nh;          /* next header */
    u_int8_t ip_reserved;    /* reserved */
    u_int16_t ip_frag;       /* fragmentation stuff */
    u_int32_t ip_id;         /* id */
};

/*
 *  IPv6 routing header
 *  Internet Protocol, version 6
 *  Base header size: 4 bytes
 */
#define X_IPV6_NH_ROUTING  43
struct x_ipv6_routing_hdr
{
    u_int8_t ip_nh;          /* next header */
    u_int8_t ip_len;         /* length of header in 8 octet units (sans 1st) */
    u_int8_t ip_rtype;       /* routing type */
    u_int8_t ip_segments;    /* segments left */
    /* routing information allocated dynamically */
};

/*
 *  IPv6 destination options header
 *  Internet Protocol, version 6
 *  Base header size: 2 bytes
 */
#define X_IPV6_NH_DESTOPTS 60
struct x_ipv6_destopts_hdr
{
    u_int8_t ip_nh;          /* next header */
    u_int8_t ip_len;         /* length of header in 8 octet units (sans 1st) */
    /* destination options information allocated dynamically */
};

/*
 *  IPv6 hop by hop options header
 *  Internet Protocol, version 6
 *  Base header size: 2 bytes
 */
#define X_IPV6_NH_HBH      0
struct x_ipv6_hbhopts_hdr
{
    u_int8_t ip_nh;          /* next header */
    u_int8_t ip_len;         /* length of header in 8 octet units (sans 1st) */
    /* destination options information allocated dynamically */
};

/*
 *  ICMP6 header
 *  Internet Control Message Protocol v6
 *  Base header size: 8 bytes
 */
#ifndef IPPROTO_ICMP6
#define IPPROTO_ICMP6   0x3a
#endif
struct x_icmpv6_hdr
{
    u_int8_t icmp_type;       /* ICMP type */
#ifndef ICMP6_ECHO
#define ICMP6_ECHO          128
#endif
#ifndef ICMP6_ECHOREPLY
#define ICMP6_ECHOREPLY     129
#endif
#ifndef ICMP6_UNREACH
#define ICMP6_UNREACH       1
#endif
#ifndef ICMP6_PKTTOOBIG
#define ICMP6_PKTTOOBIG     2
#endif
#ifndef ICMP6_TIMXCEED
#define ICMP6_TIMXCEED      3
#endif
#ifndef ICMP6_PARAMPROB
#define ICMP6_PARAMPROB     4
#endif
    u_int8_t icmp_code;       /* ICMP code */
    u_int16_t icmp_sum;       /* ICMP Checksum */
    u_int16_t id;             /* ICMP id */
    u_int16_t seq;            /* ICMP sequence number */
};



/*
 *  ICMP header
 *  Internet Control Message Protocol
 *  Base header size: 4 bytes
 */
/*
 * draft-bonica-internet-icmp-08
 *
 * The Destination Unreachable, Time Exceeded
 * and Parameter Problem messages are slighly changed as per
 * the above draft. A new Length field gets added to give
 * the caller an idea about the length of the piggypacked
 * IP packet before the MPLS extension header starts.
 *
 * The Length field represents length of the padded "original datagram"
 * field  measured in 32-bit words.
 *
 * 0                   1                   2                   3
 * 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |     Type      |     Code      |          Checksum             |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |     unused    |    Length     |          unused               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |      Internet Header + leading octets of original datagram    |
 * |                                                               |
 * |                           //                                  |
 * |                                                               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */
struct x_icmpv4_hdr
{
    u_int8_t icmp_type;       /* ICMP type */
#ifndef     ICMP_ECHOREPLY
#define     ICMP_ECHOREPLY                  0
#endif
#ifndef     ICMP_UNREACH
#define     ICMP_UNREACH                    3
#endif
#ifndef     ICMP_SOURCEQUENCH
#define     ICMP_SOURCEQUENCH               4
#endif
#ifndef     ICMP_REDIRECT
#define     ICMP_REDIRECT                   5
#endif
#ifndef     ICMP_ECHO
#define     ICMP_ECHO                       8
#endif
#ifndef     ICMP_ROUTERADVERT
#define     ICMP_ROUTERADVERT               9
#endif
#ifndef     ICMP_ROUTERSOLICIT
#define     ICMP_ROUTERSOLICIT              10
#endif
#ifndef     ICMP_TIMXCEED
#define     ICMP_TIMXCEED                   11
#endif
#ifndef     ICMP_PARAMPROB
#define     ICMP_PARAMPROB                  12
#endif
#ifndef     ICMP_TSTAMP
#define     ICMP_TSTAMP                     13
#endif
#ifndef     ICMP_TSTAMPREPLY
#define     ICMP_TSTAMPREPLY                14
#endif
#ifndef     ICMP_IREQ
#define     ICMP_IREQ                       15
#endif
#ifndef     ICMP_IREQREPLY
#define     ICMP_IREQREPLY                  16
#endif
#ifndef     ICMP_MASKREQ
#define     ICMP_MASKREQ                    17
#endif
#ifndef     ICMP_MASKREPLY
#define     ICMP_MASKREPLY                  18
#endif
    u_int8_t icmp_code;       /* ICMP code */
#ifndef     ICMP_UNREACH_NET
#define     ICMP_UNREACH_NET                0
#endif
#ifndef     ICMP_UNREACH_HOST
#define     ICMP_UNREACH_HOST               1
#endif
#ifndef     ICMP_UNREACH_PROTOCOL
#define     ICMP_UNREACH_PROTOCOL           2
#endif
#ifndef     ICMP_UNREACH_PORT
#define     ICMP_UNREACH_PORT               3
#endif
#ifndef     ICMP_UNREACH_NEEDFRAG
#define     ICMP_UNREACH_NEEDFRAG           4
#endif
#ifndef     ICMP_UNREACH_SRCFAIL
#define     ICMP_UNREACH_SRCFAIL            5
#endif
#ifndef     ICMP_UNREACH_NET_UNKNOWN
#define     ICMP_UNREACH_NET_UNKNOWN        6
#endif
#ifndef     ICMP_UNREACH_HOST_UNKNOWN
#define     ICMP_UNREACH_HOST_UNKNOWN       7
#endif
#ifndef     ICMP_UNREACH_ISOLATED
#define     ICMP_UNREACH_ISOLATED           8
#endif
#ifndef     ICMP_UNREACH_NET_PROHIB
#define     ICMP_UNREACH_NET_PROHIB         9
#endif
#ifndef     ICMP_UNREACH_HOST_PROHIB
#define     ICMP_UNREACH_HOST_PROHIB        10
#endif
#ifndef     ICMP_UNREACH_TOSNET
#define     ICMP_UNREACH_TOSNET             11
#endif
#ifndef     ICMP_UNREACH_TOSHOST
#define     ICMP_UNREACH_TOSHOST            12
#endif
#ifndef     ICMP_UNREACH_FILTER_PROHIB
#define     ICMP_UNREACH_FILTER_PROHIB      13
#endif
#ifndef     ICMP_UNREACH_HOST_PRECEDENCE
#define     ICMP_UNREACH_HOST_PRECEDENCE    14
#endif
#ifndef     ICMP_UNREACH_PRECEDENCE_CUTOFF
#define     ICMP_UNREACH_PRECEDENCE_CUTOFF  15
#endif
#ifndef     ICMP_REDIRECT_NET
#define     ICMP_REDIRECT_NET               0
#endif
#ifndef     ICMP_REDIRECT_HOST
#define     ICMP_REDIRECT_HOST              1
#endif
#ifndef     ICMP_REDIRECT_TOSNET
#define     ICMP_REDIRECT_TOSNET            2
#endif
#ifndef     ICMP_REDIRECT_TOSHOST
#define     ICMP_REDIRECT_TOSHOST           3
#endif
#ifndef     ICMP_TIMXCEED_INTRANS
#define     ICMP_TIMXCEED_INTRANS           0
#endif
#ifndef     ICMP_TIMXCEED_REASS
#define     ICMP_TIMXCEED_REASS             1
#endif
#ifndef     ICMP_PARAMPROB_OPTABSENT
#define     ICMP_PARAMPROB_OPTABSENT        1
#endif

    u_int16_t icmp_sum;   /* ICMP Checksum */

    union {
        u_int8_t  pptr;                       /* ICMP_PARAMPROB */
        u_int32_t gateway; /* gateway host */
        struct {
            u_int16_t id; /* ICMP id */
            u_int16_t seq;/* ICMP sequence number */
        } echo;

        struct {
            u_int16_t pad; /* padding */
            u_int16_t mtu; /* MTU size */
        } frag;
    } icmp_hun;

#define icmp_pptr       icmp_hun.pptr
#define icmp_gwaddr     icmp_hun.gateway
#define icmp_id         icmp_hun.echo.id
#define icmp_seq        icmp_hun.echo.seq

    union {
        struct {
            n_time its_otime;
            n_time its_rtime;
            n_time its_ttime;
        } ts;
        struct {
            struct x_ipv4_hdr idi_ip;
            /* options and then 64 bits of data */
        } ip;
        u_int32_t mask;
        int8_t data[1];
    } icmp_dun;
#define icmp_otime      icmp_dun.ts.its_otime
#define icmp_rtime      icmp_dun.ts.its_rtime
#define icmp_ttime      icmp_dun.ts.its_ttime
#define icmp_ip         icmp_dun.ip.idi_ip
#define icmp_mask       icmp_dun.mask
#define icmp_data       icmp_dun.data
};


/*
 *  IGMP header
 *  Internet Group Message Protocol
 *  Static header size: 8 bytes
 */
struct x_igmp_hdr
{
    u_int8_t igmp_type;       /* IGMP type */
#ifndef IGMP_MEMBERSHIP_QUERY
#define IGMP_MEMBERSHIP_QUERY           0x11    /* membership query */
#endif
#ifndef IGMP_V1_MEMBERSHIP_REPORT
#define IGMP_V1_MEMBERSHIP_REPORT       0x12    /* Ver. 1 membership report */
#endif
#ifndef IGMP_V2_MEMBERSHIP_REPORT
#define IGMP_V2_MEMBERSHIP_REPORT       0x16    /* Ver. 2 membership report */
#endif
#ifndef IGMP_LEAVE_GROUP
#define IGMP_LEAVE_GROUP                0x17    /* Leave-group message */
#endif
    u_int8_t igmp_code;       /* IGMP code */
    u_int16_t igmp_sum;       /* IGMP checksum */
    struct in_addr igmp_group;/* IGMP host IP */
};


/*
 *  IPSEC header
 *  Internet Protocol Security Protocol
 *  Encapsulating Security Payload Header Static header size: 12 bytes
 *  Encapsulating Security Payload Footer Base header size: 2 bytes
 *  Authentication Header Static Size: 16 bytes
 */
#ifndef IPPROTO_ESP
#define IPPROTO_ESP 50      /* not everyone's got this */
#endif

/* ESP constants */
#define ESP_HEADER_LEN     8
#define ESP_AUTH_DATA_LEN 12
#define ESP_TRAILER_LEN    2

struct x_esp_hdr
{
   u_int32_t esp_spi;       /* security parameter index */
   u_int32_t esp_seq;       /* ESP sequence number */
   u_int32_t esp_iv;        /* initialization vector */
};

struct x_esp_ftr
{
    u_int8_t esp_pad_len;   /* padding length */
    u_int8_t esp_nh;        /* next header pointer */
    int8_t *esp_auth;       /* authentication data */
};
 
#ifndef IPPROTO_AH
#define IPPROTO_AH 51       /* not everyone's got this */
#endif
struct x_ah_hdr
{
    u_int8_t ah_nh;          /* next header */
    u_int8_t ah_len;         /* payload length */
    u_int16_t ah_res;        /* reserved */
    u_int32_t ah_spi;        /* security parameter index  */
    u_int32_t ah_seq;        /* AH sequence number */
    u_int32_t ah_auth;       /* authentication data */
};


/*
 *  ISL header
 *  Cisco Inter-Switch Link
 *  Static header size: 26 bytes
 */
/*
 *  For checksum stuff -- IANA says 135-254 is "unassigned" as of 12.2001.
 *  Let's hope this one stays that way for a while!
 */
#define X_PROTO_ISL    201
struct x_isl_hdr
{
    u_int8_t isl_dhost[5];    /* destination address "01:00:0c:00:00" */
#ifdef WORDS_BIGENDIAN
    u_int8_t isl_user:4,      /* user defined bits */
    isl_type:4;               /* type of frame */
#else
    u_int8_t isl_type:4,      /* type of frame */
    isl_user:4;               /* user defined bits */
#endif
    u_int8_t isl_shost[6];    /* source address */
    u_int16_t isl_len;        /* total length of packet - 18 bytes */
    u_int8_t isl_snap[6];     /* 0xaaaa03 + vendor code */
    u_int16_t isl_vid;        /* 15 bit VLAN ID, 1 bit BPDU / CDP indicator */
    u_int16_t isl_index;      /* port index */
    u_int16_t isl_reserved;   /* used for FDDI and token ring */
    /* ethernet frame and 4 byte isl crc */
};

#ifndef IPPROTO_OSPF
#define IPPROTO_OSPF    89  /* not everyone's got this */
#endif
#define IPPROTO_OSPF_LSA    890     /* made this up.  Hope it's unused */
#define X_MODX         4102    /* used in LSA checksum */

/*
 *  Options used in multiple OSPF packets
 *  More info can be found in section A.2 of RFC 2328.
 */
#define X_OPT_EBIT  0x02 /* describes the way AS-external-LSAs are flooded */
#define X_OPT_MCBIT 0x04 /* whether or not IP multicast dgrams are fwdd */
#define X_OPT_NPBIT 0x08 /* describes handling of type-7 LSAs */
#define X_OPT_EABIT 0x10 /* rtr's willingness to send/recv EA-LSAs */
#define X_OPT_DCBIT 0x20 /* describes handling of demand circuits */


/*
 *  MPLS header
 *  Multi-Protocol Label Switching
 *  Static header size: 4 bytes
 */
struct x_mpls_hdr
{
    u_int32_t mpls_les;          /* 20 bits label, 3 bits exp, 1 bit bos, ttl */
#define X_MPLS_BOS_ON    1
#define X_MPLS_BOS_OFF   0
};

/*
 *  NTP header
 *  Network Time Protocol
 *  Static header size: 48 bytes
 */
struct x_ntp_hdr_l_fp  /* int32_t floating point (64-bit) */
{
    u_int32_t integer;         /* integer */
    u_int32_t fraction;        /* fraction */
};

struct x_ntp_hdr_s_fp  /* int16_t floating point (32-bit) */
{
    u_int16_t integer;        /* integer */
    u_int16_t fraction;       /* fraction */
};


struct x_ntp_hdr
{
    u_int8_t ntp_li_vn_mode;       /* leap indicator, version, mode */
#define X_NTP_LI_NW    0x0         /* no warning */
#define X_NTP_LI_AS    0x1         /* last minute has 61 seconds */
#define X_NTP_LI_DS    0x2         /* last minute has 59 seconds */
#define X_NTP_LI_AC    0x3         /* alarm condition */

#define X_NTP_VN_2     0x2         /* version 2 */
#define X_NTP_VN_3     0x3         /* version 3 */
#define X_NTP_VN_4     0x4         /* version 4 */

#define X_NTP_MODE_R   0x0         /* reserved */
#define X_NTP_MODE_A   0x1         /* symmetric active */
#define X_NTP_MODE_P   0x2         /* symmetric passive */
#define X_NTP_MODE_C   0x3         /* client */
#define X_NTP_MODE_S   0x4         /* server */
#define X_NTP_MODE_B   0x5         /* broadcast */
#define X_NTP_MODE_RC  0x6         /* reserved for NTP control message */
#define X_NTP_MODE_RP  0x7         /* reserved for private use */
    u_int8_t ntp_stratum;          /* stratum */
#define X_NTP_STRATUM_UNAVAIL  0x0 /* unspecified or unavailable */
#define X_NTP_STRATUM_PRIMARY  0x1 /* primary reference (radio clock) */
                                        /* 2 - 15 is secondary */
                                        /* 16 - 255 is reserved */
    u_int8_t ntp_poll;                    /* poll interval (should be 4 - 12) */
    u_int8_t ntp_precision;               /* local clock precision */
    struct x_ntp_hdr_s_fp ntp_delay;       /* roundtrip delay */
    struct x_ntp_hdr_s_fp ntp_dispersion;  /* nominal error */
    u_int32_t ntp_reference_id;            /* reference source id */
#define X_NTP_REF_LOCAL    0x4c4f434c  /* uncalibrated local clock */
#define X_NTP_REF_PPS      0x50505300  /* atomic / pulse-per-second clock */
#define X_NTP_REF_ACTS     0x41435453  /* NIST dialup modem */
#define X_NTP_REF_USNO     0x55534e4f  /* USNO modem service */
#define X_NTP_REF_PTB      0x50544200  /* PTB (German) modem service */ 
#define X_NTP_REF_TDF      0x54444600  /* Allouis (French) radio */
#define X_NTP_REF_DCF      0x44434600  /* Mainflingen (German) radio */
#define X_NTP_REF_MSF      0x4d534600  /* Rugby (UK) radio */
#define X_NTP_REF_WWV      0x57575600  /* Ft Collins (US) radio */
#define X_NTP_REF_WWVB     0x57575642  /* Boulder (US) radio */
#define X_NTP_REF_WWVH     0x57575648  /* Kaui Hawaii (US) radio */
#define X_NTP_REF_CHU      0x43485500  /* Ottaha (Canada) radio */
#define X_NTP_REF_LORC     0x4c4f5243  /* LORAN-C radionavigation */
#define X_NTP_REF_OMEG     0x4f4d4547  /* OMEGA radionavigation */
#define X_NTP_REF_GPS      0x47505300  /* global positioning system */
#define X_NTP_REF_GOES     0x474f4553  /* geostationary orbit env satellite */
    struct x_ntp_hdr_l_fp ntp_ref_ts;  /* reference timestamp */ 
    struct x_ntp_hdr_l_fp ntp_orig_ts; /* originate timestamp */
    struct x_ntp_hdr_l_fp ntp_rec_ts;  /* receive timestamp */
    struct x_ntp_hdr_l_fp ntp_xmt_ts;  /* transmit timestamp */
};


/*
 *  OSPFv2 header
 *  Open Shortest Path First
 *  Static header size: 16 bytes
 */
struct x_ospf_hdr
{
    u_int8_t ospf_v;             /* version */
#define OSPFVERSION         2
    u_int8_t ospf_type;          /* type */
#define  X_OSPF_UMD    0         /* UMd monitoring packet */
#define  X_OSPF_HELLO  1         /* HELLO packet */
#define  X_OSPF_DBD    2         /* dataBase description packet */
#define  X_OSPF_LSR    3         /* link state request packet */
#define  X_OSPF_LSU    4         /* link state Update Packet */
#define  X_OSPF_LSA    5         /* link state acknowledgement packet */
    u_int16_t   ospf_len;        /* length */
    struct in_addr ospf_rtr_id;  /* source router ID */
    struct in_addr ospf_area_id; /* roam ID */
    u_int16_t ospf_sum;          /* checksum */
    u_int16_t ospf_auth_type;    /* authentication type */
#define X_OSPF_AUTH_NULL   0     /* null password */
#define X_OSPF_AUTH_SIMPLE 1     /* simple, plaintext, 8 int8_t password */
#define X_OSPF_AUTH_MD5    2     /* MD5 */
};


/*
 *  OSPF authentication header
 *  Open Shortest Path First
 *  Static header size: 8 bytes
 */
struct x_auth_hdr
{
    u_int16_t ospf_auth_null;  /* NULL */
    u_int8_t ospf_auth_keyid;  /* authentication key ID */
    u_int8_t ospf_auth_len;    /* auth data length */
    u_int ospf_auth_seq;       /* cryptographic sequence number */
};


/*
 *  OSPF hello header
 *  Open Shortest Path First
 *  Static header size: 28 bytes
 */
struct x_ospf_hello_hdr
{
    struct in_addr hello_nmask;     /* netmask associated with the interface */
    u_int16_t hello_intrvl;         /* num of seconds between routers last packet */
    u_int8_t hello_opts;            /* Options for HELLO packets (look above) */
    u_int8_t hello_rtr_pri;         /* router's priority (if 0, can't be backup) */
    u_int hello_dead_intvl;         /* # of secs a router is silent till deemed down */
    struct in_addr hello_des_rtr;   /* Designated router on the network */
    struct in_addr hello_bkup_rtr;  /* Backup router */
    struct in_addr hello_nbr;       /* neighbor router, memcpy more as needed */
};


/*
 *  Database Description header.
 */
struct x_dbd_hdr
{
    u_int16_t dbd_mtu_len;     /* max length of IP dgram that this 'if' can use */
    u_int8_t dbd_opts;         /* DBD packet options (from above) */
    u_int8_t dbd_type;         /* type of exchange occurring */
#define X_DBD_IBI      0x01    /* init */
#define X_DBD_MBIT     0x02    /* more DBD packets are to come */
#define X_DBD_MSBIT    0x04    /* If 1, sender is the master in the exchange */
    u_int  dbd_seq;            /* DBD sequence number */
};


/*
 *  used for the LS type field in all LS* headers
 */
#define X_LS_TYPE_RTR      1   /* router-LSA */
#define X_LS_TYPE_NET      2   /* network-LSA */
#define X_LS_TYPE_IP       3   /* summary-LSA (IP Network) */
#define X_LS_TYPE_ASBR     4   /* summary-LSA (ASBR) */
#define X_LS_TYPE_ASEXT    5   /* AS-external-LSA */


/*
 *  Link State Request header
 */
struct x_lsr_hdr
{
    u_int lsr_type;             /* type of LS being requested */
    u_int lsr_lsid;             /* link state ID */
    struct in_addr lsr_adrtr;   /* advertising router (memcpy more as needed) */
};


/*
 *  Link State Update header
 */
struct x_lsu_hdr
{
    u_int lsu_num;              /* number of LSAs that will be broadcasted */
};


/*
 *  Link State Acknowledgement header.
 */
struct x_lsa_hdr
{
    u_int16_t lsa_age;        /* time in seconds since the LSA was originated */
    u_int8_t lsa_opts;        /* look above for OPTS_* */
    u_int8_t lsa_type;        /* look below for LS_TYPE_* */
    u_int lsa_id;             /* link State ID */
    struct in_addr lsa_adv;   /* router ID of Advertising router */
    u_int lsa_seq;            /* LSA sequence number to detect old/bad ones */
    u_int16_t lsa_sum;        /* "Fletcher Checksum" of all fields minus age */
    u_int16_t lsa_len;        /* length in bytes including the 20 byte header */
};


/*
 *  Router LSA data format
 *
 *  Other stuff for TOS can be added for backward compatability, for this
 *  version, only OSPFv2 is being FULLY supported.
 */
struct x_rtr_lsa_hdr
{
    u_int16_t rtr_flags;        /* set to help describe packet */
#define X_RTR_FLAGS_W  0x0100   /* W bit */
#define X_RTR_FLAGS_E  0x0200   /* E bit */
#define X_RTR_FLAGS_B  0x0400   /* B bit */
    u_int16_t rtr_num;          /* number of links within that packet */
    u_int rtr_link_id;          /* describes link_data (look below) */
#define X_LINK_ID_NBR_ID   1    /* Neighbors router ID, also can be 4 */
#define X_LINK_ID_IP_DES   2    /* IP address of designated router */
#define X_LINK_ID_SUB      3    /* IP subnet number */
    u_int rtr_link_data;        /* Depending on link_id, info is here */
    u_int8_t rtr_type;          /* Description of router link */
#define X_RTR_TYPE_PTP     1    /* Point-To-Point */
#define X_RTR_TYPE_TRANS   2    /* Connection to a "transit network" */
#define X_RTR_TYPE_STUB    3    /* Connectin to a "stub network" */
#define RTR_TYPE_VRTL   4       /* connects to a "virtual link" */
    u_int8_t rtr_tos_num;       /* number of different TOS metrics for this link */
    u_int16_t rtr_metric;       /* the "cost" of using this link */
};


/*
 *  Network LSA data format.
 */
struct x_net_lsa_hdr
{
    struct in_addr net_nmask;   /* Netmask for that network */
    u_int  net_rtr_id;          /* ID of router attached to that network */
};
 
 
/*
 *  Summary LSA data format.
 */
struct x_sum_lsa_hdr
{
    struct in_addr sum_nmask;   /* Netmask of destination IP address */
    u_int  sum_metric;          /* Same as in rtr_lsa (&0xfff to use last 24bit */
    u_int  sum_tos_metric;      /* first 8bits are TOS, 24bits are TOS Metric */
};
 
 
/*
 *  AS External LSA data format.
 *  & 0xfff logic operator for as_metric to get last 24bits.
 */
struct x_as_lsa_hdr
{
    struct in_addr as_nmask;      /* Netmask for advertised destination */
    u_int  as_metric;             /* May have to set E bit in first 8bits */
#define X_AS_E_BIT_ON 0x80000000  /* as_metric */
    struct in_addr as_fwd_addr;   /* Forwarding address */
    u_int  as_rte_tag;            /* External route tag */
};


/*
 *  Base RIP header
 *  Routing Information Protocol
 *  Base header size: 24 bytes
 */
struct x_rip_hdr
{
    u_int8_t rip_cmd;         /* RIP command */
#define RIPCMD_REQUEST   1    /* want info */
#define RIPCMD_RESPONSE  2    /* responding to request */
#define RIPCMD_TRACEON   3    /* turn tracing on */
#define RIPCMD_TRACEOFF  4    /* turn it off */
#define RIPCMD_POLL      5    /* like request, but anyone answers */
#define RIPCMD_POLLENTRY 6    /* like poll, but for entire entry */
#define RIPCMD_MAX       7    /* ? command */
    u_int8_t rip_ver;         /* RIP version */
#define RIPVER_0         0
#define RIPVER_1         1
#define RIPVER_2         2
    u_int16_t rip_rd;          /* Zero (v1) or Routing Domain (v2) */
    u_int16_t rip_af;          /* Address family */
    u_int16_t rip_rt;          /* Zero (v1) or Route Tag (v2) */
    u_int32_t rip_addr;        /* IP address */
    u_int32_t rip_mask;        /* Zero (v1) or Subnet Mask (v2) */
    u_int32_t rip_next_hop;    /* Zero (v1) or Next hop IP address (v2) */
    u_int32_t rip_metric;      /* Metric */
};

/*
 *  RPC headers
 *  Remote Procedure Call
 */
#define X_RPC_CALL  0
#define X_RPC_REPLY 1
#define X_RPC_VERS  2
#define X_RPC_LAST_FRAG 0x80000000

/*
 *  Portmap defines
 */
#define X_PMAP_PROGRAM          100000
#define X_PMAP_PROC_NULL        0
#define X_PMAP_PROC_SET         1
#define X_PMAP_PROC_UNSET       2
#define X_PMAP_PROC_GETADDR     3
#define X_PMAP_PROC_DUMP        4
#define X_PMAP_PROC_CALLIT      5
#define X_PMAP_PROC_BCAST       5 /* Not a typo */
#define X_PMAP_PROC_GETTIME     6
#define X_PMAP_PROC_UADDR2TADDR 7
#define X_PMAP_PROC_TADDR2UADDR 8
#define X_PMAP_PROC_GETVERSADDR 9
#define X_PMAP_PROC_INDIRECT    10
#define X_PMAP_PROC_GETADDRLIST 11
#define X_PMAP_PROC_GETSTAT     12

/* There will be more to add... */

struct x_rpc_opaque_auth
{
    u_int32_t rpc_auth_flavor;
    u_int32_t rpc_auth_length;
#if 0
    u_int8_t *rpc_auth_data;
#endif
};

struct x_rpc_call
{
    u_int32_t rpc_rpcvers;   /* RPC version - must be 2 */
    u_int32_t rpc_prognum;   /* Program Number */
    u_int32_t rpc_vers;      /* Program Version */
    u_int32_t rpc_procedure; /* RPC procedure */
    struct x_rpc_opaque_auth rpc_credentials;
    struct x_rpc_opaque_auth rpc_verifier;
};

struct x_rpc_call_hdr
{
    u_int32_t rpc_xid;  /* xid (transaction identifier) */
    u_int32_t rpc_type;
    struct x_rpc_call  rpc_call;
};

struct x_rpc_call_tcp_hdr
{
    u_int32_t rpc_record_marking; /* used with byte stream protocols */
    struct x_rpc_call_hdr rpc_common;
};

/*
 *  STP configuration header
 *  Spanning Tree Protocol
 *  Static header size: 35 bytes
 */
struct x_stp_conf_hdr
{
    u_int16_t stp_id;         /* protocol id */
    u_int8_t stp_version;     /* protocol version */
    u_int8_t stp_bpdu_type;   /* bridge protocol data unit type */
    u_int8_t stp_flags;       /* control flags */
    u_int8_t stp_rootid[8];   /* root id */
    u_int32_t stp_rootpc;      /* root path cost */
    u_int8_t stp_bridgeid[8]; /* bridge id */
    u_int16_t stp_portid;     /* port id */
    u_int16_t stp_mage;       /* message age */
    u_int16_t stp_maxage;     /* max age */
    u_int16_t stp_hellot;     /* hello time */
    u_int16_t stp_fdelay;     /* forward delay */
};


/*
 *  STP topology change notification header
 *  Spanning Tree Protocol
 *  Static header size: 4 bytes
 */
struct x_stp_tcn_hdr
{
    u_int16_t stp_id;         /* protocol id */
    u_int8_t stp_version;     /* protocol version */
    u_int8_t stp_bpdu_type;   /* bridge protocol data unit type */
};


/*
 *  TCP header
 *  Transmission Control Protocol (RFC 793).
 *  Static header size: 20 bytes
 */
struct x_tcp_hdr
{
    u_int16_t th_sport;       /* source port */
    u_int16_t th_dport;       /* destination port */
    u_int32_t th_seq;         /* sequence number */
    u_int32_t th_ack;         /* acknowledgement number */
#ifdef WORDS_BIGENDIAN
    u_int8_t th_off:4,        /* data offset */
    th_x2:4;                  /* (unused) */
#else
    u_int8_t th_x2:4,         /* (unused) */
    th_off:4;                 /* data offset */
#endif

    u_int8_t  th_flags;       /* control flags */
#ifndef TH_FIN
#define TH_FIN    0x01      /* finished send data */
#endif
#ifndef TH_SYN
#define TH_SYN    0x02      /* synchronize sequence numbers */
#endif
#ifndef TH_RST
#define TH_RST    0x04      /* reset the connection */
#endif
#ifndef TH_PUSH
#define TH_PUSH   0x08      /* push data to the app layer */
#endif
#ifndef TH_ACK
#define TH_ACK    0x10      /* acknowledge */
#endif
#ifndef TH_URG
#define TH_URG    0x20      /* urgent! */
#endif
#ifndef TH_ECE
#define TH_ECE    0x40
#endif
#ifndef TH_CWR   
#define TH_CWR    0x80
#endif
    u_int16_t th_win;         /* window */
    u_int16_t th_sum;         /* checksum */
    u_int16_t th_urp;         /* urgent pointer */
};

#define TCP_HDR_LEN     20              /* base TCP header length */
#define TCP_OPT_LEN     2               /* base TCP option length */
#define TCP_OPT_LEN_MAX 40
#define TCP_HDR_LEN_MAX (TCP_HDR_LEN + TCP_OPT_LEN_MAX)


#define TCP_PORT_MAX    65535           /* maximum port */
#define TCP_WIN_MAX     65535           /* maximum (unscaled) window */

/*
 * Sequence number comparison macros
 */
#define TCP_SEQ_LT(a,b)         ((int)((a)-(b)) < 0)
#define TCP_SEQ_LEQ(a,b)        ((int)((a)-(b)) <= 0)
#define TCP_SEQ_GT(a,b)         ((int)((a)-(b)) > 0)
#define TCP_SEQ_GEQ(a,b)        ((int)((a)-(b)) >= 0)

/*
 * TCP FSM states
 */
#define TCP_STATE_CLOSED        0       /* closed */
#define TCP_STATE_LISTEN        1       /* listening from connection */
#define TCP_STATE_SYN_SENT      2       /* active, have sent SYN */
#define TCP_STATE_SYN_RECEIVED  3       /* have sent and received SYN */

#define TCP_STATE_ESTABLISHED   4       /* established */
#define TCP_STATE_CLOSE_WAIT    5       /* rcvd FIN, waiting for close */

#define TCP_STATE_FIN_WAIT_1    6       /* have closed, sent FIN */
#define TCP_STATE_CLOSING       7       /* closed xchd FIN, await FIN-ACK */
#define TCP_STATE_LAST_ACK      8       /* had FIN and close, await FIN-ACK */

#define TCP_STATE_FIN_WAIT_2    9       /* have closed, FIN is acked */
#define TCP_STATE_TIME_WAIT     10      /* in 2*MSL quiet wait after close */
#define TCP_STATE_MAX           11

/*
 * Options (opt_type) - http://www.iana.org/assignments/tcp-parameters
 */
#define TCP_OPT_EOL             0       /* end of option list */
#define TCP_OPT_NOP             1       /* no operation */
#define TCP_OPT_MSS             2       /* maximum segment size */
#define TCP_OPT_WSCALE          3       /* window scale factor, RFC 1072 */
#define TCP_OPT_SACKOK          4       /* SACK permitted, RFC 2018 */
#define TCP_OPT_SACK            5       /* SACK, RFC 2018 */
#define TCP_OPT_ECHO            6       /* echo (obsolete), RFC 1072 */
#define TCP_OPT_ECHOREPLY       7       /* echo reply (obsolete), RFC 1072 */
#define TCP_OPT_TIMESTAMP       8       /* timestamp, RFC 1323 */
#define TCP_OPT_POCONN          9       /* partial order conn, RFC 1693 */
#define TCP_OPT_POSVC           10      /* partial order service, RFC 1693 */
#define TCP_OPT_CC              11      /* connection count, RFC 1644 */
#define TCP_OPT_CCNEW           12      /* CC.NEW, RFC 1644 */
#define TCP_OPT_CCECHO          13      /* CC.ECHO, RFC 1644 */
#define TCP_OPT_ALTSUM          14      /* alt checksum request, RFC 1146 */
#define TCP_OPT_ALTSUMDATA      15      /* alt checksum data, RFC 1146 */
#define TCP_OPT_SKEETER         16      /* Skeeter */
#define TCP_OPT_BUBBA           17      /* Bubba */
#define TCP_OPT_TRAILSUM        18      /* trailer checksum */
#define TCP_OPT_MD5             19      /* MD5 signature, RFC 2385 */
#define TCP_OPT_SCPS            20      /* SCPS capabilities */
#define TCP_OPT_SNACK           21      /* selective negative acks */
#define TCP_OPT_REC             22      /* record boundaries */
#define TCP_OPT_CORRUPT         23      /* corruption experienced */
#define TCP_OPT_SNAP            24      /* SNAP */
#define TCP_OPT_TCPCOMP         26      /* TCP compression filter */
#define TCP_OPT_MAX             27


#define TCP_OPT_TYPEONLY(type)  \
        ((type) == TCP_OPT_EOL || (type) == TCP_OPT_NOP)

/*
 * TCP option (following TCP header)
 */
struct tcp_opt {
        uint8_t         opt_type;       /* option type */
        uint8_t         opt_len;        /* option length >= TCP_OPT_LEN */
        union tcp_opt_data {
                uint16_t        mss;            /* TCP_OPT_MSS */
                uint8_t         wscale;         /* TCP_OPT_WSCALE */
                uint16_t        sack[19];       /* TCP_OPT_SACK */
                uint32_t        echo;           /* TCP_OPT_ECHO{REPLY} */
                uint32_t        timestamp[2];   /* TCP_OPT_TIMESTAMP */
                uint32_t        cc;             /* TCP_OPT_CC{NEW,ECHO} */
                uint8_t         cksum;          /* TCP_OPT_ALTSUM */
                uint8_t         md5[16];        /* TCP_OPT_MD5 */
                uint8_t         data8[TCP_OPT_LEN_MAX - TCP_OPT_LEN];
        } opt_data;
} __attribute__((__packed__));


/*
 *  Token Ring Header
 */
struct x_token_ring_hdr
{
    u_int8_t  token_ring_access_control;
#define X_TOKEN_RING_FRAME  0x10
    u_int8_t  token_ring_frame_control;
#define X_TOKEN_RING_LLC_FRAME  0x40
    u_int8_t  token_ring_dhost[TOKEN_RING_ADDR_LEN];
    u_int8_t  token_ring_shost[TOKEN_RING_ADDR_LEN];
    u_int8_t  token_ring_llc_dsap;
    u_int8_t  token_ring_llc_ssap;
    u_int8_t  token_ring_llc_control_field;
    u_int8_t  token_ring_llc_org_code[X_ORG_CODE_SIZE];
    u_int16_t token_ring_type;
#define TOKEN_RING_TYPE_IP            0x0800  /* IP protocol */
#define TOKEN_RING_TYPE_ARP           0x0806  /* addr. resolution protocol */
#define TOKEN_RING_TYPE_REVARP        0x8035  /* reverse addr. resolution protocol */
};

struct x_token_ring_addr
{
    u_int8_t  token_ring_addr_octet[6];        /* Token Ring address */
};

/*
 *  UDP header
 *  User Data Protocol
 *  Static header size: 8 bytes
 */
struct x_udp_hdr
{
    u_int16_t uh_sport;       /* soure port */
    u_int16_t uh_dport;       /* destination port */
    u_int16_t uh_ulen;        /* length */
    u_int16_t uh_sum;         /* checksum */
};

/*
 *  Sebek header
 *  Static header size: 48 bytes
 */
struct x_sebek_hdr
{
    u_int32_t magic;           /* identify packets that should be hidden */
    u_int16_t version;         /* protocol version, currently 1 */
#define SEBEK_PROTO_VERSION 1
    u_int16_t type;            /* type of record (read data is type 0, write data is type 1) */
#define SEBEK_TYPE_READ     0  /* Currently, only read is supported */
#define SEBEK_TYPE_WRITE    1
    u_int32_t counter;         /*  PDU counter used to identify when packet are lost */
    u_int32_t time_sec;        /* seconds since EPOCH according to the honeypot */
    u_int32_t time_usec;       /* residual microseconds */
    u_int32_t pid;             /* PID */
    u_int32_t uid;             /* UID */
    u_int32_t fd;              /* FD */
#define SEBEK_CMD_LENGTH   12
    u_int8_t cmd[SEBEK_CMD_LENGTH]; /* 12 first characters of the command */
    u_int32_t length;          /* length in bytes of the PDU's body */
};


/*
 *  VRRP header
 *  Virtual Router Redundancy Protocol
 *  Static header size: 8 bytes
 */
#ifndef IPPROTO_VRRP
#define IPPROTO_VRRP 112    /* not everyone's got this */
#endif
struct x_vrrp_hdr
{
#ifdef WORDS_BIGENDIAN
    u_int8_t vrrp_t:4,        /* packet type */
    vrrp_v:4;                 /* protocol version */
#else
    u_int8_t vrrp_v:4,        /* protocol version */
    vrrp_t:4;                 /* packet type */
#endif
#define X_VRRP_VERSION_01  0x1
#define X_VRRP_VERSION_02  0x2
#define X_VRRP_TYPE_ADVERT 0x1
    u_int8_t vrrp_vrouter_id; /* virtual router id */
    u_int8_t vrrp_priority;   /* priority */
    u_int8_t vrrp_ip_count;   /* number of IP addresses */
    u_int8_t vrrp_auth_type;  /* authorization type */
#define X_VRRP_AUTH_NONE   0x1
#define X_VRRP_AUTH_PASSWD 0x2
#define X_VRRP_AUTH_IPAH   0x3
    u_int8_t vrrp_advert_int; /* advertisement interval */
    u_int16_t vrrp_sum;       /* checksum */
    /* additional addresses */
    /* authentication info */
};


/*
 *  HSRP header
 *  Static header size: 20 bytes
 */
struct x_hsrp_hdr
{
#define X_HSRP_VERSION 0x0
    u_int8_t version;           /* Version of the HSRP messages */
#define X_HSRP_TYPE_HELLO 0x0
#define X_HSRP_TYPE_COUP 0x1
#define X_HSRP_TYPE_RESIGN 0x2
    u_int8_t opcode;            /* Type of message */
#define X_HSRP_STATE_INITIAL 0x0
#define X_HSRP_STATE_LEARN   0x1
#define X_HSRP_STATE_LISTEN  0x2
#define X_HSRP_STATE_SPEAK   0x4
#define X_HSRP_STATE_STANDBY 0x8
#define X_HSRP_STATE_ACTIVE  0x10
    u_int8_t state;            /* Current state of the router */
    u_int8_t hello_time;       /* Period in seconds between hello messages */
    u_int8_t hold_time;        /* Seconds that the current hello message is valid */
    u_int8_t priority;         /* Priority for the election proccess */
    u_int8_t group;            /* Standby group */
    u_int8_t reserved;         /* Reserved field */
#define HSRP_AUTHDATA_LENGTH  8 
    u_int8_t authdata[HSRP_AUTHDATA_LENGTH]; /* Password */
    u_int32_t virtual_ip;      /* Virtual IP address */
};



#endif /* __XPROTO_H__ */
