/*
    链表测试
*/
#include <stdio.h>
#include "link.h"
int main() {
    int num = 0, size = 0, tmp = 0;
    link_t lnk = {0};
    link_init(&lnk);
    link_insert(&lnk, 11);
    link_insert(&lnk, 55);
    link_insert(&lnk, 31);
    link_insert(&lnk, 63);
    link_insert(&lnk, 23);
    link_insert(&lnk, 42);
    link_add_head(&lnk, 7);
    link_add_head(&lnk, 3);
    link_append(&lnk, 75);
    link_append(&lnk, 86);
    printf("有效数字个数是%d\n", link_size(&lnk));
    link_get_head(&lnk, &num);
    printf("第一个数字是%d\n", num);
    link_get_tail(&lnk, &num);
    printf("最后一个数字是%d\n", num);
    link_remove_head(&lnk);
    link_remove_tail(&lnk);
    link_remove(&lnk, 42);
    size = link_size(&lnk);
    for (tmp = 0;tmp <= size - 1;tmp++) {
        link_get(&lnk, tmp, &num);
        printf("%d ", num);
    }
    printf("\n");
    link_begin(&lnk);
    while (1) {
        tmp = link_next(&lnk, &num);
        if (!tmp) {
            break;
        }
        printf("%d ", num);
    }
    printf("\n");
    link_deinit(&lnk);
    return 0;
}






