# Makefile for kernel Module
#
#

obj-m += simpletimer.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=`pwd`

clean:
	make -C /lib/modules/$(shell uname -r)/build M=`pwd` clean
