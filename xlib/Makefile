include ../.config
CC = gcc
DEFS =  -D_REENTRANT -D_GNU_SOURCE=1

CFLAGS  =  $(XFLAG) $(DEFS) $(XINC) # C compiler options
LIBNAME = libxlib.a

OBJS	= xalloc.o xprintf.o xstring.o hashf.o xfmem.o xdump.o cron.o screen.o \
          format.o xhash32.o hash64.o xhash64.o hashtab.o dbuf.o llist.o \
          spt.o rbtree.o xtimeval.o  thread.o htst.o bpm.o xsm.o mutex.o mtqueue.o \
          xvector.o tdate.o xsqueue.o xspqueue.o bmh.o salloc.o xsys.o \
          obstack.o prioq.o  itoa.o xrbt.o  xxhash.o  xrand.o  murmurhash.o

all:   $(LIBNAME) 

xalloc.o: xalloc.c xalloc.h
	$(CC) $(CFLAGS) xalloc.c
xprintf.o: xprintf.c xprintf.h
	$(CC) $(CFLAGS) xprintf.c
xstring.o: xstring.c xstring.h
	$(CC) $(CFLAGS) xstring.c
hashf.o: hashf.c hashf.h
	$(CC) $(CFLAGS) hashf.c
xfmem.o: xfmem.c xfmem.h
	$(CC) $(CFLAGS) xfmem.c
xdump.o: xdump.c xdump.h
	$(CC) $(CFLAGS) xdump.c
cron.o: cron.c cron.h
	$(CC) $(CFLAGS) cron.c
screen.o: screen.c screen.h
	$(CC) $(CFLAGS) screen.c
format.o: format.c format.h
	$(CC) $(CFLAGS) format.c
hash32.o: hash32.c hash32.h
	$(CC) $(CFLAGS) hash32.c
xhash32.o: xhash32.c xhash32.h
	$(CC) $(CFLAGS) xhash32.c
hash64.o: hash64.c hash64.h
	$(CC) $(CFLAGS) hash64.c
xhash64.o: xhash64.c xhash64.h
	$(CC) $(CFLAGS) xhash64.c
hashtab.o: hashtab.c hashtab.h
	$(CC) $(CFLAGS) hashtab.c
dbuf.o: dbuf.c dbuf.h
	$(CC) $(CFLAGS) dbuf.c
llist.o: llist.c llist.h
	$(CC) $(CFLAGS) llist.c
spt.o: spt.c spt.h
	$(CC) $(CFLAGS) spt.c
rbtree.o: rbtree.c rbtree.h
	$(CC) $(CFLAGS) rbtree.c
xtimeval.o: xtimeval.c xtimeval.h
	$(CC) $(CFLAGS) xtimeval.c
thread.o: thread.c thread.h
	$(CC) $(CFLAGS) thread.c
htst.o: htst.c htst.h
	$(CC) $(CFLAGS) htst.c
bpm.o: bpm.c bpm.h
	$(CC) $(CFLAGS) bpm.c
xsm.o: xsm.c xsm.h
	$(CC) $(CFLAGS) xsm.c
mutex.o: mutex.c mutex.h
	$(CC) $(CFLAGS) mutex.c
mtqueue.o: mtqueue.c mtqueue.h
	$(CC) $(CFLAGS) mtqueue.c
xvector.o: xvector.c xvector.h
	$(CC) $(CFLAGS) xvector.c
tdate.o: tdate.c tdate.h
	$(CC) $(CFLAGS) tdate.c
xsqueue.o: xsqueue.c xsqueue.h
	$(CC) $(CFLAGS) xsqueue.c
xspqueue.o: xspqueue.c xspqueue.h
	$(CC) $(CFLAGS) xspqueue.c
bmh.o: bmh.c bmh.h
	$(CC) $(CFLAGS) bmh.c
xtimer.o: xtimer.c xtimer.h
	$(CC) $(CFLAGS) xtimer.c
salloc.o: salloc.c salloc.h
	$(CC) $(CFLAGS) salloc.c
xsys.o: xsys.c xsys.h
	$(CC) $(CFLAGS) xsys.c
obstack.o: obstack.c obstack.h
	$(CC) $(CFLAGS) obstack.c

prioq.o: prioq.c prioq.h
	$(CC) $(CFLAGS) prioq.c
itoa.o: itoa.c 
	$(CC) $(CFLAGS) itoa.c
xrbt.o: xrbt.c xrbt.h
	$(CC) $(CFLAGS) xrbt.c

xxhash.o: xxhash.c xxhash.h
	$(CC) $(CFLAGS) xxhash.c

thrqueue.o: thrqueue.c thrqueue.h
	$(CC) $(CFLAGS) thrqueue.c
rptree.o: rptree.c rptree.h
	$(CC) $(CFLAGS) rptree.c
smalloc.o: smalloc.c smalloc.h
	$(CC) $(CFLAGS) smalloc.c
xrand.o: xrand.c xrand.h
	$(CC) $(CFLAGS) xrand.c
murmurhash.o: murmurhash.c murmurhash.h
	$(CC) $(CFLAGS) murmurhash.c

$(LIBNAME) : $(OBJS)
	rm -f $(LIBNAME)
	ar rc $(LIBNAME) $(OBJS)

clean:
	rm -f *.o *.a

