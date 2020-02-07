/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 18时36分29秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

typedef union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
}semun_t;

int main()
{
    key_t key;
    semun_t arg;
    struct sembuf sb = {0, -1, 0};

    key = ftok(".", 51);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }

    int semid = semget(key, 1, IPC_CREAT | 0664);
    if(semid < 0)
    {
        perror("semid");
        return -2;
    }

    arg.val = 5;
    int r = semctl(semid, 0, SETVAL, arg);
    if(r < 0)
    {
        perror("semctl");
        return -3;
    }
    while(1)
    {
        if(semop(semid, &sb, 1) == -1)
        {
            perror("semop");
            return -4;
        }
        sleep(3);
    }
    return 0;
}

