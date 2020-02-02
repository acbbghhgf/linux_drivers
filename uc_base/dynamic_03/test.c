/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月02日 星期日 07时59分41秒
 ************************************************************************/

#include<stdio.h>
#include <tmath.h>
typedef int(*f_t)(int, int);

int process(f_t f, int x, int y)
{
    return f(x, y);
}

int main()
{
    int a = 6, b = 2;
    f_t fun_c[4] = {t_add, t_sub, t_mul, t_div};
    f_t func;

    func = t_add;
    printf("a + b = %d \n", func(a, b));
    func = t_sub;
    printf("a - b = %d \n", func(a, b));

    printf("a * b = %d \n", process(t_mul, a, b));
    for(int i = 0; i < 4; i++)
    {
        printf("%d\n", fun_c[i](a,b));
    }
    return 0;

}

