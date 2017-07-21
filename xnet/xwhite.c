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
#include "xwhite.h"
#include "xfire.h"

static xwhitelist_table *white_list = NULL;
static pthread_mutex_t white_mutex = PTHREAD_MUTEX_INITIALIZER;


void xwhite_lock (void)
{ pthread_mutex_lock(&white_mutex); }

void xwhite_unlock (void)
{ pthread_mutex_unlock(&white_mutex); }

/* Black List -----------------------------------*/
void xwhitelist_apply (void)
{
  xwhitelist *u;
  Xiptree  *xtree = xiptree_create();;
   
  if (hfirst(white_list->htab)) do {
    u = hstuff(white_list->htab);
    xiptree_insert_cmd(xtree, u->ipv4str, u);
  } while (hnext(white_list->htab));
  xiptree_destroy(white_list->xtree);
  white_list->xtree = xtree;
}

static void save_whitelist (void)
{
  FILE *fp;
  xwhitelist *u;

  if ((fp = fopen(XFIRE_WHITE_LIST_FILE , "w+"))) {
    if (hfirst(white_list->htab)) do {
      u = hstuff(white_list->htab);
      fprintf(fp, "%s\n", u->ipv4str);
    } while (hnext(white_list->htab));

    fclose(fp);
  }
}

static void load_whitelist (void)
{
  FILE *fp;
  char buf[128];
  int len;
  
  if ((fp = fopen(XFIRE_WHITE_LIST_FILE , "r"))) {
    while (fgets(buf, sizeof(buf), fp)) {
      if (buf[0] == '#' || buf[0] == '\n') continue;
      len = strlen(buf);
      buf[len--] = 0; 
      if (len) {
        xwhite_add(buf);
      }
    }
    xwhitelist_apply();
    fclose(fp);
  }
}

static void white_ip_free (void)
{
  xwhitelist *u;

 if (hfirst(white_list->htab)) do {
    u = hstuff(white_list->htab);
    if (u->ipv4str) xfree(u->ipv4str);
  } while (hnext(white_list->htab));
}

void xwhite_create (void)
{
  white_list = xzalloc(sizeof(xwhitelist_table));
  white_list->xtree = xiptree_create();
  white_list->htab  = hcreate(128);
  white_list->space = xfmem_create(sizeof(xwhitelist), 0);
  load_whitelist();
}

void xwhite_destroy (void)
{
  if (white_list) {
    xiptree_destroy(white_list->xtree);
    white_ip_free();
    hdestroy(white_list->htab);
    xfmem_destroy(white_list->space);
    xfree(white_list);
    white_list = NULL;
  }
}

/* xwhite_lock, xwhite_unlock */
void xwhite_add (char *ip)
{
  xwhitelist *u;
  
  if (!hfind(white_list->htab, (ub8 *)ip, strlen(ip))) {
    u = (xwhitelist *)xfmem_malloc(white_list->space);
    u->ipv4str = xstrdup(ip); 
    hadd(white_list->htab, (ub8 *)u->ipv4str, strlen(u->ipv4str), u);
    save_whitelist(); 
  }
}

/* xwhite_lock, xwhite_unlock */
void xwhite_del (char *ip)
{
  xwhitelist *u;

  if (hfind(white_list->htab, (ub8 *)ip, strlen(ip))) {
    u = hstuff(white_list->htab);
    if (u->ipv4str) xfree(u->ipv4str);
    xfmem_remove(white_list->space, u);
    hdel(white_list->htab); 
    save_whitelist(); 
  }
}

void xwhite_apply (void)
{
  xwhitelist *u;
  Xiptree  *xtree = xiptree_create();;
   
  if (hfirst(white_list->htab)) do {
    u = hstuff(white_list->htab);
    xiptree_insert_cmd(xtree, u->ipv4str, u);
  } while (hnext(white_list->htab));
  xiptree_destroy(white_list->xtree);
  white_list->xtree = xtree;
}

/* xwhite_lock, xwhite_unlock */
xwhitelist *xwhite_find (ub32 ip)
{
  return xiptree_lookup(white_list->xtree, ip);
}


/* xwhite_lock, xfree, xwhite_unlock */
xwhitelist **xwhite_get_array (int *cnt)
{   
  xwhitelist **table, **tptr;
  int bcnt = hcount(white_list->htab);
        
  *cnt = bcnt;
  if (bcnt == 0) return NULL; 
  table = (xwhitelist **)xmalloc(sizeof(xwhitelist *) * bcnt);
  tptr = table;
  if (hfirst(white_list->htab)) do {
    *tptr++ = hstuff(white_list->htab);
  } while (hnext(white_list->htab));
  return table;
}   
    
