#include "delay.h"
#include "base_define.h"
#include "systick.h"

//微秒延时
void delay_us(unsigned int delay_time)
{
    systick_timing(delay_time * SysTick_CLK);
    while(READ_BIT((SysTick->CAS), (1 << 16)) == 0);
}

//毫秒延时
void delay_ms(unsigned int delay_time)
{
    while(delay_time--)
    {
        systick_timing(1000 * SysTick_CLK);
        while(READ_BIT((SysTick->CAS), (1 << 16)) == 0);
    }
}
