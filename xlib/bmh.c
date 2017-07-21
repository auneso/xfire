/* 2008/10/09 - HDS */
/* 2011/01/06 - bm */

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "xalloc.h"
#include "bmh.h"


static const unsigned char xlatcase[] = {
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
  0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
  ' ',  '!',  '"',  '#',  '$',  '%',  '&',  0x27,
  '(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
  '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',
  '8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',
  '@',  'a',  'b',  'c',  'd',  'e',  'f',  'g',
  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
  'p',  'q',  'r',  's',  't',  'u',  'v',  'w',
  'x',  'y',  'z',  '[',  0x5c, ']',  '^',  '_',
  '`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',
  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
  'p',  'q',  'r',  's',  't',  'u',  'v',  'w',
  'x',  'y',  'z',  '{',  '|',  '}',  '~',  0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
  0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
  0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
  0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
  0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
  0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
  0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
  0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
  0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};


#define ALPHABET 256


/* vanilla Boyer-Moore-Horspool */
unsigned char *bmh_cs_search (unsigned char *text, int n, unsigned char *pat, int m)
{
  int i, j, k, skip[ALPHABET];

  for (k = 0; k < ALPHABET; k++) skip[k] = m;
  for (k = 0; k < m - 1; k++) skip[pat[k]] = m - k - 1;

  for (k = m - 1; k < n; k += skip[text[k] & (ALPHABET - 1)]) {
    for (j = m - 1, i = k; j >= 0 && text[i] == pat[j]; j--) i--;
    if (j == (-1))
      return (text + i + 1);
  }
  return (NULL);
}

unsigned char *bmh_csw_search (unsigned char *text, int n, unsigned char *pat, int m)
{
  int i, j, k, skip[ALPHABET];

  for (k = 0; k < ALPHABET; k++) skip[k] = m;
  for (k = 0; k < m - 1; k++) skip[pat[k]] = m - k - 1;

  for (k = m - 1; k < n; k += skip[text[k] & (ALPHABET - 1)]) {
    for (j = m - 1, i = k; j >= 0 && text[i] == pat[j]; j--) i--;
    if (j == (-1)) {
      if ((i < 0 || xlatcase[text[i]] < 'a') &&  (i + m + 1 ==  n || xlatcase[text[i+m+1]] < 'a'))
      return (text + i + 1);
    }
  }
  return (NULL);
}


unsigned char *bmh_ci_search (unsigned char *text, int n, unsigned char *pat, int m) 
{
  int i, j, k, skip[ALPHABET];

  for (k = 0; k < ALPHABET; k++) skip[k] = m;
  for (k = 0; k < m - 1; k++) skip[xlatcase[pat[k]]] = m - k - 1;

  for (k = m - 1; k < n; k += skip[xlatcase[text[k]] & (ALPHABET - 1)]) {
    for (j = m - 1, i = k; j >= 0 && xlatcase[text[i]] == xlatcase[pat[j]]; j--) i--;
    if (j == (-1))
      return (text + i + 1);
  }
  return (NULL);
}


unsigned char *bmh_ciw_search (unsigned char *text, int n, unsigned char *pat, int m)
{
  int i, j, k, skip[ALPHABET];

  for (k = 0; k < ALPHABET; k++) skip[k] = m;
  for (k = 0; k < m - 1; k++) skip[xlatcase[pat[k]]] = m - k - 1;

  for (k = m - 1; k < n; k += skip[xlatcase[text[k]] & (ALPHABET - 1)]) {
    for (j = m - 1, i = k; j >= 0 && xlatcase[text[i]] == xlatcase[pat[j]]; j--) i--;
    if (j == (-1)) {
      if ((i < 0 || xlatcase[text[i]] < 'a') &&  (i + m + 1 ==  n || xlatcase[text[i+m+1]] < 'a'))
      return (text + i + 1);
    }
  }
  return (NULL);
}



/* Boyer-Moore string search as found on the internet using Google */

#define MAX(a,b) ((a) < (b) ? (b) : (a))

static void preBmBc (unsigned char *x, int m, int bmBc[])
{
  int i;
  
  for (i = 0; i < BM_ASIZE; ++i)
    bmBc[i] = m;
  
  for (i = 0; i < m - 1; ++i)
    bmBc[x[i]] = m - i - 1;
}


static void suffixes (unsigned char *x, int m, int *suff)
{
  int f, g, i;


  f = 0;
  suff[m - 1] = m;
  g = m - 1;
  for (i = m - 2; i >= 0; --i) {
    if (i > g && suff[i + m - 1 - f] < i - g)
      suff[i] = suff[i + m - 1 - f];
    else {
      if (i < g)
        g = i;
      f = i;
      while (g >= 0 && x[g] == x[g + m - 1 - f])
        --g;
      suff[i] = f - g;
    }
  }
}


static int preBmGs (unsigned char *x, int m, int bmGs[])
{
  int i, j, *suff;


  suff = (int *)xcalloc(sizeof(int), m);
  if (suff == NULL)
    return -1;
  
  suffixes(x, m, suff);
  
  for (i = 0; i < m; ++i)
    bmGs[i] = m;

  j = 0;
  for (i = m - 1; i >= -1; --i)
    if (i == -1 || suff[i] == i + 1)
      for (; j < m - 1 - i; ++j)
        if (bmGs[j] == m)
          bmGs[j] = m - 1 - i;

  for (i = 0; i <= m - 2; ++i)
    bmGs[m - 1 - suff[i]] = m - 1 - i;

  xfree(suff);
  return 0;
}


int bm_init (BM *bmp, unsigned char *x, int m, int icase)
{
  int i;

  memset(bmp, 0, sizeof(BM));

  bmp->icase = icase;
  bmp->bmGs = (int *)xcalloc(sizeof(int), m);
  if (bmp->bmGs == NULL) return -1;
  
  bmp->saved_m = m;
  bmp->saved_x = (unsigned char *)xmalloc(m);
  if (bmp->saved_x == NULL) return -2;
  
  for (i = 0; i < m; i++)
    bmp->saved_x[i] = icase ? xlatcase[x[i]] : x[i];
  
  /* Preprocessing */
  if (preBmGs(bmp->saved_x, m, bmp->bmGs) < 0) return -3;
  
  preBmBc((unsigned char *) bmp->saved_x, m, bmp->bmBc);

  return 0;
}  

void bm_destroy (BM *bmp)
{
  if (bmp->bmGs) xfree(bmp->bmGs);
  if (bmp->saved_x) xfree(bmp->saved_x);
}


/* Search for matches
**
** If mfun is defined, then call this function for each match.
** If mfun returns anything else but 0 abort the search. If the
** returned value is < 0 then return this value, else return the
** number of matches (so far).
**
** If mfun is NULL then stop at first match and return the position
*/

int bm_search (BM *bmp, unsigned char *y, int n, int (*mfun)(void *buf, int n, int pos))
{
  int i, j, c;
  int nm = 0;
  

  /* Searching */
  j = 0;
  while (j <= n - bmp->saved_m) {
    for (i = bmp->saved_m - 1; 
         i >= 0 && bmp->saved_x[i] == (bmp->icase ? xlatcase[y[i + j]] : y[i + j]);
         --i) ;
    
    if (i < 0) {
      if (mfun) {
        ++nm;
        
        if ((c = mfun(y, n, j)))
          return (c < 0 ? c : nm);
        
        j += bmp->bmGs[0];
      }
      else
        return j;
    }
    else {
      unsigned char c = (bmp->icase ? xlatcase[y[i + j]] : y[i + j]);
      j += MAX(bmp->bmGs[i], bmp->bmBc[c] - bmp->saved_m + 1 + i);
    }
  }

  return mfun == NULL ? -1 : nm;
}

/*
    
This example uses an implementation Boyer-Moore-Horspool
matching algorithm as implemented in Streamline (http://ffpf.sourceforge.net).
    
Copyright (c) 2004-2006, Vrije Universiteit Amsterdam
All rights reserved. 
        
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
        
Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
    
Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

Neither the name of the Vrije Universiteit nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

*/

#define ALPHABET_SIZE       256
#define MAX_PATTERN_SIZE    64

static void precompute_badcharacter (const char *pattern, int patlength, int bm_badcharacter_array[])
{
  int i;

  for (i = 0; i < ALPHABET_SIZE; ++i) {
    bm_badcharacter_array[i] = patlength;
  }

  for (i = 0; i < patlength - 1; ++i) {
    bm_badcharacter_array[(u_char)pattern[i]] = patlength - i - 1;
  }   
}

void initBoyerMooreHorspool (const char *pattern, int patlength, int *bm_badcharacter_array)
{
  precompute_badcharacter(pattern, (patlength < MAX_PATTERN_SIZE ? patlength : MAX_PATTERN_SIZE), bm_badcharacter_array);
}

int BoyerMooreHorspool (const char *pattern, int patlength, const char *text, int textlen, int *bm_badcharacter_array)
{
  int j;
  char c;

  j = 0;
  while (j <= textlen - patlength) {
    c = text[j + patlength - 1];
    if (pattern[patlength - 1] == c && memcmp(pattern, text + j, patlength - 1) == 0) {
      return j;
    }
    j += bm_badcharacter_array[(u_char)c];
  }
  return -1;
}
