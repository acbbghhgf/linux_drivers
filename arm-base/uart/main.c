#include "uart.h"

void main(void)
{
    //��ʼ��UART
    uart_init();

    while(1) {
        uart_puts("hello,world\n");
    }
}
