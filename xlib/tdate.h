#ifndef __TDATE_H__
#define __TDATE_H__
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define SECONDS_IN_DAY 24*60*60

enum {  T_NOW, T_RECENT, T_TODAY, T_YESTERDAY, T_TOMORROW, T_THIS_WEEK, T_WEEK_AGO,
        T_THIS_MONTH, T_THIS_YEAR };

extern time_t start_time, end_time;

int lookup_time(const char *name);
int search_time_start(const char *da, const char *ti);
int search_time_end(const char *da, const char *ti);

time_t tdate_parse (char *str);

size_t xstrftime (char *s, size_t maxs, const char *f, const struct tm *t);


const char *long_day_of_the_week  (int day, int month, int year);
const char *short_day_of_the_week (int day, int month, int year);
const char *kr_day_of_the_week    (int day, int month, int year);

int         days_in_a_month       (int month, int year);
int         day_of_the_week       (int day, int month, int year);
int         day_of_month_ago      (int month, int year, int ago_month);
int         sec_of_month_ago      (int month, int year, int ago_month);
int         month_ago             (int *month, int *year, int ago_month);
void        week_ago              (int *sday, int *smonth, int *syear, int *eday, int *emonth, int *eyear);
void        days_ago              (int *day, int *month, int *year, int ago_day);
void        day_ago               (int *day, int *month, int *year);

#define DATE_DEF        0
#define DATE_ISO        1
#define DATE_US         2
char *xgetdate (int format);
char *xmakedate (int format, int day, int mon, int year);
int   xparsedate (char *date, int format, int *day, int *mon, int *year);

#endif
