/*************************************************************************
	> File Name: 12fei.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 07时33分14秒
 ************************************************************************/

#include<stdio.h>

int fei(int arr[], int size, int num)
{
    if(num <= 1)
    {
        return 1;
    }
    if(!arr[num -2])
    {
        arr[num - 2] = fei(arr, size, num - 2);
    }
    if(!arr[num - 1])
    {
        arr[num - 1] = fei(arr, size, num - 1);
    }
    return arr[num -2] + arr[num -1];
}
int main()
{
    int num = 0;
    int arr[50] = {0};
    printf("请输入一个编号:\n");
    scanf("%d", &num);
    printf("数字是%d\n", fei(arr, 50, num));
    return 0;
}

