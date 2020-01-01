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
    }
    return count;

}

static ssize_t wake_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    //唤醒休眠的进程
    printk("write pid [%s][%d] wait up read pid.\n", current->comm, current->pid);

    wake_up(&rwq);

    return count;
}

//定义初始化硬件操作接口对象
static struct file_operations wake_fops = {
    .owner = THIS_MODULE,
    .read = wake_read,
    .write = wake_write
};

//定义初始化混杂设备对象
static struct miscdevice wake_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "mywake",
    .fops = &wake_fops
};

static int wake_init(void)
{
    misc_register(&wake_misc);
    init_waitqueue_head(&rwq);
    return 0;
}

static void wake_exit(void)
{
    misc_deregister(&wake_misc);

}

module_init(wake_init);
module_exit(wake_exit);
MODULE_LICENSE("GPL");

