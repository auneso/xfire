#ifndef __XPINT_H__
#define __XPINT_H__

#include "xtypes.h"

/* Pointer versions of g_ntohs and g_ntohl.  Given a pointer to a member of a
 * byte array, returns the value of the two or four bytes at the pointer.
 * The pletoh[sl] versions return the little-endian representation.
 */

#define xpntohs(p)   ((ub16)                       \
                     ((ub16)*((const ub8 *)(p)+0)<<8|  \
                      (ub16)*((const ub8 *)(p)+1)<<0))

#define xpntoh24(p)  ((ub32)*((const ub8 *)(p)+0)<<16|  \
                     (ub32)*((const ub8 *)(p)+1)<<8|   \
                     (ub32)*((const ub8 *)(p)+2)<<0)

#define xpntohl(p)   ((ub32)*((const ub8 *)(p)+0)<<24|  \
                     (ub32)*((const ub8 *)(p)+1)<<16|  \
                     (ub32)*((const ub8 *)(p)+2)<<8|   \
                     (ub32)*((const ub8 *)(p)+3)<<0)

#define xpntoh40(p)  ((ub64)*((const ub8 *)(p)+0)<<32|  \
                     (ub64)*((const ub8 *)(p)+1)<<24|  \
                     (ub64)*((const ub8 *)(p)+2)<<16|  \
                     (ub64)*((const ub8 *)(p)+3)<<8|   \
                     (ub64)*((const ub8 *)(p)+4)<<0)

#define xpntoh48(p)  ((ub64)*((const ub8 *)(p)+0)<<40|  \
                     (ub64)*((const ub8 *)(p)+1)<<32|  \
                     (ub64)*((const ub8 *)(p)+2)<<24|  \
                     (ub64)*((const ub8 *)(p)+3)<<16|  \
                     (ub64)*((const ub8 *)(p)+4)<<8|   \
                     (ub64)*((const ub8 *)(p)+5)<<0)

#define xpntoh56(p)  ((ub64)*((const ub8 *)(p)+0)<<48|  \
                     (ub64)*((const ub8 *)(p)+1)<<40|  \
                     (ub64)*((const ub8 *)(p)+2)<<32|  \
                     (ub64)*((const ub8 *)(p)+3)<<24|  \
                     (ub64)*((const ub8 *)(p)+4)<<16|  \
                     (ub64)*((const ub8 *)(p)+5)<<8|   \
                     (ub64)*((const ub8 *)(p)+6)<<0)

#define xpntoh64(p)  ((ub64)*((const ub8 *)(p)+0)<<56|  \
                     (ub64)*((const ub8 *)(p)+1)<<48|  \
                     (ub64)*((const ub8 *)(p)+2)<<40|  \
                     (ub64)*((const ub8 *)(p)+3)<<32|  \
                     (ub64)*((const ub8 *)(p)+4)<<24|  \
                     (ub64)*((const ub8 *)(p)+5)<<16|  \
                     (ub64)*((const ub8 *)(p)+6)<<8|   \
                     (ub64)*((const ub8 *)(p)+7)<<0)


#define xpletohs(p)  ((ub16)                       \
                     ((ub16)*((const ub8 *)(p)+1)<<8|  \
                      (ub16)*((const ub8 *)(p)+0)<<0))

#define xpletoh24(p) ((ub32)*((const ub8 *)(p)+2)<<16|  \
                     (ub32)*((const ub8 *)(p)+1)<<8|   \
                     (ub32)*((const ub8 *)(p)+0)<<0)

#define xpletohl(p)  ((ub32)*((const ub8 *)(p)+3)<<24|  \
                     (ub32)*((const ub8 *)(p)+2)<<16|  \
                     (ub32)*((const ub8 *)(p)+1)<<8|   \
                     (ub32)*((const ub8 *)(p)+0)<<0)

#define xpletoh40(p) ((ub64)*((const ub8 *)(p)+4)<<32|  \
                     (ub64)*((const ub8 *)(p)+3)<<24|  \
                     (ub64)*((const ub8 *)(p)+2)<<16|  \
                     (ub64)*((const ub8 *)(p)+1)<<8|   \
                     (ub64)*((const ub8 *)(p)+0)<<0)

#define xpletoh48(p) ((ub64)*((const ub8 *)(p)+5)<<40|  \
                     (ub64)*((const ub8 *)(p)+4)<<32|  \
                     (ub64)*((const ub8 *)(p)+3)<<24|  \
                     (ub64)*((const ub8 *)(p)+2)<<16|  \
                     (ub64)*((const ub8 *)(p)+1)<<8|   \
                     (ub64)*((const ub8 *)(p)+0)<<0)

#define xpletoh56(p) ((ub64)*((const ub8 *)(p)+6)<<48|  \
                     (ub64)*((const ub8 *)(p)+5)<<40|  \
                     (ub64)*((const ub8 *)(p)+4)<<32|  \
                     (ub64)*((const ub8 *)(p)+3)<<24|  \
                     (ub64)*((const ub8 *)(p)+2)<<16|  \
                     (ub64)*((const ub8 *)(p)+1)<<8|   \
                     (ub64)*((const ub8 *)(p)+0)<<0)

#define xpletoh64(p) ((ub64)*((const ub8 *)(p)+7)<<56|  \
                     (ub64)*((const ub8 *)(p)+6)<<48|  \
                     (ub64)*((const ub8 *)(p)+5)<<40|  \
                     (ub64)*((const ub8 *)(p)+4)<<32|  \
                     (ub64)*((const ub8 *)(p)+3)<<24|  \
                     (ub64)*((const ub8 *)(p)+2)<<16|  \
                     (ub64)*((const ub8 *)(p)+1)<<8|   \
                     (ub64)*((const ub8 *)(p)+0)<<0)

/* Pointer routines to put items out in a particular byte order.
 * These will work regardless of the byte alignment of the pointer.
 */

#define xphtons(p, v) \
	{ 				\
	((ub8*)(p))[0] = (ub8)((v) >> 8);	\
	((ub8*)(p))[1] = (ub8)((v) >> 0);	\
	}

#define xphtonl(p, v) \
	{ 				\
	((ub8*)(p))[0] = (ub8)((v) >> 24);	\
	((ub8*)(p))[1] = (ub8)((v) >> 16);	\
	((ub8*)(p))[2] = (ub8)((v) >> 8);	\
	((ub8*)(p))[3] = (ub8)((v) >> 0);	\
	}

#define xphtonl48(p, v) \
        {                               \
        ((ub8*)(p))[0] = (ub8)((v) >> 40);      \
        ((ub8*)(p))[1] = (ub8)((v) >> 32);      \
        ((ub8*)(p))[2] = (ub8)((v) >> 24);      \
        ((ub8*)(p))[3] = (ub8)((v) >> 16);      \
        ((ub8*)(p))[4] = (ub8)((v) >> 8);       \
        ((ub8*)(p))[5] = (ub8)((v) >> 0);       \
        }


/* Macros to byte-swap 32-bit and 16-bit quantities. */
#define	XBSWAP32(x) \
	((((x)&0xFF000000)>>24) | \
	 (((x)&0x00FF0000)>>8) | \
	 (((x)&0x0000FF00)<<8) | \
	 (((x)&0x000000FF)<<24))
#define	XBSWAP16(x) \
	 ((((x)&0xFF00)>>8) | \
	  (((x)&0x00FF)<<8))

#endif /* XPINT_H */
