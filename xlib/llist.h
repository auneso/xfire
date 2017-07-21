#ifndef __LLIST_H__
#define __LLIST_H__

/* linked list ------------------------------------*/

typedef struct _lnode {
  void *ptr;
  struct _lnode *next;
  struct _lnode *prev;
} lnode;

typedef struct _llist {
  size_t size;
  struct _lnode *first;
  struct _lnode *last;
  struct _lnode *iterator;
} llist;


extern llist *llist_create ();
extern void llist_destroy (llist *list, void (*free_handle)(void* ptr));
extern void llist_clear (llist *list, void (*free_handle)(void* ptr));
extern void llist_append (llist *list, void *data_ptr);
extern int  llist_insert (llist *list, void *data_ptr);
extern void llist_remove (llist *list, void *data_ptr);
extern size_t llist_size (llist *list);

extern void *llist_get_index (llist*list, size_t offset);
extern void *llist_get_first (llist*list);
extern void *llist_get_last (llist*list);
extern void *llist_get_next (llist*list);
extern void *llist_get_prev (llist*list);

extern lnode *llist_get_first_node (llist*list);
extern lnode *llist_get_last_node (llist*list);

extern void llist_copy (llist *dst, llist *src);

#endif
