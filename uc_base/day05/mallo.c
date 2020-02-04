/*************************************************************************
	> File Name: mallo.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 08时07分35秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("pid : %d \n", getpid());
    char *p = (char *)malloc(1024);
    char *p1 = (char *)malloc(1024);
    char *p2 = (char *)malloc(33 * 4096);
    char *p3 = (char *)malloc(1024);

    printf("p content %p\n", p);
    printf("p1 content %p\n", p1);
    printf("p2 content %p\n", p2);
    printf("p3 content %p\n", p3);

    getchar();
    free(p2);
    p2 = NULL;
    getchar();
    free(p);
    p = NULL;

    free(p1);
    p1 = NULL;
    free(p3);
    p3 = NULL;
    getchar();
    return 0;
}

