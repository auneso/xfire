#ifndef __HTST_H__
#define __HTST_H__

/*
** Hash Ternary Skip Search Trie (HDS)
*/

#include "obstack.h"
#include "rbtree.h"

#define HTST_MAX_SHIFT_SIZE   65536 /* 2^16 */
#define HTST_MAX_HASH_SIZE    65536 /* 2^16 */


typedef struct htst_pattern  {
  RBTreeNode rbtn; 

  int id, len;
  int flag;
#define HTST_CASE        0x0000
#define HTST_NOCASE      0x0001

#define HTST_F_WORD      0x0002
#define HTST_B_WORD      0x0004
#define HTST_WORD        0x0006

#define HTST_F_L_WORD    0x0010
#define HTST_F_L_B_WORD  0x0020
#define HTST_B_L_WORD    0x0040
#define HTST_B_L_F_WORD  0x0060
#define HTST_L_WORD      0x0080
#define HTST_FIRST_WORD  0x0100

#define HTST_MASK_WORD   0xFFFE
  void *user;

  unsigned char *pat; 
  unsigned char *org; 
} htst_pat_t;


typedef struct htst_node
{
  struct htst_node *lo;
  struct htst_node *eq;
  struct htst_node *hi;

  htst_pat_t *pat;
  unsigned short dchar;

#define HTST_NEW_PATH  0 
#define HTST_END_PATH  1 
#define HTST_EQU_PATH  2 
  unsigned short  path;
} htst_node_t;

#define HTST_CONTINUE_MATCH 0
#define HTST_STOP_MATCH     1
typedef int (*htst_match_f)(htst_pat_t *pat, unsigned char **pos, int len, void *user);
typedef int (*htst_apply_f)(htst_pat_t *pat, void *user);

typedef struct htst {
  struct  obstack  pool;
  RBTree  *root;

  unsigned short    minlen, maxlen;
  unsigned char     shift[HTST_MAX_SHIFT_SIZE];
  struct htst_node *hash[HTST_MAX_HASH_SIZE];

  int (*search)(struct htst *htst, unsigned char *text, int len, htst_match_f match, void *user); 
} htst_t;


htst_t *htst_create (void);
void htst_destroy (htst_t *htst);

int  htst_add_pattern (htst_t *htst, unsigned char *key, int len, int id, int flag, void *user);
void *htst_add_pattern2 (htst_t *htst, unsigned char *key, int len, int id, int flag, void *user);
void htst_compile (htst_t *htst);

int htst_search (htst_t *htst, unsigned char *text, int len, htst_match_f match, void *user);

int htst_apply (htst_t *htst, htst_apply_f apply, void *user);
int htst_count (htst_t *htst);

#endif 
