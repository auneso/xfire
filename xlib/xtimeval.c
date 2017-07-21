/*
** 2015-05-07  HDS f2addtime, f2subtime correct
** 2015-10-28  HDS update xtimeval_subtract_micro
** 2016-07-11  HDS update xtimeval_subtract_micro
*/
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>

#include "xprintf.h"
#include "format.h"
#include "xtimeval.h"

/*
 * compares <tv1> and <tv2> : returns 0 if equal, -1 if tv1 < tv2, 1 if tv1 > tv2
 * Must not be used when either argument is eternity. Use tv_cmp2() for that.
 */
static inline int xtv_cmp (const struct timeval *tv2, const struct timeval *tv1)
{
  if (tv2->tv_sec > tv1->tv_sec) return 1;
  else if (tv2->tv_sec < tv1->tv_sec) return -1;
  else {
    if (tv2->tv_usec > tv1->tv_usec) return 1;
    else if (tv2->tv_usec < tv1->tv_usec) return -1;
  }
  return 0;
}

double xtimeval_get_ts(void)
{
  struct timeval ts;
  struct timezone tz;

  if (gettimeofday(&ts, &tz) == -1)
    return 0;

  return (double)ts.tv_sec + ((double)ts.tv_usec)/USEC_PER_SEC + (double)(tz.tz_minuteswest * 60);
}

void xgettimeofday (struct timeval *now)
{
  struct timespec tp;
  clock_gettime(CLOCK_REALTIME, &tp);
  now->tv_sec  = tp.tv_sec;
  now->tv_usec = tp.tv_nsec / USEC_PER_MSEC;
}

void xclock_gettime (struct timespec *tp)
{
  clock_gettime(CLOCK_REALTIME, tp);
}

/* The time since [t] in seconds */
ub64 xseconds (struct timeval * t)
{
  return t->tv_sec + t->tv_usec / USEC_PER_SEC;
}

/* The time since [t] in milliseconds */
ub64 xmilliseconds (struct timeval * t)
{
  return t->tv_sec * USEC_PER_MSEC + t->tv_usec / USEC_PER_MSEC;
}

/* The time since [t] in microseconds */
ub64 xmicroseconds (struct timeval * t)
{
  return t->tv_sec * USEC_PER_SEC + t-> tv_usec;
}

/* The time difference in milliseconds */
ub64 xdelta_time_in_milliseconds (struct timeval *tv2, struct timeval *tv1)
{
  return xtimeval_subtract_micro (tv2, tv1) / USEC_PER_MSEC;
}

/* The time difference in seconds */
ub64 xdelta_time_in_seconds (struct timeval *tv2, struct timeval *tv1)
{
  return xtimeval_subtract_micro (tv2, tv1) / USEC_PER_SEC;
}

/* The time difference in microseconds */
ub64 xdelta_time_in_microseconds (struct timeval *tv2, struct timeval *tv1)
{
  return xtimeval_subtract_micro (tv2, tv1);
}


/* Return the difference of two time_structs in seconds */
double xtime_diff_second (struct timeval *pStart, struct timeval *pEnd)
{
  return (pEnd->tv_usec - pStart->tv_usec) / USEC_PER_SEC + (double)(pEnd->tv_sec - pStart->tv_sec);
}

int xtimeval_cmp_micro (const struct timeval *tv2,  const struct timeval *tv1)
{
  return xtv_cmp(tv2, tv1);
}

ub64 xtimeval_add_micro (const struct timeval *tv1, const struct timeval *tv2)
{
  return (((ub64)tv1->tv_sec * USEC_PER_SEC + tv1-> tv_usec) + ((ub64)tv2->tv_sec * USEC_PER_SEC + tv2-> tv_usec));
}

ub64 xtimeval_subtract_micro (const struct timeval *tv2, const struct timeval *tv1)
{
  int cmp;
  ub64 ret;

  cmp = xtv_cmp(tv2, tv1);
  if (!cmp) return 0; /* same dates, null diff */
  else if (cmp < 0) {
    const struct timeval *tmp = tv2;
    tv2 = tv1;
    tv1 = tmp;
  }
  
  ret = (tv2->tv_sec - tv1->tv_sec) * USEC_PER_SEC + (tv2->tv_usec - tv1->tv_usec);
  return ret;
}

void xtimeval_add_usec (struct timeval *tv_out, const struct timeval *tv, const ub32 usec)
{
  tv_out->tv_sec  = tv->tv_sec + usec / USEC_PER_SEC;
  tv_out->tv_usec = tv->tv_usec + usec % USEC_PER_SEC;
}

void xtimeval_sub_usec (struct timeval *tv_out, const struct timeval *tv, const ub32 usec)
{
  tv_out->tv_sec  = tv->tv_sec - usec / USEC_PER_SEC;
  tv_out->tv_usec = tv->tv_usec - usec % USEC_PER_SEC;
}

float xpercentage (ub64 partial, ub64 total)
{
  if (partial && total)
    return (float)((double)partial * 100 / (double)total);
  else return 0.0;  
}


int xtimeval_cmp (const struct timeval *tv1,  const struct timeval *tv2)
{
  ub64 mc2 = (ub64)tv2->tv_sec * USEC_PER_SEC + tv2-> tv_usec;
  ub64 mc1 = (ub64)tv1->tv_sec * USEC_PER_SEC + tv1-> tv_usec;
  return mc1 - mc2;
}

void xtimeval_add (struct timeval *tv_out, const struct timeval *tv1, const struct timeval *tv2)
{
  tv_out->tv_sec  = tv1->tv_sec + tv2->tv_sec;
  tv_out->tv_usec = tv1->tv_usec + tv2->tv_usec;
  
  if ((ub64)tv_out->tv_usec >= USEC_PER_SEC) {
     tv_out->tv_sec++;
     tv_out->tv_usec -= USEC_PER_SEC;
   }      
}


void xtimeval_subtract (struct timeval *tv_out, const struct timeval *tv2, const struct timeval *tv1)
{
  if (tv2->tv_sec < tv1->tv_sec || (tv2->tv_sec == tv1->tv_sec && tv2->tv_usec < tv1->tv_usec)) {
    tv_out->tv_sec  = 0;
    tv_out->tv_usec = 0;
    return;
  }

  tv_out->tv_sec = tv2->tv_sec - tv1->tv_sec;
  
  if (tv2->tv_usec < tv1->tv_usec) {
    if (tv_out->tv_sec == 0) {
      tv_out->tv_sec  = 0;
      tv_out->tv_usec = 0;
      return;
    }
    tv_out->tv_sec -= 1;
    tv_out->tv_usec = tv2->tv_usec + USEC_PER_SEC - tv1->tv_usec;      
  } else {
    tv_out->tv_usec  = tv1->tv_usec  - tv1->tv_usec;
  }
}

/*
 * The time difference in microseconds
 */
ub64 xdelta_time (struct timeval *now, struct timeval *before)
{
  time_t delta_seconds;
  time_t delta_microseconds;

  /*
   * compute delta in second, 1/10's and 1/1000's second units
   */
  delta_seconds      = now -> tv_sec  - before -> tv_sec;
  delta_microseconds = now -> tv_usec - before -> tv_usec;

  if (delta_microseconds < 0) {
    /* manually carry a one from the seconds field */
    delta_microseconds += USEC_PER_SEC;  /* 1e6 */
    --delta_seconds;
//    if (delta_seconds < 0) printf("delta_time error = %ld\n", delta_seconds);
  }

  return((ub64)((delta_seconds * USEC_PER_SEC) + delta_microseconds));
}


void f2time (struct timeval *time, ub64 ftime)
{
  time->tv_sec  = (time_t)ftime / USEC_PER_SEC;
  time->tv_usec = (time_t)ftime % USEC_PER_SEC;
}

void f2addtime (struct timeval *time, ub64 ftime)
{
  time->tv_sec  += (time_t)ftime / USEC_PER_SEC;
  time->tv_usec += (time_t)ftime % USEC_PER_SEC;
  if ((ub64)time->tv_usec >= USEC_PER_SEC) {
    time->tv_sec++;
    time->tv_usec -= USEC_PER_SEC;
  }      
}

void f2subtime (struct timeval *time, ub64 ftime)
{
  time_t usec;
  time->tv_sec  -= (time_t)ftime / USEC_PER_SEC;
  usec = (time_t)ftime % USEC_PER_SEC;
  if (time->tv_usec < usec) {
    time->tv_sec--;
    time->tv_usec = time->tv_usec + USEC_PER_SEC - usec; 
  } else {
    time->tv_usec -= usec;
  }
}

void double2timespec (double seconds, struct timespec *ts_sleep)
{
  double ns;
  ts_sleep->tv_sec = seconds;
  ns = 1e9 * (seconds - ts_sleep->tv_sec);
  ts_sleep->tv_nsec = ns;
  ts_sleep->tv_nsec += (ts_sleep->tv_nsec < ns);

  if (NSEC_PER_SEC <= (ub64)ts_sleep->tv_nsec) {
    time_t t = ts_sleep->tv_sec + 1;
    ts_sleep->tv_sec = t;
    ts_sleep->tv_nsec -= NSEC_PER_SEC;
  }
}

static inline uint64_t timespec64_to_ns (const struct timespec *ts)
{
  return ((uint64_t) ts->tv_sec * NSEC_PER_SEC) + ts->tv_nsec;
}

struct timeval timespec_to_timeval (const struct timespec *ts)
{
  struct timespec t_spec = {0, 0};
  struct timeval t_eval = {0, 0};
  int32_t rem;
  int64_t nsec = ((uint64_t) ts->tv_sec * NSEC_PER_SEC) + ts->tv_nsec;

  if (nsec == 0) 
    return t_eval;
  rem = nsec % NSEC_PER_SEC;
  t_spec.tv_sec = nsec / NSEC_PER_SEC;

  if (rem < 0) {
    t_spec.tv_sec--;
    rem += NSEC_PER_SEC;
  }     

  t_spec.tv_nsec = rem;
  t_eval.tv_sec = t_spec.tv_sec;
  t_eval.tv_usec = t_spec.tv_nsec / 1000; 

  return t_eval;
}

/* Number of microseconds since 00:00:00 January 1, 1970 UTC */
ub64 xtime_now (void)
{
  struct timeval now;
  gettimeofday (& now, NULL);
  return (ub64) now . tv_sec * USEC_PER_SEC + now . tv_usec;
}

/* Return time in microseconds */
time_t xtime_usec (time_t t)
{
  return (time_t) t % USEC_PER_SEC;
}

/* Return time in milliseconds */
int xtime_msec (time_t t)
{
  return t % MSEC_PER_SEC;
}

/* Return time in seconds */
int xtime_sec (time_t t)
{
  return (t / MSEC_PER_SEC) % SECS_PER_MIN;
}

/* Return time in minutes */
int xtime_min (time_t t)
{
  return (t / (MSEC_PER_SEC * 60)) % 60;
}

/* Return time in hours */
int xtime_hour (time_t t)
{
  return (t / (MSEC_PER_SEC * SECS_PER_HOUR)) % 24;
}

/* Return time in days */
int xtime_day (time_t t)
{
  return (t / (MSEC_PER_SEC * SECS_PER_DAY));
}

/* Days In Seconds */
int xdays (time_t t1, time_t t2)
{
  return (t2 - t1) / SECS_PER_DAY;
}

/* Hours In Seconds */
int xhours (time_t t1, time_t t2)
{
  return (t2 - t1 - (xdays (t1, t2) * SECS_PER_DAY)) / SECS_PER_HOUR;
}

/* Minutes In Seconds */
int xmins (time_t t1, time_t t2)
{
  return (t2 - t1 - (xdays (t1, t2) * SECS_PER_DAY) - (xhours (t1, t2) * SECS_PER_HOUR)) / SECS_PER_MIN;
}

/* Return a well formatted string with a time difference at millisecond resolution */
char *xelapsed_time (struct timeval *start, struct timeval *stop)
{
  static char et[64];

  time_t elapsed = xdelta_time_in_milliseconds (stop, start);

  if (xtime_day(elapsed))
    xsprintf (et, "%d days, %02d:%02d:%02d.%03ld",
             xtime_day (elapsed), xtime_hour (elapsed), xtime_min (elapsed), xtime_sec (elapsed), xtime_usec (elapsed));
  else if (xtime_hour (elapsed))
    xsprintf (et, "%02d:%02d:%02d.%03ld",
             xtime_hour (elapsed), xtime_min (elapsed), xtime_sec (elapsed), xtime_usec (elapsed));
  else if (xtime_min (elapsed))
    xsprintf (et, "%02d:%02d.%03ld", xtime_min (elapsed), xtime_sec (elapsed), xtime_usec (elapsed));
  else if (xtime_sec (elapsed))
    xsprintf (et, "%d.%03d secs", xtime_sec (elapsed), xtime_msec (elapsed));
  else
    xsprintf (et, "%3d msecs", xtime_msec (elapsed));

  return et;
}

char *xtimeval_time (struct timeval *tv)
{
  return fmt_msecond(xmilliseconds(tv));
}

char *xtimeval_date (struct timeval *ts)
{
  static char      sdate[16];
  int mt = ts->tv_usec % 100;
  struct tm *tv = localtime(&ts->tv_sec);
  xsnprintf(sdate, sizeof(sdate), "%02d:%02d:%02d.%02d", tv->tm_hour, tv->tm_min, tv->tm_sec, mt);
  return sdate;
}

char *xtimeval_percentage_str (struct timeval *st, struct timeval *et, struct timeval *ut)
{
  return xpercentage_str(xmicroseconds(ut), xdelta_time_in_microseconds(et, st));
}

float xtimeval_percentage (struct timeval *st, struct timeval *et, struct timeval *ut)
{
  float total = xdelta_time_in_microseconds(et, st);
  float partial = xmicroseconds(ut);

  if (partial > 0.009 && total) 
    return partial * 100 / total; 
  else return 0.0;
}

/* Well formatted percentage */
char *xpercentage_str (ub64 partial, ub64 total)
{
#define ITEMS 10
  static char buffer [ITEMS] [64];
  static short k = -1;
  float percent;

  k = (k + 1) % ITEMS;

  if (partial && total) {
    percent = (float)partial * 100 / (float)total;

    if (percent > 99.99)
      sprintf (buffer[k], "100.0%%");
    else if (percent >= 10.0)
      sprintf (buffer[k], "%.2f%%", percent); 
    else
      sprintf (buffer[k], "0%.2f%%", percent); 
  }
  else
    sprintf (buffer[k], "00.00%%");

  return buffer[k];
}

/* Thread-safe replacement for usleep. Argument must be a whole
 * number of microseconds to sleep.
 */
int xusleep (unsigned long sleep_usecs)
{
  struct timespec tv;
  tv.tv_sec = sleep_usecs / USEC_PER_SEC;
  tv.tv_nsec = (sleep_usecs % USEC_PER_SEC) * USEC_PER_MSEC;

  do {
    /* Sleep for the time specified in tv. If interrupted by a
     * signal, place the remaining time left to sleep back into tv.
     */
    if (0 == nanosleep(&tv, &tv)) 
      return 0;
  } while (errno == EINTR);
  return -1;
}

char *convert_date (time_t current_sec)
{
  static char      sTemp[32];
  struct tm        tmDate;

  if (current_sec == 0)
    current_sec = time(NULL);

  localtime_r(&current_sec, &tmDate);
  strftime(sTemp, sizeof(sTemp), "%Y/%m/%d-%H:%M:%S", &tmDate);

  return sTemp;
}


#if 0

#define TIME_ETERNITY       -1
/*
 * adds <ms> ms to <from>, set the result to <tv> and returns a pointer <tv>
 */
struct timeval *xtv_delayfrom (struct timeval *tv, struct timeval *from, int ms) 
{
  if (!tv || !from) return NULL;

  tv->tv_usec = from->tv_usec + (ms%1000)*1000;
  tv->tv_sec  = from->tv_sec  + (ms/1000);
  while (tv->tv_usec >= 1000000) {
    tv->tv_usec -= 1000000;
    tv->tv_sec++;
  }
  return tv;
}

/*
 * returns the absolute difference, in ms, between tv1 and tv2
 * Must not be used when either argument is eternity.
 */
long xtv_delta (struct timeval *tv1, struct timeval *tv2)
{
  int cmp;
  unsigned long ret;
  
  cmp = xtv_cmp(tv1, tv2);
  if (!cmp)
    return 0; /* same dates, null diff */
  else if (cmp < 0) {
    struct timeval *tmp = tv1;
    tv1 = tv2;
    tv2 = tmp;
  }
  ret = (tv1->tv_sec - tv2->tv_sec) * 1000;
  if (tv1->tv_usec > tv2->tv_usec)
    ret += (tv1->tv_usec - tv2->tv_usec) / 1000;
  else
    ret -= (tv2->tv_usec - tv1->tv_usec) / 1000;
  return (unsigned long) ret;
}

/*
 * returns the difference, in ms, between tv1 and tv2
 * Must not be used when either argument is eternity.
 */
static inline unsigned long xtv_diff(struct timeval *tv1, struct timeval *tv2) 
{
  unsigned long ret;
  
  ret = (tv2->tv_sec - tv1->tv_sec) * 1000;
  if (tv2->tv_usec > tv1->tv_usec)
    ret += (tv2->tv_usec - tv1->tv_usec) / 1000;
  else
    ret -= (tv1->tv_usec - tv2->tv_usec) / 1000;
  return (unsigned long) ret;
}

/*
 * compares <tv1> and <tv2> modulo 1ms: returns 0 if equal, -1 if tv1 < tv2, 1 if tv1 > tv2
 * Must not be used when either argument is eternity. Use tv_cmp2_ms() for that.
 */
int xtv_cmp_ms (struct timeval *tv1, struct timeval *tv2)
{
  if (tv1->tv_sec == tv2->tv_sec) {
    if (tv2->tv_usec >= tv1->tv_usec + 1000)
      return -1;
    else if (tv1->tv_usec >= tv2->tv_usec + 1000)
      return 1;
    else
      return 0;
  }
  else if ((tv2->tv_sec > tv1->tv_sec + 1) ||
       ((tv2->tv_sec == tv1->tv_sec + 1) && (tv2->tv_usec + 1000000 >= tv1->tv_usec + 1000)))
    return -1;
  else if ((tv1->tv_sec > tv2->tv_sec + 1) ||
       ((tv1->tv_sec == tv2->tv_sec + 1) && (tv1->tv_usec + 1000000 >= tv2->tv_usec + 1000)))
    return 1;
  else
    return 0;
}

/*
 * returns the remaining time between tv1=now and event=tv2
 * if tv2 is passed, 0 is returned.
 * Must not be used when either argument is eternity.
 */
static inline unsigned long xtv_remain (struct timeval *tv1, struct timeval *tv2)
{
  unsigned long ret;
  
  if (xtv_cmp_ms(tv1, tv2) >= 0)
    return 0; /* event elapsed */

  ret = (tv2->tv_sec - tv1->tv_sec) * 1000;
  if (tv2->tv_usec > tv1->tv_usec)
    ret += (tv2->tv_usec - tv1->tv_usec) / 1000;
  else
    ret -= (tv1->tv_usec - tv2->tv_usec) / 1000;
  return (unsigned long) ret;
}

/*
 * zeroes a struct timeval
 */

static inline struct timeval *xtv_eternity(struct timeval *tv)
{
  tv->tv_sec = tv->tv_usec = 0;
  return tv;
}

/*
 * returns 1 if tv is null, else 0
 */
static inline int xtv_iseternity (struct timeval *tv)
{
  if (tv->tv_sec == 0 && tv->tv_usec == 0) return 1;
  else return 0;
}

/*
 * compares <tv1> and <tv2> : returns 0 if equal, -1 if tv1 < tv2, 1 if tv1 > tv2,
 * considering that 0 is the eternity.
 */
int xtv_cmp2 (struct timeval *tv1, struct timeval *tv2)
{
  if (xtv_iseternity(tv1))
    if (xtv_iseternity(tv2))
      return 0; /* same */
    else
      return 1; /* tv1 later than tv2 */
  else if (xtv_iseternity(tv2))
    return -1; /* tv2 later than tv1 */
  
  if (tv1->tv_sec > tv2->tv_sec)
    return 1;
  else if (tv1->tv_sec < tv2->tv_sec)
    return -1;
  else if (tv1->tv_usec > tv2->tv_usec)
    return 1;
  else if (tv1->tv_usec < tv2->tv_usec)
    return -1;
  else
    return 0;
}

/*
 * compares <tv1> and <tv2> modulo 1 ms: returns 0 if equal, -1 if tv1 < tv2, 1 if tv1 > tv2,
 * considering that 0 is the eternity.
 */
int xtv_cmp2_ms (struct timeval *tv1, struct timeval *tv2)
{
  if (xtv_iseternity(tv1))
    if (xtv_iseternity(tv2))
      return 0; /* same */
    else
      return 1; /* tv1 later than tv2 */
  else if (xtv_iseternity(tv2))
    return -1; /* tv2 later than tv1 */
  
  if (tv1->tv_sec == tv2->tv_sec) {
    if (tv1->tv_usec >= tv2->tv_usec + 1000)
      return 1;
    else if (tv2->tv_usec >= tv1->tv_usec + 1000)
      return -1;
    else
      return 0;
  }
  else if ((tv1->tv_sec > tv2->tv_sec + 1) ||
       ((tv1->tv_sec == tv2->tv_sec + 1) && (tv1->tv_usec + 1000000 >= tv2->tv_usec + 1000)))
    return 1;
  else if ((tv2->tv_sec > tv1->tv_sec + 1) ||
       ((tv2->tv_sec == tv1->tv_sec + 1) && (tv2->tv_usec + 1000000 >= tv1->tv_usec + 1000)))
    return -1;
  else
    return 0;
}

/*
 * returns the remaining time between tv1=now and event=tv2
 * if tv2 is passed, 0 is returned.
 * Returns TIME_ETERNITY if tv2 is eternity.
 */
unsigned long xtv_remain2(struct timeval *tv1, struct timeval *tv2)
{
  unsigned long ret;

  if (xtv_iseternity(tv2)) return TIME_ETERNITY;

  if (xtv_cmp_ms(tv1, tv2) >= 0) return 0; /* event elapsed */

  ret = (tv2->tv_sec - tv1->tv_sec) * 1000;
  if (tv2->tv_usec > tv1->tv_usec)
    ret += (tv2->tv_usec - tv1->tv_usec) / 1000;
  else
    ret -= (tv1->tv_usec - tv2->tv_usec) / 1000;
  return (unsigned long) ret;
}

/*
 * returns the first event between tv1 and tv2 into tvmin.
 * a zero tv is ignored. tvmin is returned.
 */
inline struct timeval *
xtv_min (struct timeval *tvmin, struct timeval *tv1, struct timeval *tv2) 
{
  if (xtv_cmp2(tv1, tv2) <= 0) *tvmin = *tv1;
  else             *tvmin = *tv2;
  return tvmin;
}


/*
 * Returns the difference between gmt and local time in seconds.
 * Use gmtime() and localtime() to keep things simple.
 */
int gmt2local (time_t t)
{
  register int dt, dir;
  register struct tm *gmt, *loc;
  struct tm sgmt;

  if (t == 0) t = time(NULL);
  gmt = &sgmt;
  *gmt = *gmtime(&t);
  loc = localtime(&t);
  dt = (loc->tm_hour - gmt->tm_hour) * 60 * 60 + (loc->tm_min - gmt->tm_min) * 60;

  /*
   * If the year or julian day is different, we span 00:00 GMT
   * and must add or subtract a day. Check the year first to
   * avoid problems when the julian day wraps.
   */
  dir = loc->tm_year - gmt->tm_year;
  if (dir == 0)
    dir = loc->tm_yday - gmt->tm_yday;
  dt += dir * 24 * 60 * 60;

  return (dt);
}

time_t convert_long_time(int nYear, int nMonth, int nDay, int nHour)
{
  struct tm tm_ptr;
  time_t m_time;

  tm_ptr.tm_year  = nYear - 1900;
  tm_ptr.tm_mon   = nMonth - 1;
  tm_ptr.tm_mday  = nDay;
  tm_ptr.tm_hour  = nHour;
  tm_ptr.tm_min   = 0;
  tm_ptr.tm_sec   = 0;
  tm_ptr.tm_isdst = 0; //default 0

  m_time = mktime(&tm_ptr);

  return m_time;
}



/* 2014-10-01 util-linux-2.24/lib/timeutils.c */

#include <assert.h>
#define UL_BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))

#ifdef __GNUC__

/* &a[0] degrades to a pointer: a different type from an array */
# define __must_be_array(a) \
        UL_BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(__typeof__(a), __typeof__(&a[0])))

# define ignore_result(x) ({ \
        __typeof__(x) __dummy __attribute__((__unused__)) = (x); (void) __dummy; \
})

#else /* !__GNUC__ */
# define __must_be_array(a)     0
# define __attribute__(_arg_)
# define ignore_result(x) ((void) (x))
#endif /* !__GNUC__ */

#ifndef ARRAY_SIZE
# define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))
#endif

#define WHITESPACE " \t\n\r"

#define streq(a,b) (strcmp((a),(b)) == 0)

static const char *startswith(const char *s, const char *prefix)
{
  size_t sz = prefix ? strlen(prefix) : 0;

  if (s && sz && strncmp(s, prefix, sz) == 0)
    return s + sz;
  return NULL;
}
static inline const char *startswith_no_case(const char *s, const char *prefix)
{
  size_t sz = prefix ? strlen(prefix) : 0;

  if (s && sz && strncasecmp(s, prefix, sz) == 0)
    return s + sz;
  return NULL;
}
static const char *endswith(const char *s, const char *postfix)
{
  size_t sl = s ? strlen(s) : 0;
  size_t pl = postfix ? strlen(postfix) : 0;

  if (pl == 0)
    return (char *)s + sl;
  if (sl < pl)
    return NULL;
  if (memcmp(s + sl - pl, postfix, pl) != 0)
    return NULL;
  return (char *)s + sl - pl;
}

static int parse_sec(const char *t, usec_t *usec)
{
   static const struct {
    const char *suffix;
    usec_t usec;
   } table[] = {
    { "seconds",  USEC_PER_SEC },
    { "second",   USEC_PER_SEC },
    { "sec",      USEC_PER_SEC },
    { "s",        USEC_PER_SEC },
    { "minutes",  USEC_PER_MINUTE },
    { "minute",   USEC_PER_MINUTE },
    { "min",      USEC_PER_MINUTE },
    { "months",   USEC_PER_MONTH },
    { "month",    USEC_PER_MONTH },
    { "msec",     USEC_PER_MSEC },
    { "ms",       USEC_PER_MSEC },
    { "m",        USEC_PER_MINUTE },
    { "hours",    USEC_PER_HOUR },
    { "hour",     USEC_PER_HOUR },
    { "hr",       USEC_PER_HOUR },
    { "h",        USEC_PER_HOUR },
    { "days",     USEC_PER_DAY },
    { "day",      USEC_PER_DAY },
    { "d",        USEC_PER_DAY },
    { "weeks",    USEC_PER_WEEK },
    { "week",     USEC_PER_WEEK },
    { "w",        USEC_PER_WEEK },
    { "years",    USEC_PER_YEAR },
    { "year",     USEC_PER_YEAR },
    { "y",        USEC_PER_YEAR },
    { "usec",     1ULL },
    { "us",       1ULL },
    { "",         USEC_PER_SEC },  /* default is sec */
   };

  const char *p;
  usec_t r = 0;
  int something = FALSE;

  assert(t);
  assert(usec);

  p = t;
  for (;;) {
    long long l, z = 0;
    char *e;
    unsigned i, n = 0;

    p += strspn(p, WHITESPACE);

    if (*p == 0) {
      if (!something)
        return -EINVAL;

      break;
    }

    errno = 0;
    l = strtoll(p, &e, 10);

    if (errno > 0)
      return -errno;

    if (l < 0)
      return -ERANGE;

    if (*e == '.') {
      char *b = e + 1;

      errno = 0;
      z = strtoll(b, &e, 10);
      if (errno > 0)
        return -errno;

      if (z < 0)
        return -ERANGE;

      if (e == b)
        return -EINVAL;

      n = e - b;

    } else if (e == p)
      return -EINVAL;

    e += strspn(e, WHITESPACE);

    for (i = 0; i < ARRAY_SIZE(table); i++)
      if (startswith(e, table[i].suffix)) {
        usec_t k = (usec_t) z * table[i].usec;

        for (; n > 0; n--)
          k /= 10;

        r += (usec_t) l *table[i].usec + k;
        p = e + strlen(table[i].suffix);

        something = TRUE;
        break;
      }

    if (i >= ARRAY_SIZE(table))
      return -EINVAL;

  }

  *usec = r;

  return 0;
}

int parse_timestamp (const char *t, usec_t *usec)
{
   static const struct {
    const char *name;
    const int nr;
   } day_nr[] = {
    { "Sunday",  0 },
    { "Sun",  0 },
    { "Monday",  1 },
    { "Mon",  1 },
    { "Tuesday",  2 },
    { "Tue",  2 },
    { "Wednesday",  3 },
    { "Wed",  3 },
    { "Thursday",  4 },
    { "Thu",  4 },
    { "Friday",  5 },
    { "Fri",  5 },
    { "Saturday",  6 },
    { "Sat",  6 },
   };

  const char *k;
  struct tm tm, copy;
  time_t x;
  usec_t plus = 0, minus = 0, ret;
  int r, weekday = -1;
  unsigned i;

  /*
   * Allowed syntaxes:
   *
   *   2012-09-22 16:34:22
   *   2012-09-22 16:34    (seconds will be set to 0)
   *   2012-09-22          (time will be set to 00:00:00)
   *   16:34:22            (date will be set to today)
   *   16:34               (date will be set to today, seconds to 0)
   *   now
   *   yesterday           (time is set to 00:00:00)
   *   today               (time is set to 00:00:00)
   *   tomorrow            (time is set to 00:00:00)
   *   +5min
   *   -5days
   *
   */

  assert(t);
  assert(usec);

  x = time(NULL);
  localtime_r(&x, &tm);
  tm.tm_isdst = -1;

  if (streq(t, "now"))
    goto finish;

  else if (streq(t, "today")) {
    tm.tm_sec = tm.tm_min = tm.tm_hour = 0;
    goto finish;

  } else if (streq(t, "yesterday")) {
    tm.tm_mday--;
    tm.tm_sec = tm.tm_min = tm.tm_hour = 0;
    goto finish;

  } else if (streq(t, "tomorrow")) {
    tm.tm_mday++;
    tm.tm_sec = tm.tm_min = tm.tm_hour = 0;
    goto finish;

  } else if (t[0] == '+') {

    r = parse_sec(t + 1, &plus);
    if (r < 0)
      return r;

    goto finish;
  } else if (t[0] == '-') {

    r = parse_sec(t + 1, &minus);
    if (r < 0)
      return r;

    goto finish;

  } else if (endswith(t, " ago")) {
    char *z;

    z = strndup(t, strlen(t) - 4);
    if (!z)
      return -ENOMEM;

    r = parse_sec(z, &minus);
    if (r < 0)
      return r;

    goto finish;
  }

  for (i = 0; i < ARRAY_SIZE(day_nr); i++) {
    size_t skip;

    if (!startswith_no_case(t, day_nr[i].name))
      continue;

    skip = strlen(day_nr[i].name);
    if (t[skip] != ' ')
      continue;

    weekday = day_nr[i].nr;
    t += skip + 1;
    break;
  }

  copy = tm;
  k = strptime(t, "%y-%m-%d %H:%M:%S", &tm);
  if (k && *k == 0)
    goto finish;

  tm = copy;
  k = strptime(t, "%Y-%m-%d %H:%M:%S", &tm);
  if (k && *k == 0)
    goto finish;

  tm = copy;
  k = strptime(t, "%y-%m-%d %H:%M", &tm);
  if (k && *k == 0) {
    tm.tm_sec = 0;
    goto finish;
  }

  tm = copy;
  k = strptime(t, "%Y-%m-%d %H:%M", &tm);
  if (k && *k == 0) {
    tm.tm_sec = 0;
    goto finish;
  }

  tm = copy;
  k = strptime(t, "%y-%m-%d", &tm);
  if (k && *k == 0) {
    tm.tm_sec = tm.tm_min = tm.tm_hour = 0;
    goto finish;
  }

  tm = copy;
  k = strptime(t, "%Y-%m-%d", &tm);
  if (k && *k == 0) {
    tm.tm_sec = tm.tm_min = tm.tm_hour = 0;
    goto finish;
  }

  tm = copy;
  k = strptime(t, "%H:%M:%S", &tm);
  if (k && *k == 0)
    goto finish;

  tm = copy;
  k = strptime(t, "%H:%M", &tm);
  if (k && *k == 0) {
    tm.tm_sec = 0;
    goto finish;
  }

  tm = copy;
  k = strptime(t, "%Y%m%d%H%M%S", &tm);
  if (k && *k == 0) {
    tm.tm_sec = 0;
    goto finish;
  }

  return -EINVAL;

finish:
  x = mktime(&tm);
  if (x == (time_t)-1)
    return -EINVAL;

  if (weekday >= 0 && tm.tm_wday != weekday)
    return -EINVAL;

  ret = (usec_t) x *USEC_PER_SEC;

  ret += plus;
  if (ret > minus)
    ret -= minus;
  else
    ret = 0;

  *usec = ret;

  return 0;
}
#endif
