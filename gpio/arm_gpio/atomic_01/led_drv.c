#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <mach/platform.h> //PAD_GPIO_C
#include <linux/miscdevice.h>
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


//定义初始化原子量作为设备状态
static atomic_t open_cnt = ATOMIC_INIT(1);


//打开设备操作接口
int led_open(struct inode *inode, struct file *file)
{
    int i;


    //临界区
    if(!atomic_dec_and_test(&open_cnt))
    {
        printk("device was opened!!!\n");
        
        atomic_inc(&open_cnt);
        
        return -EBUSY;//返回设备忙错误码
    }
    
    printk("device open success.\n");
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

    atomic_inc(&open_cnt);
    
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
    .owner = THIS_MODULE,
    .open = led_open, //oepn led cdev
    .release = led_close, //close led cdev_init
    .unlocked_ioctl = led_ioctl
};

//定义初始化混杂设备对象
static struct miscdevice led_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "myled",
    .fops = &led_fops
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

    //注册混杂设备对象
    misc_register(&led_misc);

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
    
    //卸载混杂设备对象
    misc_deregister(&led_misc);

    printk("led exit...\n");
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
