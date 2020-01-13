/*************************************************************************
	> File Name: 10var.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时29分33秒
 ************************************************************************/

#include<stdio.h>
void func()
{
    static int num = 1000;
    printf("num = %d \n", num);
    num = 10;
}

void func1(void)
{
    int num = 100;
    func();
}

int main()
{
    func();
    func1();
    return 0;
}

