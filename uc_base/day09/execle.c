/*************************************************************************
	> File Name: execle.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 09时41分46秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main()
{
    char *const ps_env[] = {"name=ww-test", NULL};

    execle("./myenv", "myenv", NULL, ps_env);

    return 0;
}

