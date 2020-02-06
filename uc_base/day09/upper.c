/*************************************************************************
	> File Name: upper.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 08时52分43秒
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>

int main()
{
    int ch;
    while((ch = getchar()) != EOF)
    {
        putchar(toupper(ch));
    }
    return 0;
}

