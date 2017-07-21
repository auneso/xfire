#ifndef __ITOA_H__
#define __ITOA_H__
/**
 * convert n to characters in s
 * s will NOT be zero terminated, return strlen of s
 * this is a simple implementation that works for complete long int range
 * architecture independent
 * about 2 times faster than sprintf (in range [INT_MIN/10 - INT_MAX/10])
 */
int ltoa_simple (char *s, long num);

/**
 * convert n to characters in s
 * s will NOT be zero terminated, return strlen of s
 * about 3 times faster than sprintf (in range [INT_MIN/10 - INT_MAX/10])
 * (original function found on http://cboard.cprogramming.com
 * itoas() iMalc version updated ver. 0.8)
 */
int itoa_int32 (char *s, int32_t snum);
int itoa_uint32 (char *s, uint32_t snum);
int itoa_int64 (char *s, int64_t snum);
int itoa_uint64 (char *s, uint64_t snum);
int ftoa (char *outbuf, float f);

/**
 * ftoa_prec_f0: printing floats as rounded integer
 * works exactly like sprintf "%.0f" for |f| < 2^64,
 * +-ULONG_MAX is printed when |f| >= 2^64 or +-inf or nan,
 * round to even like IEEE 754-1985 4.1 says,
 * about 20 times faster than sprintf (exponent range 2^-1, 2^20)
 */
int ftoa_prec_f0 (char *outbuf, float f);

char * itoa_int32_str (char *s, int32_t snum);
char * itoa_uint32_str (char *s, uint32_t snum);
char * itoa_int64_str (char *s, int64_t snum);
char * itoa_uint64_str (char *s, uint64_t snum);
char * ftoa_str (char *outbuf, float f);
char * ftoa_prec_f0_str (char *outbuf, float f);

#endif
