/*
 * https://en.wikipedia.org/wiki/Dynamic_Host_Configuration_Protocol
 * RFC: 2131
 *
 *    0                   1                   2                   3
 *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *    |     op (1)    |   htype (1)   |   hlen (1)    |   hops (1)    |
 *    +---------------+---------------+---------------+---------------+
 *    |                            xid (4)                            |
 *    +-------------------------------+-------------------------------+
 *    |           secs (2)            |           flags (2)           |
 *    +-------------------------------+-------------------------------+
 *    |         ciaddr (4)   Client IP Address                        |
 *    +---------------------------------------------------------------+
 *    |         yiaddr (4)   "Your” IP Address                        |
 *    +---------------------------------------------------------------+
 *    |         siaddr (4)   Server IP Address                        |
 *    +---------------------------------------------------------------+
 *    |         giaddr (4)   Gateway IP Address                       |
 *    +---------------------------------------------------------------+
 *    |         chaddr (16)  Client Hardware Address                  |
 *    +---------------------------------------------------------------+
 *    |         sname  (64)  Server Name                              |
 *    +---------------------------------------------------------------+
 *    |         file   (128) Boot Filename                            |
 *    +---------------------------------------------------------------+
 *    |                       options  (variable)                     |
 *    +---------------------------------------------------------------+
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
//#include <net/ethernet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define __FAVOR_BSD
#include <netinet/udp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ifaddrs.h>


#include "format.h"
#include "xproto.h"
#include "xcksum.h"
#include "xpacket.h"
#include "xvhost.h"
#include "xpint.h"
#include "xarp.h"
#include "xdhcp.h"
#include "xdpdk.h"


static ub8 *get_dhcp_option (ub8 opt, ub8 *ptr, ub8 *end)
{
  do {
    /* we have found our option */
    if (*ptr == opt)
      return ptr + 1;

    /*
     * move thru options :
     *
     * OPT LEN .. .. .. OPT LEN .. ..
     */
    ptr = ptr + 2 + (*(ptr + 1));

  } while (ptr < end && *ptr != DHCP_OPT_END);

  return NULL;
}


/*
 * This function will be called for any incoming DHCP responses
 */
void
xdhcp_dissect_rsp (xpacket *xp)
{
#if 0
  if (memcmp(xp->p_ethh->ether_dhost, xp->xdev->xmac, XETHER_ADDR_LEN)) {
    /* not my dhcp response */
    return;
  }
#endif 

  dhcp_t *dhcp = (dhcp_t *)xp->data_ptr;
   
  /* sanity check */
  if (xp->data_len < sizeof(dhcp_t)) return; 

  /* check for the magic cookie */
  if (dhcp->magic_cookie != htonl(DHCP_MAGIC_COOKIE)) return;


  /* Get the IP address given by the server */
  ub32 my_ip = ntohl(dhcp->yiaddr);
  
  {
    ub32 netmask = 0;
    ub32 router = 0;
    ub32 dns = 0;
    ub32 lease_time = 0;

    ub8 *options, *opt, *end;
    options = (ub8 *)(dhcp + 1);
    end = (ub8 *)(xp->data_ptr + xp->data_len);

    opt = get_dhcp_option(DHCP_OPT_MSG_TYPE, options, end);

     /* option not found */
    if (opt == NULL) return;
     
    /* netmask */
    if ((opt = get_dhcp_option(DHCP_OPT_NETMASK, options, end)) != NULL)
      netmask = xpntohl(opt + 1);

    /* default gateway */
    if ((opt = get_dhcp_option(DHCP_OPT_ROUTER, options, end)) != NULL)
      router = xpntohl(opt + 1);
      
       /* default gateway */

    if ((opt = get_dhcp_option(DHCP_OPT_LEASE_TIME, options, end)) != NULL)
      lease_time = xpntohl(opt + 1);

    /* dns server */
    if ((opt = get_dhcp_option(DHCP_OPT_DNS, options, end)) != NULL)
      dns = xpntohl(opt + 1);

    printf("\n\n $$$$ DHCP IP = %s, netmask = %s, route = %s, dns = %s lease_time = %u\n", intoa(my_ip), intoa(netmask), intoa(router), intoa(dns), lease_time);
  }
}


/*
 * Ethernet output handler - Fills appropriate bytes in ethernet header
 */
static void
ether_output (xpacket *xp, u_int8_t *mac, int len)
{
  struct x_ethernet_hdr *eframe = (struct x_ethernet_hdr *)xp->frame;

  memcpy(eframe->ether_shost, mac, XETHER_ADDR_LEN);
  memset(eframe->ether_dhost, -1,  XETHER_ADDR_LEN);
  eframe->ether_type = htons(ETHERTYPE_IP);

  len = len + sizeof(struct x_ethernet_hdr);

  xp->mbuf->pkt_len = xp->mbuf->data_len = len;

  /* Send the packet on wire */
  /* HDS --------------------*/
  xdpdk_send_single_packet (xp->mbuf, xp->xdev->portid);
}

/*
 * IP Output handler - Fills appropriate bytes in IP header
 */
static void
ip_output (struct ip *ip_header, int *len)
{
  *len += sizeof(struct ip);

  ip_header->ip_hl = 5;
  ip_header->ip_v = IPVERSION;
  ip_header->ip_tos = 0x10;
  ip_header->ip_len = htons(*len);
  ip_header->ip_id = htonl(0xffff);
  ip_header->ip_off = 0;
  ip_header->ip_ttl = 16;
  ip_header->ip_p = IPPROTO_UDP;
  ip_header->ip_sum = 0;
  ip_header->ip_src.s_addr = 0;
  ip_header->ip_dst.s_addr = 0xFFFFFFFF;

  ip_header->ip_sum = in_xcksum((unsigned short *) ip_header, sizeof(struct ip));
}

/*
 * UDP output - Fills appropriate bytes in UDP header
 */
static void udp_output (struct udphdr *udp_header, int *len)
{
  if (*len & 1) *len += 1;
  *len += sizeof(struct udphdr);

  udp_header->uh_sport = htons(DHCP_CLIENT_PORT);
  udp_header->uh_dport = htons(DHCP_SERVER_PORT);
  udp_header->uh_ulen = htons(*len);
  udp_header->uh_sum = 0;
}

/*
 * DHCP output - Just fills DHCP_BOOTREQUEST
 */
static void dhcp_output (dhcp_t *dhcp, u_int8_t *mac, int *len)
{
  *len += sizeof(dhcp_t);
  memset(dhcp, 0, sizeof(dhcp_t));

  dhcp->opcode = DHCP_BOOTREQUEST;
  dhcp->htype = DHCP_HARDWARE_TYPE_10_EHTHERNET;
  dhcp->hlen = 6;
  memcpy(dhcp->chaddr, mac, DHCP_CHADDR_LEN);

  dhcp->magic_cookie = htonl(DHCP_MAGIC_COOKIE);
}

/*
 * Adds DHCP option to the bytestream
 */
static int fill_dhcp_option (u_int8_t *packet, u_int8_t code, u_int8_t *data, u_int8_t len)
{
  packet[0] = code;
  packet[1] = len;
  memcpy(&packet[2], data, len);

  return len + (sizeof(u_int8_t) * 2);
}

/*
 * Fill DHCP options
 */
static int fill_dhcp_discovery_options (dhcp_t *dhcp)
{
  int len = 0;
  u_int32_t req_ip;
  u_int8_t parameter_req_list[] = {MESSAGE_TYPE_REQ_SUBNET_MASK, MESSAGE_TYPE_ROUTER, MESSAGE_TYPE_DNS, MESSAGE_TYPE_DOMAIN_NAME};
  u_int8_t option;

  option = DHCP_OPTION_DISCOVER;
  len += fill_dhcp_option(&dhcp->bp_options[len], MESSAGE_TYPE_DHCP, &option, sizeof(option));
  req_ip = htonl(0xc0a8010a);
  len += fill_dhcp_option(&dhcp->bp_options[len], MESSAGE_TYPE_REQ_IP, (u_int8_t *)&req_ip, sizeof(req_ip));
  len += fill_dhcp_option(&dhcp->bp_options[len], MESSAGE_TYPE_PARAMETER_REQ_LIST, (u_int8_t *)&parameter_req_list, sizeof(parameter_req_list));
  option = 0;
  len += fill_dhcp_option(&dhcp->bp_options[len], MESSAGE_TYPE_END, &option, sizeof(option));

  return len;
}

/*
 * Send DHCP DISCOVERY packet
 */
static void dhcp_discovery (xpacket *xp, ub8 *mac)
{
  int plen = 0;
  char *packet;
  struct udphdr *udp_header;
  struct ip *ip_header;
  dhcp_t *dhcp;

  packet = xp->frame;

  ip_header = (struct ip *)(packet + sizeof(struct x_ethernet_hdr));
  udp_header = (struct udphdr *)(((char *)ip_header) + sizeof(struct ip));
  dhcp = (dhcp_t *)(((char *)udp_header) + sizeof(struct udphdr));

  plen = fill_dhcp_discovery_options(dhcp);
  dhcp_output(dhcp, mac, &plen);
  udp_output(udp_header, &plen);
  ip_output(ip_header, &plen);
  ether_output(xp, mac, plen);
}

void xdhcp_discovery (ub8 portid)
{
  xpacket *xp, xpkt;
  xdevice *xdev = xpacket_get_xdevice(portid);

  if (xdev == NULL) {
    printf("xdhcp_discovery bad portid = %d\n", portid); 
    return;
  }
  xp = xpacket_pkt_alloc(xdev, &xpkt);

  /* Send DHCP DISCOVERY packet */
  dhcp_discovery(xp, xdev->xmac);
}

