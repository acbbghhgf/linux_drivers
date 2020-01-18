/*************************************************************************
	> File Name: 07ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 21时55分38秒
 ************************************************************************/

#include<stdio.h>
int add(int num, int num1)
{
    return num + num1;
}
int main()
{
    int (*p_func)(int, int) = NULL;
    p_func = add;
    printf("p_func = %p\n", p_func);
    printf("p_func(3, 6) = %d\n", p_func(3,6));
    return 0;
}
