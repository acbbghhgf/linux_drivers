/*************************************************************************
	> File Name: config.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 11时25分57秒
 ************************************************************************/

#include "config.h"

int get_server_conf(const char *path, struct server_conf *s_conf)
{
    char name[64];
    char value[128];
    FILE *fp;

    fp = fopen(path, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    while(fscanf(fp, "%s%s", name, value)!=EOF)
    {
        if(!strcmp(name, "port"))
        {
            s_conf->port = atoi(value);
        }
        if(!strcmp(name, "Document"))
        {
            strcpy(s_conf->release_dir, value);
        }
    }
    fclose(fp);
    return 0;
}
