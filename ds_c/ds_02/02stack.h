/*************************************************************************
	> File Name: 02stack.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 20时58分55秒
 ************************************************************************/

#ifndef _02STACK_H
#define _02STACK_H

typedef struct{
    int buf[SIZE];
    int num;
}stack;

void stack_init(stack *);

void stack_deinit(stack *);

int stack_full(const stack *);

int stack_empty(const stack *);

int stack_size(const stack *);

void stack_push(stack *, int);

int stack_pop(stack *);

int stack_top(const stack *);


#endif
