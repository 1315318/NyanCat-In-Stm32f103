#include "rcc.h"
#include "base_define.h"
#include "flash.h"

//系统时钟初始化
void SystemInit(void) 
{
    SET_BIT((RCC->CR), (1 << 16));              //HSE使能
    while(READ_BIT((RCC->CR), (1 << 17)) == 0); //等待HSE就绪
    SET_BIT((RCC->CFGR), (1 << 16));            //设置HSE作为PLL输入时钟
    CLEAN_BIT((RCC->CFGR), (0xF << 18));
    SET_BIT((RCC->CFGR), (7 << 18));            //设置PLL倍频系数，当前值：9倍
    SET_BIT((RCC->CR), (1 << 24 ));             //PLL使能
    while(READ_BIT((RCC->CR), (1 << 25)) == 0); //等待PLL锁定
    SET_BIT((RCC->CR), (1 << 19));              //CSS使能
    CLEAN_BIT((Flash->ACR), (7));
    SET_BIT((Flash->ACR), (2));                 //设置Flash延时
    CLEAN_BIT((RCC->CFGR), (3));
    SET_BIT((RCC->CFGR), (2));                  //切换系统时钟为PLL倍频后的HSE
    while(((RCC->CFGR >> 2) & 3) != 2);         //确认系统时钟切换状态
    CLEAN_BIT((RCC->CR), (1 << 0));             //关闭HSI
}