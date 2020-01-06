#定义变量
NAME=uart_demo
BIN=$(NAME).bin
ELF=$(NAME).elf 
OBJ=main.o uart.o 

CROSS_COMPILE=arm-cortex_a9-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy
CP=cp
RM=rm
INSTALLPATH=/tftpboot
  
#链接选项
LDFLAGS=-nostdlib -nostartfiles -emain
#编译选项
CFLAGS=-nostdlib

#定义编译规则
#shell.bin:shell.elf
#   arm...objcopy -O binary shell.elf shell.bin
$(BIN):$(ELF)
	$(OBJCOPY) -O binary $(ELF) $(BIN)
	$(CP) $(BIN) $(INSTALLPATH)

#shell.elf:main.o uart.o led.o strcmp.o
#     arm...ld -nostartfiles -nostdlib -... -o shell.elf main.o ...
$(ELF):$(OBJ)
	$(LD) $(LDFLAGS) -o $(ELF) $(OBJ)

#各种.o:各种.c
#  各种编译
%.o:%.c
	$(CC) $(CFLAGS)	-c -o $@ $<
 
#伪目标
#当执行make clean时,仅仅执行clean伪目标对应的命令
clean:
	$(RM) $(BIN) $(ELF) $(OBJ)   

