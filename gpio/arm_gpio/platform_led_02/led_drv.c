#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/mm.h>
#include <linux/slab.h>


static void *gpiobase;
static unsigned long *gpiocout, *gpiocoutenb, *gpioaltfn0;
static int pin1;
static int pin2;
static int pin3;

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
                    *gpiocout &= ~(1 << pin1);
                if(kindex == 2)
                    *gpiocout &= ~(1 << pin2);
                if(kindex == 3)
                    *gpiocout &= ~(1 << pin3);
                printk("open led on. kindex = %d\n", kindex);
            break;
        case LED_OFF:
                if(kindex == 1)
                    *gpiocout |= (1 << pin1);
                if(kindex == 2)
                    *gpiocout |= (1 << pin2);
                if(kindex == 3)
                    *gpiocout |= (1 << pin3);
                printk("open led off. kindex = %d\n", kindex);
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

    //通过指针得到resource描述的硬件信息
    //preg_res = &led_info[0]
    //ppin_res = &led_info[1]
    struct resource *preg_res;
    struct resource *ppin_res_1;
    struct resource *ppin_res_2;
    struct resource *ppin_res_3;

    preg_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    ppin_res_1 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
    ppin_res_2 = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
    ppin_res_3 = platform_get_resource(pdev, IORESOURCE_IRQ, 2);

    //处理硬件信息
    gpiobase = ioremap(preg_res->start, preg_res->end - preg_res->start);
    gpiocout = (unsigned long *)(gpiobase + 0x00);
    gpiocoutenb = (unsigned long *)(gpiobase + 0x04);
    gpioaltfn0 = (unsigned long *)(gpiobase + 0x20);

    //获取GPIO编号
    pin1 = ppin_res_1->start;
    pin2 = ppin_res_2->start;
    pin3 = ppin_res_3->start;

    //配置GPIO功能为输出并输出1
    //led1
    *gpioaltfn0 &= ~(0x3 << (2 *pin1));
    *gpioaltfn0 |= (1 << (2*pin1));
    *gpiocoutenb |= (1 <<pin1);
    *gpiocout |= (1 << pin1);

    //led2
    *gpioaltfn0 &= ~(0x3 << (2 *pin2));
    *gpioaltfn0 |= (1 << (2*pin2));
    *gpiocoutenb |= (1 <<pin2);
    *gpiocout |= (1 << pin2);
    
    //led3
    *gpioaltfn0 &= ~(0x3 << (2 *pin3));
    *gpioaltfn0 |= (1 << (2*pin3));
    *gpiocoutenb |= (1 <<pin3);
    *gpiocout |= (1 << pin3);

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
    
    *gpiocout |= (1<<pin1);
    *gpiocout |= (1<<pin2);
    *gpiocout |= (1<<pin3);

    //解除地址映射
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
