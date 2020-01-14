/*************************************************************************
	> File Name: 04string.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时30分37秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    char buf[50] = {0}, tmp[10] = {0};
    int grade = 0;
    while(1)
    {
        printf("请输入一个考试成绩：\n");
        scanf("%d", &grade);
        if(grade < 0)
        {
            break;
        }
        sprintf(tmp, "%d ", grade);
        strcat(buf, tmp);
    }
    buf[strlen(buf) -1] = 0;
    printf("结果是%s\n", buf);
    return 0;
}


