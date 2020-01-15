/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 07时20分55秒
 ************************************************************************/

#include<stdio.h>
#include "add.h"
int main()
{
    int num = 0, num1 = 0, sum = 0;
    printf("请输入两个数字：");
    scanf("%d%d", &num, &num1);
    sum = add(num, num1);
    printf("求和结果是%d\n", sum);
    return 0;
}
