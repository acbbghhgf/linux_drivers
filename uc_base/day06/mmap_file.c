3210**********************************************************************
	> File Name: mmap_file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 08时55分08秒
 ************************************************************************/

#include<stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    void *p = mmap(NULL, 6, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED)
    {
        perror("mmap");
        return 2;
    }
    printf("mmap success...\n");
    close(fd);
    int *q = (int *)p;
    q[0] = 0x30313233;
    munmap(p, 6);
    return 0;
}

