#ifndef USART_H
#define USART_H

//定义USART寄存器
struct USART_REG
{
    volatile unsigned int SR;
    volatile unsigned int DR;
    volatile unsigned int BRR;
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int CR3;
    volatile unsigned int GTPR;
}

//定义USART初地址
#define USART1 ((volatile struct USART_REG*) 0x40013800)
#define USART2 ((volatile struct USART_REG*) 0x40004400)
#define USART3 ((volatile struct USART_REG*) 0x40004800)


#define DMAT 7 //DMA使能发送
#define DMAR 6 //DMA使能接收

#endif