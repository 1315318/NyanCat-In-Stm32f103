#include "systick.h"
#include "base_define.h"

//Systick寄存器交互，读CAS寄存器第16位判断倒计时是否结束
void systick_timing(unsigned int ticks)
{
    SysTick->CAS = 0;             //CAS寄存器所有位置零
    SysTick->RV  = 0;             //重载数值寄存器所有位置零
    SysTick->RV  = ticks;         //写入倒计时值
    SET_BIT((SysTick->CAS), (1)); //开启计时器
}
