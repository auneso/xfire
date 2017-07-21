#ifndef __XDHCP_H__
#define __XDHCP_H__

typedef u_int32_t ip4_t;

#define DHCP_CHADDR_LEN 16
#define DHCP_SNAME_LEN  64
#define DHCP_FILE_LEN   128

/*
 * http://www.tcpipguide.com/free/t_DHCPMessageFormat.htm
 */
typedef struct dhcp
{
    u_int8_t    opcode;
    u_int8_t    htype;
    u_int8_t    hlen;
    u_int8_t    hops;
    u_int32_t   xid;
    u_int16_t   secs;
    u_int16_t   flags;
    ip4_t       ciaddr;
    ip4_t       yiaddr;
    ip4_t       siaddr;
    ip4_t       giaddr;
    u_int8_t    chaddr[DHCP_CHADDR_LEN];
    char        bp_sname[DHCP_SNAME_LEN];
    char        bp_file[DHCP_FILE_LEN];
    uint32_t    magic_cookie;
    u_int8_t    bp_options[0];
} dhcp_t;

#define DHCP_BOOTREQUEST                    1
#define DHCP_BOOTREPLY                      2

#define DHCP_HARDWARE_TYPE_10_EHTHERNET     1

#define MESSAGE_TYPE_PAD                    0
#define MESSAGE_TYPE_REQ_SUBNET_MASK        1
#define MESSAGE_TYPE_ROUTER                 3
#define MESSAGE_TYPE_DNS                    6
#define MESSAGE_TYPE_DOMAIN_NAME            15
#define MESSAGE_TYPE_REQ_IP                 50
#define MESSAGE_TYPE_DHCP                   53
#define MESSAGE_TYPE_PARAMETER_REQ_LIST     55
#define MESSAGE_TYPE_END                    255

#define DHCP_OPTION_DISCOVER                1
#define DHCP_OPTION_OFFER                   2
#define DHCP_OPTION_REQUEST                 3
#define DHCP_OPTION_PACK                    4

/* DHCP options */
enum {
   DHCP_MAGIC_COOKIE    = 0x63825363,
   DHCP_DISCOVER        = 0x01,
   DHCP_OFFER           = 0x02,
   DHCP_REQUEST         = 0x03,
   DHCP_ACK             = 0x05,
   DHCP_OPT_NETMASK     = 0x01,
   DHCP_OPT_ROUTER      = 0x03,
   DHCP_OPT_DNS         = 0x06,
   DHCP_OPT_DOMAIN      = 0x0f,
   DHCP_OPT_RQ_ADDR     = 0x32,
   DHCP_OPT_LEASE_TIME  = 0x33,
   DHCP_OPT_MSG_TYPE    = 0x35,
   DHCP_OPT_SRV_ADDR    = 0x36,
   DHCP_OPT_RENEW_TIME  = 0x3a,
   DHCP_OPT_CLI_IDENT   = 0x3d,
   DHCP_OPT_FQDN        = 0x51,
   DHCP_OPT_END         = 0xff,
   DHCP_OPT_MIN_LEN     = 0x12c,
};


#define DHCP_SERVER_PORT    67
#define DHCP_CLIENT_PORT    68

void xdhcp_dissect_rsp (xpacket *xp);
void xdhcp_discovery (ub8 portid);

#endif
