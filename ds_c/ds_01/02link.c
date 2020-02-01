/*************************************************************************
	> File Name: 02link.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 07时26分49秒
 ************************************************************************/

#include<stdio.h>
typedef struct node{
    int num;
    struct node *p_next;
}node;
int main()
{
    int cnt = 0;
    node node1 = {1}, node2 = {5}, node3 = {13}, head = {0}, tail = {0}, node4 = {7};
    node *p_node = NULL;
    head.p_next = &node1;
    node1.p_next = &node2;
    node2.p_next = &node3;
    node3.p_next = &tail;

    for(p_node = &head; p_node != &tail; p_node = p_node->p_next)
    {
        node *p_first = p_node;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        if(p_mid == &tail || p_mid->num > node4.num)
        {
            p_first->p_next = &node4;
            node4.p_next = p_mid;
            break;
        }
    }
    for(p_node = &head; p_node != &tail; p_node = p_node->p_next)
    {
        node *p_first = p_node;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        if(p_mid != &tail && p_mid->num == 5)
        {
            p_first->p_next = p_last;
            break;
        }
    }
    printf("\n");
    for(p_node = &head; p_node != &tail; p_node = p_node->p_next)
    {
        node *p_first = p_node;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        if(p_mid != &tail)
        {
            cnt++;
            break;
        }
    }
    printf("有效数字个数是%d\n", cnt);
    cnt = 0;
    for(p_node = &head; p_node != &tail; p_node = p_node->p_next)
    {
        node *p_first = p_node;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        if(p_mid != &tail)
        {
            if(cnt == 2)
            {
                printf("编号为2 的数字是%d\n", p_mid->num);
                break;
            }
            cnt++;
        }
    }
    return 0;
}
