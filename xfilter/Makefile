include ../.config
CC = gcc
CPP = g++

DEFS =  -D_REENTRANT -D_GNU_SOURCE=1 -I./ $(XINC)
CFLAGS  = $(XFLAG) $(DEFS)  # C compiler options
LIBNAME = libxfilter.a
HEADERS = xfilter.h xipmap.h xportmap.h xiport.h vportmap.h xipfind.h


OBJS =  xfilter.o xiparser.o xipmap.o xiptree.o xportmap.o xiport.o vportmap.o \
        xipfind.o atp.o xnode.o xradix.o patricia.o radix32.o ptree.o xport.o \
        bignum.o
   
 
all:   $(LIBNAME)


xfilter.o : xfilter.c xfilter.h
	$(CC) $(CFLAGS) xfilter.c

xiparser.o : xiparser.c xiparser.h
	$(CC) $(CFLAGS) xiparser.c

xipmap.o : xipmap.c xipmap.h
	$(CC) $(CFLAGS) xipmap.c

xiptree.o : xiptree.c xiptree.h
	$(CC) $(CFLAGS) xiptree.c

xportmap.o : xportmap.c xportmap.h
	$(CC) $(CFLAGS) xportmap.c

xiport.o : xiport.c xiport.h
	$(CC) $(CFLAGS) xiport.c

vportmap.o : vportmap.c vportmap.h
	$(CC) $(CFLAGS) vportmap.c

xipfind.o : xipfind.c xipfind.h
	$(CC) $(CFLAGS) xipfind.c

atp.o : atp.c atp.h
	$(CC) $(CFLAGS) atp.c

xnode.o : xnode.c xnode.h
	$(CC) $(CFLAGS) xnode.c

xradix.o : xradix.c xradix.h
	$(CC) $(CFLAGS) xradix.c

patricia.o : patricia.c patricia.h
	$(CC) $(CFLAGS) patricia.c

radix32.o : radix32.c radix32.h
	$(CC) $(CFLAGS) radix32.c

ptree.o : ptree.c ptree.h
	$(CC) $(CFLAGS) ptree.c

xport.o : xport.c xport.h
	$(CC) $(CFLAGS) xport.c

bignum.o : bignum.c bignum.h
	$(CC) $(CFLAGS) bignum.c

$(LIBNAME) : $(OBJS) $(POBJS)
	rm -f $(LIBNAME)
	ar rc $(LIBNAME) $(OBJS) $(POBJS)

clean:
	rm -f *.o *.a


