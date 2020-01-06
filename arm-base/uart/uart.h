#ifndef __UART_H
#define __UART_H

/*定义相关的寄存器信息*/
#define ULCON0  (*(volatile unsigned long *)0xC00A1000)
#define UCON0 (*(volatile unsigned long *)0xC00A1004)
#define UTRSTAT0 (*(volatile unsigned long *)0xC00A1010)
#define UTXH0 (*(volatile unsigned long *)0xC00A1020)
#define URXH0 (*(volatile unsigned long *)0xC00A1024)
#define UBRDIV0 (*(volatile unsigned long *)0xC00A1028)
#define UFRACDIV0 (*(volatile unsigned long *)0xC00A102C)

#define GPIOD_ALTFN0 (*(volatile unsigned long *)0xC001D020)
#define GPIOD_ALTFN1 (*(volatile unsigned long *)0xC001D024)

/*UART时钟配置相关寄存器*/
#define UARTCLKENB (*(volatile unsigned long *)0xC000A900)
#define UARTCLKGEN0L (*(volatile unsigned long *)0xC000A904)

/*声明相关函数*/
//初始化UART函数
extern void uart_init(void);
//发送单个字节数据
extern void uart_putc(char c);
//发送字符串函数
extern void uart_puts(char *str); 
#endif





