/*************************************************************************
	> File Name: timer.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 11时04分46秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void doit(int n)
{
    printf("recv signal ... \n");
    return ;
}

int main()
{
    struct itimerval new;
    new.it_value.tv_sec = 5;
    new.it_value.tv_usec = 0;
    new.it_interval.tv_sec = 0;
    new.it_interval.tv_usec = 500000;

    signal(SIGALRM, doit);
    setitimer(ITIMER_REAL, &new, NULL);
    while(1)
    {
        pause();
    }
    return 0;
}

