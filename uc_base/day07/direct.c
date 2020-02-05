/*************************************************************************
	> File Name: direct.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 08时22分08秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd, s_fd;
    char msg[] = "this is a test\n";
    fd = open("somefile", O_RDWR | O_CREAT, 0664);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    s_fd = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
    close(fd);

    write(STDOUT_FILENO, msg, strlen(msg));
    //dup2(s_fd, STDOUT_FILENO);
    //write(STDOUT_FILENO, msg, strlen(msg));
    close(s_fd);
    return 0;
}

