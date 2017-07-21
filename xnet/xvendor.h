#ifndef __XVENDOR_H__
#define __XVENDOR_H__

/*
** in  mac -> 00112233445566
** out mac vendor name
*/
void create_oui_table (void);
void destroy_oui_table (void);
char *get_oui_info (unsigned char *mac);
#endif
