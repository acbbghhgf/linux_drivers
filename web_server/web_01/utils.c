/*************************************************************************
	> File Name: utils.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 11时31分38秒
 ************************************************************************/

#include "utils.h"

void daemon_mode()
{
    int fr = 0;

    fr = fork();
    if(fr < 0)
    {
        perror("fork");
        fprintf(stderr, "fork() failed\n");
        exit(1);
    }
    else if(fr > 0)
    {
        exit(0);
    }

    if(setsid() < 0)
    {
        fprintf(stderr, "setsid() failed\n");
        exit(1);
    }
    
    fr = fork();
    if(fr < 0)
    {
        fprintf(stderr, "fork() failed\n");
        exit(1);
    }
    else if(fr > 0)
    {
        fprintf(stderr, "forked to background (%d)\n", fr);
        exit(0);
    }

    umask(0);

    fr = chdir("/");
    if(fr != 0)
    {
        fprintf(stderr, "chdir() failed\n");
        exit(0);
    }

    close(0);
    close(1);
    close(2);

    open("/dev/null", O_RDWR);
    fr = dup(0);
    fr = dup(0);

    signal(SIGCHLD, SIG_IGN);

}

