/*************************************************************************
	> File Name: exec.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 21时54分37秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *const ps_argv[] = {"ps", "-o", "pid,ppid,pgrp,comm", NULL};

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
        execl("/bin/ps", "ps", "-o", "pid,ppid,pgrp,comm", NULL);
        execvp("ps", ps_argv);
    }
    else{
        wait(NULL);
    }
    return 0;
}

