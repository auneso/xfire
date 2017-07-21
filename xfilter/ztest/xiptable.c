#include <stdio.h>
#include "format.h"
#include "xrbt.h"
#include "xiptree.h"



int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("usage : %s ipaddress\n", argv[0]);
    return 1;
  }


  XRBTR32 *table = xiptree_make_table (argv[1]);
  XRBTN32 *ip;
  int i = 1; 
  if ((ip = xrbt32_first(table))) do {
    printf("idx = %d, ip = %s\n", i, intoa(ip->key));
    i++;
  } while ((ip = xrbt32_next(ip)));

  xrbt32_destroy(table);

  return 0;
 
}

