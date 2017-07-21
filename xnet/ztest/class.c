#include <string.h>
#include "format.h"
#include "xproto.h"

/* function to report if the passed address falls within
 * the rfc 1918, (private VPN), range, meaning these are
 *  definitely spoof.
 */
static int is_rfc1918 (uint32_t iph4)
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

int main (int argc, char *argv[])
{
  ub32 ipaddr;

  if (argc != 2) {
    printf("Usage : class ip-addr\n");
    return 1;
  }

  ipaddr = atoin(argv[1]);

  if (is_rfc1918 (ipaddr)) printf("Loacl IP\n");
  else                     printf("Public IP\n");

  if (IN_CLASSA(ipaddr)) {
    printf("Class A\n");
    return 0;
  }
  if (IN_CLASSB(ipaddr)) {
    printf("Class B\n");
    return 0;
  }
  if (IN_CLASSC(ipaddr)) {
    printf("Class C\n");
    return 0;
  }
  return 0;
}
