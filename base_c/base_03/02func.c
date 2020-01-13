/*************************************************************************
	> File Name: 02func.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 21时28分52秒
 ************************************************************************/

#include<stdio.h>

void func()
{
    int num;
    printf("num = %d\n", num);
    num = 10;
}

void func1(void)
{
    int val = 100;
    func();
}

int main()
{
    func();
    func();
    func1();
    
    func();
    func();
    func();
    return 0;
}

