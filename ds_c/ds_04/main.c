/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月01日 星期六 21时31分51秒
 ************************************************************************/

#include<stdio.h>
#include "tree.h"

void print_cb(int num)
{
    printf("%d ", num);
}

int main()
{
    tree tr = {0};
    tree_init(&tr);
    
    tree_insert_in_order(&tr, 40);
    tree_insert_in_order(&tr, 30);
    tree_insert_in_order(&tr, 20);
    tree_insert_in_order(&tr, 10);
    tree_insert_in_order(&tr, 80);
    tree_insert_in_order(&tr, 70);
    tree_insert_in_order(&tr, 60);

    printf("height = %d \n", tree_height(&tr));

    tree_remove(&tr, 70);
    printf("height = %d \n", tree_height(&tr));

    tree_remove(&tr, 30);
    printf("height = %d \n", tree_height(&tr));
  
    tree_miter(&tr, print_cb);
    printf("\n");
    tree_deinit(&tr);
    return 0;
}
