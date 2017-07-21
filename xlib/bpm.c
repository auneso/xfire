/*
** A Fast Boolean Multi-Pattern Match Engine
** A Trie (from reTrieval), is a multi-way tree structure useful for
** storing strings over an binary. used a 2 byte Bad Characeter shift table 
**
** The boolean operators supported are logical or, logical
**  and, and logical not. These operators are represented by the symbols,
**  "|", "&", and, "!", respectively, and left and right parenthesis, "("
**  and ")", are used as the grouping operators.
**
**  Associativity of operators is left to right, and the precedence of
**  operators is identical to 'C':
**
**    precedence      operator
**
**    high            ! = not
**    middle          & = and
**    lowest          | = or
**
**  The operator symbols can be escaped with the "\\" character to include
**  the symbol in a search pattern.
**
**
** Hash Ternary Search Trie
** 2003/07/01, 2005/01/20  - HDS
** 2005/03/07, 2005/07/05, 2005/07/12 - HDS
** 2008/09/01 - HDS dup pattern support "abcd" "abc", "abc&aaa", "abc&bbb"
** 2008/09/04 - HDS speed up  : one time check for dup patterns
** 2009/01/29 - HDS bpm_lookup , postfix_eval bug fixed
** 2009/02/02 - HDS hash key _bkey, bpm_add_pattern2
** 2009/02/02 - RYH mem_alloc bug fixed xmalloc -> xzalloc
** 2009/02/03 - HDS bpm_find , bpm_add_pattern2 dup check
** 2009/02/04 - HDS llist -> xvector
** 2009/02/06 - HDS bpm_set, bpm_val 
** 2015/02/24 - HDS obstatck
** 2015/03/18 - HDS bpm_add_pattern callback para
** 2015/03/20 - HDS bpm_val remove j
** 2015/04/07 - HDS bpm_add_auto_pattern
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "bpm.h"

typedef struct _bkey {
  int pidx;
  int cidx;
} bkey;

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


#define T_HEX (1<<7)
#define T_ALL (T_HEX)
static unsigned char tbl[0x100]={
  ['a'] T_HEX | 10, ['b'] T_HEX | 11, ['c'] T_HEX | 12, ['d'] T_HEX | 13,
  ['e'] T_HEX | 14, ['f'] T_HEX | 15, ['A'] T_HEX | 10, ['B'] T_HEX | 11,
  ['C'] T_HEX | 12, ['D'] T_HEX | 13, ['E'] T_HEX | 14, ['F'] T_HEX | 15,
  ['0'] T_HEX |  0, ['1'] T_HEX |  1, ['2'] T_HEX |  2, ['3'] T_HEX | 3,
  ['4'] T_HEX |  4, ['5'] T_HEX |  5, ['6'] T_HEX |  6, ['7'] T_HEX | 7,
  ['8'] T_HEX |  8, ['9'] T_HEX |  9,
};


static inline unsigned int chartype (unsigned char c)
{
  return (unsigned int)tbl[c];
}

static inline unsigned char hexchar (unsigned char ch)
{
  return tbl[ch] & ~T_ALL;
}


#define PUSH(x,y) (y)->next=(x);(x)=(y)
#define POP(x) (x);(x)=(x)->next

static void *bpm_malloc(bpm_t *bpm, size_t size)
{
  return obstack_alloc(&bpm->pool, size);
}

static void *bpm_zalloc(bpm_t *bpm, size_t size)
{
  char *ptr;
  ptr = obstack_alloc(&bpm->pool, size);
  memset(ptr, 0, size);
  return ptr;
}

static void *mem_alloc (bpm_t *bpm, size_t size)
{
  void *retval = (void *) 0;
  MEM *ref;

  ref = (MEM *)bpm_malloc(bpm, sizeof(MEM));
  retval = ref->reference = (void *)bpm_zalloc(bpm, size);
  PUSH(bpm->mem_stack, ref);
  return (retval);
}


static void or (bpm_t *bpm, EVAL *element)
{
  EVAL *operand1, *operand2;

  operand1 = POP(bpm->eval_stack);
  operand2 = POP(bpm->eval_stack);

  if (operand1->value != 0 || operand2->value != 0) 
    element->value = operand1->value + operand2->value;
  else 
    element->value = 0; /* no, no matches */
  PUSH(bpm->eval_stack, element);
}

static void and (bpm_t *bpm, EVAL *element)
{
  EVAL *operand1, *operand2;

  operand1 = POP(bpm->eval_stack);
  operand2 = POP(bpm->eval_stack);

  if (operand1->value == 0 || operand2->value == 0)
    element->value = 0; /* yes, no matches */
  else 
    element->value = operand1->value + operand2->value;
  PUSH (bpm->eval_stack, element);
}

static void not (bpm_t *bpm, EVAL *element)
{
  EVAL *operand1, *operand2;

  operand1 = POP(bpm->eval_stack);
  operand2 = POP(bpm->eval_stack);

  if (operand1->value != 0)
    element->value = 0; /* yes, no matches */
  else
    element->value = operand2->value;
  PUSH(bpm->eval_stack, element);
}

static void identifier (bpm_t *bpm, EVAL *element)
{
  PUSH(bpm->eval_stack, element); /* push the eval struture on the eval stack */
}

static int postfix_eval (bpm_t *bpm, ELEMENT *postfix_stack)
{
  ELEMENT *element = postfix_stack;

  bpm->eval_stack = (EVAL *)0;

  while (element != (ELEMENT *) 0) {
    if (element->precedence == BPM_IDENTIFIER) {
      element->eval->value = element->count;
      element->count = 0; /* reset value counter */
    }

    (*element->eval->function)(bpm, element->eval);
    element = element->next;
  }
  
  return (bpm->eval_stack->value);
}

static int allocate_eval (bpm_t *bpm, ELEMENT *element)
{
  element->eval = (EVAL *)mem_alloc(bpm, sizeof(EVAL));

  switch (element->precedence) {

  case BPM_LEFT: /* '(' grouping operator */
    return(1);  /* can't be, syntax error */
    break;

  case BPM_OR: /* "or" operator */
    element->eval->function = (PTF)or; 
    break;

  case BPM_AND: /* "and" operator */
    element->eval->function = (PTF)and;
    break;

  case BPM_NOT: /* "not" operator */
    element->eval->function = (PTF)not; 
    break;

  case BPM_RIGHT: /* ')' grouping operator */
    return(2);  /* can't be, syntax error */
    break;

  case BPM_IDENTIFIER: /* a word */
    element->eval->function = (PTF) identifier;
    break;

  case BPM_NONE: /* no token */
    return(3);  /* can't be, syntax error */
    break;

  default:
    return(4);  /* can't be, syntax error */
    break;
  }
  return(0);
}


static enum token_type
lexicon (unsigned char *buffer, int buffer_len, int *skip_len,
         unsigned char *token, int *token_len, int is_boolean)
{
  unsigned char *buffer_ref;
  unsigned char *token_ref;
  int lexical_state = 0, tlen = 0, slen = 0;;
  enum token_type retval = BPM_NONE;

  if (!is_boolean) {
    if (buffer_len) {
      memcpy(token, buffer, buffer_len);
      *skip_len  = buffer_len;
      *token_len = buffer_len;
      return BPM_IDENTIFIER;
    } else { 
      return BPM_NONE;
    } 
  }

  token_ref  = token;
  buffer_ref = buffer;

  while (buffer_len && lexical_state != 2) {
    switch (*buffer_ref) {
      case '(': /* '(' grouping operator */
      case ')': /* ')' grouping operator */
      case '&': /* "and" operator */
      case '|': /* "or" operator */
      case '!': /* "not" operator */
        if (lexical_state == 0) { /* initial state? */
          *token_ref = *buffer_ref;
          token_ref++;
          tlen++;

          switch (*buffer_ref) {
          case '(': /* '(' grouping operator */
            retval = BPM_LEFT; break;

          case ')': /* ')' grouping operator */
            retval = BPM_RIGHT; break;

          case '&': /* "and" operator */
            retval = BPM_AND; break;

          case '|': /* "or" operator */
            retval = BPM_OR; break;

          case '!': /* "not" operator */
            retval = BPM_NOT; break;

          default: /* end of buffer "operator" */
            retval = BPM_NONE; break;
          }
        } else {
          buffer_ref--;
          buffer_len++;
          slen--;
        }
        lexical_state = 2;
        break;

#ifdef HDS  /* for binary pattern */
      case ' ': /* white space */
      case '\f':
      case '\r':
      case '\v':
      case '\t':
      case '\n':
        if (lexical_state != 0)  /* initial state? */
          lexical_state = 2; 
        break;
#endif

      case '\\': /* character an escape character? */
        buffer_ref++; /* skip escape char */
        buffer_len--;
        slen++;

        *token_ref = *buffer_ref;
        token_ref++;
        tlen++;
        retval = BPM_IDENTIFIER;
        lexical_state = 1;
        break;

      case '$': /* character an hexa character? */
        if (buffer_len > 2) {
          buffer_ref++; /* skip escape char */
          buffer_len--;
          slen++;
          
          *token_ref = hexchar(*buffer_ref) << 4;
          buffer_ref++;
          buffer_len--;
          slen++;
          *token_ref |= hexchar(*buffer_ref);
          token_ref++;
          tlen++;
          retval = BPM_IDENTIFIER;
          lexical_state = 1; 
          break;
        } 

      default :
        *token_ref = *buffer_ref;
        token_ref++;
        tlen++;
        retval = BPM_IDENTIFIER;
        lexical_state = 1; 
        break;
    }

    buffer_ref++;
    buffer_len--;
    slen++;
  }
  *token_len = tlen;
  *skip_len  = slen;
  *token_ref = '\0'; 

  return (retval); /* return the lexicon type */
}


static ELEMENT *
postfix_proc (bpm_t *bpm, bpm_pat_t *pat, int nocase, int is_boolean)
{
  unsigned char *token, *pattern;
  int grouping_count = 0, operand_count = 0;
  enum token_type lex_val, precedence;
  ELEMENT *intermediate_element,
          *new_element = (ELEMENT *)0,
          *intermediate_stack = (ELEMENT *)0,
          *forward_postfix_stack = (ELEMENT *)0,
          *reverse_postfix_stack = (ELEMENT *)0,
          *retval = (ELEMENT *)0;
   int plen, slen, tlen;

  if (nocase) pattern = pat->pat;
  else        pattern = pat->org;
  plen  = pat->len;
  token = pat->tokens;

  while ((lex_val = lexicon(pattern, plen, &slen, token, &tlen, is_boolean)) != BPM_NONE) {
    if (lex_val != BPM_RIGHT) { /* is the token a ')'? */
      new_element = (ELEMENT *)mem_alloc(bpm, sizeof(ELEMENT));

      new_element->lexicon    = token;
      new_element->length     = tlen;
      new_element->precedence = lex_val;
      new_element->eval       = (EVAL *)0;

      if (lex_val != BPM_LEFT)  /* is the token a '('? */
        if (allocate_eval(bpm, new_element)) return NULL;
    }

    switch (lex_val) {
      case BPM_NOT: /* operator? */
      case BPM_AND:
      case BPM_OR:
        if (intermediate_stack != (ELEMENT *) 0) {
          do {
            if (intermediate_stack == (ELEMENT *) 0) {
              intermediate_element = (ELEMENT *) 0; break;
            }

            intermediate_element = POP(intermediate_stack);

            if (intermediate_element != (ELEMENT *) 0
            && (int) intermediate_element->precedence >= (int)lex_val) {
              PUSH(reverse_postfix_stack, intermediate_element);
            }
          } while (intermediate_element != (ELEMENT *) 0
          &&  (int)intermediate_element->precedence >= (int)lex_val);

          if (intermediate_element != (ELEMENT *) 0) {
            PUSH(intermediate_stack, intermediate_element);
          }
        }
        PUSH(intermediate_stack, new_element);
        break;

      case BPM_LEFT: /* '(' grouping operator? */
        grouping_count++;
        PUSH(intermediate_stack, new_element);
        break;

      case BPM_RIGHT: /* ')' grouping operator? */
        if (--grouping_count >= 0) {
          do {
            intermediate_element = POP(intermediate_stack);
            precedence = intermediate_element->precedence;

            if (precedence != BPM_LEFT) { /* token a '('? */
              PUSH(reverse_postfix_stack, intermediate_element); 
            }
          } while (precedence != BPM_LEFT);
        }
        break;

      case BPM_IDENTIFIER: /* a word? */
      case BPM_NONE:       /* no token? */
      default:
        PUSH (reverse_postfix_stack, new_element);
        break;
    }

    token   += tlen+1;
    pattern += slen;
    plen    -= slen;
  }

  if (grouping_count == 0) {
    while (intermediate_stack != (ELEMENT *)0) {
      intermediate_element = POP(intermediate_stack);
      PUSH(reverse_postfix_stack, intermediate_element);
    }

    while (reverse_postfix_stack != (ELEMENT *)0) {
      intermediate_element = POP(reverse_postfix_stack);
      PUSH(forward_postfix_stack, intermediate_element);
    }

    retval = forward_postfix_stack;
    intermediate_element = forward_postfix_stack;

    while (intermediate_element != (ELEMENT *)0) {
      if (intermediate_element->precedence == BPM_IDENTIFIER)
        operand_count++;
      else {
        operand_count--;

        if (operand_count < 1) {
          return NULL; 
        }
      }
      intermediate_element = intermediate_element->next;
    }

    if (operand_count != 1)  /* operand count not one? */
      return NULL; 
  }
  return (retval);
}


static void lowercpy (unsigned char *dst, unsigned char *src, int len)
{
  int i;

  for (i = 0; i < len; i++) 
    dst[i] = (unsigned char)xlatcase[src[i]];
}


#define ALPHABET 256


/* vanilla Boyer-Moore-Horspool */
static unsigned char *bmh_search (unsigned char *text, int n, unsigned char *pat, int m)
{
  int i, j, k, skip[ALPHABET];

  for (k = 0; k < ALPHABET; k++)
    skip[k] = m;
  for (k = 0; k < m - 1; k++)
    skip[pat[k]] = m - k - 1;

  for (k = m - 1; k < n; k += skip[text[k] & (ALPHABET - 1)]) {
    for (j = m - 1, i = k; j >= 0 && text[i] == pat[j]; j--)
      i--;
    if (j == (-1))
      return (text + i + 1);
  }
  return (NULL);
}

static int patcmp (ELEMENT *postfix, unsigned char *ptr)
{
  /* Uooo bad search */
  if (bmh_search(postfix->pat->org, postfix->pat->len, ptr, postfix->length))
    return 0;
  return 1;
}


static int bpm_insert (bpm_t *bpm, unsigned char *s, int l, ELEMENT *element)
{
  int diff;
  bpm_node_t *curr, **pcurr;
  el_node_t *node;

  pcurr = &bpm->hash[((*s)<<8) | *(s+1)];
  s += 2; l -= 2;

  while ((curr = *pcurr)) {
    if (l == 0) { 
      if (!curr->path) curr->path = BPM_EQU_PATH;
      node = (el_node_t *)bpm_zalloc(bpm, sizeof(el_node_t)); 
      node->element = element;
      PUSH(curr->dup, node);
      return 1;
    }

    diff = *s - curr->dchar;
    if      (diff < 0) pcurr = &(curr->lo);
    else if (diff > 0) pcurr = &(curr->hi);
    else { s++, l--;   pcurr = &(curr->eq); }
  }
  for (;;) {
    curr = *pcurr = (bpm_node_t *)bpm_zalloc(bpm, sizeof(bpm_node_t)); /* The memory is set to zero */

    if (l == 0) {
      node = (el_node_t *)bpm_zalloc(bpm, sizeof(el_node_t));
      node->element = element;
      PUSH(curr->dup, node);
      curr->path  = BPM_END_PATH;
      curr->dchar = *(s-1);
      return 1;
    }
    curr->dchar = *s++;  l--;
    curr->path = BPM_NEW_PATH;
    pcurr = &(curr->eq);
  }
  return 1;
}

static void bpm_set (bpm_t *bpm, unsigned char *ptr, el_node_t *dup, int cs)
{
  ELEMENT *postfix;
  el_node_t *tnode, *node = dup;

  while (node != (el_node_t *)0) {
    tnode = POP(node);
    postfix = tnode->element;

    if (postfix->count) break; /* only first set */

    if (cs || postfix->pat->nocase || !patcmp(postfix, ptr)) {
      postfix->count++;
      postfix->ptr = (char *)ptr;
      bpm->match[postfix->pat->sid] = postfix;
    }
  }
}

static int bpm_val (bpm_t *bpm, bpm_match_f match, void *user)
{
  ELEMENT *postfix;
  int i, m;

  for (i = 0, m = 0; i < bpm->mcount; i++) {
    postfix = bpm->match[i];
    if (postfix) {
      if (postfix_eval(bpm, postfix->pat->postfix_stack)) {
        m++;
        if (postfix->pat->match)  postfix->pat->match(postfix, user);
        else if (match)  match(postfix, user);
      }
      bpm->match[i] = NULL;
    }
  }
  return m;
}

static int
bpm_ci (bpm_t *bpm, unsigned char *text, int len, void *user, bpm_match_f match)
{
  bpm_node_t *curr;
  unsigned char *ptr, *pend, *b, *s;
  int shift, diff;

  ptr  = text;
  pend = text + len;

  for (b = ptr + bpm->slen - 1; b < pend; ptr++, b++) {
    shift = bpm->shift[(xlatcase[*b]<<8) | xlatcase[*(b-1)]];

    while (shift) {
      b  += shift; ptr += shift;
      if (b >= pend) goto do_eval;
      shift = bpm->shift[(xlatcase[*b]<<8) | xlatcase[*(b-1)]];
    }

    curr = bpm->hash[(xlatcase[*ptr]<<8) | xlatcase[*(ptr+1)]];
    if (curr) {
      s = ptr + 2;
      do {
        if (curr->path) { /* match pattern */
          bpm_set(bpm, ptr, curr->dup, 0);
        }
        diff = xlatcase[*s] - curr->dchar;
        if      (diff < 0) curr = curr->lo;
        else if (diff > 0) curr = curr->hi;
        else { s++;        curr = curr->eq; }
      } while (curr && s <= pend);
    }
  }
do_eval:
  return bpm_val(bpm, match, user);
}

static int
bpm_cs (bpm_t *bpm, unsigned char *text, int len, void *user, bpm_match_f match)
{
  bpm_node_t *curr;
  unsigned char *ptr, *pend, *b, *s;
  int shift, diff;

  ptr  = text;
  pend = text + len;

  for (b = ptr + bpm->slen - 1; b < pend; ptr++, b++) {
    shift = bpm->shift[(*b<<8) | *(b-1)];

    while (shift) {
      b  += shift; ptr += shift;
      if (b >= pend) goto do_eval;
      shift = bpm->shift[(*b<<8) | *(b-1)];
    }

    curr = bpm->hash[(*ptr<<8) | *(ptr+1)];
    if (curr) {
      s = ptr + 2;
      do {
        if (curr->path) { /* match pattern */
          bpm_set(bpm, ptr, curr->dup, 1);
        }
        diff = *s - curr->dchar;
        if      (diff < 0) curr = curr->lo;
        else if (diff > 0) curr = curr->hi;
        else { s++;        curr = curr->eq; }
      } while (curr && s <= pend);
    }
  }
do_eval:
  return bpm_val(bpm, match, user);
}

bpm_t *bpm_create (void)
{
  bpm_t *bpm;

  bpm = (bpm_t *)xzalloc(sizeof(bpm_t));
  bpm->htab       = hcreate(64);
  bpm->slen       = 1024;  
  bpm->mem_stack  = (MEM *)0;
  obstack_init(&bpm->pool);
  return bpm;
}

void bpm_destroy (bpm_t *bpm)
{
  obstack_free(&bpm->pool, NULL);
  hdestroy(bpm->htab);
  xfree(bpm);
}

int bpm_add_pattern2 (bpm_t *bpm, unsigned char *pattern, int plen,
                     int nocase, int is_boolean, int pid, int cid, void *user, bpm_match_f match) 
{
  bpm_pat_t *pat;
  bkey key;
  
  if (!bpm) return  BPM_NOT_CREATE;

  key.pidx   = pid;
  key.cidx   = cid;
  if (hfind(bpm->htab, (ub8 *)&key, sizeof(bkey))) return BPM_DUP_PATTERN;
  if (plen < 2) return BPM_SMALL_PATTERN;

  pat = bpm_zalloc(bpm, sizeof(bpm_pat_t));
  pat->pidx   = pid;
  pat->cidx   = cid;
  pat->len    = plen;
  pat->user   = user;
  pat->match  = match;
  pat->nocase = nocase ? 1 : 0;
  pat->boolean = is_boolean ? 1 : 0;
  pat->pat = bpm_zalloc(bpm, plen+1);
  lowercpy(pat->pat, pattern, plen);
  pat->org = bpm_zalloc(bpm, plen+1);
  memcpy(pat->org, pattern, plen);

  pat->tokens = bpm_zalloc(bpm, (plen+1) * 2);

  hadd(bpm->htab, (ub8 *)pat, sizeof(bkey), pat);
  return 0;
}

int bpm_add_pattern (bpm_t *bpm, unsigned char *pattern, int plen,
                     int nocase, int is_boolean, int cidx, void *user, bpm_match_f match) 
{
  return bpm_add_pattern2 (bpm, pattern, plen, nocase, is_boolean, 0, cidx, user, match); 
}


int bpm_add_auto_pattern (bpm_t *bpm, unsigned char *pattern, int plen,
                          int nocase, int pidx, int cidx, void *user, bpm_match_f match)
{
  int is_boolean = 0;
  char *ptr = (char *)pattern;
  char *end = ptr + plen;
  
  while (ptr < end) {
    switch (*ptr) {
      case '(': case ')': case '&': case '|': case '!': 
        is_boolean = 1;
        goto end_proc;
      case '\\':
        ptr++;
      default:
        ptr++;
     }
  }
end_proc:
  return bpm_add_pattern2 (bpm, pattern, plen, nocase, is_boolean, pidx, cidx, user, match);
}

int bpm_compile (bpm_t *bpm)
{
  bpm_pat_t *pat;
  unsigned short shift, cindex, slen = bpm->slen;
  unsigned char *ptr;
  int i, nocase = 0;
  ELEMENT *postfix_stack, *temp_element;

  if (!bpm) return  BPM_NOT_CREATE;
  if (hcount(bpm->htab) == 0) return 0;

  bpm->mcount = hcount(bpm->htab);
  bpm->match = (ELEMENT **)bpm_zalloc(bpm, sizeof(ELEMENT *) * hcount(bpm->htab));

  i = 0;
  if (hfirst(bpm->htab)) do { 
    pat = hstuff(bpm->htab);
    pat->sid = i++;  /* pattern seq number */
    nocase  += pat->nocase;
  } while (hnext(bpm->htab));

  if (hfirst(bpm->htab)) do { 
    pat = hstuff(bpm->htab);
    pat->postfix_stack = postfix_proc(bpm, pat, nocase, pat->boolean);
    if (!pat->postfix_stack) {
      printf("BPM syntax error = [%s]\n", pat->org);
      return BPM_BAD_SYNTAX; /* syntax error */
    }
  } while (hnext(bpm->htab));

   
  if (hfirst(bpm->htab)) do { 
    pat = hstuff(bpm->htab);

    postfix_stack = pat->postfix_stack;
    while (postfix_stack != (ELEMENT *)0) {
      temp_element = POP(postfix_stack);
      if (temp_element->precedence == BPM_IDENTIFIER) {
        temp_element->pat = pat;
        if (temp_element->length < 2) {
          printf("ERROR [%s] len = %d, [%s]\n", pat->org, temp_element->length, temp_element->lexicon);
          return BPM_SMALL_TOKEN;  /* token length too small  < 2 */ 
        }
        if (temp_element->length < slen) slen = temp_element->length;
      }
    }
  } while (hnext(bpm->htab));

  if (slen > 255) slen = 255;
  bpm->slen = slen;

  for (i = 0; i < BPM_MAX_SHIFT_SIZE;i++)
    bpm->shift[i] = slen-1;


  if (hfirst(bpm->htab)) do {
    pat = hstuff(bpm->htab);
    
    postfix_stack = pat->postfix_stack;
    while (postfix_stack != (ELEMENT *)0) {
      temp_element = POP(postfix_stack);
      if (temp_element->precedence == BPM_IDENTIFIER) {
    
        ptr = temp_element->lexicon;
        if (!bpm_insert(bpm, ptr, temp_element->length, temp_element)) { 
          return BPM_DUP_TOKEN; /* dup token */
        }
        bpm->ecount++;

        for (i = 0; i < slen - 1; i++) {
          shift = slen - 2 - i;
          if (shift > 255) shift = 255;
          cindex = (ptr[i] | (ptr[i+1]<<8));

          if (shift < bpm->shift[cindex]) {
            bpm->shift[cindex] = shift;
          }
        }
      }
    }
  } while (hnext(bpm->htab));

  if (nocase) bpm->search = bpm_ci;
  else        bpm->search = bpm_cs;
  return 0;
} 

int bpm_find (bpm_t *bpm, unsigned char *text, int len)
{
  if (!bpm ||!bpm->search || !text || len < bpm->slen) return 0; 
  return bpm->search(bpm, text, len, NULL, NULL);
}

int bpm_search (bpm_t *bpm, unsigned char *text, int len, void *user, bpm_match_f match)
{
  if (!bpm || !bpm->search || !text || len < bpm->slen) return 0;
  return bpm->search(bpm, text, len, user, match);
}

static int match_vector (ELEMENT *postfix, void *user)
{
  xvector_append((xvector *)user, postfix->pat->user);
  return 0; 
}

/* use after must free */
xvector *bpm_lookup (bpm_t *bpm, unsigned char *text, int len)
{
  if (!bpm || hcount(bpm->htab) == 0 || !text || len < bpm->slen) return NULL;
  xvector *xv = xvector_create(0);

  bpm->search(bpm, text, len, xv, match_vector);

  if (xvector_count(xv)) return xv;
  xvector_destroy(xv);
  return NULL; 
}

int bpm_apply (bpm_t *bpm, bpm_apply_f apply, void *user)
{
  bpm_pat_t *pat;
  int count = 0;

  if (!bpm) return 0; 
  if (hcount(bpm->htab) == 0) return count;

  if (hfirst(bpm->htab)) do { 
    count++;
    pat = hstuff(bpm->htab);
    if (apply(pat, user)) break;
  } while (hnext(bpm->htab));
  return count;
}

int bpm_count (bpm_t *bpm)
{
  if (!bpm) return 0; 
  return hcount(bpm->htab);
}


int bpm_element_count (bpm_t *bpm)
{
  if (!bpm) return 0;
  return bpm->ecount;
}
