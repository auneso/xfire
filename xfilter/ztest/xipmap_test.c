#include <stdlib.h>
#include "xipmap.h"

int main (int argc, char *argv[])
{
  Xipmap *xm;

  unsigned int ip = atoin(argv[1]);
  printf("ip = %d\n", ip);
  int nRet;

  xm = xipmap_create();

  //xipmap_insert_cmd(xm, "10.1.5.108;10.1.5.109;10.1.4.1/24;10.1.3.1~10.1.3.255", NULL);
  
  xipmap_insert_cmd(xm, "10.1.5.108;10.1.5.109", NULL);
  xipmap_insert_cmd(xm, "10.1.4.1/24", NULL);
  xipmap_insert_cmd(xm, "10.1.3.1~10.1.3.255", NULL);

  nRet = xipmap_search (xm, ip);

  printf("nRet = %d\n", nRet);

  xipmap_destroy(xm);

  return 0;
}

