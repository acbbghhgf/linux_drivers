#定义变量
NAME=shell
BIN=$(NAME).bin
ELF=$(NAME).elf 
OBJ=main.o uart.o led.o strcmp.o

CROSS_COMPILE=arm-cortex_a9-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy
CP=cp
RM=rm
INSTALLPATH=/tftpboot
  
#链接选项
LDFLAGS=-nostdlib -nostartfiles -Ttext=0x48000000 -emain
#编译选项
CFLAGS=-nostdlib

#定义编译规则
shell.bin:shell.elf
	arm-cortex_a9-linux-gnueabi-objcopy -O binary shell.elf shell.bin

$(BIN):$(ELF)
	$(OBJCOPY) -O binary $(ELF) $(BIN)
	$(CP) $(BIN) $(INSTALLPATH)
$(ELF):$(OBJ)
	$(LD) $(LDFLAGS) -o $(ELF) $(OBJ)
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
		$(RM) $(BIN) $(ELF) $(OBJ)   
