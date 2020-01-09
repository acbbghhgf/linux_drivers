/*************************************************************************
	> File Name: 08arr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 20时11分02秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int arr[] = {0, 1, 2, 3, 4};
    int num = 0;

    printf("arr[2] = %d\n", arr[2]);
    for(num = 0; num <= 4; num++)
    {
        printf("%d\t", arr[num]);
    }
    printf("\n");

    for(num = 4; num >=0; num--)
    {
        printf("%d\t", arr[num]);
    }
    printf("\n");
    return 0;
}

