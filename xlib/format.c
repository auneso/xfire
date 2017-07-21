/*
** 2008/10/29 - HDS 
** 2014/04/17 - HDS intoa change
** 2014/07/30 - HDS format_lock
** 2015/08/03 - HDS fmt_throughput 1024 -> 1000
** 2015/08/27 - HDS idx count bug fixed
** 2015/08/28 - HDS buf para
** 2015/09/21 - HDS update intoab, atoin
*/

#include <sys/types.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include "xprintf.h"
#include "itoa.h"
#include "format.h"

/* 100,000,000,000 */
char *fmt_commab (sb64 n, char *buf, int size)
{
  int len = 1, posn = 1, sign = 1, bufsize = 31;
  char *ptr;

  ptr = buf + 3;

  if (2 > bufsize) {
ABORT:
    *buf = 0;
    return buf;
  }

  *ptr-- = 0;
  --bufsize;
  if (0L > n) {
    sign = -1;
    n = -n;
  }

  for ( ; len <= bufsize; ++len, ++posn) {
    *ptr-- = (char)((n % 10L) + '0');
    if (0L == (n /= 10L))
      break;
    if (0 == (posn % 3)) {
      *ptr-- = ',';
      ++len;
    }
    if (len >= bufsize)
      goto ABORT;
  }

  if (0 > sign) {
    if (len >= bufsize)
      goto ABORT;
    *ptr-- = '-';
    ++len;
  }

  memmove(buf, ++ptr, len + 1);

  return buf;
}


/* 100,000,000,000 */
char *fmt_comma (sb64 n)
{
  static short idx = 0;
  static char str[4][32];
  char *buf;
  buf = str[idx];
  idx = (idx + 1) % 4;
  return fmt_commab(n, buf, sizeof(str[0]));
}

char *fmt_bytesb (ub64 bytes, ub64 mod, char *p, int len)
{
  ub64 l ,m, n;

  l = m = bytes; 
  if (l < mod) { xsnprintf(p, len, "%d", bytes); return p; }

  m = l / mod; n = (l - m * mod) / 11; l = m; /* Kilo <> Milli */
  if (l < mod) { xsnprintf(p, len, "%d.%02dK", (int)m, (int)n); return p; }

  m = l / mod; n = (l - m * mod) / 11; l = m; /* Mega <> Micro */
  if (l < mod) { xsnprintf(p, len, "%d.%02dM", (int)m, (int)n); return p; }

  m = l / mod; n = (l - m * mod) / 11; l = m; /* Giga <> Nano */
  if (l < mod) { xsnprintf(p, len, "%d.%02dG", (int)m, (int)n); return p; }

  m = l / mod; n = (l - m * mod) / 11; l = m; /* Tera <> Pico */
  if (l < mod) { xsnprintf(p, len, "%d.%02dT", (int)m, (int)n); return p; }

  m = l / mod; n = (l - m * mod) / 11; l = m; /* Peta <> Femto */
  if (l < mod) { xsnprintf(p, len, "%d.%02dP", (int)m, (int)n); return p; }

  m = l / mod; n = (l - m * mod) / 11; l = m; /* Exa  <> Atto */
  if (l < mod) { xsnprintf(p, len, "%d.%02dE", (int)m, (int)n); return p; }
  return ("+inf.");
}

char *fmt_bytes (ub64 bytes)
{
  static short idx = 0;
  static char str[4][12];
  char *buf;

  buf = str[idx];
  idx = (idx + 1) % 4;
  return fmt_bytesb(bytes, 1024, buf, sizeof(str[0]));
}

char *fmt_throughputb (double nbytes)
{
  static short idx = 0;
  static char str[4][12];
  char *buf;

  buf = str[idx];
  idx = (idx + 1) % 4;
  return fmt_bytesb(nbytes * 8, 1000, buf, 12); /* nbits*/
}

char *format_numbers (double val, char *buf, ub32 buf_len, ub8 add_decimals) 
{
  u_int a1 = ((u_long)val / 1000000000) % 1000;
  u_int a = ((u_long)val / 1000000) % 1000;
  u_int b = ((u_long)val / 1000) % 1000;
  u_int c = (u_long)val % 1000;
  u_int d = (u_int)((val - (u_long)val)*100) % 100;

  if (add_decimals) {
    if (val >= 1000000000) {
      snprintf(buf, buf_len, "%u'%03u'%03u'%03u.%02d", a1, a, b, c, d);
    } else if (val >= 1000000) {
      snprintf(buf, buf_len, "%u'%03u'%03u.%02d", a, b, c, d);
    } else if (val >= 100000) {
      snprintf(buf, buf_len, "%u'%03u.%02d", b, c, d);
    } else if (val >= 1000) {
      snprintf(buf, buf_len, "%u'%03u.%02d", b, c, d);
    } else
      snprintf(buf, buf_len, "%.2f", val);
  } else {
    if (val >= 1000000000) {
      snprintf(buf, buf_len, "%u'%03u'%03u'%03u", a1, a, b, c);
    } else if (val >= 1000000) {
      snprintf(buf, buf_len, "%u'%03u'%03u", a, b, c);
    } else if (val >= 100000) {
      snprintf(buf, buf_len, "%u'%03u", b, c);
    } else if (val >= 1000) {
      snprintf(buf, buf_len, "%u'%03u", b, c);
    } else
      snprintf(buf, buf_len, "%u", (unsigned int)val);
  }

  return(buf);
}

char *fmt_secondb (time_t sec, char *p, int len)
{
  time_t day, hour, min;

  day = sec / (3600 * 24);
  if (day > 0) {
    sec -= day * (3600 * 24);
    hour = sec / 3600;
    if (hour > 0) sec -= hour * 3600; 
    min = sec / 60;
    if (min > 0) sec -= min * 60;
    if (day > 99)
      xsnprintf(p, len, "%04u-%02u", day, hour);
    else 
      xsnprintf(p, len, "%02u-%02u:%02u", day, hour, min);
  } else {
    hour = sec / 3600;
    if (hour > 0) sec -= hour * 3600;
    min = sec / 60; 
    if (min > 0) sec -= min * 60;
    xsnprintf(p, len, "%02u:%02u:%02u", hour, min, sec);
  }
  return(p);
}

char *fmt_second (time_t sec)
{
  static short idx = 0;
  static char str[4][12];
  char *p;

  p = str[idx];
  idx = (idx + 1) % 4;

  return fmt_secondb (sec, p, sizeof(str[0]));
}


char *fmt_msecondb (ub64 usec, char *p, int len)
{
  time_t day, hour, min;
  ub64 sec, msec;

  sec = usec / 1000;
  msec = (usec - sec * 1000) / 10;

  day = sec / (3600 * 24);
  if (day > 0) {
    sec -= day * (3600 * 24);
    hour = sec / 3600;
    if (hour > 0) sec -= hour * 3600;
    min = sec / 60;
    if (min > 0) sec -= min * 60;
    if (day > 99)
      xsnprintf(p, len, "%04u-%02u", day, hour);
    else
      xsnprintf(p, len, "%02u-%02u:%02u", day, hour, min);
  } else {
    hour = sec / 3600;
    if (hour > 0) {
      sec -= hour * 3600;
      min = sec / 60;
      if (min > 0) sec -= min * 60;
      xsnprintf(p, len, "%02u:%02u:%02u", hour, min, (ub32)sec);
    }
    else {
      min = (sec / 60);
      if (min > 0) sec -= min*60;
      if (msec > 99) msec %= 100;
      xsnprintf(p, len, "%02u:%02u.%02u", min, (ub32)sec, (ub32)msec);
    }
  }
  return(p);
}

char *fmt_msecond (ub64 usec)
{
  static short idx = 0;
  static char str[4][12];
  char *p;

  p = str[idx];
  idx = (idx + 1) % 4;
  return fmt_msecondb(usec, p, sizeof(str[0]));

}


/*  Format the timestamp */
char *ts_format (int sec, int usec)
{
  static char buf[sizeof("00:00:00.000000")];
  (void)xsnprintf(buf, sizeof(buf), "%02d:%02d:%02d.%06u", sec / 3600, (sec % 3600) / 60, sec % 60, usec);

  return buf;
}



static const char hexa[] = "0123456789abcdef";
static const char HEXA[] = "0123456789ABCDEF";

char *etheraddr_stringb (ub8 *ep, char *buf)
{
  u_int  i, j;
  char   *cp, *p;

  p = cp = buf;

  if ((j = *ep >> 4) < 16)
    *cp++ = hexa[j];
  else
    *cp++ = '0';
  *cp++ = hexa[*ep++ & 0xf];

  for (i = 5; (int)--i >= 0;) {
    *cp++ = ':';
    if ((j = *ep >> 4) < 16)
      *cp++ = hexa[j];
    else
      *cp++ = '0';

    *cp++ = hexa[*ep++ & 0xf];
  }
  *cp = '\0';
  return (p);
}

char *etheraddr_string (ub8 *ep)
{   
  static short idx = 0;
  static char str[4][MAC_STR_SIZE];
  char   *p; 
    
  p = str[idx];
  idx = (idx + 1) % 4;
  return etheraddr_stringb(ep, p);
}

char *string_etheraddr (ub8 *ep)
{
  static char ether[7];
  short  i, j;

  memset ((char *)&ether, '\0', sizeof (ether));
  for (i = 0; (i < 17) && (ep[i]); i += 3) {
    for (j = 0; j < 16; j++) {
      if (ep[i] == hexa[j]) break;
      if (ep[i] == HEXA[j]) break;
    }
    ether[i/3] = j << 4;

    for (j = 0; j < 16; j++) {
      if (ep[i+1] == hexa[j]) break;
      if (ep[i+1] == HEXA[j]) break;
    }
    ether[i/3] = ether[i/3] | j;
  }
  ether[6] = '\0';
  return ((char *)&ether);
}

#if 0
/*      
 * borrowed from trafshow.
 *      
 * A faster replacement for inet_ntoa().
 */     

char *intoa (unsigned int addr)
{
  register char *cp;
  register unsigned int byte;
  register int n;
  static char buf[sizeof(".xxx.xxx.xxx.xxx")];
 
  addr = ntohl(addr);

  cp = &buf[sizeof buf];
  *--cp = '\0';

  n = 4;
  do {
    byte = addr & 0xff;
    *--cp = byte % 10 + '0';
    byte /= 10;
    if (byte > 0) {
      *--cp = byte % 10 + '0';
      byte /= 10;
      if (byte > 0)
        *--cp = byte + '0';
    }   
    *--cp = '.';
    addr >>= 8;
  } while (--n > 0);
                
  return cp + 1;
}               
#endif

char *intoab (ub32 a, char *org_dst)
{
  const char digits[] = "0123456789";
  int i;
  char *dst = org_dst;
  

  for (i = 0; i < 4; ++i) {
    int n = (a >> (24 - i * 8)) & 0xFF;
    int non_zerop = 0;

    if (non_zerop || n / 100 > 0) {
      *dst++ = digits[n / 100];
      n %= 100;
      non_zerop = 1;
    }
    if (non_zerop || n / 10 > 0) {
      *dst++ = digits[n / 10];
      n %= 10;
      non_zerop = 1;
    }
    *dst++ = digits[n];
    if (i != 3)
      *dst++ = '.';
  }
  *dst++ = '\0';
  return org_dst;
}

char *intoa (unsigned int addr) 
{
  static short idx = 0;
  static char buf[4][IPV4_STR_SIZE];
  char *str;
  
  str = buf[idx];
  idx = (idx+1) % 4;
  return intoab(addr, str);
}

ub32 atoin (char *s)
{
  ub32 a, b, c, d;

  if (!s) return 0;

  if (xsscanf(s, "%u.%u.%u.%u", &a, &b, &c, &d) != 4 || (a | b | c | d) > 255) {
    return atoi(s);
  } 
  return (a << 24) + (b << 16) + (c << 8) + d;
}

ub32 atoin_n (char *s)
{
  ub32 a, b, c, d, v;
  int n;

  if (!s) return 0;

  a = b = c = d = 0;
  n = xsscanf(s, "%u.%u.%u.%u", &a, &b, &c, &d);
  switch (n) {
    case 1 :
      v = (a << 24);
      break;
    case 2 : 
      v = (a << 24) + (b << 16);
      break;
    case 3 : 
      v = (a << 24) + (b << 16) + (c << 8);
      break;
    case 4 :
      v = (a << 24) + (b << 16) + (c << 8) + d;
      break;
    default :
      v = 0;
  }
    
  if ((a | b | c | d) > 255) return 0;
  return v;
}

int ipcmp (ub32 ip1, ub32 ip2)
{
  int diff;
  if ((diff = ((ip1 >> 24) & 0xff) - ((ip2 >> 24) & 0xff)) != 0) return diff;
  if ((diff = ((ip1 >> 16) & 0xff) - ((ip2 >> 16) & 0xff)) != 0) return diff;
  if ((diff = ((ip1 >>  8) & 0xff) - ((ip2 >>  8) & 0xff)) != 0) return diff;
  diff = (ip1 & 0xff) - (ip2 & 0xff); 
  return diff;
}

void sprinthex (char *to_buf, void const *from, int from_len)
{
  unsigned char const *from_buf = (unsigned char const *) from;

  while (from_len-- > 0) {
    *(to_buf++) = hexa[((*from_buf) >> 4) & 0xf];
    *(to_buf++) = hexa[(*from_buf) & 0xf];
    from_buf++;
  }
  *to_buf = 0;
}


static ub8 EBCDIC_to_ASCII[256] = {
   0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
   0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
   0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
   0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
   0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
   0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
   0x2E, 0x2E, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
   0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x2E, 0x3F,
   0x20, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x2E, 0x2E, 0x2E, 0x2E, 0x3C, 0x28, 0x2B, 0x7C,
   0x26, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x2E, 0x2E, 0x21, 0x24, 0x2A, 0x29, 0x3B, 0x5E,
   0x2D, 0x2F, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x2E, 0x2E, 0x7C, 0x2C, 0x25, 0x5F, 0x3E, 0x3F,
   0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x2E, 0x2E, 0x3A, 0x23, 0x40, 0x27, 0x3D, 0x22,
   0x2E, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
   0x68, 0x69, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x2E, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70,
   0x71, 0x72, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x2E, 0x7E, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
   0x79, 0x7A, 0x2E, 0x2E, 0x2E, 0x5B, 0x2E, 0x2E,
   0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x5D, 0x2E, 0x2E,
   0x7B, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
   0x48, 0x49, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x7D, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
   0x51, 0x52, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x5C, 0x2E, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
   0x59, 0x5A, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
   0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
   0x38, 0x39, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E
};

/*
 * prints only "printable" characters, the
 * others are represented as '.'
 */

int ascii_format (const ub8 *buf, size_t len, ub8 *dst)
{
   ub32 i = 0;

   /* some sanity checks */
   if (len == 0 || buf == NULL) {
      *dst = 0;
      return 0;
   }

   /* make the substitions */
   for (i = 0; i < len; i++) {
      if (isprint((int)buf[i]) || buf[i] == '\n' || buf[i] == '\t' )
         dst[i] = buf[i];
      else
         dst[i] = '.';
   }

   return len;
}

/*
 * convert from ebcdic to ascii
 */

int ebcdic_format (const ub8 *buf, size_t len, ub8 *dst)
{
   ub32 i = 0;

   /* some sanity checks */
   if (len == 0 || buf == NULL) {
      *dst = 0;
      return 0;
   }

   /* convert from ebcdic to ascii */
   for (i = 0; i < len; i++)
      dst[i] = (char) EBCDIC_to_ASCII[(ub8)buf[i]];

   return ascii_format(dst, len, dst);
}



#define  isoctal(c)  (((u_char)(c)) >= '0' && ((u_char)(c)) <= '7')
#define  isvisible(c)                                         \
  (((u_int)(c) <= UCHAR_MAX && isascii((u_char)(c)) &&        \
  (((c) != '*' && (c) != '?' && (c) != '[' && (c) != '#') ||  \
    (flag & VIS_GLOB) == 0) && isgraph((u_char)(c))) ||       \
  ((flag & VIS_SP) == 0 && (c) == ' ') ||                     \
  ((flag & VIS_TAB) == 0 && (c) == '\t') ||                   \
  ((flag & VIS_NL) == 0 && (c) == '\n') ||                    \
  ((flag & VIS_SAFE) && ((c) == '\b' ||                       \
    (c) == '\007' || (c) == '\r' ||                           \
    isgraph((u_char)(c)))))

/*
 * vis - visually encode characters
 */
char *vis (char *dst, int c, int flag, int nextc)
{
  if (isvisible(c)) {
    *dst++ = c;
    if (c == '\\' && (flag & VIS_NOSLASH) == 0)
      *dst++ = '\\';
    *dst = '\0';
    return (dst);
  }

  if (flag & VIS_CSTYLE) {
    switch(c) {
    case '\n':
      *dst++ = '\\';
      *dst++ = 'n';
      goto done;
    case '\r':
      *dst++ = '\\';
      *dst++ = 'r';
      goto done;
    case '\b':
      *dst++ = '\\';
      *dst++ = 'b';
      goto done;
    case '\a':
      *dst++ = '\\';
      *dst++ = 'a';
      goto done;
    case '\v':
      *dst++ = '\\';
      *dst++ = 'v';
      goto done;
    case '\t':
      *dst++ = '\\';
      *dst++ = 't';
      goto done;
    case '\f':
      *dst++ = '\\';
      *dst++ = 'f';
      goto done;
    case ' ':
      *dst++ = '\\';
      *dst++ = 's';
      goto done;
    case '\0':
      *dst++ = '\\';
      *dst++ = '0';
      if (isoctal(nextc)) {
        *dst++ = '0';
        *dst++ = '0';
      }
      goto done;
    }
  }
  if (((c & 0177) == ' ') || (flag & VIS_OCTAL) ||
      ((flag & VIS_GLOB) && (c == '*' || c == '?' || c == '[' || c == '#'))) {
    *dst++ = '\\';
    *dst++ = ((u_char)c >> 6 & 07) + '0';
    *dst++ = ((u_char)c >> 3 & 07) + '0';
    *dst++ = ((u_char)c & 07) + '0';
    goto done;
  }
  if ((flag & VIS_NOSLASH) == 0)
    *dst++ = '\\';
  if (c & 0200) {
    c &= 0177;
    *dst++ = 'M';
  }
  if (iscntrl((u_char)c)) {
    *dst++ = '^';
    if (c == 0177)
      *dst++ = '?';
    else
      *dst++ = c + '@';
  } else {
    *dst++ = '-';
    *dst++ = c;
  }
done:
  *dst = '\0';
  return (dst);
}

/*
 * strvis, strnvis, strvisx - visually encode characters from src into dst
 *  
 *  Dst must be 4 times the size of src to account for possible
 *  expansion.  The length of dst, not including the trailing NULL,
 *  is returned. 
 *
 *  Strnvis will write no more than siz-1 bytes (and will NULL terminate).
 *  The number of bytes needed to fully encode the string is returned.
 *
 *  Strvisx encodes exactly len bytes from src into dst.
 *  This is useful for encoding a block of data.
 */
int
strvis (char *dst, const char *src, int flag)
{
  char c;
  char *start;

  for (start = dst; (c = *src);)
    dst = vis(dst, c, flag, *++src);
  *dst = '\0';
  return (dst - start);
}

int
strnvis (char *dst, const char *src, size_t siz, int flag)
{
  char *start, *end;
  char tbuf[5];
  int c, i;

  i = 0;
  for (start = dst, end = start + siz - 1; (c = *src) && dst < end; ) {
    if (isvisible(c)) {
      i = 1;
      *dst++ = c;
      if (c == '\\' && (flag & VIS_NOSLASH) == 0) {
        /* need space for the extra '\\' */
        if (dst < end)
          *dst++ = '\\';
        else {
          dst--;
          i = 2;
          break;
        }
      }
      src++;
    } else {
      i = vis(tbuf, c, flag, *++src) - tbuf;
      if (dst + i <= end) {
        memcpy(dst, tbuf, i);
        dst += i;
      } else {
        src--;
        break;
      }
    }
  }
  if (siz > 0)
    *dst = '\0';
  if (dst + i > end) {
    /* adjust return value for truncation */
    while ((c = *src))
      dst += vis(tbuf, c, flag, *++src) - tbuf;
  }
  return (dst - start);
}

int
strvisx (char *dst, const char *src, size_t len, int flag)
{
  char c;
  char *start;

  for (start = dst; len > 1; len--) {
    c = *src;
    dst = vis(dst, c, flag, *++src);
  }
  if (len)
    dst = vis(dst, *src, flag, '\0');
  *dst = '\0';
  return (dst - start);
}



/* integer limits */
#define FP32 4294967295ULL
#define FP64 18446744073709551615ULL

uint64_t countercalc (uint64_t a, uint64_t b)
{
  /* no flip */
  if (b >= a) {
    return b - a;
  /* flip exists */
  } else {
    /* original counter is 64bit */
    if (a > FP32) {
      return FP64 - a + b;
    /* original counter is 32bit */
    } else {
      return FP32 - a + b;
    }
  }
}


/*_________________---------------------------__________________
  _________________        printHex           __________________
  -----------------___________________________------------------
*/

static ub8 bin2hex(int nib) { return (nib < 10) ? ('0' + nib) : ('A' - 10 + nib); }

int printHex (const u_char *a, int len, u_char *buf, int bufLen, int marker, int bytesPerOutputLine)
{
  int b = 0, i = 0;
  for (; i < len; i++) {
    u_char byte;
    if (b > (bufLen - 10)) break;
    if (marker > 0 && i == marker) {
      buf[b++] = '<';
      buf[b++] = '*';
      buf[b++] = '>';
      buf[b++] = '-';
    }
    byte = a[i];
    if (isprint(byte)) {
      buf[b++] = byte; 
    } else {
      buf[b++] = bin2hex(byte >> 4);
      buf[b++] = bin2hex(byte & 0x0f);
    }
    if (i > 0 && (i % bytesPerOutputLine) == 0) buf[b++] = '\n';
    else {
      // separate the bytes with a dash       
      if (i < (len - 1)) buf[b++] = '-';
    }
  }
  buf[b] = '\0'; 
  return b;
} 


#if 0
#define KILOBYTE       1024
#define MEGABYTE    1048576
#define GIGABYTE 1073741824

/* Converts a filesize to a string.
 */
int filesize2str (char *buffer, int len, off_t fsize)
{
  int result = 0;

  buffer[len - 1] = '\0';
  if (fsize < KILOBYTE) {
    result = snprintf(buffer, len - 1, "%llu byte", (long long)fsize);
  } else if (fsize < MEGABYTE) {
    result = snprintf(buffer, len - 1, "%0.1f kB", ((double)(fsize >> 6)) / 16);
  } else if (fsize < GIGABYTE) {
    result = snprintf(buffer, len - 1, "%0.1f MB", ((double)(fsize >> 16)) / 16);
  } else {
    result = snprintf(buffer, len - 1, "%0.1f GB", ((double)(fsize >> 26)) / 16);
  }     

  return (result < 0) ? 0 : result;
}
#endif
