/*************************************************************************
	> File Name: wake_test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月01日 星期三 21时52分08秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;

    fd = open("/dev/mywake", O_RDWR);
    if(fd < 0)
    {
        perror("open device fail");
        return -1;
    }
    if(argc != 2)
    {
        printf("useage : %s <r | w> \n", argv[0]);
        return -1;
    }

    if(!strcmp(argv[1], "r"))
    {
        read(fd, NULL, 0);
    }
    else if(!strcmp(argv[1], "w"))
    {
        write(fd, NULL, 0);
    }

    close(fd);
    return 0;
}

