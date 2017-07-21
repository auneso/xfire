#ifndef __VPORTMAP_H__
#define __VPORTMAP_H__

void vportmap_set (unsigned int ip, unsigned short rport, unsigned char vport);
void vportmap_clear (void);
void vportmap_unset (unsigned int ip, unsigned short rport);
unsigned short vportmap_get (unsigned int ip, unsigned short rport);

#endif
