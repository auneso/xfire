
/* static fixed memory allocation using stack */
/* 2008/10/1 - HDS */

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include "salloc.h"
#include "xalloc.h"

smem_t *smem_create (int size, int num)
{
  int i;
  char *ptr;
  
  smem_t *smem = (smem_t *)xmalloc(sizeof(smem_t));
  smem->cell   = (char **)xmalloc(sizeof(char *) * num);
  smem->smem = ptr = xmalloc(size * num);

  for (i = 0; i < num; i++) 
    smem->cell[i] = ptr + i * size;

  smem->top  = 0;
  smem->max  = num;
  smem->size = size;
  return smem;
}

void smem_destroy (smem_t *smem)
{
  if (smem) { 
    xfree(smem->smem);
    xfree(smem->cell);
    xfree(smem);
  }
}

void *smalloc (smem_t *smem)
{
  void *rmem = NULL;

  if (smem->top < smem->max) {
    rmem = (void *)smem->cell[smem->top++];
  }
  return rmem;
}

void *scalloc (smem_t *smem)
{
  void *mem = smalloc(smem);
  if (mem) memset(mem, 0, smem->size);
  return mem;
}

void sfree (smem_t *smem, void *cell)
{
  if (smem->top) {
    smem->cell[--smem->top] = cell; 
  }
}

int smem_count (smem_t *smem)
{
  return smem->top;
}
