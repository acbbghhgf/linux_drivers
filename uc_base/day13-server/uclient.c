/*************************************************************************
	> File Name: uclient.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 09时52分58秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in SA4;

int main(int argc, char *argv[])
{
    int s_fd;
    SA4 server;
    char buf[] = "this is a test\n";
    char rbuf[128];

    if(argc < 2)
    {
        printf("please input ip...\n");
        return -1;
    }

    s_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(s_fd < 0)
    {
        perror("socket");
        return -2;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7776);
    inet_pton(AF_INET, argv[1], &server.sin_addr);
    sendto(s_fd, buf, strlen(buf)+1, 0, (SA *)&server, sizeof(server));
    int r = recvfrom(s_fd, rbuf, 128, 0, NULL, NULL);
    write(1, rbuf, r);
    printf("\n");
    close(s_fd);
    return 0;

}

