/*
** An Aggregation-based Traffic Profiler
*/

/*
** 2009/12/09 - HDS
*/

#include <sys/param.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <err.h>

#include "xalloc.h"
#include "atp.h"

static struct atp_node *leaf_alloc(struct atp *tp, const void *key, struct atp_node *np);
static void leaf_free(struct atp *tp, struct atp_node *leaf);
static void leaf_reclaim(struct atp *tp, int n);

static void tnode_reset(struct atp_node *np);
static int tnode_resetcount(struct atp_node *np, void *arg);
static int tnode_sum(struct atp_node *np, void *arg);
static struct atp_node *tnode_find(struct atp *tp, const void *key, size_t len);
static int tnode_aggregate(struct atp_node *np, void *arg);

/*
 * return the bit value at the specified position
 */
static unsigned char bitpos[8] =
  { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };

static int bit_test (const void *p, size_t pos)
{
  const unsigned char *cp;
  size_t off;

  cp = p;
  off = (pos - 1) / 8;
  return (cp[off] & bitpos[(pos - 1) & 7]);
}

static void bit_set (void *p, size_t pos)
{
  unsigned char *cp;
  size_t off;

  cp = p;
  off = (pos - 1) / 8;
  cp[off] |= bitpos[(pos - 1) & 7];
}

static unsigned char prefixmask[8] =
  { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe };

/*
 * compare prefixes of p1 and p2
 */
static int prefix_cmp (const void *p1, const void *p2, size_t len)
{
  const unsigned char *c1, *c2;
  unsigned char mask;
  size_t bytes, bits;

  if (len == 0)
    return (0);

  c1 = p1;
  c2 = p2;
  bytes = len / 8;
  bits = len & 7;

  while (bytes-- != 0)
    if (*c1++ != *c2++)
      return (*--c1 - *--c2);
  if ((mask = prefixmask[bits]) == 0)
    return (0);
  return ((*c1 & mask) - (*c2 & mask));
}

/*
 * extract a common prefix from p1 and p2 to p3, return the common prefixlen
 */
static size_t
prefix_common (const void *p1, const void *p2, size_t len, void *p3)
{
  const unsigned char *c1, *c2, *end;
  unsigned char val, *c3;
  size_t bytes, bits, n;

  c1 = p1;
  c2 = p2;
  c3 = p3;
  end = p3 + ((len + 7) / 8);
  n = 0;
  bytes = len / 8;
  bits = len & 7;

  while (bytes-- != 0) {
    if (*c1 != *c2) {
      bits = 7; /* at most 7 bits can be common */
      break;
    }
    *c3++ = *c1++;
    c2++;
    n += 8;
  }
  if (bits != 0) {
    val = *c1 ^ *c2;
    do {
      if (val & 0x80)
        break;
      n++;
      val <<= 1;
    } while (--bits != 0);
    *c3++ = *c1 & prefixmask[n & 7];
  }
  /* clear the remaining bytes */
  while (c3 < end)
    *c3++ = 0;
  return (n);
}

static int key_print (u_char *key, size_t len, size_t prefixlen)
{
  int i;

  printf("0x");
  for (i = 0; i < len/8; i++)
    printf("%02x", key[i]);
  printf("/%u", (u_int)prefixlen);
  return (0);
}

static int tnode_print (struct atp_node *np, void *arg)
{
  int i;

  for (i = 0; i < np->tn_depth; i++)
    printf(" ");
  key_print(np->tn_key, np->tn_atp->tr_keylen, np->tn_prefixlen);
  printf(": %llu (%.2f%%)\n",
         (ull)np->tn_count,
         (double)np->tn_count/np->tn_atp->tr_count*100);
  return (0);
}



/*
 * radix (or patricia) atp implementation for aguri
 */

/*
 * initialize a atp.
 * the lru list contains free nodes and leaf nodes, but not internal nodes.
 */
void
atp_atp_init (struct atp *tp, size_t keylen, size_t maxnodes)
{
  struct atp_node *np;
  int i;

  tp->tr_keylen = keylen;
  TAILQ_INIT(&tp->tr_lru);

  for (i = 0; i < maxnodes; i++) {
    np = xmalloc(sizeof(*np));
    TAILQ_INSERT_TAIL(&tp->tr_lru, np, tn_chain);
    tnode_reset(np);
    np->tn_atp = tp;
    np->tn_inatp = 0;
    tp->tr_nfree++;
  }

  /* allocate the top node */
  np = TAILQ_FIRST(&tp->tr_lru);
  tnode_reset(np);
  memset(&np->tn_key, 0, sizeof(np->tn_key));
  np->tn_prefixlen = 0;
  tp->tr_top = np;
  np->tn_inatp = 1;
  tp->tr_nfree--;
  TAILQ_REMOVE(&tp->tr_lru, np, tn_chain);
}

void
atp_destroy (struct atp *tp)
{
  struct atp_node *np;

  /* first, remove nodes from the atp */
  if (tp->tr_top->tn_left != NULL)
    atp_sub_reduce(tp, tp->tr_top, 0);

  /*
   * at this point, only top is remaining in the atp,
   * and all nodes are in the LRU list.
   */
  assert(tp->tr_top->tn_left == NULL && tp->tr_top->tn_right == NULL);
  while ((np = TAILQ_FIRST(&tp->tr_lru)) != NULL) {
    TAILQ_REMOVE(&tp->tr_lru, np, tn_chain);
    xfree(np);
  }

  tp->tr_top = NULL;
  tp->tr_nfree = 0;
}

/*
 * preorder atp walk
 */
int
atp_walk (struct atp *tp, int (*func)(struct atp_node *, void *), void *arg)
{
  return (atp_sub_walk(tp->tr_top, func, arg));
}

/*
 * postorder atp walk
 */
int
atp_postorderwalk (struct atp *tp, int (*func)(struct atp_node *, void *), void *arg)
{
  return (atp_sub_postorderwalk(tp->tr_top, func, arg));
}

void
atp_resetcount (struct atp *tp)
{
  atp_walk(tp, tnode_resetcount, 0);
  tp->tr_count = 0;
#ifdef AGURI_STATS
  tp->tr_stats.hits = 0;
  tp->tr_stats.total = 0;
#endif
}

int
atp_aggregate (struct atp *tp, u_int64_t thresh)
{
  u_int64_t arg;

  arg = thresh;
  atp_postorderwalk(tp, tnode_aggregate, (void *)&arg);
  return (0);
}

void
atp_print (struct atp *tp)
{
  atp_walk(tp, tnode_print, 0);
}

/*
 * preorder atp walk
 */
int
atp_sub_walk (struct atp_node *top, int (*func)(struct atp_node *, void *), void *arg)
{
  struct atp_node *np;
  int error, depth;

  depth = 0;
  np = top;
  while (1) {

    assert((np->tn_left == NULL && np->tn_right == NULL)
        || (np->tn_left != NULL && np->tn_right != NULL));

    np->tn_depth = depth;
    if ((error = (*func)(np, arg)) != 0)
      return (error);

    if (np->tn_left != NULL) {
      np = np->tn_left;
      depth++;
    } else {
      while (np != top &&
             np == np->tn_parent->tn_right) {
        np = np->tn_parent;
        depth--;
      }
      if (np == top)
        break;
      np = np->tn_parent->tn_right;
    }
  }
  return (0);
}

/*
 * postorder atp walk
 */
int
atp_sub_postorderwalk (struct atp_node *top, int (*func)(struct atp_node *, void *), void *arg)
{
  struct atp_node *np;
  int error, depth;

  depth = 0;
  np = top;
  while (np->tn_left != NULL) {
    np = np->tn_left;
    depth++;
  }
  while (1) {
    np->tn_depth = depth;
    if ((error = (*func)(np, arg)) != 0)
      return (error);

    if (np == top)
      break;

    /*
     * move on to the next node
     */
    if (np == np->tn_parent->tn_right) {
      /* at right child, go up */
      np = np->tn_parent;
      depth--;
    } else {
      /*
       * at left child. move to its sibling, then
       * go down to the left most child.
       */
      np = np->tn_parent->tn_right;
      while (np->tn_left != NULL) {
        np = np->tn_left;
        depth++;
      }
    }
  }
  return (0);
}

u_int64_t
atp_sub_sum (struct atp_node *np)
{
  u_int64_t cnt = 0;

  atp_sub_walk(np, tnode_sum, &cnt);
  return (cnt);
}

/*
 * reduce a sub atp into a single leaf node
 */
void
atp_sub_reduce (struct atp *tp, struct atp_node *np, int depth)
{
  if (depth > 0) {
    /* nodes to be deleted */
    if (np->tn_left == NULL) {
      /* leaf node */
      assert(np->tn_right == NULL);
      TAILQ_REMOVE(&tp->tr_lru, np, tn_chain);
    } else {
      /* internal node */
      assert(np->tn_right != NULL);
      atp_sub_reduce(tp, np->tn_left, depth + 1);
      atp_sub_reduce(tp, np->tn_right, depth + 1);
    }

    np->tn_parent->tn_count += np->tn_count;
    if (np->tn_parent->tn_left == np)
      np->tn_parent->tn_left = NULL;
    else
      np->tn_parent->tn_right = NULL;
    np->tn_inatp = 0;
    TAILQ_INSERT_TAIL(&tp->tr_lru, np, tn_chain);
    tp->tr_nfree++;
#ifdef AGURI_STATS
    tp->tr_stats.reclaimed++;
#endif
    return;
  }

  /* remaining node, converted from an internal node to a leaf */
  assert(np->tn_left != NULL && np->tn_right != NULL);
  atp_sub_reduce(tp, np->tn_left, depth + 1);
  atp_sub_reduce(tp, np->tn_right, depth + 1);
  assert(np->tn_left == NULL && np->tn_right == NULL);
  TAILQ_INSERT_HEAD(&tp->tr_lru, np, tn_chain);
}

/*
 * creat a leaf node and its branch point.
 * then, insert the branch point as the parent of the specified node.
 */
static struct atp_node *
leaf_alloc (struct atp *tp, const void *key, struct atp_node *np)
{
  struct atp_node *bp, *leaf;

  /* reclaim two nodes from the LRU list */
  leaf = TAILQ_LAST(&tp->tr_lru, _lru);
  while (leaf->tn_inatp)
    leaf = TAILQ_PREV(leaf, _lru, tn_chain);
  TAILQ_REMOVE(&tp->tr_lru, leaf, tn_chain);
  TAILQ_INSERT_HEAD(&tp->tr_lru, leaf, tn_chain);
  leaf->tn_inatp = 1;
  tp->tr_nfree--;
  tnode_reset(leaf);
  memcpy(leaf->tn_key, key, tp->tr_keylen/8);
  leaf->tn_prefixlen = tp->tr_keylen;

  assert(tp->tr_nfree > 0);
  bp = TAILQ_LAST(&tp->tr_lru, _lru);
  while (bp->tn_inatp)
    bp = TAILQ_PREV(bp, _lru, tn_chain);
  TAILQ_REMOVE(&tp->tr_lru, bp, tn_chain);
  bp->tn_inatp = 1;
  tp->tr_nfree--;
  tnode_reset(bp);
  bp->tn_prefixlen =
      prefix_common(np->tn_key, key, tp->tr_keylen, bp->tn_key);

  if (bp->tn_prefixlen >= np->tn_prefixlen) {
    /*
     * leaf should be a child of np
     */
    assert(np->tn_left == NULL && np->tn_right == NULL);
    TAILQ_REMOVE(&tp->tr_lru, np, tn_chain);
    TAILQ_INSERT_HEAD(&tp->tr_lru, bp, tn_chain);
    if (bp->tn_prefixlen != np->tn_prefixlen) {
      bit_set(bp->tn_key, np->tn_prefixlen + 1);
      np->tn_left = leaf;
      np->tn_right = bp;
    } else {
      np->tn_left = bp;
      np->tn_right = leaf;
    }
    bp->tn_parent = np;
    leaf->tn_parent = np;
    return (leaf);
  }

  if (np->tn_parent->tn_left == np)
    np->tn_parent->tn_left = bp;
  else
    np->tn_parent->tn_right = bp;
  bp->tn_parent = np->tn_parent;
  if (bit_test(key, bp->tn_prefixlen + 1)) {
    bp->tn_left = np;
    bp->tn_right = leaf;
  } else {
    bp->tn_left = leaf;
    bp->tn_right = np;
  }
  np->tn_parent = bp;
  leaf->tn_parent = bp;

  return (leaf);
}

static void
leaf_free (struct atp *tp, struct atp_node *leaf)
{
  struct atp_node *bp, *np, *parent;

  assert(leaf->tn_inatp);
  assert(leaf->tn_left == NULL && leaf->tn_right == NULL);
  bp = leaf->tn_parent;
  assert(bp->tn_left != NULL && bp->tn_right != NULL);
  parent = bp->tn_parent;
  assert(parent != NULL);


  /*
   * aggregate the counter values of the nodes to be deleted
   * into their parent node
   */
  parent->tn_count += bp->tn_count + leaf->tn_count;

  if (bp->tn_left == leaf)
    np = bp->tn_right;
  else
    np = bp->tn_left;
  if (parent->tn_left == bp)
    parent->tn_left = np;
  else
    parent->tn_right = np;
  np->tn_parent = parent;

  leaf->tn_inatp = 0;
  bp->tn_inatp = 0;
  TAILQ_REMOVE(&tp->tr_lru, leaf, tn_chain);
  TAILQ_INSERT_TAIL(&tp->tr_lru, leaf, tn_chain);
  TAILQ_INSERT_TAIL(&tp->tr_lru, bp, tn_chain);
  tp->tr_nfree += 2;
#ifdef AGURI_STATS
  tp->tr_stats.reclaimed += 2;
#endif
}

/*
 * reclaim leaf nodes using the LRU replacement algorithm.
 * we don't select a node as a possible victim if the node is
 *  - already reclaimed
 *  - the counter value is larger than the threshold
 *  - both of its parent and sibling's subatp are larger than the threshold
 * then, we compare parent's count with sibling's subatp sum.
 * - if parent is larger, reduce the subatp into parent.
 * - otherwise, reclaim this node and parent, and leave the sibling's subatp.
 */
static void
leaf_reclaim (struct atp *tp, int n)
{
  struct atp_node *np, *after, *parent, *sibling;
  u_int64_t thresh, sum, moved_to_head;

  thresh = tp->tr_count / 64;
  if (thresh == 0)
    thresh = 1;
  while (tp->tr_nfree < n) {
    /*
     * select a victim from the LRU list.
     * exclude nodes whose count is more than the threshold.
     */
    moved_to_head = 0;
    np = TAILQ_LAST(&tp->tr_lru, _lru);
    while (np != NULL) {
      if (np->tn_inatp == 0) {
        /* free node */
        np =  TAILQ_PREV(np, _lru, tn_chain);
        continue;
      } else if (np->tn_count > thresh) {
        /* if bigger than thresh, move it to head */
        after = np;
        np = TAILQ_PREV(np, _lru, tn_chain);
        if (moved_to_head > 3)
          continue;
        TAILQ_REMOVE(&tp->tr_lru, after, tn_chain);
        TAILQ_INSERT_HEAD(&tp->tr_lru, after, tn_chain);
        moved_to_head++;
        continue;
      }
      /*
       * a possible victim found.
       * see if either its parent or sibling's subatp is
       * smaller than the threshold.
       * also check if parent is not the top node.
       */
      parent = np->tn_parent;
      if (parent->tn_left == np)
        sibling = parent->tn_right;
      else
        sibling = parent->tn_left;
      sum = atp_sub_sum(sibling);
      if (sum > thresh && (parent->tn_count > thresh || parent == tp->tr_top)) {
        after = np;
        np =  TAILQ_PREV(np, _lru, tn_chain);
        if (moved_to_head > 3)
          continue;
        TAILQ_REMOVE(&tp->tr_lru, after, tn_chain);
        TAILQ_INSERT_HEAD(&tp->tr_lru, after, tn_chain);
        moved_to_head++;
        continue;
      }

      /*
       * at this point, we are about to reclaim this victim.
       * compare parent's count with sibling's subatp sum.
       * if parent is larger, reduce the subatp into parent.
       * otherwise, reclaim this node and parent, and leave
       * sibling.
       */
      if (parent->tn_count > sum || parent == tp->tr_top)
        atp_sub_reduce(tp, np->tn_parent, 0);
      else
        leaf_free(tp, np);
      break;
    }

    if (np == NULL) {
      thresh *= 2;
#if 0
      fprintf(stderr, "thresh increased to %llu\n", thresh);
#endif
    }
  }
}

void
atp_leaf_addcount (struct atp *tp, const void *key, u_int64_t cnt)
{
  (void)atp_node_addcount(tp, key, tp->tr_keylen, cnt);
}

struct atp_node *
atp_node_addcount (struct atp *tp, const void *key, size_t len, u_int64_t cnt)
{
  struct atp_node *np;

#ifdef AGURI_STATS
  tp->tr_stats.total++;
#endif
  np = tnode_find(tp, key, len);

  np->tn_count += cnt;
  tp->tr_count += cnt;

  /* if this is a leaf, place this node at the head of the LRU list */
  if (np->tn_left == NULL)
    if (np != TAILQ_FIRST(&tp->tr_lru)) {
      TAILQ_REMOVE(&tp->tr_lru, np, tn_chain);
      TAILQ_INSERT_HEAD(&tp->tr_lru, np, tn_chain);
    }
  return (np);
}

static void
tnode_reset (struct atp_node *np)
{
  np->tn_parent = np->tn_left = np->tn_right = NULL;
  np->tn_count = 0;
  np->tn_prefixlen = 0;
}

static int
tnode_resetcount (struct atp_node *np, void *arg)
{
  np->tn_count = 0;
  return (0);
}

static int
tnode_sum (struct atp_node *np, void *arg)
{
  u_int64_t *p = arg;

  *p += np->tn_count;
  return (0);
}

static struct atp_node *
tnode_find (struct atp *tp, const void *key, size_t len)
{
  struct atp_node *np;
  int needfree;

  /*
   * before starting a search, make sure at least two free nodes
   * are available at the tail of the LRU list, since two nodes
   * are required to allocate a new leaf during the search.
   * for an internal node, we may need 4 free nodes.
   */
  if (len == tp->tr_keylen)
    needfree = 2;  /* leaf node */
  else
    needfree = 4;  /* internal node */
  if (tp->tr_nfree < needfree)
    leaf_reclaim(tp, needfree);

  np = tp->tr_top;
  while (1) {
    if (len < np->tn_prefixlen) {
      /*
       * a special case for looking for a non-existent
       * internal node.  we need to create dummy
       * leaves to make this branch point.
       *  first case: np is a child of the target
       *    create a dummy leaf to make the target
       *  second case: np isn't a child of the target
       *    we need 4 nodes.  first create
       *    a branch point by the target key with full
       *    prefixlen.  then, go on to the first case.
       */
      u_char  leafkey[MAX_KEYBYTES];

      memcpy(leafkey, key, tp->tr_keylen/8);
      if (prefix_cmp(np->tn_key, key, len) == 0) {
        if (bit_test(np->tn_key, len + 1) == 0)
          bit_set(leafkey, len + 1);
        (void)leaf_alloc(tp, leafkey, np);
        assert(len == np->tn_parent->tn_prefixlen);
        assert(prefix_cmp(np->tn_parent->tn_key, key, len) == 0);
        return (np->tn_parent);
      } else {
        np = leaf_alloc(tp, leafkey, np);
        continue;
      }
    }

    if (prefix_cmp(np->tn_key, key, np->tn_prefixlen) != 0) {
      /*
       * the prefix doesn't match, we need to
       * insert new nodes here
       */
      np = leaf_alloc(tp, key, np);
      if (len != tp->tr_keylen)
        continue;
      return (np);
    }

    /*
     * the prefix matched.
     * if len is equal to the prefixlen, we have a match.
     * otherwise, we have to go down the atp.
     * since the node holds the common prefix of the
     * two children, the bit value at prefixlen + 1
     * shows which way to take.
     */
    if (len == np->tn_prefixlen) {
#ifdef AGURI_STATS
      tp->tr_stats.hits++;
#endif
      return (np);
    }

    /* if np has no child, create 2 leaves */
    if (np->tn_right == NULL) {
      np = leaf_alloc(tp, key, np);
      if (len != tp->tr_keylen)
        continue;
      return (np);
    }

    if (bit_test(key, np->tn_prefixlen + 1))
      np = np->tn_right;
    else
      np = np->tn_left;
  }
  /* NOTREACHED */
}

static int
tnode_aggregate (struct atp_node *np, void *arg)
{
  u_int64_t thresh = *(u_int64_t *)arg;

  /* if count is less than thresh, aggregate */
  if (np->tn_parent != NULL && np->tn_count < thresh) {
    np->tn_parent->tn_count += np->tn_count;
    np->tn_count = 0;
  } else {
#if 0  /* use another atp_walk to clear counter for now */
    /*
     * we are done with this node.
     * clear the count for the next round.
     */
    np->tn_count = 0;
#endif
  }
  return (0);
}




