/*************************************************************************
	> File Name: link.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 21时27分43秒
 ************************************************************************/

#ifndef _LINK_H
#define _LINK_H

typedef struct node{
    int num;
    struct node *p_next;
    struct node *p_prev;
}node_t;

typedef struct{
    node_t head, tail;
    node_t *p_cur;
}link_t;

void link_init(link_t *);
void link_deinit(link_t *);
int link_size(const link_t *);
void link_add_head(link_t *, int);
void link_append(link_t *, int);
void link_insert(link_t *, int);
void link_remove_head(link_t *);
void link_remove_tail(link_t *);
void link_remove(link_t *, int);
int link_get_head(const link_t *, int *);
int link_get_tail(const link_t *, int *);
int link_get(const link_t *, int , int *);
void link_begin(link_t *);
int link_next(link_t *, int *);

#endif
