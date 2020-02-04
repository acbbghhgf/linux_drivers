/*************************************************************************
	> File Name: process_layout.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 08时16分32秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int var_g = 50;
void count(void)
{
    static int c = 1;
    c++;
    printf("c = %d\n", c);
    printf("c address = %p\n", &c);
}


int main()
{
    int i = 0;
    char buf[12] = "tarena";
    char *str = "tarena";

    printf("pid = %d\n", getpid());
    printf("buf %p\n", buf);
    printf("str address %p\n", &str);
    printf("str content %p\n", str);
    for(i = 0; i < 5; i++)
        count();
    printf("var_g address %p\n", &var_g);
    getchar();
    return 0;
}

