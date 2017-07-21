#ifndef __BPM_H__
#define __BPM_H__

/*
** Hash Ternary Search Trie - HDS
*/

#include "hashtab.h"
#include "xvector.h"
#include "obstack.h"


typedef struct mem
{
  void *reference;  /* reference to allocated area */
  struct mem *next; /* reference to next element in the allocated list */
} MEM;


enum token_type
{
  BPM_LEFT,        /* '(' grouping operator */
  BPM_OR,          /* "or" operator */
  BPM_AND,         /* "and" operator */
  BPM_NOT,         /* "not" operator */
  BPM_RIGHT,       /* ')' grouping operator */
  BPM_IDENTIFIER,  /* a word */
  BPM_NONE         /* no token */
};


typedef struct symbol_element
{
  unsigned char *lexicon;
  int    length;
  enum   token_type precedence;
  struct symbol_element *next;
  struct eval_element *eval;

  struct bpm_pattern *pat;
  char *ptr;

  int count;
} ELEMENT;

typedef struct bpm bpm_root;

typedef void (*PTF)(bpm_root *bpm, struct eval_element *element);

typedef struct eval_element
{
  int value;
  PTF function;
  struct eval_element *next;
} EVAL;

typedef int (*bpm_match_f)(ELEMENT *postfix, void *user);

#define BPM_CASE_INSENSITIVE 0x01
#define BPM_BOOLEAN_SEARCH   0x02

#define BPM_DUP_PATTERN      -1
#define BPM_SMALL_PATTERN    -2
#define BPM_DUP_TOKEN        -3
#define BPM_SMALL_TOKEN      -4
#define BPM_BAD_SYNTAX       -5
#define BPM_NOT_CREATE       -6


#define BPM_MAX_SHIFT_SIZE   65536 /* 2^16 */
#define BPM_MAX_HASH_SIZE    65536 /* 2^16 */

typedef struct bpm_pattern  {
  int pidx, cidx;
  int sid;
  short len;
  char nocase, boolean;
  void *user;
  bpm_match_f match;
  unsigned char *pat; 
  unsigned char *org; 

  unsigned char *tokens; 
  ELEMENT  *postfix_stack;
} bpm_pat_t;

typedef int (*bpm_apply_f)(bpm_pat_t *pat, void *user);

typedef struct el_node
{
  ELEMENT  *element;
  struct el_node *next;
} el_node_t;

typedef struct bpm_node
{
  struct bpm_node *lo;
  struct bpm_node *eq;
  struct bpm_node *hi;

  unsigned char dchar;
  unsigned char check;

#define BPM_NEW_PATH  0 
#define BPM_END_PATH  1 
#define BPM_EQU_PATH  2
  unsigned short  path;

  el_node_t *dup;
} bpm_node_t;


typedef struct bpm {
  struct  obstack  pool;
  struct htab      *htab;

  int     slen;
  unsigned char    shift[BPM_MAX_SHIFT_SIZE];
  struct bpm_node *hash[BPM_MAX_HASH_SIZE];

  int (*search)(struct bpm *bpm, unsigned char *text, int len, void *user, bpm_match_f match); 

  MEM  *mem_stack;
  EVAL *eval_stack;
  ELEMENT  **match;
  int     mcount, ecount;
} bpm_t;


bpm_t *bpm_create (void);
void bpm_destroy (bpm_t *bpm);
int  bpm_add_pattern (bpm_t *bpm, unsigned char *pat, int plen, int nocase, int is_boolean, int cidx, void *data, bpm_match_f match);
int  bpm_add_auto_pattern (bpm_t *bpm, unsigned char *pattern, int plen, int nocase, int pidx, int cidx, void *user, bpm_match_f match);
int  bpm_add_pattern2 (bpm_t *bpm, unsigned char *pat, int plen, int nocase, int is_boolean, int pidx, int cidx, void *data, bpm_match_f match);
int  bpm_compile (bpm_t *bpm);

int  bpm_find (bpm_t *bpm, unsigned char *text, int len);
int  bpm_search (bpm_t *bpm, unsigned char *text, int len, void *user, bpm_match_f match);
xvector *bpm_lookup (bpm_t *bpm, unsigned char *text, int len);

int  bpm_apply (bpm_t *bpm, bpm_apply_f apply, void *user);
int  bpm_count (bpm_t *bpm);
int  bpm_element_count (bpm_t *bpm);

#endif /* __BPM_H__ */
