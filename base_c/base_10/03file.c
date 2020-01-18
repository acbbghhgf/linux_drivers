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
    FILE *p_file = fopen("a.bin", "rb");
    if(p_file)
    {
        size = fread(arr, sizeof(int), 5, p_file);
        printf("一共读取了%d个整数\n", size);
        for(num; num < 5; num++)
        {
            printf("%d ", arr[num]);
        }
        printf("\n");
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
