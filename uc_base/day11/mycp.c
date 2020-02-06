/*************************************************************************
	> File Name: mycp.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 20时38分12秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void copy_file(int s, int d)
{
    int r, w;
    char buf[1024];
    char *tmp;

    r = read(s, buf, 1024);
    while(r > 0)
    {
        tmp = buf;
        while(1)
        {
            w = write(d, tmp, r);
            r = r-w;
            tmp += w;
            if(r== 0)
                break;
        }
    }
    return ;
}

int main(int argc, char *argv[])
{
    int s_fd, d_fd;
    s_fd = open(argv[1], O_RDONLY);
    if(s_fd < 0)
    {
        perror("open");
        return -1;
    }

    d_fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0664);
    if(d_fd < 0)
    {
        perror("open");
        return -2;
    }
    
    copy_file(s_fd, d_fd);
    close(s_fd);
    close(d_fd);
    printf(":) copy end...\n");
    return 0;
}

