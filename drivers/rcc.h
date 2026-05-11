#ifndef RCC_H
#define RCC_H

//RCC寄存器
struct RCC
{
    volatile unsigned int CR;
    volatile unsigned int CFGR;
    volatile unsigned int CIR;
    volatile unsigned int APB2RSTR;
    volatile unsigned int APB1RSTR;
    volatile unsigned int AHBENR;
    volatile unsigned int APB2ENR;
    volatile unsigned int APB1ENR;
    volatile unsigned int BDCR;
    volatile unsigned int CSR;
};

//RCC初地址
#define RCC ((volatile struct RCC *) 0x40021000)

//系统时钟初始化
void SystemInit(void); 

#endif