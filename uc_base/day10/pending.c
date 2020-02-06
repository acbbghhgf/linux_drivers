/*************************************************************************
	> File Name: pending.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 10时32分07秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>


int main()
{
    printf("pid : %d\n", getpid());
    sigset_t b,p;
    sigemptyset(&b);
    sigaddset(&b, 2);
    sigaddset(&b, 3);
    sigprocmask(SIG_SETMASK, &b, NULL);
    while(1)
    {
        sleep(1);
        sigemptyset(&p);
        sigpending(&p);
        int f = sigismember(&p, 2);
        if(f < 0)
        {
            perror("sigismember");
            return -1;
        }
        else if(f == 0)
        {
            printf("signal is not 2\n");
        }
        else{
            printf("2 signal recv\n");
        }

        int f3 = sigismember(&p, 3);
        if(f3 < 0)
        {
            perror("sigismember");
            return -2;
        }
        else if(f3 == 0)
        {
            printf("signal is not 3\n");
        }
        else{
            printf("3 signal recv\n");
        }
    }
    return 0;

}

