
/* 
 * Fri Jul 13 2001 Crutcher Dunnavant <crutcher+kernel@datastacks.com>
 * - changed to provide snprintf and vsnprintf functions
 * linux/lib/vsprintf.c
 *
 * 2008/10/31 - HDS
 */

#include <stdarg.h>
#include <limits.h>
#include "xstring.h"
#include "xalloc.h"
#include "xprintf.h"


static ub32 div64_32 (sb64 *n, ub32 base)
{
  ub64 rem = *n;
  ub64 b = base;
  ub64 res, d = 1;
  ub32 high = rem >> 32;

  /* Reduce the thing a bit first */
  res = 0;
  if (high >= base) {
    high /= base;
    res = (ub64) high << 32;
    rem -= (ub64) (high*base) << 32;
  }

  while ((sb64)b > 0 && b < rem) {
    b = b+b;
    d = d+d;
  }

  do {
    if (rem >= b) {
      rem -= b;
      res += d;
    }
    b >>= 1;
    d >>= 1;
  } while (d);

  *n = res;
  return rem;
}


/* http://www.fefe.de/libowfat */
unsigned int fmt_double (char *dest, double d, int maxlen, int prec)
{
  union {
    double d;
    unsigned long long x;
  } __u = { .d=d, };

  /* step 1: extract sign, mantissa and exponent */
  signed int s = __u.x>>63;
  signed long e = ((__u.x>>52)&((1<<11)-1))-1023;
  /* step 2: exponent is base 2, compute exponent for base 10 */
  signed long e10=1+(long)(e*0.30102999566398119802); /* log10(2) */
  /* step 3: calculate 10^e10 */
  int i;
  double tmp = 10.0;
  char *oldbuf = dest;
  int initial = 1;
  int writeok = (dest!=0);

  if (s) { d = -d; if (writeok) *dest='-'; --maxlen; dest++; }
  if (d == 0.0) {
    if (writeok) *dest = '0';
    --maxlen; dest++;
    return dest - oldbuf;
  }
  if ((i = e10) >= 0) {
    while (i > 10) { tmp = tmp*1e10; i-=10; }
    while (i > 1) { tmp = tmp*10; --i; }
  } else {
    i = (e10 = -e10);
    while (i > 10) { tmp = tmp*1e-10; i -= 10; }
    while (i > 1) { tmp = tmp / 10; --i; }
  }
  while (d / tmp < 1) {
    --e10;
    tmp /= 10.0;
  }
  /* step 4: see if precision is sufficient to display all digits */
  if (e10 > prec) {
    /* use scientific notation */
    int len = fmt_double(writeok?dest:0,d/tmp,maxlen,prec);
    if (len == 0) return 0;
    maxlen -= len; dest += len;
    if (--maxlen >= 0) {
      if (writeok) *dest='e';
      ++dest;
    }
    for (len = 1000; len > 0; len /= 10) {
      if (e10 >= len || !initial) {
        if (--maxlen >= 0) {
          if (writeok) *dest = (e10/len)+'0';
          ++dest;
        }
        initial = 0;
        e10 = e10 % len;
      }
    }
    if (maxlen >= 0) return dest - oldbuf;
    return 0;
  }
  /* step 5: loop through the digits, inserting the decimal point when
   * appropriate */
  for (; prec > 0; ) {
    double tmp2 = d/tmp;
    char c;
    d -= ((int)tmp2*tmp);
    c = ((int)tmp2);
    if ((!initial) || c) {
      if (--maxlen >= 0) {
        initial = 0;
        if (writeok) *dest = c+'0';
        ++dest;
      } else
        return 0;
      --prec;
    }
    if (tmp > 0.5 && tmp < 1.5) {
      tmp = 1e-1;
      initial = 0;
      if (--maxlen >= 0) {
        if (writeok) *dest = '.';
        ++dest;
      } else
        return 0;
    } else
      tmp /= 10.0;
  }
  return dest-oldbuf;
}

/**
 * simple_strtoul - convert a string to an unsigned long
 * @cp: The start of the string
 * @endp: A pointer to the end of the parsed string will be placed here
 * @base: The number base to use
 */
static unsigned long
simple_strtoul(const char *cp, char **endp, unsigned int base)
{
  unsigned long result = 0,value;

  if (!base) {
    base = 10;
    if (*cp == '0') {
      base = 8;
      cp++;
      if ((*cp == 'x') && IsXDigit(cp[1])) {
        cp++;
        base = 16;
      }
    }
  }
  while (IsXDigit(*cp) &&
         (value = IsDigit(*cp) ? *cp-'0' : toupper(*cp)-'A'+10) < base) {
    result = result*base + value;
    cp++;
  }
  if (endp)
    *endp = (char *)cp;
  return result;
}

/**
 * simple_strtol - convert a string to a signed long
 * @cp: The start of the string
 * @endp: A pointer to the end of the parsed string will be placed here
 * @base: The number base to use
 */
static long simple_strtol (const char *cp,char **endp, unsigned int base)
{
  if(*cp=='-')
    return -simple_strtoul(cp+1, endp, base);
  return simple_strtoul(cp, endp, base);
}

/**
 * simple_strtoull - convert a string to an unsigned long long
 * @cp: The start of the string
 * @endp: A pointer to the end of the parsed string will be placed here
 * @base: The number base to use
 */
static unsigned long long
simple_strtoull (const char *cp, char **endp, unsigned int base)
{
  unsigned long long result = 0,value;

  if (!base) {
    base = 10;
    if (*cp == '0') {
      base = 8;
      cp++;
      if ((*cp == 'x') && IsXDigit(cp[1])) {
        cp++;
        base = 16;
      }
    }
  }
  while (IsXDigit(*cp) && (value = IsDigit(*cp) ? *cp-'0' : (IsLower(*cp)
      ? toupper(*cp) : *cp)-'A'+10) < base) {
    result = result*base + value;
    cp++;
  }
  if (endp)
    *endp = (char *)cp;
  return result;
}

/**
 * simple_strtoll - convert a string to a signed long long
 * @cp: The start of the string
 * @endp: A pointer to the end of the parsed string will be placed here
 * @base: The number base to use
 */
static long long simple_strtoll (const char *cp,char **endp,unsigned int base)
{
  if (*cp == '-')
    return -simple_strtoull(cp+1,endp,base);
  return simple_strtoull(cp,endp,base);
}

static int skip_atoi(const char **s)
{
  int i=0;

  while (IsDigit(**s))
    i = i*10 + *((*s)++) - '0';
  return i;
}

#define ZEROPAD   1    /* pad with zero */
#define SIGN      2    /* unsigned/signed long */
#define PLUS      4    /* show plus */
#define SPACE     8    /* space if plus */
#define LEFT     16    /* left justified */
#define SPECIAL  32    /* 0x */
#define LARGE    64    /* use 'ABCDEF' instead of 'abcdef' */


static char *number (char *buf, char *end, sb64 num, int base,
                     int size, int precision, int type)
{
  char c,sign,tmp[66];
  const char *digits;
  static const char small_digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  static const char large_digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i;

  digits = (type & LARGE) ? large_digits : small_digits;
  if (type & LEFT)
    type &= ~ZEROPAD;
  if (base < 2 || base > 36)
    return 0;
  c = (type & ZEROPAD) ? '0' : ' ';
  sign = 0;
  if (type & SIGN) {
    if (num < 0) {
      sign = '-';
      num = -num;
      size--;
    } else if (type & PLUS) {
      sign = '+';
      size--;
    } else if (type & SPACE) {
      sign = ' ';
      size--;
    }
  }
  if (type & SPECIAL) {
    if (base == 16)
      size -= 2;
    else if (base == 8)
      size--;
  }
  i = 0;
  if (num == 0)
    tmp[i++] = '0';
  else while (num != 0)
    tmp[i++] = digits[div64_32(&num, base)];
  if (i > precision)
    precision = i;
  size -= precision;
  if (!(type & (ZEROPAD+LEFT))) {
    while (size-->0) {
      if (buf <= end)
        *buf = ' ';
      ++buf;
    }
  }
  if (sign) {
    if (buf <= end)
      *buf = sign;
    ++buf;
  }
  if (type & SPECIAL) {
    if (base == 8) {
      if (buf <= end)
        *buf = '0';
      ++buf;
    } else
    if (base == 16) {
      if (buf <= end)
        *buf = '0';
      ++buf;
      if (buf <= end)
        *buf = digits[33];
      ++buf;
    }
  }
  if (!(type & LEFT)) {
    while (size-- > 0) {
      if (buf <= end)
        *buf = c;
      ++buf;
    }
  }
  while (i < precision--) {
    if (buf <= end)
      *buf = '0';
    ++buf;
  }
  while (i-- > 0) {
    if (buf <= end)
      *buf = tmp[i];
    ++buf;
  }
  while (size-- > 0) {
    if (buf <= end)
      *buf = ' ';
    ++buf;
  }
  return buf;
}

/**
* vsnprintf - Format a string and place it in a buffer
* @buf: The buffer to place the result into
* @size: The size of the buffer, including the trailing null space
* @fmt: The format string to use
* @args: Arguments for the format string
*
* Call this function if you are already dealing with a va_list.
* You probably want snprintf instead.
 */
static int _vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
  int len;
  unsigned long long num;
  int i, base;
  char *str, *end, c;
  const char *s;

  int flags;        /* flags to number() */

  int field_width;  /* width of output field */
  int precision;    /* min. # of digits for integers; max
                       number of chars for from string */
  int qualifier;    /* 'h', 'l', or 'L' for integer fields */
                    /* 'z' support added 23/7/1999 S.H.    */
                    /* 'z' changed to 'Z' --davidm 1/25/99 */

  str = buf;
  end = buf + size - 1;

  if (end < buf - 1) {
    end = ((void *) -1);
    size = end - buf + 1;
  }

  for (; *fmt ; ++fmt) {
    if (*fmt != '%') {
      if (str <= end) *str = *fmt;
      ++str;
      continue;
    }

    /* process flags */
    flags = 0;
repeat:
    ++fmt;    /* this also skips first '%' */
    switch (*fmt) {
      case '-': flags |= LEFT;    goto repeat;
      case '+': flags |= PLUS;    goto repeat;
      case ' ': flags |= SPACE;   goto repeat;
      case '#': flags |= SPECIAL; goto repeat;
      case '0': flags |= ZEROPAD; goto repeat;
    }

    /* get field width */
    field_width = -1;
    if (IsDigit(*fmt))
      field_width = skip_atoi(&fmt);
    else if (*fmt == '*') {
      ++fmt;
      /* it's the next argument */
      field_width = va_arg(args, int);
      if (field_width < 0) {
        field_width = -field_width;
        flags |= LEFT;
      }
    }

    /* get the precision */
    precision = -1;
    if (*fmt == '.') {
      ++fmt;  
      if (IsDigit(*fmt))
        precision = skip_atoi(&fmt);
      else if (*fmt == '*') {
        ++fmt;
        /* it's the next argument */
        precision = va_arg(args, int);
      }
      if (precision < 0)
        precision = 0;
    }

    /* get the conversion qualifier */
    qualifier = -1;
    if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L' ||
        *fmt =='Z'  || *fmt == 'z') {
      qualifier = *fmt;
      ++fmt;
      if (qualifier == 'l' && *fmt == 'l') {
        qualifier = 'L';
        ++fmt;
      }
    }

    /* default base */
    base = 10;

    switch (*fmt) {
      case 'c':
        if (!(flags & LEFT)) {
          while (--field_width > 0) {
            if (str <= end)
              *str = ' ';
            ++str;
          }
        }
        c = (unsigned char) va_arg(args, int);
        if (str <= end)
          *str = c;
        ++str;
        while (--field_width > 0) {
          if (str <= end)
            *str = ' ';
          ++str;
        }
        continue;

      case 's':
        s = va_arg(args, char *);
        if (!s)
          s = "<NULL>";

        len = strnlen(s, precision);
        if (!(flags & LEFT)) {
          while (len < field_width--) {
            if (str <= end)
              *str = ' ';
            ++str;
          }
        }
        for (i = 0; i < len; ++i) {
          if (str <= end)
            *str = *s;
          ++str; ++s;
        }
        while (len < field_width--) {
          if (str <= end)
            *str = ' ';
          ++str;
        }
        continue;

      case 'p':
        if (field_width == -1) {
          field_width = 2*sizeof(void *);
          flags |= ZEROPAD;
        }
        str = number(str, end, (unsigned long) va_arg(args, void *),
                     16, field_width, precision, flags);
        continue;


      case 'n':
        /* FIXME:
         * What does C99 say about the overflow case here? */
        if (qualifier == 'l') {
          long *ip = va_arg(args, long *);
          *ip = (str - buf);
        } else
        if (qualifier == 'Z' || qualifier == 'z') {
          size_t * ip = va_arg(args, size_t *);
          *ip = (str - buf);
        } else {
          int * ip = va_arg(args, int *);
          *ip = (str - buf);
        }
        continue;

      case '%':
        if (str <= end)
          *str = '%';
        ++str;
        continue;

        /* integer number formats - set up the flags and "break" */
      case 'o':
        base = 8;
        break;

      case 'X':
        flags |= LARGE;
      case 'x':
        base = 16;
        break;

      case 'd':
      case 'i':
        flags |= SIGN;
      case 'u':
        break;

      case 'f':
        qualifier = *fmt;
        break;

      default:
        if (str <= end)
          *str = '%';
        ++str;
        if (*fmt) {
          if (str <= end)
            *str = *fmt;
          ++str;
        } else {
          --fmt;
        }
        continue;
    }
    
    if (qualifier == 'f') {
      double fp_num = va_arg(args, double);
      str += fmt_double(str, fp_num, end - str, precision);
    } else {
      if (qualifier == 'L')
        num = va_arg(args, long long);
      else
      if (qualifier == 'l') {
        num = va_arg(args, unsigned long);
        if (flags & SIGN)
          num = (signed long) num;
      } else
      if (qualifier == 'Z' || qualifier == 'z') {
        num = va_arg(args, size_t);
      } else
      if (qualifier == 'h') {
        num = (unsigned short) va_arg(args, int);
        if (flags & SIGN)
          num = (signed short) num;
      } else {
        num = va_arg(args, unsigned int);
        if (flags & SIGN)
          num = (signed int) num;
      }
      str = number(str, end, num, base, field_width, precision, flags);
    }
  }
  if (str <= end)
    *str = '\0';
  else if (size > 0)
    /* don't write out a null byte if the buf size is zero */
    *end = '\0';
  /* the trailing null byte doesn't count towards the total
   * ++str;
   */
  return str-buf;
}

/**
 * xsnprintf - Format a string and place it in a buffer
 * @buf: The buffer to place the result into
 * @size: The size of the buffer, including the trailing null space
 * @fmt: The format string to use
 * @...: Arguments for the format string
 */
int xsnprintf (char *buf, size_t size, const char *fmt, ...)
{
  va_list args;
  int i;

  va_start(args, fmt);
  i = _vsnprintf(buf, size, fmt, args);
  va_end(args);
  return i;
}

/**
 * xprintf - Format a string and place it in a buffer
 * @buf: The buffer to place the result into
 * @fmt: The format string to use
 * @...: Arguments for the format string
 */
int xsprintf(char * buf, const char *fmt, ...)
{
  va_list args;
  int i;

  va_start(args, fmt);
  i = _vsnprintf(buf, 0xFFFFFFFFUL, fmt,args);
  va_end(args);
  return i;
}




/**
 * xvsscanf - Unformat a buffer into a list of arguments
 * @buf:  input buffer
 * @fmt:  format of buffer
 * @args:  arguments
 */
static int xvsscanf(const char *buf, const char *fmt, va_list args)
{
  const char *str = buf;
  char *next;
  char digit;
  int num = 0;
  int qualifier;
  int base;
  int field_width;
  int is_sign = 0;

  while (*fmt && *str) {
    /* skip any white space in format */
    /* white space in format matchs any amount of
     * white space, including none, in the input.
     */
    if (IsSpace(*fmt)) {
      while (IsSpace(*fmt))
        ++fmt;
      while (IsSpace(*str))
        ++str;
    }

    /* anything that is not a conversion must match exactly */
    if (*fmt != '%' && *fmt) {
      if (*fmt++ != *str++)
        break;
      continue;
    }

    if (!*fmt)
      break;
    ++fmt;
    
    /* skip this conversion.
     * advance both strings to next white space
     */
    if (*fmt == '*') {
      while (!IsSpace(*fmt) && *fmt)
        fmt++;
      while (!IsSpace(*str) && *str)
        str++;
      continue;
    }

    /* get field width */
    field_width = -1;
    if (IsDigit(*fmt))
      field_width = skip_atoi(&fmt);

    /* get conversion qualifier */
    qualifier = -1;
    if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L' ||
        *fmt == 'Z' || *fmt == 'z') {
      qualifier = *fmt;
      fmt++;
    }
    base = 10;
    is_sign = 0;

    if (!*fmt || !*str)
      break;

    switch (*fmt++) {
    case 'c':
    {
      char *s = (char *)va_arg(args, char *);
      if (field_width == -1)
        field_width = 1;
      do {
        *s++ = *str++;
      } while (field_width-- > 0 && *str);
      num++;
    }
    continue;
    case 's':
    {
      char *s = (char *) va_arg(args, char *);
      if (field_width == -1)
        field_width = INT_MAX;
      /* first, skip leading white space in buffer */
      while (isspace(*str))
        str++;

      /* now copy until next white space */
      while (*str && !isspace(*str) && field_width--) {
        *s++ = *str++;
      }
      *s = '\0';
      num++;
    }
    continue;
    case 'n':
    /* return number of characters read so far */
    {
      int *i = (int *)va_arg(args,int*);
      *i = str - buf;
    }
    continue;
    case 'o':
      base = 8;
      break;
    case 'x':
    case 'X':
      base = 16;
      break;
    case 'i':
      base = 0;
    case 'd':
      is_sign = 1;
    case 'u':
      break;
    case '%':
      /* looking for '%' in str */
      if (*str++ != '%') 
        return num;
      continue;
    default:
      /* invalid format; stop here */
      return num;
    }

    /* have some sort of integer conversion.
     * first, skip white space in buffer.
     */
    while (IsSpace(*str))
      str++;

    digit = *str;
    if (is_sign && digit == '-')
      digit = *(str + 1);

    if (!digit
    || (base == 16 && !isxdigit(digit))
    || (base == 10 && !IsDigit(digit))
    || (base == 8  && (!IsDigit(digit) || digit > '7'))
    || (base == 0  && !IsDigit(digit)))
        break;

    switch (qualifier) {
    case 'h':
      if (is_sign) {
        short *s = (short *) va_arg(args, short *);
        *s = (short) simple_strtol(str,&next,base);
      } else {
        unsigned short *s = (unsigned short *)va_arg(args, unsigned short *);
        *s = (unsigned short) simple_strtoul(str, &next, base);
      }
      break;
    case 'l':
      if (is_sign) {
        long *l = (long *) va_arg(args,long *);
        *l = simple_strtol(str,&next,base);
      } else {
        unsigned long *l = (unsigned long*)va_arg(args, unsigned long*);
        *l = simple_strtoul(str,&next,base);
      }
      break;
    case 'L':
      if (is_sign) {
        long long *l = (long long*) va_arg(args, long long *);
        *l = simple_strtoll(str,&next,base);
      } else {
        unsigned long long *l
          = (unsigned long long*)va_arg(args,unsigned long long*);
        *l = simple_strtoull(str,&next,base);
      }
      break;
    case 'Z':
    case 'z':
    {
      size_t *s = (size_t*) va_arg(args,size_t*);
      *s = (size_t) simple_strtoul(str, &next, base);
    }
    break;
    default:
      if (is_sign) {
        int *i = (int *)va_arg(args, int*);
        *i = (int) simple_strtol(str, &next, base);
      } else {
        unsigned int *i = (unsigned int*) va_arg(args, unsigned int*);
        *i = (unsigned int) simple_strtoul(str,&next,base);
      }
      break;
    }
    num++;

    if (!next)
      break;
    str = next;
  }
  return num;
}

/**
 * xscanf - Unformat a buffer into a list of arguments
 * @buf:  input buffer
 * @fmt:  formatting of buffer
 * @...:  resulting arguments
 */
int xsscanf (const char * buf, const char * fmt, ...)
{
  va_list args;
  int i;

  va_start(args,fmt);
  i = xvsscanf(buf,fmt,args);
  va_end(args);
  return i;
}


int xvasprintf (char **ptr, const char *format, va_list ap)
{
  int ret;
  va_list ap2;

  va_copy(ap2, ap);
  
  ret = vsnprintf(NULL, 0, format, ap2);
  if (ret <= 0) return ret;

  (*ptr) = (char *)xmalloc(ret+1);
  if (!*ptr) return -1;

  va_copy(ap2, ap);

  ret = vsnprintf(*ptr, ret+1, format, ap2);

  return ret;
}


int xasprintf (char **ptr, const char *format, ...)
{
  va_list ap;
  int ret;
  
  *ptr = NULL;
  va_start(ap, format);
  ret = xvasprintf(ptr, format, ap);
  va_end(ap);

  return ret;
}


char*
xstrconcat (const char *string1, ...)
{
  int   l;
  va_list args;
  char   *s;
  char   *concat;
  char   *ptr;

  if (!string1)
    return NULL;

  l = 1 + strlen (string1);
  va_start (args, string1);
  s = va_arg (args, char*);
  while (s)
    {
      l += strlen (s);
      s = va_arg (args, char*);
    }
  va_end (args);

  concat = xmalloc(l);
  ptr = concat;

  ptr = stpcpy (ptr, string1);
  va_start (args, string1);
  s = va_arg (args, char*);
  while (s)
    {
      ptr = stpcpy (ptr, s);
      s = va_arg (args, char*);
    }
  va_end (args);

  return concat;
}


