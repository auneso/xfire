/*
** set program name : librte_eal/linuxapp/eal/eal_interrupts.c (rte_eal_intr_init) 
*/
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

#include "xtimeval.h"
#include "format.h"
#include "thread.h"
#include "xprintf.h"
#include "xlog.h"
#include "xsys.h"

#include "xfire.h"
#include "xwall.h"
#include "xpacket.h"
#include "xblack.h"
#include "xsession.h"

#include "xdpdk.h"
#include "xconfig.h"


#define XFIRE_CHECK_VERSION 0x0001
#define XFIRE_NONE_DAEMON   0x0002
#define XFIRE_STOP          0x0004
#define XFIRE_REBUILD       0x0008
#define XFIRE_UPGRADE       0x0010
#define XFIRE_START         0x0020
#define XFIRE_INIT          0x0040
#define XDPDK_INIT          0x0080
#define XFIRE_ARG_ERROR     0x1000

#define SIGNAL_XFIRE_STOP  SIGINT

int xfire_run = 1;

static char xfire_version[64];
static int  xfire_spec;
static pid_t xfire_old_pid, xfire_new_pid;

static rte_rwlock_t count_lock = RTE_RWLOCK_INITIALIZER;

void xfire_write_lock (void)
{
  rte_rwlock_write_lock(&count_lock);
}

void xfire_write_unlock (void)
{
  rte_rwlock_write_unlock(&count_lock);
}

void xfire_read_lock (void)
{
  rte_rwlock_read_lock(&count_lock);
}

void xfire_read_unlock (void)
{
  rte_rwlock_read_unlock(&count_lock);
}

char *get_xfire_version (void)
{
  return xfire_version;
}

int get_xfire_spec (void)
{
  return xfire_spec;
}

static void xfire_set_spec (void)
{
  xsys_init();
  xfire_spec = xsys_spec();
}

void xfire_shutdown (int sig)
{
  signal(SIGNAL_XFIRE_STOP, SIG_IGN);
   
  exit(1);
}


static void xfire_set_signal (void)
{
  signal(SIGPIPE, SIG_IGN);
  signal(SIGCLD,  SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGABRT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGTERM, SIG_IGN);

  signal(SIGNAL_XFIRE_STOP, xfire_shutdown);
}

static pid_t xdaemon (int opt)
{
  int fd;

  switch (fork()) {
    case -1: return (-1);
    case 0:  break;
    default: _exit(0);
  }
  if (setsid() == -1) return (-1);

  if (((opt & XFIRE_REBUILD) || (opt & XFIRE_UPGRADE)) 
  && (fd = open("/dev/null", O_RDWR, 0)) != -1) {
    (void)dup2(fd, STDIN_FILENO);
    (void)dup2(fd, STDOUT_FILENO);
    (void)dup2(fd, STDERR_FILENO);
    if (fd > 2) (void)close (fd);
  }
  setsid();
  signal(SIGCHLD, SIG_IGN);

  return (0);
}

static void read_pid_file (void)
{
  xfire_old_pid = 0;

  if (access(XFIRE_PID_FILE, F_OK) == 0) {
    FILE *fp = fopen(XFIRE_PID_FILE, "r");

    if (fp) {
      flock(fileno(fp), LOCK_EX);
      if (fscanf(fp, "%d", &xfire_old_pid) != 1 || kill(xfire_old_pid, 0) == -1) {
        flock(fileno(fp), LOCK_UN);
        fclose(fp);
        xfire_old_pid = 0;
        unlink(XFIRE_PID_FILE);
      } else {
        flock(fileno(fp), LOCK_UN);
        fclose(fp);
      }
    }
  }
}

/* Create the runnnig daemon pidfile */
static void write_pid_file (void)
{
  unlink(XFIRE_PID_FILE);
  
  int fd = open(XFIRE_PID_FILE, O_RDWR|O_CREAT|O_CLOEXEC, 0644);
  if (fd < 0) {
    printf("pidfile_write : Can not open %s pidfile", XFIRE_PID_FILE);
    exit(1);
  }
  flock(fd, LOCK_EX);
  char pidbuf[12];
  xsprintf(pidbuf, "%d\n", xfire_new_pid);
  ssize_t r = write(fd, pidbuf, strlen(pidbuf));
  if (r == -1) {
    printf("unable to write pidfile: %s", strerror(errno));
    flock(fd, LOCK_UN);
    close(fd);
    exit(1);
  }
  flock(fd, LOCK_UN);
  close(fd);
}

static void xfire_check_run (void)
{
  if (xfire_old_pid == 0) {
    write_pid_file();
    return;
  }
  /* If no process is attached to pidfile, remove it */
  if (kill(xfire_old_pid, 0) == -1) {
    unlink(XFIRE_PID_FILE);
    write_pid_file();
    return;
  }
  printf("\nAlready Running xfire  (%d)\n", xfire_old_pid);
  exit(1);
}

static void xfire_kill (void)
{
  if (xfire_old_pid == 0) return;
  int t = 0;
  int status;

  kill(xfire_old_pid, SIGINT);
  do {
    sleep(1);
    if (t++ > 5) kill(xfire_old_pid, SIGKILL);
  } while (kill(xfire_old_pid, 0) == 0); 
  (void)wait(&status);
}


static void usage (void)
{
  fprintf (stderr,"Usage : xfire\n");
  fprintf (stderr,"        -v Version\n");
  fprintf (stderr,"        -n  (none daemon mode)\n");
  fprintf (stderr,"        -stop   (stop xfire)\n");
  fprintf (stderr,"        -start (start xfire)\n");
  fprintf (stderr,"        -init (init xfire)\n");
  exit(0);
}

static void xfire_run_proc (int argc, char **argv)
{
  /* Main packet proc */
  xdpdk_run_proc(argc, argv);
}

static void xfire_init (void)
{
  system("rm -f "XFIRE_ARP_INFO_FILE"");
  system("rm -f "XFIRE_MAC_INFO_FILE"");
}

static void print_xfire_version (int date)
{
  if (!date) {
    char *ptr = strchr(xfire_version, '-');
    if (ptr) *ptr = 0;
  }
  printf("\nxfire Ver-L %s\n", xfire_version);
}

int get_xfire_opt (int argc, char *argv[])
{  
  int i, val = 0;

  if (argc > 1) {
    for (i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-v") == 0) {         /* xfire version  */
        val |= XFIRE_CHECK_VERSION;
      } else
      if (strcmp(argv[i], "-n") == 0) {         /* none daemon mode */
        val |= XFIRE_NONE_DAEMON;
      } else
      if (strcmp(argv[i], "-stop") == 0) {      /* stop xfire */
        val |= XFIRE_STOP;
      } else
      if (strcmp(argv[i], "-start") == 0) {     /* start xfire */
        val |= XFIRE_START;
      } else
      if (strcmp(argv[i], "-init") == 0) {      /* init xfire */
        val |= XFIRE_INIT;
      } else
      if (strcmp(argv[i], "-c") == 0) {        /* init dpdk */
        val |= XDPDK_INIT;
        i++;
      }
    }
  }
  return val;
}

int main (int argc, char **argv)
{
  int opt = 0;
  
  /*
   * We don't need network access, so relinquish any set-UID
   * or set-GID privileges we have (if any).
   *
   * We do *not* want set-UID privileges when opening a
   * trace file, as that might let the user read other
   * people's trace files (especially if we're set-UID
   * root).
   */
  if (setgid(getgid()) != 0 || setuid(getuid()) != 0 )
    fprintf(stderr, "Warning: setgid/setuid failed !\n");

  if (geteuid() || getuid()) {
    fprintf(stderr, "UID or EUID of 0 needed\n");
    exit(1);
  }
  
  if (setgid(0) || setuid(0)) {
    fprintf(stderr, "setuid error\n");
    exit(1);
  }

  read_pid_file();
  snprintf(xfire_version, sizeof(xfire_version), "%s - %s %s", XFIRE_VERSION,  __DATE__, __TIME__);
  

//  opt = get_xfire_opt(argc, argv);
//  if (opt & XFIRE_ARG_ERROR) {
//    usage();
//    exit(1);
//  }

  if (xpacket_create() == -1) xfire_fatal("xpacket_create error\n");

//  if (!(opt & XFIRE_NONE_DAEMON) && xdaemon(opt) == -1) {
//    xfire_fatal("\nxfire not daemon\n");
//  }

  xfire_new_pid = getpid();

  if (opt & XFIRE_CHECK_VERSION) {
    print_xfire_version(1);
    exit(0);
  }
  print_xfire_version(0);
  if (opt & XFIRE_STOP) {
    xfire_logging("xfire stop\n"); 
    xfire_kill();
    exit(0);
  } else
  if (opt & XFIRE_START) {
    xfire_logging("xfire satrt(%d -> %d)\n", xfire_old_pid, xfire_new_pid);
    xfire_kill();
  } else
  if (opt & XFIRE_INIT) {
    xfire_logging("xfire Init(%d)\n", xfire_new_pid);
    xfire_init();
    xfire_kill();
  }
  xfire_check_run();


  if (xfire_configure(XFIRE_CONFIG_FILE) == -1) xfire_fatal("\nxfire Config Error\n");


  xfire_set_spec();
  xfire_set_signal();

  setpriority(PRIO_PROCESS, getpid(), XFIRE_PRIORITY); /* max -20 */

  xfire_logging("xfire Boot V-%s\n", XFIRE_VERSION); 

  xfire_run_proc (argc, argv);
  
  exit(0);
}


