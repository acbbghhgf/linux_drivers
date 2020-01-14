/*************************************************************************
	> File Name: 08ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时13分50秒
 ************************************************************************/

#include<stdio.h>

int *max(const int *p_num, int size)
{
    const int *p_tmp = NULL, *p_max = NULL;
    for(p_tmp = p_num; p_tmp < p_num + size; p_tmp++)
    {
        if(!p_max || *p_max < *p_tmp)
        {
            p_max = p_tmp;
        }
    }
    return (int *)p_max;
}

int main()
{
    int arr[] = {39, 62, 15, 22, 41};
    int *p_num = max(arr, 5);
    printf("最大的数字是%d\n", *p_num);
    return 0;
}

