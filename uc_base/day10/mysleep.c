/*************************************************************************
	> File Name: mysleep.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时45分44秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>

void doit(int n)
{
    printf("recv signal %d ...\n", n);
    return ;
}

unsigned int mysleep(unsigned int seconds)
{
    signal(SIGALRM, doit);
    int l = alarm(seconds);
    pause();
    return l;
}

int main()
{
    while(1)
    {
        mysleep(4);
        printf("sleep after.\n");
    }
    return 0;
}

