/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 08时47分55秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in client;
    char msg[128] = {0};
    char buf[128];

    if(argc < 2)
    {
        printf("please input server ip\n");
        return 1;
    }

    int s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_fd < 0)
    {
        perror("socket");
        return -1;
    }

    client.sin_family = AF_INET;
    client.sin_port = htons(7777);
    inet_pton(AF_INET, argv[1], &client.sin_addr);

    int c = connect(s_fd, (struct sockaddr *)&client, sizeof(client));
    if(c < 0)
    {
        perror("connect");
        return -2;
    }

#if 0
    write(s_fd, msg, strlen(msg));
    int r = read(s_fd, buf, 128);
    write(1, buf, r);
#else
    while(fgets(msg, 128, stdin) != NULL)
    {
        write(s_fd, msg, strlen(msg)+1);
        if(strcmp(msg, "quit\n")== 0)
        {
            printf(":) quit...\n");
            break;
        }
        int r = read(s_fd, buf, 128);
        write(1, buf, r);
        printf("\n");
    }
#endif
    close(s_fd);
    return 0;
}

