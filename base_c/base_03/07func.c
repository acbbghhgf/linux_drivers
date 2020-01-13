/*************************************************************************
	> File Name: 07func.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 23时26分25秒
 ************************************************************************/

#include<stdio.h>
void print(int num, int num1)
{
    printf("%d X %d = %d\n", num, num1, num * num1);
}

int main()
{
    int num = 0;
    for(num = 0; num < 6; num++)
    {
        print(num, 10 - num);
    }
    return 0;
}


