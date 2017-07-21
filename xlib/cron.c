/*
** This is a clone of 'original' vixie-cron. It was used in Red Hat|Fedora
**  system and patched for a long time. Now was made clone tagged with version 4.2. 
** http://mmaslano.fedorapeople.org/cronie 
** 2009/01/12 - HDS 
** 2009/01/28 - HDS cron_func
** 2009/03/23 - HDS cron_get_time
** 2009/07/25 - HDS get_range (eq range)
*/

/* Examples 
# 8am-7pm activity reports every 20 minutes during weekdays.
0 8-18 * * 1-5 
# activity reports every 10 minutes everyday.
0 * * * * 
#
# Activity reports every an hour on Saturday and Sunday.
0 * * * 0,6
#
# 7pm-8am activity reports every an hour during weekdays.
 0 19-7 * * 1-5
#
# Daily summary prepared at 19:05.
5 19 * * * 
*/

#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "xstring.h"
#include "llist.h"
#include "xfmem.h"
#include "thread.h"
#include "cron.h"

static llist *job = NULL;
static xfmem_t  *space; 
static pthread_mutex_t cron_mutex;
static int up_cron;


static time_t  TargetTime;

#define  SECONDS_PER_MINUTE     60 
#define  MAX_COMMAND          1000 
#define EOL -1
#define OK   0

/* Cron Timer -------------------------------------------*/
static void cron_sync (void)
{
  struct tm	*tm;

  TargetTime = time((time_t*)0);
  tm = localtime(&TargetTime);
  TargetTime += (SECONDS_PER_MINUTE - tm->tm_sec);
}

static void cron_sleep (void)
{
  int	seconds_to_wait;

  seconds_to_wait = (int) (TargetTime - time((time_t*)0));
  sleep((unsigned int) seconds_to_wait);
}

void cron_get_time (cron_time *tct)
{
  struct tm *tm;
  time_t now;

  now = time((time_t*)0);
  tm = localtime(&now);
  tct->minute = tm->tm_min -  FIRST_MINUTE;
  tct->hour   = tm->tm_hour - FIRST_HOUR;
  tct->dom    = tm->tm_mday - FIRST_DOM;
  tct->month  = tm->tm_mon + 1 /* 0..11 -> 1..12 */ - FIRST_MONTH;
  tct->dow    = tm->tm_wday - FIRST_DOW;
}

int cron_check_time (cron_time *t, cron *c)
{
  /* the dom/dow situation is odd.  '* * 1,15 * Sun' will run on the
   * first and fifteenth AND every Sunday;  '* * * * Sun' will run *only*
   * on Sundays;  '* * 1,15 * *' will run *only* the 1st and 15th.  this
   * is why we keep 'e->dow_star' and 'e->dom_star'.  yes, it's bizarre.
   * like many bizarre things, it's the standard.
   */
  if (!up_cron) return -1;

  if (bit_test(c->minute, t->minute)
  && bit_test(c->hour, t->hour)
  && bit_test(c->month, t->month)
  && (((c->flags & DOM_STAR) || (c->flags & DOW_STAR))
          ? (bit_test(c->dow,t->dow) && bit_test(c->dom,t->dom))
          : (bit_test(c->dow,t->dow) || bit_test(c->dom,t->dom)))) {
     return 1;
 }
 return 0;
}


static void cron_tick (void)
{
  struct tm *tm;
  cron_time  tct;
  cron_func *func; 

  /* make 0-based values out of these so we can use them as indicies
   */
  tm = localtime(&TargetTime); 
  tct.minute = tm->tm_min  - FIRST_MINUTE;
  tct.hour   = tm->tm_hour - FIRST_HOUR;
  tct.dom    = tm->tm_mday - FIRST_DOM;
  tct.month  = tm->tm_mon + 1 /* 0..11 -> 1..12 */ - FIRST_MONTH;
  tct.dow    = tm->tm_wday - FIRST_DOW;

  pthread_mutex_lock(&cron_mutex);
  for (func = llist_get_first(job);  func != NULL; func = llist_get_next(job)) {
    func->job(&tct, func->user);
  }
  pthread_mutex_unlock(&cron_mutex);
}


/* cron entry -------------------------------------*/
static int get_char (char **cmd)
{
  int   ch;
  ch = *(*cmd)++;
  if ((ch == ' ') || (ch == '\t')) {
    do {
      ch = *(*cmd)++;
    } while ((ch == ' ') || (ch == '\t'));
    (*cmd)--;
    ch = ' ';
  }
  if (!ch) ch = EOL;
  return ch;
}


static int get_string (char *string, int size, char **cmd, char *terms)
{
  int  ch;

  while (EOL != (ch = get_char(cmd)) && !strchr(terms, ch)) {
    if (size > 1) {
      *string++ = (char)ch;
      size--;
    }
  }

  if (size > 0)
    *string = '\0';
  return ch;
}

static int set_element (unsigned char *bits, int low, int high, int number)
{
#ifdef CRON_DEBUG
  printf("set_element(?,%d,%d,%d)\n", low, high, number);
#endif

  if (number < low || number > high)
    return EOL;

  bit_set(bits, (number-low));
  return OK;
}

#define  MAX_TEMPSTR         100
static char get_number (int *numptr, int ch, char **cmd)
{
  char  temp[MAX_TEMPSTR], *pc;
  int   len, all_digits;;

  pc = temp;
  len = 0;
  all_digits = 1;
  /* first look for a number */
  while (IsDigit((unsigned char)ch)) {
    if (++len >= MAX_TEMPSTR) return EOL;
    *pc++ = ch;
    if (!IsDigit(ch))
      all_digits = 0;
    ch = get_char(cmd);
  }
  *pc = '\0';

  if (all_digits) {
    *numptr = atoi(temp);
    return ch;
  }
  return EOL;
}

/* range = number | number "-" number [ "/" number ] */
static char get_range (unsigned char *bits, int low, int high, int ch, char **cmd)
{
  register int  i;
  auto int num1, num2;

  if (ch == '*') {
    /* '*' means "first-last" but can still be modified by /step */
    num1 = low;
    num2 = high;
    if (EOL == (ch = get_char(cmd))) return EOL;
  } else {
    if (EOL == (ch = get_number(&num1, ch, cmd))) return EOL;

    if (ch != '-') {
      /* not a range, it's a single number.  */
      if (EOL == set_element(bits, low, high, num1)) return EOL;
      return ch;
    } else {
      /* eat the dash */
      if (EOL == (ch = get_char(cmd))) return EOL;

      /* get the number following the dash */
      if (EOL == (ch = get_number(&num2, ch, cmd))) return EOL;
    }
  }

  if (num1 == num2) {
    if (EOL == set_element(bits, low, high, num1)) return EOL;
  } else 
  if (num1 < num2) {
    for (i = num1;  i <= num2;  i++)
      if (EOL == set_element(bits, low, high, i)) return EOL;
  }
  else {
    for (i = num1;  i <= high;  i++)
      if (EOL == set_element(bits, low, high, i)) return EOL;
    for (i = low;  i <= num2;  i++)
      if (EOL == set_element(bits, low, high, i)) return EOL;
  }
  return ch;
}

static int get_list (unsigned char *bits, int low, int high, int ch, char **cmd)
{
  /* list = range {"," range} */
  /* clear the bit string, since the default is 'off'.  */
  bit_nclear(bits, 0, (high-low+1));

  /* process all ranges */
  while (1) {
    ch = get_range(bits, low, high, ch, cmd);
    if (ch == ',') ch = get_char(cmd);
    else           break;
  }
  Skip_Nonblanks(ch, cmd)
  Skip_Blanks(ch, cmd)
  return ch;
}



/* Cron --------------------------------------------------*/
int cron_set_time (cron *e, char *cmd)
{
  int  ch, rv = 0;
  
  if (!up_cron) return -10;

  pthread_mutex_lock(&cron_mutex);

  ch = get_char(&cmd);
  if (ch == EOL) { rv = -1; goto end_set; }

  if (ch == '@') {
    ch = get_string(cmd, MAX_COMMAND, &cmd, " \t\n");
    if (!strcmp("reboot", cmd)) {
      e->flags |= WHEN_REBOOT;
    } else if (!strcmp("yearly", cmd) || !strcmp("annually", cmd)){
      bit_set(e->minute, 0);
      bit_set(e->hour, 0);
      bit_set(e->dom, 0);
      bit_set(e->month, 0);
      bit_nset(e->dow, 0, DOW_COUNT);
      e->flags |= DOW_STAR;
    } else if (!strcmp("monthly", cmd)) {
      bit_set(e->minute, 0);
      bit_set(e->hour, 0);
      bit_set(e->dom, 0);
      bit_nset(e->month, 0, MONTH_COUNT);
      bit_nset(e->dow, 0, DOW_COUNT);
      e->flags |=  DOW_STAR;
    } else if (!strcmp("weekly", cmd)) {
      bit_set(e->minute, 0);
      bit_set(e->hour, 0);
      bit_nset(e->dom, 0, DOM_COUNT);
      bit_nset(e->month, 0, MONTH_COUNT);
      bit_set(e->dow, 0);
      e->flags |= DOM_STAR;
    } else if (!strcmp("daily", cmd) || !strcmp("midnight", cmd)) {
      bit_set(e->minute, 0);
      bit_set(e->hour, 0);
      bit_nset(e->dom, 0, DOM_COUNT);
      bit_nset(e->month, 0, MONTH_COUNT);
      bit_nset(e->dow, 0, DOW_COUNT);
    } else if (!strcmp("hourly", cmd)) {
      bit_set(e->minute, 0);
      bit_nset(e->hour, 0, HOUR_COUNT);
      bit_nset(e->dom, 0, DOM_COUNT);
      bit_nset(e->month, 0, MONTH_COUNT);
      bit_nset(e->dow, 0, DOW_COUNT);
    } else {
       rv =  -2;
       goto end_set;
    }
    Skip_Blanks(ch, &cmd);
    if (ch == EOL || ch == '\n') {
      rv = -3;
      goto end_set;
    }
  } else {
    /* minutes */
    ch = get_list(e->minute, FIRST_MINUTE, LAST_MINUTE, ch, &cmd);
    if (ch == EOL) { rv = -4; goto end_set; }

    /* hours */
    ch = get_list(e->hour, FIRST_HOUR, LAST_HOUR, ch, &cmd);
    if (ch == EOL) { rv = -5; goto end_set; }

    /* DOM (days of month) */
    if (ch == '*') e->flags |= DOM_STAR;
    ch = get_list(e->dom, FIRST_DOM, LAST_DOM, ch, &cmd);
    if (ch == EOL) { rv = -5; goto end_set; }

    /* month */
    ch = get_list(e->month, FIRST_MONTH, LAST_MONTH, ch, &cmd);
    if (ch == EOL) { rv = -6; goto end_set; }
    
    /* DOW (days of week) */
    if (ch == '*') e->flags |= DOW_STAR;
    ch = get_list(e->dow, FIRST_DOW, LAST_DOW, ch, &cmd);
  
    /* make sundays equivilent */
    if (bit_test(e->dow, 0) || bit_test(e->dow, 7)) {
      bit_set(e->dow, 0);
      bit_set(e->dow, 7);
    }
  }
end_set:
  pthread_mutex_unlock(&cron_mutex);
  return rv;
}

cron_func *cron_add_job (job_func func, void *user)
{
  cron_func *cf;

  if (up_cron) {
    pthread_mutex_lock(&cron_mutex);
    cf = (cron_func  *)xfmem_malloc(space); 
    cf->job = func;
    cf->user = user;
    cf->idx = -1;
    llist_append(job, cf);
    pthread_mutex_unlock(&cron_mutex);
    return cf;
  }
  return NULL;
}

void cron_del_job (cron_func *cfunc)
{
  if (up_cron) {
    pthread_mutex_lock(&cron_mutex);
    llist_remove(job, cfunc);
    xfmem_free(space, cfunc);
    pthread_mutex_unlock(&cron_mutex);
  }
}

int cron_add_job_idx (job_func func, void *user, int idx)
{
  if (up_cron) {
    cron_func  *cf;
    cf = llist_get_first(job);
    if (cf) do {
      if (cf->idx == idx) return 0;;
    } while ((cf = llist_get_next(job)));
      
    pthread_mutex_lock(&cron_mutex);
    cf = (cron_func  *)xfmem_malloc(space);
    cf->job = func;
    cf->user = user;
    cf->idx = idx;
    llist_append(job, cf);
    pthread_mutex_unlock(&cron_mutex);
    return 1;
  }
  return 0;
}

void *cron_del_job_idx (int idx)
{
  if (up_cron) {
    cron_func  *cf;
    void *user;
    cf = llist_get_first(job);
    if (cf) do {
      if (cf->idx == idx) {
        pthread_mutex_lock(&cron_mutex);
        llist_remove(job, cf);
        user = cf->user;
        xfmem_free(space, cf);
        pthread_mutex_unlock(&cron_mutex);
        return user;
      }
    } while ((cf = llist_get_next(job)));
  }
  return NULL;
}


static void *run_cron_timer (void *arg)
{
  ThreadAddTable(arg, 0, 0);

  cron_sync();

  while (1) {
    cron_sleep();
    cron_tick();
    cron_sync();
  }
  return NULL;
}

void cron_start (void)
{
  up_cron = 1;
  job = llist_create();
  space = xfmem_create(sizeof(cron_func), 0);
  pthread_mutex_init(&cron_mutex, NULL);
  ThreadCreate(run_cron_timer, (void *)"cron_start");
}

