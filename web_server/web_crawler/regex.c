/*************************************************************************
	> File Name: regex.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 17时54分38秒
 ************************************************************************/

#include<stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("usage : %s <HTML file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }
    if(fseek(fp, 0, SEEK_END) == -1)
    {
        perror("fseek");
        return EXIT_FAILURE;
    }
    long size = ftell(fp);
    if(size == -1)
    {
        perror("ftell");
        return EXIT_FAILURE;
    }

    char *buf = (char *)malloc(size + 1);
    if(!buf)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }
    if(fseek(fp, 0, SEEK_SET) == -1)
    {
        perror("fseek");
        return EXIT_FAILURE;
    }
    if(fread(buf, 1, size, fp) != size)
    {
        perror("fread");
        return EXIT_FAILURE;
    }

    buf[size] = '\n';
    fclose(fp);
    regex_t ex;

    int error = regcomp(&ex, "href = \"\\s*\\([^ >\"]*\\)\\s*\"", 0);
    if(error)
    {
        char errInfo[1024];
        regerror(error, &ex, errInfo, sizeof(errInfo));
        printf("regcomp: %s\n", errInfo);
        return EXIT_FAILURE;
    }
    char const *html = buf;
    regmatch_t match[2];
    while(regexec(&ex, html, 2, match, 0) != REG_NOMATCH)
    {
        html += match[1].rm_so;
        size_t len = match[1].rm_eo - match[1].rm_so;
        char *url = (char *)malloc(len + 1);
        memcpy(url, html, len);
        url[len] = '\0';
        printf("%s\n", url);
        free(url);
        html += len + match[0].rm_eo - match[1].rm_eo;
    }
    regfree(&ex);
    free(buf);
    return EXIT_SUCCESS;
}

