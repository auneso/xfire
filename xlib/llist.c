/*
**  2008/10/24 - HDS
**  2008/01/29 - HDS llist_copy, llist_insert
*/

#include <string.h>
#include <assert.h>

#include "xalloc.h"
#include "llist.h"

llist *llist_create()
{
  llist *list = NULL;
  list = (llist*)xcalloc(sizeof(llist), 1);
  if (list == NULL)
    return NULL;
  return list;
}

void llist_destroy (llist *list, void (*free_handle)(void *ptr))
{
  if (list) {
    llist_clear(list, free_handle);
    xfree(list);
  }
}

void llist_clear (llist *list, void (*free_handle)(void *ptr))
{
  lnode *node = list->first;
  lnode *tmp = NULL;
  while (node) {
    tmp = node->next;
    if (free_handle) free_handle(node->ptr);
    xfree(node);
    node = tmp;
  }
  memset(list, 0, sizeof(llist));
}

void llist_append (llist *list, void *data_ptr)
{
  lnode *new_node = (lnode*)xzalloc(sizeof(lnode));
  new_node->ptr = data_ptr;
  
  if (list->last) {
    list->last->next = new_node;
    new_node->prev = list->last;
  }
  else {
    list->first = new_node;
  }

  list->last = new_node;
  list->size++;
}

void llist_remove (llist *list, void *data_ptr)
{
  lnode *node = list->first;
  assert(data_ptr);

  list->iterator = NULL;

  while (node) {
    if (node->ptr == data_ptr) {
      if (node->next)
        node->next->prev = node->prev;
      
      if (node->prev)
        node->prev->next = node->next;
      
      if (node == list->last)
        list->last = node->prev;

      if (node == list->first)
        list->first = node->next;

      xfree(node);

      list->size--;
      break;
    }
    node = node->next;
  }
}

size_t llist_size (llist* list)
{
  return list->size;
}

void *llist_get_index (llist* list, size_t offset)
{
  lnode* node = list->first;
  size_t n = 0;

  for (n = 0; n < list->size; n++) {
    if (n == offset) {
      return node->ptr;
    }
    node = node->next;
  }
  return NULL;
}


void *llist_get_first (llist *list)
{
  list->iterator = list->first;
  if (list->iterator == NULL) return NULL;
  return list->iterator->ptr;
}

lnode *llist_get_first_node (llist* list)
{
  list->iterator = list->first;
  if (list->iterator == NULL) return NULL;
  return list->iterator;
}

void *llist_get_last (llist *list)
{
  list->iterator = list->last;
  if (list->iterator == NULL) return NULL;
  return list->iterator->ptr;
}

lnode *llist_get_last_node (llist *list)
{
  list->iterator = list->last;
  if (list->iterator == NULL) return NULL;
  return list->iterator;
}

void *llist_get_next (llist *list)
{
  if (list->iterator == NULL) list->iterator = list->first;
  else                        list->iterator = list->iterator->next;
  
  if (list->iterator == NULL) return NULL;
  return list->iterator->ptr;
}

void *llist_get_prev (llist* list)
{
  if (list->iterator == NULL) return NULL;
  list->iterator = list->iterator->prev;
  if (list->iterator == NULL) return NULL;
  return list->iterator->ptr;
}

void llist_copy (llist *dst, llist *src)
{
  void *ptr;

  ptr = llist_get_first(src);
  while (ptr) {
    llist_append(dst, ptr);
    ptr = llist_get_next (src);
  }
}

int llist_insert (llist *list, void *data_ptr)
{
  void *ptr;

  ptr = llist_get_first(list);
  while (ptr) {
    if (ptr == data_ptr) return 0;
    ptr = llist_get_next (list);
  }
  llist_append(list, data_ptr);
  return 1;
}
