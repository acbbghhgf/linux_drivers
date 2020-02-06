/*************************************************************************
	> File Name: processA.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 20时14分42秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct msgbuf{
    long mtype;
    char mtext[256];
}msgbuf_t;

int main()
{
    key_t key;
    msgbuf_t mb;
    key = ftok("hello", 32);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }

    int msgid = msgget(key, IPC_CREAT | 0664);
    if(msgid < 0)
    {
        perror("msgid");
        return -2;
    }
    mb.mtype = 3;
    strcpy(mb.mtext, "this is test\n");
    int s = msgsnd(msgid, &mb, strlen(mb.mtext)+1, 0);
    if(s < 0)
    {
        perror("msgsnd");
        return -3;
    }
    return 0;
}

