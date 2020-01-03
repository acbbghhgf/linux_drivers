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
#include <linux/mm.h>

#define LED_ON 0x100001
#define LED_OFF 0x100002

//vma:指向内核创建的一个vm_area_struct对象
//此对象来描述内核帮你找的空闲的用户虚拟内存的属性
static int led_mmap(struct file *file, struct vm_area_struct *vma)
{
    //切记：只做一件事，将物理地址映射到用户虚拟地址上。
    //映射关系：物理地址0xC001C000和vm_start做映射。
    remap_pfn_range(vma, vma->vm_start, 0xC001C000>>12, vma->vm_end - vma->vm_start, vma->vm_page_prot);
    return 0;
}


//定义初始化LED硬件操作接口
static struct file_operations led_fops ={
    .owner = THIS_MODULE,//模块的所属者
    .mmap = led_mmap
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
	
    printk("led init...\n");
    return 0;
}

//出口:rmmod
static void led_exit(void)
{
    misc_deregister(&led_misc);

    printk("led exit...\n");
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
