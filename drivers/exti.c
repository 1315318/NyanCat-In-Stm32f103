#include "exti.h"
#include "base_define.h"

//中断解除屏蔽
void imr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num)
{
    SET_BIT((exti->IMR), (1 << exti_num));
}

//事件解除屏蔽
void emr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num)
{
    SET_BIT((exti->EMR), (1 << exti_num));
}

//上升沿触发选择
void rtsr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num)
{
    SET_BIT((exti->RTSR), (1 << exti_num));
}

//下降沿触发选择
void ftsr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num)
{
    SET_BIT((exti->FTSR), (1 << exti_num));
}

//挂起寄存器
void pr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num)
{
    SET_BIT((exti->PR), (1 << exti_num));
}