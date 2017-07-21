/*
 * Copyright (C) 2001-2003 WIDE Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
#ifndef __ATP_H__
#define __ATP_H__

#include <sys/queue.h>

#define  MAX_KEYBYTES  16
#define  MAX_KEYBITS  (MAX_KEYBYTES * 8)

struct atp_node {
  struct  atp_node *tn_parent;     /* parent node */
  struct  atp_node *tn_left;       /* left child node */
  struct  atp_node *tn_right;      /* right child node */
  struct  atp *tn_atp;            /* back pointer to atp head */
  TAILQ_ENTRY(atp_node) tn_chain;  /* the LRU list entry */
  
  size_t  tn_prefixlen;             /* prefix length of the key */
  u_char  tn_key[MAX_KEYBYTES];     /* key value */

  u_char     tn_inatp;
  short      tn_depth;               /* set in atp_walk */
  u_int64_t  tn_count;
};

struct atp {
  struct  atp_node *tr_top;    /* top node of the atp */
  size_t  tr_keylen;            /* key size in bits */
  u_int   tr_nfree;             /* free node count */

  u_int64_t  tr_count;

#ifdef AGURI_STATS
  struct {
    u_int  hits;
    u_int  total;
    u_int  reclaimed;
  } tr_stats;
#endif  
  TAILQ_HEAD(_lru, atp_node)  tr_lru;  /* LRU list */
};

/*
 * cast u_int64_t to ull for printf, since type of u_int64_t
 * is architecture dependent
 */
typedef  unsigned long long  ull;

void atp_init(struct atp *tp, size_t keylen, size_t maxnodes);
void atp_destroy(struct atp *tp);

void atp_leaf_addcount(struct atp *tp, const void *key, u_int64_t cnt);
struct atp_node *atp_node_addcount(struct atp *tp, const void *key, size_t len, u_int64_t cnt);

int atp_walk(struct atp *tp, int (*func)(struct atp_node *, void *), void *arg);
int atp_aggregate(struct atp *tp, u_int64_t thresh);
void atp_resetcount(struct atp *tp);
void atp_print(struct atp *tp);

int atp_sub_walk (struct atp_node *top, int (*func)(struct atp_node *, void *), void *arg);
int atp_sub_postorderwalk (struct atp_node *top, int (*func)(struct atp_node *, void *), void *arg);
u_int64_t atp_sub_sum(struct atp_node *np);
void atp_sub_reduce(struct atp *tp, struct atp_node *np, int depth);

#endif
