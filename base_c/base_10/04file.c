/*************************************************************************
	> File Name: 02file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 22时18分15秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5}, num = 0, size = 0;
    char buf[10] = {0};
    FILE *p_file = fopen("a.bin", "w");
    if(p_file)
    {
        for(num; num < 5; num++)
        {
            fprintf(p_file, "%d ", arr[num]);
        }
        //size = fwrite(arr, sizeof(int), 5, p_file);
        //printf("写入%d个整数类型存储区\n", size);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
