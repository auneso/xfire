#ifndef __PRIOQ_H__
#define __PRIOQ_H__



typedef struct prioqueue  prioq_t;

prioq_t *prioq_new (int size, int (*cmp)(void *, void *));
int  prioq_add (prioq_t *pq, void *data);
void *prioq_get (prioq_t *pq);
int  prioq_items (prioq_t *pq);
void prioq_free (prioq_t *pq);


#endif
