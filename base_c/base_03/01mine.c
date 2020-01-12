/*************************************************************************
	> File Name: 01mine.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 07时30分07秒
 ************************************************************************/

#include<stdio.h>
#include <time.h>
int main()
{
    int arr[10][10] = {0};
    int delta[][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
    int row = 0, col = 0, cnt = 0, num = 0;
    srand(time(0));

    do{
        row = rand() % 10;
        col = rand() % 10;
        if(!arr[row][col])
        {
            arr[row][col] = -1;
            cnt++;
        }
    }while(cnt < 10);

    for(row = 0; row <10; row++)
    {
        for(col = 0; col <10; col++)
        {
            if(arr[row][col] != -1)
            {
                continue;
            }
            for(num = 0; num < 8; num++)
            {
                int tmp_row = row + delta[num][0];
                int tmp_col = col + delta[num][1];
                if(tmp_row <0 || tmp_row > 9)
                {
                    continue;
                }
                if((tmp_col <0 || tmp_col >9))
                {
                    continue;
                }
                if(arr[tmp_row][tmp_col] == -1)
                {
                    continue;
                }
                arr[tmp_row][tmp_col]++;
            }
        }
    }
    for(row = 0; row <10; row++)
    {
        for(col = 0; col < 10; col++)
        {
            if(!arr[row][col])
            {
                printf("O");
            }
            else if(arr[row][col] == -1)
            {
                printf("X");
            }
            else{
                printf("%d", arr[row][col]);
            }
        }
        printf("\n");
    }
    return 0;

}
