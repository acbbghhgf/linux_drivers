/*************************************************************************
	> File Name: 04ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时42分22秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    int num = 0;
    for(num = 0; num < argc; num++)
    {
        printf("%s\n", *(argv + num));
    }
    return 0;
}

