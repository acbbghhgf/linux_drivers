/*************************************************************************
	> File Name: 06struct.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时23分29秒
 ************************************************************************/

#include<stdio.h>
typedef struct{
    int row, col;
}pt;

typedef struct{
    pt center;
    int radius;
}circle;
int len2(const pt *p_pt1, const pt *p_pt2)
{
    return (p_pt1->row - p_pt2->row) *(p_pt1->row - p_pt2->row) + (p_pt1->col - p_pt2->col) * (p_pt1->col - p_pt2->col);
}
int relation(const circle *p_cl, const pt *p_pt)
{
    int tmp = len2(&p_cl->center, p_pt);
    if(tmp > p_cl->radius * p_cl->radius)
    {
        return 2;
    }
    else if(tmp < p_cl->radius * p_cl->radius)
    {
        return 0;
    }
    else{
        return 1;
    }
}
int main()
{
    int ret = 0;
    circle cl = {0};
    pt pt1 = {0};

    printf("请输入一个圆的位置：\n");
    scanf("%d%d%d", &cl.center.row, &cl.center.col, &cl.radius);
    printf("请输入点的位置：\n");
    scanf("%d%d", &pt1.row, &pt1.col);
    ret = relation(&cl, &pt1);
    if(!ret)
    {
        printf("点在圆内\n");
    }
    else if(ret == 1)
    {
        printf("点在圆上\n");
    }
    else{
        printf("点在圆外\n");
    }
    return 0;
}
