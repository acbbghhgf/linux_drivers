kernel_dir=/home/ww/ARM/kernel
obj-m += btn_drv.o
all:
	make -C ${kernel_dir} SUBDIRS=$(PWD) modules

test:led_test.c
	arm-cortex_a9-linux-gnueabi-gcc led_test.c -o led_test

clean:
	make -C ${kernel_dir} SUBDIRS=$(PWD) clean
	rm ./led_test
