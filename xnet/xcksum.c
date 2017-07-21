/* 
** 2012-04-30 HDS
*/

#include "xproto.h"
#include "xtypes.h"
#include "xcksum.h"

#define  ip_cksum_carry(x) (x = (x >> 16) + (x & 0xffff), (~(x + (x >> 16)) & 0xffff))

static int ip_cksum_add (const void *buf, int len, int cksum)
{
  ub16 *sp = (ub16 *)buf;
  int n, sn;

  sn = (int) len / 2;
  n = (sn + 15) / 16;

  /* XXX - unroll loop using Duff's device. */
  switch (sn % 16) {
  case 0:  do {
    cksum += *sp++;
  case 15:
    cksum += *sp++;
  case 14:
    cksum += *sp++;
  case 13:
    cksum += *sp++;
  case 12:
    cksum += *sp++;
  case 11:
    cksum += *sp++;
  case 10:
    cksum += *sp++;
  case 9:
    cksum += *sp++;
  case 8:
    cksum += *sp++;
  case 7:
    cksum += *sp++;
  case 6:
    cksum += *sp++;
  case 5:
    cksum += *sp++;
  case 4:
    cksum += *sp++;
  case 3:
    cksum += *sp++;
  case 2:
    cksum += *sp++;
  case 1:
    cksum += *sp++;
    } while (--n > 0);
  }
  if (len & 1)
    cksum += htons(*(u_char *)sp << 8);

  return (cksum);
}

/* Standard BSD internet checksum routine. Uses libdnet helper functions. */
unsigned short in_xcksum (ub16 *ptr, int nbytes)
{
  int sum;

  sum = ip_cksum_add(ptr, nbytes, 0);
  return ip_cksum_carry(sum);
}

/* For computing TCP/UDP checksums, see RFC 1071 and TCP/IP Illustrated
   sections 3.2, 11.3, and 17.3. */
static unsigned short tcpudp_cksum (ub32 src, const ub32 dst, ub8 proto, ub16 len, const void *hstart)
{
  struct pseudo {
    ub32 src;
    ub32 dst;
    ub8 zero;
    ub8 proto;
    ub16 length;
  } hdr;
  int sum;

  hdr.src = src;
  hdr.dst = dst;
  hdr.zero = 0;
  hdr.proto = proto;
  hdr.length = htons(len);

  /* Get the ones'-complement sum of the pseudo-header. */
  sum = ip_cksum_add(&hdr, sizeof(hdr), 0);

  /* Add it to the sum of the packet. */
  sum = ip_cksum_add(hstart, len, sum);

  /* Fold in the carry, take the complement, and return. */
  return ip_cksum_carry(sum);
}

unsigned short ip_in_xcksum (struct x_ipv4_hdr *iph, unsigned short *ptr, int nbytes)
{
  return tcpudp_cksum (iph->ip_src, iph->ip_dst, iph->ip_p, nbytes, (void *)ptr);
}


#if 0
#include <slirp.h>

/*
 * Checksum routine for Internet Protocol family headers (Portable Version).
 *
 * This routine is very heavily used in the network
 * code and should be modified for each CPU to be as fast as possible.
 *
 * XXX Since we will never span more than 1 mbuf, we can optimise this
 */
#define mtod(m,t)        ((t)(m)->m_data)

#define ADDCARRY(x)  (x > 65535 ? x -= 65535 : x)
#define REDUCE {l_util.l = sum; sum = l_util.s[0] + l_util.s[1];        \
        (void)ADDCARRY(sum);}

int cksum (struct mbuf *m, int len)
{
  register uint16_t *w;
  register int sum = 0;
  register int mlen = 0;
  int byte_swapped = 0;

  union {
    uint8_t  c[2];
    uint16_t s;
  } s_util;
  union {
    uint16_t s[2];
    uint32_t l;
  } l_util;

  if (m->m_len == 0) goto cont;
  w = mtod(m, uint16_t *);

  mlen = m->m_len;

  if (len < mlen) mlen = len;
  /*
   * Force to even boundary.
   */
  if ((1 & (uintptr_t)w) && (mlen > 0)) {
    REDUCE;
    sum <<= 8;
    s_util.c[0] = *(uint8_t *)w;
    w = (uint16_t *)((int8_t *)w + 1);
    mlen--;
    byte_swapped = 1;
  }
  /*
   * Unroll the loop to make overhead from
   * branches &c small.
   */
  while ((mlen -= 32) >= 0) {
    sum += w[0];  sum += w[1];  sum += w[2];  sum += w[3];
    sum += w[4];  sum += w[5];  sum += w[6];  sum += w[7];
    sum += w[8];  sum += w[9];  sum += w[10]; sum += w[11];
    sum += w[12]; sum += w[13]; sum += w[14]; sum += w[15];
    w += 16;
  }
  mlen += 32;
  while ((mlen -= 8) >= 0) {
    sum += w[0]; sum += w[1]; sum += w[2]; sum += w[3];
    w += 4;
  }
  mlen += 8;
  if (mlen == 0 && byte_swapped == 0)
     goto cont;
  REDUCE;
  while ((mlen -= 2) >= 0) {
    sum += *w++;
  }

  if (byte_swapped) {
    REDUCE;
    sum <<= 8;
    if (mlen == -1) {
      s_util.c[1] = *(uint8_t *)w;
      sum += s_util.s;
      mlen = 0;
    } else 
       mlen = -1;
  } else if (mlen == -1)
     s_util.c[0] = *(uint8_t *)w;

cont:
  if (mlen == -1) {
    /* The last mbuf has odd # of bytes. Follow the
     standard (the odd byte may be shifted left by 8 bits
         or not as determined by endian-ness of the machine) */
    s_util.c[1] = 0;
    sum += s_util.s;
  }
  REDUCE;
  return (~sum & 0xffff);
}





#endif


