/*************************************************************************
	> File Name: file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 08时07分33秒
 ************************************************************************/

#include<stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror("fopen");
        printf("errno:%d\n", errno);
        printf("%s \n", strerror(errno));
        return 1;
    }
    printf("open file success ...\n");
    fclose(fp);
    return 0;
}

