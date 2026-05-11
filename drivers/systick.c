#include "systick.h"
#include "base_define.h"

//Systick寄存器交互，读CAS寄存器第16位判断倒计时是否结束
void systick_timing(unsigned int ticks)
{
    //CAS寄存器和重载数值寄存器所有位置零
    SysTick->CAS = 0;             
    SysTick->RV  = 0;             
    
    //写入倒计时值，开启计时器
    SysTick->RV  = ticks;         
    SET_BIT((SysTick->CAS), (1)); 
}
