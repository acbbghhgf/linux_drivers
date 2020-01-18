/*************************************************************************
	> File Name: 09heap.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 22时02分37秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int *p_num = NULL, num = 0;
    srand(time(0));
    p_num = (int *)malloc(5 * sizeof(int));
    if(!p_num)
    {
        printf("malloc fail!\n");
        return 0;
    }
    for(num = 0; num < 5; num++)
    {
        *(p_num + num) = rand() % 36 + 1;
    }
    for(num = 0; num < 5; num++)
    {
        printf("%d ", *(p_num + num));
    }
    printf("\n");
    free(p_num);
    p_num = NULL;
    return 0;
}
