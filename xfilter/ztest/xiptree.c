#include <stdlib.h>
#include "format.h"
#include "xiptree.h"

char *insert = "hds";
char *cmd[] = {
//  "0.0.0.1-0.0.0.10, 0.0.0.1-0.0.0.20",    /* case 1 */
//  "168.188.0.0/16",    /* case 1 */
//  "0.0.0.0-192.168.10.179,192.168.10.181-255.255.255.255",
//  "168.188.200.0/24,168.188.252.0/24",    /* case 1 */
  "168.188.253.30/32,168.188.253.32/32,168.188.1.6/32,168.188.1.8/32,168.188.3.20/32,168.188.3.21/32,168.188.11.19/32,168.188.253.27/32,168.188.1.202/32,168.188.1.133/32",
  "203.253.211.1-203.253.211.255,192.203.138.1-192.203.138.255",
//  ".203",
  ""
};

int main (int argc, char *argv[])
{
  Xiptree *xt;
  char *ptr;
  ub32 ip = atoin(argv[1]);
  
//while (1) {
    int i = 0;
    xt = xiptree_create();
    while (*cmd[i]) {   
      printf("\nCASE [%d] = [%s]\n", i+1, cmd[i]);
      if (!xiptree_insert_cmd(xt, cmd[i], insert)) {
        printf("err = %s\n", cmd[i]);
      }
      i++;
    }
    printf("table cnt = %d\n", xiptree_table_count(xt));
    if (xiptree_search(xt, ip)) {
      printf("found = %s\n", argv[1]);
    } else {
      printf("Not found = %s\n", argv[1]);
    }
    xiptree_dump(xt);

    xiptree_destroy(xt);
//}
  return 0;
}

