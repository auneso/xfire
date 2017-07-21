include ../.config
CC = gcc
DEFS =  -D_REENTRANT -D_GNU_SOURCE=1

CFLAGS  +=  $(XFLAG) $(DEFS) $(XINC) # C compiler options
LIBNAME = libxnet.a

OBJS    = xdpdk.o xnet.o xconfig.o xpacket.o xbridge.o xarp.o xdhcp.o \
          xicmp.o xtraffic.o xvendor.o xcksum.o xwhite.o xblack.o xwall.o xportpool.o \
          xlog.o xvhost.o xsession.o xinline.o xl3sw.o xnat.o xroute.o xalert.o \
          xcli.o
         

all:   $(LIBNAME) 

xdpdk.o: xdpdk.c xdpdk.h
	$(CC) $(XFLAG) $(CFLAGS) xdpdk.c
xnet.o: xnet.c xnet.h
	$(CC) $(XFLAG) $(CFLAGS) xnet.c
xconfig.o: xconfig.c xconfig.h
	$(CC) $(XFLAG) $(CFLAGS) xconfig.c
xpacket.o : xpacket.c xpacket.h
	$(CC) $(XFLAG) $(CFLAGS) xpacket.c
xbridge.o :  xbridge.c xbridge.h
	$(CC) $(XFLAG) $(CFLAGS) xbridge.c
xarp.o : xarp.c xarp.h
	$(CC) $(XFLAG) $(CFLAGS) xarp.c
xdhcp.o : xdhcp.c xdhcp.h
	$(CC) $(XFLAG) $(CFLAGS) xdhcp.c
xicmp.o : xicmp.c xicmp.h
	$(CC) $(XFLAG) $(CFLAGS) xicmp.c
xtraffic.o: xtraffic.c xtraffic.h
	$(CC) $(XFLAG) $(CFLAGS) xtraffic.c
xvendor.o: xvendor.h
	$(CC) $(XFLAG) $(CFLAGS) xvendor.c
xcksum.o: xcksum.c xcksum.h
	$(CC) $(XFLAG) $(CFLAGS) xcksum.c
xwhite.o : xwhite.c xwhite.h
	$(CC) $(XFLAG) $(CFLAGS) xwhite.c
xblack.o : xblack.c xblack.h
	$(CC) $(XFLAG) $(CFLAGS) xblack.c
xwall.o : xwall.c xwall.h
	$(CC) $(XFLAG) $(CFLAGS) xwall.c
xportpool.o : xportpool.c xportpool.h
	$(CC) $(XFLAG) $(CFLAGS) xportpool.c
xlog.o : xlog.c xlog.h
	$(CC) $(XFLAG) $(CFLAGS) xlog.c
xvhost.o : xvhost.c xvhost.h
	$(CC) $(XFLAG) $(CFLAGS) xvhost.c
xsession.o : xsession.c xsession.h
	$(CC) $(XFLAG) $(CFLAGS) xsession.c
xinline.o : xinline.c xinline.h
	$(CC) $(XFLAG) $(CFLAGS) xinline.c
xl3sw.o : xl3sw.c xl3sw.h
	$(CC) $(XFLAG) $(CFLAGS) xl3sw.c
xnat.o : xnat.c xnat.h
	$(CC) $(XFLAG) $(CFLAGS) xnat.c
xroute.o : xroute.c xroute.h
	$(CC) $(XFLAG) $(CFLAGS) xroute.c
xalert.o : xalert.c xalert.h
	$(CC) $(XFLAG) $(CFLAGS) xalert.c
xcli.o : xcli.c xcli.h
	$(CC) $(XFLAG) $(CFLAGS) xcli.c

$(LIBNAME) : $(OBJS) $(POBJS)
	rm -f $(LIBNAME)
	ar rc $(LIBNAME) $(OBJS) $(POBJS)

LDLIBS += $(LIBNAME)

clean:
	rm -f *.o *.a
