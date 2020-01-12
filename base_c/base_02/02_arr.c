/*************************************************************************
	> File Name: 02_arr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月12日 星期日 20时54分34秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int arr[5] = {0}, size = 0;
    printf("%p %p\n", arr, &arr[0]);
    printf("sizeof(arr) = %d\n", sizeof(arr));
    printf("请输入一个整数:\n");
    scanf("%d", &size);
    int arr1[size];
    printf("sizeof(arr1) = %d \n", sizeof(arr1));
    return 0;
}

