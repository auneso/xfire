#ifndef __DBUF_H__
#define __DBUF_H__

#define DBUF_STATIC_SIZE 2048
typedef struct {
    char *buffer;
    int len;
    int allocated_len;
    char static_buf[DBUF_STATIC_SIZE];
} dynamic_buffer;

void dbuf_init(dynamic_buffer *dbuf);
int  dbuf_putc(dynamic_buffer *dbuf, char const c);
int  dbuf_puts(dynamic_buffer *dbuf, char const *str);
int  dbuf_putl(dynamic_buffer *dbuf, char const *str, int l);
void dbuf_free(dynamic_buffer *dbuf);

#define DBUF_VAL(buf_ptr) ((buf_ptr)->buffer)
#define DBUF_LEN(buf_ptr) ((buf_ptr)->len)
#endif
