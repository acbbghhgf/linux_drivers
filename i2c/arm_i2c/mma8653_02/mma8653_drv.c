#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h> //struct i2c_driver ...
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/delay.h>

//��������MMA8653������ٶ���Ϣ���ݽṹ
struct mma8653_data {
    short x; //X��ļ���ֵ
    short y; //Y��ļ���ֵ
    short z; //Z��ļ���ֵ
};

//��������ƥ��Ķ���
static struct i2c_device_id mma8653_id[] = {
    {"my8653", 0}, //"mma8653"����ƥ��
};

static struct i2c_client *g_client; //ȫ��ָ��

//clientָ��ָ��ƥ��ɹ���Ӳ���ڵ����
static void mma8653_hw_init(struct i2c_client *client)
{
    int ret = 0;

    //I2C�豸��������SMBUS�ӿں���������I2C������
    //���շ���Ӳ������ʱ��
    //SMBUS�ӿں�����ʹ�ò���:
    // 1.��SMBUS�ӿں�����˵��ʹ���ĵ�,���ں�Դ���Documentation\i2c\smbus-protocol
    // �򿪴��ļ�
    // 2.�ٴ�MMA8653��оƬ�ֲ�,�ҵ���Ӧ�Ķ�ʱ��ͼ
    // 3.���ݶ�ʱ��ͼ���ĵ�smbus-protocol���ҵ���Ӧ��ʵ�ֺ���
    // 4.�ҵ���Ӧ�ĺ����Ժ�,��sourceinsight���ҵ���������Ķ���
    //��ȡ�������Ĳ����ͷ���ֵ
    //ע��:smbus�ӿں����е�clientָ��һ��Ҫ����ƥ��ɹ���Ӳ���ڵ����ָ��
    
   //��Ƭ�ڼĴ���0x0D������
    ret = i2c_smbus_read_byte_data(client, 0x0D);
    printk("%s:addr = %#x, Read ID value is :%#x\n",
                        __func__, client->addr, ret);

    i2c_smbus_write_byte_data(client, 0x2A, 0); //ʡ��ģʽ
    i2c_smbus_write_byte_data(client, 0x0E,0); //���ò�����Χ+-2g
}

static void mma8653_read_data(struct mma8653_data *mma)
{
	unsigned char tmp_data[7];

       //�ж��µ������Ƿ�Ϸ���Ч
        while(!(i2c_smbus_read_byte_data(g_client, 0x00) & 0x08)) {
            printk("data is not ready!\n");
        }

       //�����ٶ�ֵ��ȡ
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
    struct mma8653_data mma; //�����ں˻�����

    switch(cmd) {
        case GS_MMA8653_GETXYZ_CMD:
            mma8653_config_mode(); //����MMA8653
            mma8653_read_data(&mma); //��ȡ�Ĵ����ļ��ٶ�ֵ
            copy_to_user((struct mma8653_data *)arg, &mma, sizeof(mma));
            break;
        default:
            return -1;
    }
    return 0;    
}

//�����ʼ��Ӳ�������ӿ�
static struct file_operations mma8653_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = mma8653_ioctl
};

//�����ʼ�������豸����
static struct miscdevice mma8653_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "mma8653",
    .fops = &mma8653_fops
};

//clientָ��ָ��ƥ��ɹ���Ӳ���ڵ����
static int mma8653_probe(
							struct i2c_client *client, 
							const struct i2c_device_id *id)
{
	printk("MMA8653 �豸��ַ = %d\n", client->addr);

   //ע������豸����,���û��ṩ���ʲ����ӿ�
    misc_register(&mma8653_misc);   
   //�Ѿֲ�����ȫ�ֻ�
    g_client = client;
   
   //��ʼ��mma8653Ӳ����Ϣ
    mma8653_hw_init(client);
    return 0;
}

static int mma8653_remove(struct i2c_client *client)
{
    misc_deregister(&mma8653_misc);    
    return 0;
}

//�����ʼ��I2C���������ڵ����
static struct i2c_driver mma8653_drv = {
    .driver = {
        .name = "tarena" //����Ҫ
    },
    .id_table = mma8653_id, //���е�name����ƥ��
    .probe = mma8653_probe, //ƥ��ɹ�����
    .remove = mma8653_remove //ɾ������
};

static int mma8653_init(void)
{
   //ע������ڵ㵽drv
    i2c_add_driver(&mma8653_drv);
    return 0;
}

static void mma8653_exit(void)
{
   //��drvɾ������ڵ�
    i2c_del_driver(&mma8653_drv);
}

module_init(mma8653_init);
module_exit(mma8653_exit);
MODULE_LICENSE("GPL");
