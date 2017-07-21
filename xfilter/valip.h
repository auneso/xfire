#ifndef __VALIP_H__
#define  __VALIP_H__

#include <ctype.h>

#define ISASCII(c) isascii(_UCHAR_(c))
#define _UCHAR_(c) ((unsigned char)(c))
#define ISALNUM(c) (ISASCII(c) && isalnum((unsigned char)(c)))
#define ISALPHA(c) (ISASCII(c) && isalpha((unsigned char)(c)))
#define ISCNTRL(c) (ISASCII(c) && iscntrl((unsigned char)(c)))
#define ISDIGIT(c) (ISASCII(c) && isdigit((unsigned char)(c)))
#define ISGRAPH(c) (ISASCII(c) && isgraph((unsigned char)(c)))
#define ISLOWER(c) (ISASCII(c) && islower((unsigned char)(c)))
#define ISPRINT(c) (ISASCII(c) && isprint((unsigned char)(c)))
#define ISPUNCT(c) (ISASCII(c) && ispunct((unsigned char)(c)))
#define ISSPACE(c) (ISASCII(c) && isspace((unsigned char)(c)))
#define ISUPPER(c) (ISASCII(c) && isupper((unsigned char)(c)))
#define TOLOWER(c) (ISUPPER(c) ? tolower((unsigned char)(c)) : (c))
#define TOUPPER(c) (ISLOWER(c) ? toupper((unsigned char)(c)) : (c))


#define VALID_HOSTNAME_LEN      255     /* RFC 1035 */
#define VALID_LABEL_LEN         63      /* RFC 1035 */


int valid_hostname (const char *);
int valid_hostaddr (const char *);
int valid_ipv4_hostaddr (const char *);
int valid_ipv6_hostaddr (const char *);
int valid_hostport (const char *);

#endif
