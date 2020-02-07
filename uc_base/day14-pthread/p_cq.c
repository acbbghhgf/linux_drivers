/*************************************************************************
	> File Name: p_cq.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 18时21分55秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

int queue[5];
sem_t c_num, p_num;

void *p(void *arg)
{
    int j = 0;
    while(1)
    {
        sem_wait(&p_num);
        queue[j] = rand() % 1000 + 1;
        printf("p %d\n", queue[j]);
        sem_post(&c_num);
        j = (j + 1) % 5;
        sleep(rand() % 3);
    }
}

void *c(void *arg)
{
    int i = 0;
    while(1)
    {
        sem_wait(&c_num);
        printf("c %d\n", queue[i]);
        queue[i] = 0;
        sem_post(&p_num);
        i = (i + 1) % 5;
        sleep(rand() %5);
    }
}

int main()
{
    pthread_t pid, cid;
    srand(time(NULL));
    sem_init(&c_num, 0, 0);
    sem_init(&p_num, 0, 5);

    pthread_create(&pid, NULL, p, NULL);
    pthread_create(&cid, NULL, c, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    sem_destroy(&c_num);
    sem_destroy(&p_num);
    return 0;
}

