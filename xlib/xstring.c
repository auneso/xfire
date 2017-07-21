
/* String Handler ---------------------*/
/*
** 2008/10/23 HDS   
** 2009/05/26 HDS  - textcpy, textlcpy, textlen 
** 2009/07/17 HDS  - xstrlcpy, xstrlcat
** 2010/05/27 HDS  - xstrexch
** 2011/06/16 HDS  - dup_msplit
*/
#include "xstring.h"
#include "xalloc.h"
#include "xtypes.h"

const unsigned char ToLowerTab[] = { 
  0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa,
  0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14,
  0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
  0x1e, 0x1f,
  ' ', '!', '"', '#', '$', '%', '&', 0x27, '(', ')',
  '*', '+', ',', '-', '.', '/',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  ':', ';', '<', '=', '>', '?',
  '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
  '_',
  '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
  0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
  0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99,
  0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9,
  0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9,
  0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
  0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9,
  0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
  0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9,
  0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

const unsigned char ToUpperTab[] = { 
  0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa,
  0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14,
  0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
  0x1e, 0x1f,
  ' ', '!', '"', '#', '$', '%', '&', 0x27, '(', ')',
  '*', '+', ',', '-', '.', '/',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  ':', ';', '<', '=', '>', '?',
  '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
  'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^',
  0x5f,
  '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
  'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^',
  0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
  0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99,
  0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9,
  0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9,
  0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
  0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9,
  0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
  0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9,
  0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff 
};

/*
 * CharAttrs table
 *
 * NOTE: RFC 1459 sez: anything but a ^G, comma, or space is allowed
 * for channel names
 */
const unsigned int CharAttrs[] = {
/* 0  */     CNTRL_C,
/* 1  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 2  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 3  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 4  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 5  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 6  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 7 BEL */  CNTRL_C|NONEOS_C,
/* 8  \b */  CNTRL_C|CHAN_C|NONEOS_C,
/* 9  \t */  SPACE_C|CHAN_C|NONEOS_C,
/* 10 \n */  SPACE_C|CHAN_C|NONEOS_C|EOL_C,
/* 11 \v */  CNTRL_C|SPACE_C|CHAN_C|NONEOS_C,
/* 12 \f */  CNTRL_C|SPACE_C|CHAN_C|NONEOS_C,
/* 13 \r */  SPACE_C|CHAN_C|NONEOS_C|EOL_C,
/* 14 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 15 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 16 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 17 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 18 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 19 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 20 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 21 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 22 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 23 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 24 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 25 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 26 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 27 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 28 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 29 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 30 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 31 */     CNTRL_C|CHAN_C|NONEOS_C,
/* SP */     PRINT_C|SPACE_C,
/* ! */      PRINT_C|KWILD_C|CHAN_C|NONEOS_C,
/* " */      PRINT_C|CHAN_C|NONEOS_C,
/* # */      PRINT_C|CHANPFX_C|CHAN_C|NONEOS_C,
/* $ */      PRINT_C|CHAN_C|NONEOS_C|USER_C,
/* % */      PRINT_C|CHAN_C|NONEOS_C,
/* & */      PRINT_C|CHANPFX_C|CHAN_C|NONEOS_C,
/* ' */      PRINT_C|CHAN_C|NONEOS_C,
/* ( */      PRINT_C|CHAN_C|NONEOS_C,
/* ) */      PRINT_C|CHAN_C|NONEOS_C,
/* * */      PRINT_C|KWILD_C|CHAN_C|NONEOS_C|SERV_C,
/* + */      PRINT_C|CHAN_C|NONEOS_C,
/* , */      PRINT_C|NONEOS_C,
/* - */      PRINT_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* . */      PRINT_C|KWILD_C|CHAN_C|NONEOS_C|USER_C|SERV_C,
/* / */      PRINT_C|CHAN_C|NONEOS_C,
/* 0 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 1 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 2 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 3 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 4 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 5 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 6 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 7 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 8 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* 9 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* : */      PRINT_C|CHAN_C|NONEOS_C,
/* ; */      PRINT_C|CHAN_C|NONEOS_C,
/* < */      PRINT_C|CHAN_C|NONEOS_C,
/* = */      PRINT_C|CHAN_C|NONEOS_C,
/* > */      PRINT_C|CHAN_C|NONEOS_C,
/* ? */      PRINT_C|KWILD_C|CHAN_C|NONEOS_C,
/* @ */      PRINT_C|KWILD_C|CHAN_C|NONEOS_C,
/* A */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* B */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* C */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* D */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* E */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* F */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* G */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* H */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* I */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* J */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* K */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* L */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* M */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* N */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* O */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* P */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* Q */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* R */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* S */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* T */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* U */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* V */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* W */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* X */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* Y */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* Z */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* [ */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* \ */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* ] */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* ^ */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* _ */      PRINT_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* ` */      PRINT_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* a */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* b */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* c */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* d */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* e */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* f */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* g */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* h */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* i */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* j */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* k */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* l */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* m */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* n */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* o */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* p */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* q */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* r */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* s */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* t */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* u */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* v */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* w */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* x */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* y */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* z */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C|HOST_C,
/* { */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* | */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* } */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|NONEOS_C|USER_C,
/* ~ */      PRINT_C|ALPHA_C|CHAN_C|NONEOS_C|USER_C,
/* del  */   CHAN_C|NONEOS_C,
/* 0x80 */   CHAN_C|NONEOS_C,
/* 0x81 */   CHAN_C|NONEOS_C,
/* 0x82 */   CHAN_C|NONEOS_C,
/* 0x83 */   CHAN_C|NONEOS_C,
/* 0x84 */   CHAN_C|NONEOS_C,
/* 0x85 */   CHAN_C|NONEOS_C,
/* 0x86 */   CHAN_C|NONEOS_C,
/* 0x87 */   CHAN_C|NONEOS_C,
/* 0x88 */   CHAN_C|NONEOS_C,
/* 0x89 */   CHAN_C|NONEOS_C,
/* 0x8A */   CHAN_C|NONEOS_C,
/* 0x8B */   CHAN_C|NONEOS_C,
/* 0x8C */   CHAN_C|NONEOS_C,
/* 0x8D */   CHAN_C|NONEOS_C,
/* 0x8E */   CHAN_C|NONEOS_C,
/* 0x8F */   CHAN_C|NONEOS_C,
/* 0x90 */   CHAN_C|NONEOS_C,
/* 0x91 */   CHAN_C|NONEOS_C,
/* 0x92 */   CHAN_C|NONEOS_C,
/* 0x93 */   CHAN_C|NONEOS_C,
/* 0x94 */   CHAN_C|NONEOS_C,
/* 0x95 */   CHAN_C|NONEOS_C,
/* 0x96 */   CHAN_C|NONEOS_C,
/* 0x97 */   CHAN_C|NONEOS_C,
/* 0x98 */   CHAN_C|NONEOS_C,
/* 0x99 */   CHAN_C|NONEOS_C,
/* 0x9A */   CHAN_C|NONEOS_C,
/* 0x9B */   CHAN_C|NONEOS_C,
/* 0x9C */   CHAN_C|NONEOS_C,
/* 0x9D */   CHAN_C|NONEOS_C,
/* 0x9E */   CHAN_C|NONEOS_C,
/* 0x9F */   CHAN_C|NONEOS_C,
/* 0xA0 */   CHAN_C|NONEOS_C,
/* 0xA1 */   CHAN_C|NONEOS_C,
/* 0xA2 */   CHAN_C|NONEOS_C,
/* 0xA3 */   CHAN_C|NONEOS_C,
/* 0xA4 */   CHAN_C|NONEOS_C,
/* 0xA5 */   CHAN_C|NONEOS_C,
/* 0xA6 */   CHAN_C|NONEOS_C,
/* 0xA7 */   CHAN_C|NONEOS_C,
/* 0xA8 */   CHAN_C|NONEOS_C,
/* 0xA9 */   CHAN_C|NONEOS_C,
/* 0xAA */   CHAN_C|NONEOS_C,
/* 0xAB */   CHAN_C|NONEOS_C,
/* 0xAC */   CHAN_C|NONEOS_C,
/* 0xAD */   CHAN_C|NONEOS_C,
/* 0xAE */   CHAN_C|NONEOS_C,
/* 0xAF */   CHAN_C|NONEOS_C,
/* 0xB0 */   CHAN_C|NONEOS_C,
/* 0xB1 */   CHAN_C|NONEOS_C,
/* 0xB2 */   CHAN_C|NONEOS_C,
/* 0xB3 */   CHAN_C|NONEOS_C,
/* 0xB4 */   CHAN_C|NONEOS_C,
/* 0xB5 */   CHAN_C|NONEOS_C,
/* 0xB6 */   CHAN_C|NONEOS_C,
/* 0xB7 */   CHAN_C|NONEOS_C,
/* 0xB8 */   CHAN_C|NONEOS_C,
/* 0xB9 */   CHAN_C|NONEOS_C,
/* 0xBA */   CHAN_C|NONEOS_C,
/* 0xBB */   CHAN_C|NONEOS_C,
/* 0xBC */   CHAN_C|NONEOS_C,
/* 0xBD */   CHAN_C|NONEOS_C,
/* 0xBE */   CHAN_C|NONEOS_C,
/* 0xBF */   CHAN_C|NONEOS_C,
/* 0xC0 */   CHAN_C|NONEOS_C,
/* 0xC1 */   CHAN_C|NONEOS_C,
/* 0xC2 */   CHAN_C|NONEOS_C,
/* 0xC3 */   CHAN_C|NONEOS_C,
/* 0xC4 */   CHAN_C|NONEOS_C,
/* 0xC5 */   CHAN_C|NONEOS_C,
/* 0xC6 */   CHAN_C|NONEOS_C,
/* 0xC7 */   CHAN_C|NONEOS_C,
/* 0xC8 */   CHAN_C|NONEOS_C,
/* 0xC9 */   CHAN_C|NONEOS_C,
/* 0xCA */   CHAN_C|NONEOS_C,
/* 0xCB */   CHAN_C|NONEOS_C,
/* 0xCC */   CHAN_C|NONEOS_C,
/* 0xCD */   CHAN_C|NONEOS_C,
/* 0xCE */   CHAN_C|NONEOS_C,
/* 0xCF */   CHAN_C|NONEOS_C,
/* 0xD0 */   CHAN_C|NONEOS_C,
/* 0xD1 */   CHAN_C|NONEOS_C,
/* 0xD2 */   CHAN_C|NONEOS_C,
/* 0xD3 */   CHAN_C|NONEOS_C,
/* 0xD4 */   CHAN_C|NONEOS_C,
/* 0xD5 */   CHAN_C|NONEOS_C,
/* 0xD6 */   CHAN_C|NONEOS_C,
/* 0xD7 */   CHAN_C|NONEOS_C,
/* 0xD8 */   CHAN_C|NONEOS_C,
/* 0xD9 */   CHAN_C|NONEOS_C,
/* 0xDA */   CHAN_C|NONEOS_C,
/* 0xDB */   CHAN_C|NONEOS_C,
/* 0xDC */   CHAN_C|NONEOS_C,
/* 0xDD */   CHAN_C|NONEOS_C,
/* 0xDE */   CHAN_C|NONEOS_C,
/* 0xDF */   CHAN_C|NONEOS_C,
/* 0xE0 */   CHAN_C|NONEOS_C,
/* 0xE1 */   CHAN_C|NONEOS_C,
/* 0xE2 */   CHAN_C|NONEOS_C,
/* 0xE3 */   CHAN_C|NONEOS_C,
/* 0xE4 */   CHAN_C|NONEOS_C,
/* 0xE5 */   CHAN_C|NONEOS_C,
/* 0xE6 */   CHAN_C|NONEOS_C,
/* 0xE7 */   CHAN_C|NONEOS_C,
/* 0xE8 */   CHAN_C|NONEOS_C,
/* 0xE9 */   CHAN_C|NONEOS_C,
/* 0xEA */   CHAN_C|NONEOS_C,
/* 0xEB */   CHAN_C|NONEOS_C,
/* 0xEC */   CHAN_C|NONEOS_C,
/* 0xED */   CHAN_C|NONEOS_C,
/* 0xEE */   CHAN_C|NONEOS_C,
/* 0xEF */   CHAN_C|NONEOS_C,
/* 0xF0 */   CHAN_C|NONEOS_C,
/* 0xF1 */   CHAN_C|NONEOS_C,
/* 0xF2 */   CHAN_C|NONEOS_C,
/* 0xF3 */   CHAN_C|NONEOS_C,
/* 0xF4 */   CHAN_C|NONEOS_C,
/* 0xF5 */   CHAN_C|NONEOS_C,
/* 0xF6 */   CHAN_C|NONEOS_C,
/* 0xF7 */   CHAN_C|NONEOS_C,
/* 0xF8 */   CHAN_C|NONEOS_C,
/* 0xF9 */   CHAN_C|NONEOS_C,
/* 0xFA */   CHAN_C|NONEOS_C,
/* 0xFB */   CHAN_C|NONEOS_C,
/* 0xFC */   CHAN_C|NONEOS_C,
/* 0xFD */   CHAN_C|NONEOS_C,
/* 0xFE */   CHAN_C|NONEOS_C,
/* 0xFF */   CHAN_C|NONEOS_C
};

/*
** If X is a character that can be used in an identifier then
** IdChar(X) will be true.  Otherwise it is false.
**  
** For ASCII, any character with the high-order bit set is
** allowed in an identifier.  For 7-bit characters, 
** sqlite3IsIdChar[X] must be 1. 
*/
static const char AsciiIdChar[] = {
  /* x0 x1 x2 x3 x4 x5 x6 x7 x8 x9 xA xB xC xD xE xF */
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  /* 2x */
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,  /* 3x */
      0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  /* 4x */
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,  /* 5x */
      0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  /* 6x */
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,  /* 7x */
};
#define IdChar(C) (((c=C)&0x80)!=0 || (c>0x1f && AsciiIdChar[c-0x20]))

char *itoa (char *s, int n)
{
  int  i;
  int  sign;

  if ((sign = n) < 0) n = -n;

  i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) s[i++] = '-';

  s[i] = '\0';
  return strrev(s);
}

char *ltoa (long val, char *buf, int base) 
{
  ldiv_t r;  /* result of val / base  */

  if (base > 36 || base < 2) {
     *buf = '\0';
     return buf;
  }
  if (val < 0)
    *buf++ = '-';
  r = ldiv (labs(val), base);

  /* output digits of val/base first */

  if (r.quot > 0)
    buf = ltoa(r.quot, buf, base);

  /* output last digit */

  *buf++ = "0123456789abcdefghijklmnopqrstuvwxyz"[(int)r.rem];
  *buf   = '\0';
  return buf;
}


char *radix_cvt (const char *in, char *out, int rin, int rout)
{
  long n;
  char *dummy;

  n = strtol(in, &dummy, rin);
  return ltoa(n, out, rout);
}


/*
**  reverse "count" bytes starting at "buf"
*/

void memrev (char  *buf, size_t count)
{
  char *r;

  for (r = buf + count - 1; buf < r; buf++, r--) {
    *buf ^= *r;
    *r   ^= *buf;
    *buf ^= *r;
  }
}

/*
**  swap "head" bytes with "tail" bytes at "buf"
*/

void aswap (char  *buf, size_t head, size_t tail)
{
  memrev(buf, head);
  memrev(buf + head, tail);
  memrev(buf, head + tail);
}

char *rmlead (char *str)
{
  char *obuf;

  if (str) {
    for (obuf = str; *obuf && IsSpace(*obuf); ++obuf)
      ;
    if (str != obuf)
      strmove(str, obuf);
  }
  return str;
}


char *rmtrail (char *str)
{
  int i;

  if (str && 0 != (i = strlen(str))) {
    while (--i >= 0) {
      if (!IsSpace(str[i]))
        break;
    }
    str[++i] = 0;
  }
  return str;
}


/* remove all whitespace from a string */
char *rmallws (char *str)
{
  char *obuf, *nbuf;

  if (str) {
    for (obuf = str, nbuf = str; *obuf; ++obuf) {
      if (!IsSpace(*obuf))
        *nbuf++ = *obuf;
    }
    *nbuf = 0;
  }
  return str;
}

/* Remove leading, trailing, & excess embedded spaces */
char *strtrim (char *str)
{
  char *ibuf, *obuf;

  if (str) {
    for (ibuf = obuf = str; *ibuf; ) {
      while (*ibuf && (IsSpace (*ibuf)))
        ibuf++;
      if (*ibuf && (obuf != str))
        *(obuf++) = ' ';
      while (*ibuf && (!IsSpace (*ibuf)))
        *(obuf++) = *(ibuf++);
    }
    *obuf = 0;
  }
  return (str);
}

char *sstrcpy (char *to, char *from)
{
    memmove(to, from, 1+strlen(from));
    return to;
}

char *sstrcat (char *to, char *from)
{
    sstrcpy(to + strlen(to), from);
    return to;
}

char *sstrdel (char *s, ...)
{
  /* Find out how many arguments are present */

  int c = 0;
  va_list ap, hold;

  if (s == NULL) return NULL;

  va_start(ap, s);
  memcpy(&hold, &ap, sizeof(va_list));
  while (va_arg(ap, char *) != NULL) c++;
  va_end(ap);

  if (c) {
    /* Assign pointers  */
    char *r = s,*n = s;
    char *p;
    int len, i;

    /* Copy next character to result */
    /* And then check for matches if */
    /* not at end of string          */
    while ((*r = *n) != 0) {
      int l = 0;

      /* Substitute for va_start(ap,s) */
      memcpy(&ap, &hold, sizeof(va_list));

      for (i = 0; i < c; i++) {
        /* Initialise the pointer and the length    */
        len = strlen(p = va_arg(ap, char*));

        /* Compare ONLY if we haven't found one yet */
        /* or if this one is bigger than the one we */
        /* found AND this arg has a length > 0      */

        if (len > 0 && (l == 0 || len> l) && strncmp(n, p, len) == 0) {
          l = len;
        }
      }
      va_end(ap);
      if (l)
        n += l;
      else  n++, r++;
    }
  }
  return s;
}


char *stptok (const char *s, char *tok, size_t toklen, char *brk)
{
  char *lim, *b;

  if (!*s)
    return NULL;

  lim = tok + toklen - 1;
  while ( *s && tok < lim ) {
    for ( b = brk; *b; b++ ) {
      if ( *s == *b ) {
        *tok = 0;
        for (++s, b = brk; *s && *b; ++b) {
          if (*s == *b) {
            ++s;
            b = brk;
          }
        }
        return (char *)s;
      }
    }
    *tok++ = *s++;
  }
  *tok = 0;
  return (char *)s;
}

char *strchcat(char *string, int ch, size_t buflen)
{
  size_t len;

  if (NULL == string || ((len = strlen(string)) + 1) >= buflen)
    return NULL;

  string[len++] = ch;
  string[len]   = '\0';
  return string;
}

char *strdel (char *str, size_t posn, size_t len)
{
  char *pos0, *pos1;

  if (str) {
    if (posn < strlen(str)) {
      for (pos0 = pos1 = str + posn; *pos1 && len; ++pos1, --len) {
        ;
      }
      strmove(pos0, pos1);
    }
  }
  return str;
}

char *strdelch (char *string, const char *lose)
{
  if (!string || !*string)
    return NULL;
  if (lose) {
    char *s;

    for (s = string; *s; ++s) {
      if (strchr(lose, *s)) {
        strmove(s, s + 1);
        --s;
      }
    }
  }
  return string;
}

char *strecpy (char *target, const char *src)
{
  if (src && target) {
    while ((*target++ = *src++) != 0)
      ;
    return (--target);
  }
  else  return NULL;
}


int strrepc (char *str, char from, char to)
{
  char  *ptr;
  int   cnt = 0;

  while (0 != (ptr = strchr(str, from))) {
    str[ptr - str] = to ;
    cnt++;
  }
  return(cnt) ;
}

char *strneuter (char *string, char *bad, int replacement)
{
  char   *cp;
  int     ch;

  for (cp = string; (ch = *(unsigned char *) cp) != 0; cp++)
    if (strchr(bad, ch) != 0)
      *cp = replacement;
   return (string);
}

char *strrepl (char *str, int bsize, char *oldstr, char *newstr)
{
  int oldlen, newlen;
  char *p, *q;

  if (NULL == (p = strstr(str, oldstr)))
    return str;
  oldlen = strlen(oldstr);
  newlen = strlen(newstr);
  if ((int)(strlen(str) + newlen - oldlen + 1) > bsize)
    return NULL;
  memmove(q = p+newlen, p+oldlen, strlen(p+oldlen)+1);
  memcpy(p, newstr, newlen);
  return q;
}

char *strrev (char *str)
{
  char *p1, *p2;

  if (!str || !*str)
    return str;

  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

char *strrpbrk (const char *str, const char *ch)
{
  const char  *p;
  char        *p0, *p1;

  for (p = ch, p0 = p1 = NULL; p && *p; ++p) {
    p1 = strrchr(str, *p);
    if (p1 && p1 > p0)
      p0 = p1;
  }
  return p0;
}

int strtrimcr (char *str, char *set)
{
  int  i, j;

  j = i = strlen(str) - 1;

  while (strrchr(set, str[i]) && (0 <= i)) {
    /* While string is terminated by one of the specified characters */
    str[i--] = '\0';          /*- Replace character with '\0' */
  }

  return(j - i);    /* Return the difference between old and new length */
}


int strtrimcl (char *str, char *set)
{
  int   i = 0, j;

  j = strlen(str) - 1;

  while (strrchr(set, str[i]) && (i <= j)) {
    /* While first character in string matches tag */
    i++; /*- Count no of removed chars */
  }

  if (0 < i) /* IF there were matches */
    strcpy(str, &str[i]); /*- shift string to the left */

  return(i); /* Return no of matching chars */
}


int rep_last_char (char *str, char ch1, char ch2)
{
  int   i;

  i = strlen(str) - 1;

  if (str[i] == ch1)
    str[i] = ch2;

  return(i);
}

char *strupr (char *string)
{
  char *s;

  if (string) {
    for (s = string; *s; ++s)
      *s = ToUpper(*s);
  }
  return string;
}

char *strlwr(char *string)
{
  char *s;

  if (string) {
    for (s = string; *s; ++s)
      *s = ToLower(*s);
  }
  return string;
}

#define  SKIP(p)  while (IsSpace(*p)) p++;

int strbcmp (const char *a, const char *b)
{
  int cmp;

  while (*a && *b) {
    if (IsSpace(*a) && IsSpace(*b)) {
      SKIP(a);
      SKIP(b);
    } else if ((cmp = (*a++ - *b++)) != 0)
      return (cmp);
  }
  SKIP(a);
  SKIP(b);
  return (*a - *b);
}



/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(src) + MIN(siz, strlen(initial dst)).
 * If retval >= siz, truncation occurred.
 */
int xstrlcat (char *dst, const char *src, size_t siz)
{
  register char *d = dst;
  register const char *s = src;
  register size_t n = siz;
  size_t dlen;

  /* Find the end of dst and adjust bytes left but don't go past end */
  while (n-- != 0 && *d != '\0')
    d++;
  dlen = d - dst;
  n = siz - dlen;

  if (n == 0)
    return (dlen + strlen (s));
  while (*s != '\0') {
    if (n != 1) {
      *d++ = *s;
      n--;
    }
    s++;
  }
  *d = '\0';

  return (dlen + (s - src));    /* count does not include NUL */
}


/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
int xstrlcpy (char *dst, const char *src, size_t siz)
{
  register char *d = dst;
  register const char *s = src;
  register size_t n = siz;

  /* Copy as many bytes as will fit */
  if (n != 0 && --n != 0) {
    do {
      if ((*d++ = *s++) == 0)
        break;
    } while (--n != 0);
  }

  /* Not enough room in dst, add NUL and traverse rest of src */
  if (n == 0) {
    if (siz != 0)
      *d = '\0';              /* NUL-terminate dst */
    while (*s++)
      ;
  }

  return (s - src - 1);   /* count does not include NUL */
}

int textlcpy3 (char *dst, const char *src, size_t max)
{
  size_t i = 0;

  while (i < max) {

    if (IsCntrl(*src)) {
      *dst++ = 0x20;
      src++;
      i++;
    } else {
      *dst++ = *src++;
      i++;
    }
  }

  *dst = '\0';

  return i;
}

int textlcpy2 (char *dst, const char *src, size_t max)
{
  size_t i = 0;

  while (!IsCntrl(*src) && i < max) {
    *dst++ = *src++;
    i++;

    if (IsCntrl(*src) && ((i+1) < max)) {
      *dst++ = 0x20;
      src++;
      i++;
    }
  }

  *dst = '\0';

  return i;
}

int textlcpy (char *dst, const char *src, size_t siz)
{
  register char *d = dst;
  register const char *s = src;
  register size_t n = siz;

  /* Copy as many bytes as will fit */
  if (n != 0 && --n != 0) {
    do {
      if (IsCntrl(*src)) {
        *d = '\0';                /* NUL-terminate dst */
        break;
      } else
      *d++ = *s++;
    }
    while (--n != 0);
  }

  /* Not enough room in dst, add NUL and traverse rest of src */
  if (n == 0) {
    if (siz != 0)
      *d = '\0';              /* NUL-terminate dst */
    return (s - src);         /* count does not include NUL */
  }
  return (s - src - 1);       /* count does not include NUL */
}

char *textcpy (char *dst, const char *src)
{
  char *target = dst;
  if (src && dst) {
    while (!IsCntrl(*src)) *dst++ = *src++;
    *dst = 0;
    return (target);
  }
  else  return NULL;
}

int textlen2 (const char *src, size_t max)
{
  size_t i = 0;

  while (!IsCntrl(*src) && i < max) {
    src++;
    i++;

    if (IsCntrl(*src) && ((i+1) < max)) {
      src++;
      i++;
    }
  }

  return i;
}

int textlen (const char *src, size_t max)
{
  size_t i = 0;
  while (!IsCntrl(*src) && i < max) {
    src++; i++;
  }
  return i;
}

/*
 - msplit - divide a string into fields, like awk split()
 = int split(char *string, char *fields[], int nfields, char *sep);
 */
int    /* number of fields, including overflow */
msplit (char *string, char *fields[], int nfields, char *sep)
{
  register char *p = string;
  register char c;
  register char sepc = sep[0];
  register char sepc2;
  register int fn;
  register char **fp = fields;
  register char *sepp;
  register int trimtrail;

  /* white space */
  if (sepc == '\0') {
    while ((c = *p++) == ' ' || c == '\t') continue;
    p--;
    trimtrail = 1;
    sep = " \t";  /* note, code below knows this is 2 long */
    sepc = ' ';
  } else trimtrail = 0;
  sepc2 = sep[1];    /* now we can safely pick this up */

  /* catch empties */
  if (*p == '\0') return(0);

  /* single separator */
  if (sepc2 == '\0') {
    fn = nfields;
    for (;;) {
      *fp++ = p;
      fn--;
      if (fn == 0) break;
      while ((c = *p++) != sepc)
        if (c == '\0') return(nfields - fn);
      *(p-1) = '\0';
    }
    /* we have overflowed the fields vector -- just count them */
    fn = nfields;
    for (;;) {
      while ((c = *p++) != sepc)
        if (c == '\0') return(fn);
      fn++;
    }
    /* not reached */
  }

  /* two separators */
  if (sep[2] == '\0') {
    fn = nfields;
    for (;;) {
      *fp++ = p;
      fn--;
      while ((c = *p++) != sepc && c != sepc2)
        if (c == '\0') {
          if (trimtrail && **(fp-1) == '\0') fn++;
          return(nfields - fn);
        }
      if (fn == 0) break;
      *(p-1) = '\0';
      while ((c = *p++) == sepc || c == sepc2) continue;
      p--;
    }
    /* we have overflowed the fields vector -- just count them */
    fn = nfields;
    while (c != '\0') {
      while ((c = *p++) == sepc || c == sepc2) continue;
      p--;
      fn++;
      while ((c = *p++) != '\0' && c != sepc && c != sepc2) continue;
    }
    /* might have to trim trailing white space */
    if (trimtrail) {
      p--;
      while ((c = *--p) == sepc || c == sepc2) continue;
      p++;
      if (*p != '\0') {
        if (fn == nfields+1) *p = '\0';
        fn--;
      }
    }
    return(fn);
  }

  /* n separators */
  fn = 0;
  for (;;) {
    if (fn < nfields) *fp++ = p;
    fn++;
    for (;;) {
      c = *p++;
      if (c == '\0') return(fn);
      sepp = sep;
      while ((sepc = *sepp++) != '\0' && sepc != c) continue;
      if (sepc != '\0') break; /* it was a separator */
    }
    if (fn < nfields) *(p-1) = '\0';
    for (;;) {
      c = *p++;
      sepp = sep;
      while ((sepc = *sepp++) != '\0' && sepc != c) continue;
      if (sepc == '\0') break; /* it wasn't a separator */
    }
    p--;
  }
  /* not reached */
}

char *dup_msplit  (char *string, char *fields[], int nfields, char *sep)
{
  char *ptr = xstrdup(string);
  msplit(ptr, fields, nfields, sep);
  return ptr;
}

/* substitute characters. */
void xstrexch (char *str, const char *rstr, const char *sstr)
{
  int one = 0;

  one = rstr[1] ? 0 : 1;
  if (one) {
    while (*str) {
      if (*str == *rstr) *str = *sstr;
      str++;
    }
  } else {
    const char *rp, *sp;
    while (*str) {
      rp = rstr; sp = sstr;
      while (*rp) {
        if (*str == *rp) {
          *str = *sp;
          break;
        }
        rp++; sp++;
      }
      str++;  
    }
  }
}

char *xmemstr (char *stack, char *needle, int size)
{
  char *p;
  char needlesize = strlen(needle);

  for (p = stack; p <= (stack-needlesize+size); p++) {
    if (memcmp(p, needle, needlesize) == 0)
      return p; /* found */
  }
  return NULL;
}

/*
 * Binary Character Search. Given a sorted array of characters, find a given
 * character in the array. Returns 1 if the character is found, 0 if the
 * character is not found.
 * 
 * key - character being looked up
 * list - sorted array of characters to search in
 * len - length of list, minus any trailing (not required) NULL
 */
int bcsrch (char key, const char* list, unsigned int len)
{
  char *base = (char *)list;
  char *last = base + len - 1; /* Last element in table */
  char *p;

  while (last >= base) {
    p = base + ((last - base) >> 1);

    if (key == *p)
      return 1; /* Key found */
    else if (key < *p)
      last = p - 1;
    else
      base = p + 1;
  }
  return 0; /* Key not found */
}
