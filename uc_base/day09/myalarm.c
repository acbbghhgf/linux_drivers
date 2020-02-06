/*************************************************************************
	> File Name: myalarm.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时18分10秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>


int main()
{
    int i;
    alarm(1);
    for(i = 0; ;i++)
    {
        printf("%d\n", i);
    }
    return 0;
}

