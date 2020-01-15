/*************************************************************************
	> File Name: 12macro.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 07时28分26秒
 ************************************************************************/

#include<stdio.h>
#define     CASE(ch)    ((ch) >= 'a' && (ch) <= 'z' ? (ch) - 'a' + 'A' : (ch) - 'A' + 'a')

int main()
{
    char ch = 0;
    do{
        printf("请输入一个字符：");
        scanf("%c", &ch);
        printf("转换结果 %c\n", CASE(ch));
    }while(ch != 'q' && ch !='Q');
    printf("退出。。。\n");

    return 0;
}
