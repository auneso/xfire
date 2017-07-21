/*
**  2009/01/07 - HDS 
**  2009/10/06 - HDS day_of_month_ago
**  2009/10/12 - HDS sec_of_month_ago
**  2009/11/27 - HDS month_ago
**  2010/06/24 - HDS week_ago, day_ago
*/
 
#include "tdate.h"

/* search-time.c - time handling utility functions
 * Copyright 2006-08 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors:
 *     Steve Grubb <sgrubb@redhat.com>
 */


time_t start_time = 0, end_time = 0;

struct nv_pair {
    int        value;
    const char *name;
};

static struct nv_pair timetab[] = {
  { T_NOW,        "now" },
  { T_RECENT,     "recent" },
  { T_TODAY,      "today" },
  { T_YESTERDAY,  "yesterday" },
  { T_TOMORROW,   "tomorrow" },
  { T_THIS_WEEK,  "this-week" },
  { T_WEEK_AGO,   "week-ago" },
  { T_THIS_MONTH, "this-month" },
  { T_THIS_YEAR,  "this-year" },
};
#define TIME_NAMES (int)(sizeof(timetab)/sizeof(timetab[0]))

int lookup_time (const char *name)
{
  int i;

  for (i = 0; i < TIME_NAMES; i++) {
    if (strcmp(timetab[i].name, name) == 0) {
      return timetab[i].value;
    }
  }
  return -1;
}

static void clear_tm (struct tm *t)
{
  t->tm_sec   = 0;       /* seconds */
  t->tm_min   = 0;       /* minutes */
  t->tm_hour  = 0;       /* hours */
  t->tm_mday  = 0;       /* day of the month */
  t->tm_mon   = 0;       /* month */
  t->tm_year  = 0;       /* year */
  t->tm_isdst = 0;       /* DST flag */
}

/* The time in t1 is replaced by t2 */
static void replace_time (struct tm *t1, struct tm *t2)
{
  t1->tm_sec  = t2->tm_sec;   /* seconds */
  t1->tm_min  = t2->tm_min;   /* minutes */
  t1->tm_hour = t2->tm_hour;  /* hours */
}

/* The date in t1 is replaced by t2 */
static void replace_date (struct tm *t1, struct tm *t2)
{
  t1->tm_mday  = t2->tm_mday;   /* day */
  t1->tm_mon   = t2->tm_mon;    /* month */
  t1->tm_year  = t2->tm_year;   /* year */
  t1->tm_isdst = t2->tm_isdst;  /* daylight savings time */
}
static void set_tm_now (struct tm *d)
{
  time_t t = time(NULL);
  struct tm *tv = localtime(&t);
  replace_time(d, tv);
  replace_date(d, tv);
}

static void set_tm_today (struct tm *d)
{
  time_t t = time(NULL);
  struct tm *tv = localtime(&t);
  d->tm_sec = 0;          /* seconds */
  d->tm_min = 0;          /* minutes */
  d->tm_hour = 0;         /* hours */
  replace_date(d, tv);
}

static void set_tm_yesterday (struct tm *d)
{
  time_t t = time(NULL) - (time_t)(SECONDS_IN_DAY);
  struct tm *tv = localtime(&t);
  d->tm_sec = 0;          /* seconds */
  d->tm_min = 0;          /* minutes */
  d->tm_hour = 0;         /* hours */
  replace_date(d, tv);
}

static void set_tm_tomorrow (struct tm *d)
{
  time_t t = time(NULL) + (time_t)(SECONDS_IN_DAY);
  struct tm *tv = localtime(&t);
  d->tm_sec = 0;          /* seconds */
  d->tm_min = 0;          /* minutes */
  d->tm_hour = 0;         /* hours */
  replace_date(d, tv);
}

static void set_tm_recent (struct tm *d)
{
  time_t t = time(NULL) - (time_t)(10*60); /* 10 minutes ago */
  struct tm *tv = localtime(&t);
  replace_time(d, tv);
  replace_date(d, tv);
}

static void set_tm_this_week (struct tm *d)
{
  time_t t = time(NULL);
  struct tm *tv = localtime(&t);
  d->tm_sec = 0;          /* seconds */
  d->tm_min = 0;          /* minutes */
  d->tm_hour = 0;         /* hours */
  t -= (time_t)(tv->tm_wday*SECONDS_IN_DAY);
  tv = localtime(&t);
  replace_date(d, tv);
}

static void set_tm_week_ago (struct tm *d)
{
  time_t t = time(NULL);
  struct tm *tv = localtime(&t);
  d->tm_sec = 0;          /* seconds */
  d->tm_min = 0;          /* minutes */
  d->tm_hour = 0;         /* hours */
  t -= (time_t)(7*SECONDS_IN_DAY);
  tv = localtime(&t);
  replace_date(d, tv);
}

static void set_tm_this_month (struct tm *d)
{
  time_t t = time(NULL);
  struct tm *tv = localtime(&t);
  d->tm_sec = 0;          /* seconds */
  d->tm_min = 0;          /* minutes */
  d->tm_hour = 0;         /* hours */
  replace_date(d, tv);
  d->tm_mday = 1;         /* override day of month */
}

static void set_tm_this_year (struct tm *d)
{
  time_t t = time(NULL);
  struct tm *tv = localtime(&t);
  d->tm_sec = 0;          /* seconds */
  d->tm_min = 0;          /* minutes */
  d->tm_hour = 0;         /* hours */
  replace_date(d, tv);
  d->tm_mday = 1;         /* override day of month */
  d->tm_mon = 0;          /* override month */
}

/* Combine date & time into 1 struct. Results in date. */
static void add_tm (struct tm *d, struct tm *t)
{
  time_t dst;
  struct tm *lt;

  replace_time(d, t);

  /* Now we need to figure out if DST is in effect */
  dst = time(NULL);
  lt = localtime(&dst);
  d->tm_isdst = lt->tm_isdst;
}


int days_in_a_month (int month, int year)
{
  static int t[]  = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  static int lt[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0))
    return(lt[month-1]);
  return(t[month-1]);
}

int day_of_the_week (int day, int month, int year)
{
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

  year -= month < 3;
  return((year + (year / 4) - (year / 100) + (year / 400) + (t[month-1]) + day) % 7);
}


static int lookup_and_set_time (const char *da, struct tm *d)
{
  int retval = lookup_time(da);

  if (retval >= 0) {
    switch (retval) {
      case T_NOW:
        set_tm_now(d);
        break;
      case T_RECENT:
        set_tm_recent(d);
        break;
      case T_TODAY:
        set_tm_today(d);
        break;
      case T_YESTERDAY:
        set_tm_yesterday(d);
        break;
      case T_TOMORROW:
        set_tm_tomorrow(d);
        break;
      case T_THIS_WEEK:
        set_tm_this_week(d);
        break;
      case T_WEEK_AGO:
        set_tm_week_ago(d);
        break;
      case T_THIS_MONTH:
        set_tm_this_month(d);
        break;
      case T_THIS_YEAR:
        set_tm_this_year(d);
        break;
    }
    return 0;
  } else
    return -1;
}


extern char *strptime (const char *s, const char *format, struct tm *tm);

/* If da == NULL, use current date */
/* If ti == NULL, then use midnight 00:00:00 */
int search_time_start (const char *da, const char *ti)
{
  int rc = 0;
  struct tm d, t;
  char *ret;

  if (da == NULL)
    set_tm_now(&d);
  else {
    if (lookup_and_set_time(da, &d) < 0) {
      ret = strptime(da, "%x", &d);
      if (ret == NULL) {
        fprintf(stderr, "Invalid start date (%s). Month, Day, and Year are required.\n", da);
        return 1;
      }
      if (*ret != 0) {
        fprintf(stderr, "Error parsing start date (%s)\n", da);
        return 1;
      }
    } else {
      int keyword = lookup_time(da);
      if (keyword == T_RECENT || keyword == T_NOW) {
        if (ti == NULL || strcmp(ti, "00:00:00") == 0)
          goto set_it;
      }
    }
  }

  if (ti != NULL) {
    char tmp_t[9];

    if (strlen(ti) <= 5) {
      snprintf(tmp_t, sizeof(tmp_t), "%s:00", ti);
    } else {
      tmp_t[0]=0;
      strncat(tmp_t, ti, sizeof(tmp_t)-1);
    }
    ret = strptime(tmp_t, "%X", &t);
    if (ret == NULL) {
      fprintf(stderr, "Invalid start time (%s). Hour, Minute, and Second are required.\n", ti);
      return 1;
    }
    if (*ret != 0) {
      fprintf(stderr, "Error parsing start time (%s)\n", ti);
      return 1;
    }
  } else
    clear_tm(&t);

  add_tm(&d, &t);
  if (d.tm_year < 104) {
    fprintf(stderr, "Error - year is %d\n", d.tm_year+1900);
    return -1;
  }
set_it:
  start_time = mktime(&d);
  if (start_time == -1) {
    fprintf(stderr, "Error converting start time\n");
    rc = -1;
  }
  return rc;
}

/* If date == NULL, use current date */
/* If ti == NULL, use current time */
int search_time_end (const char *da, const char *ti)
{
  int rc = 0;
  struct tm d, t;
  char *ret;

  if (da == NULL)
    set_tm_now(&d);
  else {
    if (lookup_and_set_time(da, &d) < 0) {
      ret = strptime(da, "%x", &d);
      if (ret == NULL) {
        fprintf(stderr, "Invalid end date (%s). Month, Day, and Year are required.\n", da);
        return 1;
      }
      if (*ret != 0) {
        fprintf(stderr, "Error parsing end date (%s)\n", da);
        return 1;
      }
    } else {
      int keyword = lookup_time(da);
      if (keyword == T_RECENT || keyword == T_NOW) {
        if (ti == NULL || strcmp(ti, "00:00:00") == 0)
          goto set_it;
      }
      // Special case today
      if (keyword == T_TODAY) {
        set_tm_now(&d);
        if (ti == NULL || strcmp(ti, "00:00:00") == 0)
          goto set_it;
      }
    }
  }

  if (ti != NULL) {
    char tmp_t[9];

    if (strlen(ti) <= 5) {
      snprintf(tmp_t, sizeof(tmp_t), "%s:00", ti);
    } else {
      tmp_t[0]=0;
      strncat(tmp_t, ti, sizeof(tmp_t)-1);
    }
    ret = strptime(tmp_t, "%X", &t);
    if (ret == NULL) {
      fprintf(stderr, "Invalid end time (%s). Hour, Minute, and Second are required.\n", ti);
      return 1;
    }
    if (*ret != 0) {
      fprintf(stderr, "Error parsing end time (%s)\n", ti);
      return 1;
    }
  } else {
    time_t tt = time(NULL);
    struct tm *tv = localtime(&tt);
    clear_tm(&t);
    t.tm_hour = tv->tm_hour;
    t.tm_min = tv->tm_min;
    t.tm_sec = tv->tm_sec;
    t.tm_isdst = tv->tm_isdst;

  }
  add_tm(&d, &t);
  if (d.tm_year < 104) {
    fprintf(stderr, "Error - year is %d\n", d.tm_year+1900);
    return -1;
  }
set_it:
  end_time = mktime(&d);
  if (end_time == -1) {
    fprintf(stderr, "Error converting end time\n");
    rc = -1;
  }
  return rc;
}

/* This is a stripped-down version of date_parse.c, available at
** http://www.acme.com/software/date_parse/
*/


struct strlong {
  char* s;
  long l;
};


static void
pound_case (char* str)
{
  for (; *str != '\0'; ++str) {
    if (isupper((int) *str))
      *str = tolower((int) *str);
  }
}

static int
strlong_compare (const void *v1, const void *v2)
{
  return strcmp(((struct strlong*) v1)->s, ((struct strlong*) v2)->s);
}


static int
strlong_search (char* str, struct strlong* tab, int n, long* lP)
{
  int i, h, l, r;

  l = 0;
  h = n - 1;
  for (;;) {
    i = (h + l) / 2;
    r = strcmp(str, tab[i].s);
    if (r < 0)
      h = i - 1;
    else if (r > 0)
      l = i + 1;
    else {
      *lP = tab[i].l;
      return 1;
    }
    if (h < l)
      return 0;
  }
}


static int
scan_wday (char* str_wday, long* tm_wdayP)
{
  static struct strlong wday_tab[] = {
  { "sun", 0 }, { "sunday",    0 },
  { "mon", 1 }, { "monday",    1 },
  { "tue", 2 }, { "tuesday",   2 },
  { "wed", 3 }, { "wednesday", 3 },
  { "thu", 4 }, { "thursday",  4 },
  { "fri", 5 }, { "friday",    5 },
  { "sat", 6 }, { "saturday",  6 },
  };
  static int sorted = 0;

  if (!sorted) {
    (void)qsort(wday_tab, sizeof(wday_tab)/sizeof(struct strlong),
                sizeof(struct strlong), strlong_compare);
    sorted = 1;
  }
  pound_case(str_wday);
  return strlong_search(str_wday, wday_tab, sizeof(wday_tab)/sizeof(struct strlong), tm_wdayP);
}


static int
scan_mon (char* str_mon, long* tm_monP)
{
  static struct strlong mon_tab[] = {
  { "jan", 0 },  { "january", 0 },
  { "feb", 1 },  { "february", 1 },
  { "mar", 2 },  { "march", 2 },
  { "apr", 3 },  { "april", 3 },
  { "may", 4 },
  { "jun", 5 },  { "june", 5 },
  { "jul", 6 },  { "july", 6 },
  { "aug", 7 },  { "august", 7 },
  { "sep", 8 },  { "september", 8 },
  { "oct", 9 },  { "october", 9 },
  { "nov", 10 }, { "november", 10 },
  { "dec", 11 }, { "december", 11 },
  };
  static int sorted = 0;

  if (!sorted) {
    (void) qsort(mon_tab, sizeof(mon_tab)/sizeof(struct strlong),
                 sizeof(struct strlong), strlong_compare);
    sorted = 1;
  }
  pound_case(str_mon);
  return strlong_search(str_mon, mon_tab, sizeof(mon_tab)/sizeof(struct strlong), tm_monP);
}


static int
is_leap (int year)
{
  return year % 400? (year % 100 ? (year % 4 ? 0 : 1) : 0) : 1;
}


/* Basically the same as mktime(). */
static time_t
tm_to_time (struct tm *tmP)
{
  time_t t;
  static int monthtab[12] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

  /* Years since epoch, converted to days. */
  t = (tmP->tm_year - 70) * 365;
  /* Leap days for previous years. */
  t += (tmP->tm_year - 69) / 4;
  /* Days for the beginning of this month. */
  t += monthtab[tmP->tm_mon];
  /* Leap day for this year. */
  if (tmP->tm_mon >= 2 && is_leap(tmP->tm_year + 1900))
    ++t;
  /* Days since the beginning of this month. */
  t += tmP->tm_mday - 1;  /* 1-based field */
  /* Hours, minutes, and seconds. */
  t = t * 24 + tmP->tm_hour;
  t = t * 60 + tmP->tm_min;
  t = t * 60 + tmP->tm_sec;

  return t;
}


time_t tdate_parse (char *str)
{
  struct tm tm;
  char *cp;
  char str_mon[500], str_wday[500];
  int tm_sec, tm_min, tm_hour, tm_mday, tm_year;
  long tm_mon, tm_wday;
  time_t t;

  /* Initialize. */
  (void) memset((char*) &tm, 0, sizeof(struct tm));

  /* Skip initial whitespace ourselves - sscanf is clumsy at this. */
  for (cp = str; *cp == ' ' || *cp == '\t'; ++cp)
    continue;

  /* And do the sscanfs.  WARNING: you can add more formats here,
  ** but be careful!  You can easily screw up the parsing of existing
  ** formats when you add new ones.  The order is important.
  */

  /* DD-mth-YY HH:MM:SS GMT */
  if (sscanf(cp, "%d-%400[a-zA-Z]-%d %d:%d:%d GMT",
             &tm_mday, str_mon, &tm_year, &tm_hour, &tm_min, &tm_sec) == 6
  && scan_mon(str_mon, &tm_mon))
  {
    tm.tm_mday = tm_mday;
    tm.tm_mon  = tm_mon;
    tm.tm_year = tm_year;
    tm.tm_hour = tm_hour;
    tm.tm_min  = tm_min;
    tm.tm_sec  = tm_sec;
  }
  else
  /* DD mth YY HH:MM:SS GMT */
  if (sscanf(cp, "%d %400[a-zA-Z] %d %d:%d:%d GMT",
             &tm_mday, str_mon, &tm_year, &tm_hour, &tm_min, &tm_sec) == 6
  && scan_mon(str_mon, &tm_mon))
  {
    tm.tm_mday = tm_mday;
    tm.tm_mon  = tm_mon;
    tm.tm_year = tm_year;
    tm.tm_hour = tm_hour;
    tm.tm_min  = tm_min;
    tm.tm_sec  = tm_sec;
  }
  else
  /* HH:MM:SS GMT DD-mth-YY */
  if (sscanf(cp, "%d:%d:%d GMT %d-%400[a-zA-Z]-%d",
             &tm_hour, &tm_min, &tm_sec, &tm_mday, str_mon, &tm_year) == 6
  && scan_mon(str_mon, &tm_mon))
  {
    tm.tm_hour = tm_hour;
    tm.tm_min  = tm_min;
    tm.tm_sec  = tm_sec;
    tm.tm_mday = tm_mday;
    tm.tm_mon  = tm_mon;
    tm.tm_year = tm_year;
  }
  else
  /* HH:MM:SS GMT DD mth YY */
  if (sscanf(cp, "%d:%d:%d GMT %d %400[a-zA-Z] %d",
             &tm_hour, &tm_min, &tm_sec, &tm_mday, str_mon, &tm_year) == 6
  && scan_mon(str_mon, &tm_mon))
  {
    tm.tm_hour = tm_hour;
    tm.tm_min  = tm_min;
    tm.tm_sec  = tm_sec;
    tm.tm_mday = tm_mday;
    tm.tm_mon  = tm_mon;
    tm.tm_year = tm_year;
  }
  else
  /* wdy, DD-mth-YY HH:MM:SS GMT */
  if (sscanf(cp, "%400[a-zA-Z], %d-%400[a-zA-Z]-%d %d:%d:%d GMT",
             str_wday, &tm_mday, str_mon, &tm_year, &tm_hour, &tm_min, &tm_sec) == 7
  && scan_wday(str_wday, &tm_wday) && scan_mon(str_mon, &tm_mon))
  {
    tm.tm_wday = tm_wday;
    tm.tm_mday = tm_mday;
    tm.tm_mon  = tm_mon;
    tm.tm_year = tm_year;
    tm.tm_hour = tm_hour;
    tm.tm_min  = tm_min;
    tm.tm_sec  = tm_sec;
  }
  else
  /* wdy, DD mth YY HH:MM:SS GMT */
  if (sscanf(cp, "%400[a-zA-Z], %d %400[a-zA-Z] %d %d:%d:%d GMT",
             str_wday, &tm_mday, str_mon, &tm_year, &tm_hour, &tm_min, &tm_sec) == 7
  && scan_wday(str_wday, &tm_wday) && scan_mon(str_mon, &tm_mon))
  {
    tm.tm_wday = tm_wday;
    tm.tm_mday = tm_mday;
    tm.tm_mon  = tm_mon;
    tm.tm_year = tm_year;
    tm.tm_hour = tm_hour;
    tm.tm_min  = tm_min;
    tm.tm_sec  = tm_sec;
  }
  else
  /* wdy mth DD HH:MM:SS GMT YY */
  if (sscanf(cp, "%400[a-zA-Z] %400[a-zA-Z] %d %d:%d:%d GMT %d",
             str_wday, str_mon, &tm_mday, &tm_hour, &tm_min, &tm_sec, &tm_year) == 7
  && scan_wday(str_wday, &tm_wday) && scan_mon(str_mon, &tm_mon))
  {
    tm.tm_wday = tm_wday;
    tm.tm_mon  = tm_mon;
    tm.tm_mday = tm_mday;
    tm.tm_hour = tm_hour;
    tm.tm_min  = tm_min;
    tm.tm_sec  = tm_sec;
    tm.tm_year = tm_year;
  }
  else
    return (time_t) -1;

  if (tm.tm_year > 1900)
    tm.tm_year -= 1900;
  else if (tm.tm_year < 70)
    tm.tm_year += 100;

  t = tm_to_time(&tm);

  return t;
}


/**
 *
 * xstrftime.c
 *
 * implements the ansi c function strftime()
 *
 * written 6 september 1989 by jim nutt
 * released into the public domain by jim nutt
 *
 * modified 21-Oct-89 by Rob Duff
 *
 * modified 08-Dec-04 by Tobi Oetiker (added %V)
 * modified 09-Oct-04 by HDS (added %k)
**/

#include <stddef.h>     /* for size_t */
#include <stdarg.h>     /* for va_arg */
#include <time.h>       /* for struct tm */

/* Define your own defaults in config.h if necessary */
#if defined(TZNAME_STD) && defined(TZNAME_DST)
char     *tzname_[2] = { TZNAME_STD, TZNAME_DST };
#else
#define tzname_ tzname
#endif

static char *k_day[] = {
    "일", "월", "화", "수", "목", "금", "토"
};

static char *a_day[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static char *l_day[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

static char *a_month[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static char *l_month[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};



const char *long_day_of_the_week (int day, int month, int year)
{
  if (day > days_in_a_month(month, year))
    return("ERROR");
  return(l_day[day_of_the_week(day, month, year)]);
}

const char *short_day_of_the_week (int day, int month, int year)
{
  if (day > days_in_a_month(month, year))
    return("ERROR");
  return(a_day[day_of_the_week(day, month, year)]);
}

const char *kr_day_of_the_week (int day, int month, int year)
{
  if (day > days_in_a_month(month, year))
    return("ERROR");
  return(k_day[day_of_the_week(day, month, year)]);
}

int day_of_month_ago (int month, int year, int ago_month)
{
  int i = 0, sd = 0, d, m;

  if (ago_month > 12) return -1;

  for (i = 0, m = month - 1; m > 0 && i < ago_month; m--, i++) {
    d = days_in_a_month(m, year);
    sd += d;
  }
  if (i < ago_month) {
    year--;
    m = ago_month - i;
    for (i = 0; i < m ; i++) {
      d = days_in_a_month(12-i, year);
      sd += d;
    }
  } 
  return sd;
}

int sec_of_month_ago (int month, int year, int ago_month)
{
  return day_of_month_ago(month, year, ago_month) * SECONDS_IN_DAY;
}

int month_ago (int *month, int *year, int ago_month)
{ 
  int i, y, m;
  
  if (*month < 1 || *month > 12) return -1;
   
  y = *year; m = *month;
  for (i = 0; i < ago_month; i++) {
    if (--m == 0) {
      y--; m = 12;
    }
  }
  *year = y; *month = m;
  return 0;
}     

void week_ago (int *sday, int *smonth, int *syear, int *eday, int *emonth, int *eyear)
{
  time_t t = time(NULL);
  struct tm *tv = localtime(&t);

  t -= (time_t)((tv->tm_wday+6)*SECONDS_IN_DAY);
  tv = localtime(&t);
  
  *sday   = tv->tm_mday;
  *smonth = tv->tm_mon + 1;
  *syear  = tv->tm_year + 1900;

  t += (time_t)(6*SECONDS_IN_DAY);
  tv = localtime(&t);
  
  *eday   = tv->tm_mday;
  *emonth = tv->tm_mon + 1;
  *eyear  = tv->tm_year + 1900;
}

void days_ago (int *day, int *month, int *year, int agoday)
{
  time_t t = time(NULL);
  struct tm *tv;

  t -= (time_t)(SECONDS_IN_DAY)*agoday;
  tv = localtime(&t);

  *day   = tv->tm_mday;
  *month = tv->tm_mon + 1;
  *year  = tv->tm_year + 1900;
}


void day_ago (int *day, int *month, int *year)
{
  days_ago(day, month, year, 1);
}


static char buf[26];

static void strfmt (char *str, const char *fmt, ...);

/**
 *
 * size_t xstrftime(char *str, *size_t maxs, *const char *fmt, *const struct tm *t)
 *
 *      this functions acts much like a sprintf for time/date output.
 *      given a pointer to an output buffer, a format string and a
 *      time, it copies the time to the output buffer formatted in
 *      accordance with the format string.  the parameters are used
 *      as follows:
 *
 *          str is a pointer to the output buffer, there should
 *          be at least maxs characters available at the address
 *          pointed to by str.
 *
 *          maxs is the maximum number of characters to be copied
 *          into the output buffer, included the '\0' terminator
 *
 *          fmt is the format string.  a percent sign (%) is used
 *          to indicate that the following character is a special
 *          format character.  the following are valid format
 *          characters:
 *
 *              %A      full weekday name (Monday)
 *              %a      abbreviated weekday name (Mon)
 *              %B      full month name (January)
 *              %b      abbreviated month name (Jan)
 *              %c      standard date and time representation
 *              %d      day-of-month (01-31)
 *              %H      hour (24 hour clock) (00-23)
 *              %I      hour (12 hour clock) (01-12)
 *              %j      day-of-year (001-366)
 *              %M      minute (00-59)
 *              %m      month (01-12)
 *              %p      local equivalent of AM or PM
 *              %S      second (00-59)
 *              %U      week-of-year, first day sunday (00-53)
 *              %W      week-of-year, first day monday (00-53)
 *              %V      ISO 8601 Week number 
 *              %w      weekday (0-6, sunday is 0)
 *              %X      standard time representation
 *              %x      standard date representation
 *              %Y      year with century
 *              %y      year without century (00-99)
 *              %Z      timezone name
 *              %%      percent sign
 *
 *      the standard date string is equivalent to:
 *
 *          %a %b %d %Y
 *
 *      the standard time string is equivalent to:
 *
 *          %H:%M:%S
 *
 *      the standard date and time string is equivalent to:
 *
 *          %a %b %d %H:%M:%S %Y
 *
 *      strftime_() returns the number of characters placed in the
 *      buffer, not including the terminating \0, or zero if more
 *      than maxs characters were produced.
 *
**/

size_t xstrftime (char *s, size_t maxs, const char *f, const struct tm *t)
{
  int       w, d;
  char     *p, *q, *r;

  p = s;
  q = s + maxs - 1;
  while ((*f != '\0')) {
    if (*f++ == '%') {
      r = buf;
      switch (*f++) {
        case '%':
          r = "%";
          break;

        case 'a':
          r = a_day[t->tm_wday];
          break;

        case 'k':
          r = k_day[t->tm_wday];
          break;

        case 'A':
          r = l_day[t->tm_wday];
          break;

        case 'b':
          r = a_month[t->tm_mon];
          break;

        case 'B':
          r = l_month[t->tm_mon];
          break;

        case 'c':
          strfmt(r, "%0 %0 %2 %2:%2:%2 %4",
                 a_day[t->tm_wday], a_month[t->tm_mon],
                 t->tm_mday, t->tm_hour, t->tm_min,
                 t->tm_sec, t->tm_year + 1900);
          break;

        case 'd':
          strfmt(r, "%2", t->tm_mday);
          break;

        case 'H':
          strfmt(r, "%2", t->tm_hour);
          break;

        case 'I':
          strfmt(r, "%2", (t->tm_hour % 12) ? t->tm_hour % 12 : 12);
          break;

        case 'j':
          strfmt(r, "%3", t->tm_yday + 1);
          break;

        case 'm':
          strfmt(r, "%2", t->tm_mon + 1);
          break;

        case 'M':
          strfmt(r, "%2", t->tm_min);
          break;

        case 'p':
          r = (t->tm_hour > 11) ? "PM" : "AM";
          break;

        case 'S':
          strfmt(r, "%2", t->tm_sec);
          break;

        case 'U':
          w = t->tm_yday / 7;
          if (t->tm_yday % 7 > t->tm_wday)
            w++;
          strfmt(r, "%2", w);
          break;

        case 'W':
          w = t->tm_yday / 7;
          if (t->tm_yday % 7 > (t->tm_wday + 6) % 7)
            w++;
          strfmt(r, "%2", w);
          break;

        case 'V':

          /* ISO 8601 Week Of Year:
             If the week (Monday - Sunday) containing January 1 has four or more
             days in the new year, then it is week 1; otherwise it is week 53 of
             the previous year and the next week is week one. */

           w = (t->tm_yday + 7 - (t->tm_wday ? t->tm_wday - 1 : 6)) / 7;
           d = (t->tm_yday + 7 - (t->tm_wday ? t->tm_wday - 1 : 6)) % 7;

           if (d >= 4) {
             w++;
           } else if (w == 0) {
             w = 53;
           }
           strfmt(r, "%2", w);
           break;

         case 'w':
           strfmt(r, "%1", t->tm_wday);
           break;

         case 'x':
           strfmt(r, "%3s %3s %2 %4", a_day[t->tm_wday],
                  a_month[t->tm_mon], t->tm_mday, t->tm_year + 1900);
           break;

         case 'X':
           strfmt(r, "%2:%2:%2", t->tm_hour, t->tm_min, t->tm_sec);
           break;

         case 'y':
           strfmt(r, "%2", t->tm_year % 100);
           break;

         case 'Y':
           strfmt(r, "%4", t->tm_year + 1900);
           break;

         case 'Z':
           r = (t->tm_isdst && tzname_[1][0]) ? tzname_[1] : tzname_[0];
           break;

         default:
           buf[0] = '%';   /* reconstruct the format */
           buf[1] = f[-1];
           buf[2] = '\0';
           if (buf[1] == 0)
             f--;    /* back up if at end of string */
      }
      while (*r) {
        if (p == q) {
          *q = '\0';
          return 0;
        }
        *p++ = *r++;
      }
    } else {
      if (p == q) {
        *q = '\0';
        return 0;
      }
      *p++ = f[-1];
    }
  }
  *p = '\0';
  return p - s;
}

/*
 *  stdarg.h
 *
typedef void *va_list;
#define va_start(vp,v) (vp=((char*)&v)+sizeof(v))
#define va_arg(vp,t) (*((t*)(vp))++)
#define va_end(vp)
 *
 */

static int powers[5] = { 1, 10, 100, 1000, 10000 };

/**
 * static void strfmt(char *str, char *fmt);
 *
 * simple sprintf for strftime
 *
 * each format descriptor is of the form %n
 * where n goes from zero to four
 *
 * 0    -- string %s
 * 1..4 -- int %?.?d
 *
**/

static void strfmt (char *str, const char *fmt, ...)
{
  int       ival, ilen;
  char     *sval;
  va_list   vp;

  va_start(vp, fmt);
  while (*fmt) {
    if (*fmt++ == '%') {
      ilen = *fmt++ - '0';
      if (ilen == 0) {    /* zero means string arg */
        sval = va_arg(vp, char *);

        while (*sval)
          *str++ = *sval++;
      } else {    /* always leading zeros */

        ival = va_arg(vp, int);

        while (ilen) {
          ival %= powers[ilen--];
          *str++ = (char) ('0' + ival / powers[ilen]);
        }
      }
    } else
      *str++ = fmt[-1];
  }
  *str = '\0';
  va_end(vp);
}

char *xgetdate (int format)
{
  static char date[12];
  time_t currenttime;
  struct tm *ltime;

  (void)time(&currenttime);
  ltime = localtime(&currenttime);
  switch (format) {
    default:
    case DATE_DEF:
     /* DD-MM-YYYY */
      snprintf(date,11, "%.2d-%.2d-%4d",ltime->tm_mday,
               (ltime->tm_mon+1), (ltime->tm_year+1900));
      break;
    case DATE_ISO:
      /* YYYY-MM-DD */
      snprintf(date,11, "%4d-%.2d-%.2d",(ltime->tm_year+1900),
               (ltime->tm_mon+1), ltime->tm_mday);
      break;
    case DATE_US:
      /* MM-DD-YYYYY */
      snprintf(date,11, "%.2d-%.2d-%4d",(ltime->tm_mon+1),
               ltime->tm_mday, (ltime->tm_year+1900));
      break;
  }
  return date;
}

char *xmakedate (int format, int day, int mon, int year)
{
  /* return the date in d */
  static char date[12];

  switch (format) {
    default:
    case DATE_DEF:
      /* DD-MM-YYYY */
      snprintf(date,11, "%.2d-%.2d-%4d",day,mon,year);
      break;
    case DATE_ISO:
      /* YYYY-MM-DD */
      snprintf(date,11, "%4d-%.2d-%.2d",year, mon, day);
      break;
    case DATE_US:
      /* MM-DD-YYYYY */
      snprintf(date,11, "%.2d-%.2d-%4d",mon, day, year);
      break;
  }
  return date;
}

int xparsedate (char *date, int format, int *day, int *mon, int *year)
{
  /* parse a date according to format */
  switch (format) {
    default:
    case DATE_DEF:
      return sscanf(date,"%2d-%2d-%4d",day,mon,year);
    case DATE_ISO:
      return sscanf(date,"%4d-%2d-%2d",year,mon,day);
    case DATE_US:
      return sscanf(date,"%2d-%2d-%4d",mon,day,year);
  }
}



/* Generic date manipulation routines. */

/* RFC1123: Sun, 06 Nov 1994 08:49:37 GMT */
#define RFC1123_FORMAT "%3s, %02d %3s %4d %02d:%02d:%02d GMT"

/* RFC850:  Sunday, 06-Nov-94 08:49:37 GMT */
#define RFC1036_FORMAT "%s, %2d-%3s-%2d %2d:%2d:%2d GMT"

/* asctime: Wed Jun 30 21:49:08 1993 */
#define ASCTIME_FORMAT "%3s %3s %2d %2d:%2d:%2d %4d"

static const char *rfc1123_weekdays[7] = { 
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" 
};
static const char *short_months[12] = { 
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

/* Returns the time/date GMT, in RFC1123-type format: eg
 *  Sun, 06 Nov 1994 08:49:37 GMT. */
char *rfc1123_date (time_t anytime)
{
  struct tm *gmt;
  char *ret;

  gmt = gmtime(&anytime);
  if (gmt == NULL)
    return NULL;
  ret = malloc(29 + 1); /* dates are 29 chars long */
  /*  it goes: Sun, 06 Nov 1994 08:49:37 GMT */
  snprintf(ret, 30, RFC1123_FORMAT,
           rfc1123_weekdays[gmt->tm_wday], gmt->tm_mday, 
           short_months[gmt->tm_mon], 1900 + gmt->tm_year, 
           gmt->tm_hour, gmt->tm_min, gmt->tm_sec);
    
  return ret;
}

/* Takes an RFC1123-formatted date string and returns the time_t.
 * Returns (time_t)-1 if the parse fails. */
time_t rfc1123_parse (const char *date) 
{
  struct tm gmt;
  static char wkday[4], mon[4];
  int n;

  /*  it goes: Sun, 06 Nov 1994 08:49:37 GMT */
  n = sscanf(date, RFC1123_FORMAT, wkday, &gmt.tm_mday, mon, &gmt.tm_year, &gmt.tm_hour, &gmt.tm_min, &gmt.tm_sec);
  /* Is it portable to check n==7 here? */
  gmt.tm_year -= 1900;
  for (n = 0; n < 12; n++)
    if (strcmp(mon, short_months[n]) == 0)
      break;
  /* tm_mon comes out as 12 if the month is corrupt, which is desired,
   * since the mktime will then fail */
  gmt.tm_mon = n;
  return mktime(&gmt);
}

/* Takes a string containing a RFC1036-style date and returns the time_t */
time_t rfc1036_parse (const char *date) 
{
  struct tm gmt;
  int n;
  static char wkday[10], mon[4];

  /* RFC850/1036 style dates: Sunday, 06-Nov-94 08:49:37 GMT */
  n = sscanf(date, RFC1036_FORMAT,
                wkday, &gmt.tm_mday, mon, &gmt.tm_year,
                &gmt.tm_hour, &gmt.tm_min, &gmt.tm_sec);
  /* portable to check n here? */
  for (n = 0; n < 12; n++)
    if (strcmp(mon, short_months[n]) == 0)
      break;
  /* tm_mon comes out as 12 if the month is corrupt, which is desired,
   * since the mktime will then fail */
  gmt.tm_mon = n;
  return mktime(&gmt);
}


/* (as)ctime dates are like:
 *    Wed Jun 30 21:49:08 1993
 */
time_t asctime_parse (const char *date) 
{
  struct tm gmt;
  int n;
  static char wkday[4], mon[4];

  n = sscanf(date, ASCTIME_FORMAT,
             wkday, mon, &gmt.tm_mday, &gmt.tm_hour, &gmt.tm_min, &gmt.tm_sec, &gmt.tm_year);
  /* portable to check n here? */
  for (n = 0; n < 12; n++)
    if (strcmp(mon, short_months[n]) == 0)
      break;
  /* tm_mon comes out as 12 if the month is corrupt, which is desired,
   * since the mktime will then fail */
  gmt.tm_mon = n;
  return mktime(&gmt);
}

#undef RFC1036_FORMAT
#undef ASCTIME_FORMAT
#undef RFC1123_FORMAT

