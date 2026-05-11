#ifndef SYSTICK_H
#define SYSTICK_H

//SysTick寄存器
struct SysTick
{
    volatile unsigned int CAS;  
    volatile unsigned int RV;   
    volatile unsigned int CV;   
    volatile unsigned int CALV; 
};

//SysTick初地址
#define SysTick ((volatile struct SysTick *) 0xE000E010)

//当前SysTick时钟：9MHZ（默认八分频）
#define SysTick_CLK 9 

//Systick寄存器交互，读CAS寄存器第16位判断倒计时是否结束
void systick_timing(unsigned int ticks);

#endif