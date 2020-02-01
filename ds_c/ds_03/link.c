/*************************************************************************
	> File Name: link.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 21时33分44秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "link.h"
void link_init(link_t *p)
{
    p->head.p_next = &p->tail;
    p->tail.p_prev = &p->head;
    p->tail.p_next = NULL;
    p->head.p_prev = NULL;
    p->p_cur = NULL;
}

void link_deinit(link_t *p)
{
    while(p->head.p_next != &p->tail)
    {
        node_t *p_first = &p->head;
        node_t *p_mid = p_first->p_next;
        node_t *p_last = p_mid->p_next;
        p_first->p_next = p_last;
        p_last->p_prev = p_first;
        free(p_mid);
        p_mid = NULL;
    }
}
int link_size(const link_t *p)
{
    int cnt = 0;
    const node_t *p_node = NULL;
    for(p_node = &p->head; p_node != &p->tail; p_node = p_node->p_next)
    {
        const node_t *p_first = p_node;
        const node_t *p_mid = p_first->p_next;
        const node_t *p_last = p_mid->p_next;
        if(p_mid != &p->tail)
        {
            cnt++;
        }
    }
    return cnt;
}
void link_add_head(link_t *p, int num)
{
    node_t *p_first = &p->head;
    node_t *p_mid = p_first->p_next;
    node_t *p_last = p_mid->p_next;
    node_t *p_node = (node_t *)malloc(sizeof(node_t));
    if(!p_node)
    {
        return ;
    }
    p_node->num = num;
    p_node->p_next = NULL;
    p_node->p_prev = NULL;
    p_first->p_next = p_node;
    p_node->p_next = p_mid;
    p_node->p_prev = p_first;
    p_mid->p_prev = p_node;
}

void link_append(link_t *p, int num)
{
    node_t *p_first = p->tail.p_prev;
    node_t *p_mid = p_first->p_next;
    node_t *p_last = p_mid->p_next;
    node_t *p_node = (node_t *)malloc(sizeof(node_t));
    if(!p_node)
    {
        return ;
    }
    p_node->num = num;
    p_node->p_next = NULL;
    p_node->p_prev = NULL;
    p_first->p_next = p_node;
    p_node->p_next = p_mid;
    p_node->p_prev = p_first;
    p_mid->p_prev = p_node;
}
void link_insert(link_t *p, int num)
{
    node_t *p_tmp = NULL;
    node_t *p_node = (node_t *)malloc(sizeof(node_t));
    if(!p_node)
    {
        return ;
    }
    p_node->num = num;
    p_node->p_next = NULL;
    p_node->p_prev = NULL;
    for(p_tmp = &p->head; p_tmp != &p->tail; p_tmp = p_tmp->p_next)
    {
        node_t *p_first = p_tmp;
        node_t *p_mid = p_first->p_next;
        node_t *p_last = p_mid->p_next;
        if(p_mid == &p->tail || p_mid->num > num)
        {
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            p_node->p_prev = p_first;
            p_mid->p_prev = p_node;
            break;
        }
    }
}

void link_remove_head(link_t *p)
{
    node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    if(p->head.p_next == &p->tail)
    {
        return ;
    }
    p_first = &p->head;
    p_mid = p_first->p_next;
    p_last = p_mid->p_next;
    p_first->p_next = p_last;
    p_last->p_prev = p_first;
    free(p_mid);
    p_mid = NULL;
    p->p_cur = NULL;
}

void link_remove_tail(link_t *p)
{
    node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    if(p->head.p_next == &p->tail)
    {
        return ;
    }
    p_first = p->tail.p_prev->p_prev;
    p_mid = p_first->p_next;
    p_last = p_mid->p_next;
    p_first->p_next = p_last;
    p_last->p_prev = p_first;
    free(p_mid);
    p_mid = NULL;
    p->p_cur = NULL;
}

void link_remove(link_t *p, int num)
{
    node_t *p_node = NULL;
    for(p_node = &p->head; p_node != &p->tail; p_node = p_node->p_next)
    {
        node_t *p_first = p_node;
        node_t *p_mid = p_first->p_next;
        node_t *p_last = p_mid->p_next;
        if(p_mid != &p->tail && p_mid->num == num)
        {
            p_first->p_next = p_last;
            p_last->p_prev = p_first;
            free(p_mid);
            p_mid = NULL;
            break;
        }
    }
    p->p_cur = NULL;
}

int link_get_head(const link_t *p, int *p_num)
{
    if(p->head.p_next == &p->tail)
    {
        return 0;
    }
    else{
        *p_num = p->head.p_next->num;
        return 1;
    }
}
int link_get_tail(const link_t *p, int *p_num)
{
    if(p->head.p_next == &p->tail)
    {
        return 0;
    }
    else{
        *p_num = p->tail.p_prev->num;
        return 1;
    }
}
int link_get(const link_t *p, int sn, int *p_num)
{
    int cnt = 0;
    const node_t *p_node = NULL;
    for(p_node = &p->head; p_node != &p->tail; p_node = p_node->p_next)
    {
        const node_t *p_first = p_node;
        const node_t *p_mid = p_first->p_next;
        const node_t *p_last = p_mid->p_next;
        if(p_mid != &p->tail)
        {
            if(cnt == sn)
            {
                *p_num = p_mid->num;
                return 1;
            }
            cnt++;
        }
    }
    return 0;
}
void link_begin(link_t *p)
{
    p->p_cur = &p->head;
}
int link_next(link_t *p, int *p_num)
{
    if(!p->p_cur)
    {
        return 0;
    }
    p->p_cur = p->p_cur->p_next;
    if(p->p_cur == &p->tail)
    {
        p->p_cur = NULL;
        return 0;
    }
    else{
        *p_num = p->p_cur->num;
        return 1;
    }
}
