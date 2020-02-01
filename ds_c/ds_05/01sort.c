/*************************************************************************
	> File Name: 01sort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月01日 星期六 22时21分09秒
 ************************************************************************/
//排序法

#include<stdio.h>

void bubble_sort_1(int *p_num, int size)
{
    int num = 0, num1 = 0, tmp = 0;
    for(num = size - 1; num > 0; num--)
    {
        for(num1 = 0; num1 < num; num1++)
        {
            tmp = *(p_num + num1 - 1);
            *(p_num + num1 - 1) = *(p_num + num1);
            *(p_num + num1) = tmp;
        }
    }
}

void bubble_sort_2(int *p_num, int size)
{
    int num = 0, num1 = 0, tmp = 0;
    for(num = 0; num < size -1; num++)
    {
        for(num1 = size - 2; num1 >= num; num1--)
        {
            if(*(p_num + num1) > *(p_num + num1 + 1))
            {
                tmp = *(p_num + num1);
                *(p_num + num1) = *(p_num + num1 + 1);
                *(p_num + num1 + 1) = tmp;
            }
        }
    }
}

void choice_sort(int *p_num, int size)
{
    int num = 0, num1 = 0, tmp = 0;
    for(num = size - 1; num > 0; num--)
    {
        for(num1 = 0; num1 <= num -1; num1++)
        {
            if(*(p_num + num1) > *(p_num + num))
            {
                tmp = *(p_num + num1);
                *(p_num + num1) = *(p_num + num);
                *(p_num + num) = tmp;
            }
        }
    }
}

void insert_sort(int *p_num, int size)
{
    int num = 0, num1 = 0, tmp = 0;
    for(num = 1; num <= size -1; num++)
    {
        for(num1 = num - 1; num1 >= 0; num1--)
        {
            if(*(p_num + num1) > *(p_num + num1 + 1))
            {
                tmp = *(p_num + num1);
                *(p_num + num1) = *(p_num + num1 + 1);
                *(p_num + num1 + 1) = tmp;
            }
            else{
                break;
            }
        }
    }
}

void quick_sort(int *p_num, int size)
{
    int *p_start = p_num, *p_end = p_num + size -1, tmp = 0;
    int base = *p_num;
    if(size <= 1)
    {
        return ;
    }
    while(p_start < p_end)
    {
        if(*p_start > *p_end)
        {
            tmp = *p_start;
            *p_start = *p_end;
            *p_end = tmp;
        }
        if(*p_start == base)
        {
            p_end--;
        }
        else{
            p_start++;
        }
    }
    quick_sort(p_num, p_start - p_num);
    quick_sort(p_start + 1, size - (p_start - p_num) -1);
}

int main()
{
    int arr[] = {2, 1, 22, 41, 12, 31, 154, 14, 112, 13, 50}, num = 0;
    quick_sort(arr, 11);
    for(num = 0; num < 11; num++)
    {
        printf("%d ", arr[num]);
    }
    printf("\n");
    return 0;
}

