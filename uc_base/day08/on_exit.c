/*************************************************************************
	> File Name: on_exit.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 21时18分14秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

void doit(int n, void *arg)
{
    printf("n = %d\targ:%s\n", n, (char *)arg);
    return ;
}

int main()
{
    on_exit(doit, "beijing");
    getchar();
    exit(3);
}

