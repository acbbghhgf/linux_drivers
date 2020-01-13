/*************************************************************************
	> File Name: 11ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时31分58秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int num = 0;
    int *p_num = NULL, *p_num1 = &num;
    p_num = &num;
    *p_num = 10;
    printf("num = %d\n", num);
    return 0;
}

