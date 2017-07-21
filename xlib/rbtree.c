
/*
** Red-black tree (symmetric binary B-trees)
**
** A red-black tree is a binary tree where each node has color as an extra
** attribute, either red or black. By constraining the coloring of the nodes it
** is ensured that the longest path from the root to a leaf is no longer than
** twice the length of the shortest path. This means that the tree is balanced.
** A red-black tree must satisfy these properties: 
** http://web.mit.edu/~emin/www/source_code/red_black_tree/index.html
**
** - The root is black 
** - All leaves are black. 
** - Red nodes can only have black children. 
** - All paths from a node to its leaves contain the same number of black nodes.
**
** 2003/02/21 HDS - add
** 2003/05/26 HDS - rbtree_lookup
** 2009/10/28 HDS - user para  (comp function)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "xalloc.h"
#include "rbtree.h"


/*
 * This is a "safe" test for the red-ness of a child which may be NULL; 
 * NULL is considered "black".
 */
#define IS_RED(node)        (((node) != NULL) && ((node)->is_red))

static void rotate_left (RBTree *t, RBTreeNode *x)
{
  RBTreeNode *y = x->right;

  if ((x->right = y->left))
    y->left->parent = x;

  if ((y->parent = x->parent)) {
    if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
  } else 
    t->root = y;

  y->left   = x;
  x->parent = y;
}

static void rotate_right (RBTree *t, RBTreeNode *x)
{
  RBTreeNode *y = x->left;

  if ((x->left = y->right))
    y->right->parent = x;

  if ((y->parent = x->parent)) {
    if (x == x->parent->right)
      x->parent->right = y;
    else
      x->parent->left = y;
  } else 
    t->root = y;

  y->right  = x;
  x->parent = y;
}

static void delete_fixup (RBTree *t, RBTreeNode *node, RBTreeNode *node_parent)
{
  RBTreeNode *w, *x, *x_parent;

  x = node;
  x_parent = node_parent;

  while ((x != t->root) && (!IS_RED(x))) {
    if (x == x_parent->left) {
      w = x_parent->right;
      if (w->is_red) {
        w->is_red = 0;
        x_parent->is_red = 1;
        rotate_left(t, x_parent);
        w = x_parent->right;
      }
      if (!IS_RED(w->left) && !IS_RED(w->right)) {
        w->is_red = 1;
        x = x_parent;
      } else {
        if (!IS_RED(w->right)) {
          w->left->is_red = 0;
          w->is_red = 1;
          rotate_right(t, w);
          w = x_parent->right;
        }
        w->is_red = x_parent->is_red;
        x_parent->is_red = 0;
        if (w->right)
          w->right->is_red = 0;
        rotate_left(t, x_parent);
        x = t->root;
      }
    } else {
      w = x_parent->left;
      if (w->is_red) {
        w->is_red = 0;
        x_parent->is_red = 1;
        rotate_right(t, x_parent);
        w = x_parent->left;
      }
      if (!IS_RED(w->right) && !IS_RED(w->left)) {
        w->is_red = 1;
        x = x_parent;
      } else {
        if (!IS_RED(w->left)) {
          w->right->is_red = 0;
          w->is_red = 1;
          rotate_left(t, w);
          w = x_parent->left;
        }
        w->is_red = x_parent->is_red;
        x_parent->is_red = 0;
        if (w->left)
          w->left->is_red = 0;
        rotate_right(t, x_parent);
        x = t->root;
      }
    }
    x_parent = x->parent;
  }
  if (x)
    x->is_red = 0;
}


RBTree *rbtree_create (rbt_comp_f compare, int dup, void *user)
{
  RBTree *rbt;

  rbt = xmalloc(sizeof(RBTree));
  rbt->compare = compare;
  rbt->user    = user;
  rbt->dup     = dup;
  rbt->count   = 0;
  rbt->root    = NULL;
  return rbt;
}

void rbtree_destroy (RBTree *rbt)
{
  xfree(rbt);
}

void rbtree_init (RBTree *rbt, rbt_comp_f compare, int dup, void *user)
{
  rbt->compare = compare;
  rbt->dup     = dup;
  rbt->user    = user;
  rbt->count   = 0;
  rbt->root    = NULL;
}

RBTreeNode *rbtree_search (RBTree *t, RBTreeNode *n)
{
  RBTreeNode *walk, *found = NULL;
  int stat = 0;

  walk = t->root;
  while (walk) {
    stat = t->compare(n, walk, t->user);
    if (stat == 0) {
      found = walk;
      break;
    } else if (stat < 0) {
      walk = walk->left;
    } else {
      walk = walk->right;
    }
  }
  return found;
}

RBTreeNode *rbtree_lookup (RBTree *t, RBTreeNode *n, int mode)
{
  RBTreeNode *lastwalk = NULL, *walk, *found = NULL;
  int stat = 0;
  
  walk = t->root;
  while (walk) {
    stat = t->compare(n, walk, t->user);
    if (stat == 0) {
      found = walk;
      break;
    } else if (stat < 0) {
      lastwalk = walk;
      walk = walk->left;
    } else {
      lastwalk = walk;
      walk = walk->right;
    }
  }

  if (found) {
    if (mode == RBTREE_GTEQ || mode == RBTREE_LTEQ) return(found);
    else
    if (mode == RBTREE_GREAT) return(rbtree_next(walk));
    else 
    if (mode == RBTREE_LESS) return(rbtree_prev(walk));
  }
  else {
    if (mode == RBTREE_GTEQ || mode == RBTREE_GREAT) {
      if (stat > 0) return(rbtree_next(lastwalk));
      else return(lastwalk);
    }

    if (mode == RBTREE_LTEQ || mode == RBTREE_LESS) {
      if (stat < 0) return(rbtree_prev(lastwalk));
      else return(lastwalk);
    }
  }
  return(NULL);
}


int rbtree_insert (RBTree *t, RBTreeNode *n)
{
  RBTreeNode *x, *y;
  int stat = 0;

  n->left = n->right = n->parent = NULL;

  x = t->root;
  y = NULL;
  while (x) {
    y = x;
    stat = t->compare(n, x, t->user);
    if ((stat == 0) && !t->dup) {
      return -1;
    } else if (stat < 0) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  n->parent = y;
  if (y == NULL)
    t->root = n;
  else if (stat < 0)
    y->left = n;
  else
    y->right = n;

  x = n;
  y = NULL;
  x->is_red = 1;
  while ((x != t->root) && (x->parent->is_red)) {
    if (x->parent == x->parent->parent->left) {
      y = x->parent->parent->right;
      if (IS_RED(y)) {
        x->parent->is_red = 0;
        y->is_red = 0;
        x->parent->parent->is_red = 1;
        x = x->parent->parent;
      } else {
        if (x == x->parent->right) {
          x = x->parent;
          rotate_left(t, x);
        }
        x->parent->is_red = 0;
        x->parent->parent->is_red = 1;
        rotate_right(t, x->parent->parent);
      }
    } else {
      y = x->parent->parent->left;
      if (IS_RED(y)) {
        x->parent->is_red = 0;
        y->is_red = 0;
        x->parent->parent->is_red = 1;
        x = x->parent->parent;
      } else {
        if (x == x->parent->left) {
          x = x->parent;
          rotate_right(t, x);
        }
        x->parent->is_red = 0;
        x->parent->parent->is_red = 1;
        rotate_left(t, x->parent->parent);
      }
    }
  }
  t->root->is_red = 0;

  t->count++;
  return 0;
}

int rbtree_remove (RBTree *t, RBTreeNode *node)
{
  RBTreeNode *x, *y, *z = node;

  if (!z->left || !z->right) y = z;
  else                       y = rbtree_next(z);

  if (y->left) x = y->left;
  else         x = y->right;

  if (x) x->parent = y->parent;

  if (!y->parent) t->root = x;
  else if (y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;

  if (!y->is_red) delete_fixup(t, x, y->parent);

  if (y != z) {
    y->left = z->left;
    if (y->left) y->left->parent = y;

    y->right = z->right;
    if (y->right) y->right->parent = y;

    y->parent = z->parent;
    if (!z->parent) t->root = y;
    else if (z->parent->left == z) y->parent->left = y;
    else y->parent->right = y;

    y->is_red = z->is_red;
  }
  t->count--;
  return 0;
}

RBTreeNode *rbtree_first (const RBTree *t)
{
  RBTreeNode *walk;

  walk = t->root;
  if (walk)
    while (walk->left) 
      walk = walk->left;

  return walk;
}

RBTreeNode *rbtree_last (const RBTree *t)
{
  RBTreeNode *walk;

  walk = t->root;
  if (walk)
    while (walk->right) 
      walk = walk->right;

  return walk;
}

RBTreeNode *rbtree_prev (const RBTreeNode *node)
{
  RBTreeNode *walk;

  if (node->left) {
    walk = node->left;
    while (walk->right) 
      walk = walk->right;
  } else {
    const RBTreeNode *walk2 = node;

    walk = walk2->parent;
    while (walk && (walk2 == walk->left)) {
      walk2 = walk;
      walk = walk->parent;
    }
  }
  return walk;
}

RBTreeNode *rbtree_next (const RBTreeNode *node)
{
  RBTreeNode *walk;

  if (node->right) {
    walk = node->right;
    while (walk->left) 
      walk = walk->left;
  } else {
    const RBTreeNode *walk2 = node;

    walk = walk2->parent;
    while (walk && (walk2 == walk->right)) {
      walk2 = walk;
      walk = walk->parent;
    }
  }
  return walk;
}

int rbtree_traverse (const RBTree *t, int (*func)(RBTreeNode *n, void *data), void *data)
{
  RBTreeNode *n;
  int count = 0;

  n = rbtree_first(t);
  while (n) {
    if (func(n, data)) break;
    count++;
    n = rbtree_next(n);
  }
  return(count);
}

