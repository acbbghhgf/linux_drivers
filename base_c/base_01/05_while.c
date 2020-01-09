/*************************************************************************
	> File Name: 05_while.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 19时57分56秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num = 0, guess = 0;
    srand(time(0));
    num = rand() % 100;
    do{
        printf("猜一个数字\n");
        getchar();
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
        }
    } while(num != guess);
    return 0;
}

