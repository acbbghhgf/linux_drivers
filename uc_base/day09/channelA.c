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
    char msg[] = "hello world\n";
    int m = mkfifo(argv[1], 0664);
    if(m < 0)
    {
        perror("mkfifo");
        return -1;
    }

    int fd = open(argv[1], O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -2;
    }

    sleep(10);
    write(fd, msg, strlen(msg) + 1);
    sleep(10);
    close(fd);
    return 0;
}

