/*************************************************************************
	> File Name: 09arr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 20时14分35秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int arr[10] = {0}, num = 0;
    printf("请输入一个数字\n");
    scanf("%d", &num);
    
    do{
        arr[num % 10]++;
        num /=10;
    }while(num);
    for(num = 0; num <= 9; num++)
    {
        if(arr[num])
        {
            printf("数字%d出现了%d次\n", num, arr[num]);
        }
    }
    return 0;
}

