#ifndef USART_H
#define USART_H

//USART寄存器
struct USART_REG
{
    volatile unsigned int SR;
    volatile unsigned int DR;
    volatile unsigned int BRR;
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int CR3;
    volatile unsigned int GTPR;
};

//USART初地址
#define USART1 ((volatile struct USART_REG *) 0x40013800)
#define USART2 ((volatile struct USART_REG *) 0x40004400)
#define USART3 ((volatile struct USART_REG *) 0x40004800)

//操作类型
#define OFF 0
#define ON  1

//功能位位置
#define RE     2  //接收使能
#define RXNEIE 5  //接收缓冲区非空中断使能
#define WL     12 //字长
#define UE     13 //USART使能

//停止位 
#define STBITS_ONE  0
#define STBITS_HAF  1
#define STBITS_TWO  2
#define STBITS_QUAR 3

//停止位位置
#define STBITS 12 

//DMA接收发送
#define DMAT 7 //DMA使能发送
#define DMAR 6 //DMA使能接收

//RCC对应时钟使能
void enr_usart(volatile struct USART_REG *usart);

//数据寄存器
void dr_usart(volatile struct USART_REG *usart, unsigned char data);

//设置波特率，mant为USART分频器除法因子(USARTDIV)的整数部分，farc为USART分频器除法因子(USARTDIV)的小数部分
void brr_usart(volatile struct USART_REG *usart, unsigned int mant, unsigned char frac);

//配置CR1寄存器
void cr1_usart(volatile struct USART_REG *usart, unsigned char option_type, unsigned char func_num);

//配置CR2寄存器
void cr2_usart(volatile struct USART_REG *usart, unsigned char func_num, unsigned char func_location);

//配置CR3寄存器
void cr3_usart(volatile struct USART_REG *usart, unsigned char func_num);

#endif