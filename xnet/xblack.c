/*
*/
#include <string.h>
#include <time.h>
#include <pthread.h>

#include "hashf.h"
#include "hashtab.h"
#include "xfmem.h"
#include "xtimeval.h"
#include "xstring.h"
#include "format.h"
#include "xalloc.h"
#include "xprintf.h"

#include "xconfig.h"
#include "xblack.h"
#include "xfire.h"

static xblacklist_table *black_list = NULL;
static pthread_mutex_t black_mutex = PTHREAD_MUTEX_INITIALIZER;


void xblack_lock (void)
{ pthread_mutex_lock(&black_mutex); }

void xblack_unlock (void)
{ pthread_mutex_unlock(&black_mutex); }

/* Black List -----------------------------------*/
void xblacklist_apply (void)
{
  xblacklist *u;
  Xiptree  *xtree = xiptree_create();;
   
  if (hfirst(black_list->htab)) do {
    u = hstuff(black_list->htab);
    xiptree_insert_cmd(xtree, u->ipv4str, u);
  } while (hnext(black_list->htab));
  xiptree_destroy(black_list->xtree);
  black_list->xtree = xtree;
}

static void save_blacklist (void)
{
  FILE *fp;
  xblacklist *u;

  if ((fp = fopen(XFIRE_BLACK_LIST_FILE , "w+"))) {
    if (hfirst(black_list->htab)) do {
      u = hstuff(black_list->htab);
      fprintf(fp, "%s\n", u->ipv4str);
    } while (hnext(black_list->htab));

    fclose(fp);
  }
}

static void load_blacklist (void)
{
  FILE *fp;
  char buf[128];
  int len;
  
  if ((fp = fopen(XFIRE_BLACK_LIST_FILE , "r"))) {
    while (fgets(buf, sizeof(buf), fp)) {
      if (buf[0] == '#' || buf[0] == '\n') continue;
      len = strlen(buf);
      buf[len--] = 0; 
      if (len) {
        xblack_add(buf);
      }
    }
    xblacklist_apply();
    fclose(fp);
  }
}

static void black_ip_free (void)
{
  xblacklist *u;

 if (hfirst(black_list->htab)) do {
    u = hstuff(black_list->htab);
    if (u->ipv4str) xfree(u->ipv4str);
  } while (hnext(black_list->htab));
}

void xblack_create (void)
{
  black_list = xzalloc(sizeof(xblacklist_table));
  black_list->xtree = xiptree_create();
  black_list->htab  = hcreate(128);
  black_list->space = xfmem_create(sizeof(xblacklist), 0);
  load_blacklist();
}

void xblack_destroy (void)
{
  if (black_list) {
    xiptree_destroy(black_list->xtree);
    black_ip_free();
    hdestroy(black_list->htab);
    xfmem_destroy(black_list->space);
    xfree(black_list);
    black_list = NULL;
  }
}

/* xblack_lock, xblack_unlock */
void xblack_add (char *ip)
{
  xblacklist *u;
  
  if (!hfind(black_list->htab, (ub8 *)ip, strlen(ip))) {
    u = (xblacklist *)xfmem_malloc(black_list->space);
    u->ipv4str = xstrdup(ip); 
    hadd(black_list->htab, (ub8 *)u->ipv4str, strlen(u->ipv4str), u);
    save_blacklist(); 
  }
}

/* xblack_lock, xblack_unlock */
void xblack_del (char *ip)
{
  xblacklist *u;

  if (hfind(black_list->htab, (ub8 *)ip, strlen(ip))) {
    u = hstuff(black_list->htab);
    if (u->ipv4str) xfree(u->ipv4str);
    xfmem_remove(black_list->space, u);
    hdel(black_list->htab); 
    save_blacklist(); 
  }
}

void xblack_apply (void)
{
  xblacklist *u;
  Xiptree  *xtree = xiptree_create();;
   
  if (hfirst(black_list->htab)) do {
    u = hstuff(black_list->htab);
    xiptree_insert_cmd(xtree, u->ipv4str, u);
  } while (hnext(black_list->htab));
  xiptree_destroy(black_list->xtree);
  black_list->xtree = xtree;
}

/* xblack_lock, xblack_unlock */
xblacklist *xblack_find (ub32 ip)
{
  return xiptree_lookup(black_list->xtree, ip);
}


/* xblack_lock, xfree, xblack_unlock */
xblacklist **xblack_get_array (int *cnt)
{   
  xblacklist **table, **tptr;
  int bcnt = hcount(black_list->htab);
        
  *cnt = bcnt;
  if (bcnt == 0) return NULL; 
  table = (xblacklist **)xmalloc(sizeof(xblacklist *) * bcnt);
  tptr = table;
  if (hfirst(black_list->htab)) do {
    *tptr++ = hstuff(black_list->htab);
  } while (hnext(black_list->htab));
  return table;
}   
    
