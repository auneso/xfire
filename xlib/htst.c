/*
** A Fast Multi-Pattern Search Engine
** Hash Ternary Search Trie
** A Trie (from reTrieval), is a multi-way tree structure useful for
** storing strings over an binary. used a 2 byte Bad Characeter shift table
** Trie is an efficient indexing method.
** It is indeed also a kind of deterministic finite automaton (DFA)
**
** 2003/07/01, 2005/01/20
** 2005/03/07, 2005/07/05
** 2008/08/29  HDS  EQU path pattern handling (eg :"abc", "abcd", "abcde").
** 2008/10/10  HDS  word pattern
** 2009/02/05  HDS  htst_find
** 2009/08/05  HDS  match para (ptr - text -> pend - ptr)
** 2011/01/13  HDS  seach skip
** 2011/10/17  HDS  front, back word 
** 2012/02/07  HDS  search longest pattern
** 2012/04/17  HDS  pat para text, text length
** 2012/05/23  HDS  HTST_CHECK_WORD
** 2013/01/10  HDS  HTST_FIRST_WORD
** 2013/03/10  HDS  void *htst_add_pattern2 (htst_t *htst, unsigned char *key, int len, int id, int flag, void *user)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "xalloc.h"
#include "obstack.h"
#include "htst.h"

#ifdef HTST_USE_UTF8
/* UTF support */
#include "utf8tables.h"
#endif

#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif


#if 0
/* the last '\0' is not needed because string is zero terminated */
static u_char  lowcase[] =
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0-\0\0" "0123456789\0\0\0\0\0\0"
  "\0abcdefghijklmnopqrstuvwxyz\0\0\0\0\0"
  "\0abcdefghijklmnopqrstuvwxyz\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
#endif


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
  'x',  'y',  'z',  '[',  '\\', ']',  '^',  '_',
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

#define IS_FIRST_WORD (ptr == text)
#define IS_F_WORD     (ptr == text || *(ptr - 1) < 0x21)
#define IS_B_WORD     (ptr + pat->len == pend || *(ptr + pat->len) < 0x21)
#define IS_WORD       (IS_F_WORD && IS_B_WORD)
#define IS_F_L_WORD   (ptr == text || *(ptr - 1) == '\n' || *(ptr - 1) == '\r')
#define IS_F_L_B_WORD (IS_F_L_WORD && IS_B_WORD)
#define IS_B_L_WORD   (ptr + pat->len == pend  || *(ptr + pat->len) == '\r' || *(ptr + pat->len) == '\n')
#define IS_B_L_F_WORD (IS_B_L_WORD && IS_F_WORD)
#define IS_L_WORD     (IS_F_L_WORD && IS_B_L_WORD)

#define HTST_CHECK_WORD \
  switch (pat->flag & HTST_MASK_WORD) {                                \
    default              : break;                                      \
    case HTST_FIRST_WORD : if (!IS_FIRST_WORD) return nfound;   break; \
    case HTST_WORD       : if (!IS_WORD)       goto next_match; break; \
    case HTST_F_WORD     : if (!IS_F_WORD)     goto next_match; break; \
    case HTST_B_WORD     : if (!IS_B_WORD)     goto next_match; break; \
    case HTST_L_WORD     : if (!IS_L_WORD)     goto next_match; break; \
    case HTST_F_L_WORD   : if (!IS_F_L_WORD)   goto next_match; break; \
    case HTST_B_L_WORD   : if (!IS_B_L_WORD)   goto next_match; break; \
    case HTST_F_L_B_WORD : if (!IS_F_L_B_WORD) goto next_match; break; \
    case HTST_B_L_F_WORD : if (!IS_B_L_F_WORD) goto next_match; break; \
  }

static void lowercpy (unsigned char *dst, unsigned char *src, int len)
{
  int i;
  for (i = 0; i < len; i++) dst[i] = (unsigned char)xlatcase[src[i]];
}

static htst_pat_t *htst_insert (htst_t *htst, unsigned char *p, int len, htst_pat_t *pat)
{
  int diff, l = len;
  htst_node_t *curr, **pcurr;
  unsigned char *s = p;

  pcurr = &htst->hash[((*s)<<8) | *(s+1)];
  s += 2; l -= 2;

  while ((curr = *pcurr)) {
    if (l == 0) { 
      if (curr->path) { /* dup pattern */
        return NULL;
      } else {  
        curr->path |= HTST_EQU_PATH;
        curr->pat  = pat;
        return pat;
      }
    } else if (curr->path) curr->path |= HTST_EQU_PATH;
    diff = *s - curr->dchar;
    if      (diff < 0) pcurr = &(curr->lo);
    else if (diff > 0) pcurr = &(curr->hi);
    else { s++, l--;   pcurr = &(curr->eq); }
  }

  for (;;) {
    curr = *pcurr = (htst_node_t *)obstack_alloc(&htst->pool, sizeof(htst_node_t)); /* The memory is set to zero */
    memset(curr, 0, sizeof(htst_node_t));
    if (l == 0) {
      curr->pat   = pat;
      curr->path  = HTST_END_PATH;
      curr->dchar = *(s-1);
      return pat;
    }
    curr->dchar = *s++;  l--;
    curr->path = HTST_NEW_PATH;
    pcurr = &(curr->eq);
  }
}


static int
htst_ci (htst_t *htst, unsigned char *text, int len, htst_match_f match, void *user)
{
  htst_pat_t *pat;
  htst_node_t *curr, *eqn = NULL;
  unsigned char *ptr, *pend, *b, *s, *sp, *eqp = NULL;
  int shift, diff, nfound = 0, minlen = htst->minlen -1;

  ptr = text; pend = text + len;
  b = ptr + minlen;
  do {
    shift = htst->shift[(xlatcase[*b]<<8) | xlatcase[*(b-1)]];
    while (shift) {
      b  += shift; ptr += shift;
      if (b >= pend) return nfound;
      shift = htst->shift[(xlatcase[*b]<<8) | xlatcase[*(b-1)]];
    }

    curr = htst->hash[(xlatcase[*ptr]<<8) | xlatcase[*(ptr+1)]];
    if (curr) {
      sp = ptr;
      s = ptr + 2;
      do {
        if (curr->path & HTST_EQU_PATH && curr->pat) {
          eqp = ptr; eqn = curr;
        } else
        if (curr->path & HTST_END_PATH) {
          pat = curr->pat;
prev_match:
          eqp = NULL;
          HTST_CHECK_WORD
          if ((pat->flag & HTST_NOCASE) || memcmp(pat->org, ptr, pat->len) == 0) {
            nfound++;
            if (match(pat, &ptr, pend - ptr, user) == HTST_STOP_MATCH) return nfound;
          }
          break;
        }
        diff = xlatcase[*s] - curr->dchar;
        if      (diff < 0) curr = curr->lo;
        else if (diff > 0) curr = curr->hi;
        else { s++;        curr = curr->eq; }
      } while (curr && s <= pend);
next_match:
      if (eqp) {
        pat = eqn->pat;
        ptr = eqp;
        goto prev_match;
      }
      if (ptr == sp) { ptr++; b++; }
      else  b += ptr - sp;
    } else {
      ptr++; b++; 
    }
  } while (b < pend);
  return nfound;
}

static int
htst_cs (htst_t *htst, unsigned char *text, int len, htst_match_f match, void *user)
{
  htst_pat_t *pat; 
  htst_node_t *curr, *eqn = NULL;
  unsigned char *ptr, *pend, *b, *s, *sp, *eqp = NULL;
  int shift, diff, nfound = 0, minlen = htst->minlen -1;

  ptr = text; pend = text + len;
  b = ptr + minlen;
  do  {
    shift = htst->shift[(*b<<8) | *(b-1)];
    while (shift) {
      b += shift; ptr += shift;
      if (b >= pend) return nfound;
      shift = htst->shift[(*b<<8) | *(b-1)];
    }

    curr = htst->hash[(*ptr<<8) | *(ptr+1)];
    if (curr) {
      sp = ptr; 
      s = ptr + 2;
      do {
        if (curr->path & HTST_EQU_PATH && curr->pat) {
          eqp = ptr; eqn = curr;
        } else
        if (curr->path & HTST_END_PATH) {
          pat = curr->pat;
prev_match:
          eqp = NULL;
          HTST_CHECK_WORD
          nfound++;
          if (match(pat, &ptr, pend - ptr, user) == HTST_STOP_MATCH) return nfound;
          break;
        }
        diff = *s - curr->dchar;
        if      (diff < 0) curr = curr->lo;
        else if (diff > 0) curr = curr->hi;
        else { s++;        curr = curr->eq; }
      } while (curr && s <= pend);
next_match:
      if (eqp) {
        pat = eqn->pat;
        ptr = eqp;
        goto prev_match;
      }        
      if (ptr == sp) { ptr++; b++; }
      else  b += ptr - sp;
    } else {
      ptr++; b++;
    }
  } while (b < pend);
  return nfound;
}

static int cmp_name (void *a, void *b, void *user)
{
  htst_pat_t *ha = (htst_pat_t *)a;
  htst_pat_t *hb = (htst_pat_t *)b;
  int rv = ha->len - hb->len;
  user = user;
  if (rv == 0) return memcmp((char *)ha->org, (char *)hb->org, ha->len);
  return rv;
}

htst_t *htst_create (void)
{
  htst_t *htst;

  htst = (htst_t *)xzalloc(sizeof(htst_t));
  obstack_init(&htst->pool);
  htst->root   = rbtree_create(cmp_name, 0 , NULL);
  htst->minlen = 1024;
  return htst;
}

void htst_destroy (htst_t *htst)
{
  rbtree_destroy(htst->root);
  obstack_free(&htst->pool, NULL);
  xfree(htst);
}

int htst_add_pattern (htst_t *htst, unsigned char *key, int len, int id, int flag, void *user) 
{
  htst_pat_t *pat, node;

  node.org = key;
  node.len = len;
  if (len < 2 || rbtree_search(htst->root, (RBTreeNode *)&node)) return 0;  /* pattern dup ? */

  pat = obstack_alloc(&htst->pool, sizeof(htst_pat_t));
  pat->id     = id;
  pat->len    = len;
  pat->user   = user;
  pat->flag   = flag;
  pat->pat = obstack_alloc(&htst->pool, len+1);
  lowercpy(pat->pat, key, len); pat->pat[len] = 0;
  pat->org = obstack_alloc(&htst->pool, len+1);
  memcpy(pat->org, key, len);   pat->org[len] = 0;

  rbtree_insert(htst->root, (RBTreeNode *)pat);
  return 1;
}

void *htst_add_pattern2 (htst_t *htst, unsigned char *key, int len, int id, int flag, void *user)
{
  htst_pat_t *pat, node;

  node.org = key;
  node.len = len;

  if (len < 2) return NULL;
  if ((pat = (htst_pat_t *)rbtree_search(htst->root, (RBTreeNode *)&node))) return pat->user;  /* pattern dup ? */

  pat = obstack_alloc(&htst->pool, sizeof(htst_pat_t));
  pat->id     = id;
  pat->len    = len;
  pat->user   = user;
  pat->flag   = flag;
  pat->pat = obstack_alloc(&htst->pool, len+1);
  lowercpy(pat->pat, key, len); pat->pat[len] = 0;
  pat->org = obstack_alloc(&htst->pool, len+1);
  memcpy(pat->org, key, len);   pat->org[len] = 0;

  rbtree_insert(htst->root, (RBTreeNode *)pat);
  return user;
}

void htst_compile (htst_t *htst)
{
  htst_pat_t *pat;
  unsigned short shift, cindex, slen = htst->minlen;
  unsigned char *ptr;
  int i, nocase = 0;

  if (rbtree_count(htst->root) == 0) return;

  if ((pat = (htst_pat_t *)rbtree_first(htst->root))) do { 
    nocase |= (pat->flag & HTST_NOCASE);
    if (pat->len < slen) slen = pat->len;
  } while ((pat = (htst_pat_t *)rbtree_next((RBTreeNode *)pat)));
  if (slen > 255) slen = 255;
  htst->minlen = slen;

  for (i = 0; i < HTST_MAX_SHIFT_SIZE; i++) htst->shift[i] = slen-1;

  if ((pat = (htst_pat_t *)rbtree_first(htst->root))) do {
    if (nocase) ptr = pat->pat;
    else        ptr = pat->org; 

    htst_insert(htst, ptr, pat->len, pat); 

    for (i = 0; i < slen - 1; i++) {
      shift = slen - 2 - i;
      if (shift > 255) shift = 255;
  
      cindex = (ptr[i] | (ptr[i+1]<<8));
  
      if (shift < htst->shift[cindex]) htst->shift[cindex] = shift;
    }
  } while ((pat = (htst_pat_t *)rbtree_next((RBTreeNode *)pat)));

  if (nocase) htst->search = htst_ci;
  else        htst->search = htst_cs;
} 


int htst_search (htst_t *htst, unsigned char *text, int len, htst_match_f match, void *user)
{
  if (!htst || rbtree_count(htst->root) == 0 || !text || len < htst->minlen) return 0;
  return htst->search(htst, text, len, match, user);
}

int htst_apply (htst_t *htst, htst_apply_f apply, void *user)
{
  htst_pat_t *pat;
  int count = 0;

  if (rbtree_count(htst->root) == 0) return count;

  if ((pat = (htst_pat_t *)rbtree_first(htst->root))) do { 
    count++;
    if (apply(pat, user)) break;
  } while ((pat = (htst_pat_t *)rbtree_next((RBTreeNode *)pat)));
  return count;
}

int htst_count (htst_t *htst)
{
  return rbtree_count(htst->root);
}

