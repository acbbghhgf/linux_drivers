/*************************************************************************
	> File Name: pthread_c.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 17时10分00秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

void *doit(void *arg)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("pid : %d\ttid : %lu\n", pid, tid);
    printf("%s\n", (char *)arg);
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, doit, "new");
    printf("main tid : %lu\n", tid);
    sleep(2);
    doit("main");
    return 0;
}

