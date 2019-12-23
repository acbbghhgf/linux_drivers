#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <mach/platform.h> //PAD_GPIO_C

//声明描述LED硬件相关的数据结构
struct led_resource {
    int gpio; //GPIO软件编号
    char *name; //LED的名称
};

//定义初始化四个LED灯的硬件信息对象
static struct led_resource led_info[] = {
    {
        .name = "LED1",
        .gpio = PAD_GPIO_C+12
    },
	{
        .name = "LED2",
        .gpio = PAD_GPIO_C+7
    },
	{
        .name = "LED3",
        .gpio = PAD_GPIO_C+11
    },
	{
        .name = "LED4",
        .gpio = PAD_GPIO_B+26
    }
};

//入口：insmod
static int led_init(void)
{
    int i;
    //1.先向内核申请GPIO硬件资源
    //2.然后配置GPIO为输出功能,输出0,开灯
    for(i = 0; i < ARRAY_SIZE(led_info); i++) {
        gpio_request(led_info[i].gpio, 
                        led_info[i].name);
        gpio_direction_output(led_info[i].gpio, 0);
    }
	printk("led init...\n");
    return 0;
}

//出口:rmmod
static void led_exit(void)
{
    int i;
    //1.输出1，关灯
    //2.释放GPIO硬件资源
    for(i = 0; i < ARRAY_SIZE(led_info); i++) {
        gpio_set_value(led_info[i].gpio, 1);
        gpio_free(led_info[i].gpio);
    } 
    printk("led exit...\n");
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
