#ifndef __XIPARSER_H__
#define __XIPARSER_H__

#include "xipmap.h"

/*
**  Given string, fills in the struct xnetspec (must be allocated)
**  Accept CIDR IP/mask format or IP_start-IP_end range.
**  Returns true (nonzero) on success, false (zero) on failure.
**  CIDR format a.b.c.d/xx
**  IP range    a.b.c.d-e.f.g.h
**  Single IP   a, a.b, a.b.c, a.b.c.d
*/
ub32 xip_parser (char *line, xnetspec *spec);


#endif
