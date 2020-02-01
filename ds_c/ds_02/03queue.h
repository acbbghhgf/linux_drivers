/*************************************************************************
	> File Name: 03queue.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 21时11分14秒
 ************************************************************************/

#ifndef _03QUEUE_H
#define _03QUEUE_H

typedef struct{
    int buf[SIZE];
    int head, tail;
}queue;

void queue_init(queue *);
void queue_deinit(queue *);
int queue_full(const queue *);
int queue_empty(const queue *);
int queue_size(const queue *);
void queue_push(queue *, int);
int queue_pop(queue *);
int queue_front(const queue *);

#endif
