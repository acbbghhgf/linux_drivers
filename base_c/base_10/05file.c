/*************************************************************************
	> File Name: 03file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 22时21分54秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int arr[5] = {0}, size = 0, num = 0;
    FILE *p_file = fopen("a.bin", "r");
    if(p_file)
    {
        for(num = 0; num < 5; num++)
        {
            fscanf(p_file, "%d", arr+num);
        }
        for(num = 0; num < 5; num++)
        {
            printf("%d ", arr[num]);
        }
        printf("\n");
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
