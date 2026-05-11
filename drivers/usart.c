#include "usart.h"
#include "base_define.h"
#include "rcc.h"

//RCC对应时钟使能
void enr_usart(volatile struct USART_REG* usart)
{
    if (usart == USART1)
    {
        SET_BIT((RCC->APB2ENR), (1 << 14));
    }
    if (usart == USART2)
    {
        SET_BIT((RCC->APB1ENR), (1 << 17));
    }
    if (usart == USART3)
    {
        SET_BIT((RCC->APB1ENR), (1 << 18));
    }
}

//数据寄存器
void dr_usart(volatile struct USART_REG* usart, unsigned char data)
{
    CLEAN_BIT((usart->DR), (0xFF << 0));
    SET_BIT((usart->DR), (0xFF << 0));
}

//设置波特率，mant为USART分频器除法因子(USARTDIV)的整数部分，farc为USART分频器除法因子(USARTDIV)的小数部分
void brr_usart(volatile struct USART_REG* usart, unsigned int mant, unsigned char frac)
{
    CLEAN_BIT((usart->BRR), (0xF << 0));
    SET_BIT((usart->BRR), ((frac & 0xF) << 0));
    CLEAN_BIT((usart->BRR), (0xFFF << 4));
    SET_BIT((usart->BRR), ((mant & 0xFFF) << 4));
}

//配置CR1寄存器
void cr1_usart(volatile struct USART_REG* usart, unsigned char option_type, unsigned char func_num)
{
    if (option_type == ON)
    {
        SET_BIT((usart->CR1), (1 << func_num));
    }   
    if (option_type == OFF)
    {
        CLEAN_BIT((usart->CR1), (1 << func_num)); 
    }
}

//配置CR2寄存器
void cr2_usart(volatile struct USART_REG* usart, unsigned char func_num, unsigned char func_location)
{
    if (func_num == 0)
    {
        if (func_location == 0)
        {
            CLEAN_BIT((usart->CR2), (0xF << func_location));    
        }
        if (func_location == 12)
        {
            CLEAN_BIT((usart->CR2), (3 << func_location));
        }
        else
        {
            CLEAN_BIT((usart->CR2), (1 << func_location));
        }
    }
    else 
    {
        SET_BIT((usart->CR2), (func_num << func_location));
    }
}

//配置CR3寄存器
void cr3_usart(volatile struct USART_REG* usart, unsigned char func_num)
{
    SET_BIT((usart->CR3), (1 << func_num));
}