/*************************************************************************
	> File Name: pthread_m.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 17时47分02秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int counter;

void *doit(void *arg)
{
    int i, value;
    for(i = 0; i < 50; i++)
    {
        pthread_mutex_lock(&mutex);
        value = counter;
        printf("%lu:%d\n", pthread_self(), value+1);
        counter = value + 1;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t tidA, tidB;
    pthread_create(&tidA, NULL, doit, NULL);
    pthread_create(&tidB, NULL, doit, NULL);

    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}

