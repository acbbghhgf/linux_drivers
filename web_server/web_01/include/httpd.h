/*************************************************************************
	> File Name: include/httpd.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 11时40分56秒
 ************************************************************************/

#ifndef _INCLUDE/HTTPD_H
#define _INCLUDE/HTTPD_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <libgen.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;

typedef struct{
    char method[12];
    char path[128];
    char protocol[32];
}request_t;

typedef struct{
    int status;
    char protocol[32];
    char file_type[32];
}response_t;

int response_file(int src, int dst);
int look_for_uri(const char *uri, const char *dir);
void response_head(response_t *res, int fd);
void parse_request_head_info(int fd, request_t *req);
const char *get_file_type(const char *path);
void do_response(response_t *res, const char *file, int c_fd);
void do_request(const request_t *req, response_t *res, const char *dir);

#endif
