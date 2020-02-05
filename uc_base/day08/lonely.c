/*************************************************************************
	> File Name: lonely.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 21时27分08秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return -1;
    }
    if(pid == 0)
    {
        sleep(5);
        printf("child ... pid = %d, ppid = %d\n", getpid(), getppid());
        exit(0);
    }
    else{
        printf("parent ... pid = %d\n", getpid());
        exit(0);
    }
    return 0;
}

