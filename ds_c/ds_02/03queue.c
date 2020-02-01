/*************************************************************************
	> File Name: 03queue.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 21时13分16秒
 ************************************************************************/

#include "03queue.h"
void queue_init(queue *p_queue)
{
    p_queue->head = 0;
    p_queue->tail = 0;
}

void queue_deinit(queue *p_queue)
{
    p_queue->head = 0;
    p_queue->tail = 0;
}

int queue_full(const queue *p_queue)
{
    return p_queue->tail >= SIZE;
}
int queue_empty(const queue *p_queue)
{
    return p_queue->tail - p_queue->head;
}
int queue_size(const queue *p_queue)
{
    return p_queue->tail - p_queue->head;
}
void queue_push(queue *p_queue, int num)
{
    p_queue->buf[p_queue->tail] = num;
    p_queue->tail++;
}
int queue_pop(queue *p_queue)
{
    p_queue->head++;
    return p_queue->buf[p_queue->head - 1];
}
int queue_front(const queue *p_queue)
{
    return p_queue->buf[p_queue->head];
}
