/*************************************************************************
	> File Name: led_test.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月23日 星期一 21时59分34秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LED_ON 0x100001
#define LED_OFF 0x100002


int main(int argc, char *argv[])
{
    int fd1, fd2, fd3, fd4;

    fd1 = open("/dev/myled1", O_RDWR);
    if(fd1 < 0)
    {
        printf("open file fail.\n");
        perror("open faile.\n");
        return -1;
    }
    fd2 = open("/dev/myled2", O_RDWR);
    if(fd2 < 0)
    {
        printf("open file fail.\n");
        perror("open faile.\n");
        return -1;
    }
    fd3 = open("/dev/myled3", O_RDWR);
    if(fd3 < 0)
    {
        printf("open file fail.\n");
        perror("open faile.\n");
        return -1;
    }
    fd4 = open("/dev/myled4", O_RDWR);
    if(fd4 < 0)
    {
        printf("open file fail.\n");
        perror("open faile.\n");
        return -1;
    }

    while(1)
    {
        ioctl(fd1, LED_ON);
        sleep(1);
        ioctl(fd2, LED_ON);
        sleep(1);
        ioctl(fd3, LED_ON);
        sleep(1);
        ioctl(fd4, LED_ON);
        sleep(1);
        ioctl(fd1, LED_OFF);
        sleep(1);
        ioctl(fd2, LED_OFF);
        sleep(1);
        ioctl(fd3, LED_OFF);
        sleep(1);
        ioctl(fd4, LED_OFF);
        sleep(1);
    }

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);


    return 0;
}

