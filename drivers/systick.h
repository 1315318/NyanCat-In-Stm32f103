#ifndef SYSTICK_H
#define SYSTICK_H

//定义SysTick寄存器
struct SysTick
{
    volatile unsigned int CAS;  //控制及状态寄存器
    volatile unsigned int RV;   //重装载数值寄存器
    volatile unsigned int CV;   //当前数值寄存器
    volatile unsigned int CALV; //校准数值寄存器
};

//定义SysTick初地址
#define SysTick     ((volatile struct SysTick*) 0xE000E010)

//当前SysTick时钟：9MHZ（默认八分频）
#define SysTick_CLK ((unsigned char) 9) 

void systick_timing(unsigned int ticks);

#endif