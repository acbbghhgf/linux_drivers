kernel_dir=/home/ww/ARM/kernel
obj-m += led_drv.o
all:
	make -C ${kernel_dir} SUBDIRS=$(PWD) modules
clean:
	make -C ${kernel_dir} SUBDIRS=$(PWD) clean
