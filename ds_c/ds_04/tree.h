/*************************************************************************
	> File Name: tree.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月21日 星期二 07时48分10秒
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H

struct node;
typedef struct{
    struct node *p_node;
}tree;


typedef struct node{
    int num;
    tree left;
    tree right;
}node;

void tree_init(tree *);
void tree_deinit(tree *);
void tree_insert_in_order(tree *, int);
void tree_miter(const tree *, void (*)(int));
void tree_fiter(const tree *, void (*)(int));
void tree_liter(const tree *, void (*)(int));
void tree_remove(tree *, int);
int tree_height(const tree *);

#endif
