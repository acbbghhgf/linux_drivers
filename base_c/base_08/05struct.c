/*************************************************************************
	> File Name: 05struct.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时21分43秒
 ************************************************************************/

#include<stdio.h>
typedef struct{
    char buf[2];
    int num;
}tmp;
typedef struct{
    char ch;
    int num;
    char ch1;
}tmp1;

int main()
{
    printf("sizeof(tmp) = %d\n", sizeof(tmp));
    printf("sizeof(tmp1) = %d\n", sizeof(tmp1));
    return 0;
}
