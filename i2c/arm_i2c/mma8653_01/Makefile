kernel_dir=/home/ww/ARM/kernel
obj-m += mymma8653_drv.o
all:
	make -C ${kernel_dir} SUBDIRS=$(PWD) modules

test:mma8653_test.c
	arm-cortex_a9-linux-gnueabi-gcc $^ -o mma8653_test

clean:
	make -C ${kernel_dir} SUBDIRS=$(PWD) clean
	rm ./mma8653_test
