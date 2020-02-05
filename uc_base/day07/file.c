/*************************************************************************
	> File Name: file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 08时52分57秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("hello", "r");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    printf("file open success ...\n");
    fclose(fp);
    return 0;
}

