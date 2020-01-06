#include "uart.h"

//UART初始化函数
void uart_init(void)
{
    //0.禁止UART时钟
    //UARTCLKENB[2]=0
    UARTCLKENB &= ~(1 << 2);

    //1.配置UART0使用的两个管脚的功能
    //UARTRXD0
    //GPIOD_ALTFN0[29:28]=00
    GPIOD_ALTFN0 &= ~(0x3 << 28);
    //GPIOD_ALTFN0[29:28]=01
    GPIOD_ALTFN0 |= (1 << 28);
    
    //为UARTTXD0
    //GPIOD_ALTFN1[5:4]=00
    GPIOD_ALTFN1 &= ~(0x3 << 4);
    //GPIOD_ALTFN1[5:4]=01
    GPIOD_ALTFN1 |= (1 << 4);

    //2.配置UART的工作时钟为50MHz
    //PLL1(800MHz)/(0xF + 1) = 50MHz
    //UARTCLKGEN0L[4:2]=000
    //UARTCLKGEN0L[12:5]=00000000
    UARTCLKGEN0L &= ~((7 << 2) | (0xFF << 5));
    //UARTCLKGEN0L[4:2]=001
    //UARTCLKGEN0L[12:5]=00001111
    UARTCLKGEN0L |= ((1 << 2) | (0xF << 5));
    
    //3.配置UART的工作参数
    //波特率115200:根据公式进行配置即可
    //数据位8,奇偶校验:None,停止位1
    ULCON0 = 3;//115200,8,N,1
    UCON0 = 5; //轮循方式
    UBRDIV0=26;//50000000/115200*16-1取整   
    UFRACDIV0=2;//(26.12-26)*16=2.02取整
    //4.打开UART时钟,即可使用UART
    //UARTCLKENB[2]=1
    UARTCLKENB |= (1 << 2);
}

//发送字符函数
void uart_putc(char c)
{
    //1.由于CPU的处理速度远远快与UART
    //控制器发送数据的速度,发送之前先
    //判断发送缓冲区是否为空
    //UTRSTAT0[1]=0:有数
    //UTRSTAT0[1]=1：空
    while(!(UTRSTAT0 & 0x2));

    //2.正式发送数据
    UTXH0 = c; //将数据塞到发送缓冲区
    
    //3.判断是否需要发回车字符
    if (c == '\n')
        uart_putc('\r');
}

//发送字符串函数
//"hello,world"
void uart_puts(char *str)
{
    while(*str) {
        uart_putc(*str);
        str++;
    }
}








