/*************************************************************************
	> File Name: blocked.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时26分10秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>

void doit(int n)
{
    printf("recv %d signal...\n", n);
    return ;
}

int main()
{
    sigset_t block;
    printf("pid : %d\n", getpid());

    signal(64, doit);

    sigemptyset(&block);
    sigaddset(&block, 64);
    sigprocmask(SIG_SETMASK, &block, NULL);
    sleep(10);

    sigprocmask(SIG_UNBLOCK, &block, NULL);
    return 0;
}

