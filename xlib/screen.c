#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

void erase_whole_screen (void )
{ printf("\e[2J"); fflush(stdout); }

void erase_form_screen (void )
{ printf("\e[0J"); fflush(stdout); }

void erase_to_screen (void )
{ printf("\e[1J"); fflush(stdout); }


void erase_whole_line (void)
{ printf("\e[2K"); fflush(stdout); }

void erase_from_line (void)
{ printf("\e[0K"); fflush(stdout); }

void erase_to_line (void)
{ printf("\e[1K"); fflush(stdout); }


void goto_cursor(int x, int y)
{ printf("\e[%d;%dH", y, x); fflush(stdout); }

void set_underline (void)
{ printf("\e[4m"); fflush(stdout); }

void reset_underline (void)
{ printf("\e[24m"); fflush(stdout); }

void set_blink (void)
{ printf("\e[5m"); fflush(stdout); }

void reset_blink (void)
{ printf("\e[25m"); fflush(stdout); }

void set_inverse (void)
{ printf("\e[7m"); fflush(stdout); }

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

static struct termios  save_termios;
static int    ttysavefd = -1;
static enum { RESET, RAW, CBREAK }  ttystate = RESET;

/* put terminal into a cbreak mode */
int tty_cbreak (int fd, int wait_for_chars, int timer_dsec)
{
  struct termios  buf;

  if (tcgetattr(fd, &save_termios) < 0)
    return -1;
  buf = save_termios;
  buf.c_lflag &= ~(ECHO | ICANON); /* echo off, canonical mode off */

  buf.c_cc[VMIN] = wait_for_chars;
  buf.c_cc[VTIME] = timer_dsec;

  if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
    return -1;
  ttystate = CBREAK;
  ttysavefd = fd;
  return 0;
}

/* put terminal into a raw mode */
int tty_raw (int fd, int wait_for_chars, int timer_dsec)
{
  struct termios  buf;

  if (tcgetattr(fd, &save_termios) < 0)
    return -1;

  buf = save_termios;

  buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
          /* echo off, canonical mode off, extended input
             processing off, signal chars off */
  buf.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
          /* no SIGINT on BREAK, CR-to-NL off, input parity
             check off, don't strip 8th bit on input,
             output flow control off */
  buf.c_cflag &= ~(CSIZE | PARENB);
          /* clear size bits, parity checking off */
  buf.c_cflag |= CS8;
          /* set 8 bits/char */

  buf.c_oflag &= ~(OPOST);
          /* output processing off */

  buf.c_cc[VMIN] = wait_for_chars;
  buf.c_cc[VTIME] = timer_dsec;
  if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
    return -1;
  ttystate = RAW;
  ttysavefd = fd;
  return 0;
}

/* restore terminal's mode */
int tty_reset (int fd)
{
  if (ttystate != CBREAK && ttystate != RAW)
    return 0;

  if (tcsetattr(fd, TCSAFLUSH, &save_termios) < 0)
    return -1;
  ttystate = RESET;
  return(0);
}

/* can be set up by atexit(tty_atexit) */
void tty_atexit (void)
{
  if (ttysavefd >= 0 && ttystate != RESET)
    tty_reset(ttysavefd);
}

/* reset linux terminal */
void tty_tput_reset (void)
{
  printf("\033c\033]R");
  fflush(stdout);
}

int tty_key_pressed (int time)
{
  /* The following source code is based on
     Morgan McGuires (morgan@cs.brown.edu)
     POSIX implementation of _kbhit. */

  static int init = 0;
  struct timeval tmo;
  fd_set fd;

  if (init == 0) {
    struct termios trm;
    tcgetattr(0, &trm);
    trm.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &trm);
    setbuf(stdin, NULL);
    init = 1;
  }
  FD_ZERO(&fd);
  FD_SET(0, &fd);
  tmo.tv_sec  = time;
  tmo.tv_usec = 0;
  return select(0 + 1, &fd, NULL, NULL, &tmo);
}


int tty_size (int fd, int *x, int *y)
{
  struct winsize ts;

  if (!isatty(fd)) return 0;

  if (ioctl(1,TIOCGWINSZ,&ts) && ts.ws_row>0 && ts.ws_col>0) {
    *x = ts.ws_col;
    *y = ts.ws_row;
    return 1;
  }
  return 0;
}

