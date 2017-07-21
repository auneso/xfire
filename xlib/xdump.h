#ifndef __XDUMP_H__
#define __XDUMP_H__
#include "dbuf.h"

void xdump (char *data, int dlen);
void xdump_dbuf (dynamic_buffer *dbuf, char *data, int dlen);

#endif
