/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月07日 星期二 07时37分57秒
 ************************************************************************/

#include "uart.h"
#include "strcmp.h"
#include "led.h"

static char buf[32];

void main(void)
{
    //初始化uart
    uart_init();
   // uart_puts("\n Shell#");
    //初始化led
    //led_init();

    //读取当前用户输入
    while(1)
    {
        uart_puts("\n Shell#");
        uart_gets(buf, 32);
        if(!my_strcmp(buf, "led on"))
            led_on();
        else if(!my_strcmp(buf, "led off"))
            led_off();
        else
            uart_puts("\n Your command is invalid\n");
    }
}

