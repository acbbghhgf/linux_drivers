/*************************************************************************
	> File Name: 04add.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 22时51分54秒
 ************************************************************************/

#include<stdio.h>

int add(void)
{
    int num = 0, num1 = 0;
    printf("请输入两个整数：\n");
    scanf("%d%d", &num, &num1);
    return num+num1;
}

int main()
{
    int num = add();
    printf("求和结果是%d\n", num);
    return 0;
}

