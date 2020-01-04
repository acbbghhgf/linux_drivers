obj-m += led_drv.o led_dev.o
all:
	make -C /home/ww/ARM/kernel SUBDIRS=$(PWD) modules

test: led_test.c
	arm-cortex_a9-linux-gnueabi-gcc $< -o led_test
clean:
	make -C /home/ww/ARM/kernel SUBDIRS=$(PWD) clean
	rm led_test
