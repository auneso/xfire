#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "xprintf.h"
#include "xalloc.h"
#include "xipmap.h"

Xipmap  *root;

static u_long addr (char *s)
{
  int a, b, c, d;

  if (!s) return 0;
  if (xsscanf(s, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
    return 0;
  if (a > 255 || b > 255 || c > 255 || d > 255)
    return 0;
  return ntohl((a << 24) + (b << 16) + (c << 8) + d);
}

#define BUILD_IP(IP) ((IP[0]<<24) | (IP[1]<<16) | (IP[2]<<8) | IP[3])

void
test1()
{

  u_long s, startval = addr("128.16.64.16");
  u_long  sval = addr("61.16.64.16");
  int iterate = 100000;
  const int start = 20;
  const int end = 32;
  const int step = 0x1000;
  int i, j, k, n, *rv;
  long st, et;
  xnetspec ip;
  

  st = clock();
  s = startval;
  n = 0;
  for (i = 0; i < iterate; i++, s += step) {
    for (j = start; j < end; j++) {
      ip.min = s & (~((1 << (32-j))-1) & 0xFFFFFFFF);
      ip.max = ip.min | (((1 << (32-j))-1) & 0xFFFFFFFF);
      xipmap_insert(root, &ip, NULL);
      n++;
    }
  }
  et = clock() - st;
  printf("insert %d for %ld times\n\n", n, et);


  st = clock();
  s = startval; k = 0; n = 0;
  for (i = 0; i < iterate; i++, s += step) {
//    for (j = start; j < end; j++) {
      if (!xipmap_search(root, s)) {
        n++;
      }
      else {
        k++;
      }
//      printf("%d %#lx %d\n", i, s, j);
//    }
  }
  et = clock() - st;
  printf("searching %d:%d for %d times\n\n", n, k, et);
}

int main()
{
  long st, et;


//while(1) {
  root = xipmap_create();
  st = clock();
  test1();
  et = clock() - st;
  printf("xipmap for %ld times\n\n", et);
  xipmap_destroy(root);
//}
  return 0;
}
