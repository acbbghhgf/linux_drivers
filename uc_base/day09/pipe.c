/*************************************************************************
	> File Name: pipe.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 09时05分10秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int fd[2];
    char msg[] = "this is a test\n";
    char buf[128];
    
    int r = pipe(fd);
    if(r < 0)
    {
        perror("pipe");
        return 2;
    }

    pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        //close read fd
        close(fd[0]);
        write(fd[1], msg, strlen(msg));
        exit(0);
    }
    else{
        //close write fd
        close(fd[1]);
        int rt = read(fd[0], buf, 128);
        write(1, buf, rt);
        wait(NULL);
    }
    return 0;
}

