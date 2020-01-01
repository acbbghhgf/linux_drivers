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

int main()
{
    int fd;
    fd = open("/dev/myled", O_RDWR);
    if(fd < 0)
    {
        printf("open myled fail.\n");
        perror("open fail.\n");
        return -1;
    }
    printf("open myled.\n");
    sleep(1000);
    printf("close myled.\n");
    close(fd);
    return 0;
}

