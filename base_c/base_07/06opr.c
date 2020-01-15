/*************************************************************************
	> File Name: 06opr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 07时48分45秒
 ************************************************************************/

#include<stdio.h>

#define     STR(n)      #n
#define     PTR(n)      p_##n

int main()
{
    int num = 0;
    int *PTR(num) = &num;
    STR(2 + 4);
    return 0;
}
