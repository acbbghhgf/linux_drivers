/*************************************************************************
	> File Name: 07string.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时45分36秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    char *strs[] = {"abc", "dev", "pgr", "vbn", "xyz"};
    char strs1[][10] = {"abc", "def", "pqr", "vbn", "xyz"};
    int num = 0;
    for(num = 0; num < 5; num++)
    {
        printf("%s\n", strs[num]);
        printf("%s\n", strs1[num]);
    }
    return 0;
}


