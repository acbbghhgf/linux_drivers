/*************************************************************************
	> File Name: dynamic.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月02日 星期日 07时45分18秒
 ************************************************************************/

#include<stdio.h>
#include <dlfcn.h>
typedef int (*math_t)(int, int);

int main()
{
    void *p = dlopen("libtmath.so", RTLD_NOW);
    if(p == NULL)
    {
        printf("%s\n", dlerror());
        return 1;
    }
    printf("load success..\n");
    void *func = dlsym(p, "t_sub");
    if(func == NULL)
    {
        printf("%s \n, ",dlerror());
        return 2;
    }
    math_t q = func;
    printf("6 - 2 = %d\n", q(6, 2));
    dlclose(p);
    return 0;

}

