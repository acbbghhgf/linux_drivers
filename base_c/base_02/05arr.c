/*************************************************************************
	> File Name: 05arr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 07时15分56秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int arr[3][2] = {0};
    printf("arr = %p, &arr[0][0] = %p\n", arr, &arr[0][0]);
    printf("sizeof(arr) = %d\n", sizeof(arr));
    printf("arr[1] = %p, &arr[1][0] = %p\n", arr[1], &arr[1][0]);
    printf("sizeof(arr[1]) = %d \n", sizeof(arr[1]));
    return 0;
}

