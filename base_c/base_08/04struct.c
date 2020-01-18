/*************************************************************************
	> File Name: 04struct.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时17分03秒
 ************************************************************************/

#include<stdio.h>
typedef struct{
    int row, col;
}pt;
typedef struct{
    pt pt1, pt2;
}rect;

rect *read(rect *p_rect)
{
    printf("请输入水平长方形的位置：");
    scanf("%d%d%d%d", &p_rect->pt1.row, &p_rect->pt1.col, &p_rect->pt2.row, &p_rect->pt2.col);
    return p_rect;
}
int area(const rect *p_rect)
{
    int ret = (p_rect->pt1.row - p_rect->pt2.row) * (p_rect->pt1.col - p_rect->pt2.col);
    return ret > 0 ? ret : 0 - ret;
}
int main()
{
    rect r = {0}, *p_r = NULL;
    p_r = read(&r);
    printf("area = %d\n", area(p_r));
    return 0;
}
