/*************************************************************************
	> File Name: reenterable.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时51分11秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>

void doit(int n)
{
    int v;
    static int c = 0;
    v = c;
    v++;
    usleep(5000);
    c = v;
    printf("c = %d\n", c);
    return ;
}

int main()
{
    signal(2, doit);
    while(1)
        doit(333);
    return 0;
}

