/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 18时33分23秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    key_t key;
    int ret;
    key = ftok(".", 51);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    int semid = semget(key, 1, IPC_CREAT | 0664);
    if(semid < 0)
    {
        perror("semget");
        return -2;
    }

    while(1)
    {
        ret = semctl(semid, 0, GETVAL);
        if(ret > 0)
        {
            printf("%d resources...\n", ret);
        }
        else{
            printf("no resources...\n");
        }
        sleep(2);
    }
    return 0;
}

