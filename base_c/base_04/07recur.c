/*************************************************************************
	> File Name: 07recur.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时22分18秒
 ************************************************************************/

#include<stdio.h>

int sum(int num)
{
    if(num == 1)
    {
        return 1;
    }
    return sum(num -1) + num;
}

int main()
{
    int num = 0;
    printf("请输入一个数字：\n");
    scanf("%d", &num);
    printf("求和的结果为:%d \n", sum(num));
    return 0;
}

