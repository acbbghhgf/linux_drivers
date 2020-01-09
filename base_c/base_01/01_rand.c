/*************************************************************************
	> File Name: 01_rand.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 19时43分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    printf("%d \n", rand());
    printf("%d \n", rand());
    printf("%d \n", rand());
    return 0;
}

