include ../../.config
CC = gcc
DEFS =    $(XINC)

CFLAGS = -O3 -g $(DEFS)
#CFLAGS = -Wall -O2 $(DEFS)
#LDFLAGS = -static
LIBS =   ../libxfilter.a $(XLIB) -lxlib -lpthread

all:	 xipmap_test xipmap xipmap2 xfilter xportmap xiport xipfind xradix \
         bignum mpi xiptree xiparser xport xiptable

xipmap_test:	 xipmap_test.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xipmap_test xipmap_test.o $(LIBS)

xipmap:	 xipmap.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xipmap xipmap.o $(LIBS)

xipmap2: xipmap2.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xipmap2 xipmap2.o $(LIBS)

xfilter: xfilter.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xfilter xfilter.o $(LIBS)

xportmap: xportmap.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xportmap xportmap.o $(LIBS)

xiport: xiport.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xiport xiport.o $(LIBS)

xipfind: xipfind.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xipfind xipfind.o $(LIBS)

xradix: xradix.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xradix xradix.o $(LIBS)

grepcidr: grepcidr.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o grepcidr grepcidr.o $(LIBS)

bignum: bignum.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o bignum bignum.o $(LIBS)

mpi: mpi.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o mpi mpi.o $(LIBS)

xiptree: xiptree.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xiptree xiptree.o $(LIBS)

xiparser: xiparser.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xiparser xiparser.o $(LIBS)

xport: xport.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xport xport.o $(LIBS)

xiptable: xiptable.o 
	 @rm -f $@
	 $(CC) $(CFLAGS) $(LDFLAGS) -o xiptable xiptable.o $(LIBS)

clean:
	@rm -f *.o *~  xipmap_test xipmap xipmap2 xfilter xportmap xiport xipfind xradix grepcidr \
	bignum mpi xiptree iparser xport xiptable

