#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <mach/platform.h> //PAD_GPIO_C
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define LED_ON 0x100001
#define LED_OFF 0x100002

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
//定义设备号对象
static dev_t dev;

//定义字符设备对象
static struct cdev led_cdev;

//打开设备操作接口
int led_open(struct inode *inode, struct file *file)
{
    int i;
    //1.先向内核申请GPIO硬件资源
    //2.然后配置GPIO为输出功能,输出0,开灯
    for(i = 0; i < ARRAY_SIZE(led_info); i++) {
        gpio_request(led_info[i].gpio, 
                        led_info[i].name);
        gpio_direction_output(led_info[i].gpio, 0);
    }
	printk("led open %s...\n", __func__);
    return 0;
}

//定义ioctl操作接口
static long led_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int kindex;
    copy_from_user(&kindex, (int*)arg, sizeof(kindex));

    switch(cmd){
        case LED_ON:
            gpio_set_value(led_info[kindex -1].gpio, 0);
            printk("%s: open led %d ...\n", __func__, kindex);
            break;
        case LED_OFF:
            gpio_set_value(led_info[kindex -1].gpio, 1);
            printk("%s: close led %d ...\n", __func__, kindex);
            break;
        default:
            printk("no opts ! \n");
            return -1;
    }
    return 0;
}

//关闭设备操作接口
int led_close(struct inode *inode, struct file *file)
{
    int i;
    //1.输出1，关灯
    //2.释放GPIO硬件资源
    for(i = 0; i < ARRAY_SIZE(led_info); i++) {
        gpio_set_value(led_info[i].gpio, 1);
        gpio_free(led_info[i].gpio);
    } 
    printk("led close %s...\n", __func__);
    
}

//定义初始化LED硬件操作接口
static struct file_operations led_fops ={
    .open = led_open, //oepn led cdev
    .release = led_close, //close led cdev_init
    .unlocked_ioctl = led_ioctl
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
        gpio_direction_output(led_info[i].gpio, 1);
    }
    //申请设备号
    alloc_chrdev_region(&dev, 0, 1, "myled");

    //初始化字符设备对象并且添加操作接口
    cdev_init(&led_cdev, &led_fops);

    //向内核注册字符设备对象，一旦注册成功，内核就会有一个真正的字符设备对象
    cdev_add(&led_cdev, dev, 1);

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

    //释放设备号
    unregister_chrdev_region(dev, 1);
    //卸载字符设备对象
    cdev_del(&led_cdev);

    printk("led exit...\n");
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
