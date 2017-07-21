#include <stdlib.h>
#include <string.h>
#include "xalloc.h"
#include "dbuf.h"

static int dbuf_makeroom (dynamic_buffer *dbuf, int n)
{
  /* Double size until it's greater than n (strictly > to leave room
     for trailing '\0' */
  int size = dbuf->allocated_len;
  char *buf;

  if (size > n) return 0;

  while (size <= n) size *= 2;

  /* Allocate memory */
  buf = (char *)xmalloc(size);

  /* Copy contents */
  memcpy(buf, dbuf->buffer, dbuf->len);

  /* Free old contents if necessary */
  if (dbuf->buffer != dbuf->static_buf) xfree(dbuf->buffer);
  dbuf->buffer = buf;
  dbuf->allocated_len = size;
  return 0;
}

void dbuf_init (dynamic_buffer *dbuf)
{
  dbuf->buffer = dbuf->static_buf;
  dbuf->len = 0;
  dbuf->allocated_len = DBUF_STATIC_SIZE;
  dbuf->buffer[0] = 0;
}

int dbuf_putc (dynamic_buffer *dbuf, char const c)
{
  if (dbuf->allocated_len <= dbuf->len + 1) {
    if (dbuf_makeroom(dbuf, dbuf->len + 1) != 0) return -1;
  }
  dbuf->buffer[dbuf->len++] = c;
  dbuf->buffer[dbuf->len] = 0;
  return 0;
}

int dbuf_puts (dynamic_buffer *dbuf, char const *str)
{
  int len = strlen(str);
  if (!len) return 0;

  if (dbuf->allocated_len <= dbuf->len + len) {
    if (dbuf_makeroom(dbuf, dbuf->len + len) != 0) return -1;
  }
  strcpy((dbuf->buffer + dbuf->len), str);
  dbuf->len += len;
  return 0;
}

int dbuf_putl (dynamic_buffer *dbuf, char const *str, int len)
{
  if (!len) return 0;
    
  if (dbuf->allocated_len <= dbuf->len + len) {
    if (dbuf_makeroom(dbuf, dbuf->len + len) != 0) return -1;
  } 
  memcpy((dbuf->buffer + dbuf->len), str, len);
  dbuf->len += len;
  dbuf->buffer[dbuf->len] = 0;
  return 0; 
}   


void dbuf_free (dynamic_buffer *dbuf)
{
  if (dbuf->buffer != dbuf->static_buf) free(dbuf->buffer);
  dbuf_init(dbuf);
}

