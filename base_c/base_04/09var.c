/*************************************************************************
	> File Name: 09var.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时27分12秒
 ************************************************************************/

#include<stdio.h>

int num1;
void func(void)
{
    int num1 = 100;
    int num = 10;
    printf("num1 = %d \n", num1);
}

int main()
{
    func();
    printf("num1 = %d \n", num1);
    return 0;
}

