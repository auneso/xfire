/*
* ICMP - Internet Control Message Protocol
*/
/*
** 2014-02-18 HDS
** 2014-09-18 HDS  xp->odev
*/
#include <string.h>

#include "xbridge.h"
#include "xcksum.h"
#include "xvhost.h"
#include "xicmp.h"
#include "format.h"
#include "xnet.h"
/**
 * IP_DEFAULT_TTL: Default value for Time-To-Live used by transport layers.
 */
#ifndef IP_DEFAULT_TTL
#define IP_DEFAULT_TTL                  255
#endif



/* chage mac, ip, ttl, type */
/* 0               8                16                              31
   +--------------+----------------+----------------------------------+
   |  Type = 8    |    Code = 0    |      Header Checksum             |
   +--------------+----------------+----------------------------------+
   |         Identifier            |      Sequence Number             |
   +-------------------------------+----------------------------------+
   |                             Data                                 | 
   +------------------------------------------------------------------+
   +------------------------------------------------------------------+
*/
static void icmp_echo_reply (xpacket *xp)
{
  char tmac[XETHER_ADDR_LEN];

  memcpy(tmac, xp->p_ethh->ether_shost, XETHER_ADDR_LEN);  
  memcpy(xp->p_ethh->ether_shost, xp->p_ethh->ether_dhost, XETHER_ADDR_LEN);  
  memcpy(xp->p_ethh->ether_dhost, tmac, XETHER_ADDR_LEN);  

  xp->p_iph->ip_src = htonl(xp->dst_ip); 
  xp->p_iph->ip_dst = htonl(xp->src_ip); 

  xp->src_ip = ntohl(xp->p_iph->ip_src);
  xp->dst_ip = ntohl(xp->p_iph->ip_dst);
  
  xp->p_iph->ip_ttl = IP_DEFAULT_TTL;

  xp->p_iph->ip_sum = 0;
  xp->p_iph->ip_sum = in_xcksum((unsigned short *)xp->p_iph, XIP_HDR_LENGTH(xp->p_iph));

  xp->p_icmph->icmp_type = ICMP_ECHOREPLY;
  xp->p_icmph->icmp_code = 0;
  
  xp->p_icmph->icmp_sum = 0;
  xp->p_icmph->icmp_sum = in_xcksum((unsigned short *)xp->p_icmph, xp->data_len);

  xp->send = XFIRE_SEND_PACKET;
}

int xicmp_dissect (xpacket *xp)
{

#ifdef XICMP_DEBUG
  if (xp->p_icmph->icmp_type == ICMP_ECHO) {
    printf("ICMP_ECHO :  src = %s, dst = %s, type = %d. code = %d\n",  
          intoa(xp->src_ip), intoa(xp->dst_ip), xp->p_icmph->icmp_type, xp->p_icmph->icmp_code);
  } else
  if (xp->p_icmph->icmp_type == ICMP_ECHOREPLY) {
    printf("ICMP_ECHOREPLY  :  src = %s, dst = %s, type = %d. code = %d\n", 
           intoa(xp->src_ip), intoa(xp->dst_ip), xp->p_icmph->icmp_type, xp->p_icmph->icmp_code);
  }
#endif

  if (xp->p_icmph->icmp_type == ICMP_ECHO) {
    if (xvhost_find(xp->dst_ip)) {
      icmp_echo_reply(xp);
    }

#ifdef XICMP_DEBUG
    printf("ICMP_ECHOREPLY   src = %s, dst = %s, type = %d. code = %d\n",  
           intoa(xp->src_ip), intoa(xp->dst_ip), xp->p_icmph->icmp_type, xp->p_icmph->icmp_code);
#endif
  }
  return 1;
}

