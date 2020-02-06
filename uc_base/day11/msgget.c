/*************************************************************************
	> File Name: msgget.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 20时07分16秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key;
    key = ftok("hello", 32);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    printf("key = %x\n", key);
    int msgid = msgget(key, IPC_CREAT | 0664);
    if(msgid < 0)
    {
        perror("msgget");
        return -2;
    }
    printf("msggid = %d\n", msgid);
    return 0;
}

