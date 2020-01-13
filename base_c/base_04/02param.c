/*************************************************************************
	> File Name: 02param.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 23时44分46秒
 ************************************************************************/

#include<stdio.h>

void neg(int arr[], int size)
{
    int num = 0;
    for(; num < size; num++)
    {
        arr[num] = 0 - arr[num];
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, num = 0;
    neg(arr, 5);
    for(num = 0; num < 5; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n");

    return 0;
}
