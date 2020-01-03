/*************************************************************************
	> File Name: wake_drv.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月01日 星期三 21时34分19秒
 ************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>
#include <mach/platform.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/input.h>
#include <linux/timer.h>

//声明硬件数据结构
struct btn_resource{
    int gpio;
    char *name;
    int code;
};

//声明上报按键信息数据结构
struct btn_event{
    int state;//上报状态，1：按下，0：松开
    int code;//上报键值
};

//初始化键值信息
static struct btn_resource btn_info[] = {
    {
        .gpio = PAD_GPIO_A + 28,
        .name = "KEY_UP",
        .code = KEY_UP
    }  
};

//分配内存缓冲区，记录当前操作的键值信息
static struct btn_event kbtn;

//指示按键是否有操作，有-ispressed = 1， 无-ispressed = 0
static int ispressed;

//定义一个定时器对象
static struct timer_list btn_timer;

//定义一个等待队列头对象
static wait_queue_head_t rwq;

static ssize_t wake_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    //如果按键误操作，进程直接进入休眠状态，如果按键有操作，进程立刻返回，
    //进程休眠时 ispressed = 0，一旦唤醒 ispressed = 1
    wait_event_interruptible(rwq, ispressed);
    
    ispressed = 0;

    printk("pid [%s][%d] is wait success...\n", current->comm, current->pid);
    //将中断赋值好的kbtn返回.
    
    copy_to_user(buf, &kbtn, sizeof(kbtn));
    
    return count;
}

//记录当前按键的硬件信息
static struct btn_resource *pdata;

//中断处理函数
static void btn_timer_function(unsigned long data)
{

    //将信息保存在全局变量中
    kbtn.state = gpio_get_value(pdata->gpio);
    kbtn.code = pdata->code;

    //一旦按键按下，唤醒休眠进程
    ispressed = 1;

    //唤醒休眠的进程
    printk("write pid [%s][%d] wait up read pid.\n", current->comm, current->pid);

    wake_up(&rwq);
}

static irqreturn_t button_isr(int irq, void *dev)
{
    //获取当前操作的按键的硬件信息
    pdata = dev;

    //刷新定时器
    mod_timer(&btn_timer, jiffies + msecs_to_jiffies(10));
    return IRQ_HANDLED;
}

//定义初始化硬件操作接口对象
static struct file_operations wake_fops = {
    .owner = THIS_MODULE,
    .read = wake_read,
};

//定义初始化混杂设备对象
static struct miscdevice wake_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "mywake",
    .fops = &wake_fops
};

static int wake_init(void)
{
    int i;

    misc_register(&wake_misc);
    init_waitqueue_head(&rwq);

    //初始化gpio资源，注册中断处理函数
    for(i = 0; i < ARRAY_SIZE(btn_info); i++)
    {
        int irq = gpio_to_irq(btn_info[i].gpio);
        gpio_request(btn_info[i].gpio, btn_info[i].name);
        request_irq(irq, button_isr, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING, btn_info[i].name, &btn_info[i]);
    }

    //初始化定时器
    init_timer(&btn_timer);
    btn_timer.function = btn_timer_function;

    return 0;
}

static void wake_exit(void)
{
    int i;
    misc_deregister(&wake_misc);

    for(i = 0; i < ARRAY_SIZE(btn_info); i++)
    {
        int irq = gpio_to_irq(btn_info[i].gpio);
        gpio_free(btn_info[i].gpio);
        free_irq(irq, &btn_info[i]);
    }
    //删除定时器
    del_timer(&btn_timer);
}

module_init(wake_init);
module_exit(wake_exit);
MODULE_LICENSE("GPL");

