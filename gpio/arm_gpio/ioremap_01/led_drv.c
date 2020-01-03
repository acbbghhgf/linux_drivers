#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <mach/platform.h> //PAD_GPIO_C
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/io.h>

#define LED_ON 0x100001
#define LED_OFF 0x100002

//记录各个寄存器的内核虚拟地址
static void *gpio_base;
static unsigned long *gpiocout;//数据寄存器内核虚拟地址
static unsigned long *gpiocutenb;//输出圣能寄存器内核虚拟地址
static unsigned long *gpiocaltfn0;//复用功能选择寄存器内核虚拟地址


//定义ioctl操作接口
static long led_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    //分配内核缓冲区
    int kindex;
    copy_from_user(&kindex, (int*)arg, sizeof(kindex));

    switch(cmd){
        case LED_ON:
            *gpiocout &= ~(1 << 12);
            printk("%s: open led %d ...\n", __func__, kindex);
            break;
        case LED_OFF:
            *gpiocout |= (1 << 12);
            printk("%s: close led %d ...\n", __func__, kindex);
            break;
        default:
            printk("no opts ! \n");
            return -1;
    }

    //添加硬件打印信息
    printk("GPIOCALTFN0=%#x, GPIOCOUTENB=%#x, GPIOCOUT=%#x\n", *gpiocaltfn0, *gpiocutenb, *gpiocout);

    return 0;
}


//定义初始化LED硬件操作接口
static struct file_operations led_fops ={
    .owner = THIS_MODULE,//模块的所属者
    .unlocked_ioctl = led_ioctl
};

//定义初始化混杂设备对象
static struct miscdevice led_misc={
    //内核分配次设备号
    .minor = MISC_DYNAMIC_MINOR,
    .name = "myled",//内核帮助创建设备文件/dev/myled
    .fops = &led_fops //给混杂设备对象添加硬件操作接口
};

//入口：insmod
static int led_init(void)
{
    //向内核注册混杂设备对象
    misc_register(&led_misc);
	
    //映射各个物理寄存器地址
    gpio_base = ioremap(0xC001C000, 0x24);
    gpiocout = (unsigned long *)(gpio_base + 0x00);
    gpiocutenb = (unsigned long *)(gpio_base + 0x04);
    gpiocaltfn0 = (unsigned long *)(gpio_base + 0x20);

    //配置为GPIO功能、输出、输出为1.
    *gpiocaltfn0 &= ~(0x3 << 24);
    *gpiocaltfn0 |= (1<<24);
    *gpiocutenb |= (1<<12);
    *gpiocout |= (1 << 12);

    printk("led init...\n");
    return 0;
}

//出口:rmmod
static void led_exit(void)
{
    *gpiocout |= (1<<12);
    iounmap(gpio_base);

    misc_deregister(&led_misc);

    printk("led exit...\n");
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
