/*************************************************************************
	> File Name: led_test.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月23日 星期一 21时59分34秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define LED_ON 0x100001
#define LED_OFF 0x100002


int main(int argc, char *argv[])
{
    int fd;
    void *gpiobase;

    unsigned long *gpiocout;
    unsigned long *gpiocoutenb;
    unsigned long *gpiocaltfn0;
    
    if(argc != 2)
    {
        printf("use : %s <on | off> \n", argv[0]);
        return -1;
    }

    fd = open("/dev/myled", O_RDWR);
    if(fd < 0)
    {
        printf("open myled fail.\n");
        return -1;
    }
    else
    {
        printf("open myled success.\n");
    }
    
    gpiobase = mmap(0, 0x100, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    gpiocout = (unsigned long *)(gpiobase + 0x00);
    gpiocoutenb = (unsigned long *)(gpiobase + 0x04);
    gpiocaltfn0 = (unsigned long *)(gpiobase + 0x20);

    //配置引脚为GPIO功能，配置为输出，输出1
    *gpiocaltfn0 &= ~(0x3 << 24);
    *gpiocaltfn0 |= (1 << 24);
    *gpiocoutenb |= (1 << 12);
    *gpiocout |= (1 << 12);

    //根据用户命令开关灯:
    if(!strcmp(argv[1], "on"))
        *gpiocout &= ~(1 << 12);
    else if(!strcmp(argv[1], "off"))
        *gpiocout |= (1 << 12);

    sleep(5);
    
    //解除地址映射
    munmap(gpiobase, 0x100);

    printf("close myled.\n");

    close(fd);
    return 0;
}

