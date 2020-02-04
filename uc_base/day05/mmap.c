/*************************************************************************
	> File Name: mmap.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 08时35分29秒
 ************************************************************************/

#include<stdio.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
    void *p = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if(p == MAP_FAILED)
    {
        perror("mmap");
        return -1;
    }
    printf("mapping success ...\n");
    strcpy(p, "tarena");
    printf("%s \n", (char *)p);
    munmap(p, 1024);
    return 0;
}

