/*************************************************************************
	> File Name: shmA.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 20时31分21秒
 ************************************************************************/

#include<stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>

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
    printf("get share memory id : %d\n", shmid);
    void *p = shmat(shmid, NULL, 0);
    if(p == (void *)-1)
    {
        perror("shmat");
        return -3;
    }
    strcpy(p, "hello ww test\n");
    shmdt(p);
    return 0;
}

