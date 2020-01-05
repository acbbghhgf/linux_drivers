#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h> //struct i2c_driver ...
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/delay.h>

//声明描述MMA8653三轴加速度信息数据结构
struct mma8653_data {
    short x; //X轴的加速值
    short y; //Y轴的加速值
    short z; //Z轴的加速值
};

//将来用于匹配的对象
static struct i2c_device_id mma8653_id[] = {
    {"my8653", 0}, //"mma8653"用于匹配
};

static struct i2c_client *g_client; //全局指针

//client指针指向匹配成功的硬件节点对象
static void mma8653_hw_init(struct i2c_client *client)
{
    int ret = 0;

    //I2C设备驱动调用SMBUS接口函数来操作I2C控制器
    //最终发起硬件操作时序
    //SMBUS接口函数的使用步骤:
    // 1.打开SMBUS接口函数的说明使用文档,在内核源码的Documentation\i2c\smbus-protocol
    // 打开此文件
    // 2.再打开MMA8653的芯片手册,找到对应的读时序图
    // 3.根据读时序图在文档smbus-protocol中找到对应的实现函数
    // 4.找到对应的函数以后,在sourceinsight中找到这个函数的定义
    //获取到函数的参数和返回值
    //注意:smbus接口函数中的client指针一定要传递匹配成功的硬件节点对象指针
    
   //读片内寄存器0x0D的数据
    ret = i2c_smbus_read_byte_data(client, 0x0D);
    printk("%s:addr = %#x, Read ID value is :%#x\n",
                        __func__, client->addr, ret);

    i2c_smbus_write_byte_data(client, 0x2A, 0); //省电模式
    i2c_smbus_write_byte_data(client, 0x0E,0); //设置测量范围+-2g
}

static void mma8653_read_data(struct mma8653_data *mma)
{
	unsigned char tmp_data[7];

       //判断新的数据是否合法有效
        while(!(i2c_smbus_read_byte_data(g_client, 0x00) & 0x08)) {
            printk("data is not ready!\n");
        }

       //将加速度值读取
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
    data =  i2c_smbus_read_byte_data(g_client, 0x2A);
    data |= 1;
    i2c_smbus_write_byte_data(g_client, 0x2A, data);
}

#define GS_MMA8653_GETXYZ_CMD   0x100001

static long mma8653_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    struct mma8653_data mma; //分配内核缓冲区

    switch(cmd) {
        case GS_MMA8653_GETXYZ_CMD:
            mma8653_config_mode(); //激活MMA8653
            mma8653_read_data(&mma); //读取寄存器的加速度值
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
    .name = "mma8653",
    .fops = &mma8653_fops
};

//client指针指向匹配成功的硬件节点对象
static int mma8653_probe(
							struct i2c_client *client, 
							const struct i2c_device_id *id)
{
	printk("MMA8653 设备地址 = %d\n", client->addr);

   //注册混杂设备对象,给用户提供访问操作接口
    misc_register(&mma8653_misc);   
   //把局部进行全局化
    g_client = client;
   
   //初始化mma8653硬件信息
    mma8653_hw_init(client);
    return 0;
}

static int mma8653_remove(struct i2c_client *client)
{
    misc_deregister(&mma8653_misc);    
    return 0;
}

//定义初始化I2C外设的软件节点对象
static struct i2c_driver mma8653_drv = {
    .driver = {
        .name = "tarena" //不重要
    },
    .id_table = mma8653_id, //其中的name用于匹配
    .probe = mma8653_probe, //匹配成功调用
    .remove = mma8653_remove //删除调用
};

static int mma8653_init(void)
{
   //注册软件节点到drv
    i2c_add_driver(&mma8653_drv);
    return 0;
}

static void mma8653_exit(void)
{
   //从drv删除软件节点
    i2c_del_driver(&mma8653_drv);
}

module_init(mma8653_init);
module_exit(mma8653_exit);
MODULE_LICENSE("GPL");
