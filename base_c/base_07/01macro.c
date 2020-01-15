/*************************************************************************
	> File Name: 01macro.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 07时35分37秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int arr[SIZE] = {0}, num = 0;
    srand(time(0));
    for(num = 0; num < SIZE; num++)
    {
        arr[num] = rand() % MAX + 1;
    }
    for(num = 0; num < SIZE; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n");
    return 0;
}
