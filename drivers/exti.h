#ifndef EXTI_H
#define EXTI_H

//定义EXTI寄存器
struct EXTI_REG
{
    volatile unsigned int IMR;   //中断屏蔽寄存器
    volatile unsigned int EMR;   //事件屏蔽寄存器
    volatile unsigned int RTSR;  //上升沿触发选择寄存器
    volatile unsigned int FTSR;  //下降沿触发选择寄存器
    volatile unsigned int SWIER; //软件中断事件寄存器
    volatile unsigned int PR;    //挂起寄存器
};

//定义EXTI初地址
#define EXTI ((volatile struct EXTI_REG*) 0x40010400)

//中断解除屏蔽
void imr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num);

//事件解除屏蔽
void emr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num);

//上升沿触发选择
void rtsr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num);

//下降沿触发选择
void ftsr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num);

//挂起寄存器
void pr_exti(volatile struct EXTI_REG* exti, unsigned char exti_num);

#endif