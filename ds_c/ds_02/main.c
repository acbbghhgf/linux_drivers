/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 21时01分49秒
 ************************************************************************/

#include<stdio.h>
#include "02stack.h"

int main()
{
    stack stk = {0};
    stack_init(&stk);
    printf("***********开始状态*************\n");
    printf("stack full = %d, empty = %d, size = %d\n", stack_full(&stk), stack_empty(&stk), stack_size(&stk));

    printf("***********开始push*************\n");
    stack_push(&stk, 4);
    stack_push(&stk, 10);
    stack_push(&stk, 23);
    stack_push(&stk, 31);
    stack_push(&stk, 47);

    printf("***********push完状态*************\n");
    printf("stack full = %d, empty = %d, size = %d\n", stack_full(&stk), stack_empty(&stk), stack_size(&stk));
    printf("stack top = %d\n", stack_top(&stk));

    printf("***********开始pop*************\n");
    printf("%d ", stack_pop(&stk));
    printf("%d ", stack_pop(&stk));
    printf("%d ", stack_pop(&stk));
    printf("%d ", stack_pop(&stk));
    printf("%d ", stack_pop(&stk));

    printf("***********pop后状态*************\n");
    printf("stack full = %d, empty = %d, size = %d\n", stack_full(&stk), stack_empty(&stk), stack_size(&stk));
    stack_deinit(&stk);
    return 0;

}
