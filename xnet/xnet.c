#include <string.h>
#include <arpa/inet.h>

#include "format.h"
#include "xstring.h"
#include "xiparser.h"
#include "xarp.h"
#include "xroute.h"
#include "xnet.h"

static xnetspec local_net;
static ub32 my_ip = 0;
static ub32 my_mask = 0;
static ub8  my_portid = 0;

int xnet_is_public (ub32 ip)
{
  if (ip < local_net.min || ip > local_net.max) return 1;
  return 0;
}

int xnet_is_local (ub32 ip)
{
  if (ip >= local_net.min && ip <= local_net.max) return 1;
  return 0;
}

ub32 xnet_my_ip (void)
{
  return my_ip;
}

ub32 xnet_my_gateway (void)
{
  return my_ip;
}

xbound_type xnet_bound_type (ub32 sip, ub32 dip)
{
  if (sip >= local_net.min && sip <= local_net.max
  &&  dip >= local_net.min && dip <= local_net.max) {
    return XBOUND_LS_LD;
  } else
  if ((sip < local_net.min || sip > local_net.max)
  &&  (dip < local_net.min || dip > local_net.max)) {
    return XBOUND_RS_RD;
  } else
  if ((sip < local_net.min || sip > local_net.max)
  &&   dip >= local_net.min && dip <= local_net.max) {
    return XBOUND_RS_LD;
  }
  return XBOUND_LS_RD;
}

void xnet_set_local (ub32 ip, ub32 mask)
{
  char range[64];
  char ipv4[IPV4_STR_SIZE];
  int count = 0;

  while (mask != 0) {
    count += mask & 1;
    mask >>= 1;
  }
  snprintf(range, sizeof(range), "%s/%d", intoab(ip, ipv4), count);
  xip_parser(range, &local_net);

//  printf("set_local_net min = %s, max = %s\n", intoa(local_net.min), intoa(local_net.max));
}

int xnet_is_unicast (ub8 address)
{
  const unsigned char *addr = (unsigned char *) &address;
  if ((addr[0] & 0xe0) == 0xe0)
    return 0; /* multicast */

  return 1;
}

int xnet_is_multicast (ub32 address)
{
  const unsigned char *addr = (unsigned char *) &address;
  if ((addr[0] != 0xff) && ((addr[0] & 0xe0) == 0xe0))
    return 1; /* multicast */

  return 0;
}

int xnet_is_loopback (ub32 address)
{
  const unsigned char *addr = (unsigned char *) &address;
  if (addr[0] == 0x7f)
    return 1;

  return 0;
}

int xnet_is_broadcast (ub32 addr)
{
  if (addr == XNET_IP4_BCAST)
    return 1;

  return 0;
}


int xnet_is_valid_src (ub32 address)
{
  if (xnet_is_broadcast(address)) {
    // "Source is a broadcast address, discard packet\n");
    return 0;
  } else 
  if (xnet_is_multicast(address)) {
    //"Source is a multicast address, discard packet\n");
    return 0;
  }
  return 1;
}

ub32 xnet_get_net_class (ub32 addr)
{
  ub32 nmask;

  addr = htonl(addr);
  if (IP_CLASSA(addr)) { /* determine network mask for address class */
    nmask = IP_CLASSA_NET;
  } else
  if (IP_CLASSB(addr)) {
    nmask = IP_CLASSB_NET;
  } else
  {
    nmask = IP_CLASSC_NET;
  }
  return nmask;
}

/* host order  */
int xnet_check_ip (ub32 a)
{
  /*
    RFC 1918 - Private Address Space

    The Internet Assigned Numbers Authority (IANA) has reserved the
    following three blocks of the IP address space for private internets:

    10.0.0.0        -   10.255.255.255  (10/8 prefix)
    172.16.0.0      -   172.31.255.255  (172.16/12 prefix)
    192.168.0.0     -   192.168.255.255 (192.168/16 prefix)
  */
  if (((a & 0xFF000000) == 0x0A000000 /* 10.0.0.0/8 */)
  ||  ((a & 0xFFF00000) == 0xAC100000 /* 172.16.0.0/12 */)
  ||  ((a & 0xFFFF0000) == 0xC0A80000 /* 192.168.0.0/16 */)
  ||  ((a & 0xFF000000) == 0x7F000000 /* 127.0.0.0/8 */)
     )
    return PRIVATE_IP;
  else if((a & 0xF0000000) == 0xE0000000 /* 224.0.0.0/4 */)
    return MULTICAST_IP;
  else if((a == 0xFFFFFFFF) || (a == 0))
    return BROADCAST_IP;
  return PUBLIC_IP;
}



/* function to report if the passed address falls within
 * the rfc 1918, (private VPN), range, meaning these are
 *  definitely spoof.
 */
int xnet_is_rfc1918 (uint32_t iph4)
{
  if (((iph4 & 0xff000000) == 0x0a000000) || /*       10/8 */
      ((iph4 & 0xff000000) == 0x00000000) || /*        0/8 */
      ((iph4 & 0xff000000) == 0x7f000000) || /*      127/8 */
      ((iph4 & 0xffff0000) == 0xa9fe0000) || /* 169.254/16 */
      ((iph4 & 0xfff00000) == 0xac100000) || /*  172.16/12 */
      ((iph4 & 0xffff0000) == 0xc0a80000))   /* 192.168/16 */
    return 1;
  return 0;
}

int xnet_valid_netmask (ub32 mask)
{
  int cnt = 0;
  int end = 0;
  int i;

  /*
   * Swap bytes for convenient parsing
   * e.g. 0x..f8ff will become 0xfff8..
   * Then, we count the consecutive bits
   *
   * */

  for (i = 0; i < 32; i++) {
    if ((mask << i) & 0x80000000) {
      if (end) return -1;
      cnt++;
    } else {
      end = 1;
    }
  }
  return cnt;
}

/* ip mask portid */
int xnet_set_gateway_info(char *addr)      
{
  char *ptr[3];
   
  if (msplit(addr, ptr, 3, " \t") != 3) {
     printf("Error xnet_set_my_ip = [%s]\n", addr);
    return 0;
  }
  my_ip   = atoin(ptr[0]);
  my_mask = atoin(ptr[1]);
  xnet_set_local(my_ip, my_mask);
  my_portid = atoi(ptr[2]);


  return 1;
}

void xnet_set_gateway (void)
{
  printf("LOCAL GATEWAY = %s %s %d\n", intoa(my_ip), intoa(my_mask), my_portid);
  xarp_add_virtual_mac(my_ip, my_portid, XGW_DEV_TYPE);

}


char *xnet_protocol_str (ub8 protocol)
{
  switch (protocol) {
    case XNET_TCP_PROTOCOL  :  return "tcp";
    case XNET_UDP_PROTOCOL  :  return "udp";
    case XNET_ICMP_PROTOCOL :  return "icmp";
    case XNET_ARP_PROTOCOL  :  return "arp";
    default : return "none";
  }
}
