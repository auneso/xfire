#ifndef __FORMAT_H__
#define __FORMAT_H__
#include "xtypes.h"

#define IPV4_STR_SIZE sizeof("255.255.255.255 ")
#define MAC_STR_SIZE  sizeof("XX:XX:XX:XX:XX:XX ")

char *fmt_commab (sb64 n, char *buf, int size);
char *fmt_comma (sb64 n);

char *fmt_bytesb (ub64 bytes, ub64 mod, char *p, int len);
char *fmt_bytes (ub64 bytes);
char *fmt_throughput (double nbytes);

char *fmt_second (time_t sec);
char *fmt_msecond (ub64 usec);
char *format_numbers (double val, char *buf, ub32 buf_len, ub8 add_decimals);

char *etheraddr_stringb (ub8 *ep, char *buf);
char *etheraddr_string (ub8 *ep);

char *string_etheraddr (ub8 *ep);

char *intoab (unsigned int addr, char *buff);
char *intoa (unsigned int addr);

ub32 atoin (char *s);
ub32 atoin_n (char *s);
int ipcmp (ub32 ip1, ub32 ip2);

void sprinthex (char *to_buf, void const *from, int from_len);
int ebcdic_format (const ub8 *buf, size_t len, ub8 *dst);

/*
 * to select alternate encoding format
 */
#define	VIS_OCTAL	0x01	/* use octal \ddd format */
#define	VIS_CSTYLE	0x02	/* use \[nrft0..] where appropriate */

/*
 * to alter set of characters encoded (default is to encode all
 * non-graphic except space, tab, and newline).
 */
#define	VIS_SP		0x04	/* also encode space */
#define	VIS_TAB		0x08	/* also encode tab */
#define	VIS_NL		0x10	/* also encode newline */
#define	VIS_WHITE	(VIS_SP | VIS_TAB | VIS_NL)
#define	VIS_SAFE	0x20	/* only encode "unsafe" characters */

/*
 * other
 */
#define	VIS_NOSLASH	0x40	/* inhibit printing '\' */
#define	VIS_GLOB	0x100	/* encode glob(3) magics and '#' */

/*
 * unvis return codes
 */
#define	UNVIS_VALID	 1	/* character valid */
#define	UNVIS_VALIDPUSH	 2	/* character valid, push back passed char */
#define	UNVIS_NOCHAR	 3	/* valid sequence, no character produced */
#define	UNVIS_SYNBAD	-1	/* unrecognized escape sequence */
#define	UNVIS_ERROR	-2	/* decoder in unknown state (unrecoverable) */

/*
 * unvis flags
 */
#define	UNVIS_END	1	/* no more characters */

char	*vis(char *, int, int, int);
int	strvis(char *, const char *, int);
int	strnvis(char *, const char *, size_t, int);
int	strvisx(char *, const char *, size_t, int);
int	strunvis(char *, const char *);
int	unvis(char *, char, int *, int);
ssize_t strnunvis(char *, const char *, size_t);

ub64 countercalc (ub64 a, ub64 b);

int printHex (const u_char *a, int len, u_char *buf, int bufLen, int marker, int bytesPerOutputLine);
#endif /* __FORMAT_H__*/
