/*************************************************************************
	> File Name: raise.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时15分52秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>

void doit(int n)
{
    printf("recv signum ... %d\n", n);
    return ;
}

int main()
{
    printf("pid : %d\n", getpid());
    signal(2, doit);
    while(1)
    {
        sleep(2);
        raise(2);
    }
    return 0;
}

