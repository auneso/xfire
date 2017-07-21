#ifndef __XTYPE_H__
#define __XTYPE_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <limits.h>


#define OK      0
#define ERROR   -1

#ifndef FALSE
#define FALSE     0
#endif /*FALSE*/
#ifndef TRUE
#define TRUE      1
#endif /*TRUE*/

#ifndef MIN
#define MIN(a, b)       ((a) < (b) ? (a) : (b))
#endif  /* MIN */
#ifndef MAX
#define MAX(a, b)       ((a) > (b) ? (a) : (b))
#endif  /* MAX */
#ifndef ABS
#define ABS(a)          ((a) < 0 ? -(a) : (a))
#endif  /* ABS */
/**
 * Force alignment
 */
#define _ntn_aligned(a) __attribute__((__aligned__(a)))


#if ULONG_MAX > 0xffffffff

typedef unsigned long       ub64;
typedef unsigned int        ub32;
typedef unsigned short      ub16;
typedef unsigned char       ub8;

typedef signed long         sb64;
typedef signed int          sb32;
typedef signed short        sb16;
typedef signed char         sb8;
typedef unsigned long       xsize;

#define X_FMT_U64           "%lu"
#define BIT64_ARCH

#else
typedef unsigned long long  ub64;
typedef unsigned int        ub32;
typedef unsigned short      ub16;
typedef unsigned char       ub8;

typedef signed long long    sb64;
typedef signed int          sb32;
typedef signed short        sb16;
typedef signed char         sb8;

typedef unsigned long long  xsize;

#define X_FMT_U64           "%llu"
#define BIT32_ARCH

#endif

typedef unsigned char  byte;
typedef int xboolean;

#define PTRSIZE (sizeof(void *))

#define bis(target,mask)  ((target) |=  (mask))
#define bic(target,mask)  ((target) &= ~(mask))
#define bit(target,mask)  ((target) &   (mask))

#ifndef min
#define min(x,y) ({             \
        typeof(x) _x = (x);     \
        typeof(y) _y = (y);     \
        (void) (&_x == &_y);    \
        _x < _y ? _x : _y; })
#endif

#ifndef max
#define max(x,y) ({             \
        typeof(x) _x = (x);     \
        typeof(y) _y = (y);     \
        (void) (&_x == &_y);    \
        _x > _y ? _x : _y; })
#endif

#ifndef align
# define align(a) (((ub32)a+(sizeof(void *)-1))&(~(sizeof(void *)-1)))
#endif /* align */


/* ############################ bytes ############################ */
#define SWAPBYTES16(word) (\
(((word)&0x00ff) << 8) | \
(((word)&0xff00) >> 8) \
)

#define SWAPBYTES32(word) (\
(((word)&0x000000ff) << 24)| \
(((word)&0x0000ff00) << 8) | \
(((word)&0x00ff0000) >> 8) | \
(((word)&0xff000000) >> 24) \
)

/* non-zero if byteasword is in word, where byte is held to far right 8bits */
#define BYTEINWORD32(word, byteasword)(\
(((word)&0x000000ff)         == (byteasword)) || \
((((word)&0x0000ff00) >> 8)  == (byteasword)) || \
((((word)&0x00ff0000) >> 16) == (byteasword)) || \
((((word)&0xff000000) >> 24) == (byteasword)) \
)

/* ############################ bits ############################ */


/***********************************************************************\
|macro:		COUNTBITS16						|
|purpose:	count the bits that are 1 in a 16 bit lvalue		|
|usage:		COUNTBITS16( bits );					|
|   or:		count = COUNTBITS16( bits );				|
|note:		the lvalue argument always ends up with the result	|
\***********************************************************************/
#define COUNTBITS16(b) (\
	(b)=(((b)>> 1)&0x5555)+((b)&0x5555),\
	(b)=(((b)>> 2)&0x3333)+((b)&0x3333),\
	(b)=(((b)>> 4)&0x0707)+((b)&0x0707),\
	(b)=(((b)>> 8)&0x000f)+((b)&0x000f),\
	(b))

/***********************************************************************\
|macro:		COUNTBITS32						|
|purpose:	count the bits that are 1 in a 32 bit lvalue		|
|usage:		COUNTBITS32( bits );					|
|   or:		count = COUNTBITS32( bits );				|
|note:		the lvalue argument always ends up with the result	|
\***********************************************************************/
#define COUNTBITS32(b) (\
	(b)=(((b)>> 1)&0x55555555)+((b)&0x55555555),\
	(b)=(((b)>> 2)&0x33333333)+((b)&0x33333333),\
	(b)=(((b)>> 4)&0x07070707)+((b)&0x07070707),\
	(b)=(((b)>> 8)&0x000f000f)+((b)&0x000f000f),\
	(b)=(((b)>>16)&0x0000001f)+((b)&0x0000001f),\
	(b))

/***********************************************************************\
|macro:		COUNTBITS64						|
|purpose:	count the bits that are 1 in a 64 bit lvalue		|
|usage:		COUNTBITS64( bits );					|
|   or:		count = COUNTBITS64( bits );				|
|note:		the lvalue argument always ends up with the result	|
\***********************************************************************/
#define COUNTBITS64(b) (\
	(b)=(((b)>> 1)&0x5555555555555555)+((b)&0x5555555555555555),\
	(b)=(((b)>> 2)&0x3333333333333333)+((b)&0x3333333333333333),\
	(b)=(((b)>> 4)&0x0707070707070707)+((b)&0x0707070707070707),\
	(b)=(((b)>> 8)&0x000f000f000f000f)+((b)&0x000f000f000f000f),\
	(b)=(((b)>>16)&0x0000001f0000001f)+((b)&0x0000001f0000001f),\
	(b)=(((b)>>32)&0x000000000000003f)+((b)&0x000000000000003f),\
	(b))

/***********************************************************************\
|macro:		REVERSEBITS16						|
|purpose:	reverse the bit order in a 16 bit lvalue		|
|usage:		REVERSEBITS16( bits );					|
|   or:		value = REVERSEBITS16( bits );				|
|note:		the lvalue argument always ends up with the result	|
\***********************************************************************/
#define REVERSEBITS16(b) (\
	(b)=(((b)>> 1)&0x5555)|(((b)&0x5555)<< 1),\
	(b)=(((b)>> 2)&0x3333)|(((b)&0x3333)<< 2),\
	(b)=(((b)>> 4)&0x0f0f)|(((b)&0x0f0f)<< 4),\
	(b)=(((b)>> 8)&0x00ff)|(((b)&0x00ff)<< 8),\
	(b))

/***********************************************************************\
|macro:		REVERSEBITS32						|
|purpose:	reverse the bit order in a 32 bit lvalue		|
|usage:		REVERSEBITS32( bits );					|
|   or:		value = REVERSEBITS32( bits );				|
|note:		the lvalue argument always ends up with the result	|
\***********************************************************************/
#define REVERSEBITS32(b) (\
	(b)=(((b)>> 1)&0x55555555)|(((b)&0x55555555)<< 1),\
	(b)=(((b)>> 2)&0x33333333)|(((b)&0x33333333)<< 2),\
	(b)=(((b)>> 4)&0x0f0f0f0f)|(((b)&0x0f0f0f0f)<< 4),\
	(b)=(((b)>> 8)&0x00ff00ff)|(((b)&0x00ff00ff)<< 8),\
	(b)=(((b)>>16)&0x0000ffff)|(((b)&0x0000ffff)<<16),\
	(b))

/***********************************************************************\
|macro:		REVERSEBITS64						|
|purpose:	reverse the bit order in a 64 bit lvalue		|
|usage:		REVERSEBITS64( bits );					|
|   or:		value = REVERSEBITS64( bits );				|
|note:		the lvalue argument always ends up with the result	|
\***********************************************************************/
#define REVERSEBITS64(b) (\
	(b)=(((b)>> 1)&0x5555555555555555)|(((b)&0x5555555555555555)<< 1),\
	(b)=(((b)>> 2)&0x3333333333333333)|(((b)&0x3333333333333333)<< 2),\
	(b)=(((b)>> 4)&0x0f0f0f0f0f0f0f0f)|(((b)&0x0f0f0f0f0f0f0f0f)<< 4),\
	(b)=(((b)>> 8)&0x00ff00ff00ff00ff)|(((b)&0x00ff00ff00ff00ff)<< 8),\
	(b)=(((b)>>16)&0x0000ffff0000ffff)|(((b)&0x0000ffff0000ffff)<<16),\
	(b)=(((b)>>32)&0x00000000ffffffff)|(((b)&0x00000000ffffffff)<<32),\
	(b))

typedef struct _value_string {
  int  value;
  char *strptr;
} value_string;



#endif	/* __XTYPE_H__ */
