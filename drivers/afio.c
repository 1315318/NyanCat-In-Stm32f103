#include "afio.h"
#include "base_define.h"
#include "rcc.h"
#include "gpio.h"

//RCC对应时钟使能
void enr_afio(void)
{
    SET_BIT((RCC->APB2ENR), (1 << 0));
}

//事件控制
void evcr_afio(volatile struct AFIO_REG* afio, unsigned char prot_type, unsigned char pin_num)
{
    CLEAN_BIT((afio->EVCR), (7 << 4));
    SET_BIT((afio->EVCR), (prot_type << 4)); //端口选择
    CLEAN_BIT((afio->EVCR), (0xF << 0));
    SET_BIT((afio->EVCR), (pin_num << 0));   //引脚选择
    SET_BIT((afio->EVCR), (1 << 7));         //允许事件输出
}

//外部中断配置
void exti_afio(volatile struct AFIO_REG* afio, unsigned char exti_num, unsigned char port_type)
{
    if (exti_num >= 0 && exti_num <= 3)
    {
        CLEAN_BIT((afio->EXTICR1), (0xF << (exti_num % 4) * 4));
        SET_BIT((afio->EXTICR1), (port_type << (exti_num % 4) * 4));
    }
    if (exti_num >= 4 && exti_num <= 7)
    {
        CLEAN_BIT((afio->EXTICR2), (0xF << (exti_num % 4) * 4));
        SET_BIT((afio->EXTICR2), (port_type << (exti_num % 4) * 4));
    }
    if (exti_num >= 8 && exti_num <= 11)
    {
        CLEAN_BIT((afio->EXTICR3), (0xF << (exti_num % 4) * 4));
        SET_BIT((afio->EXTICR3), (port_type << (exti_num % 4) * 4));
    }
    if (exti_num >= 12 && exti_num <= 15)
    {
        CLEAN_BIT((afio->EXTICR4), (0xF << (exti_num % 4) * 4));
        SET_BIT((afio->EXTICR4), (port_type << (exti_num % 4) * 4));
    }
}