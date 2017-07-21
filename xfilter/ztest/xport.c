#include "xport.h"

int main (int argc, char *argv[])
{
  ub16 *port_list;
  int i, pnum;
  
  if (argc < 2) {
    printf("Usage : %s port_list\n", argv[0]);
    return 1;
  }
  port_list = xport_parser(argv[1],  &pnum);
  for (i = 0; i < pnum; i++) {
    printf("port[%d] = [%u]\n", i , port_list[i]);
  }

  if (argc == 3) { 
    if (xport_in_ports(atoi(argv[2]), port_list, pnum)) {
      printf("found port = %s\n", argv[2]);
    }
    else  printf("not found port = %s\n", argv[2]);
  }
  free(port_list);
  return 0;
}
