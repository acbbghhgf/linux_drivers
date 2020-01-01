/*************************************************************************
	> File Name: btn_drv.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 09时08分30秒
 ************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/timer.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/input.h>

struct btn_resource{
    int gpio; //按键对应的GPIO
    char *name;//gpio Name
    int code;//按键值
};

struct led_resource{
    int gpio;
    char *name;
};

//定义吃时候按键对应的硬件信息
static struct btn_resource btn_info[] = {
    {
        .gpio = PAD_GPIO_A + 28,
        .name = "KEY_UP",
        .code = KEY_UP
    },
    {
        .gpio = PAD_GPIO_B + 9,
        .name = "KEY_DOWN",
        .code = KEY_DOWN
    }
};

static struct led_resource led_info[] ={
    {
        .gpio = PAD_GPIO_C + 12,
        .name = "LED1"
    },
    {
        .gpio = PAD_GPIO_C + 7,
        .name = "LED2"
    },
    {
        .gpio = PAD_GPIO_C + 11,
        .name = "LED3"
    },
    {
        .gpio = PAD_GPIO_B + 26,
        .name = "LED4"
    }
};

//记录按键的硬件信息
static struct btn_resource *pdata;

//定义定时器对象
static struct timer_list mytimer;

//定义定时器时间
static int mytimer_value = 5;
static int led_cmd_flag = 0;

//定义初始化自旋锁
static spinlock_t mylock;

//tasklet process mytimer_function led opts

static void timer_tasklet_function(unsigned long data)
{
    //open led or close led
    int i = 0;
    int *p_data = data;
    printk("%s : current timer value = %d, state = %d\n", __func__, mytimer_value, *p_data);
    if(*p_data)
    {
        *p_data = 0;
        for(i = 0; i < ARRAY_SIZE(led_info); i++)
        {
            gpio_set_value(led_info[i].gpio, 0);
        }
    }
    else
    {
        *p_data = 1;
        for(i = 0; i < ARRAY_SIZE(led_info); i++)
        {
            gpio_set_value(led_info[i].gpio, 1);
        }
    }
    printk("tasklet process : %s \n", __func__);

}

//定义初始化一个tasklet对象
static DECLARE_TASKLET(mytimer_tasklet, timer_tasklet_function, (unsigned long)&led_cmd_flag);

//定时器处理函数
//data = (unsigned long)&g_data
static void mytimer_function(unsigned long data)
{
    //登记底半部tasklet处理函数
    tasklet_schedule(&mytimer_tasklet);

    //add_timer(&mytimer);
    mod_timer(&mytimer, jiffies + mytimer_value * HZ);
    printk("schedule timer top process : %s \n", __func__);
}

//工作队列方式处理定时器延长或缩短
//work = &btn_work
static void btn_work_function(struct work_struct *work)
{
    switch(pdata->code)
    {
        case KEY_UP:
            //add expir timeout
            spin_lock(&mylock);
            if(mytimer_value < 10)
                mytimer_value++;
            spin_unlock(&mylock);
            break;
        case KEY_DOWN:
            //submit expir timeout
            spin_lock(&mylock);
            if(mytimer_value > 0)
                mytimer_value--;
            spin_unlock(&mylock);
            break;
        default:
            printk("dev->code is not impire.\n");
    }
    printk("btn work function : %s \n", __func__);

}

//定义工作队列
static struct work_struct btn_work;

//中断处理函数
//不同的按键触发irq不同，KEY_UP对应irq = gpio_to_irq(GPIOA28)
//响应的参数不同，dev = &btn_info[0]或者dev = &btn_info[1]
static irqreturn_t button_isr(int irq, void *dev)
{
    //获取当前硬件信息
    pdata = (struct btn_resource *)dev;

    //登记工作队列
    schedule_work(&btn_work);
    
    //验证顶半部先执行
    printk("top func : %s mytimer_value = %d\n", __func__, mytimer_value);

    return IRQ_HANDLED;//返回执行成功
}

static int mytimer_init(void)
{
    int i;

    //初始化自旋锁
    spin_lock_init(&mylock);

    //吃时候定时器对象
    init_timer(&mytimer);
    //指定定时器超时时间
    mytimer.expires = jiffies + 5 * HZ;
    mytimer.function = mytimer_function;

    //指定参数
    mytimer.data = (unsigned long)&led_cmd_flag;
    add_timer(&mytimer);

    for(i = 0; i < ARRAY_SIZE(btn_info); i++)
    {
        int irq = gpio_to_irq(btn_info[i].gpio);
        gpio_request(btn_info[i].gpio, btn_info[i].name);
        //IRQF_TRIGGER_FALLING
        //IRQF_TRIGGER_RISING
        request_irq(irq, button_isr, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING, btn_info[i].name, &btn_info[i]);
    }

    for(i = 0; i < ARRAY_SIZE(led_info); i++)
    {
        gpio_request(led_info[i].gpio, led_info[i].name);
        gpio_direction_output(led_info[i].gpio, 0);
    }

    printk("led btn timer init...\n");

    //初始化工作队列
    INIT_WORK(&btn_work, btn_work_function);

    return 0;
}

static void mytimer_exit(void)
{
    int i;
    del_timer(&mytimer);

    for(i =0; i < ARRAY_SIZE(btn_info); i++)
    {
        int irq = gpio_to_irq(btn_info[i].gpio);
        gpio_free(btn_info[i].gpio);
        free_irq(irq, &btn_info[i]);
    }
    for(i = 0; i < ARRAY_SIZE(led_info); i++)
    {
        gpio_set_value(led_info[i].gpio, 1);
        gpio_free(led_info[i].gpio);
    }

    printk("led btn timer exit...\n");
}

module_init(mytimer_init);
module_exit(mytimer_exit);
MODULE_LICENSE("GPL");

