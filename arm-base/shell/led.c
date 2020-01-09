/*************************************************************************
	> File Name: led.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月07日 星期二 07时51分53秒
 ************************************************************************/

#include "led.h"

//初始化函数定义
void led_init(void)
{
    //配置引脚功能为GPIO功能
    GPIOCALTFN0 &= ~(3 << 24);
    GPIOCALTFN0 |= (1 << 24);
    //配置引脚为输出功能
    GPIOCOUTENB |= (1<<12);

    GPIOCALTFN0 &= ~(3 << 14);
    GPIOCALTFN0 |= (1 <<14);

    GPIOCOUTENB |= (1 << 7);
}

//开灯函数定义
void led_on(void)
{
    //配置输出0
    GPIOCOUT &= ~(1<<12);
    GPIOCOUT &= ~(1<<7);
}
//关灯函数定义
void led_off(void)
{
    //配置输出1
    GPIOCOUT |= (1 << 12);
    GPIOCOUT |= ~(1<<7);
}

