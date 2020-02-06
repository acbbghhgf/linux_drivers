/*************************************************************************
	> File Name: pause.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时40分51秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void doit(int n)
{
    printf("recv %d signal\n", n);
    return ;
}

int main()
{
    pid_t pid;
    printf("pid : %d\n", getpid());
    signal(2, doit);
    pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        printf("child pid %d\n", getpid());
        sleep(10);
        exit(0);
    }
    else{
        printf("parent pid %d\n", getpid());
        wait(NULL);
    }
    return 0;
}

