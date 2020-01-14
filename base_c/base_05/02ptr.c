/*************************************************************************
	> File Name: 02ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 19时56分26秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, num = 0;
    int *p_num = arr;
    for(num = 0; num < 5; num++)
    {
        printf("%d ", arr[num]);
        printf("%d ", p_num[num]);
        printf("%d ", *(p_num + num));
    }
    printf("\n");
    printf("arr = %p, arr + 3 = %p arr -3 = %p &arr = %p \n", arr, arr+3, arr - 3, &arr[3]);
    printf("&arr[3] - arr= %d \n",  &arr[3] - arr);
    return 0;
}

