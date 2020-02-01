/*
    队列测试
*/
#include <stdio.h>
#include "03queue.h"
int main() {
    queue que = {0};
    queue_init(&que);
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("数字个数是%d\n", queue_size(&que));
    queue_push(&que, 4);
    queue_push(&que, 11);
    queue_push(&que, 23);
    queue_push(&que, 31);
    queue_push(&que, 42);
    queue_push(&que, 55);
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("数字个数是%d\n", queue_size(&que));
    printf("最前面的数字是%d\n", queue_front(&que));
    printf("%d ", queue_pop(&que));
    printf("%d ", queue_pop(&que));
    printf("%d\n", queue_pop(&que));
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("数字个数是%d\n", queue_size(&que));
    printf("%d ", queue_pop(&que));
    printf("%d\n", queue_pop(&que));
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("数字个数是%d\n", queue_size(&que));
    queue_deinit(&que);
    return 0;
}



