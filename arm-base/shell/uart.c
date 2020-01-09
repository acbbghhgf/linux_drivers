/*************************************************************************
	> File Name: uart.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月07日 星期二 19时51分24秒
 ************************************************************************/

#include "uart.h"

//初始化函数
void uart_init(void)
{
    //配置RX和TX对应的引脚分别为UARTRXD0 UARTTXD0
    //GPIOD14 -> UARTTRXD0
    //GPIODALTFN0[29:28] = 01
    GPIODALTFN0 &= ~(3 << 28);
    GPIODALTFN0 |= (3 << 28);
    
    //GPIODALTFN1 [5:4] = 01
    GPIODALTFN1 &= ~(3 << 4);
    GPIODALTFN1 |= (3 << 4);

    //配置时钟50Mhz
    //PLL[0] = 800
    //N = 800 / 50 = 16
    //n = clkdiv0 + 1 => clkdiv0 = 15
    //CLKDIV0 = UARTCLKGENOL[12:5]
    UARTCLKGENOL &= ~(0xFF << 5);
    UARTCLKGENOL |= (0xF << 5);

    // 115200 8 NOTREACHED
    ULCON0 = 3;
    UCON0 = 5;
    UBRDIV0 = 26;
    UFRACVAL0 = 2;

    //打开时钟
    UARTCLKENB |= (1 << 2);
}

void uart_putc(char c)
{
    while(!(UTRSTAT0 & 0x2));

    UTXH0 = c;

    //发送回车符
    if(c == '\n')
        uart_putc('\r');
}

void uart_puts(char *str)
{
    while(*str)
    {
        uart_putc(*str);
        str++;
    }
}

char uart_getc(void)
{
    while(!(UTRSTAT0 & 0x1));
    return (URXH0 & 0xFF);
}

void uart_gets(char buf[], int len)
{
    int i;
    for(i = 0; i < len - 1; i++)
    {
        buf[i] = uart_getc();
        uart_putc(buf[i]);
        if(buf[i] == '\r')
            break;
    }
    buf[i] = 0;
}


