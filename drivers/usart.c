#include "usart.h"

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

//配置CR3寄存器
void cr3_usart(volatile struct USART_REG* usart, unsigned char func_num)
{
    SET_BIT((usart->CR3), (1 << func_num));
}