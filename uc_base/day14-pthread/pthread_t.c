/*************************************************************************
	> File Name: pthread_t.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 17时38分32秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>

int counter;
void *doit(void *arg)
{
    int i, value;
    for(i = 0; i< 5000; i++)
    {
        value = counter;
        printf("%lu:%d\n", pthread_self(), value+1);
        counter = value + 1;
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

    return 0;
}

