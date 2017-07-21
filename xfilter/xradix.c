/*
 * author Anoop Saldanha <poonaatsoc@gmail.com>
 * Implementation of radix trees
 */
/*
** 2010/09/04 - HDS
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "xalloc.h"
#include "xstring.h"
#include "xradix.h"

struct in_addr *RadixValidateIPV4Address (const char *addr_str)
{
  struct in_addr *addr;

  addr = xmalloc(sizeof(struct in_addr));
  if (inet_pton(AF_INET, addr_str, addr) <= 0) {
    xfree(addr);
    return NULL;
  }
  return addr;
}

struct in6_addr *RadixValidateIPV6Address (const char *addr_str)
{
  struct in6_addr *addr;

  addr = xmalloc(sizeof(struct in6_addr));
  if (inet_pton(AF_INET6, addr_str, addr) <= 0) {
    xfree(addr);
    return NULL;
  }
  return addr;
}

void RadixChopIPAddressAgainstNetmask (uint8_t *stream, uint8_t netmask, uint16_t key_bitlen)
{
  int mask = 0;
  int i = 0;
  int bytes = key_bitlen / 8;

  for (i = 0; i < bytes; i++) {
    mask = -1;
    if ( ((i + 1) * 8) > netmask) {
      if ( ((i + 1) * 8 - netmask) < 8)
        mask = -1 << ((i + 1) * 8 - netmask);
      else
        mask = 0;
    }
    stream[i] &= mask;
  }
}

static RadixUserData *RadixAllocRadixUserData (uint8_t netmask, void *user)
{
  RadixUserData *user_data = xzalloc(sizeof(RadixUserData));

  user_data->netmask = netmask;
  user_data->user = user;

  return user_data;
}

static void RadixDeAllocRadixUserData (RadixUserData *user_data)
{
  xfree(user_data);
}

static void RadixAppendToRadixUserDataList (RadixUserData *new, RadixUserData **list)
{
  RadixUserData *temp = NULL;
  RadixUserData *prev = NULL;

  /* add to the list in descending order.  The reason we do this is for
   * optimizing key retrieval for a ip key under a netblock */
  prev = temp = *list;
  while (temp != NULL) {
    if (new->netmask > temp->netmask)
      break;
    prev = temp;
    temp = temp->next;
  }

  if (temp == *list) {
    new->next = *list;
    *list = new;
  } else {
    new->next = prev->next;
    prev->next = new;
  }
}

static RadixPrefix *RadixCreatePrefix (uint8_t *key_stream, uint16_t key_bitlen, void *user, uint8_t netmask)
{
  RadixPrefix *prefix = NULL;

  if ((key_bitlen % 8 != 0)) return NULL;

  if (key_stream == NULL) return NULL;

  prefix = xzalloc(sizeof(RadixPrefix));
  prefix->stream = xzalloc(key_bitlen / 8);

  memcpy(prefix->stream, key_stream, key_bitlen / 8);
  prefix->bitlen = key_bitlen;
  prefix->user_data = RadixAllocRadixUserData(netmask, user);

  return prefix;
}

static void RadixAddNetmaskUserDataToPrefix (RadixPrefix *prefix, uint8_t netmask, void *user)
{
  RadixAppendToRadixUserDataList(RadixAllocRadixUserData(netmask, user), &prefix->user_data);
}

static void RadixRemoveNetmaskUserDataFromPrefix (RadixPrefix *prefix, uint8_t netmask)
{
  RadixUserData *temp = NULL, *prev = NULL;

  prev = temp = prefix->user_data;
  while (temp != NULL) {
    if (temp->netmask == netmask) {
      if (temp == prefix->user_data)
        prefix->user_data = temp->next;
      else
        prev->next = temp->next;

      RadixDeAllocRadixUserData(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
}

static int RadixPrefixContainNetmask (RadixPrefix *prefix, uint8_t netmask)
{
  RadixUserData *user_data;

  user_data = prefix->user_data;
  while (user_data != NULL) {
    if (user_data->netmask == netmask)
      return 1;
    user_data = user_data->next;
  }
  return 0;
}

static int RadixPrefixNetmaskCount (RadixPrefix *prefix)
{
  RadixUserData *user_data;
  uint32_t count = 0;

  user_data = prefix->user_data;
  while (user_data != NULL) {
    count++;
    user_data = user_data->next;
  }
  return count;
}

static int RadixPrefixContainNetmaskAndSetUserData (RadixPrefix *prefix, uint16_t netmask, int exact_match)
{
  RadixUserData *user_data;

  user_data = prefix->user_data;
  /* Check if we have a match for an exact ip.  An exact ip as in not a proper
   * netblock, i.e. an ip with a netmask of 32(ipv4) or 128(ipv6) */
  if (exact_match) {
    if (user_data->netmask == netmask) {
      prefix->user_data_result = user_data->user;
      return 1;
    } else {
      goto no_match;
    }
  }

  /* Check for the user_data entry for this netmask_value */
  while (user_data != NULL) {
    if (user_data->netmask == netmask) {
      prefix->user_data_result = user_data->user;
      return 1;
    }
    user_data = user_data->next;
  }

no_match:
  return 0;
}

static void RadixReleasePrefix (RadixPrefix *prefix, RadixTree *tree)
{
  RadixUserData *user_data_temp1 = NULL;
  RadixUserData *user_data_temp2 = NULL;

  if (prefix != NULL) {
    if (prefix->stream != NULL)
      xfree(prefix->stream);

    user_data_temp1 = prefix->user_data;
    user_data_temp2 = user_data_temp1;
    if (tree->Free != NULL) {
      while (user_data_temp1 != NULL) {
        user_data_temp2 = user_data_temp1;
        user_data_temp1 = user_data_temp1->next;
        tree->Free(user_data_temp2->user);
        RadixDeAllocRadixUserData(user_data_temp2);
      }
    } else if (user_data_temp1 != NULL) {
      xfree(user_data_temp1);
    }
    xfree(prefix);
  }
}

static inline RadixNode *RadixCreateNode ()
{
  return (RadixNode *)xzalloc(sizeof(RadixNode));
}

static void RadixReleaseNode (RadixNode *node, RadixTree *tree)
{
  if (node != NULL) {
    RadixReleasePrefix(node->prefix, tree);

    if (node->netmasks != NULL)
      xfree(node->netmasks);

    xfree(node);
  }
}

RadixTree *RadixCreateRadixTree (void (*Free)(void*), void (*PrintData)(void*))
{
  RadixTree *tree;

  tree = xzalloc(sizeof(RadixTree));
  tree->Free = Free;
  tree->PrintData = PrintData;

  return tree;
}

static void RadixReleaseRadixSubtree(RadixNode *node, RadixTree *tree)
{
  if (node != NULL) {
    RadixReleaseRadixSubtree(node->left, tree);
    RadixReleaseRadixSubtree(node->right, tree);
    RadixReleaseNode(node, tree);
  }
}

void RadixReleaseRadixTree (RadixTree *tree)
{
  RadixReleaseRadixSubtree(tree->head, tree);
  tree->head = NULL;
}

static RadixNode *RadixAddKey (uint8_t *key_stream, uint16_t key_bitlen, RadixTree *tree, void *user, uint8_t netmask)
{
  RadixNode *node = NULL;
  RadixNode *new_node = NULL;
  RadixNode *parent = NULL;
  RadixNode *inter_node = NULL;
  RadixNode *bottom_node = NULL;

  RadixPrefix *prefix = NULL;

  uint8_t *stream = NULL;
  uint8_t bitlen = 0;

  int check_bit = 0;
  int differ_bit = 0;

  int i = 0;
  int j = 0;
  int temp = 0;

  /* chop the ip address against a netmask */
  RadixChopIPAddressAgainstNetmask(key_stream, netmask, key_bitlen);

  if ((prefix = RadixCreatePrefix(key_stream, key_bitlen, user, netmask)) == NULL) {
    return NULL;
  }

  /* the very first element in the radix tree */
  if (tree->head == NULL) {
    node = RadixCreateNode();
    node->prefix = prefix;
    node->bit    = prefix->bitlen;
    tree->head  = node;

    if (netmask == 255 || (netmask == 32 && key_bitlen == 32) || (netmask == 128 && key_bitlen == 128))
      return node;

    /* if we have reached here, we are actually having a proper netblock in
     * our hand(i.e. < 32 for ipv4 and < 128 for ipv6).  Add the netmask for
     * this node.  The reason we add netmasks other than 32 and 128, is
     * because we need those netmasks in case of searches for ips contained
     * in netblocks.  If the netmask is 32 or 128, either ways we will be
     * having an exact match for that ip value.  If it is not, we start
     * chopping the incoming search ip key using the netmask values added
     * into the tree and then verify for a match */
    node->netmask_cnt++;
    node->netmasks = xrealloc(node->netmasks, (node->netmask_cnt * sizeof(uint8_t)));
    node->netmasks[0] = netmask;
    return node;
  }

  node = tree->head;
  stream = prefix->stream;
  bitlen = prefix->bitlen;

  /* we walk down the tree only when we satisfy 2 conditions.  The first one
   * being the incoming prefix is shorter than the differ bit of the current
   * node.  In case we fail in this aspect, we walk down to the tree, till we
   * arrive at a node that ends in a prefix */
  while (node->bit < bitlen || node->prefix == NULL) {
    /* if the bitlen isn't long enough to handle the bit test, we just walk
     * down along one of the paths, since either paths should end up with a
     * node that has a common prefix whose differ bit is greater than the
     * bitlen of the incoming prefix */
    if (bitlen < node->bit) {
      if (node->right == NULL)
        break;
      node = node->right;
    } else {
      if (RADIX_BITTEST(stream[node->bit >> 3], (0x80 >> (node->bit % 8))) ) {
        if (node->right == NULL)
          break;
        node = node->right;
      } else {
        if (node->left == NULL)
          break;
        node = node->left;
      }
    }
  }

  /* we need to keep a reference to the bottom-most node, that actually holds
   * the prefix */
  bottom_node = node;

  /* get the first bit position where the ips differ */
  check_bit = (node->bit < bitlen)? node->bit: bitlen;
  for (i = 0; (i * 8) < check_bit; i++) {
    if ((temp = (stream[i] ^ bottom_node->prefix->stream[i])) == 0) {
      differ_bit = (i + 1) * 8;
      continue;
    }

    /* find out the position where the first bit differs.  This method is
     * faster, but at the cost of being larger.  But with larger caches
     * these days we don't have to worry about cache misses */
    temp = temp * 2;
    if (temp >= 256)      j = 0;
    else if (temp >= 128) j = 1;
    else if (temp >= 64)  j = 2;
    else if (temp >= 32)  j = 3;
    else if (temp >= 16)  j = 4;
    else if (temp >= 8)   j = 5;
    else if (temp >= 4)   j = 6;
    else if (temp >= 2)   j = 7;

    differ_bit = i * 8 + j;
    break;
  }
  if (check_bit < differ_bit)
    differ_bit = check_bit;

  /* walk up the tree till we find the position, to fit our new node in */
  parent = node->parent;
  while (parent && differ_bit <= parent->bit) {
    node = parent;
    parent = node->parent;
  }

  /* We already have the node in the tree with the same differing bit pstn */
  if (differ_bit == bitlen && node->bit == bitlen) {
    if (node->prefix != NULL) {
      /* Check if we already have this netmask entry covered by this prefix */
      if (RadixPrefixContainNetmask(node->prefix, netmask)) {
        /* Basically we already have this stream prefix, as well as the
         * netblock entry for this.  A perfect duplicate. */
        /* "Duplicate entry for this ip address/netblock") */
      } else {
        /* Basically we already have this stream prefix, but we don't
         * have an entry for this particular netmask value for this
         * prefix.  For example, we have an entry for 192.168.0.0 and
         * 192.168.0.0/16 and now we are trying to enter 192.168.0.0/20 */
        RadixAddNetmaskUserDataToPrefix(node->prefix, netmask, user);

        /* if we are adding a netmask of 32(for ipv4) or 128(for ipv6)
         * it indicates we are adding an exact host ip into the radix
         * tree, in which case we don't need to add the netmask value
         * into the tree */
        if (netmask == 255 || (netmask == 32 && bitlen == 32) || (netmask == 128 && bitlen == 128))
          return node;

        /* looks like we have a netmask which is != 32 or 128, in which
         * case we walk up the tree to insert this netmask value in the
         * correct node */
        parent = node->parent;
        while (parent != NULL && netmask < (parent->bit + 1)) {
          node = parent;
          parent = parent->parent;
        }

        node->netmask_cnt++;
        node->netmasks = xrealloc(node->netmasks, (node->netmask_cnt * sizeof(uint8_t)));

        if (node->netmask_cnt == 1) {
          node->netmasks[0] = netmask;
          return new_node;
        }

        node->netmasks[node->netmask_cnt - 1] = netmask;

        for (i = node->netmask_cnt - 2; i >= 0; i--) {
          if (netmask < node->netmasks[i]) {
            node->netmasks[i + 1] = netmask;
            break;
          }

          node->netmasks[i + 1] = node->netmasks[i];
          node->netmasks[i] = netmask;
        }
      }
    } else {
      node->prefix = RadixCreatePrefix(prefix->stream, prefix->bitlen, user, 255);
    }
    return node;
  }

  /* create the leaf node for the new key */
  new_node = RadixCreateNode();
  new_node->prefix = prefix;
  new_node->bit = prefix->bitlen;

  /* indicates that we have got a key that has length that is already covered
   * by a prefix of some other key in the tree.  We create a new intermediate
   * node with a single child and stick it in.  We need the if only in the
   * case of variable length keys */
  if (differ_bit == bitlen) {
    if (RADIX_BITTEST(bottom_node->prefix->stream[differ_bit >> 3], (0x80 >> (differ_bit % 8))) ) {
      new_node->right = node;
    } else {
      new_node->left = node;
    }
    new_node->parent = node->parent;

    if (node->parent == NULL)
      tree->head = new_node;
    else if (node->parent->right == node)
      node->parent->right = new_node;
    else
      node->parent->left = new_node;

    node->parent = new_node;
    /* stick our new_node into the tree.  Create a node that holds the
     * differing bit position and break the branch.  Also handle the
     * tranfer of netmasks between node and inter_node(explained in more
     * detail below) */
  } else {
    inter_node = RadixCreateNode();
    inter_node->prefix = NULL;
    inter_node->bit = differ_bit;
    inter_node->parent = node->parent;

    if (node->netmasks != NULL) {
      for (i = 0; i < node->netmask_cnt; i++) {
        if (node->netmasks[i] < differ_bit + 1)
          break;
      }

      inter_node->netmasks = xmalloc((node->netmask_cnt - i) * sizeof(uint8_t));

      for (j = 0; j < (node->netmask_cnt - i); j++)
        inter_node->netmasks[j] = node->netmasks[i + j];

      inter_node->netmask_cnt = (node->netmask_cnt - i);
      node->netmask_cnt = i;

      if (node->netmask_cnt == 0) {
        xfree(node->netmasks);
        node->netmasks = NULL;
      }
    }

    if (RADIX_BITTEST(stream[differ_bit >> 3], (0x80 >> (differ_bit % 8))) ) {
      inter_node->left = node;
      inter_node->right = new_node;
    } else {
      inter_node->left = new_node;
      inter_node->right = node;
    }
    new_node->parent = inter_node;

    if (node->parent == NULL)
      tree->head = inter_node;
    else if (node->parent->right == node)
      node->parent->right = inter_node;
    else
      node->parent->left = inter_node;

    node->parent = inter_node;
  } 
  /* insert the netmask into the tree */
  if (netmask != 255 && (netmask != 32 || (netmask == 32 && bitlen != 32)) && netmask != 128) {
    node = new_node;
    parent = new_node->parent;
    while (parent != NULL && netmask < (parent->bit + 1)) {
      node = parent;
      parent = parent->parent;
    }

    node->netmask_cnt++;
    node->netmasks = xrealloc(node->netmasks, (node->netmask_cnt * sizeof(uint8_t)));

    if (node->netmask_cnt == 1) {
      node->netmasks[0] = netmask;
      return new_node;
    }

    node->netmasks[node->netmask_cnt - 1] = netmask;

    for (i = node->netmask_cnt - 2; i >= 0; i--) {
      if (netmask < node->netmasks[i]) {
        node->netmasks[i + 1] = netmask;
        break;
      }

      node->netmasks[i + 1] = node->netmasks[i];
      node->netmasks[i] = netmask;
    }
  }

  return new_node;
}

RadixNode *RadixAddKeyGeneric (uint8_t *key_stream, uint16_t key_bitlen, RadixTree *tree, void *user)
{
  return (RadixNode *)RadixAddKey(key_stream, key_bitlen, tree, user, 255);
}

RadixNode *RadixAddKeyIPV4 (uint8_t *key_stream, RadixTree *tree, void *user)
{
  return (RadixNode *)RadixAddKey(key_stream, 32, tree, user, 32);
}

RadixNode *RadixAddKeyIPV6 (uint8_t *key_stream, RadixTree *tree, void *user)
{
  return (RadixNode *)RadixAddKey(key_stream, 128, tree, user, 128);
}

RadixNode *RadixAddKeyIPV4Netblock (uint8_t *key_stream, RadixTree *tree, void *user, uint8_t netmask)
{
  return (RadixNode *)RadixAddKey(key_stream, 32, tree, user, netmask);
}

RadixNode *RadixAddKeyIPV6Netblock (uint8_t *key_stream, RadixTree *tree, void *user, uint8_t netmask)
{
  return (RadixNode *)RadixAddKey(key_stream, 128, tree, user, netmask);
}

RadixNode *RadixAddKeyIPV4String (const char *str, RadixTree *tree, void *user)
{
  uint32_t ip;
  uint8_t netmask = 32;
  char ip_str[32]; /* Max length for full ipv4/mask string with NUL */
  char *mask_str = NULL;
  struct in_addr addr;

  /* Make a copy of the string so it can be modified */
  xstrlcpy(ip_str, str, sizeof(ip_str) - 2);
  *(ip_str + (sizeof(ip_str) - 1)) = '\0';

  /* Does it have a mask? */
  if (NULL != (mask_str = strchr(ip_str, '/'))) {
    int cidr;
    *(mask_str++) = '\0';

    /* Dotted type netmask not supported (yet) */
    if (strchr(mask_str, '.') != NULL) {
      return NULL;
    }

    /* Get binary values for cidr mask */
    cidr = atoi(mask_str);
    if ((cidr < 0) || (cidr > 32)) {
      return NULL;
    }
    netmask = (uint8_t)cidr;
  }

  /* Validate the IP */
  int r;
  if ((r = inet_pton(AF_INET, ip_str, &addr)) <= 0) {
    return NULL;
  }
  ip = addr.s_addr;

  return RadixAddKey((uint8_t *)&ip, 32, tree, user, netmask);
}

RadixNode *RadixAddKeyIPV6String (const char *str, RadixTree *tree, void *user)
{
  uint8_t netmask = 128;
  char ip_str[80]; /* Max length for full ipv6/mask string with NUL */
  char *mask_str = NULL;
  struct in6_addr addr;

  /* Make a copy of the string so it can be modified */
  xstrlcpy(ip_str, str, sizeof(ip_str) - 2);
  *(ip_str + sizeof(ip_str) - 1) = '\0';

  /* Does it have a mask? */
  if (NULL != (mask_str = strchr(ip_str, '/'))) {
    int cidr;
    *(mask_str++) = '\0';

    /* Dotted type netmask not supported (yet) */
    if (strchr(mask_str, '.') != NULL) {
      return NULL;
    }

    /* Get binary values for cidr mask */
    cidr = atoi(mask_str);
    if ((cidr < 0) || (cidr > 32)) {
      return NULL;
    }
    netmask = (uint8_t)cidr;
  }

  /* Validate the IP */
  if (inet_pton(AF_INET6, ip_str, &addr) <= 0) {
    return NULL;
  }

  return RadixAddKey(addr.s6_addr, 128, tree, user, netmask);
}

static void RadixTransferNetmasksBWNodes (RadixNode *dest, RadixNode *src)
{
  int i = 0, j = 0;

  /* no netmasks in the source node, to transfer to the destination node */
  if (src->netmasks == NULL) return;

  dest->netmasks = xrealloc(dest->netmasks, (src->netmask_cnt + dest->netmask_cnt) * sizeof(uint8_t));

  for (i = dest->netmask_cnt, j = 0; j < src->netmask_cnt; i++, j++)
    dest->netmasks[i] = src->netmasks[j];
}

static void RadixRemoveNetblockEntry (RadixNode *node, uint8_t netmask)
{
  RadixNode *parent = NULL;
  RadixNode *local_node = node;
  int i = 0;

  RadixRemoveNetmaskUserDataFromPrefix(node->prefix, netmask);

  if (netmask == 32 || netmask == 128)
    return;

  local_node = node;
  parent = local_node->parent;
  while (parent != NULL && netmask < (parent->bit + 1)) {
    local_node = parent;
    parent = parent->parent;
  }

  for (i = 0; i < node->netmask_cnt; i++) {
    if (node->netmasks[i] == netmask)
      break;
  }

  if (i == node->netmask_cnt) {
    /* "Something's wrong with the tree.  We are unable to find the "netmask entry" */
    return;
  }

  for ( ; i < node->netmask_cnt - 1; i++)
    node->netmasks[i] = node->netmasks[i + 1];

  node->netmask_cnt--;
  if (node->netmask_cnt == 0) {
    xfree(node->netmasks);
    node->netmasks = NULL;
    return;
  }

  node->netmasks = xrealloc(node->netmasks, node->netmask_cnt * sizeof(uint8_t));
}

static void RadixRemoveKey (uint8_t *key_stream, uint16_t key_bitlen, RadixTree *tree, uint8_t netmask)
{
  RadixNode *node = tree->head;
  RadixNode *parent = NULL;
  RadixNode *temp_dest = NULL;

  RadixPrefix *prefix = NULL;

  int mask = 0;
  int i = 0;

  if (node == NULL)
    return;

  if ((prefix = RadixCreatePrefix(key_stream, key_bitlen, NULL, 255)) == NULL)
    return;

  while (node->bit < prefix->bitlen) {
    if (RADIX_BITTEST(prefix->stream[node->bit >> 3], (0x80 >> (node->bit % 8))) ) {
      node = node->right;
    } else {
      node = node->left;
    }

    if (node == NULL) {
      RadixReleasePrefix(prefix, tree);
      return;
    }
  }

  if (node->bit != prefix->bitlen || node->prefix == NULL) {
    RadixReleasePrefix(prefix, tree);
    return;
  }

  i = prefix->bitlen / 8;
  if (memcmp(node->prefix->stream, prefix->stream, i) == 0) {
    mask = -1 << (8 - prefix->bitlen % 8);

    if (prefix->bitlen % 8 == 0 ||
      (node->prefix->stream[i] & mask) == (prefix->stream[i] & mask)) {
      if (!RadixPrefixContainNetmask(node->prefix, netmask)) {
        /* The ip key exists in the Radix Tree */
        RadixReleasePrefix(prefix, tree);
        return;
      }
    } else {
      /* You are trying to remove a key that doesn't exist in the Radix Tree */
      RadixReleasePrefix(prefix, tree);
      return;
    }
  } else {
    /* You are trying to remove a key that doesn't exist in the Radix Tree */
    RadixReleasePrefix(prefix, tree);
    return;
  }

  /* The ip node does exist, and the netblock entry does exist in this node, if
   * we have reached this point.  If we have more than one netblock entry, it
   * indicates we have multiple entries for this key.  So we delete that
   * particular netblock entry, and make our way out of this function */
  if (RadixPrefixNetmaskCount(node->prefix) > 1) {
    RadixRemoveNetblockEntry(node, netmask);
    RadixReleasePrefix(prefix, tree);
    return;
  }

  /* we are deleting the root of the tree.  This would be the only node left
   * in the tree */
  if (tree->head == node) {
    xfree(node);
    tree->head = NULL;
    RadixReleasePrefix(prefix, tree);
    return;
  }

  parent = node->parent;
  /* parent->parent is not the root of the tree */
  if (parent->parent != NULL) {
    if (parent->parent->left == parent) {
      if (node->parent->left == node) {
        temp_dest = parent->right;
        parent->parent->left = parent->right;
        parent->right->parent = parent->parent;
      } else {
        temp_dest = parent->left;
        parent->parent->left = parent->left;
        parent->left->parent = parent->parent;
      }
    } else {
      if (node->parent->left == node) {
        temp_dest = parent->right;
        parent->parent->right = parent->right;
        parent->right->parent = parent->parent;
      } else {
        temp_dest = parent->left;
        parent->parent->right = parent->left;
        parent->left->parent = parent->parent;
      }
    }
    /* parent is the root of the tree */
  } else {
    if (parent->left == node) {
      temp_dest = tree->head->right;
      tree->head->right->parent = NULL;
      tree->head = tree->head->right;
    } else {
      temp_dest = tree->head->left;
      tree->head->left->parent = NULL;
      tree->head = tree->head->left;
    }
  }
  /* We need to shift the netmask entries from the node that would be
   * deleted to its immediate descendant */
  RadixTransferNetmasksBWNodes(temp_dest, parent);
  /* release the nodes */
  RadixReleaseNode(parent, tree);
  RadixReleaseNode(node, tree);
  RadixReleasePrefix(prefix, tree);
}

void RadixRemoveKeyGeneric (uint8_t *key_stream, uint16_t key_bitlen, RadixTree *tree)
{
  return RadixRemoveKey(key_stream, key_bitlen, tree, 255);
}

void RadixRemoveKeyIPV4Netblock (uint8_t *key_stream, RadixTree *tree, uint8_t netmask)
{
  return RadixRemoveKey(key_stream, 32, tree, netmask);
}

void RadixRemoveKeyIPV4 (uint8_t *key_stream, RadixTree *tree)
{
  return RadixRemoveKey(key_stream, 32, tree, 32);
}

void RadixRemoveKeyIPV6Netblock (uint8_t *key_stream, RadixTree *tree, uint8_t netmask)
{
  return RadixRemoveKey(key_stream, 128, tree, netmask);
}

void RadixRemoveKeyIPV6 (uint8_t *key_stream, RadixTree *tree)
{
  return RadixRemoveKey (key_stream, 128, tree, 128);
}

static inline RadixNode *RadixFindKeyIPNetblock (uint8_t *key_stream, uint8_t key_bitlen, RadixNode *node)
{
  RadixNode *netmask_node = NULL;
  int mask = 0;
  int bytes = 0;
  int i = 0;
  int j = 0;

  while (node != NULL && node->netmasks == NULL)
    node = node->parent;

  if (node == NULL)
    return NULL;
  /* hold the node found containing a netmask.  We will need it when we call
   * this function recursively */
  netmask_node = node;

  for (j = 0; j < netmask_node->netmask_cnt; j++) {
    bytes = key_bitlen / 8;
    for (i = 0; i < bytes; i++) {
      mask = -1;
      if ( ((i + 1) * 8) > netmask_node->netmasks[j]) {
        if ( ((i + 1) * 8 - netmask_node->netmasks[j]) < 8)
          mask = -1 << ((i + 1) * 8 - netmask_node->netmasks[j]);
        else
          mask = 0;
      }
      key_stream[i] &= mask;
    }

    while (node->bit < key_bitlen) {
      if (RADIX_BITTEST(key_stream[node->bit >> 3], (0x80 >> (node->bit % 8))) ) {
        node = node->right;
      } else {
        node = node->left;
      }

      if (node == NULL)
        return NULL;
    }

    if (node->bit != key_bitlen || node->prefix == NULL)
      return NULL;

    if (memcmp(node->prefix->stream, key_stream, bytes) == 0) {
      mask = -1 << (8 - key_bitlen % 8);

      if (key_bitlen % 8 == 0 ||
        (node->prefix->stream[bytes] & mask) == (key_stream[bytes] & mask)) {
        if (RadixPrefixContainNetmaskAndSetUserData(node->prefix, netmask_node->netmasks[j], 0))
          return node;
      }
    }
  }

  return RadixFindKeyIPNetblock(key_stream, key_bitlen, netmask_node->parent);
}

static RadixNode *RadixFindKey (uint8_t *key_stream, uint16_t key_bitlen, RadixTree *tree, int exact_match)
{
  if (tree == NULL || tree->head == NULL)
    return NULL;

  RadixNode *node = tree->head;
  int mask = 0;
  int bytes = 0;
  uint8_t tmp_stream[255];

  if (key_bitlen > 255)
    return NULL;

  memset(tmp_stream, 0, 255);
  memcpy(tmp_stream, key_stream, key_bitlen / 8);

  while (node->bit < key_bitlen) {
    if (RADIX_BITTEST(tmp_stream[node->bit >> 3], (0x80 >> (node->bit % 8))) ) {
      node = node->right;
    } else {
      node = node->left;
    }

    if (node == NULL) {
      return NULL;
    }
  }

  if (node->bit != key_bitlen || node->prefix == NULL) {
    return NULL;
  }

  bytes = key_bitlen / 8;
  if (memcmp(node->prefix->stream, tmp_stream, bytes) == 0) {
    mask = -1 << (8 - key_bitlen % 8);

    if (key_bitlen % 8 == 0 ||
      (node->prefix->stream[bytes] & mask) == (tmp_stream[bytes] & mask)) {
      if (RadixPrefixContainNetmaskAndSetUserData(node->prefix, key_bitlen, 1)) {
        return node;
      }
    }
  }

  /* if you are not an ip key, get out of here */
  if (exact_match) {
    return NULL;
  }

  RadixNode *ret = RadixFindKeyIPNetblock(tmp_stream, key_bitlen, node);
  return ret;
}

RadixNode *RadixFindKeyGeneric (uint8_t *key_stream, uint16_t key_bitlen, RadixTree *tree)
{
  return RadixFindKey(key_stream, key_bitlen, tree, 1);
}

RadixNode *RadixFindKeyIPV4ExactMatch (uint8_t *key_stream, RadixTree *tree)
{
  return RadixFindKey(key_stream, 32, tree, 1);
}

RadixNode *RadixFindKeyIPV4BestMatch (uint8_t *key_stream, RadixTree *tree)
{
  return RadixFindKey(key_stream, 32, tree, 0);
}

RadixNode *RadixFindKeyIPV4Netblock (uint8_t *key_stream, RadixTree *tree, uint8_t netmask)
{
  RadixNode *node;
  node = RadixFindKey(key_stream, 32, tree, 0);
  if (node == NULL)
    return node;

  if (RadixPrefixContainNetmaskAndSetUserData(node->prefix, netmask, 1))
    return node;
  else
    return NULL;
}

RadixNode *RadixFindKeyIPV6Netblock (uint8_t *key_stream, RadixTree *tree, uint8_t netmask)
{
  RadixNode *node;
  node = RadixFindKey(key_stream, 128, tree, 0);
  if (node == NULL)
    return node;

  if (RadixPrefixContainNetmaskAndSetUserData(node->prefix, (uint16_t)netmask, 1))
    return node;
  else
    return NULL;
}

RadixNode *RadixFindKeyIPV6ExactMatch (uint8_t *key_stream, RadixTree *tree)
{
  return RadixFindKey(key_stream, 128, tree, 1);
}

RadixNode *RadixFindKeyIPV6BestMatch (uint8_t *key_stream, RadixTree *tree)
{
  return RadixFindKey(key_stream, 128, tree, 0);
}

void RadixPrintNodeInfo (RadixNode *node, int level,  void (*PrintData)(void*))
{
  int i = 0;

  if (node == NULL)
    return;

  for (i = 0; i < level; i++)
    printf("   ");

  printf("%d [", node->bit);

  if (node->netmasks == NULL) {
    printf("%d, ", -1);
  } else {
    for (i = 0; i < node->netmask_cnt; i++)
      printf("%s%d", (0 == i ? "" : ", "), node->netmasks[i]);
  }

  printf("] (");
  if (node->prefix != NULL) {
    for (i = 0; i * 8 < node->prefix->bitlen; i++)
      printf("%s%d", (0 == i ? "" : "."), node->prefix->stream[i]);
    printf(")\n");

    if (PrintData != NULL) {
      RadixUserData *ud = NULL;
      do {
        ud = node->prefix->user_data;
        printf(" [%d], ", ud->netmask);
        PrintData(ud->user);
        ud = ud->next;
      } while (ud != NULL);
    } else {
      printf("No print function provided");
    }
    printf("\n");
  } else {
    printf("NULL)\n");
  }
}

static void RadixPrintRadixSubtree (RadixNode *node, int level, void (*PrintData)(void*))
{
  if (node != NULL) {
    RadixPrintNodeInfo(node, level, PrintData);
    RadixPrintRadixSubtree(node->left, level + 1, PrintData);
    RadixPrintRadixSubtree(node->right, level + 1, PrintData);
  }
}

void RadixPrintTree(RadixTree *tree)
{
  printf("Printing the Radix Tree: \n");

  RadixPrintRadixSubtree(tree->head, 0, tree->PrintData);
}

