/*************************************************************************
	> File Name: 03return.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 21时32分10秒
 ************************************************************************/

#include <stdio.h>

int read(void)
{
    int num = 0;
    printf("请输入一个数字：\n");
    scanf("%d", &num);
    return num;
}

int main()
{
    int num = read();
    printf("num = %d\n", num);
    return 0;
}

