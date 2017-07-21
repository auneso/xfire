/*
 ** 2017-02-02 HDS thread_setname
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/resource.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include "xvector.h"
#include "xalloc.h"
#include "thread.h"
#include "xlog.h"
#include "xproto.h"

#define KILOBYTE   1024
#define PTHREAD_STACK_SIZE     512 * KILOBYTE

static pthread_mutex_t mutex;
static pthread_cond_t  cond; 
static int tflag = -1;


pid_t ThreaGetPid (void)
{
  pid_t  pid;
 
#ifdef __linux__
  pid = syscall(SYS_gettid); /* gettid() is not available with glibc */
#else
  pid = getpid();
#endif
  return pid;
}

/*
 * Sets CPU priority for who.
 */
static void task_mode_cpu_priority (int prio)
{
  if (prio != 0) {
    if (setpriority(PRIO_PROCESS, ThreaGetPid(), prio) < 0) {
      fprintf(stderr, "ERROR: %s:%d %s.\n\n",  __FILE__, __LINE__, strerror(errno));
    }
  }
}


static int thread_setname (pthread_t id, const char *name)
{
        int ret = -1;
#if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
#if __GLIBC_PREREQ(2, 12)
        ret = pthread_setname_np(id, name);
#endif
#endif
        return ret;
}

#define MAX_THREAD_NAME_LEN 16

void ThreadAddTable (char *loc, int cpu, int prio)
{
  pid_t  pid;
#ifdef __linux__
  static int core_id = 1;
  if (cpu) {
    int s;
    cpu_set_t cpuset;
    int numCPU = sysconf(_SC_NPROCESSORS_ONLN);
    pid = syscall(SYS_gettid); /* gettid() is not available with glibc */

    if (numCPU < 4)  {
      fprintf(stderr, "pid = %d  %s\n", pid, loc);
    } else {

      CPU_ZERO(&cpuset);
      CPU_SET(core_id, &cpuset);

      if ((s = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset)) != 0)
        printf("Error while binding  core %d: errno=%i\n", core_id, s);
      else {
        printf("pid = %d %s, core = %d/%d\n", pid, loc, core_id, numCPU);
      }
      core_id = (core_id+1) % numCPU;
    }
  } else {
    pid = ThreaGetPid();
//  fprintf(stderr, "pid = %d %s\n", pid, loc);
  }
#else
  pid = getpid();
//  fprintf(stderr, "pid = %d %s\n", pid, loc);
#endif
  if (loc) {
    thread_setname(pthread_self(), loc);
  }

  task_mode_cpu_priority(prio);
  pthread_mutex_lock(&mutex);
  tflag = 1;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex); 
}

pthread_t ThreadCreate (void *(*func)(void *), void *arg)
{
  pthread_t       thread;
  pthread_attr_t  attr;
  int             ret;
  size_t stacksize;

  if (tflag == -1) {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
  }
  tflag = 0;

  if (pthread_attr_init(&attr) != 0) {
    fprintf(stderr, "pthread init error - %s\n", (char *)arg);
  } else
  if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
    fprintf(stderr, "pthread set detach state error - %s\n", (char *)arg);
  } else 
  if (pthread_attr_getstacksize (&attr, &stacksize) != 0) {
    fprintf(stderr, "pthread get stack size error\n");
  } else  {
    if (stacksize < PTHREAD_STACK_SIZE) {
      stacksize = PTHREAD_STACK_SIZE; 
      fprintf(stderr, "Amount of stack needed per thread = %d\n", (int)stacksize);
    }
    if (pthread_attr_setstacksize (&attr, stacksize) != 0) {
      fprintf(stderr, "pthread set stack size error = %dytes\n", (int)stacksize);
    } else
    if ((ret = pthread_create(&thread, &attr, func, arg)) != 0) {
      fprintf(stderr, "Can't create thread - %s\n", strerror(ret));
    } else  {
      pthread_mutex_lock(&mutex);
      while (tflag == 0)
        pthread_cond_wait(&cond, &mutex);
      pthread_mutex_unlock(&mutex);
      return thread;
    }
  }
  exit(1);
}

void ThreadAddMain (char *loc, int prio)
{
  ThreadAddTable(loc, 1, prio);
}

int MutexCreate (TMutex * const mutexP)
{
  return (pthread_mutex_init(mutexP, NULL) == 0);
}

int MutexLock (TMutex * const mutexP)
{
  return (pthread_mutex_lock(mutexP) == 0);
}

int MutexUnlock (TMutex * const mutexP)
{
  return (pthread_mutex_unlock(mutexP) == 0);
}

int MutexTryLock (TMutex * const mutexP)
{
  return (pthread_mutex_trylock(mutexP) == 0);
}

void MutexFree (TMutex * const mutexP)
{
  pthread_mutex_destroy(mutexP);
}


#if 0

xthread_t *xthread_create (int (*func)(void *), void *user)
{
  xthread_t *xt;
  void *stack;
  pid_t pid;
  
  xt    = xmalloc(sizeof(xthread_t));    
  stack = xmalloc(STACKSIZE);

#ifndef _BSD_
  // Call the clone system call to create the child thread
  pid = clone(func, stack + STACKSIZE, CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, user);
  if (pid == -1) {
    perror("clone() error");
    exit(2);
  }
#else
  // Call the rfork_thread  system call to create the child thread
  pid = rfork_thread(RFPROC|RFMEM, stack + STACKSIZE, func, user);
  if (pid == -1) {
    perror("rfork() error");
    exit(2);
  }
#endif
  xt->pid   = pid;
  xt->stack = stack;
  xt->user  = user;
  return xt;
}


void xthread_destory (xthread_t *t)
{
  if (t) {
    xfree(t->stack);
    xfree(t);
  }
}

/**
 * threadpool.c
 *
 * This file will contain your implementation of a threadpool.
 */

typedef struct _thread_st {
  sp_thread_t id;
  sp_thread_mutex_t mutex;
  sp_thread_cond_t cond;
  dispatch_fn fn;
  void *arg;
  threadpool parent;
} _thread;

// _threadpool is the internal threadpool structure that is
// cast to type "threadpool" before it given out to callers
typedef struct _threadpool_st {
  // you should fill in this structure with whatever you need
  sp_thread_mutex_t tp_mutex;
  sp_thread_cond_t tp_idle;
  sp_thread_cond_t tp_full;
  sp_thread_cond_t tp_empty;
  _thread ** tp_list;
  int tp_index;
  int tp_max_index;
  int tp_stop;

  int tp_total;
} _threadpool;

threadpool create_threadpool (int num_threads_in_pool)
{
  _threadpool *pool;

  // sanity check the argument
  if ((num_threads_in_pool <= 0) || (num_threads_in_pool > MAXT_IN_POOL))
    return NULL;

  pool = (_threadpool *)xmalloc(sizeof(_threadpool));
  if (pool == NULL) {
    fprintf(stderr, "Out of memory creating a new threadpool!\n");
    return NULL;
  }

  // add your code here to initialize the newly created threadpool
  sp_thread_mutex_init(&pool->tp_mutex, NULL);
  sp_thread_cond_init(&pool->tp_idle, NULL);
  sp_thread_cond_init(&pool->tp_full, NULL);
  sp_thread_cond_init(&pool->tp_empty, NULL);
  pool->tp_max_index = num_threads_in_pool;
  pool->tp_index = 0;
  pool->tp_stop = 0;
  pool->tp_total = 0;
  pool->tp_list = (_thread **)xmalloc(sizeof(void *) * MAXT_IN_POOL);
  memset(pool->tp_list, 0, sizeof(void *) * MAXT_IN_POOL);

  return (threadpool) pool;
}

int save_thread (_threadpool * pool, _thread * thread)
{
  int ret = -1;

  sp_thread_mutex_lock(&pool->tp_mutex);

  if (pool->tp_index < pool->tp_max_index) {
    pool->tp_list[ pool->tp_index ] = thread;
    pool->tp_index++;
    ret = 0;

    sp_thread_cond_signal(&pool->tp_idle);

    if (pool->tp_index >= pool->tp_total) {
      sp_thread_cond_signal(&pool->tp_full);
    }
  }

  sp_thread_mutex_unlock(&pool->tp_mutex);

  return ret;
}

sp_thread_result_t SP_THREAD_CALL wrapper_fn (void * arg)
{
  _thread * thread = (_thread*)arg;
  _threadpool * pool = (_threadpool*)thread->parent;

  for (; 0 == ((_threadpool*)thread->parent)->tp_stop;) {
    thread->fn(thread->arg);

    if (0 != ((_threadpool*)thread->parent)->tp_stop) break;

    sp_thread_mutex_lock(&thread->mutex);
    if (0 == save_thread(thread->parent, thread)) {
      sp_thread_cond_wait(&thread->cond, &thread->mutex);
      sp_thread_mutex_unlock(&thread->mutex);
    } else {
      sp_thread_mutex_unlock(&thread->mutex);
      sp_thread_cond_destroy(&thread->cond);
      sp_thread_mutex_destroy(&thread->mutex);

      xfree(thread);
      break;
    }
  }

  sp_thread_mutex_lock(&pool->tp_mutex);
  pool->tp_total--;
  if (pool->tp_total <= 0) sp_thread_cond_signal(&pool->tp_empty);
  sp_thread_mutex_unlock(&pool->tp_mutex);

  return 0;
}

int dispatch_threadpool (threadpool from_me, dispatch_fn dispatch_to_here, void *arg)
{
  int ret = 0;

  _threadpool *pool = (_threadpool *) from_me;
  sp_thread_attr_t attr;
  _thread * thread = NULL;

  // add your code here to dispatch a thread
  sp_thread_mutex_lock(&pool->tp_mutex);

  while (pool->tp_index <= 0 && pool->tp_total >= pool->tp_max_index) {
    sp_thread_cond_wait(&pool->tp_idle, &pool->tp_mutex);
  }

  if (pool->tp_index <= 0) {
    _thread * thread = (_thread *)xmalloc(sizeof(_thread));
    memset(&(thread->id), 0, sizeof(thread->id));
    sp_thread_mutex_init(&thread->mutex, NULL);
    sp_thread_cond_init(&thread->cond, NULL);
    thread->fn = dispatch_to_here;
    thread->arg = arg;
    thread->parent = pool;

    sp_thread_attr_init(&attr);
    sp_thread_attr_setdetachstate(&attr, SP_THREAD_CREATE_DETACHED);

    if (0 == sp_thread_create(&thread->id, &attr, wrapper_fn, thread)) {
      pool->tp_total++;
      printf("create thread#%ld\n", thread->id);
    } else {
      ret = -1;
      printf("cannot create thread\n");
      sp_thread_mutex_destroy(&thread->mutex);
      sp_thread_cond_destroy(&thread->cond);
      xfree(thread);
    }
  } else {
    pool->tp_index--;
    thread = pool->tp_list[ pool->tp_index ];
    pool->tp_list[ pool->tp_index ] = NULL;

    thread->fn = dispatch_to_here;
    thread->arg = arg;
    thread->parent = pool;

    sp_thread_mutex_lock(&thread->mutex);
    sp_thread_cond_signal(&thread->cond) ;
    sp_thread_mutex_unlock (&thread->mutex);
  }

  sp_thread_mutex_unlock(&pool->tp_mutex);

  return ret;
}

void destroy_threadpool (threadpool destroyme)
{
  _threadpool *pool = (_threadpool *) destroyme;

  // add your code here to kill a threadpool
  int i = 0;

  sp_thread_mutex_lock(&pool->tp_mutex);

  if (pool->tp_index < pool->tp_total) {
    printf("waiting for %d thread(s) to finish\n", pool->tp_total - pool->tp_index);
    sp_thread_cond_wait(&pool->tp_full, &pool->tp_mutex);
  }

  pool->tp_stop = 1;

  for (i = 0; i < pool->tp_index; i++) {
    _thread * thread = pool->tp_list[ i ];

    sp_thread_mutex_lock(&thread->mutex);
    sp_thread_cond_signal(&thread->cond) ;
    sp_thread_mutex_unlock (&thread->mutex);
  }

  if (pool->tp_total > 0) {
    printf("waiting for %d thread(s) to exit\n", pool->tp_total);
    sp_thread_cond_wait(&pool->tp_empty, &pool->tp_mutex);
  }

  for(i = 0; i < pool->tp_index; i++) {
    xfree(pool->tp_list[ i ]);
    pool->tp_list[ i ] = NULL;
  }

  sp_thread_mutex_unlock(&pool->tp_mutex);

  pool->tp_index = 0;

  sp_thread_mutex_destroy(&pool->tp_mutex);
  sp_thread_cond_destroy(&pool->tp_idle);
  sp_thread_cond_destroy(&pool->tp_full);
  sp_thread_cond_destroy(&pool->tp_empty);

  xfree(pool->tp_list);
  xfree(pool);
}
#endif
