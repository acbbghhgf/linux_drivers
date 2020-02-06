/*************************************************************************
	> File Name: mykill.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时13分17秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int signum = atoi(argv[1]);
    pid_t pid = atoi(argv[2]);
    kill(pid, signum);
    return 0;
}

