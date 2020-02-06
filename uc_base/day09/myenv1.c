/*************************************************************************
	> File Name: myenv1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 08时42分43秒
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    for(; envp[i] != NULL; i++)
    {
        printf("%s\n", envp[i]);
    }
    return 0;
}

