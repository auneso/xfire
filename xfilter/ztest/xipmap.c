#include <stdlib.h>
#include "format.h"
#include "xipmap.h"

char *cmd[] = {
  "0.0.0.1-0.0.0.10, 0.0.0.1-0.0.0.20",    /* case 1 */
  "0.0.0.1-0.0.0.10, 0.0.0.1-0.0.0.5",     /* case 2 */
  "0.0.0.1-0.0.0.10, 0.0.0.1-0.0.0.20",    /* case 3 */
  "0.0.0.1-0.0.0.10, 0.0.0.10-0.0.0.20",   /* case 4 */
  "0.0.0.1-0.0.0.5, 0.0.0.10-0.0.0.20, 0.0.0.7-0.0.0.9",    /* case 5 */
  "0.0.0.1-0.0.0.5, 0.0.0.10-0.0.0.20, 0.0.0.7-0.0.0.12",    /* case 6 */
  "*",    /* case 1 */
  ""
};


int main (int argc, char *argv[])
{
  Xipmap *xm;
  xvector *xv;
  char *ptr;
  ub32 ip_cnt;

  if (argc == 3) {
    unsigned int ip = atoin(argv[2]);

    printf("ip = %s[%x]\n", argv[2], ip);

    xm = xipmap_create();
    ip_cnt = xipmap_insert_cmd(xm, argv[1], "HDS");
     printf("xipmap_insert_cmd ip_cnt [%u] = [%s]\n", ip_cnt, argv[1]);

    
//    xipmap_dump(xm);

    xv  = xipmap_lookup(xm, ip);

    if (xv) {
      if ((ptr = (char *)xvector_first(xv))) do {
        printf("found = [%s]\n", ptr);
      } while ((ptr = (char *)xvector_next(xv)));
    }
    else   printf("not found = %s\n", intoa(ip));
    xipmap_destroy(xm);

  } else
  if (argc == 2) {
    unsigned int ip = atoin(argv[1]);
    int i = 0;

    xm = xipmap_create();

    while (cmd[i]) {
//      printf("\nCASE [%d] = [%s]\n", i+1, cmd[i]);
      ip_cnt = xipmap_insert_cmd(xm, cmd[i], cmd[i]);
      printf("xipmap_insert_cmd ip_cnt [%u] = [%s]\n", ip_cnt, cmd[i]);
      i++;
    }

    xv  = xipmap_lookup(xm, ip);

    if (xv) {
      printf("found = %s\n", intoa(ip));
      if ((ptr = (char *)xvector_first(xv))) do {
        printf("found = [%s]\n", ptr);
      } while ((ptr = (char *)xvector_next(xv)));
    } else 
       printf("not found = %s\n", intoa(ip));

    xipmap_destroy(xm);
  } else {
//    while (1) {
      int i = 0;
      xm = xipmap_create();
      while (*cmd[i]) {
        ip_cnt = xipmap_insert_cmd(xm, cmd[i],  cmd[i]);
        printf("\nip_cnt [%u] = [%s]\n", ip_cnt, cmd[i]);
        i++;
      }
      xipmap_destroy(xm);
//    }
  }
  return 0;
}


