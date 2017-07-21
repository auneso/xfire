#ifndef __XIPTREE_H__
#define __XIPTREE_H__

#include "xtypes.h"
#include "xrbt.h"
#include "xfmem.h"
#include "rbtree.h"
#include "xipmap.h"


typedef struct _Xiptnode
{
  RBTreeNode node;
  xnetspec ns;
  void  *user;
} Xiptnode;

typedef struct _Xiptree
{
  RBTree  *root;
  xfmem_t *mem;
  ub32 ip_count;
} Xiptree;


Xiptree *xiptree_create (void);
void    xiptree_destroy (Xiptree *xit);
ub32    xiptree_insert_ip (Xiptree *xit, ub32 start_ip, ub32 end_ip, void *user);
ub32    xiptree_insert_cmd (Xiptree *xit, const char *cmd, void *user);
int     xiptree_remove_ip (Xiptree *xit, ub32 start_ip, ub32 end_ip);
int     xiptree_check_cmd (Xiptree *xit, const char *cmd);
int     xiptree_valid_cmd (const char *cmd);
int     xiptree_search (Xiptree *xit, unsigned int ip);
int     xiptree_table_count (Xiptree *xit);
int     xiptree_ip_count (Xiptree *xit);
void   *xiptree_lookup (Xiptree *xit, unsigned int ip);

int xiptree_dump (Xiptree *xit);

XRBTR32 *xiptree_make_table (const char *cmd);

#endif

