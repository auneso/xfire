/*
** 2013-08-09  HDS 
** 2013-08-13  HDS bug fixed 
** 2013-11-13  HDS xsys_get_cpu_num
** 2014-08-28  HDS xsys_mem_size, xsys_disk_size
*/
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include "xsys.h"

extern char *intoa(unsigned int);

struct cpudata {
  unsigned long user, system, idle, nice, total;
};


struct memdata {
  unsigned long total, free, buffered, cached;
};

static struct cpudata oldcpu;

/* Get CPU data */
static void get_cpu_stat (struct cpudata *cpu)
{
  FILE *file;
  char temp[10];
  char line[255];

  /* CPU */
  if ((file = fopen("/proc/stat", "r"))) {
    fgets(line, 255, file);
    fclose(file);
    sscanf(line, "%s %lu %lu %lu %lu", temp, &cpu->user, &cpu->nice, &cpu->system, &cpu->idle);
    cpu->total = cpu->user + cpu->system + cpu->idle + cpu->nice;
  } else {
    cpu->total = cpu->user = cpu->system = cpu->idle = cpu->nice = 0;
  }
}

#define MEMTOTAL  "MemTotal:"
#define MEMFREE   "MemFree:"
#define MEMBUF    "Buffers:"
#define MEMCACHE  "Cached:"
#define SWAPTOTAL "SwapTotal:"
#define SWAPFREE  "SwapFree:"

/* Get Memory data */
static void get_mem_stat (struct memdata *mem)
{
  FILE *file;
  char line[255];
  int i = 0;

  if ((file = fopen("/proc/meminfo", "r"))) {
    while (!feof(file) && i < 4) {
      fgets(line, 255, file);
      if (memcmp(line, MEMTOTAL, strlen(MEMTOTAL)) == 0) {
        sscanf(line + strlen(MEMTOTAL), "%ld", &mem->total);
        i++;
      } else
      if (memcmp(line, MEMFREE, strlen(MEMFREE)) == 0) {
        sscanf(line + strlen(MEMFREE), "%ld", &mem->free);
        i++;
      } else
      if (memcmp(line, MEMBUF, strlen(MEMBUF)) == 0) {
        sscanf(line + strlen(MEMBUF), "%ld", &mem->buffered);
        i++;
      } else
      if (memcmp(line, MEMCACHE, strlen(MEMCACHE)) == 0) {
        sscanf(line + strlen(MEMCACHE), "%ld", &mem->cached);
        i++;
      } 
    }
    fclose(file);
  }
}


void xsys_init (void)
{
  get_cpu_stat(&oldcpu);
}

int xsys_spec (void)
{
  int spec;
  struct memdata mem;
  int numCPU = sysconf(_SC_NPROCESSORS_ONLN);

  get_mem_stat(&mem);

  spec = mem.total/(1024*1024);

//  printf("SYSTEM = %d:%ld", numCPU, mem.total);

  if      (spec > 30 && numCPU > 8)  { return XSYS_ENTERPRISE; }
  else if (spec > 16 && numCPU > 4)  { return XSYS_PROFESSIONAL; }
  else                               { return XSYS_STANDARD; }
}

void xsys_get_mem_use (float *used)
{
  struct memdata mem;

  get_mem_stat(&mem);

/*
  printf("Mem total = %ld, free = %ld, buffered = %ld, cached = %ld\n",
          mem.total, mem.free, mem.buffered, mem.cached);
*/

  if (mem.total >=  mem.free + mem.buffered + mem.cached)
    *used = (float)(mem.total - mem.free - mem.buffered - mem.cached) * 100.0 / mem.total;
  else
    *used = 100.0;
}

unsigned long xsys_mem_size (void)
{
  struct sysinfo  info;

  if (0 != sysinfo(&info)) return 0;
  return info.totalram * info.mem_unit;
}


void xsys_get_cpu_use (float *used)
{
  struct cpudata cpu;
  float uload = 0, sload = 0;
  
  get_cpu_stat(&cpu);
  if (cpu.total - oldcpu.total > 0)
    uload = (float) ((cpu.user - oldcpu.user) * 100) / (cpu.total - oldcpu.total);
  if (cpu.total - oldcpu.total) 
    sload = (float) ((cpu.system - oldcpu.system) * 100) / (cpu.total - oldcpu.total);
  *used = uload + sload;
  oldcpu = cpu;
}

unsigned int xsys_get_cpu_num (void)
{
#ifdef _SC_NPROCESSORS_ONLN
  return sysconf(_SC_NPROCESSORS_ONLN);
#else /* !_SC_NPROCESSORS_ONLN */
  int mib[2];
  unsigned int n;
  size_t len = sizeof(n);

  mib[0] = CTL_HW;
  mib[1] = HW_AVAILCPU;
  sysctl(mib, sizeof(mib)/sizeof(int), &n, &len, NULL, 0);

  if (n < 1) {
    mib[1] = HW_NCPU;
    sysctl(mib, sizeof(mib)/sizeof(int), &n, &len, NULL, 0);
    if (n < 1) {
      n = 1;
    }
  }
  return n;
#endif /* !_SC_NPROCESSORS_ONLN */

#if 0
  FILE    *f = NULL;
  int     ncpu = 0;

  if ((f = fopen("/proc/cpuinfo", "r"))) {
    char line[1024];
    while (NULL != fgets(line, sizeof(line), f)) {
      if (memcmp(line, "processor", 8)) continue;
      ncpu++;
    }
    fclose(f);
  }

  if (0 == ncpu) ncpu = 1;
  return ncpu;
#endif
}

void xsys_get_mnt_fs_use (char *mnt_point, float *used)
{
  struct statvfs  svfsbuf;
  unsigned long blk_free;
  unsigned long blk_used;
//  unsigned long blk_reserved;

  if (statvfs (mnt_point, &svfsbuf) == -1) { 
    *used = 0;
    return;
  }
   
  blk_free     = svfsbuf.f_bavail;
  blk_used     = svfsbuf.f_blocks - svfsbuf.f_bfree;
//  blk_reserved = svfsbuf.f_bfree - svfsbuf.f_bavail;

#if 0
  {
    unsigned long inode_free;
    unsigned long inode_reserved;
    unsigned long inode_used;

    /* Sanity-check for the values in the struct */
    if (svfsbuf.f_ffree < svfsbuf.f_favail) svfsbuf.f_ffree = svfsbuf.f_favail;
    if (svfsbuf.f_files < svfsbuf.f_ffree)  svfsbuf.f_files = svfsbuf.f_ffree;

    inode_free = (unsigned long) svfsbuf.f_favail;
    inode_reserved = (unsigned long) (svfsbuf.f_ffree - svfsbuf.f_favail);
    inode_used = (unsigned long) (svfsbuf.f_files - svfsbuf.f_ffree);
  }
#endif

  if (blk_used == 0) *used = 0;
  else {
    *used = (float)(blk_used * 100.0) / (blk_used + blk_free) + 0.5;
  }
}

unsigned long xsys_disk_size (char *mnt_point)
{
  struct statvfs  svfsbuf;
  if (statvfs (mnt_point, &svfsbuf) == -1) return 0;
  return svfsbuf.f_blocks * svfsbuf.f_frsize;
}


void get_cpu_id (char *cpuid, int len)
{
  unsigned long x[4];
  unsigned long y[4];
  int i;
  int j;
  char c;

  x[0] = x[1] =  x[2] =  x[3] = 0;

  asm volatile(".byte 15;.byte 162" : "=a"(x[0]),"=b"(x[1]),"=c"(x[3]),"=d"(x[2]) : "0"(0) );
  if (!x[0]) return;
  asm volatile(".byte 15;.byte 162" : "=a"(y[0]),"=b"(y[1]),"=c"(y[2]),"=d"(y[3]) : "0"(1) );

  for (i = 1; i < 4;++i)
    for (j = 0; j < 4;++j) {
      c = x[i] >> (8 * j);
      if (c < 32) c = 32;
      if (c > 126) c = 126;
      putchar(c);
    }

  snprintf(cpuid, len,  "-%08lx-%08lx\n", y[0], y[3]);
}

unsigned long xsys_uptime (void)
{
  struct sysinfo  info;

  if (0 != sysinfo(&info)) return 0;
  return info.uptime;
}

/*
 parse /proc/net/route which is as follow :

Iface   Destination     Gateway         Flags   RefCnt  Use     Metric  Mask            MTU     Window  IRTT
wlan0   0001A8C0        00000000        0001    0       0       0       00FFFFFF        0       0       0
eth0    0000FEA9        00000000        0001    0       0       0       0000FFFF        0       0       0
wlan0   00000000        0101A8C0        0003    0       0       0       00000000        0       0       0
eth0    00000000        00000000        0001    0       0       1000    00000000        0       0       0

 One header line, and then one line by route by route table entry.
*/
#include <arpa/inet.h>
unsigned int xsys_my_gateway (void)
{
  unsigned int d, g;
  char buf[256];
  int line = 0;
  FILE *f;
  char *p;

  f = fopen("/proc/net/route", "r");
  if (!f) return 0; 

  while (fgets(buf, sizeof(buf), f)) {
    if (line > 0) {  /* skip the first line */
      p = buf;
      /* skip the interface name */
      while (*p && !isspace(*p)) p++;
      while (*p && isspace(*p)) p++;
      if ((sscanf(p, "%x%x", &d, &g) == 2)
      &&  (d == 0 && g != 0)) { /* default */
        fclose(f);
        return g;
      }
    }
    line++;
  }
  /* default route not found ! */
  if (f) fclose(f);
  return 0;
}

unsigned long xsys_phys_mem (void)
{
  long pagesize, pages;

  pagesize = sysconf(_SC_PAGESIZE);
  pages = sysconf(_SC_PHYS_PAGES);
  if (pages == -1 || pagesize == -1)
    return 0;

  return pages * pagesize;
}

int xsys_page_size (void)
{
  return (int)sysconf(_SC_PAGESIZE);
}

#if 0
 struct sysinfo {
   long uptime;             /* Seconds since boot */
   unsigned long loads[3];  /* 1, 5, and 15 minute load averages */
   unsigned long totalram;  /* Total usable main memory size */
   unsigned long freeram;   /* Available memory size */
   unsigned long sharedram; /* Amount of shared memory */
   unsigned long bufferram; /* Memory used by buffers */
   unsigned long totalswap; /* Total swap space size */
   unsigned long freeswap;  /* swap space still available */
   unsigned short procs;    /* Number of current processes */
   unsigned long totalhigh; /* Total high memory size */
   unsigned long freehigh;  /* Available high memory size */
   unsigned int mem_unit;   /* Memory unit size in bytes */
   char _f[20-2*sizeof(long)-sizeof(int)]; /* Padding for libc5 */
 };
void xsys_info () 
{
  struct sysinfo si;
  sysinfo(&si);
}
#endif

