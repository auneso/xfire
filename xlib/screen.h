#ifndef __SCREEN_H__
#define __SCREEN_H__

// ISO VT100/220 definitions
#define VT_COL_TEXT_BLACK    "30"
#define VT_COL_TEXT_RED      "31"
#define VT_COL_TEXT_GREEN    "32"
#define VT_COL_TEXT_YELLOW   "33"
#define VT_COL_TEXT_BLUE     "34"
#define VT_COL_TEXT_MAGENTA  "35"
#define VT_COL_TEXT_CYAN     "36"
#define VT_COL_TEXT_WHITE    "37"
#define VT_COL_BACK_BLACK    "40"
#define VT_COL_BACK_RED      "41"
#define VT_COL_BACK_GREEN    "42"
#define VT_COL_BACK_YELLOW   "43"
#define VT_COL_BACK_BLUE     "44"
#define VT_COL_BACK_MAGENTA  "45"
#define VT_COL_BACK_CYAN     "46"
#define VT_COL_BACK_WHITE    "47"

#define VT_GOTOXY(X,Y)  "\33["Y";"X"f"
#define VT_COLOR(C)     "\33["C"m"
#define VT_RESET        "\33[m"
#define VT_REVERSE      "\33[7m"
#define VT_UNREVERSE    "\33[27m"
#define VT_BOLD         "\33[1m"
#define VT_UNBOLD       "\33[22m"
#define VT_BLINK        "\33[5m"
#define VT_UNBLINK      "\33[25m"

#define VT_CLREOL       "\33[K"
#define VT_CLRSOL       "\33[1K"
#define VT_CLRLIN       "\33[2K"
#define VT_CLREOS       "\33[J"
#define VT_CLRSOS       "\33[1J"
#define VT_CLRSCR       "\33[2J"


void erase_whole_screen (void);
void erase_form_screen (void);
void erase_to_screen (void);
void erase_whole_line (void);
void erase_from_line (void);
void erase_to_line (void);
void goto_cursor(int x, int y);
void set_underline (void);
void reset_underline (void);
void set_blink (void);
void reset_blink (void);
void set_inverse (void);

int  tty_cbreak (int fd, int wait_for_chars, int timer_dsec);
int  tty_raw (int fd, int wait_for_chars, int timer_dsec);
int  tty_reset (int fd);
void tty_atexit (void);
void tty_tput_reset (void);
int  tty_size (int fd, int *x, int *y);

int  tty_key_pressed (int time);

#endif

