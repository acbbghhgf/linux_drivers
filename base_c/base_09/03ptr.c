/*************************************************************************
	> File Name: 03ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时40分20秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int num = 0;
    int *p_num = &num;
    int **pp_num = &p_num;
    **pp_num = 10;
    printf("num = %d\n", num);
    *pp_num = NULL;
    printf("p_num = %p\n", p_num);
    return 0;
}
