/*************************************************************************
	> File Name: myenv.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 08时40分11秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    extern char **environ;
    int i = 0;
    while(*(environ + i) != NULL)
    {
        printf("%s\n", *(environ + i));
        i++;
    }
    return 0;
}

