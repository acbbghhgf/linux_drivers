/*************************************************************************
	> File Name: 09compile.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 07时56分20秒
 ************************************************************************/

#include<stdio.h>
int main()
{
#if     defined(GONGCHANG)
    printf("80 %%\n");
#elif   !defined(GONGCHANG) && !defined(JINGPIN)
    printf("100 %%\n");
#else
    printf("120 %%\n");
#endif
    return 0;
}
