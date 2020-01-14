/*************************************************************************
	> File Name: 08main.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时47分45秒
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
    int num = 0;
    for(num = 0; num < argc; num++)
    {
        printf("%s\n", argv[num]);
    }
    return 0;
}

