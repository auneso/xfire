#include <stdio.h>
#include <string.h>
#include <time.h>

#include "xpint.h"
#include "xtypes.h"
#include "format.h"

#include <stdio.h>

static char *mac = "54:ab:3a:bc:cf:60";

int main (int argc, char *argv[])
{
  char *sm, dm[6], dd[6];
  ub64 m;
  long st, et;
  long i, j, k, l;

  sm = string_etheraddr((ub8 *)mac);
  m = xpntoh48(sm);

  xphtonl48(dm, m);
  printf("mac = %s, dm = %s\n", mac, etheraddr_string((ub8 *)dm));
 
  st = clock();
  
  for (i = 0; i < 1000000000000; i++) {
    for (j = 0; j < 1000000000000; j++) {
      for (k = 0; k < 1000000000000; k++) xphtonl48(dm, m);
    }
  }
  et = clock() - st;
  printf("xphtonl48 = %ld\n", et);


  st = clock();
  for (i = 0; i < 1000000000000; i++) {
    for (j = 0; j < 1000000000000; j++) {
      for (k = 0; k < 1000000000000; k++) memcpy(dd, mac, 6);
    }
  }
  et = clock() - st;
  printf("memcpy = %ld\n", et);

 
  return 0;
}
