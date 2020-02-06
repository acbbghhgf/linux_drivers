/*************************************************************************
	> File Name: env_test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 08时44分24秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main()
{
    printf("USER:%s\n", getenv("USER"));

    putenv("name=ww-test");
    printf("name:%s\n", getenv("name"));

    setenv("name", "test_plus", 1);
    printf("name:%s\n", getenv("name"));
    unsetenv("name");

    printf("name:%s\n", getenv("name"));
    clearenv();
    printf("USER:%s\n", getenv("USER"));

    return 0;
}

