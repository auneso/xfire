#ifndef __XIPMAP_H__
#define __XIPMAP_H__

#include "xtypes.h"
#include "xfmem.h"
#include "xvector.h"
#include "rbtree.h"

/*
  Specifies a network. Whether originally in CIDR format (IP/mask)
  or a range of IPs (IP_start-IP_end), spec is converted to a range.
  The range is min to max (32-bit IPs) inclusive.
*/
typedef struct _xnetspec
{
  unsigned int min;
  unsigned int max;
} xnetspec;


typedef struct _Xipnode
{
  RBTreeNode node;
  xnetspec ns;
  xvector *xvec;
} Xipnode;

typedef struct _Xipmap
{
  RBTree  *root;
  xfmem_t *mem;
} Xipmap;

Xipmap *xipmap_create (void);
void    xipmap_destroy (Xipmap *map);
void    xipmap_insert (Xipmap *map, xnetspec *ns, void *user);
ub32     xipmap_insert_ip (Xipmap *map, ub32 start_ip, ub32 end_ip, void *user);
ub32    xipmap_insert_cmd (Xipmap *map, const char *cmd, void *user);
int     xipmap_search (Xipmap *map, unsigned int ip);
xvector *xipmap_lookup (Xipmap *map, unsigned int ip);
xvector *xipmap_check_cmd (Xipmap *map, const char *cmd);
ub32 xipmap_count (Xipmap *map);

Xipnode *xipmap_first (Xipmap *map);
Xipnode *xipmap_next (Xipnode *xip);

int xipmap_dump (Xipmap *map);

#endif

