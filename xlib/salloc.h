#ifndef __SALLOC_H__
#define __SALLOC_H__

typedef struct _smem {
  int  top;
  int  max;
  
  int  size;
  char *smem;
  char **cell;
} smem_t;

smem_t  *smem_create (int size, int num);
void    smem_destroy(smem_t *smem);
int     smem_count(smem_t *smem);

void    *smalloc(smem_t *smem);
void    *scalloc(smem_t *smem);
void    sfree(smem_t *smem, void *cell);

#endif /* __SALLOC_H__ */
