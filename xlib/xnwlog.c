/*
** 2009/02/04 - HDS
** 2016/04/20 - abort -> exit
*/
#include "xnwlog.h"
#include "tdate.h"
#include "xnw.h"


void xnw_fatal (const char *message, ...)
{
  FILE *log_fd;
  int tmp_error = errno;
  va_list vp;
  time_t    now;
  char st[64];

  if ((log_fd = fopen(XNW_LOG_FILE, "a+")) == NULL) {
    xnw_warn(XNW_LOG_FILE);
    return;
  }  
  time(&now);
  xstrftime(st, sizeof(st), "%Y/%m/%d %a  %X", localtime(&now));
  
  va_start(vp, message);
  fprintf(log_fd, "FATAL [%s] : ", st);
  vfprintf(log_fd, message, vp);

  /* if message has a \n mark, don't call perror */
  if (strchr(message, '\n') == NULL) {
    fprintf(log_fd, ": %s\n", strerror(tmp_error));
  }
  va_end(vp);
  fclose(log_fd);
  exit(1);
}

/**
 * Warning will just warn with the specified warning message
 * and then return from the function not exiting the system.
**/
void xnw_warning (const char *message, ...)
{
  FILE *log_fd;
  int tmp_error = errno;
  va_list vp;
  time_t    now;
  char st[64];

  if ((log_fd = fopen(XNW_LOG_FILE, "a+")) == NULL) {
    xnw_warn(XNW_LOG_FILE);
    return;
  }  
  time(&now);
  xstrftime(st, sizeof(st), "%Y/%m/%d %a  %X", localtime(&now));

  va_start(vp, message);
  fprintf(log_fd, "WARNING [%s] : ", st);
  vfprintf(log_fd, message, vp);

  /* if message has a \n mark, don't call perror */
  if (strchr(message, '\n') == NULL) {
    fprintf(log_fd, ": %s\n", strerror(tmp_error));
  }
  va_end(vp);
  fclose(log_fd);
}

void xnw_logging (const char *message, ...)
{
  FILE *log_fd;
  va_list vp;
  time_t    now;
  char st[64];

  if ((log_fd = fopen(XNW_LOG_FILE, "a+")) == NULL) {
    xnw_warn(XNW_LOG_FILE);
    return;
  }
  time(&now);
  xstrftime(st, sizeof(st), "%Y/%m/%d %a  %X", localtime(&now));

  va_start(vp, message);
  fprintf(log_fd, "LOG [%s] : ", st);
  vfprintf(log_fd, message, vp);
  va_end(vp);
  fclose(log_fd);
}


void
xnw_err(int eval, const char *fmt, ...)
{
  va_list ap;
 
  va_start(ap, fmt);
  if (fmt != NULL) {
    (void)vfprintf(stderr, fmt, ap);
    (void)fprintf(stderr, ": ");
  }
  va_end(ap);
  (void)fprintf(stderr, "%s\n", strerror(errno));
  exit(eval);   
}               
        
void    
xnw_warn (const char *fmt, ...)
{       
  va_list ap;
 
  va_start(ap, fmt);
  if (fmt != NULL) {
    (void)vfprintf(stderr, fmt, ap);
    (void)fprintf(stderr, ": ");
  }
  va_end(ap);
  (void)fprintf(stderr, "%s\n", strerror(errno));
}               
                
void    
xnw_errx (int eval, const char *fmt, ...)
{       
  va_list ap;

  va_start(ap, fmt);
  if (fmt != NULL)
    (void)vfprintf(stderr, fmt, ap);
  (void)fprintf(stderr, "\n");
  va_end(ap);
  exit(eval);
}

void
xnw_warnx(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  if (fmt != NULL)
    (void)vfprintf(stderr, fmt, ap);
  (void)fprintf(stderr, "\n");
  va_end(ap);
}
