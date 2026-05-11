#include "gpio.h"
#include "base_define.h"
#include "rcc.h"

//RCC对应时钟使能
void enr_gpio(volatile struct GPIOx *gpio_type)
{
    if (gpio_type == GPIOA)
    {
        SET_BIT((RCC->APB2ENR), (1 << 2)); 
    }
    if (gpio_type == GPIOB)
    {
        SET_BIT((RCC->APB2ENR), (1 << 3)); 
    }
    if (gpio_type == GPIOC)
    {
        SET_BIT((RCC->APB2ENR), (1 << 4)); 
    }
}

//gpio_type为引脚类型，pin_num为引脚号，范围0～15，mode为输出模式
void init_gpio(volatile struct GPIOx *gpio_type, unsigned char pin_num, unsigned char mode)
{
    if (pin_num >=0 && pin_num <= 7)
    {
        CLEAN_BIT((gpio_type->CRL), (0xF << (pin_num * 4)));
        SET_BIT((gpio_type->CRL), (mode << (pin_num * 4)));
    }
    if (pin_num >= 8 && pin_num <= 15)
    {
        CLEAN_BIT((gpio_type->CRH), (0xF << ((pin_num - 8) * 4)));
        SET_BIT((gpio_type->CRH), (mode << ((pin_num - 8) * 4)));
    }
}

//gpio_type为引脚类型，pin_num为引脚号，范围0～15
void set_gpio(volatile struct GPIOx *gpio_type, unsigned char pin_num, unsigned char level)
{
    if (level == LOW)
    {
        BSRR_CLEAN((gpio_type->BSRR), (1 << pin_num));
    }
    if (level == HIGH)
    {
        BSRR_SET((gpio_type->BSRR), (1 << pin_num));
    }  
}
