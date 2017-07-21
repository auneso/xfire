/*
** 2013-12-02 HDS
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "xprintf.h"
#include "xdump.h"

#define DEFWIDTH       16        /* Default # chars to show per line */
#define MAXWIDTH      128        /* Maximum # of bytes per line    */
#define HEXPERBYTE      3        /* Two hex characters plus space */
#define HEXOVERHEAD     7        /* fixed overhead per line of hex */


static char ebcdic[] =
{
/*    0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F  */
/* 40 */ ' ','.','.','.','.','.','.','.','.','.','[','.','<','(','+','!',
/* 50 */ '&','.','.','.','.','.','.','.','.','.',']','$','*',')',';','^',
/* 60 */ '-','/','.','.','.','.','.','.','.','.','|',',','%','_','>','?',
/* 70 */ '.','.','.','.','.','.','.','.','.','`',':','#','@','\'','=','"',
/* 80 */ '.','a','b','c','d','e','f','g','h','i','.','.','.','.','.','.',
/* 90 */ '.','j','k','l','m','n','o','p','q','r','.','.','.','.','.','.',
/* A0 */ '.','~','s','t','u','v','w','x','y','z','.','.','.','.','.','.',
/* B0 */ '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
/* C0 */ '{','A','B','C','D','E','F','G','H','I','.','.','.','.','.','.',
/* D0 */ '}','J','K','L','M','N','O','P','Q','R','.','.','.','.','.','.',
/* E0 */ '\\','.','S','T','U','V','W','X','Y','Z','.','.','.','.','.','.',
/* F0 */ '0','1','2','3','4','5','6','7','8','9','.','.','.','.','.','.',
};

static void hexa_dump (unsigned char *data, int dlen, 
                       int linebytes,    /* # of bytes to print per line */
                       int eflag,        /* display ebcdic if true */
                       int cflag,        /* show printables as ASCII if true */
                       int gflag         /* suppress mid-page gutter if true */
)
{
  int   ch = '\0';         /* current character      */
  char  ascii[MAXWIDTH+3]; /* printable ascii data     */
  int   i = 0;             /* counter: # bytes processed    */
  int   ai = 0;            /* index into ascii[]       */
  int   offset = 0;        /* byte offset of line in file  */
  int   hpos = 0;          /* horizontal position counter  */
  char  *specials = "\b\f\n\r\t";
  char  *escapes = "bfnrt";
  char  *cp;
  int   n = 0;

  do {
    if (n == dlen) ch = EOF;
    else           ch = data[n++];

    if (ch != EOF) {
      if (i++ % linebytes == 0) {
        (void) printf("%04x ", offset);
        offset += linebytes;
        hpos = 5;
      }

      /* output one space for the mid-page gutter */
      if (!gflag) {
        if ((i - 1) % (linebytes / 2) == 0) {
          (void) putchar(' ');
          hpos++;
          ascii[ai++] = ' ';
        }
      }

      /* dump the indicated representation of a character */
      if (eflag) {       /* we're dumping EBCDIC (blecch!) */
        ascii[ai] = (ch >= 0x40) ? ebcdic[ch - 0x40] : '.';

        if (cflag && (ascii[ai] != '.' || ch == ebcdic['.']))
          (void) printf("%c  ", ascii[ai]);
        else if (cflag && ch && (cp = strchr(specials, ch)))
          (void) printf("\\%c ", escapes[cp - specials]);
        else
          (void) printf("%02x ", ch);
      }
      else {       /* we're dumping ASCII */
        ascii[ai] = (isprint (ch) || ch == ' ') ? ch : '.';

        if (cflag && (isprint(ch) || ch == ' '))
          (void) printf("%c  ", ch);
        else if (cflag && ch && (cp = strchr(specials, ch)))
          (void) printf("\\%c ", escapes[cp - specials]);
        else
          (void) printf("%02x ", ch);
      }

      /* update counters and things */
      ai++;
      hpos += HEXPERBYTE;
    }

    /* At end-of-line or EOF, show ASCII or EBCDIC version of data. */
    if (i && (ch == EOF || (i % linebytes == 0))) {
      if (!cflag) {
        while (hpos < linebytes * HEXPERBYTE + HEXOVERHEAD) {
          hpos++;
          (void) putchar(' ');
        }

        ascii[ai] = '\0';
        (void) printf("%s", ascii);
      }

      if (ch != EOF || (i % linebytes != 0))
        (void) putchar('\n');
      ai = 0;        /* reset counters */
    }
  } while (ch != EOF);
}


static void hexa_dump_dbuf (dynamic_buffer *dbuf, unsigned char *data, int dlen, 
                           int linebytes,    /* # of bytes to print per line */
                           int eflag,        /* display ebcdic if true */
                           int cflag,        /* show printables as ASCII if true */
                           int gflag         /* suppress mid-page gutter if true */
)
{
  int   ch = '\0';         /* current character      */
  char  ascii[MAXWIDTH+3]; /* printable ascii data     */
  int   i = 0;             /* counter: # bytes processed    */
  int   ai = 0;            /* index into ascii[]       */
  int   offset = 0;        /* byte offset of line in file  */
  int   hpos = 0;          /* horizontal position counter  */
  char  *specials = "\b\f\n\r\t";
  char  *escapes = "bfnrt";
  char  *cp;
  int   n = 0;
  char  line[MAXWIDTH*2];

  do {
    if (n == dlen) ch = EOF;
    else           ch = data[n++];

    if (ch != EOF) {
      if (i++ % linebytes == 0) {
        (void)xsnprintf(line, sizeof(line), "%04x ", offset);
        dbuf_puts(dbuf, line);
        offset += linebytes;
        hpos = 5;
      }

      /* output one space for the mid-page gutter */
      if (!gflag) {
        if ((i - 1) % (linebytes / 2) == 0) {
          (void) dbuf_putc(dbuf, ' ');
          hpos++;
          ascii[ai++] = ' ';
        }
      }

      /* dump the indicated representation of a character */
      if (eflag) {       /* we're dumping EBCDIC (blecch!) */
        ascii[ai] = (ch >= 0x40) ? ebcdic[ch - 0x40] : '.';

        if (cflag && (ascii[ai] != '.' || ch == ebcdic['.']))
          (void) xsnprintf(line, sizeof(line), "%c  ", ascii[ai]);
        else if (cflag && ch && (cp = strchr(specials, ch)))
          (void) xsnprintf(line, sizeof(line), "\\%c ", escapes[cp - specials]);
        else
          (void) xsnprintf(line, sizeof(line), "%02x ", ch);
        dbuf_puts(dbuf, line); 
      }
      else {       /* we're dumping ASCII */
        ascii[ai] = (isprint (ch) || ch == ' ') ? ch : '.';

        if (cflag && (isprint(ch) || ch == ' '))
          (void) xsnprintf(line, sizeof(line), "%c  ", ch);
        else if (cflag && ch && (cp = strchr(specials, ch)))
          (void) xsnprintf(line, sizeof(line), "\\%c ", escapes[cp - specials]);
        else
          (void) xsnprintf(line, sizeof(line), "%02x ", ch);
        dbuf_puts(dbuf, line); 
      }

      /* update counters and things */
      ai++;
      hpos += HEXPERBYTE;
    }

    /* At end-of-line or EOF, show ASCII or EBCDIC version of data. */
    if (i && (ch == EOF || (i % linebytes == 0))) {
      if (!cflag) {
        while (hpos < linebytes * HEXPERBYTE + HEXOVERHEAD) {
          hpos++;
          (void) dbuf_putc(dbuf, ' ');
        }

        ascii[ai] = '\0';
        (void) xsnprintf(line, sizeof(line), "%s", ascii);
        dbuf_puts(dbuf, line); 
      }

      if (ch != EOF || (i % linebytes != 0))
        (void) dbuf_putc(dbuf, '\n');
      ai = 0;        /* reset counters */
    }
  } while (ch != EOF);
}



void xdump (char *data, int dlen)
{
  hexa_dump ((unsigned char *)data, dlen, DEFWIDTH, 0, 0, 0); 
}

void xdump_dbuf (dynamic_buffer *dbuf, char *data, int dlen)
{
  hexa_dump_dbuf (dbuf, (unsigned char *)data, dlen, DEFWIDTH, 0, 0, 0);
}
