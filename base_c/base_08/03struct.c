/*************************************************************************
	> File Name: 03struct.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 21时54分47秒
 ************************************************************************/

#include<stdio.h>
typedef struct{
    int row, col;
}pt;

pt *read(pt *p_pt)
{
    printf("请输入点的位置: \n");
    scanf("%d%d", &p_pt->row, &p_pt->col);
    return p_pt;
}
void print(const pt *p_pt)
{
    printf("点的位置是(%d, %d)\n", p_pt->row, p_pt->col);
}
int main()
{
    pt pt1 = {0}, *p_pt = NULL;
    p_pt = read(&pt1);
    print(p_pt);
    print(&pt1);

    return 0;
}
