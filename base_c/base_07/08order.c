/*************************************************************************
	> File Name: 08order.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 07时52分18秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int order = 0;
    printf("请点菜：\n");
    scanf("%d", &order);
#ifdef      ZHAOBENSHAN
    if(order == 2)
    {
        printf("真没有\n");
    }
    else{
        printf("没有\n");
    }
#else
    if(order == 2)
    {
        printf("没有\n");
    }
    else{
        printf("有\n");
    }
#endif
    return 0;
}
