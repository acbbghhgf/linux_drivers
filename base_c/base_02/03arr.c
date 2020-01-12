/*************************************************************************
	> File Name: 03arr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 07时10分38秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size = 0, num = 0;
    srand(time(0));
    printf("请输入数字个数:\n");
    scanf("%d", &size);
    int arr[size];
    for(num = 0; num <= size -1; num++)
    {
        arr[num] = rand() % 36 + 1;
        printf("%d ", arr[num]);
    }

    printf("\n");
    return 0;
}

