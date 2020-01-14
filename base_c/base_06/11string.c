/*************************************************************************
	> File Name: 11string.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时56分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *p_grade = "10,20,30,40,50", *p_tmp = p_grade;
    int sum = 0;
    while(1)
    {
        sum += atoi(p_tmp);
        p_tmp = strstr(p_tmp, ",");
        if(!p_tmp)
        {
            break;
        }
        p_tmp++;
    }
    printf("求和结果是%d\n", sum);
    return 0;
}

