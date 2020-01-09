/*************************************************************************
	> File Name: strcmp.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月07日 星期二 07时45分23秒
 ************************************************************************/

#include "strcmp.h"

int my_strcmp(const char *str1, const char *str2)
{
    while(*str1)
    {
        if(*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

