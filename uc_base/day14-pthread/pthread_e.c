/*************************************************************************
	> File Name: pthread_c.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 17时10分00秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

void *doit_1(void *arg)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("pid : %d\ttid : %lu\n", pid, tid);
    printf("%s\n", (char *)arg);
    printf("thread1 doit1 return\n");

    return (void *)1;
}

void *doit_2(void *arg)
{
    printf("doit2 pthread_exit\n");
    pthread_exit((void *)2);
}

void *doit_3(void *arg)
{
    while(1)
    {
        printf("doit3 running...\n");
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    void *ret;
    pthread_create(&tid, NULL, doit_1, "running...doit 1");

    pthread_join(tid, &ret);
    printf("doit1 exit code %d\n", (int)ret);

    pthread_create(&tid, NULL, doit_2, NULL);
    pthread_join(tid, &ret);
    printf("doit2 exit code %d\n", (int)ret);

    pthread_create(&tid, NULL, doit_3, NULL);
    pthread_cancel(tid);
    pthread_join(tid, &ret);
    printf("doit3 exit code %d\n", (int)ret);
    return 0;
}

