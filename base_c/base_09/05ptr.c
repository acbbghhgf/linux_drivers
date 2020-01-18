/*************************************************************************
	> File Name: 05ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时43分40秒
 ************************************************************************/

#include<stdio.h>
void set_null(int **pp_num)
{
    *pp_num = NULL;
}
int main()
{
    int num = 0;
    int *p_num = &num;
    set_null(&p_num);
    printf("p_num = %p\n", p_num);
    return 0;
}
