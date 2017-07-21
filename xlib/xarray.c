/*
 * Array is an xarray of (void*) items with unlimited capacity
 *
 * Array grows when xarrayAppend() is called and no space is left
 * Currently, xarray does not have an interface for deleting an item because
 *   we do not need such an interface yet.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "xarray.h"

/* grows internal buffer to satisfy required minimal capacity */
static void xarray_grow (xarray * a, int min_capacity)
{
  const int min_delta = 16;
  int delta;
  assert(a->capacity < min_capacity);
  delta = min_capacity;

  /* make delta a multiple of min_delta */
  delta += min_delta - 1;
  delta /= min_delta;
  delta *= min_delta;

  /* actual grow */
  assert(delta > 0);
  a->capacity += delta;
  a->items = a->items ?
  realloc(a->items, a->capacity * sizeof(void *)) :
  malloc(a->capacity * sizeof(void *));
  /* reset, just in case */
  memset(a->items + a->count, 0, (a->capacity - a->count) * sizeof(void *));
}

xarray *xarray_create (void)
{
  xarray *a = malloc(sizeof(xarray));
  xarray_init(a);
  return a;
}

void xarray_init(xarray * a)
{
  assert(a != NULL);
  memset(a, 0, sizeof(xarray));
}

void xarray_clean(xarray * a)
{
  assert(a != NULL);
  /* could also warn if some objects are left */
  free(a->items);
  a->items = NULL;
  a->count = 0;
}

void xarray_destroy (xarray * a)
{
  assert(a != NULL);
  xarray_clean(a);
  free(a);
}

void xarray_append (xarray * a, void *obj)
{
  assert(a != NULL);
  if (a->count >= a->capacity) xarray_grow(a, a->count + 1);
  a->items[a->count++] = obj;
}

void xarray_insert (xarray *a, void *obj, int position)
{
  assert(a != NULL);
  if (a->count >= a->capacity) xarray_grow(a, a->count + 1);
  if (position > a->count) position = a->count;
  if (position < a->count) memmove(&a->items[position + 1], &a->items[position], (a->count - position) * sizeof(void *));
  a->items[position] = obj;
  a->count++;
}

/* if you are going to append a known and large number of items, call this first */
void xarray_preappend (xarray * a, int app_count)
{
  assert(a != NULL);
  if (a->count + app_count > a->capacity)
    xarray_grow(a, a->count + app_count);
}

