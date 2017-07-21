#include <stdio.h>
#include <string.h>
#include "format.h"
#include "xroute.h"


int main (int argc, char *argv[])
{
  xroute_ipv4 *xr;
  char buf[1024];
  ub32 ip;

  xroute_create();

  xroute_dump();

  while (1) {

    fgets(buf, sizeof(buf), stdin);
    if (buf[0] == '.') break;
    buf[strlen(buf)] = 0; 
    ip = atoin(buf);

    printf("IP = %s\n", intoa(ip));

    xr = xroute_find(ip);
    if (xr) {
      printf("dst_ip = %s gateway = %s netmask = %s metric = %u portid = %u\n", intoa(xr->dst_ip), intoa(xr->gateway), intoa(xr->netmask), xr->metric, xr->portid);
    }
  }
  return 0;

}
