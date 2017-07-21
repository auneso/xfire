/*
 * 2009/02/11 - HDS add
 * 2017/03/24 - HDS port '*' -> 1~XPORTMAP_MAX
 * 2017/04/01 - HDS return port count
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#include "xtypes.h"
#include "xalloc.h"
#include "xfmem.h"
#include "xstring.h"
#include "xprintf.h"
#include "xvector.h"
#include "xportmap.h"

#define INIT_PORTS  4


int xportmap_parser (const char *line, xportspec *spec)
{
  unsigned int PORT[2];

  /* Try parsing a range. Spaces around hyphen are optional. */
  if (strchr(line, '-')
  && (sscanf(line, "%u - %u", &PORT[0], &PORT[1]) == 2))
  {
    spec->min = PORT[0];
    spec->max = PORT[1];
    if (spec->max >= spec->min)
      return (spec->max - spec->min + 1);
    else
      return 0;
  } else
  /* Try simple port */
  if (sscanf(line, "%u", &PORT[0]) == 1)
  {
    spec->min = PORT[0];
    spec->max = spec->min;
    return 1;
  }
  return 0;  /* could not parse */
}

/* Compare two netspecs, for sorting. Comparison is done on minimum of range */
static int port_sort (const void *a, const void *b)
{
  unsigned int c1 = ((xportspec*)a)->min;
  unsigned int c2 = ((xportspec*)b)->min;
  if (c1 < c2) return -1;
  if (c1 > c2) return +1;
  return 0;
}

/* Compare two netspecs, for searching. Test if key (only min) is inside range */
static int port_search (const void *a, const void  *b)
{
  unsigned int key = ((xportspec*)a)->min;
  unsigned int min = ((xportspec*)b)->min;
  unsigned int max = ((xportspec*)b)->max;
  if (key < min) return -1;
  if (key > max) return +1;
  return 0;
}

xportmap *xportmap_create (void)
{
  xportmap *map = xmalloc(sizeof(xportmap));
  map->patterns = 0;
  map->capacity = INIT_PORTS;
  map->array = (xportspec *)xmalloc(map->capacity * sizeof(xportspec));
  return map;
}

void xportmap_destroy (xportmap *map)
{
  xfree(map->array);
  xfree(map);
}

int xportmap_insert (xportmap *map, xportspec *newspec)
{
  if (map->patterns == map->capacity) {
    map->capacity *= 2;
    map->array = xrealloc(map->array, map->capacity*sizeof(xportspec));
  }
  map->array[map->patterns++] = *newspec;
  return (newspec->max - newspec->min + 1);
}

/* insert OK return port cnt, Error 0 */
int xportmap_insert_cmd (xportmap *map, const char *cmd)
{
  char *p, *t, *str;
  xvector *xvec;
  xportspec *ps;
  xfmem_t *mem;
  int eol = 0;
  int port_cnt = 0, cnt;
  if (!cmd) return 0;

  if (*cmd == '*') {
    xportspec xps;
    xps.min = 0;
    xps.max = XPORTMAP_MAX;
    xportmap_insert(map, &xps);
    return (xps.max - xps.min  + 1);
  }

  mem = xfmem_create(sizeof(xportspec), 0);
  xvec = xvector_create(0);
  str = xstrdup((char *)cmd);
  p = rmallws(str);
  while (!eol) {
    t = p;
    while (*p && *p != ',') p++;
    if (*p == 0) eol = 1;
    if (t != p) {
      *p = 0;
      ps = (xportspec *)xfmem_malloc(mem);
      if ((cnt = xportmap_parser (t, ps))) { /* OK */
         port_cnt += cnt;
        xvector_append(xvec, ps);
      } else  {                     /* Error */
        port_cnt = 0;
        break;
      }
      if (eol) break;
      t = ++p;
    }
  }
  xfree(str);

  if (port_cnt) {
    ps = (xportspec *)xvector_first(xvec);
    while (ps) {
      xportmap_insert(map, ps);
      ps = (xportspec *)xvector_next(xvec);
    }
  }

  xfmem_destroy(mem);
  xvector_destroy(xvec);
  return port_cnt;
}

int xportmap_valid_cmd (const char *cmd)
{
  char *p, *t, *str;
  xportspec ps;
  int eol = 0, rv = 1;

  if (!cmd  || !*cmd) return 0;

  str = xstrdup((char *)cmd);
  p = rmallws(str);
  while (!eol) {
    t = p;
    while (*p && *p != ',') p++;
    if (*p == 0) eol = 1;
    if (t != p) {
      *p = 0;
      if (!xportmap_parser(t, &ps)) { /* OK */
        rv = 0;
        break;
      }
      if (eol) break;
      t = ++p;
    }
  }
  xfree(str);
  return rv;
}

void xportmap_compile (xportmap *map)
{
  int item;
  xportspec *array = map->array;

  if (map->patterns < 2) return;

  qsort((char *)array, map->patterns, sizeof(xportspec), port_sort);

  /* cure overlaps so that ranges are disjoint and consistent */
  for (item = 1; item < map->patterns; item++) {
    if (array[item].max <= array[item-1].max)
      array[item] = array[item-1];
    else if (array[item].min <= array[item-1].max)
      array[item].min = array[item-1].max + 1; /* overflow possibility */
  }
}

int xportmap_insert_cmd_one (xportmap *map, const char *cmd)
{
  int rv = xportmap_insert_cmd(map, cmd);
  if (rv) xportmap_compile(map);
  return rv;
}

int xportmap_search (xportmap *map, unsigned short port)
{
  xportspec key;

  if (map->patterns == 0) return 0;

  key.min = port;
  if (bsearch(&key, map->array, map->patterns, sizeof(xportspec), port_search))
    return 1;
  return 0;
}

void xportmap_dump (xportmap *map)
{
  int i;
  xportspec *ps;

  for (i = 0; i < map->patterns; i++) {
    ps = &map->array[i];
    printf("idx = %d, min = %d, max = %d\n", i + 1, ps->min, ps->max);
  }
}



