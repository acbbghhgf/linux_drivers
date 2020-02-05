/*************************************************************************
	> File Name: wait.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 21时33分22秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int s;
    pid = fork();

    if(pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if(pid == 0)
    {
        printf("child pid = %d\n", getpid());
        getchar();
        exit(1);
    }
    else{
        wait(&s);
        if(WIFEXITED(s))
        {
            printf("status : %d\n", WEXITSTATUS(s));
        }
        if(WIFSIGNALED(s))
        {
            printf("signum : %d\n", WTERMSIG(s));
        }
        printf("parent ...\n");
    }
    return 0;
}

