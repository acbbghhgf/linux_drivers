/*************************************************************************
	> File Name: 05string.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时35分28秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char buf[10] = {0};
    printf("请输入一个字符串：\n");
    fgets(buf, 10, stdin);
    if(strlen(buf) == 9 && buf[8] != '\n')
    {
        scanf("%*[^\n]");
        scanf("%*c");
    }
    printf("%s\n", buf);
    printf("请输入一个字符串：\n");
    fgets(buf, 10, stdin);
    printf("%s\n", buf);
    return 0;
}
