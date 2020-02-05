/*************************************************************************
	> File Name: diros.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 07时57分51秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    struct dirent *p;
    DIR *dirp = opendir(argv[1]);
    if(dirp == NULL)
    {
        perror("opendir");
        return -1;
    }
    printf("directory open success ...\n");
    while((p = readdir(dirp)) != NULL)
    {
        printf("%s\t%lu\n", p->d_name, p->d_ino);
    }
    closedir(dirp);
    return 0;
}

