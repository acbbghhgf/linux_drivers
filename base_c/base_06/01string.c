/*************************************************************************
	> File Name: 01string.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时12分46秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int main()
{
    char str[10] = "abc";
    printf("有效字符个数是%d \n", strlen(str));
    printf("sizeof(str) = %d\n", sizeof(str));
    printf("%s\n", strcat(str, "def"));
    printf("%s\n", str);

    printf("%s\n", strncat(str, "xyzpqr", 3));
    printf("%s\n", str);
    printf("比较结果是%d\n", strcmp("abc", "abd"));
    printf("比较结果是%d\n", strncmp("abc", "abd", 2));

    printf("%s\n", strcpy(str, "xyz"));
    printf("%s\n", str);
    printf("%s\n", strncpy(str, "abc", 2));
    printf("%s\n", str);
    memset(str, 'h', 9);
    printf("%s\n", str);
    printf("%s\n", strstr("abcdefghijk", "def"));
    return 0;
}

