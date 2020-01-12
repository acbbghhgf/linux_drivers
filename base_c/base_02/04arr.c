/*************************************************************************
	> File Name: 04arr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 07时13分39秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int arr[][2] = {1, 2, 3, 5, 6};
    int row = 0, col = 0, cnt = 0;
    for(row = 0; row <= 2; row++)
    {
        for(col = 0;col <= 1; col++)
        {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
    return 0;
}

