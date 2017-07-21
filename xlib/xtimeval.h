#ifndef __XTIMEVAL_H__
#define __XTIMEVAL_H__
#include <sys/time.h>
#include <stdint.h>
#include "xtypes.h"

double xtimeval_get_ts(void);
void xgettimeofday (struct timeval *now);
void xclock_gettime (struct timespec *tp);

/* The time since [t] in seconds */
ub64 xseconds (struct timeval * t);

/* The time since [t] in milliseconds */
ub64 xmilliseconds (struct timeval * t);

/* The time since [t] in microseconds */
ub64 xmicroseconds (struct timeval * t);

/* The time difference in seconds */
ub64 xdelta_time_in_seconds (struct timeval * t2, struct timeval * t1);

/* The time difference in milliseconds */
ub64 xdelta_time_in_milliseconds (struct timeval *tv2, struct timeval *tv1); 

/* The time difference in microseconds */
ub64 xdelta_time_in_microseconds (struct timeval *tv2, struct timeval *tv1);

void xtimeval_add_usec (struct timeval *tv_out, const struct timeval *tv, const ub32 usec);
void xtimeval_sub_usec (struct timeval *tv_out, const struct timeval *tv, const ub32 usec);

#define xtimeval_isset(tvp)\
  ((tvp)->tv_sec || (tvp)->tv_usec)

/*  compares <t1> and <t2> : returns 0 if equal, -1 if t1 < t2, 1 if t1 > t2. */
int xtimeval_cmp (const struct timeval *t1,  const struct timeval *t2);

void xtimeval_add(struct timeval *rtv, const struct timeval *tv1, const struct timeval *tv2);
void xtimeval_subtract(struct timeval *rtv, const struct timeval *etv, const struct timeval *stv);

int  xtimeval_cmp_micro (const struct timeval *tv1,  const struct timeval *tv2);
ub64 xtimeval_add_micro(const struct timeval *tv1, const struct timeval *tv2);
ub64 xtimeval_subtract_micro (const struct timeval *etv, const struct timeval *stv);


void f2time (struct timeval *time, ub64 ftime);
void f2addtime (struct timeval *time, ub64 ftime);
void f2subtime (struct timeval *time, ub64 ftime);
void double2timespec (double seconds, struct timespec *ts_sleep);

ub64 xdelta_time (struct timeval *now, struct timeval *before);

/* number of microseconds per second */
#define SECS_PER_DAY   86400
#define SECS_PER_HOUR  3600
#define SECS_PER_MIN   60


typedef uint64_t usec_t;
typedef uint64_t nsec_t;

#define MSEC_PER_SEC  1000ULL
#define USEC_PER_SEC  1000000ULL
#define USEC_PER_MSEC 1000ULL
#define NSEC_PER_SEC  1000000000ULL
#define NSEC_PER_MSEC 1000000ULL
#define NSEC_PER_USEC 1000ULL

#define USEC_PER_MINUTE (60ULL*USEC_PER_SEC)
#define NSEC_PER_MINUTE (60ULL*NSEC_PER_SEC)
#define USEC_PER_HOUR   (60ULL*USEC_PER_MINUTE)
#define NSEC_PER_HOUR   (60ULL*NSEC_PER_MINUTE)
#define USEC_PER_DAY    (24ULL*USEC_PER_HOUR)
#define NSEC_PER_DAY    (24ULL*NSEC_PER_HOUR)
#define USEC_PER_WEEK   (7ULL*USEC_PER_DAY)
#define NSEC_PER_WEEK   (7ULL*NSEC_PER_DAY)
#define USEC_PER_MONTH  (2629800ULL*USEC_PER_SEC)
#define NSEC_PER_MONTH  (2629800ULL*NSEC_PER_SEC)
#define USEC_PER_YEAR   (31557600ULL*USEC_PER_SEC)
#define NSEC_PER_YEAR   (31557600ULL*NSEC_PER_SEC)

#define FORMAT_TIMESTAMP_MAX ((4*4+1)+11+9+4+1) /* weekdays can be unicode */
#define FORMAT_TIMESTAMP_RELATIVE_MAX 256
#define FORMAT_TIMESPAN_MAX 64

int parse_timestamp(const char *t, usec_t *usec);

/* Number of microseconds since 00:00:00 January 1, 1970 UTC */
ub64 xtime_now (void);

/* Return time in microseconds */
time_t xtime_usec (time_t t);

/* Return time in milliseconds */
int xtime_msec (time_t t);

/* Return time in seconds */
int xtime_sec (time_t t);

/* Return time in minutes */
int xtime_min (time_t t);

/* Return time in hours */
int xtime_hour (time_t t);

/* Return time in days */
int xtime_day (time_t t);

/* Days In Seconds */
int xdays (time_t t1, time_t t2);

/* Hours In Seconds */
int xhours (time_t t1, time_t t2);

/* Minutes In Seconds */
int xmins (time_t t1, time_t t2);

/* Return a well formatted string with a time difference at millisecond resolution */
char *xelapsed_time (struct timeval * start, struct timeval * stop);

/* Well formatted percentage */
char *xpercentage_str (ub64 partial, ub64 total);
float xpercentage (ub64 partial, ub64 total);

char *xtimeval_time (struct timeval *tv);
char *xtimeval_date (struct timeval *tv);

char *xtimeval_percentage_str (struct timeval *st, struct timeval *et, struct timeval *ut);
float xtimeval_percentage (struct timeval *st, struct timeval *et, struct timeval *ut);
int xusleep (unsigned long sleep_usecs);

/*
 * compares <tv1> and <tv2> : returns 1 if <tv1> is before <tv2>, otherwise 0.
 * This should be very fast because it's used in schedulers.
 * It has been optimized to return 1  (so call it in a loop which continues
 * as long as tv1<=tv2)
 */

#define tv_isbefore(tv1, tv2)                                               \
        (unlikely((unsigned)(tv1)->tv_sec < (unsigned)(tv2)->tv_sec) ? 1 :  \
         (unlikely((unsigned)(tv1)->tv_sec > (unsigned)(tv2)->tv_sec) ? 0 : \
          unlikely((unsigned)(tv1)->tv_usec < (unsigned)(tv2)->tv_usec)))

/*
 * returns the first event between <tv1> and <tv2> into <tvmin>.
 * a zero tv is ignored. <tvmin> is returned. If <tvmin> is known
 * to be the same as <tv1> or <tv2>, it is recommended to use
 * tv_bound instead.
 */
#define tv_min(tvmin, tv1, tv2) ({      \
        if (tv_isbefore(tv1, tv2)) {    \
                *tvmin = *tv1;          \
        }                               \
        else {                          \
                *tvmin = *tv2;          \
        }                               \
        tvmin;                          \
}) 
 
/*
 * returns the first event between <tv1> and <tv2> into <tvmin>.
 * a zero tv is ignored. <tvmin> is returned. This function has been
 * optimized to be called as tv_min(a,a,b) or tv_min(b,a,b).
 */     
#define tv_bound(tv1, tv2) ({      \
        if (tv_isbefore(tv2, tv1)) \
                  *tv1 = *tv2;     \
        tv1;                       \
})

struct timeval timespec_to_timeval (const struct timespec *ts);

int gmt2local (time_t t);
char *convert_date (time_t current_sec);
time_t convert_long_time(int nYear, int nMonth, int nDay, int nHour);
#endif
