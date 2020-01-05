#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define GS_MMA8653_GETXYZ_CMD   0x100001

struct mma8653_data {
    short x;
    short y;
    short z;
};

int main(void)
{
    int fd;
    struct mma8653_data info; //分配用户缓冲区

    fd = open("/dev/mma8653", O_RDWR);
    if (fd < 0)
        return -1;

    while(1) {
        ioctl(fd, GS_MMA8653_GETXYZ_CMD, &info);
        printf("%d    %d    %d\n", info.x, info.y, info.z);
        //usleep(50000);
    }
    
    close(fd);
    return 0;
}
