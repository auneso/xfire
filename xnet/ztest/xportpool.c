#include <stdio.h>
#include "xportpool.h"



int main (int argc, char *argv[])
{
  int i, cnt, sport, eport, nport;
  xportpool *xpp;
  xsport **xsp;

  if (argc != 3) {
    printf("Usage %s start_port end_port\n", argv[0]);
    return 1;
  }
  sport = atoi(argv[1]);
  eport = atoi(argv[2]);
  nport = eport - sport + 1;
  
  xsp = xzalloc(nport * sizeof(xsport *)); 

  xpp  = xportpool_create(sport, eport);

  printf("POP ======================\n");
  for (i = 0; i < nport; i++) {
    if ((xsp[i] = xportpool_pop(xpp, 1, 1, 1, 1))) { 
      printf("pop port %d = %u\n", i, xsp[i]->port);
    }
  }
  cnt = xportpool_count(xpp, 1, 1, 1, 1);
  printf("pop count %d\n", cnt);
  
  printf("PUSH ======================\n");
  for (i = 0; i < nport; i += 2 ) {
    if (xsp[i]) {
       printf("push port %d = %u\n", i, xsp[i]->port);
       xportpool_push(xsp[i]); 
     }
  }
  cnt = xportpool_count(xpp, 1, 1, 1, 1);
  printf("push count %d\n", cnt);

  printf("POP2 ======================\n");
  for (i = 0 ; i < nport; i++) {
    if ((xsp[i] = xportpool_pop(xpp, 1, 1, 1, 1))) {
      printf("pop port %d = %u\n", i, xsp[i]->port);
    } else {
      printf("full port %d\n", i);
    }
  }
  cnt = xportpool_count(xpp, 1, 1, 1, 1);
  printf("pop2 count %d\n", cnt);
  return 0;
}
