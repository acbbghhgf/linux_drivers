/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月01日 星期六 20时55分11秒
 ************************************************************************/

#include<stdlib.h>
#include "tree.h"

void tree_init(tree *p_tree)
{
    p_tree->p_node = NULL;
}

void tree_deinit(tree *p_tree)
{
    if(!(p_tree->p_node))
    {
        return ;
    }
    tree_deinit(&(p_tree->p_node->left));
    tree_deinit(&(p_tree->p_node->right));
    free(p_tree->p_node);
    p_tree->p_node = NULL;
}

tree *tree_search_in_order(const tree *p_tree, int num)
{
    if(!(p_tree->p_node))
    {
        return (tree *)p_tree;
    }
    if(p_tree->p_node->num == num)
    {
        return (tree *)p_tree;
    }
    else if(p_tree->p_node->num > num)
    {
        return tree_search_in_order(&(p_tree->p_node->left), num);
    }
    else{
        return tree_search_in_order(&(p_tree->p_node->right), num);
    }
}

void tree_insert_in_order(tree *p_tree, int num)
{
    node *p_node = NULL;
    tree *p_tmp = tree_search_in_order(p_tree, num);
    if(p_tmp->p_node)
    {
        return ;
    }
    p_node = (node *)malloc(sizeof(node));
    if(p_node)
    {
        p_node->num = num;
        p_node->left.p_node = NULL;
        p_node->right.p_node = NULL;
        p_tmp->p_node = p_node;
    }
}

void tree_miter(const tree *p_tree, void (*p_func)(int))
{
    if(!(p_tree->p_node))
    {
        return ;
    }
    tree_miter(&(p_tree->p_node->left), p_func);
    p_func(p_tree->p_node->num);
    tree_miter(&(p_tree->p_node->right), p_func);
}

void tree_fiter(const tree *p_tree, void(*p_func)(int))
{
    if(!(p_tree->p_node))
    {
        return ;
    }
    p_func(p_tree->p_node->num);
    tree_fiter(&(p_tree->p_node->left), p_func);
    tree_fiter(&(p_tree->p_node->right), p_func);
}

void tree_liter(const tree *p_tree, void (*p_func)(int))
{
    if(!(p_tree->p_node))
    {
        return ;
    }
    tree_liter(&(p_tree->p_node->left), p_func);
    tree_liter(&(p_tree->p_node->right), p_func);
    p_func(p_tree->p_node->num);
}

void tree_remove(tree *p_tree, int num)
{
    node *p_node = NULL;
    tree *p_tmp = tree_search_in_order(p_tree, num);
    if(!(p_tmp->p_node))
    {
        return ;
    }
    p_node = p_tmp->p_node;
    if(!(p_node->left.p_node))
    {
        p_tmp->p_node = p_node->right.p_node;
    }
    else if(!(p_node->right.p_node))
    {
        p_tmp->p_node = p_node->left.p_node;
    }
    else{
        tree *p_tmp1 = tree_search_in_order(&(p_node->left), p_node->right.p_node->num);
        p_tmp1->p_node = p_node->right.p_node;
        p_tmp->p_node = p_node->left.p_node;
    }
    free(p_node);
    p_node = NULL;
}

int tree_height(const tree *p_tree)
{
    int left_height = 0, right_height = 0, ret = 0;
    if(!(p_tree->p_node))
    {
        return 0;
    }
    left_height = tree_height(&(p_tree->p_node->left));
    right_height = tree_height(&(p_tree->p_node->right));
    ret = left_height > right_height ? left_height : right_height;
    return ret + 1;
}


