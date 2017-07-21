
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
#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <pthread.h>
#define SPIN_MEMORY

/******************************************************
 *  Locks and associated operations
 ******************************************************/
#ifdef SPIN_MEMORY
typedef volatile int spin_mutex;
#else
typedef pthread_spin_t spin_mutex;
#endif

#ifdef __cplusplus
extern "C" {
#endif


void spin_mutex_init(spin_mutex *lock);
void spin_mutex_lock(spin_mutex *lock);
void spin_mutex_wait_lock(spin_mutex *lock, int cnt, int usec);
void spin_mutex_unlock(spin_mutex *lock);
int  spin_mutex_trylock(spin_mutex *lock);
void spin_mutex_destroy (spin_mutex *lock);

void global_mutex_init();
void global_mutex_lock();
void global_mutex_unlock();
int  global_mutex_trylock();
void global_mutex_destroy();

#ifdef __cplusplus
}
#endif

#endif
