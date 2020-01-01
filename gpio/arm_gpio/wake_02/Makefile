kernel_dir=/home/ww/ARM/kernel
obj-m += wake_drv.o
all:
	make -C ${kernel_dir} SUBDIRS=$(PWD) modules

test:wake_test.c
	arm-cortex_a9-linux-gnueabi-gcc $^ -o wake_test

clean:
	make -C ${kernel_dir} SUBDIRS=$(PWD) clean
	rm ./wake_test
