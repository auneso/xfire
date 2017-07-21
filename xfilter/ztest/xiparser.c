#include <stdlib.h>
#include "format.h"
#include "xiparser.h"


int main (int argc, char *argv[])
{
  xnetspec ns;
 
  if (argc != 2) {
    printf("$s ip\n");
    printf("**  CIDR format a.b.c.d/xx\n"
           "**  IP range    a.b.c.d-e.f.g.h\n"
           "**  Single IP   a, a.b, a.b.c, a.b.c.d\n");
    return 0;
  }
  if (xip_parser(argv[1], &ns)) {
    printf("minr_ip = %s, max_ip = %s\n", intoa(ns.min), intoa(ns.max));
  } else {
    printf("ip format error\n");
  }
  return 0;
}

