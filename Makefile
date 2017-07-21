include /home/xfire/.config
ifeq ($(RTE_SDK),)
$(error "Please define RTE_SDK environment variable")
endif

# Default target, can be overriden by command line or environment
RTE_TARGET ?= x86_64-native-linuxapp-gcc

include $(RTE_SDK)/mk/rte.vars.mk
APP=xfire

SRCS-y := $(XFIRE_HOME)/xnet/xfire.c

CFLAGS  +=  $(XINC) # C compiler options
LDFLAGS += $(XLIB) -lxnet -lxfilter -lxhttpd -lxlib -lxjsonrpc -ljrpc -lpthread -lm -lrt -ldl
DIRS-y += $(XFIRE_HOME)/xnet $(XFIRE_HOME)/xfilter $(XFIRE_HOME)/xlib $(XFIRE_HOME)/xhttpd $(XFIRE_HOME)/xjsonrpc $(XFIRE_HOME)/jsonrpc

include $(RTE_SDK)/mk/rte.extsubdir.mk
include $(RTE_SDK)/mk/rte.extapp.mk

xinstall :
	cp -f ./build/xfire /xfire/xfire

xclean :
	rm -f ./build/xfire
