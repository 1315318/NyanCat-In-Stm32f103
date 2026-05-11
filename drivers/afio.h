#ifndef AFIO_H
#define AFIO_H

//定义AFIO寄存器
struct AFIO_REG
{
    volatile unsigned int EVCR;    //事件控制寄存器
    volatile unsigned int MAPR;    //复用重映射和调试I/O配置寄存器
    volatile unsigned int EXTICR1; //外部中断配置寄存器1
    volatile unsigned int EXTICR2; //外部中断配置寄存器2
    volatile unsigned int EXTICR3; //外部中断配置寄存器3
    volatile unsigned int EXTICR4; //外部中断配置寄存器4
};

//定义AFIO初地址
#define AFIO   ((volatile struct AFIO_REG*) 0x40010000) 

//定义端口选择
#define PA     ((unsigned char) 0)
#define PB     ((unsigned char) 1)
#define PC     ((unsigned char) 2)

//定义外部中断选择
#define EXTI0  ((unsigned char) 0)
#define EXTI1  ((unsigned char) 1)
#define EXTI2  ((unsigned char) 2)
#define EXTI3  ((unsigned char) 3)
#define EXTI4  ((unsigned char) 4)
#define EXTI5  ((unsigned char) 5)
#define EXTI6  ((unsigned char) 6)
#define EXTI7  ((unsigned char) 7)
#define EXTI8  ((unsigned char) 8)
#define EXTI9  ((unsigned char) 9)
#define EXTI10 ((unsigned char) 10)
#define EXTI11 ((unsigned char) 11)
#define EXTI12 ((unsigned char) 12)
#define EXTI13 ((unsigned char) 13)
#define EXTI14 ((unsigned char) 14)
#define EXTI15 ((unsigned char) 15)

//RCC对应时钟使能
void enr_afio(void);

//事件控制
void evcr_afio(volatile struct AFIO_REG* afio, unsigned char prot_type, unsigned char pin_num);

//外部中断配置
void exti_afio(volatile struct AFIO_REG* afio, unsigned char exti_num, unsigned char port_type);

#endif