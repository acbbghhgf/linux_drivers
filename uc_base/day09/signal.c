/*************************************************************************
	> File Name: signal.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时05分48秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>

void doit(int n)
{
    printf("recv signal ...\n");
    return ;
}

int main()
{
    printf("pid : %d\n", getpid());
    signal(2, SIG_IGN);
    signal(3, doit);

    while(1);
    return 0;
}

