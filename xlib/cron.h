#ifndef __CRON_H__
#define __CRON_H__

//      The time and date fields are:
//
//              field          allowed values
//              -----          --------------
//              minute         0-59
//              hour           0-23
//              day of month   1-31
//              month          1-12 (or names, see below)
//              day of week    0-7 (0 or 7 is Sun, or use names)
//
//       A field may be an asterisk (*), which always stands for "first-last".
//
//       Ranges of numbers are allowed.  Ranges are two numbers separated with a hyphen.  The specified range
//       is inclusive.  For example, 8-11 for an "hours" entry specifies execution at hours 8, 9, 10 and  11.
//
//       Lists  are  allowed.   A  list  is  a  set  of  numbers  (or ranges) separated by commas.  Examples:
//       "1,2,5,9", "0-4,8-12".
//
//       Step values can be used in conjunction with ranges.  Following a  range  with  "<number>"  specifies
//       skips of the number's value through the range.  For example, "0-23/2" can be used in the hours field
//       to  specify  command  execution  every  other  hour  (the  alternative  in  the   V7   standard   is
//       "0,2,4,6,8,10,12,14,16,18,20,22").   Steps  are  also permitted after an asterisk, so if you want to
//       say "every two hours", just use "*/2".
//
//       Names can also be used for the "month" and "day of week" fields.  Use the first three letters of the
//       particular day or month (case doesn't matter).  Ranges or lists of names are not allowed.
//
//       The  "sixth"  field (the rest of the line) specifies the command to be run.
//       The entire command poration of the line, up to a newline or % character,
//       will be executed by /bin/sh or by the shell speciafied  in  the SHELL variable of the cronfile.
//       Percent-signs (%) in the command, unless escaped with
//       backslash (\), will be changed into newline characters, and all data after the first % will be  sent
//       to the command as standard input.
//
//       Note:  The  day  of  a command's execution can be specified by two fields a day of month, and day of
//       week.  If both fields are restricted (ie, aren't *), the command  will  be  run  when  either  field
//       matches the current time.  For example,
//       "30  4  1,15 * 5" would cause a command to be run at 4:30 am on the 1st and 15th of each month, plus
//       every Friday.
//
//      Names can also be used for the ``month'' and ``day  of  week''  fields.
//       Use  the  first  three  letters  of  the  particular day or month (case
//       doesn't matter).  Ranges or lists of names are not allowed.
//
//       The time descriptor can also be one of  the  following  special  values
//       instead:
//
//              @reboot
//              @hourly
//              @daily
//              @weekly
//              @monthly
//
//       The  command  will  then be run only at startup (@reboot) or roughly in
//       the specified intervals.
//
//       The optional flag field determines whether the command should be run if
//       it  occured  between the time cron was last shut down and startup. This
//       permits cron to run commands regularly even on systems that  don't  run
//       all of the time (``home computers''). The flag field can have four vala¢æ[39;93H
//       ues:
//
//       empty  standard cron behaviour, start the command only if cron is  run
//              ning at the specified time.
//
//       *      catch  up all occurences of this job.  Cron runs this command as
//              many times as it would have done if it had not been shut down.
//
//       !      catch up this job, but run only once, no matter how  many  times
//              it occured between shutdown and startup.
//
//       \      as  empty.  This allows the first character of the command to be
//              ``*'' or ``!''.
//       Note: The day of a command's execution can be specified by  two  fields
//       day  of  month,  and  day  of  week. If both fields are restricted (ie, aren't *),
//       the command will be run when either field matches  the  current time.
//        For example,
//
//              30 4 1,15 * 5
//
//       would  cause a command to be run at 4:30 am on the 1st and 15th of each
//       month, plus every Friday.
//       #
//       # run five minutes after midnight, every day; if cron is not running at
//       # that time, catch up at startup; run several times if down for more
//       # than one day
//       5 0 * * * 
//
//       #
//       # run at 2:15pm on the first of every month; catch up, but run only once
//       # even if the computer is down for several months
//       15 14 1 * *
//
//       #
//       # run at 10 pm on weekdays, annoy Joe; do not do it, if cron is not
//       # up at that time.
//       0 22 * * 1-5
//
//       # run 23 minutes after midn, 2am, 4am ..., everyday
//       23 0-23/2 * * *
//
//       # run at 5 after 4 every sunday
//       5 4 * * sun
//

# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include "xtypes.h"


/* bits control -----------------------------*/
typedef unsigned char bitstr_t;

/* internal macros */
/* byte of the bitstring bit is in */
#define _bit_byte(bit) ((bit) >> 3)

/* mask for the bit within its byte */
#define _bit_mask(bit) (1 << ((bit)&0x7))

/* bytes in a bitstring of nbits bits */
#define bitstr_size(nbits) ((((nbits) - 1) >> 3) + 1)

/* allocate a bitstring on the stack */
#define bit_decl(name, nbits) (name)[bitstr_size(nbits)]

/* is bit N of bitstring name set? */
#define bit_test(name, bit) ((name)[_bit_byte(bit)] & _bit_mask(bit))

/* set bit N of bitstring name */
#define bit_set(name, bit) (name)[_bit_byte(bit)] |= _bit_mask(bit)

/* clear bits start ... stop in bitstring */
#define bit_nclear(name, start, stop) { \
  register bitstr_t *_name = name; \
  register int _start = start, _stop = stop; \
  register int _startbyte = _bit_byte(_start); \
  register int _stopbyte = _bit_byte(_stop); \
  if (_startbyte == _stopbyte) { \
    _name[_startbyte] &= ((0xff >> (8 - (_start&0x7))) | \
                          (0xff << ((_stop&0x7) + 1))); \
  } else { \
    _name[_startbyte] &= 0xff >> (8 - (_start&0x7)); \
    while (++_startbyte < _stopbyte) \
      _name[_startbyte] = 0; \
    _name[_stopbyte] &= 0xff << ((_stop&0x7) + 1); \
  } \
}

/* set bits start ... stop in bitstring */
#define bit_nset(name, start, stop) { \
  register bitstr_t *_name = name; \
  register int _start = start, _stop = stop; \
  register int _startbyte = _bit_byte(_start); \
  register int _stopbyte = _bit_byte(_stop); \
  if (_startbyte == _stopbyte) { \
    _name[_startbyte] |= ((0xff << (_start&0x7)) & \
                          (0xff >> (7 - (_stop&0x7)))); \
  } else { \
    _name[_startbyte] |= 0xff << ((_start)&0x7); \
    while (++_startbyte < _stopbyte) \
      _name[_startbyte] = 0xff; \
    _name[_stopbyte] |= 0xff >> (7 - (_stop&0x7)); \
  } \
}

#define bit_ffc(name, nbits, value) { \
  register bitstr_t *_name = name; \
  register int _byte, _nbits = nbits; \
  register int _stopbyte = _bit_byte(_nbits), _value = -1; \
  for (_byte = 0; _byte <= _stopbyte; ++_byte) \
    if (_name[_byte] != 0xff) { \
      _value = _byte << 3; \
      for (_stopbyte = _name[_byte]; (_stopbyte&0x1); \
        ++_value, _stopbyte >>= 1); \
      break; \
    } \
  *(value) = _value; \
}

/* find first bit set in name */
#define bit_ffs(name, nbits, value) { \
  register bitstr_t *_name = name; \
  register int _byte, _nbits = nbits; \
  register int _stopbyte = _bit_byte(_nbits), _value = -1; \
  for (_byte = 0; _byte <= _stopbyte; ++_byte) \
    if (_name[_byte]) { \
      _value = _byte << 3; \
      for (_stopbyte = _name[_byte]; !(_stopbyte&0x1); \
        ++_value, _stopbyte >>= 1); \
      break; \
    } \
  *(value) = _value; \
}

#define  FIRST_MINUTE  0
#define  LAST_MINUTE  59
#define  MINUTE_COUNT  (LAST_MINUTE - FIRST_MINUTE + 1)

#define  FIRST_HOUR    0
#define  LAST_HOUR    23
#define  HOUR_COUNT  (LAST_HOUR - FIRST_HOUR + 1)

#define  FIRST_DOM     1
#define  LAST_DOM     31
#define  DOM_COUNT  (LAST_DOM - FIRST_DOM + 1)

#define  FIRST_MONTH   1
#define  LAST_MONTH   12
#define  MONTH_COUNT  (LAST_MONTH - FIRST_MONTH + 1)

/* note on DOW: 0 and 7 are both Sunday, for compatibility reasons. */
#define  FIRST_DOW     0
#define  LAST_DOW      7
#define  DOW_COUNT  (LAST_DOW - FIRST_DOW + 1)
 

#define Skip_Blanks(c, f) \
  while (c == '\t' || c == ' ') \
    c = get_char(f);

#define Skip_Nonblanks(c, f) \
  while (c != '\t' && c != ' ' && c != '\n' && c != EOF) \
    c = get_char(f);
     
#define MAX_TIMER_LEN  64


typedef struct _cron {
  bitstr_t  bit_decl(minute, MINUTE_COUNT);
  bitstr_t  bit_decl(hour,   HOUR_COUNT);
  bitstr_t  bit_decl(dom,    DOM_COUNT);
  bitstr_t  bit_decl(month,  MONTH_COUNT);
  bitstr_t  bit_decl(dow,    DOW_COUNT);
  int       flags;
#define MIN_STAR        0x01
#define HR_STAR         0x02
#define DOM_STAR        0x04
#define DOW_STAR        0x08
#define WHEN_REBOOT     0x10
#define DONT_LOG        0x20
} cron;

typedef struct _cron_time {
  int minute;
  int hour;
  int dom;
  int month;
  int dow;
} cron_time;

typedef void   (*job_func)(cron_time *tct, void *user);
typedef struct _cron_func {
  job_func job;
  void *user;
  int  idx;
} cron_func;

typedef struct _quota {
  ub32   usetimes;
  ub32   usebytes;
  ub32   usesessions;
  ub32   idletime;
} quota;


int cron_check_time (cron_time *tct, cron *cron);
int cron_set_time (cron *cron, char *cmd);
void cron_get_time (cron_time *tct);

cron_func *cron_add_job (job_func func, void *user);
void cron_del_job (cron_func *func);
int cron_add_job_idx (job_func func, void *user, int idx);
void *cron_del_job_idx (int idx);

void cron_start (void);

#endif /* __CRON_H__ */
