#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <stdio.h>
#include "xportmap.h"

xportmap *root;

void test1 (char *port)
{
  if (xportmap_insert_cmd(root, port)) {
    xportmap_compile(root);
    xportmap_dump(root);
  }
}

void test2 (void)
{
  xportspec ps;
  int iterate = 100;
  const int step = 10;
  int i, n, s = 10, cnt;
  long st, et;
  
  

  s = 10;
  n = 0;
  for (i = 0; i < iterate; i++, s += step) {
    ps.min = s;
    ps.max = s + 100;
    cnt = xportmap_insert(root, &ps);
    printf("cnt = %d\n", cnt);
    n++;
  }
  xportmap_compile(root);
  et = clock() - st;

  xportmap_dump(root);

  st = clock();

  s = 10; n = 0;
  for (i = 0; i < iterate; i++, s += step) {
    if (xportmap_search(root, (unsigned short)s+1)) {
      n++;
    }
  }
  et = clock() - st;
  printf("xportmap for %ld times\n\n", et);
  printf("searching found %d/%d\n\n", n, iterate);
}

int main(int argc, char *argv[])
{

//while(1) {
  root = xportmap_create();
  if (argc == 2) {
    test1(argv[1]);
  } else {
    test2();
  }
  xportmap_destroy(root);
//}
  return 0;
}
