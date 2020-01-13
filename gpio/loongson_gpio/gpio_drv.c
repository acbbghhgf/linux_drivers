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

static int gpio_num = 55;
module_param(gpio_num, int, S_IRUGO);

struct ls2k_gpio_info 
{
    int		gpio;
    int		irq;
    int		irq_flags;
    char	name[6];
};

struct ls2k_gpio_info  ls2k_gpio_irq;

#define GPIO_INT_ENABLE	0x1fe10530
#define INT_POL			0x1fe11470
#define INT_EDGE		0x1fe11474

static int ls2k_gpio_info(struct ls2k_gpio_info *dev, int gpio, int flags)
{
	char offset;
	struct ls2k_gpio_info *date = dev;

	date->gpio = gpio;

	if(date->gpio < 4) {
		offset = 28 + date->gpio;
		date->irq = 68 + date->gpio;
	} else if(date->gpio < 32) {
		offset = 26;
		date->irq = 66;
	} else {
		offset = 27;
		date->irq = 67;
	}
	
	date->irq_flags = flags;
	
	sprintf(date->name, "gpio%d",date->gpio);

	printk("text %s irq:%d\n",date->name,date->irq);
	
	if(IRQF_TRIGGER_RISING & date->irq_flags) {
		ls2k_writel(ls2k_readl(INT_EDGE) | (1 << offset),  INT_EDGE);		//set edge
		ls2k_writel(ls2k_readl(INT_POL)  & ~(1 << offset), INT_POL);		//set falling
	} else if(IRQF_TRIGGER_FALLING & date->irq_flags) {
		ls2k_writel(ls2k_readl(INT_EDGE) | (1 << offset),  INT_EDGE);		//set edge
		ls2k_writel(ls2k_readl(INT_POL)  | (1 << offset),  INT_POL);		//set falling
	} else if(IRQF_TRIGGER_HIGH & date->irq_flags) {
		ls2k_writel(ls2k_readl(INT_EDGE) & ~(1 << offset), INT_EDGE);		//set edge
		ls2k_writel(ls2k_readl(INT_POL)  & ~(1 << offset), INT_POL);		//set falling
	} else if(IRQF_TRIGGER_LOW & date->irq_flags) {
		ls2k_writel(ls2k_readl(INT_EDGE) & ~(1 << offset), INT_EDGE);		//set edge
		ls2k_writel(ls2k_readl(INT_POL)  | (1 << offset),  INT_POL);		//set falling
	} else {
		return -1;
	}
	ls2k_writel(ls2k_readl(GPIO_INT_ENABLE + date->gpio/32*4) | (1 << date->gpio%32), GPIO_INT_ENABLE + date->gpio/32*4);	//int enable

	return 0;
}

static irqreturn_t gpio_handler(int irq, void *dev)
{
	int value = 0;
	struct ls2k_gpio_info *p = (struct ls2k_gpio_info *)dev;

	if((p->gpio) >=4) {
		value = gpio_get_value(p->gpio);
		if(p->irq_flags & IRQF_TRIGGER_HIGH) {
			if(!value)
				return IRQ_NONE;
		} else if(p->irq_flags & IRQF_TRIGGER_LOW) {
			if(value)
				return IRQ_NONE;
		} else {
			return IRQ_NONE;
		}
	} 
	printk("%s\n",p->name);
	return IRQ_HANDLED;
}

static int __init ls2k_gpio_irq_init(void)
{
	int error,irq_flags;
	
	if((gpio_num < 0) || (gpio_num > 63))
		return -1;

	error = gpio_request(gpio_num,"gpio_irq");
	if (error < 0) {
		printk("gpio-irq: failed to request GPIO %d,"
			" error %d\n",gpio_num, error);
		goto fail1;
	}

	error = gpio_direction_input(gpio_num);
	if (error < 0) {
		printk("gpio-irq: failed to configure input"
			" direction for GPIO %d, error %d\n",gpio_num, error);
		goto fail1;
	}
	
	if(gpio_num < 4) {
		irq_flags = IRQF_TRIGGER_FALLING;
	} else {
		irq_flags = IRQF_SHARED | IRQF_TRIGGER_LOW;
	}

	error = ls2k_gpio_info(&ls2k_gpio_irq, gpio_num, irq_flags);
	if (error < 0) {
		printk("gpio-irq: failed to ls2k_gpio_info"
			" for GPIO %d, error %d\n",gpio_num, error);
		goto fail1;
	}

	error = request_irq(ls2k_gpio_irq.irq, gpio_handler, irq_flags, ls2k_gpio_irq.name,&ls2k_gpio_irq);
	if (error) {
		printk("gpio-irq: Unable to claim irq %d; error %d\n",ls2k_gpio_irq.irq, error);
		goto fail2;
	}
	return 0;

fail2:
	free_irq(ls2k_gpio_irq.irq,&ls2k_gpio_irq);
	ls2k_writel(ls2k_readl(GPIO_INT_ENABLE + ls2k_gpio_irq.gpio/32*4) & ~(1 << ls2k_gpio_irq.gpio%32), GPIO_INT_ENABLE + ls2k_gpio_irq.gpio/32*4);	//int disable
fail1:
	gpio_free(ls2k_gpio_irq.gpio);
	return error;
}

static void __exit ls2k_gpio_irq_exit(void)
{
	free_irq(ls2k_gpio_irq.irq,&ls2k_gpio_irq);
	ls2k_writel(ls2k_readl(GPIO_INT_ENABLE + ls2k_gpio_irq.gpio/32*4) & ~(1 << ls2k_gpio_irq.gpio%32), GPIO_INT_ENABLE + ls2k_gpio_irq.gpio/32*4);	//int disable
	gpio_free(ls2k_gpio_irq.gpio);
}

module_init(ls2k_gpio_irq_init);
module_exit(ls2k_gpio_irq_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("loongson <xxx@loongson.cn>");
MODULE_DESCRIPTION("ls2k GPIO irq");
MODULE_ALIAS("LS2K");

