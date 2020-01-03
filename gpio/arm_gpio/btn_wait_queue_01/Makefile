kernel_dir=/home/ww/ARM/kernel
obj-m += btn_drv.o
all:
	make -C ${kernel_dir} SUBDIRS=$(PWD) modules

test:btn_test.c
	arm-cortex_a9-linux-gnueabi-gcc $^ -o btn_test

clean:
	make -C ${kernel_dir} SUBDIRS=$(PWD) clean
	rm ./btn_test
