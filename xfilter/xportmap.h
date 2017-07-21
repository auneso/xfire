#ifndef __XPORTMAP_H__
#define __XPORTMAP_H__


#define XPORTMAP_MAX 65535
/*
  Specifies a network port.
  Whether a range of PORTs (PORT_start-PORT_end), spec is converted to a range.
  The range is min to max (16-bit PORTs) inclusive.
*/
typedef struct _xportspec
{
  unsigned short min;
  unsigned short max;
} xportspec ;


typedef struct _xportmap
{
  xportspec *array;       /* array of patterns, network specs */
  unsigned int patterns;  /* total patterns in array */
  unsigned int capacity;  /* current capacity of array */
} xportmap;

int xport_parse (const char *line, xportspec *spec);

xportmap *xportmap_create (void);
void xportmap_destroy (xportmap *map);
int  xportmap_insert (xportmap *map, xportspec *newspec);
int  xportmap_insert_cmd (xportmap *map, const char *cmd);
int  xportmap_insert_cmd_one (xportmap *map, const char *cmd);
int  xportmap_valid_cmd (const char *cmd);
void xportmap_compile (xportmap *map);
int  xportmap_search (xportmap *map, unsigned short port);
void xportmap_dump (xportmap *map);


#endif

