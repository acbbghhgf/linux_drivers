/*************************************************************************
	> File Name: 05recur.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时17分44秒
 ************************************************************************/

#include<stdio.h>

void print(void)
{
    printf("1\n");
    print();
}

int main()
{
    print();
    return 0;
}

