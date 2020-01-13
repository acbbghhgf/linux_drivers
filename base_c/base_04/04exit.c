/*************************************************************************
	> File Name: 04exit.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时15分56秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

void func(void)
{
    printf("2\n");
    exit(0);
    printf("3\n");
}

int main()
{
    printf("1\n");
    func();
    printf("4\n");
    return 0;
}

