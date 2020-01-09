/*************************************************************************
	> File Name: 01lottery.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 20时19分07秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[7] = {0}, arr1[7] = {0}, num = 0, num1 = 0, tmp = 0, size = 0, cnt = 0;
    srand(time(0));
    do{
        tmp = rand() % 36 + 1;
        for(num = 0; num < size; num++)
        {
            if(arr[num] == tmp)
            {
                break;
            }
        }
        if(num == size)
        {
            arr[size] = tmp;
            size++;
        }
    } while(size < 7);

    for(num = 0; num <= 6; num++)
    {
        printf("%d\t", arr[num]);
    }
    printf("\n");

    for(num = 0; num <= 6; num++)
    {
        printf("请输入一个数字：\n");
        scanf("%d", &arr1[num]);
    }

    cnt = 0;
    for(num = 0; num <= 6; num++)
    {
        for(num1 = 0; num1 <= 6; num1++)
        {
            if(arr[num] == arr1[num1])
            {
                cnt++;
                break;
            }
        }
    }
    printf("买对的数字个数是%d \n", cnt);
    return 0;
}

