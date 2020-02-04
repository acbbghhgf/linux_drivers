/*************************************************************************
	> File Name: mystat.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 09时14分24秒
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat sbuf;
    struct passwd *p;
    int s;
    s = stat(argv[1], &sbuf);
    if(s == -1)
    {
        perror("stat");
        return -1;
    }
    printf("size : %ld\n", sbuf.st_size);
    printf("hard links: %d\n", sbuf.st_nlink);
    printf("inode number : %lu\n", sbuf.st_ino);
    p = getpwuid(sbuf.st_uid);
    if(p == NULL)
    {
        printf("getpwuid error.\n");
        return 2;
    }
    printf("username : %s\n", p->pw_name);
    struct group *q = getgrgid(sbuf.st_gid);
    printf("group name : %s\n", q->gr_name);
    char *st = ctime(&sbuf.st_atime);
    printf("time : %s\n", st);
    printf("mode : %o\n", sbuf.st_mode);

#if 1
    if(S_ISREG(sbuf.st_mode))
        printf("-");
    if(S_ISDIR(sbuf.st_mode))
        printf("d");
    printf("\n");
#else
    switch(sbuf.st_mode & S_IFMT)
    {
        case S_IFREG:
            printf("-");
            break;
        case S_IFDIR:
            printf("d");
            break;
        default:
            break;
    }
    printf("\n");
#endif

    if(sbuf.st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    if(sbuf.st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");
    printf("\n");

#if 1
    switch(sbuf.st_mode & 00700)
    {
        case S_IRUSR:
            printf("r");
            break;
        case S_IWUSR:
            printf("w");
            break;
        case S_IXUSR:
            printf("x");
            break;
        default:
            break;
    }
#endif

    return 0;
}

