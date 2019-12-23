KERNELDIR := /home/ww/loongson/kernel/linux-3.10/
PWD :=$(shell pwd)

obj-m += gpio_drv.o

default:
	echo "please make ARCH=mips!!!!!"
	$(MAKE) -C $(KERNELDIR)  M=$(PWD)  
clean:
	rm -rf .tmp_versions Module.symvers *.mod.c *.o *.ko .*.cmd Module.markers modules.order
