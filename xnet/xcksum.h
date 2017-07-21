#ifndef __XCKSUM_H__
#define __XCKSUM_H__

unsigned short in_xcksum (ub16 *ptr,int nbytes);
unsigned short ip_in_xcksum (struct x_ipv4_hdr *iph, unsigned short *ptr, int nbytes);

#endif

