#ifndef __SPT_H__
#define __SPT_H__

#include <stdlib.h>
#include "xtypes.h"

typedef struct spt {
  struct spt *leftlink;
  struct spt *rightlink;
  struct spt *uplink;
  ub64   prio; 
} spt_t;

void   spt_enqueue (spt_t **root, spt_t *n);
spt_t *spt_dequeue (spt_t **root);
spt_t *spt_head (spt_t **root);
void   spt_remove (spt_t **root, spt_t *n);
spt_t *spt_first (spt_t *root);
spt_t *spt_last (spt_t *root);
spt_t *spt_next (spt_t *n);
spt_t *spt_prev (spt_t *n);

#endif
