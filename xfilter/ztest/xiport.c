#include <stdlib.h>
#include "xiport.h"

char *iptab[] = {
  "0.0.0.1-0.0.0.10, 0.0.0.20-0.0.0.40",  
  "0.0.0.70-0.0.0.80, 0.0.0.90-0.0.0.100",  
  "0.0.0.150-0.0.0.200, 0.0.0.210-0.0.0.220",
  ""
};
char *portab[] = {
  "10-50,100-200",
  "20-30,40",
  "2000-4000"
};


int main (int argc, char *argv[])
{
  Xiport *xf;
  int i;
  unsigned int ip;
  unsigned short port;
  
  if (argc < 3) {
    printf("Usage : %s ip port\n", argv[0]);
    return 1;
  }

  ip = atoi(argv[1]);
  port = atoi(argv[2]);


  xf = xiport_create();
  for (i = 0; i < 3; i++) {
    xiport_insert(xf, i+1,  iptab[i], portab[i]);
  }

  if (xiport_find(xf, ip, port)) 
   printf("found \n");
  else 
   printf("not found \n");

  xiport_destroy(xf);
  return 0;
}

