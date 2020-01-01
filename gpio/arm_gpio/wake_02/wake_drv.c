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

//定义一个等待队列头对象
static wait_queue_head_t rwq;

static ssize_t wake_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    //定义初始化装载休眠进程容器，将当前进程添加到容器中。
    wait_queue_t wait;
    init_waitqueue_entry(&wait, current);

    //将当前进程添加到等待队列中
    add_wait_queue(&rwq, &wait);

    //设置当前进程休眠的状态类型为可中断
    set_current_state(TASK_INTERRUPTIBLE);

    //当前进程正式进入休眠状态
    printk("pid [%s][%d] sleep ... \n", current->comm, current->pid);
    schedule();

    //唤醒后，设置进程状态为可运行
    set_current_state(TASK_RUNNING);

    //将被唤醒的进程从队列中移除
    remove_wait_queue(&rwq, &wait);

    //判断进程被唤醒的原因
    if(signal_pending(current))
    {
        printk("pid [%s][%d] is signal wait...\n", current->comm, current->pid);
        return -ERESTARTSYS;
    }
    else{
        printk("pid [%s][%d] is wait success...\n", current->comm, current->pid);
        //将中断赋值好的kbtn返回.
        copy_to_user(buf, &kbtn, sizeof(kbtn));
    }
    return count;

}

//中断处理函数
static irqreturn_t button_isr(int irq, void *dev)
{
    //获取当前操作的按键的硬件信息
    struct btn_resource *pdata = dev;

    //将信息保存在全局变量中
    kbtn.state = gpio_get_value(pdata->gpio);
    kbtn.code = pdata->code;

    //一旦按键按下，唤醒休眠进程

    //唤醒休眠的进程
    printk("write pid [%s][%d] wait up read pid.\n", current->comm, current->pid);

    wake_up(&rwq);

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
}

module_init(wake_init);
module_exit(wake_exit);
MODULE_LICENSE("GPL");

