#ifndef __XPORT_H__
#define __XPORT_H__
#include "xtypes.h"

ub16 *xport_parser (char *str_ports, int *port_num);
int xport_in_ports (ub16 port, ub16 *port_list, int port_num);

#endif

