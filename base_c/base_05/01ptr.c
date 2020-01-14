/*************************************************************************
	> File Name: 01ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 19时45分17秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int num = 0, num1 = 0, num2 = 0, tmp = 0;
    int *p_num = &num, *p_num1 = &num1, *p_num2 = &num2, *p_tmp = &tmp;

    printf("请输入三个数字:\n");
    scanf("%d%d%d", p_num, p_num1, p_num2);
    if(*p_num < *p_num1)
    {
        p_tmp = p_num;
        p_num = p_num1;
        p_num1 = p_tmp;
    }
    if(*p_num < *p_num2)
    {
        p_tmp = p_num;
        p_num = p_num2;
        p_num2 = p_tmp;
    }
    if(*p_num1 < *p_num2)
    {
        p_tmp = p_num2;
        p_num2 = p_num1;
        p_num1 = p_tmp;
    }
    printf("%d %d %d\n", *p_num, *p_num1, *p_num2);
    return 0;
}

