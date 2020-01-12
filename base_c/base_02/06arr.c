/*************************************************************************
	> File Name: 06arr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 07时20分41秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int arr[5][5] = {0};
    int row = 0, col = 0;
    for(row = 0; row <= 4; row++)
    {
        for(col = 0; col <= 4; col++)
        {
            if(!row && col <= 3)
            {
                arr[row][col] = 1;
            }
            else if(row <= 3 && col == 4)
            {
                arr[row][col] = 2;
            }
            else if(row == 4 && col >= 1)
            {
                arr[row][col] = 1;
            }
            else if(row >= 1 && !col)
            {
                arr[row][col] = 4;
            }
        }
    }
    for(row = 0; row <= 4; row++)
    {
        for(col = 0; col <= 4; col++)
        {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
    return 0;
}

