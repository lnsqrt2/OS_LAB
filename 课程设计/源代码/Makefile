#Makefile

obj-m:=proj3_Device.o
KDIR:=/lib/modules/$(shell uname -r)/build
SRCPWD:=$(shell pwd)
all:
	make -C $(KDIR) M=$(SRCPWD) modules
clean:
	rm -rf proj3_Device.o
