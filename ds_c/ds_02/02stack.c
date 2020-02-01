/*************************************************************************
	> File Name: 02stack.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 20时54分30秒
 ************************************************************************/
#include "02stack.h"
void stack_init(stack *p_stack)
{
    p_stack->num = 0;
}

void stack_deinit(stack *p_stack)
{
    p_stack->num = 0;
}

int stack_full(const stack *p_stack)
{
    return p_stack->num >= SIZE;
}

int stack_empty(const stack *p_stack)
{
    return !(p_stack->num);
}
int stack_size(const stack *p_stack)
{
    return p_stack->num;
}
void stack_push(stack *p_stack, int num)
{
    p_stack->buf[p_stack->num] = num;
    p_stack->num++;
}

int stack_pop(stack *p_stack)
{
    int ret = p_stack->buf[p_stack->num - 1];
    p_stack->num--;
    return ret;
}
int stack_top(const stack *p_stack)
{
    return p_stack->buf[p_stack->num - 1];
}

