#ifndef _XSYS_H
#define _XSYS_H

#define XSYS_ENTERPRISE   1
#define XSYS_PROFESSIONAL 2
#define XSYS_STANDARD     3

void xsys_init (void);

int xsys_spec (void);
unsigned int xsys_get_cpu_num (void);
void xsys_get_mem_use (float *used);
void xsys_get_cpu_use (float *used);
void xsys_get_mnt_fs_use (char *mnt_point, float *used);

unsigned long xsys_disk_size (char *mnt_point);
unsigned long xsys_mem_size (void);
unsigned long xsys_uptime (void);
unsigned int xsys_my_gateway (void);

unsigned long xsys_phys_mem (void);
int xsys_page_size (void);

#endif
