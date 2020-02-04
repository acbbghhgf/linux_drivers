/*************************************************************************
	> File Name: rw_file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 08时44分10秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0664);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    printf("file open success ...\n");
    close(fd);
    return 0;
}

