/*************************************************************************
	> File Name: atexit.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 21时22分56秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

void doit(void)
{
    printf("hahahah...\n");
    return ;
}

int main()
{
    atexit(doit);
    getchar();
    return 0;
}

