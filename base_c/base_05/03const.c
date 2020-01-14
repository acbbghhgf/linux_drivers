/*************************************************************************
	> File Name: 03const.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时02分23秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int num = 0;
    const int *p_num = &num;
    int *const p_num1 = &num;

    p_num = NULL;
    *p_num1 = 10;

    return 0;
}

