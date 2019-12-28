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

#define LED_ON 0x100001
#define LED_OFF 0x100002


int main(int argc, char *argv[])
{
    int fd;
    int index;
    
    if(argc != 3)
    {
        printf("use : %s <on | off> <1 | 2 | 3 | 4>\n", argv[0]);
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

    index = strtol(argv[2], NULL, 0);
    if(!strcmp(argv[1], "on"))
        ioctl(fd, LED_ON, &index);
    else if(!strcmp(argv[1], "off"))
        ioctl(fd, LED_OFF, &index);

    sleep(3);
    printf("close myled.\n");

    close(fd);
    return 0;
}

