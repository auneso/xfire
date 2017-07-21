include ../.config
CC        = gcc
CFLAGS    = $(XFLAG) -D_REENTRANT -D_GNU_SOURCE $(XINC) -I./ 
LIBNAME   = libxjsonrpc.a
OBJ    = json_traffic.o json_alert_data.o json_system.o  \
         json_xarp_list.o json_xdev_list.o  json_error.o jsonrpc_registry.o

all: $(LIBNAME)

JASON_CFLAGS  = -I../jsonrpc/

json_traffic:
	$(CC) $(CFLAGS) $(JASON_CFLAGS) -c json_traffic.c

json_alert_data:
	$(CC) $(CFLAGS) $(JASON_CFLAGS) -c json_alert_data.c

json_system:
	$(CC) $(CFLAGS) $(JASON_CFLAGS) -c json_system.c

json_xarp_list:
	$(CC) $(CFLAGS) $(JASON_CFLAGS) -c json_xarp_list.c

json_xdev_list:
	$(CC) $(CFLAGS) $(JASON_CFLAGS) -c json_xdev_list.c

json_error:
	$(CC) $(CFLAGS) $(JASON_CFLAGS) -c json_error.c

jsonrpc_registry:
	$(CC) $(CFLAGS) $(JASON_CFLAGS) -c jsonrpc_registry.c

$(LIBNAME) : $(OBJ) 
	rm -f $(LIBNAME)
	ar rc $(LIBNAME) $(OBJ) 

clean:
	rm -f *.a *.o *~

# EOF
