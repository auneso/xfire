#include <stdlib.h>
#include "format.h"
#include "xipfind.h"


int main (int argc, char *argv[])
{
  Xfip *xm;
  xvector *xv;
  char *ptr;

  if (argc == 2) {
    int cidx;
    unsigned int ip = atoin(argv[1]);

    printf("ip = %s[%x]\n", argv[1], ip);
while (1) {
    xm = xfip_create();

    xfip_insert(xm, 1, 1, argv[1]);
    xfip_compile(xm);

    xv  = xfip_search(xm, ip);

    cidx = xfip_match (xv, 1);
    printf("cidx = %d : %s\n", cidx, intoa(ip));
    cidx = xfip_match (xv, 1);
    printf("cidx = %d : %s\n", cidx, intoa(ip));
    xfip_destroy (xm);
}
  }
  return 0;
}

