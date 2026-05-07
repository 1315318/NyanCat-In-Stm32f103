#ifndef AFIO_H
#define AFIO_H

//定义AFIO寄存器
struct AFIO
{
    volatile unsigned int EVCR;    //事件控制寄存器
    volatile unsigned int MAPR;    //复用重映射和调试I/O配置寄存器
    volatile unsigned int EXTICR1; //外部中断配置寄存器1
    volatile unsigned int EXTICR2; //外部中断配置寄存器2
    volatile unsigned int EXTICR3; //外部中断配置寄存器3
    volatile unsigned int EXTICR4; //外部中断配置寄存器4
};

//定义AFIO初地址
#define AFIO ((volatile struct AFIO*) 0x40010000) 

//定义端口选择
#define PA 0
#define PB 1
#define PC 2

//定义外部中断选择
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

#endif