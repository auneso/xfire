/*
** 2008/06/26 - HDS add
** 2010/01/20 - HDS modify ip para add
*/

#include "xalloc.h"
#include "llist.h"

static llist *vportmap = NULL;
struct vpm {
  unsigned int ip;
  unsigned short rport;
  unsigned short vport;
}; 


void vportmap_set (unsigned int ip, unsigned short rport, unsigned char vport)
{
  struct vpm *v;

  if (vportmap == NULL) {
    vportmap = llist_create();
  }
  v = xmalloc(sizeof(struct vpm));
  v->ip = ip;
  v->rport = rport;
  v->vport = vport;
  llist_append(vportmap, v);
}

static void free_handle(void *ptr)
{ xfree(ptr); }

void vportmap_clear (void)
{
  llist_destroy (vportmap, free_handle);
}

void vportmap_unset (unsigned int ip, unsigned short rport)
{
  struct vpm *v;

  v = llist_get_first (vportmap);
  while (v) {
    if (v->ip == ip && v->rport == rport) {
      llist_remove(vportmap, v);
      xfree(v);
    }
    v = llist_get_next(vportmap);
  }
}

unsigned short vportmap_get (unsigned int ip, unsigned short rport)
{
  struct vpm *v;

  v = llist_get_first (vportmap);
  while (v) {
    if (v->ip == ip && v->rport == rport) {
      return v->vport;
    }
    v = llist_get_next(vportmap);
  }
  return -1;
}
