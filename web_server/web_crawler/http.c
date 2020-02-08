/*************************************************************************
	> File Name: http.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 17时39分45秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("usage : %s <host addr> <host dns> [<message dir>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char const *ip = argv[1];
    char const *domain = argv[2];
    char const *path = argc < 4 ? "" : argv[3];

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        return EXIT_FAILURE;
    }
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7777);

    if(!inet_aton(ip, &addr.sin_addr))
    {
        perror("inet_aton");
        return EXIT_FAILURE;
    }

    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }
    char request[1024];
    sprintf(request, "GET /%S HTTP/1.0\r\n \
    Host: %s\r\n \
    Accept: */*\r\n \
    Connection: Close\r\n \
    User-Agent: Mozilla/5.0\r\n \
    Referer: %s\r\n\r\n", path, domain, domain);

    if(send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    for(;;)
    {
        char respond[1024] = {0};
        ssize_t rlen = recv(sockfd, respond, sizeof(respond) -1, 0);
        if(rlen == -1)
        {
            perror("recv");
            return EXIT_FAILURE;
        }
        if(!rlen)
        {
            break;
        }
        printf("%s", respond);
    }
    printf("\n");
    close(sockfd);
    return EXIT_SUCCESS;
}
