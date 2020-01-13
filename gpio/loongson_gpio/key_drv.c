#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/sched.h>
#include <linux/pm.h>
#include <linux/sysctl.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <ls2k.h>

#define DEVICE_KEY_NAME "buttons"

#define LS2K_GPIO_55    55
#define LS2K_GPIO_56    56
#define LS2K_GPIO_57    57
#define LS2K_GPIO_58    58
#define LS2K_GPIO_59    59
#define LS2K_GPIO_60    60

#defineDEVICE_NAME "buttons" //设备名称

/*定义中断所用的结构体*/
struct button_irq_des{
    int irq; //按键对应的中断号

    int pin; //按键所对应的GPIO 端口

    char *pin_setting; //按键对应的引脚描述，实际并未用到，保留

    int number; //定义键值，以传递给应用层/用户态

    char *name; //每个按键的名称
};

/*结构体实体定义*/

static structbutton_irq_desc button_irqs[] =

    {

        {IRQ_EINT8, LS2K_GPIO_55, "gpio_55", 0, "KEY0"},

        {IRQ_EINT11, LS2K_GPIO_56, "gpio_56", 1, "KEY1"},

        {IRQ_EINT13, LS2K_GPIO_57, "gpio_57", 2, "KEY2"},

        {IRQ_EINT14, LS2K_GPIO_58, "gpio_58", 3, "KEY3"},

        {IRQ_EINT15, LS2K_GPIO_59, "gpio_59", 4, "KEY4"},

        {IRQ_EINT19, LS2K_GPIO_60, "gpio_60", 5, "KEY5"},

};

/*开发板上按键的状态变量，注意这里是’0’，对应的ASCII码为30*/

static volatilechar key_values[] = {'0', '0', '0', '0', '0', '0'};

/*因为本驱动是基于中断方式的，在此创建一个等待队列，以配合中断函数使用；当有按键按下并读>取到键值时，将会唤醒此队列，并设置中断标志，以便能通过read 函数判断和读取键值传递到用户>态；当没有按键按下时，系统并不*/

/*会轮询按键状态，以节省时钟资源*/

static DECLARE_WAIT_QUEUE_HEAD(button_waitq);

/*中断标识变量，配合上面的队列使用，中断服务程序会把它设置为1，read 函数会把它清零*/

static volatile int ev_press = 0;

/*本按键驱动的中断服务程序*/

static irqreturn_t buttons_interrupt(intirq, void *dev_id)

{

    struct button_irq_desc *button_irqs = (struct button_irq_desc *)dev_id;

    int down;

    //udelay(0);

    /*获取被按下的按键状态*/

    down = !gpio_get_value(button_irqs->pin);

    /*状态改变，按键被按下，从这句可以看出，当按键没有被按下的时候，寄存器的值为1(上拉)，

     但按键被按下的时候，寄存器对应的值为0*/

    if (down != (key_values[button_irqs->number] & 1))
    { // Changed

        /*如果key1 被按下，则key_value[0]就变为’1’，对应的ASCII 码为31*/

        key_values[button_irqs->number] = '0' + down;

        ev_press = 1; /*设置中断标志为1*/

        wake_up_interruptible(&button_waitq); /*唤醒等待队列*/
    }

    return IRQ_RETVAL(IRQ_HANDLED);
}

/**在应用程序执行open(“/dev/buttons”,…)时会调用到此函数，在这里，它的作用主要是注册6 个按

     键的中断。

      

     *所用的中断类型是IRQ_TYPE_EDGE_BOTH，也就是双沿触发，在上升沿和下降沿均会产生中断，这样>做

      

      **是为了更加有效地判断按键状态

      

      */

static int loongson_buttons_open(structinode *inode, struct file *file)

{

    int i;

    int err = 0;

    for (i = 0; i < sizeof(button_irqs) / sizeof(button_irqs[0]); i++)
    {
        if (button_irqs[i].irq < 0)
        {
            continue;
        }
        /*注册中断函数*/
        err = request_irq(button_irqs[i].irq, buttons_interrupt, IRQ_TYPE_EDGE_BOTH,

                          button_irqs[i].name, (void *)&button_irqs[i]);
        if (err)
            break;
    }

    if (err)
    {
        /*如果出错，释放已经注册的中断，并返回*/
        i--;
        for (; i >= 0; i--)
        {
            if (button_irqs[i].irq < 0)
            {
                continue;
            }
            disable_irq(button_irqs[i].irq);
            free_irq(button_irqs[i].irq, (void *)&button_irqs[i]);
        }

        return -EBUSY;
    }

    /*注册成功，则中断队列标记为1，表示可以通过read 读取*/

    ev_press = 1;

    /*正常返回*/

    return 0;
}

/*
   

   *此函数对应应用程序的系统调用close(fd)函数，在此，它的主要作用是当关闭设备时释放6 个按键

  的中断*处理函数

   

   */

static int loongson_buttons_close(structinode *inode, struct file *file)
{

    int i;

    for (i = 0; i < sizeof(button_irqs) / sizeof(button_irqs[0]); i++)

    {

        if (button_irqs[i].irq < 0)
        {
            continue;
        }

        /*释放中断号，并注销中断处理函数*/

        free_irq(button_irqs[i].irq, (void *)&button_irqs[i]);
    }

    return 0;
}

/*

   *对应应用程序的read(fd,…)函数，主要用来向用户空间传递键值

   */

static int loongson_buttons_read(structfile *filp, char __user *buff, size_t count, loff_t *offp)
{

    unsigned long err;

    if (!ev_press)

    {

        if (filp->f_flags & O_NONBLOCK)

            /*当中断标识为0 时，并且该设备是以非阻塞方式打开时，返回*/

            return -EAGAIN;

        else

            /*当中断标识为0 时，并且该设备是以阻塞方式打开时，进入休眠状态，等待被唤醒*/

            wait_event_interruptible(button_waitq, ev_press);
    }

    /*把中断标识清零*/

    ev_press = 0;

    /*一组键值被传递到用户空间*/

    err = copy_to_user(buff, (const void *)key_values, min(sizeof(key_values), count));

    return err ? -EFAULT : min(sizeof(key_values), count);
}

static unsigned int s3c24xx_buttons_poll(struct file *file, struct poll_table_struct *wait)

{

    unsigned intmask = 0;

    /*把调用poll 或者select 的进程挂入队列，以便被驱动程序唤醒*/

    poll_wait(file, &button_waitq, wait);

    if (ev_press)

        mask |= POLLIN | POLLRDNORM;

    return mask;
}

/*设备操作集*/

static structfile_operations dev_fops = {

    .owner = THIS_MODULE,

    .open = loongson_buttons_open,

    .release = s3c24xx_buttons_close,

    .read = s3c24xx_buttons_read,

    .poll = s3c24xx_buttons_poll,

};

static structmiscdevice misc = {

    .minor = MISC_DYNAMIC_MINOR,

    .name = DEVICE_NAME,

    .fops = &dev_fops,

};

/*设备初始化，主要是注册设备*/

static int __init dev_init(void)

{

    int ret;

    /*把按键设备注册为misc 设备，其设备号是自动分配的*/

    ret = misc_register(&misc);

    printk(DEVICE_NAME "\tinitialized\n");

    return ret;
}

/*注销设备*/

static void __exitdev_exit(void)

{

    misc_deregister(&misc);
}

module_init(dev_init); //模块初始化，仅当使用insmod/podprobe 命令加载时有用，如果设备不是通过模块方式加载，此处将不会被调用
module_exit(dev_exit); //卸载模块，当该设备通过模块方式加载后，可以通过rmmod 命令卸载，将
