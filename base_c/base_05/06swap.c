/*************************************************************************
	> File Name: 06swap.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时09分31秒
 ************************************************************************/

#include<stdio.h>

void swap(int *p_num, int *p_num1)
{
    int tmp = 0;
    tmp = *p_num;
    *p_num = *p_num1;
    *p_num1 = tmp;
}

int main()
{
    int num = 0, num1 = 0;
    printf("请输入两个数字：\n");
    scanf("%d%d", &num, &num1);
    swap(&num, &num1);
    printf("num = %d, num1 = %d\n", num, num1);
    return 0;
}

