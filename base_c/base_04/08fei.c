/*************************************************************************
	> File Name: 08fei.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时25分08秒
 ************************************************************************/

#include<stdio.h>

int fei(int num)
{
    if(num <= 1)
    {
        return 1;
    }
    return fei(num - 2) + fei(num -1);
}

int main()
{
    int num = 0;
    printf("请输入一个编号：\n");
    scanf("%d", &num);
    printf("数字是:%d \n", fei(num));
    return 0;
}

