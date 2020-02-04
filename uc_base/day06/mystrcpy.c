/*************************************************************************
	> File Name: mystrcpy.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 09时31分35秒
 ************************************************************************/

#include<stdio.h>

char *mystrcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while(*src != '\0')
    {
        *tmp++ = *src++;
    }
    *tmp = *src;
    return dest;
}

int main()
{
    char str[] = "tarena";
    char dest[12];
    char buf[12];
    mystrcpy(buf, mystrcpy(dest, str));
    printf("dest : %s\n", dest);
    printf("buf : %s\n", buf);
    return 0;
}

