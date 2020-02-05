/*************************************************************************
	> File Name: zombile.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 21时49分04秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();

    if(pid < 0)
    {
        perror("fork");
        return 1;
    }
    if(pid == 0)
    {
        exit(0);
    }
    else{
        sleep(10);
        wait(NULL);
    }
    return 0;
}

