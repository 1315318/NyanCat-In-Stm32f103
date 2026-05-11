#ifndef AFIO_H
#define AFIO_H

//AFIO寄存器
struct AFIO_REG
{
    volatile unsigned int EVCR;    
    volatile unsigned int MAPR;    
    volatile unsigned int EXTICR1; 
    volatile unsigned int EXTICR2; 
    volatile unsigned int EXTICR3; 
    volatile unsigned int EXTICR4; 
};

//AFIO初地址
#define AFIO ((volatile struct AFIO_REG *) 0x40010000) 

//端口选择
#define PA 0
#define PB 1
#define PC 2

//外部中断选择
#define EXTI0  0
#define EXTI1  1
#define EXTI2  2
#define EXTI3  3
#define EXTI4  4
#define EXTI5  5
#define EXTI6  6
#define EXTI7  7
#define EXTI8  8
#define EXTI9  9
#define EXTI10 10
#define EXTI11 11
#define EXTI12 12
#define EXTI13 13
#define EXTI14 14
#define EXTI15 15

//RCC对应时钟使能
void enr_afio(void);

//事件控制
void evcr_afio(volatile struct AFIO_REG *afio, unsigned char prot_type, unsigned char pin_num);

//外部中断配置
void exti_afio(volatile struct AFIO_REG *afio, unsigned char exti_num, unsigned char port_type);

#endif