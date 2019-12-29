/*************************************************************************
	> File Name: btn_drv.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 09时08分30秒
 ************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <mach/platform.h>
#include <linux/input.h>

struct btn_resource{
    int gpio; //按键对应的GPIO
    char *name;//gpio Name
    int code;//按键值
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

//中断处理函数
//不同的按键触发irq不同，KEY_UP对应irq = gpio_to_irq(GPIOA28)
//响应的参数不同，dev = &btn_info[0]或者dev = &btn_info[1]
static irqreturn_t button_isr(int irq, void *dev)
{
    int state;
    //获取当前硬件信息
    struct btn_resource *pdata = (struct btn_resource *)dev;

    //获取当前对应的GPIO状态
    state = gpio_get_value(pdata->gpio);

    //打印显示
    printk("%s : key value [ %d  ],key state: [ %s ]\n", __func__, pdata->code, state ? "off" : "on");

    return IRQ_HANDLED;//返回执行成功
}

static int btn_init(void)
{
    int i;

    for(i = 0; i < ARRAY_SIZE(btn_info); i++)
    {
        int irq = gpio_to_irq(btn_info[i].gpio);
        gpio_request(btn_info[i].gpio, btn_info[i].name);
        //IRQF_TRIGGER_FALLING
        //IRQF_TRIGGER_RISING
        request_irq(irq, button_isr, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING, btn_info[i].name, &btn_info[i]);
    }

    return 0;
}

static void btn_exit(void)
{
    int i;

    for(i =0; i < ARRAY_SIZE(btn_info); i++)
    {
        int irq = gpio_to_irq(btn_info[i].gpio);
        gpio_free(btn_info[i].gpio);
        free_irq(irq, &btn_info[i]);
    }
}

module_init(btn_init);
module_exit(btn_exit);
MODULE_LICENSE("GPL");

