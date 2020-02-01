/*************************************************************************
	> File Name: 02search.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月01日 星期六 22时40分55秒
 ************************************************************************/

#include<stdio.h>

//折半查找
int *half_search(const int *p_num, int size, int num)
{
    const int *p_start = p_num, *p_end = p_num + size -1, *p_mid = NULL;
    while(p_start <= p_end)
    {
        p_mid = p_start + (p_end - p_start + 1)/ 2;
        if(*p_mid == num)
        {
            return (int *)p_mid;
        }
        else if(*p_mid < num)
        {
            p_start = p_mid + 1;
        }
        else{
            p_end = p_mid - 1;
        }
    }
    return NULL;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80}, num = 0;
    int *p_num = NULL;
    printf("请输入要查找的数字:\n");
    scanf("%d", &num);
    p_num = half_search(arr, 10, num);
    if(p_num)
    {
        printf("找到数字是%d\n", *p_num);
    }
    else{
        printf("没有找到\n");
    }
    return 0;
}

