/*************************************************************************
	> File Name: 05macro.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 07时47分19秒
 ************************************************************************/

#include<stdio.h>
#define SQUARE(n)   ((n) * (n))
int main()
{
    int num = 5;
    printf("SQUARE(num) = %d\n", SQUARE(num));
    printf("SQUARE(++num) = %d\n", SQUARE(++num));
    return 0;
}
