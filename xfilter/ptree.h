/*
 * netsniff-ng - the packet sniffing beast
 * By Daniel Borkmann <daniel@netsniff-ng.org>
 * Copyright 2011 Daniel Borkmann, rewritten
 * Copyright 1991-2007 Kawahara Lab., Kyoto University
 * Copyright 2000-2005 Shikano Lab., Nara Institute of Science and Technology
 * Copyright 2005-2007 Julius project team, Nagoya Institute of Technology
 * All rights reserved
 * Subject to the GPL, version 2.
 */

#ifndef __PTREE_H__
#define __PTREE_H__

#include <netinet/in.h>


struct patricia_node {
  void *key;
  size_t klen;
  struct sockaddr_storage *addr;
  size_t alen;
  union {
    int data;
    int thres_bit;
  } value;
  struct patricia_node *l, *r;
} __cacheline_aligned;

int  ptree_search_data_nearest(void *str, size_t sstr, struct sockaddr_storage *addr, size_t *alen, struct patricia_node *root);
int  ptree_search_data_exact(void *str, size_t sstr, struct sockaddr_storage *addr, size_t *alen, struct patricia_node *root);
int  ptree_add_entry(void *str, size_t sstr, int data, struct sockaddr_storage *addr, size_t alen, struct patricia_node **root);
void ptree_del_entry(void *str, size_t sstr, struct patricia_node **root);
void ptree_get_key(int data, struct patricia_node *node, struct patricia_node **wanted);
void ptree_get_key_addr(struct sockaddr_storage *addr, size_t alen, struct patricia_node *node, struct patricia_node **wanted);
void ptree_display(struct patricia_node *node, int level);
void ptree_free(struct patricia_node *root);

#define ptree_maybe_add_entry ptree_add_entry

#endif /* PATRICIA_H */
