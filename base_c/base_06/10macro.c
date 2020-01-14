/*************************************************************************
	> File Name: 10macro.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时53分53秒
 ************************************************************************/

#include<stdio.h>

#define PI 3.14f
int main()
{
    float pi = 3.14f;
    int radius = 0;
    printf("请输入半径：\n");
    scanf("%d", &radius);
    printf("周长是%g\n", 2 * PI * radius);
    printf("周长是%g\n", 2 * pi * radius);
    return 0;
}

