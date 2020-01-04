#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <mach/platform.h>
#include <linux/gpio.h>

//声明描述LED硬件相关的数据结构


//定义初始化LED1的硬件信息对象
static struct resource led_info[] = {
    {
        .start = 0xC001C000,
        .end = 0xC001C000 + 0x24,
        .flags = IORESOURCE_MEM //地址类信息
    },
    {
        .start = 12,//GPIO编号
        .end = 12,//无效，为了好看
        .flags = IORESOURCE_IRQ
    },
    {
        .start = 7,
        .end = 7,
        .flags = IORESOURCE_IRQ
    },
    {
        .start = 11,
        .end = 11,
        .flags = IORESOURCE_IRQ
    }
};

//仅仅去除警告
static void led_release(struct device *dev) {}

//定义初始化描述LED的硬件信息节点对象
static struct platform_device led_dev = {
    .name = "tarena", //用于匹配
    .id = -1,//硬件节点编号
    .resource = led_info,//装载resource描述的硬件信息
    .num_resources = ARRAY_SIZE(led_info),//硬件信息个数
    .dev = {
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
