/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 09时00分52秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        printf("i am child process...[pid = %d]\n", getpid());
    }
    else{
        printf("i am parent process...[pid = %d]\n", getpid());
    }
    return 0;
}

