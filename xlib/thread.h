#ifndef __THREAD_H__
#define __THREAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>


pid_t ThreaGetPid (void);
pthread_t ThreadCreate (void *(*func)(void *), void *arg);
void ThreadAddTable (char *loc, int cpu, int prio);
void ThreadAddMain (char *loc, int prio);

typedef pthread_mutex_t TMutex;

int  MutexCreate (TMutex * const mutexP);
int  MutexLock (TMutex * const mutexP);
int  MutexUnlock (TMutex * const mutexP);
int  MutexTryLock (TMutex * const mutexP);
void MutexFree (TMutex * const mutexP);


typedef struct thread_t {
  pid_t pid;
  void *stack;
  void *user;
} xthread_t;

// 64kB stack
#define STACKSIZE 1024*64

xthread_t *xthread_create(int (*func)(void *), void *user);
void xthread_destory(xthread_t *t);


#ifdef __cplusplus
extern "C" {
#endif

// maximum number of threads allowed in a pool
#define MAXT_IN_POOL 200

// You must hide the internal details of the threadpool
// structure from callers, thus declare threadpool of type "void".
// In threadpool.c, you will use type conversion to coerce
// variables of type "threadpool" back and forth to a
// richer, internal type.  (See threadpool.c for details.)

typedef void *threadpool;

// "dispatch_fn" declares a typed function pointer.  A
// variable of type "dispatch_fn" points to a function
// with the following signature:
// 
//     void dispatch_function(void *arg);

typedef void (*dispatch_fn)(void *);

/**
 * create_threadpool creates a fixed-sized thread
 * pool.  If the function succeeds, it returns a (non-NULL)
 * "threadpool", else it returns NULL.
 */
threadpool create_threadpool(int num_threads_in_pool);


/**
 * dispatch sends a thread off to do some work.  If
 * all threads in the pool are busy, dispatch will
 * block until a thread becomes free and is dispatched.
 * 
 * Once a thread is dispatched, this function returns
 * immediately.
 * 
 * The dispatched thread calls into the function
 * "dispatch_to_here" with argument "arg".
 */
int dispatch_threadpool(threadpool from_me, dispatch_fn dispatch_to_here,
        void *arg);

/**
 * destroy_threadpool kills the threadpool, causing
 * all threads in it to commit suicide, and then
 * frees all the memory associated with the threadpool.
 */
void destroy_threadpool(threadpool destroyme);

#ifndef WIN32

typedef void * sp_thread_result_t;
typedef pthread_mutex_t sp_thread_mutex_t;
typedef pthread_cond_t  sp_thread_cond_t;
typedef pthread_t       sp_thread_t;
typedef pthread_attr_t  sp_thread_attr_t;

#define sp_thread_mutex_init(m,a)   pthread_mutex_init(m,a)
#define sp_thread_mutex_destroy(m)  pthread_mutex_destroy(m)
#define sp_thread_mutex_lock(m)     pthread_mutex_lock(m)
#define sp_thread_mutex_unlock(m)   pthread_mutex_unlock(m)

#define sp_thread_cond_init(c,a)    pthread_cond_init(c,a)
#define sp_thread_cond_destroy(c)   pthread_cond_destroy(c)
#define sp_thread_cond_wait(c,m)    pthread_cond_wait(c,m)
#define sp_thread_cond_signal(c)    pthread_cond_signal(c)

#define sp_thread_attr_init(a)        pthread_attr_init(a)
#define sp_thread_attr_setdetachstate pthread_attr_setdetachstate
#define SP_THREAD_CREATE_DETACHED     PTHREAD_CREATE_DETACHED

#define sp_thread_self    pthread_self
#define sp_thread_create  pthread_create

#define SP_THREAD_CALL
typedef sp_thread_result_t ( * sp_thread_func_t )( void * args );

#define sp_sleep(x) sleep(x)

#else ///////////////////////////////////////////////////////////////////////



// win32 thread

#include <winsock2.h>
#include <process.h>

typedef unsigned sp_thread_t;

typedef unsigned sp_thread_result_t;
#define SP_THREAD_CALL __stdcall
typedef sp_thread_result_t ( __stdcall * sp_thread_func_t )( void * args );

typedef HANDLE  sp_thread_mutex_t;
typedef HANDLE  sp_thread_cond_t;
typedef DWORD   sp_thread_attr_t;

#define SP_THREAD_CREATE_DETACHED 1
#define sp_sleep(x) Sleep(1000*x)

int sp_thread_mutex_init( sp_thread_mutex_t * mutex, void * attr )
{
  *mutex = CreateMutex( NULL, FALSE, NULL );
  return NULL == * mutex ? GetLastError() : 0;
}

int sp_thread_mutex_destroy( sp_thread_mutex_t * mutex )
{
  int ret = CloseHandle( *mutex );

  return 0 == ret ? GetLastError() : 0;
}

int sp_thread_mutex_lock( sp_thread_mutex_t * mutex )
{
  int ret = WaitForSingleObject( *mutex, INFINITE );
  return WAIT_OBJECT_0 == ret ? 0 : GetLastError();
}

int sp_thread_mutex_unlock( sp_thread_mutex_t * mutex )
{
  int ret = ReleaseMutex( *mutex );
  return 0 != ret ? 0 : GetLastError();
}

int sp_thread_cond_init( sp_thread_cond_t * cond, void * attr )
{
  *cond = CreateEvent( NULL, FALSE, FALSE, NULL );
  return NULL == *cond ? GetLastError() : 0;
}

int sp_thread_cond_destroy( sp_thread_cond_t * cond )
{
  int ret = CloseHandle( *cond );
  return 0 == ret ? GetLastError() : 0;
}

/*
Caller MUST be holding the mutex lock; the
lock is released and the caller is blocked waiting
on 'cond'. When 'cond' is signaled, the mutex
is re-acquired before returning to the caller.
*/
int sp_thread_cond_wait( sp_thread_cond_t * cond, sp_thread_mutex_t * mutex )
{
  int ret = 0;

  sp_thread_mutex_unlock( mutex );

  ret = WaitForSingleObject( *cond, INFINITE );

  sp_thread_mutex_lock( mutex );

  return WAIT_OBJECT_0 == ret ? 0 : GetLastError();
}

int sp_thread_cond_signal( sp_thread_cond_t * cond )
{
  int ret = SetEvent( *cond );
  return 0 == ret ? GetLastError() : 0;
}

sp_thread_t sp_thread_self()
{
  return GetCurrentThreadId();
}

int sp_thread_attr_init( sp_thread_attr_t * attr )
{
  *attr = 0;
  return 0;
}

int sp_thread_attr_setdetachstate( sp_thread_attr_t * attr, int detachstate )
{
  *attr |= detachstate;
  return 0;
}

int sp_thread_create(sp_thread_t * thread, sp_thread_attr_t * attr, sp_thread_func_t myfunc, void * args )
{
  // _beginthreadex returns 0 on an error
  HANDLE h = (HANDLE)_beginthreadex( NULL, 0, myfunc, args, 0, thread );
  return h > 0 ? 0 : GetLastError();
}

#endif

#ifdef __cplusplus
}
#endif

#endif
