#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>
#include <mach/platform.h>

#define use_gpio 0

//声明描述LED硬件信息的数据结构
struct led_resource {
    unsigned long phys_address;
    int size;
    int pin;
};

struct led_pin{
    int gpio;
    char *name;
};
#if use_gpio

static struct led_pin led_info[] ={
    {
        .name = "led1",
        .gpio = PAD_GPIO_C + 11
    },
    {
        .name = "led2",
        .gpio = PAD_GPIO_C + 12
    },
    {
        .name = "led3",
        .gpio = PAD_GPIO_C + 7
    }
};
#endif

static void *gpiobase;
static unsigned long *gpioout, *gpiooutenb, *gpioaltfn0;
static int pin1;

#define LED_ON  0x100001
#define LED_OFF 0x100002
static long led_ioctl(struct file *file,
                        unsigned int cmd,
                        unsigned long arg)
{
    //1.分配内核缓冲区
    int kindex;

    //2.拷贝用户数据到内核
    copy_from_user(&kindex, (int *)arg,  sizeof(kindex));
    //3.解析用户命令
    switch(cmd) {
        case LED_ON:
                if(kindex == 1)
                    *gpioout &= ~(1 << pin1);
                /*else ... if*/
                printk("open led on. pin1 = %d\n", pin1);
#if use_gpio
                for(i = 0; i < ARRAY_SIZE(led_info); i++)
                {
                    gpio_set_value(led_info[i].gpio, 0);
                }
#endif
            break;
        case LED_OFF:
                if(kindex == 1)
                    *gpioout |= (1 << pin1);
                /*else ... if*/
                printk("open led off. pin1 = %d\n", pin1);
#if use_gpio
                for(i = 0; i < ARRAY_SIZE(led_info); i++)
                {
                    gpio_set_value(led_info[i].gpio, 1);
                }
#endif
            break;
        default:
            return -1;
    }
    return 0;
}

//定义初始化硬件操作接口对象
static struct file_operations led_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = led_ioctl
};

//定义初始化混杂设备对象
static struct miscdevice led_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "myled",
    .fops = &led_fops
};


//匹配成功,内核调用
//pdev:指向匹配成功的硬件节点
//pdev=led_dev.c中的&led_dev
static int led_probe(struct platform_device *pdev)
{
    //1.通过pdev指针获取自定义的硬件信息
    //pdata=&led1(led_dev.c中)
    struct led_resource *pdata = pdev->dev.platform_data;

    //2.处理硬件信息
    //2.1.将硬件寄存器的物理地址映射到内核虚拟地址上
    gpiobase = ioremap(pdata->phys_address, pdata->size);
    printk("phys_address = %lx, size = %x\n", pdata->phys_address, pdata->size);
    gpioout = (unsigned long *)(gpiobase + 0x00);
    gpiooutenb = (unsigned long *)(gpiobase + 0x04);
    gpioaltfn0 = (unsigned long *)(gpiobase + 0x20);
    
    //获取GPIO编号
    pin1 = pdata->pin;

    //2.2配置为GPIO功能,配置为输出,输出1
    *gpioaltfn0 &= ~(0x3 << (2*pin1));
    *gpioaltfn0 |= (1 << (2*pin1));
    *gpiooutenb |= (1 << pin1);
    *gpioout |= (1 << pin1);

#if use_gpio
    int i;
    for(i = 0; i < ARRAY_SIZE(led_info); i++)
    {
        gpio_request(led_info[i].gpio, led_info[i].name);
        gpio_direction_output(led_info[i].gpio, 0);
    }
#endif

    //3.注册混杂设备对象
    printk("register led_misc myled.\n");
    misc_register(&led_misc);
    return 0; //执行成功返回0,执行失败返回负值
}

//删除软件或者硬件节点,内核调用
//pdev:指向匹配成功的硬件节点
//pdev=led_dev.c中的&led_dev
static int led_remove(struct platform_device *pdev)
{
    //1.卸载混杂设备
    misc_deregister(&led_misc);
    printk("unregister led_misc myled.\n");
    //2.输出1,解除地址映射
    *gpioout |= (1 << pin1);
#if use_gpio
    int i;
    for(i = 0; i < ARRAY_SIZE(led_info); i++)
    {
        gpio_set_value(led_info[i].gpio, 1);
        gpio_free(led_info[i].gpio);
    }
#endif
    iounmap(gpiobase);
    return 0; //执行成功返回0,执行失败返回负值
}

//定义初始化软件节点对象
static struct platform_driver led_drv = {
    .driver = {
        .name = "tarena" //用于匹配
    },
    .probe = led_probe, //匹配成功,内核调用
    .remove = led_remove, //卸载软件或者硬件,内核调用
};

static int led_drv_init(void)
{
    //1.向内核drv链表注册软件节点对象
    //什么遍历,什么匹配,什么调probe,什么传参都是内核完成
    platform_driver_register(&led_drv);
    return 0;
}

static void led_drv_exit(void)
{
    //1.从内核的drv链表删除软件节点对象
    //内核调用remove函数
    platform_driver_unregister(&led_drv);
}
module_init(led_drv_init);
module_exit(led_drv_exit);
MODULE_LICENSE("GPL");
