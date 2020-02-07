/*************************************************************************
	> File Name: userver.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 09时46分58秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in SA4;

int main()
{
    int s_fd;
    SA4 server, client;
    char buf[128];
    int r;

    s_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(s_fd < 0)
    {
        perror("socket");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7776);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    int b = bind(s_fd, (SA *)&server, sizeof(server));
    if(b < 0)
    {
        perror("bind");
        return -2;
    }
    int clilen = sizeof(client);
    while((r=recvfrom(s_fd, buf, 128, 0, (SA *)&client, &clilen)) > 0)
    {
        for(int i = 0; i < r; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        sendto(s_fd, buf, r, 0, (SA *)&client, sizeof(client));
    }
    close(s_fd);
    return 0;

}

