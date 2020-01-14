/*************************************************************************
	> File Name: 09str.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时21分50秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    char str[] = "abcdef";
    printf("%p\n", "abc");
    printf("%p\n", "abc");
    printf("%p\n", "ab""c");
    printf("%c\n", *"abc");
    
    printf("sizeof(str) = %d\n", sizeof(str));
    printf("%s\n", str);
    return 0;
}

