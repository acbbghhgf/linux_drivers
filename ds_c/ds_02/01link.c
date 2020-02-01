/*
    动态分配节点演示
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int num;
    struct node *p_next;
} node;
int main() {
    int num = 0;
    node *p_node = NULL, *p_tmp = NULL;
    node head = {0}, tail = {0};
    //准备一个空的链式物理结构
    head.p_next = &tail;
    while (1) {
        printf("请输入一个数字：");
        scanf("%d", &num);
        if (num < 0) {
            break;
        }
        //动态分配一个节点
        p_node = (node *)malloc(sizeof(node));
        if (!p_node) {
            continue;
        }
        p_node->num = num;
        p_node->p_next = NULL;
        for (p_tmp = &head;p_tmp != &tail;p_tmp = p_tmp->p_next) {
            node *p_first = p_tmp;
            node *p_mid = p_first->p_next;
            node *p_last = p_mid->p_next;
            if (p_mid == &tail || p_mid->num > num) {
                //如果p_mid指针和尾节点捆绑
                //或p_mid指针捆绑的节点里的
                //数字比新数字大就应该把新
                //节点插入到p_first和p_mid
                //中间
                p_first->p_next = p_node;
                p_node->p_next = p_mid;
                break;
            }
        }
    }
    //删除某个数字所在的节点
    printf("请输入要删除的数字：");
    scanf("%d", &num);
    for (p_tmp = &head;p_tmp != &tail;p_tmp = p_tmp->p_next) {
        node *p_first = p_tmp;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        if (p_mid != &tail && p_mid->num == num) {
            //p_mid指针没有和尾节点捆绑
            //并且p_mid指针捆绑的节点里的
            //数字就是要删除的数字
            p_first->p_next = p_last;
            free(p_mid);
            p_mid = NULL;
            break;
        }
    }
    //把有效节点里的数字按顺序显示在屏幕上
    for (p_tmp = &head;p_tmp != &tail;p_tmp = p_tmp->p_next) {
        node *p_first = p_tmp;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        if (p_mid != &tail) {
            printf("%d ", p_mid->num);
        }
    }
    printf("\n");
    //释放所有有效节点
    while (head.p_next != &tail) {
        node *p_first = &head;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        //p_mid和第一个有效节点捆绑
        p_first->p_next = p_last;
        free(p_mid);
        p_mid = NULL;
    }
    return 0;
}





