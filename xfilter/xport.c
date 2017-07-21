/*
** 2015/12/28 - HDS
*/
#include <string.h>
#include "xtypes.h"
#include "xalloc.h"
#include "xport.h"


/*
 * Determine is <port> is in <ports>, recursively. In less than 15
 * comparisons for 65535 elements.
 */
static int rec_pip (u_short port, u_short *ports, int s, int e)
{
  if (s == e) return(ports[s] == port);
  else {
    int mid = (e + s) / 2;
    if (port > ports[mid]) return(rec_pip(port, ports, mid+1, e));
    else return(rec_pip(port, ports, s, mid));
  }
}


/*
 * is a port in our port list ? 
 *
 * We use the function rec_pip(), which is
 * recursive, and which will determine if
 * a port is present by dichotomy.
 *
 */
int xport_in_ports (u_short port, u_short *ports, int len)
{
 int mid = (len-1) / 2;
 int ret;
 
 if (port > ports[mid]) ret = rec_pip(port, ports, mid, len);
 else ret = rec_pip(port, ports, 0, mid);
 return(ret);
}


#define MAX_PORT_STANDARD    1024

static int intcmp(const void *a, const void *b)
{
    return *(const ub16 *)a - *(const ub16 *)b;
}

ub16 *xport_parser (char *str_ports, int *port_num)
{
  if (str_ports == NULL || *str_ports == 0) {
    *port_num = 0;
    return NULL;
  }
  int i = 0, eol = 0, nP, pNum, pcount, nports = 10;
  char *t, *t2, *p;
  ub16 start_port = 1;
  ub16 end_port = MAX_PORT_STANDARD;
  ub16 *port_list = (ub16 *)xmalloc(sizeof(ub16) * (nports + 1));
  port_list[0] = 0;
  char *sport = xstrdup((char *)str_ports);
  p = sport; 

  while (!eol) {
    t = p;
    while (*p && *p != ',') p++;
    if (*p == 0) eol = 1;
    if (t != p) {
      *p = 0;
      // t is next port or port range
      if ((t2 = strchr(t, '-'))) {
        // is a port range
        start_port = atoi(t);
        end_port = atoi(t2+1);
        if (start_port == 0 || end_port == 0 || end_port < start_port) {
//        fprintf(stderr, "Incorrect ports, starting = %d, ending = %d\n", start_port, end_port);
          xfree(port_list);
          xfree(sport);
          *port_num = 0;
          return NULL;
        }
        for (nP = 0; nP <= end_port - start_port ; nP++) {
          if (i == nports) {
            nports += 10;
            port_list = (ub16 *)realloc(port_list, sizeof(ub16) * (nports + 1));
          }
          port_list[i++] = start_port + nP;
        }
        start_port = 0;
      }
      else {
        // is a single port
        if (i == nports) {
          nports += 10;
          port_list = (ub16 *)realloc(port_list, sizeof(ub16) * (nports + 1));
        }
        pNum = atoi(t);
        port_list[i++] = pNum == 0 ? -1 : pNum; //if not number  -> -1
        start_port = 0;
      }
      if (eol) break;
      t = ++p;
    }
  }
  port_list[i] = 0;

  pcount = 0;
  while (port_list[pcount] != 0) ++pcount;

  qsort(port_list, pcount, sizeof(ub16), intcmp);
  //will remove dups from tail of array one by one (replacing with -1)
  for (i = pcount; i > 0 ; i-- ) {
    if ((port_list[i] == port_list[i-1])  &&(port_list[i] != 65535)) {
//      fprintf(stdout, "Duplicate port found in list: %d\n", port_list[i]);
      port_list[i] = 65535;
    }
  }
  xfree(sport);
  *port_num = pcount;
  return port_list;
}
