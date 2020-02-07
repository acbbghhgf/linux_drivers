/*************************************************************************
	> File Name: p_c.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 18时07分06秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct node{
    int data;
    struct node *next;
}node_t;
typedef node_t *node_p;

node_p head;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *p(void *arg)
{
    node_p new;
    while(1)
    {
        new = (node_p)malloc(sizeof(node_t));
        new->next = NULL;
        new->data = rand() % 1000 + 1;
        pthread_mutex_lock(&mutex);
        new->next = head;
        head = new;
        printf("p %d\n", new->data);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        sleep(rand() % 5);
    }
}

void *c(void *arg)
{
    node_p tmp;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(head == NULL)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        tmp = head;
        head = head->next;
        pthread_mutex_unlock(&mutex);
        printf("c %d\n", tmp->data);
        free(tmp);
        tmp = NULL;
        sleep(rand() % 8);
    }
}

int main()
{
    pthread_t pid, cid;
    srand(time(NULL));

    pthread_create(&pid, NULL, p, NULL);
    pthread_create(&cid, NULL, c, NULL);

    pthread_join(cid, NULL);
    pthread_join(pid, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}

