/*
** 2010/06/17 - HDS
** Organizationally Unique Identifier (OUI) is a 24-bit number 
*/
#include "hashtab.h"
#include "format.h"
#include "xvendor.h"

#include "xoui.h"


static struct htab  *oui_tab = NULL;
static char *oui_none = "none";

static const char hex_chars[] = "0123456789ABCDEF";

static void oui_to_str (unsigned char *oui, unsigned char *ep)
{
  u_int  i, hi, lo;

  for (i = 0; i < 3; i++) {
    hi = *ep >> 4;
    lo = *ep++ & 0xf; 
    if (hi < 16 && lo < 16) {
      *oui++ = hex_chars[hi];
      *oui++ = hex_chars[lo];
    } else {
      *oui++ = 0;
      *oui++ = 0;
    }
  }
  *oui = '\0';
}

void create_oui_table (void)
{
  int i = 0, n = 0;

  while (mac_vendor[n].mac) n++; 

  oui_tab = hcreate(n);
  for (i = 0; i < n; i++)
    hadd(oui_tab, (unsigned char *)mac_vendor[i].mac, 6, mac_vendor[i].vendor);
}

void destroy_oui_table (void) 
{
  if (oui_tab) hdestroy(oui_tab);
}

/*
** in  mac -> 00112233445566 
** out mac vendor name
*/
char *get_oui_info (unsigned char *mac)
{
  if (oui_tab) {
    unsigned char oui[8];

    oui_to_str(oui, mac);
    if (hfind(oui_tab, oui, 6)) return hstuff(oui_tab);
  } 
  return oui_none;
}
