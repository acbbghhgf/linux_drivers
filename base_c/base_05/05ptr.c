/*************************************************************************
	> File Name: 05ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时07分19秒
 ************************************************************************/

#include<stdio.h>

void print(const int *p_num, int size)
{
    int num = 0;
    for(num = 0; num < size; num++)
    {
        printf("%d ", *(p_num + num));
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    return 0;
}


