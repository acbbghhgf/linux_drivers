/*************************************************************************
	> File Name: 03func.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 23时48分00秒
 ************************************************************************/

#include<stdio.h>

double add(double num, double num1);

int main()
{
    int num = 0, num1 = 0, sum = 0;
    printf("请输入两个数字：\n");
    scanf("%d%d", &num, &num1);
    sum = add(num, num1);
    printf("sum = %d\n", sum);
    return 0;
}

double add(double num, double num1)
{
    return num + num1;
}

