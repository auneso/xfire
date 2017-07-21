#ifndef __XPQ_H__
#define __XPQ_H__

typedef int (*xpq_compar)(const void *lhs, const void *rhs);
typedef struct {
  void **q;
  size_t length;
  size_t capacity;
  xpq_compar compar;
} xpq_t;

int  xpq_init(xpq_t *pq, xpq_compar cmp);
void xpq_free(xpq_t *pq);
int  xpq_push(xpq_t *pq, void *item);
void *xpq_top(xpq_t *pq);
void xpq_pop(xpq_t *pq);
int  xpq_empty(xpq_t *pq);
size_t xpq_size(xpq_t *pq);

#endif /* __XPQ_H__ */
