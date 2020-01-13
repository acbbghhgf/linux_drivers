/*************************************************************************
	> File Name: 06recur.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时18分53秒
 ************************************************************************/

#include<stdio.h>

void print(int num)
{
    if(num == 1)
    {
        printf("1 ");
        return;
    }
    print(num -1);
    printf("%d ", num);
}

int main()
{
    print(6);
    printf("\n");
    return 0;
}

