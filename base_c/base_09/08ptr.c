/*************************************************************************
	> File Name: 08ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 21时57分27秒
 ************************************************************************/

#include<stdio.h>
void print(int *p_num, int size)
{
    int num = 0;
    for(num = 0; num < size; num++)
    {
        printf("%d ", *(p_num + num));
    }
    printf("\n");
}

void print_cb(int *p_num)
{
    printf("%d ", *p_num);
}

void neg_cb(int *p_num)
{
    *p_num = 0 - *p_num;
}
void for_each(int *p_num, int size, void (*p_func)(int *))
{
    int num = 0;
    for(num = 0; num < size; num++)
    {
        p_func(p_num + num);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    for_each(arr, 5, print_cb);
    printf("\n");
    for_each(arr, 5, neg_cb);
    for_each(arr, 5, print_cb);

    printf("\n");
    return 0;
}

