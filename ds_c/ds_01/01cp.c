/*************************************************************************
	> File Name: 01cp.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 07时20分31秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    int size = 0;
    char buf[100] = {0};
    FILE *p_src = NULL, *p_dest = NULL;
    if(argc < 3)
    {
        printf("命令格式错误\n");
        return 0;
    }
    p_src = fopen(argv[1], "rb");
    if(!p_src)
    {
        printf("src file open fail\n");
        return 0;
    }
    p_dest = fopen(argv[2], "wb");
    if(!p_dest)
    {
        printf("new file open fail\n");
        fclose(p_src);
        p_src = NULL;
        return 0;
    }
    while(1)
    {
        size = fread(buf, sizeof(char), 100, p_src);
        if(!size)
        {
            printf("src read EOF\n");
            break;
        }
        fwrite(buf, sizeof(char), size, p_dest);
    }
    fclose(p_dest);
    p_dest = NULL;
    fclose(p_src);
    p_src = NULL;
    return 0;
}
