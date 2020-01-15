/*************************************************************************
	> File Name: read.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 07时25分18秒
 ************************************************************************/

#include<stdio.h>
#include "read.h"
int read()
{
    int num = 0;
    printf("请输入一个数字：\n");
    scanf("%d", &num);
    return num;
}


