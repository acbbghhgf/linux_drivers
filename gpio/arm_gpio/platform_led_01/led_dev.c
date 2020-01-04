#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

//声明描述LED硬件相关的数据结构
struct led_resource {
    unsigned long phys_address; //寄存器的起始物理地址
    int size; //寄存器存储空间的大小
    int pin; //引脚编号
};

//定义初始化LED1的硬件信息对象
static struct led_resource led1 = {
    .phys_address = 0xC001C000,
    .size = 0x24,
    .pin = 7
};

//仅仅去除警告
static void led_release(struct device *dev) {}

//定义初始化描述LED的硬件信息节点对象
static struct platform_device led_dev = {
    .name = "tarena", //用于匹配
    .id = -1,//硬件节点编号
    .dev = {
        .platform_data = &led1,//装载自定义的硬件信息 
        .release = led_release //仅仅是为了去除警告而已
    }
};

static int led_dev_init(void)
{
    //1.向内核dev链表添加注册硬件节点对象即可
    //内核会帮你遍历drv链表,匹配,调用,传参
    platform_device_register(&led_dev);
    printk("register device led_dev.\n");
    return 0;
}

static void led_dev_exit(void)
{
    //从内核的dev链表删除硬件节点对象
    platform_device_unregister(&led_dev);
    printk("unregister device led_dev.\n");
}
module_init(led_dev_init);
module_exit(led_dev_exit);
MODULE_LICENSE("GPL");
