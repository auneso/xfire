/*
 * Red-black tree ADT
 *
 * Copyright (c) 2001 Jeff Brown
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Absolutely no warranty of function or purpose is made by the author.
 *
 * $Id: rbtree.h,v 1.9 2002/04/19 18:19:59 jabrown Exp $
 */

#ifndef __RBTREE_H__
#define __RBTREE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RBTree RBTree;
typedef struct RBTreeNode RBTreeNode;

typedef int (*rbt_comp_f)(void *, void *, void *);


#define RBTREE_DUP_KEY  1

struct RBTreeNode {
  RBTreeNode *left, *right, *parent;
  unsigned is_red;
};

struct RBTree {
  RBTreeNode *root;
  rbt_comp_f compare;
  unsigned long count;
  int dup; 
  void *user;
};


RBTree *rbtree_create (rbt_comp_f, int dup, void *user);
void    rbtree_destroy (RBTree *t);

void rbtree_init (RBTree *rbt, rbt_comp_f compare, int dup, void *user);

RBTreeNode *rbtree_search (RBTree *t,  RBTreeNode *rbtn);

/* Modes for rbtree_lookup */
#define RBTREE_GTEQ  1    /* Exact match or greater */
#define RBTREE_LTEQ  2    /* Exact match or less */
#define RBTREE_LESS  3    /* Less than key (not equal to) */
#define RBTREE_GREAT 4    /* Greater than key (not equal to) */

RBTreeNode *rbtree_lookup (RBTree *t,  RBTreeNode *rbtn, int mode);
int rbtree_insert (RBTree *t, RBTreeNode *rbtn);
int rbtree_remove (RBTree *t, RBTreeNode *rbtn); 

RBTreeNode *rbtree_first(const RBTree *t);
RBTreeNode *rbtree_last(const RBTree *t);

RBTreeNode *rbtree_prev(const RBTreeNode *rbtn);
RBTreeNode *rbtree_next(const RBTreeNode *rbtn);

#define rbtree_count(t) ((const unsigned long) (t)->count)

int rbtree_traverse (const RBTree *t, int (*func)(RBTreeNode *n, void *data), void *data);


#ifdef __cplusplus
}
#endif

#endif  /* RBTREE_H */
