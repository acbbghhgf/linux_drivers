/*************************************************************************
	> File Name: ftok.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 20时01分00秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
    key_t key;
    key = ftok("hello", 32);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    printf("key = %d\n", key);
    return 0;
}

