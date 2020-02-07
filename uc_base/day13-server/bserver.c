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
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int t_listen(short port, int backlog)
{
    int s_fd;
    struct sockaddr_in server;
    
    s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_fd < 0)
    {
        perror("socket");
        return -1;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    int b = bind(s_fd, (struct sockaddr *)&server, sizeof(server));
    if(b < 0)
    {
        perror("bind");
        return -2;
    }
    listen(s_fd, backlog);
    return s_fd;
}

int main()
{
    int s_fd, conn_fd;
    char buf[128];
    int len;
    char IP[128];
    struct sockaddr_in client;

    s_fd = t_listen(7777, 5);

    while(1)
    {
        len = sizeof(client);
        conn_fd = accept(s_fd, (struct sockaddr *)&client, &len);
        if(conn_fd < 0)
        {
            perror("accept");
            return -3;
        }
        printf("client:%s\n", inet_ntop(AF_INET, &client.sin_addr, IP, 128));
        
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork");
            return -4;
        }
        else if(pid == 0)
        {
            // child pid
            close(s_fd);
            while(1)
            {
                int r = read(conn_fd, buf, 128);
                for(int i = 0; i < r; i++)
                {
                    buf[i] = toupper(buf[i]);
                }
                if(strcmp(buf, "QUIT\n") == 0)
                {
                    break;
                }
                write(conn_fd, buf, r);
            }
            close(conn_fd);
            exit(0);
        }
        else{
            //parent pid
            close(conn_fd);
            waitpid(-1, NULL, WNOHANG);
        }
    }
    close(s_fd);
    return 0;

}

