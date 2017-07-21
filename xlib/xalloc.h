#ifndef __XMALLOC_H__
#define __XMALLOC_H__


#include <stdlib.h>

#define XMEM_STAT
#define XMEM_REDZONE

struct memstat_ {
  int malloc_called;
  int calloc_called;
  int realloc_called;
  int free_called;

  size_t cur_size;
  size_t max_size;
  size_t limit;
};
typedef struct memstat_ memstat_t;

void *xmalloc(size_t size);
void *xzalloc(size_t size);
void *xcalloc(size_t nmemb, size_t size);
void *xrealloc(void *ptr, size_t size);
void  xfree(void *ptr);

void xmemstat(memstat_t *ms);
void xmemreset(void);
void xmemdump (void);

char *xstrdup(char *str);
char *xstrndup (char *str, int len);
char *xstrndup_lowcase (char *str, int len);
void *xmemdup(void *str, int len);
void *xresize (void *p, int nbytes);

#endif
