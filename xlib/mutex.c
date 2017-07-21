/*
 * $Id: mutex.c,v 1.2 2001/01/22 23:11:34 matley Exp $
 */
/*
 * Copyright (c) 2000 Massachusetts Institute of Technology
 * Copyright (c) 2000 Matteo Frigo
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
 * http://supertech.lcs.mit.edu/cilk/
 */
/* 2008/10/1 - HDS  : pthread_mutex -> pthread_spin */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "mutex.h"



/*
 * Copyright (c) 2000 Massachusetts Institute of Technology
 * Copyright (c) 2000 Matteo Frigo
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
 * http://supertech.lcs.mit.edu/cilk/
 */

/***********************************************************\
 * OS-specific macros
\***********************************************************/

#if defined(__osf__) && defined(__alpha__)
/* c_asm.h declares a variable called `asm' which crashes gcc */
#  ifndef __C_ASM_H
#    define __C_ASM_H
#  endif
#endif

/***********************************************************\
 * Various types of memory barriers and atomic operations
\***********************************************************/

/*------------------------
       POWERPC
 ------------------------*/
#if defined(__powerpc__) || defined(__ppc__)
#  define SPIN_CACHE_LINE 64
#  define SPIN_MB()  __asm__ __volatile__ ("sync" : : : "memory")
#  define SPIN_RMB()  __asm__ __volatile__ ("sync" : : : "memory")
#  define SPIN_WMB()  __asm__ __volatile__ ("eieio" : : : "memory")

   /* atomic swap operation */
   static inline int spin_xchg(volatile int *ptr, int x)
   {
	int result;
	__asm__ __volatile__ (
	   "0: lwarx %0,0,%1\n stwcx. %2,0,%1\n bne- 0b" :
	    "=&r"(result) :
	   "r"(ptr), "r"(x) :
	    "cr0");
	return result;
   }
#endif

/*------------------------
       IA64
 ------------------------*/
#ifdef __ia64__
#  define SPIN_CACHE_LINE 128 /* just a guess */
#  define SPIN_MB()  __asm__ __volatile__ ("mf" : : : "memory")
#  define SPIN_RMB()  SPIN_MB()
#  define SPIN_WMB()  SPIN_MB()

   /* atomic swap operation */
   static inline int spin_xchg(volatile int *ptr, int x)
   {
	int result;
	__asm__ __volatile ("xchg4 %0=%1,%2" : "=r" (result)
			    : "m" (*(int *) ptr), "r" (x) : "memory");
	return result;
   }
#endif

/*------------------------
         I386
 ------------------------*/
#ifdef __i386__
#  define SPIN_CACHE_LINE 32

   static inline void SPIN_MB(void)
   {
	/*
	 * We use an xchg instruction to serialize memory accesses, as can
	 * be done according to the Intel Architecture Software Developer's
	 * Manual, Volume 3: System Programming Guide
	 * (http://www.intel.com/design/pro/manuals/243192.htm), page 7-6,
	 * "For the P6 family processors, locked operations serialize all
	 * outstanding load and store operations (that is, wait for them to
	 * complete)."  The xchg instruction is a locked operation by
	 * default.  Note that the recommended memory barrier is the cpuid
	 * instruction, which is really slow (~70 cycles).  In contrast,
	 * xchg is only about 23 cycles (plus a few per write buffer
	 * entry?).  Still slow, but the best I can find.  -KHR
	 */
	int x=0, y;
	asm volatile ("xchgl %0,%1" :"=r" (x) :"m" (y), "0" (x) :"memory");
   }

#  define SPIN_RMB() SPIN_MB()
#  define SPIN_WMB() __asm__ __volatile__ ("": : :"memory")

   /* atomic swap operation */
   static inline int spin_xchg(volatile int *ptr, int x)
   {
	__asm__("xchgl %0,%1" :"=r" (x) :"m" (*(ptr)), "0" (x) :"memory");
	return x;
   }
#endif /* __i386__ */



/*------------------------
         SPARC
 ------------------------*/
#ifdef __sparc__

#define SPIN_CACHE_LINE 64
   /* atomic swap operation */
   static inline int spin_xchg(volatile int *ptr, register int xchg)
   {
	asm volatile ("swap [%1],%0"
		      :"=r" (xchg)	/* registers written */
		      :"r"(ptr), "0"(xchg)		/* registers read */
		      : "memory"
	);
	return xchg;
   }


#  ifdef __sparc_v9__
#    define SPIN_MB()  \
       __asm__ __volatile__("membar #StoreLoad | #StoreStore | #LoadLoad | #LoadStore" ::: "memory")
#    define SPIN_RMB() __asm__ __volatile__ ("membar #StoreLoad" ::: "memory")
#    define SPIN_WMB() __asm__ __volatile__ ("": : :"memory")
#  else
#    define SPIN_MB()  __asm__ __volatile__("stbar" ::: "memory")
     static inline void SPIN_RMB(void) { int dummy; spin_xchg(&dummy, 0); }
#    define SPIN_WMB() __asm__ __volatile__ ("": : :"memory")
#endif

#endif /* __sparc__ */

/*------------------------
         MIPS
 ------------------------*/
#ifdef __mips__
#  define SPIN_CACHE_LINE 128
#  define SPIN_MB() __asm__ __volatile__ ("sync":::"memory")
#  define SPIN_RMB() SPIN_MB()
#  define SPIN_WMB() SPIN_MB()

   /* atomic swap operation */
   static inline int spin_xchg(volatile int *m, int val)
   {
	unsigned long dummy;
	__asm__ __volatile__(
	     ".set noreorder\n"
	     ".set noat\n"
	     "ll %0,(%1)\n"
	     "1: move $1,%2\n"
	     "sc $1,(%1)\n"
	     "beqzl $1,1b\n"
	     "ll %0,(%1)\n"
	     ".set at\n"
	     ".set reorder"
	     : "=r" (val), "=r" (m), "=r" (dummy)
	     : "1" (m), "2" (val)
	     : "memory");
	return val;
   }
#endif /* __mips__ */

/*------------------------
         ALPHA
 ------------------------*/
#ifdef __alpha__
#  define SPIN_CACHE_LINE 128
#  define SPIN_MB() __asm__ __volatile__ ("mb":::"memory")
#  define SPIN_RMB() __asm__ __volatile__ ("mb":::"memory")
#  define SPIN_WMB() __asm__ __volatile__ ("wmb":::"memory")

   /* atomic swap operation */
   static inline int spin_xchg(volatile int *m, int val)
   {
	register int dummy;

	__asm__ __volatile__(
	     "1:    ldl_l %0,%2\n"
	     "      bis $31,%3,%1\n"
	     "	    stl_c %1,%2\n"
	     "	    beq %1,1b\n"
	     "	    mb\n"
	     : "=&r" (val), "=&r" (dummy), "=m" (*m)
	     : "rI" (val), "m" (*m));

	return val;
   }
#endif /* __alpha__ */

/*
 * padding, to be used in structures to avoid false sharing
 */
#define SPIN_CACHE_LINE_PAD  char __dummy[SPIN_CACHE_LINE]
#define SPIN_CACHE_LINE_ALIGNED(decl) \
    decl  __attribute__((aligned(SPIN_CACHE_LINE)))



#ifdef SPIN_CACHE_LINE

/***********************************************************\
 * Support for mutexen 
\***********************************************************/

/* implementation over shared memory */
#define ACQUIRE(lock) spin_xchg(lock, 1)
#define RELEASE(lock) *(lock) = 0

/* initialize lock */
void spin_mutex_init (spin_mutex *lock)
{
  RELEASE(lock);
}

/*
 *  Obtain lock <lock>.  Waits until lock is available.
 */
void spin_mutex_lock (spin_mutex *lock)
{
  if (ACQUIRE(lock) == 0)  /* fast case */
    return;

  SPIN_WMB();

  /* 
   * This hackery should reduce bus traffic, if the
   * cache is snooped correctly.
   */
  do {
    while (*lock != 0);
  } while (ACQUIRE(lock) != 0);

  SPIN_RMB();
}

/*
 *  Try to obtain lock <lock>.  Returns 1 upon success and 0 upon failure.
 *  Do not wait.
 */
int spin_mutex_trylock (spin_mutex *lock)
{
  SPIN_WMB();
  if (ACQUIRE(lock) == 0) {
    SPIN_RMB();
    return 1;
  } else
    return 0;
}

void spin_mutex_wait_lock (spin_mutex *lock, int try, int usec)
{
  int cnt = 0;

  while (!spin_mutex_trylock(lock)) { 
    if (cnt < try) { 
      sched_yield();
      cnt++;
    } else {
      usleep(usec);
      cnt = 0;
    }
  }
}

/*
 *  Give up lock <lock>.
 */
void spin_mutex_unlock (spin_mutex *lock)
{
  SPIN_WMB();
  RELEASE(lock);
}



void spin_mutex_destroy (spin_mutex *lock)
{
  RELEASE(lock);
}

#else


/*******************************
 * Posix-threads locks
 *******************************/
void spin_mutex_init (spin_mutex *lock)
{
  pthread_spin_init(lock, PTHREAD_PROCESS_SHARED);
}

void spin_mutex_lock (spin_mutex *lock)
{
  pthread_spin_lock(lock);
}

void spin_mutex_unlock (spin_mutex *lock)
{
  pthread_spin_unlock(lock);
}

int spin_mutex_trylock (spin_mutex *lock)
{
  if (pthread_spin_trylock(lock) == 0) {
    return 1;
  } else {
    return 0;
  }
}

void spin_mutex_wait_lock (spin_mutex *lock, int try, int usec)
{
  int cnt = 0;

  while (!spin_mutex_trylock(lock)) {
    if (cnt < try) {
      sched_yield();
      cnt++;
    } else {
      usleep(usec);
      cnt = 0;
    }
  }
}


void spin_mutex_destroy (spin_mutex *lock)
{
  pthread_spin_destroy(lock);
}

#endif /* SPIN_CACHE_LINE */



/*******************************
 * Global Mutex Locks
 *******************************/
static spin_mutex glock;

void global_mutex_init ()
{
  spin_mutex_init(&glock);
}

void global_mutex_lock ()
{
  spin_mutex_lock(&glock);
}

void global_mutex_unlock ()
{
  spin_mutex_unlock(&glock);
}

int global_mutex_trylock ()
{
  return spin_mutex_trylock(&glock);
}

void global_mutex_destroy ()
{
  spin_mutex_destroy(&glock);
}

