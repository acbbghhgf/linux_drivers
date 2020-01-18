/*************************************************************************
	> File Name: 02struct.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 21时28分55秒
 ************************************************************************/

#include<stdio.h>
typedef struct{
    int row, col;
}pt;

typedef struct{
    pt pt1, pt2;
}rect;

int main()
{
    int area = 0;
    rect r = {0};
    rect *p_r = &r;
    printf("请输入一个水平长方形的位置:\n");
    scanf("%d%d%d%d", &r.pt1.row, &r.pt1.col, &r.pt2.row, &r.pt2.col);

    area = (p_r->pt1.row - p_r->pt2.row) * (p_r->pt1.col - p_r->pt2.col);
    area = area >= 0 ? area : 0 - area;

    printf("面积是%d\n", area);

    return 0;
}
