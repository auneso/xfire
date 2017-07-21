#ifndef __XLOG_H__
#define __XLOG_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>


#if defined (DEBUG)

#define DEBUG_MSG(x, ...) do {                                 \
  fprintf(stderr, "DEBUG: "x"\n", ## __VA_ARGS__ );            \
} while(0)

#else 
#define DEBUG_MSG(x, ...)
#endif

#ifdef DEBUG_BUILD
#  define DEBUG(x...) fprintf(stderr, x)
#else
#  define DEBUG(x...) do {} while (0)
#endif /* ^DEBUG_BUILD */

#define ERRORF(x...)  fprintf(stderr, x)
#define SAYF(x...)    printf(x)

#define WARN(x...) do { \
    ERRORF("[!] WARNING: " x); \
    ERRORF("\n"); \
  } while (0)

#define FATAL(x...) do { \
    ERRORF("[-] PROGRAM ABORT : " x); \
    ERRORF("\n         Location : %s(), %s:%u\n\n", \
           __FUNCTION__, __FILE__, __LINE__); \
    exit(1); \
  } while (0)

#define ABORT(x...) do { \
    ERRORF("[-] PROGRAM ABORT : " x); \
    ERRORF("\n         Location : %s(), %s:%u\n\n", \
           __FUNCTION__, __FILE__, __LINE__); \
    abort(); \
  } while (0)

#define PFATAL(x...) do { \
    ERRORF("[-] SYSTEM ERROR : " x); \
    ERRORF("\n        Location : %s(), %s:%u\n", \
           __FUNCTION__, __FILE__, __LINE__); \
    perror("      OS message "); \
    ERRORF("\n"); \
    exit(1); \
  } while (0)

void xfire_fatal (const char *message, ...);
void xfire_warning (const char *message, ...);
void xfire_logging (const char *message, ...);

void xfire_err(int eval, const char *fmt, ...);
void xfire_warn(const char *fmt, ...);
void xfire_errx(int eval, const char *fmt, ...);
void xfire_warnx(const char *fmt, ...);

#endif
