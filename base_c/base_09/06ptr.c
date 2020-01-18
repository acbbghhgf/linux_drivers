/*************************************************************************
	> File Name: 06ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时44分52秒
 ************************************************************************/

#include<stdio.h>
typedef struct{
    int row, col;
}pt;
typedef struct{
    pt center;
    int radius;
}circle;
void max(const circle *p_c11, const circle *p_c12, circle **pp_cl)
{
    *pp_cl = (circle *)(p_c11->radius > p_c12->radius ? p_c11 : p_c12);
}

int main()
{
    circle c11 = {0}, c12 = {0}, *p_c1 = NULL;
    printf("请输入一个圆的位置：\n");
    scanf("%d%d%d", &c11.center.row, &c11.center.col, &c11.radius);
    printf("请输入一个圆的位置：\n");
    scanf("%d%d%d", &c12.center.row, &c12.center.col, &c12.radius);
    max(&c11, &c12, &p_c1);
    printf("面积比较大的是(%d, %d, %d)\n", p_c1->center.row, p_c1->center.col, p_c1->radius);
    return 0;
}

