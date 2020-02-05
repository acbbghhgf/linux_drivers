/*************************************************************************
	> File Name: processA.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 08时36分25秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    fd = open("hello", O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 6;

    int f = fcntl(fd, F_SETLKW, &lock);
    if(f < 0)
    {
        perror("fcntl");
        return -2;
    }
    printf(" B add write lock success... \n");
    getchar();
    close(fd);
    return 0;
}

