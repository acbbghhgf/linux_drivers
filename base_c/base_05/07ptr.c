/*************************************************************************
	> File Name: 07ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时12分00秒
 ************************************************************************/

#include<stdio.h>

int *read(void)
{
    static int num = 0;
    printf("请输入一个数字：\n");
    scanf("%d", &num);
    return &num;
}

int main()
{
    int *p_num = read();
    printf("数字 = %d \n", *p_num);
    return 0;
}

