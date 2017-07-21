/*
** 2013/10/30 - HDS
** 2015/09/24 - HDS  Single value IP, Wild IP
** 2015/10/30 - HDS  '*'
** 2017/04/01 - HDS  return ip count
*/

#include "xtypes.h"
#include "xprintf.h"
#include "xstring.h"
#include "xiparser.h"

/*
**  Given string, fills in the struct xnetspec (must be allocated)
**  Accept CIDR IP/mask format or IP_start-IP_end range.
**  Returns true (nonzero) on success, false (zero) on failure.
**  CIDR format  a.b.c.d/xx
**  IP range     a.b.c.d-e.f.g.h
**  Wild IP      a, a., a.b, a.b.c, a.b.c.d  
*/

/* Macro to test for valid IP address in four integers */
#define VALID_IP(IP) ((IP[0] | IP[1] | IP[2] | IP[3]) < 256)

/* Macro to build 32-bit IP from four integers */
#define BUILD_IP(IP) ((IP[0]<<24) | (IP[1]<<16) | (IP[2]<<8) | IP[3])

ub32 xip_parser (char *line, xnetspec *spec)
{
  unsigned int IP1[4], IP2[4];
  int maskbits = 32;  /* if using CIDR IP/mask format */
  char *ptr ;
  int n;

  ptr = strchr(line, '.');
  if (!ptr) {
    if (*line == '*') {
      spec->min = 1;
      spec->max = 0xFFFFFFFF;
    } else
    if (strchr(line, '-') && (xsscanf(line, "%u - %u", &IP1[0], &IP2[0]) == 2)) {
      spec->min = IP1[0];
      spec->max = IP2[0];
    } else
    if (xsscanf(line, "%u", &IP1[0]) == 1) {
      spec->min = spec->max = IP1[0];
    } else return 0;
    return (spec->max - spec->min +  1);
  }
 
  /* Try parsing IP/mask, CIDR format */
  if (strchr(line, '/')
  && (xsscanf(line, "%u.%u.%u.%u/%d", &IP1[0], &IP1[1], &IP1[2], &IP1[3], &maskbits) == 5)
  && VALID_IP(IP1) && (maskbits >= 1) && (maskbits <= 32))
  {
    spec->min = BUILD_IP(IP1) & (~((1 << (32-maskbits))-1) & 0xFFFFFFFF);
    spec->max = spec->min | (((1 << (32-maskbits))-1) & 0xFFFFFFFF);
    return (spec->max - spec->min +  1);
  } else
  /* Try parsing a range. Spaces around hyphen are optional. */
  if (strchr(line, '-')
  && (xsscanf(line, "%u.%u.%u.%u - %u.%u.%u.%u", &IP1[0], &IP1[1], &IP1[2], &IP1[3], &IP2[0], &IP2[1], &IP2[2], &IP2[3]) == 8)
  && VALID_IP(IP1) && VALID_IP(IP2)) {
    spec->min = BUILD_IP(IP1);
    spec->max = BUILD_IP(IP2);
    if (spec->max >= spec->min) return (spec->max - spec->min +  1);
    else                        return 0;
  } else {
    /* Try simple IP address */
    IP1[0] = IP1[1] = IP1[2] = IP1[3] = 0;
     n = xsscanf(line, "%u.%u.%u.%u", &IP1[0], &IP1[1], &IP1[2], &IP1[3]);
     switch (n) {
       case 1 :
         spec->min = (IP1[0] << 24);
         spec->max = spec->min | 0x00ffffff;
         break;
       case 2 :
         spec->min = (IP1[0] << 24) + (IP1[1] << 16);
         spec->max = spec->min | 0x0000ffff;
         break;
       case 3 :
         spec->min = (IP1[0] << 24) + (IP1[1] << 16) + (IP1[2] << 8);
         spec->max = spec->min | 0x000000ff;
         break;
       case 4 :
         spec->min = (IP1[0] << 24) + (IP1[1] << 16) + (IP1[2] << 8) + IP1[3];
         spec->max = spec->min;
         break;
       default :
         return 0;
    }
  }

  if (VALID_IP(IP1)) return (spec->max - spec->min +  1);
  return 0;  
}

