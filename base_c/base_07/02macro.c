/*************************************************************************
	> File Name: 02macro.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 07时38分19秒
 ************************************************************************/

#include<stdio.h>
#define PI  3.14f
#define CIRCLE(r)   2 * PI * r
int main()
{
    int radius = 0;
    printf("请输入半径：");
    scanf("%d", &radius);
    printf("周长为%g\n", CIRCLE(radius));
    return 0;
}
