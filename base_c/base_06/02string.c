/*************************************************************************
	> File Name: 02string.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 21时18分57秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    char ch = 0;
    int num = 0;
    float fnum = 0.0;
    char str[20] = {0};
    printf("%d %c %g\n", 34, 't', 5.6f);
    sprintf(str, "%d %c %g\n", 34, 't', 5.6f);

    printf("%s", str);

    sscanf("g 13 7.4", "%c%d%g", &ch, &num, &fnum);
    printf("%g %c %d\n", fnum, ch, num);
    return 0;
}

