#include "uart.h"

void main(void)
{
    //≥ı ºªØUART
    uart_init();

    while(1) {
        uart_puts("hello,world\n");
    }
}
