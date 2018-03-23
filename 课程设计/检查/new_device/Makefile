#Makefile

obj-m:=s_device.o
KDIR:=/lib/modules/$(shell uname -r)/build
SRCPWD:=$(shell pwd)
all:
	make -C $(KDIR) M=$(SRCPWD) modules
clean:
	rm -rf s_device.o
