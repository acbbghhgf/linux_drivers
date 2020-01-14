/*************************************************************************
	> File Name: 10reverse.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时24分28秒
 ************************************************************************/

#include<stdio.h>

int *reverse(int *p_num, int size)
{
    int *p_head = p_num, *p_tail = p_num + size - 1, tmp = 0;
    while(p_head < p_tail)
    {
        tmp = *p_head;
        *p_head = *p_tail;
        *p_tail = tmp;
        p_head++;
        p_tail--;
    }
    return p_num;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, num = 0;
    int *p_num = reverse(arr, 5);
    for(num = 0; num < 5; num++)
    {
        printf("%d ", *(p_num + num));
    }
    printf("\n");
    return 0;
}


