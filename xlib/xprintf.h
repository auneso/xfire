#ifndef __XPINTF_H__
#define __XPINTF_H__

#include "xtypes.h"
#include "xalloc.h"

#ifdef __linux__
int xsnprintf(char *buf, size_t size, const char *fmt, ...);
int xsprintf(char *buf, const char *fmt, ...);
int xasprintf(char **ptr, const char *format, ...);
#else
#define xsnprintf snprintf
#define xsprintf sprintf
#define xsprintf asprintf
#endif
int xsscanf(const char *buf, const char * fmt, ...);
char*
xstrconcat (const char *string1, ...);

#endif /* __XSPRTF_H__ */
