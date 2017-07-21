include ../.config
CFLAGS          = $(XFLAG) -std=gnu99 -D_GNU_SOURCE -D_REENTRANT -I../xlib -I../xhttpd
LIBS            = -lpthread -lm
ARCH        = libjrpc.a

LIB_OBJS    = xjson.o debug.o linkhash.o printbuf.o arraylist.o json_object.o  json_util.o \
              json_object_iterator.o json_tokener.o  hashmap.o  cbuffer.o jsonrpc.o


LIB_HDRS    = xjson.h debug.h linkhash.h printbuf.h arraylist.h json_object.h  json_util.h  \
              json_object_iterator.h json_tokener.h   hashmap.h  cbuffer.h jsonrpc.h


all: ${ARCH}
$(ARCH):	$(LIB_OBJS)
	$(AR) $(ARFLAGS) $(ARCH) $?
clean:
	rm -f *.o *~ *.a


