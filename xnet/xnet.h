#ifndef __XNET_H__
#define __XNET_H__

#define XNET_TCP_PROTOCOL    0x01
#define XNET_UDP_PROTOCOL    0x02
#define XNET_ICMP_PROTOCOL   0x04
#define XNET_SESS_PROTOCOL   0x07

#define XNET_ARP_PROTOCOL    0x08
#define XNET_SUPORT_PROTOCOL 0x0f

#define XNET_ALIAS_NAME_SIZE 64
#define XNET_ALERT_MSG_SIZE 256

#define XNET_TCP_TIMEOUT          60
#define XNET_UDP_TIMEOUT          10
#define XNET_ICMP_TIMEOUT         10
#define XNET_ARP_CACHE_TIMEOUT    (24*60*60)

#define XNET_ACCEPT  0
#define XNET_DROP    1


#define XNET_IP4_BCAST (0xffffffffU)
#define XNET_IP4_ANY   (0x00000000U)

#define XNET_DIRECT      0
#define XNET_INBOUND     1
#define XNET_OUTBOUND    2

typedef enum {
  XBOUND_LS_LD = 0, // local src  - local dst
  XBOUND_LS_RD,     // local src  - remote dst
  XBOUND_RS_RD,     // remote src - remote dst
  XBOUND_RS_LD,     // remote src - local dst
} xbound_type;

void xnet_set_local (ub32 ip, ub32 mask);

int xnet_is_public (ub32 ip);
int xnet_is_local (ub32 ip);
xbound_type xnet_bound_type (ub32 sip, ub32 dip);

int xnet_is_unicast (ub8 address);
int xnet_is_multicast (ub32 address);
int xnet_is_loopback (ub32 address);
int xnet_is_broadcast (ub32 address);
int xnet_is_valid_src (ub32 address);

ub32 xnet_get_net_class (ub32 addr);
int xnet_check_ip (ub32 a);
int xnet_valid_netmask (ub32 mask);

ub32 xnet_my_ip(void);
ub32 xnet_my_gateway(void);
int xnet_set_gateway_info(char *addr);
void xnet_set_gateway(void);

char *xnet_protocol_str (ub8 protocol);

#endif
