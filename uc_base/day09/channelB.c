/*************************************************************************
	> File Name: channelA.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 09时13分32秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buf[128];

    int fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }

    int r = read(fd, buf, 128);
    write(1, buf, r);
    close(fd);
    return 0;
}

