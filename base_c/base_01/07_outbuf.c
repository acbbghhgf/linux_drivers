/*************************************************************************
	> File Name: 07_outbuf.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 20时09分00秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    printf("1");
    fflush(stdout);
    while(1)
    {
        fflush(stdout);
    }
    return 0;
}

