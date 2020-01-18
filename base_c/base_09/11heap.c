/*************************************************************************
	> File Name: 11heap.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 22时10分14秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct{
    int row, col;
}pt;
typedef struct{
    pt pt1, pt2;
}rect;

pt *midpt(const rect *p_r)
{
    pt *p_mid = (pt *)malloc(sizeof(pt));
    if(p_mid)
    {
        p_mid->row = (p_r->pt1.row + p_r->pt2.row) / 2;
        p_mid->col = (p_r->pt1.col + p_r->pt2.col) / 2;
    }
    return p_mid;
}
int main()
{
    pt *p_pt = NULL;
    rect r = {0};
    printf("请输入水平长方形的位置：\n");
    scanf("%d%d%d%d", &r.pt1.row, &r.pt1.col, &r.pt2.row, &r.pt2.col);
    p_pt = midpt(&r);
    if(p_pt)
    {
        printf("中间点的位置是（%d , %d）\n", p_pt->row, p_pt->col);
        free(p_pt);
        p_pt = NULL;
    }
    return 0;
}
