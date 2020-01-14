/*************************************************************************
	> File Name: 06login.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时38分58秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char buf[10] = {0};
    int num = 0;
    for(num = 1; num < 4; num++)
    {
        printf("请输入用户名：");
        fgets(buf, 10, stdin);
        if(strlen(buf) == 9 && buf[8] != '\n')
        {
            scanf("%*[^\n]");
            scanf("%*c");
        }
        if(strcmp(buf, "admin\n"))
        {
            continue;
        }
        printf("请输入密码：");
        fgets(buf, 10, stdin);
        if(strlen(buf) == 9 && buf[8] != '\n')
        {
            scanf("%*[^\n]");
            scanf("%*c");
        }
        if(strcmp(buf, "123456\n"))
        {
            continue;
        }
        break;
    }
    if(num < 4)
    {
        printf("登录成功\n");
    }
    else{
        printf("登录失败\n");
    }
    return 0;
}

