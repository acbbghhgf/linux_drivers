/*************************************************************************
	> File Name: config.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 11时24分30秒
 ************************************************************************/

#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct server_conf{
    short port;
    char release_dir[128];
}server_conf_t;

int get_server_conf(const char *path, struct server_conf *s_conf);

#endif
