/*************************************************************************
	> File Name: 09string.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时49分34秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int heads = 0, legs = 0, num = 0;
    if(argc < 3)
    {
        printf("命令错误\n");
        return 0;
    }
    heads = atoi(argv[1]);
    legs = atoi(argv[2]);
    for(num = 0; num < heads; num++)
    {
        if(4 * num + 2 * (heads - num) == legs)
        {
            printf("兔子有%d只， 鸡有%d只\n", num, heads - num);
            return 0;
        }
    }
    return 0;
}


