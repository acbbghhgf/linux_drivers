/*************************************************************************
	> File Name: dns.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 17时25分52秒
 ************************************************************************/

#include<stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc <2)
    {
        printf("use: %s <dns>\n", argv[1]);
        return EXIT_FAILURE;
    }
    struct hostent *host = gethostbyname(argv[1]);

    if(!host)
    {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    if(host->h_addrtype == AF_INET)
    {
        printf("host name : \n");
        printf("\t%s\n", host->h_name);
        printf("host name table: \n");
        
        char **pp = host->h_aliases;
        while(*pp)
        {
            printf("\t%s\n", *pp++);
        }
        printf("host addr table: \n");
        struct in_addr **pa = (struct in_addr **)host->h_addr_list;
        while(*pa)
        {
            printf("\t%s\n", inet_ntoa(**pa++));
        }
    }
    return EXIT_SUCCESS;
}

