include ../../.config
CC = gcc
DEFS =   $(XINC) -I.. 

CFLAGS = -Wall -O2 -g $(DEFS)
CFLAGS2 = -Wall -O2 $(DEFS)
LIBS =   ../libxnet.a $(XLIB) -lxhttpd -lxfilter -lxlib -lpcap -lz -lresolv -lpthread -ldl -lm -lrt
LDFLAGS = $(LIBS)



all:	 xvendor xportpool class  xmac


xvendor: xvendor.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xvendor xvendor.o  $(LIBS)

xroute: xroute.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xroute xroute.o  $(LIBS)

xportpool: xportpool.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xportpool xportpool.o  $(LIBS)

class: class.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o class class.o  $(LIBS)

xmac: xmac.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xmac xmac.o  $(LIBS)


clean:
	@rm -f *.o *~ xvendor xroute xportpool class xmac


