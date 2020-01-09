/*************************************************************************
	> File Name: 03_for.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 19时50分26秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int num = 0, num1 = 0;
    for(num = 1; num <= 5; num++)
    {
        for(num1 = 5; num1 >= num; num1--)
        {
            printf("%d", num1);
        }
        printf("\n");
    }
    return 0;
}

