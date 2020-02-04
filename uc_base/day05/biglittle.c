/*************************************************************************
	> File Name: biglittle.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 08时05分20秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    short var_s = 0x0001;
    char *p = (char *)&var_s;

    if(!*p)
    {
        printf("big end...\n");
    }
    else{
        printf("little end ...\n");
    }
    return 0;
}

