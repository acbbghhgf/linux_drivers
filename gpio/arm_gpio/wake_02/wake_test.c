/*************************************************************************
	> File Name: wake_test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月01日 星期三 21时52分08秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct btn_event{
    int state;
    int code;
};

int main(int argc, char *argv[])
{
    int fd;
    struct btn_event btn;

    fd = open("/dev/mywake", O_RDWR);
    if(fd < 0)
    {
        perror("open device fail");
        return -1;
    }

    while(1)
    {
        read(fd, &btn, sizeof(btn));
        printf("key [%d] state = [%s]\n", btn.code, btn.state ? "off":"on");
    }

    close(fd);
    return 0;
}

