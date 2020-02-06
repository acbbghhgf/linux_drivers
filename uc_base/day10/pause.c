/*************************************************************************
	> File Name: pause.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时40分51秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>

void doit(int n)
{
    printf("recv %d signal\n", n);
    return ;
}

int main()
{
    printf("pid : %d\n", getpid());
    signal(2, doit);
    int f = pause();
    /*
    if(f < 0)
    {
        perror("pause");
        return -1;
    }
    */
    printf("pause after...%d\n", f);
    return 0;
}

