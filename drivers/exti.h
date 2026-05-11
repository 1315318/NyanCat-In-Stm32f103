#ifndef EXTI_H
#define EXTI_H

//EXTI寄存器
struct EXTI_REG
{
    volatile unsigned int IMR;   
    volatile unsigned int EMR;   
    volatile unsigned int RTSR;  
    volatile unsigned int FTSR;  
    volatile unsigned int SWIER; 
    volatile unsigned int PR;    
};

//EXTI初地址
#define EXTI ((volatile struct EXTI_REG *) 0x40010400)

//中断解除屏蔽
void imr_exti(volatile struct EXTI_REG *exti, unsigned char exti_num);

//事件解除屏蔽
void emr_exti(volatile struct EXTI_REG *exti, unsigned char exti_num);

//上升沿触发选择
void rtsr_exti(volatile struct EXTI_REG *exti, unsigned char exti_num);

//下降沿触发选择
void ftsr_exti(volatile struct EXTI_REG *exti, unsigned char exti_num);

//挂起寄存器
void pr_exti(volatile struct EXTI_REG *exti, unsigned char exti_num);

#endif