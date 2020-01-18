/*************************************************************************
	> File Name: 01file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 22时15分57秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    FILE *p_file = fopen("a.t", "w");
    if(!p_file)
    {
        printf("file open fail\n");
        return 0;
    }
    fclose(p_file);
    p_file = NULL;
    return 0;
}
