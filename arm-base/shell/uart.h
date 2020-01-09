/*************************************************************************
	> File Name: uart.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月07日 星期二 19时39分38秒
 ************************************************************************/

#ifndef _UART_H
#define _UART_H

//UART相关寄存器定义
#define ULCON0          (*(volatile unsigned long *)0xC00A1000)
#define UCON0           (*(volatile unsigned long *)0xC00A1004)
#define UTRSTAT0        (*(volatile unsigned long *)0xC00A1010)
#define UTXH0           (*(volatile unsigned long *)0xC00A1020)
#define URXH0           (*(volatile unsigned long *)0xC00A1024)
#define UBRDIV0         (*(volatile unsigned long *)0xC00A1028)
#define UFRACVAL0       (*(volatile unsigned long *)0xC00A102C)
#define GPIODALTFN0     (*(volatile unsigned long *)0xC001D020)
#define GPIODALTFN1     (*(volatile unsigned long *)0xC001D024)
#define UARTCLKENB      (*(volatile unsigned long *)0xC00A9000)
#define UARTCLKGENOL    (*(volatile unsigned long *)0xC00A9004)

//UART操作函数声明
extern void uart_init(void);
extern void uart_putc(char c);
extern void uart_puts(char *str);
extern char uart_getc(void);
extern void uart_gets(char buf[], int len);

#endif
