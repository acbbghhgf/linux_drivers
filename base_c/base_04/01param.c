/*************************************************************************
	> File Name: 01param.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 23时43分00秒
 ************************************************************************/

#include<stdio.h>

void print(int arr[], int size)
{
    int num = 0;
    for(num = 0; num < size; num++)
    {
        printf(" %d ", arr[num]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    return 0;
}

