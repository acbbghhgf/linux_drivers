/*************************************************************************
	> File Name: 02union.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 07时37分38秒
 ************************************************************************/

#include<stdio.h>
typedef union{
    char ch;
    int num;
    float fnum;
}tmp;
int main()
{
    tmp tmp_union = {0};
    printf("&tmp_union.ch = %p\n", &tmp_union.ch);
    printf("&tmp_union.num = %p\n", &tmp_union.num);
    printf("&tmp_union.fnum = %p\n", &tmp_union.fnum);

    printf("sizeof(tmp_union) = %d\n", sizeof(tmp_union));
    return 0;
}
