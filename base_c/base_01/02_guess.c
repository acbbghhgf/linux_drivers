/*************************************************************************
	> File Name: 02_guess.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 19时46分08秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num = 0, guess = 0;
    srand(time(0));
    num = rand() % 100;

    while(1)
    {
        printf("请猜一个数字：");
        scanf("%d", &guess);
        if(num > guess)
        {
            printf("猜小了\n");
        }
        else if(num < guess)
        {
            printf("猜大了\n");
        }
        else{
            printf("猜对了\n");
            break;
        }
    }
    return 0;
}
