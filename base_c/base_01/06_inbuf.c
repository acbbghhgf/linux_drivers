/*************************************************************************
	> File Name: 06_inbuf.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 20时02分56秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int num = 0, num1 = 0;

    printf("请输入一个数字：\n");

    scanf("%d", &num);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("num is %d \n", num);
    printf("请输入一个数字：\n");
    scanf("%d", &num1);
    printf("num1 is %d \n", num1);
    
    return 0;
}

