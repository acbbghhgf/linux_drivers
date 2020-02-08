/*************************************************************************
	> File Name: webserver.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 11时06分40秒
 ************************************************************************/

#include "httpd.h"
#include "utils.h"
#include "config.h"

void signal_handler(int sig)
{
    printf("get signal : %d\n", sig);
    printf("server quit... :)\n");
    exit(0);
}

void *client_thread(void *arg)
{
    int c_fd = *(int *)arg;
    request_t req;
    memset(&req, 0, sizeof(req));
    parse_request_head_info(c_fd, &req);

    response_t response;
    memset(&response, 0, sizeof(response));

    server_conf_t s_conf;
    get_server_conf("configure", &s_conf);

    char file[128] = {0};
    strcat(file, s_conf.release_dir);
    strcat(file, req.path);
    printf("file:%s\n", file);

    do_request(&req, &response, s_conf.release_dir);
    do_response(&response, file, c_fd);

    close(c_fd);
    return NULL;
}

void run(int s_fd)
{
    SAI client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t client;

    while(1)
    {
        int c_fd;
        c_fd = accept(s_fd, (SA *)&client_addr, &addr_len);
        if(pthread_create(&client, NULL, &client_thread, &c_fd) != 0)
        {
            close(c_fd);
            continue;
        }
        pthread_detach(client);
    }
}

int create_server(int port)
{
    SAI server_addr;
    int s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_fd < 0)
    {
        perror("socket");
        return -1;
    }
    int on = 1;
    setsockopt(s_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(s_fd, (SA *)&server_addr, sizeof(server_addr)) < 0)
    {
        close(s_fd);
        perror("bind");
        return -1;
    }
    listen(s_fd, 10);
    return s_fd;
}

int main(int argc, char *argv[])
{
    int daemon = 0;
    if(argc == 2)
    {
        daemon = !strcmp(argv[1], "-b");
    }
    if(daemon)
    {
        printf("enabling daemon mode!\n");
        daemon_mode();
    }

    server_conf_t s_conf;
    get_server_conf("configure", &s_conf);
    printf("config port : %d\n", s_conf.port);
    printf("config directory: %s\n", s_conf.release_dir);

    signal(SIGPIPE, SIG_IGN);
    signal(SIGINT, signal_handler);

    int s_fd = create_server(s_conf.port);
    if(s_fd < 0)
    {
        printf("create server fail\n");
        return -1;
    }
    else{
        printf("server create success. s_fd = %d\n", s_fd);
    }
    run(s_fd);

    return 0;
}
