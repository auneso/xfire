/*
** "Splay trees", or "self-adjusting search trees" are a simple and
**  efficient data structure for storing an ordered set.  The data
**  structure consists of a binary tree, without parent pointers, and no
**  additional fields.  It allows searching, insertion, deletion,
**  deletemin, deletemax, splitting, joining, and many other operations,
**  all with amortized logarithmic performance.  Since the trees adapt to
**  the sequence of requests, their performance on real access patterns is
**  typically even better.  Splay trees are described in a number of texts
**  and papers [1,2,3,4,5].
*/
/*  The implementation used here is based on the implementation
 *  which was used in the tests of splay trees reported in:
 *
 *    An Empirical Comparison of Priority-Queue and Event-Set Implementations,
 *      by Douglas W. Jones, Comm. ACM 29, 4 (Apr. 1986) 300-311.
 *
 *  The changes made include the addition of the enqprior
 *  operation and the addition of up-links to allow for the splay
 *  operation.  The basic splay tree algorithms were originally
 *  presented in:
 *
 *      Self Adjusting Binary Trees,
 *        by D. D. Sleator and R. E. Tarjan,
 *           Proc. ACM SIGACT Symposium on Theory
 *             of Computing (Boston, Apr 1983) 235-245.
 *
 *  The enq and enqprior routines use variations on the
 *  top-down splay operation, while the splay routine is bottom-up.
 *  All are coded for speed.
 *
 *  Written by:
 *    Douglas W. Jones
 *
 *  Translated to C by:
 *    David Brower, daveb@rtech.uucp
 *
 * http://www.sbhatnagar.com/SourceCode
 * http://www.link.cs.cmu.edu/link/ftp-site/splaying/
 */

/*
** 2008/10/23 - HDS 
*/
#include <stdlib.h>
#include "spt.h"


/*----------------
 *
 *  splay() -- reorganize the tree.
 *
 *  the tree is reorganized so that n is the root of the
 *  splay tree representing q; results are unpredictable if n is not
 *  in q to start with; q is split from n up to the old root, with all
 *  nodes to the left of n ending up in the left subtree, and all nodes
 *  to the right of n ending up in the right subtree; the left branch of
 *  the right subtree and the right branch of the left subtree are
 *  shortened in the process
 *
 *  this code assumes that n is not NULL and is in q; it can sometimes
 *  detect n not in q and complain
 */

static void splay (spt_t **root, spt_t *n)
{
  spt_t *up;        /* points to the node being dealt with */
  spt_t *prev;      /* a descendent of up, already dealt with */
  spt_t *upup;      /* the parent of up */
  spt_t *upupup;    /* the grandparent of up */
  spt_t *left;      /* the top of left subtree being built */
  spt_t *right;     /* the top of right subtree being built */

  left  = n->leftlink;
  right = n->rightlink;
  prev  = n;
  up = prev->uplink;

  while (up != NULL) {

    /* walk up the tree towards the root, splaying all to the left of
     * n into the left subtree, all to right into the right subtree
     */

    upup = up->uplink;
    if (up->leftlink == prev) {       /* up is to the right of n */
      if (upup != NULL && upup->leftlink == up) { /* rotate */
        upupup = upup->uplink;
        upup->leftlink = up->rightlink;
        if (upup->leftlink != NULL)
          upup->leftlink->uplink = upup;
        up->rightlink = upup;
        upup->uplink = up;
        if (upupup == NULL)
          *root = up;
        else if (upupup->leftlink == upup)
          upupup->leftlink = up;
        else
          upupup->rightlink = up;
        up->uplink = upupup;
        upup = upupup;
      }
      up->leftlink = right;
      if (right != NULL)
        right->uplink = up;
      right = up;
    } else {                          /* up is to the left of n */
      if (upup != NULL && upup->rightlink == up) {  /* rotate */
        upupup = upup->uplink;
        upup->rightlink = up->leftlink;
        if (upup->rightlink != NULL)
          upup->rightlink->uplink = upup;
        up->leftlink = upup;
        upup->uplink = up;
        if (upupup == NULL)
          *root = up;
        else if (upupup->rightlink == upup)
          upupup->rightlink = up;
        else
          upupup->leftlink = up;
        up->uplink = upupup;
        upup = upupup;
      }
      up->rightlink = left;
      if (left != NULL)
        left->uplink = up;
      left = up;
    }
    prev = up;
    up = upup;
  }

  n->leftlink  = left;
  n->rightlink = right;
  if (left != NULL)
    left->uplink = n;
  if (right != NULL)
    right->uplink = n;
  *root = n;
  n->uplink = NULL;
}

/*----------------
 *
 *  spt_enqueue() -- insert item in a tree.
 *
 *  put n in q after all other nodes with the same key; when this is
 *  done, n will be the root of the splay tree representing q, all nodes
 *  in q with keys less than or equal to that of n will be in the
 *  left subtree, all with greater keys will be in the right subtree;
 *  the tree is split into these subtrees from the top down, with rotations
 *  performed along the way to shorten the left branch of the right subtree
 *  and the right branch of the left subtree
 */
void spt_enqueue (spt_t **root, spt_t *n)
{
  spt_t *left;    /* the rightmost node in the left tree */
  spt_t *right;   /* the leftmost node in the right tree */
  spt_t *next;    /* the root of the unsplit part */
  spt_t *temp;
  ub64 prio;

  n->uplink = n->leftlink = n->rightlink = NULL;

  next = *root;
  *root = n;
  if (next == NULL) { /* trivial enq */
    n->leftlink  = NULL;
    n->rightlink = NULL;
  }
  else {              /* difficult enq */
    prio  = n->prio;
    left  = n;
    right = n;

    /* n's left and right children will hold the right and left
     * splayed trees resulting from splitting on n->prio;
     * note that the children will be reversed!
     */

    if (next->prio > prio)
      goto two;

one:        /* assert next->prio <= prio */
    do {    /* walk to the right in the left tree */
      temp = next->rightlink;
      if (temp == NULL) {
        left->rightlink = next;
        next->uplink    = left;
        right->leftlink = NULL;
        goto done;        /* job done, entire tree split */
      }

      if (temp->prio > prio) {
        left->rightlink = next;
        next->uplink    = left;
        left = next;
        next = temp;
        goto two;        /* change sides */
      }

      next->rightlink = temp->leftlink;
      if (temp->leftlink != NULL)
        temp->leftlink->uplink = next;

      left->rightlink = temp;
      temp->uplink    = left;
      temp->leftlink  = next;
      next->uplink    = temp;
      left = temp;
      next = temp->rightlink;
      if (next == NULL) {
        right->leftlink = NULL;
        goto done;        /* job done, entire tree split */
      }
    } while (next->prio <= prio);        /* change sides */

two:           /* assert next->prio > prio */
    do {       /* walk to the left in the right tree */
      temp = next->leftlink;
      if (temp == NULL) {
        right->leftlink = next;
        next->uplink    = right;
        left->rightlink = NULL;
        goto done;        /* job done, entire tree split */
      }
      if (temp->prio <= prio) {
        right->leftlink = next;
        next->uplink    = right;
        right = next;
        next = temp;
        goto one;        /* change sides */
      }
      next->leftlink = temp->rightlink;
      if (temp->rightlink != NULL)
        temp->rightlink->uplink = next;

      right->leftlink = temp;
      temp->uplink    = right;
      temp->rightlink = next;
      next->uplink    = temp;
      right = temp;
      next = temp->leftlink;
      if (next == NULL) {
        left->rightlink = NULL;
        goto done;        /* job done, entire tree split */
      }
    } while (next->prio > prio);        /* change sides */

    goto one;

done:   /* split is done, branches of n need reversal */
    temp = n->leftlink;
    n->leftlink  = n->rightlink;
    n->rightlink = temp;
  }
}

/*----------------
 *
 *  spt_dequeue() -- return and remove head node from a subtree.
 *
 *  remove and return the head node from the node set; this deletes
 *  (and returns) the leftmost node from q, replacing it with its right
 *  subtree (if there is one); on the way to the leftmost node, rotations
 *  are performed to shorten the left branch of the tree
 */
spt_t *spt_dequeue (spt_t **root)
{
  spt_t *deq;        /* one to return */
  spt_t *next;       /* the next thing to deal with */
  spt_t *left;       /* the left child of next */
  spt_t *farleft;    /* the left child of left */
  spt_t *farfarleft; /* the left child of farleft */
  
  if (root == NULL || *root == NULL) {
    deq = NULL;
  }
  else {
    next = *root;
    left = next->leftlink;
    if (left == NULL) {
      deq = next;
      *root = next->rightlink;
          
      if (*root != NULL)
        (*root)->uplink = NULL;
    }
    else for (;;) {      /* left is not null */
      /* next is not it, left is not NULL, might be it */
      farleft = left->leftlink;
      if (farleft == NULL) {
        deq = left;
        next->leftlink = left->rightlink;
        if (left->rightlink != NULL)
          left->rightlink->uplink = next;
        break;
      }
          
      /* next, left are not it, farleft is not NULL, might be it */
      farfarleft = farleft->leftlink;
      if (farfarleft == NULL) {
        deq = farleft;
        left->leftlink = farleft->rightlink;
        if (farleft->rightlink != NULL)
          farleft->rightlink->uplink = left;
        break;
      }
          
      /* next, left, farleft are not it, rotate */
      next->leftlink  = farleft;
      farleft->uplink = next;
      left->leftlink  = farleft->rightlink;
      if (farleft->rightlink != NULL)
        farleft->rightlink->uplink = left;

      farleft->rightlink = left;
      left->uplink = farleft;
      next = farleft;
      left = farfarleft;
    }
  }
  return deq;
}

/*----------------
 *
 * spt_head() --  return the "lowest" element in the tree.
 *
 *      returns a reference to the head event in the event-set q,
 *      represented as a splay tree; q->root ends up pointing to the head
 *      event, and the old left branch of q is shortened, as if q had
 *      been splayed about the head element; this is done by dequeueing
 *      the head and then making the resulting queue the right son of
 *      the head returned by spdeq; an alternative is provided which
 *      avoids splaying but just searches for and returns a pointer to
 *      the bottom of the left branch
 */
spt_t *spt_head (spt_t **root)
{
  spt_t *x;

  /* splay version, good amortized bound */
  x =  spt_dequeue (root);
  if (x != NULL) {
    x->rightlink = *root;
    x->leftlink = NULL;
    x->uplink = NULL;
    if (*root)
      (*root)->uplink = x;
  }
  *root = x;

  /* alternative version, bad amortized bound,
    but faster on the average */
  return(x);
}


/*----------------
 *
 * spt_remove() -- Remove node from a tree.
 *
 *      n is remove from q; the resulting splay tree has been splayed
 *      around its new root, which is the successor of n
 *
 */
void spt_remove (spt_t **root, spt_t *n)
{
  spt_t *x;

  splay(root, n);
  x = spt_dequeue (&(*root)->rightlink);
  if (x == NULL) {              /* empty right subtree */
    *root = (*root)->leftlink;
    if (*root) (*root)->uplink = NULL;
  }
  else {                      /* non-empty right subtree */
    x->uplink = NULL;
    x->leftlink  = (*root)->leftlink;
    x->rightlink = (*root)->rightlink;
    if (x->leftlink != NULL)
      x->leftlink->uplink = x;
    if (x->rightlink != NULL)
      x->rightlink->uplink = x;
    *root = x;
  }
}


/*----------------
 *
 * spt_first() -- return the "lowest" element in the tree.
 *
 *      returns a reference to the head event in the event-set q.
 *      avoids splaying but just searches for and returns a pointer to
 *      the bottom of the left branch.
 */
spt_t *spt_first (spt_t *root)
{
  spt_t *walk;

  walk = root;
  if (walk)
    while (walk->leftlink)
      walk = walk->leftlink;

  return walk;
}

/*----------------
 *
 * spt_last() -- find the last node in a tree.
 *
 *      Fast version does not splay result or intermediate steps.
 */
spt_t *spt_last (spt_t *root)
{
  spt_t *walk;

  walk = root;
  if (walk)
    while (walk->rightlink)
      walk = walk->rightlink;

  return walk;
}


/*----------------
 *
 * spt_next() -- fast return next higer item in the tree, or NULL.
 *
 *      return the successor of n in q, represented as a splay tree.
 *      This is a fast (on average) version that does not splay.
 */
spt_t *spt_next (spt_t *node)
{
  spt_t *walk;

  if (node == NULL) return (node);

  if (node->rightlink) {
    walk = node->rightlink;
    while (walk->leftlink)
      walk = walk->leftlink;
  } else {  
    spt_t *walk2 = node;

    walk = walk2->uplink;
    while (walk && (walk2 == walk->rightlink)) {
      walk2 = walk;
      walk = walk->uplink;
    }
  }
  return walk;
}


/*----------------
 *
 * spt_prev() -- return fast previous node in a tree, or NULL.
 *
 *      return the predecessor of n in q, represented as a splay tree.
 *      This is a fast (on average) version that does not splay.
 */
spt_t *spt_prev (spt_t *node)
{
  spt_t *walk;

  if (node == NULL) return (node);

  if (node->leftlink) {
    walk = node->leftlink;
    while (walk->rightlink)
      walk = walk->rightlink;
  } else {
    spt_t *walk2 = node;

    walk = walk2->uplink;
    while (walk && (walk2 == walk->leftlink)) {
      walk2 = walk;
      walk = walk->uplink;
    }
  }
  return walk;
}
