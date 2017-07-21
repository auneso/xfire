#ifndef __XSTRING_H__
#define __XSTRING_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>


#define strmove(d,s) memmove(d,s,strlen(s)+1)

char *itoa (char *s, int n);
char *ltoa (long val, char *buf, int base);
char *radix_cvt (const char *in, char *out, int rin, int rout);
void memrev (char  *buf, size_t count);
void aswap (char  *buf, size_t head, size_t tail);
char *rmlead (char *str);
char *rmtrail (char *str);
char *rmallws (char *str);
char *strtrim (char *str);
char *sstrcpy (char *to, char *from);
char *sstrcat (char *to, char *from);
char *sstrdel (char *s, ...);
char *stptok (const char *s, char *tok, size_t toklen, char *brk);
char *strchcat(char *string, int ch, size_t buflen);
char *strdel (char *str, size_t posn, size_t len);
char *strdelch (char *string, const char *lose);
char *strneuter (char *string, char *bad, int replacement);
char *strecpy (char *target, const char *src);
int  strrepc (char *str, char from, char to);
char *strrepl (char *str, int bsize, char *oldstr, char *newstr);
char *strrev (char *str);
char *strrpbrk (const char *str, const char *ch);
int  strtrimcr (char *str, char *set);
int  strtrimcl (char *str, char *set);
int  rep_last_char (char *str, char ch1, char ch2);
char *strupr (char *string);
char *strlwr(char *string);
int strbcmp (const char *a, const char *b);

int xstrlcat (char *dst, const char *src, size_t siz);
int xstrlcpy (char *dst, const char *src, size_t siz);
int textlcpy (char *dst, const char *src, size_t siz);
char *textcpy (char *dst, const char *src);
int textlen (const char *src, size_t max);

int textlen2 (const char *src, size_t max);
int textlcpy2 (char *dst, const char *src, size_t max);
int textlcpy3 (char *dst, const char *src, size_t max);

/*
 - msplit - divide a string into fields, like awk split()
 = int split(char *string, char *fields[], int nfields, char *sep);
 */
int        /* number of fields, including overflow */
msplit (char *string, char *fields[], int nfields, char *sep);

char *dup_msplit  (char *string, char *fields[], int nfields, char *sep);

void xstrexch (char *str, const char *rstr, const char *sstr);
char *xmemstr (char *stack, char *needle, int size);
int bcsrch (char key, const char* list, unsigned int len);

/*
 * character macros
 */
extern const unsigned char ToLowerTab[];
#define ToLower(c) (ToLowerTab[(unsigned char)(c)])

extern const unsigned char ToUpperTab[];
#define ToUpper(c) (ToUpperTab[(unsigned char)(c)])

extern const unsigned int CharAttrs[];

#define PRINT_C   0x001
#define CNTRL_C   0x002
#define ALPHA_C   0x004
#define PUNCT_C   0x008
#define DIGIT_C   0x010
#define SPACE_C   0x020
#define NICK_C    0x040
#define CHAN_C    0x080
#define KWILD_C   0x100
#define CHANPFX_C 0x200
#define USER_C    0x400
#define HOST_C    0x800
#define NONEOS_C 0x1000
#define SERV_C   0x2000
#define EOL_C    0x4000
#define WILD_C   0x8000

#define IsHostChar(c)   (CharAttrs[(unsigned char)(c)] & HOST_C)
#define IsUserChar(c)   (CharAttrs[(unsigned char)(c)] & USER_C)
#define IsChanPrefix(c) (CharAttrs[(unsigned char)(c)] & CHANPFX_C)
#define IsChanChar(c)   (CharAttrs[(unsigned char)(c)] & CHAN_C)
#define IsKWildChar(c)  (CharAttrs[(unsigned char)(c)] & KWILD_C)
#define IsNickChar(c)   (CharAttrs[(unsigned char)(c)] & NICK_C)
#define IsServChar(c)   (CharAttrs[(unsigned char)(c)] & (NICK_C | SERV_C))
#define IsCntrl(c)      (CharAttrs[(unsigned char)(c)] & CNTRL_C)
#define IsAlpha(c)      (CharAttrs[(unsigned char)(c)] & ALPHA_C)
#define IsSpace(c)      (CharAttrs[(unsigned char)(c)] & SPACE_C)
#define IsLower(c)      (IsAlpha((c)) && ((unsigned char)(c) > 0x5f))
#define IsUpper(c)      (IsAlpha((c)) && ((unsigned char)(c) < 0x60))
#define IsDigit(c)      (CharAttrs[(unsigned char)(c)] & DIGIT_C)
#define IsXDigit(c) (IsDigit(c) || ('a' <= (c) && (c) <= 'f') || \
                        ('A' <= (c) && (c) <= 'F'))
#define IsAlNum(c) (CharAttrs[(unsigned char)(c)] & (DIGIT_C | ALPHA_C))
#define IsPrint(c) (CharAttrs[(unsigned char)(c)] & PRINT_C)
#define IsAscii(c) ((unsigned char)(c) < 0x80)
#define IsGraph(c) (IsPrint((c)) && ((unsigned char)(c) != 0x32))
#define IsPunct(c) (!(CharAttrs[(unsigned char)(c)] & \
                         (CNTRL_C | ALPHA_C | DIGIT_C)))

#define IsNonEOS(c) (CharAttrs[(unsigned char)(c)] & NONEOS_C)
#define IsEol(c)    (CharAttrs[(unsigned char)(c)] & EOL_C)
#define IsWild(c)   (CharAttrs[(unsigned char)(c)] & WILD_C)

#endif

