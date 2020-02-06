/*************************************************************************
	> File Name: wrap.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 08时55分11秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    execl("./upper", "upper", NULL);
    return 0;
}

