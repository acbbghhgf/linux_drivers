/*************************************************************************
	> File Name: led.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月07日 星期二 07时49分08秒
 ************************************************************************/

#ifndef _LED_H
#define _LED_H

#define GPIOCOUT        (*(volatile unsigned long*)0xC001C000)
#define GPIOCOUTENB     (*(volatile unsigned long*)0xC001C004)
#define GPIOCALTFN0     (*(volatile unsigned long*)0xC001C020)

//声明操作函数
extern void led_init(void);
extern void led_on(void);
extern void led_off(void);

#endif
