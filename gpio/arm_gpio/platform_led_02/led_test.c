#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define LED_ON  0x100001 //开灯命令
#define LED_OFF 0x100002 //关灯命令

int main(int argc, char *argv[])
{
    int fd;
    int index; //分配用户缓冲区,保存操作灯的编号

    if(argc != 3) {
        printf("用法:%s <on|off> <1|2|3|4>\n", argv[0]);
        return -1;
    }

    //打开设备
    fd = open("/dev/myled", O_RDWR);
    printf("open file /sys/class/misc/myled/dev\n");
    //fd = open("/sys/class/misc/myled/dev", O_RDWR);
    if (fd < 0) {
        printf("open device fail!\n");
        return -1;
    }
    
    //"1"->1
    index = strtoul(argv[2], NULL, 0);

    //应用ioctl->软中断->内核sys_ioctl->驱动led_ioctl
    if(!strcmp(argv[1], "on"))
        ioctl(fd, LED_ON, &index);
    else if(!strcmp(argv[1], "off"))
        ioctl(fd, LED_OFF, &index);

    //关闭设备
    close(fd);
    return 0;
}







