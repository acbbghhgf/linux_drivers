/*************************************************************************
	> File Name: mycat.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 08时39分47秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd, r;
    char buf[128];
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    while(1)
    {
        r = read(fd, buf, 128);
        if(r <= 0)
        {
            printf("file read down.\n");
            break;
        }
        write(1, buf, r);
    }
    close(fd);
    return 0;
}

