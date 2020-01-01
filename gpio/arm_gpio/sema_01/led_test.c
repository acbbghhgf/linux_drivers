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
    int i;
    fd = open("/dev/myled", O_RDWR);
    if(fd < 0)
    {
        printf("open myled fail.\n");
        perror("open fail.\n");
        return -1;
    }
    printf("open myled.\n");
    for(i = 8; i > 0; i--)
    {
        sleep(1);
        printf("wait %d s \n", i);
    }
    printf("close myled.\n");
    close(fd);
    return 0;
}

