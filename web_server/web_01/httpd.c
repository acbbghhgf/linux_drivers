/*************************************************************************
	> File Name: httpd.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 11时46分27秒
 ************************************************************************/

#include "httpd.h"

int response_file(int src, int dst)
{
    int r, w;
    char buf[1024] = {0};
    int total = 0;

    while((r = read(src, buf, 1024)) > 0)
    {
        while(r)
        {
            w = write(dst, buf, r);
            r = r - w;
            total += w;
        }
        memset(buf, 0, strlen(buf));
    }
    if(r == -1)
    {
        perror("read");
        return -1;
    }
    return total;
}

int look_for_uri(const char *uri, const char *dir)
{
    DIR *pdir;
    struct dirent *ent;

    pdir = opendir(dir);
    if(pdir == NULL)
    {
        return 404;
    }

    while((ent = readdir(pdir)))
    {
        if((ent->d_type == 4) && strcmp(ent->d_name, ".") && strcmp(ent->d_name, ".."))
        {
            char subdir[100] = {0};
            sprintf(subdir, "%s/%s", dir, ent->d_name);
            if(200 == look_for_uri(uri, subdir)){
                return 200;
            }
        }
        else if(ent->d_type == 8)
        {
            if(!strcmp(uri, ent->d_name))
            {
                closedir(pdir);
                return 200;
            }
        }
    }
    closedir(pdir);
    return 404;
}

void response_head(response_t *res, int fd)
{
    char buffer[1024] = {0};
    sprintf(buffer, "%s %d OK\r\n \
    Content-Type:%s\r\n \
            STD_HEADER \
           \r\n", res->protocol, res->status, res->file_type);

    write(fd, buffer, strlen(buffer));
}

void parse_request_head_info(int fd, request_t *req)
{
    char buf[1024] = {0};
    int r = read(fd, buf, 1024);
    if(r < 0)
    {
        perror("read");
        return ;
    }
    printf("\n=================\n recv req data: %s\n", buf);

    sscanf(buf, "%s%s%s", req->method, req->path, req->protocol);

    if(!strcmp(req->path, "/"))
    {
        strcpy(req->path, "/index.html");
    }

    printf("method : %s\n", req->method);
    printf("url path : %s\n", req->path);
    printf("protocol : %s\n", req->protocol);
    return ;
}

const char *get_file_type(const char *file)
{
    char *suffix = NULL;
    suffix = strrchr(file, '.');
    if(suffix == NULL)
    {
        printf("get file type error.\n");
        return "";
    }

    if(strcmp(suffix, ".html") == 0)
    {
        return "text/html";
    }
    else if(strcmp(suffix, ".jpg") == 0)
    {
        return "image/jpg";
    }
    else if(strcmp(suffix, ".png") == 0)
    {
        return "image/png";
    }
    else if(strcmp(suffix, ".css") == 0)
    {
        return "text/css";
    }
    else if(strcmp(suffix, ".gif") == 0)
    {
        return "image/gif";
    }
    else{
        printf("do not know type!\n");
        return "";
    }
}

void do_request(const request_t *req, response_t *res, const char *dir)
{
    char file[128] = {0};
    strcpy(file, req->path);

    char *filename = basename(file);
    strcpy(res->file_type, get_file_type(filename));

    res->status = look_for_uri(filename, dir);
    strcpy(res->protocol, req->protocol);

    printf("file type : %s\n", res->file_type);
    printf("status : %d\n", res->status);
    printf("protocol:%s\n", res->protocol);
}


void do_response(response_t *res, const char *file, int c_fd)
{
    printf("%s:%s\n", __func__, file);
    if(res->status == 200)
    {
        response_head(res, c_fd);
        int src = open(file, O_RDONLY);
        if(src <0)
        {
            perror("open");
            printf("file = %s\n", file);
            return ;
        }
        response_file(src, c_fd);
        close(src);
    }
    if(res->status == 404)
    {
        response_head(res, c_fd);
        int src = open("www/error.html", O_RDONLY);
        if(src < 0)
        {
            perror("open");
            return ;
        }
        response_file(src, c_fd);
        close(src);
    }
}
