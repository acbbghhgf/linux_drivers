/*************************************************************************
	> File Name: shm.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 20时27分20秒
 ************************************************************************/

#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main()
{
    key_t key;
    key = ftok("hello", 32);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    printf("key : %d\n", key);

    int shmid = shmget(key, 1024, IPC_CREAT | 0664);
    if(shmid < 0)
    {
        perror("shmget");
        return -2;
    }
    printf("get share memery id : %d\n", shmid);
    return 0;
}

