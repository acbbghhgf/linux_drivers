3210**********************************************************************
	> File Name: lseek.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 08时48分54秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char buf[6];
    fd = open(argv[1], O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    lseek(fd, 120, SEEK_SET);
    int r = read(fd, buf, 4);
    write(1, buf, r);

    lseek(fd, 0, SEEK_END);
    write(fd, buf, r);

    close(fd);
    return 0;
}
