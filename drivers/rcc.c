#include "rcc.h"
#include "base_define.h"
#include "flash.h"

//系统时钟初始化
void SystemInit(void) 
{
    //设置HSE作为PLL输入时钟
    SET_BIT((RCC->CR), (1 << 16));              
    while(READ_BIT((RCC->CR), (1 << 17)) == 0); 
    SET_BIT((RCC->CFGR), (1 << 16));            
    
    //设置PLL倍频系数，当前值：9倍
    CLEAN_BIT((RCC->CFGR), (0xF << 18));
    SET_BIT((RCC->CFGR), (7 << 18));            
    
    //PLL和CSS使能
    SET_BIT((RCC->CR), (1 << 24 ));             
    while(READ_BIT((RCC->CR), (1 << 25)) == 0); 
    SET_BIT((RCC->CR), (1 << 19));              
    
    //设置Flash延时
    CLEAN_BIT((Flash->ACR), (7));
    SET_BIT((Flash->ACR), (2));                 
    
    //切换系统时钟为PLL倍频后的HSE
    CLEAN_BIT((RCC->CFGR), (3));
    SET_BIT((RCC->CFGR), (2));                  
    
    //确认系统时钟切换状态，关闭HSI
    while(((RCC->CFGR >> 2) & 3) != 2);         
    CLEAN_BIT((RCC->CR), (1 << 0));             
}