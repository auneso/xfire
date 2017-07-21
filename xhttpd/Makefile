include ../.config
CC = gcc
CPP = g++
DEFS = -D_REENTRANT -D_GNU_SOURCE=1 -I./ -I../lib/include -I../xlib -I../jsonrpc  -I../xnet  

CFLAGS  = $(XFLAG) $(DEFS)  # C compiler options
LIBNAME = libxhttpd.a


OBJS = xhttpd.o mongoose.o
    
POBJS = 
 
all:   $(LIBNAME)


xhttpd.o : xhttpd.c xhttpd.h
	$(CC) $(CFLAGS) xhttpd.c

mongoose.o : mongoose.c mongoose.h
	$(CC) $(CFLAGS) mongoose.c

$(LIBNAME) : $(OBJS) $(POBJS)
	rm -f $(LIBNAME)
	ar rc $(LIBNAME) $(OBJS) $(POBJS)

clean:
	rm -f *.o *.a


