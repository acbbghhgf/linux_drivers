/*************************************************************************
	> File Name: system.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 22时01分14秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
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
       // execl("./myt", "myt", NULL);
        system("./myt");
        exit(0);
    }
    else{
        wait(NULL);
    }
    return 0;
}

