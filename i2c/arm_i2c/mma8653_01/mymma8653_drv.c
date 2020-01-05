/*************************************************************************
	> File Name: mma8653_drv.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月05日 星期日 08时57分26秒
 ************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/delay.h>

//声明描述MMA8653三轴加速度信息数据结构
struct mma8653_data{
    short x;
    short y;
    short z;
};

//将来用于匹配的对象
static struct i2c_device_id my_mma8653_id[] = {
    {"my8653", 0},//"my8653"用于匹配
};

static struct i2c_client *g_client;//全局指针

//client 指针指向匹配成功的硬件节点
static void mma8653_hw_init(struct i2c_client *client)
{
    int ret = 0;

    //i2c设备驱动调用SMBUS接口函数来操作I2C控制器
    //最终发起硬件操作时序
    ret = i2c_smbus_read_byte_data(client, 0x0D);
    printk("%s:addr = %#xm read id value is %#x\n", __func__, client->addr, ret);

    i2c_smbus_write_byte_data(client, 0x2A, 0);//省电模式
    i2c_smbus_write_byte_data(client, 0x0E, 0);//设置测量范围 +- 2g

}

static void mma8653_read_data(struct mma8653_data *mma)
{
    unsigned char tmp_data[7];
    
    //判断数据是否合法有效
    while(!(i2c_smbus_read_byte_data(g_client, 0x00) & 0x08))
    {
        printk("data is not ready! \n");
    }

    //加速度值查询
    i2c_smbus_read_i2c_block_data(g_client, 0x01, 7, tmp_data);

    mma->x = ((tmp_data[0] << 8) & 0xff00) | tmp_data[1];
    mma->y = ((tmp_data[2] << 8) & 0xff00) | tmp_data[3];
    mma->z = ((tmp_data[4] << 8) & 0xff00) | tmp_data[5];

    mma->x = (mma->x) >> 6;
    mma->y = (mma->y) >> 6;
    mma->z = (mma->z) >> 6;

    msleep(20);
}

static void mma8653_config_mode(void)
{
    unsigned char data;
    data = i2c_smbus_read_byte_data(g_client, 0x2A);
    data |= 1;
    i2c_smbus_write_byte_data(g_client, 0x2A, data);
}

#define GS_MMA8653_GETXYZ_CMD 0x100001

static long mma8653_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    struct mma8653_data mma;
    switch(cmd)
    {
        case GS_MMA8653_GETXYZ_CMD:
            mma8653_config_mode();
            mma8653_read_data(&mma);
            copy_to_user((struct mma8653_data *)arg, &mma, sizeof(mma));
        break;
        default:
            return -1;
    }
    return 0;
}

//定义初始化硬件操作接口
static struct file_operations mma8653_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = mma8653_ioctl
};

//定义初始化混杂设备对象
static struct miscdevice mma8653_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "mymma8653",
    .fops = &mma8653_fops
};

//client 指针指向匹配成功的硬件节点对象
static int my_mma8653_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    printk(" MMA8653 addr : %d \n", client->addr);

    //注册混杂设备对象
    misc_register(&mma8653_misc);

    g_client = client;

    mma8653_hw_init(client);
    return 0;
}

static int my_mma8653_remove(struct i2c_client *client)
{
    misc_deregister(&mma8653_misc);
    return 0;
}

//定义初始化i2c外设的软件节点对象
static struct i2c_driver mma8653_drv = {
    .driver = {
        .name = "my8653_driver"
    },
    .id_table = my_mma8653_id,
    .probe = my_mma8653_probe,
    .remove = my_mma8653_remove
};

static int my_mma8653_init(void)
{
    //注册软件节点到drv
    i2c_add_driver(&mma8653_drv);
    return 0;
}

static void my_mma8653_exit(void)
{
    i2c_del_driver(&mma8653_drv);
}
module_init(my_mma8653_init);
module_init(my_mma8653_exit);
MODULE_LICENSE("GPL");
