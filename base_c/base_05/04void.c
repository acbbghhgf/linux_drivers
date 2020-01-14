/*************************************************************************
	> File Name: 04void.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 20时03分58秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    char ch = 'r';
    int num = 34;
    float fnum = 5.6f;
    void *p_v = &ch;
    printf("%c\n", *(char *)p_v);
    p_v = &num;
    printf("%d\n", *(int *)p_v);
    p_v = &fnum;
    printf("%g\n", *(float *)p_v);
    printf("%f\n", *(float *)p_v);

    return 0;
}

