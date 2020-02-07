/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 08时42分20秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <ctype.h>
#include <arpa/inet.h>

int main()
{
    int s_fd, conn_fd;
    char buf[128];
    struct sockaddr_in server;

    s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_fd < 0)
    {
        perror("socket");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7777);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    int b = bind(s_fd, (struct sockaddr *)&server, sizeof(server));
    if(b < 0)
    {
        perror("bind");
        return -2;
    }
    listen(s_fd, 5);
    while(1)
    {
        conn_fd = accept(s_fd, NULL, NULL);
        if(conn_fd < 0)
        {
            perror("accept");
            return -3;
        }
        int r = read(conn_fd, buf, 128);
        for(int i = 0; i < r; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        write(conn_fd, buf, r);
        close(conn_fd);
    }
    close(s_fd);
    return 0;

}

