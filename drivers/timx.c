#include "timx.h"
#include "base_define.h"
#include "rcc.h"

//RCC对应时钟使能
void enr_tim(volatile struct TIM *tim_type)
{
    if (tim_type == TIM2)
    {
        SET_BIT((RCC->APB1ENR), (1 << 0)); 
    }
    if (tim_type == TIM3)
    {
        SET_BIT((RCC->APB1ENR), (1 << 1)); 
    }
    if (tim_type == TIM4)
    {
        SET_BIT((RCC->APB1ENR), (1 << 2)); 
    }
}

//静态参数初始化
void init_tim(struct INIT_CONFIG *init_config)
{
    SET_BIT((init_config->tim_type->CR1), (init_config->ali_type << 5)); //设置中央对齐模式模式
    SET_BIT((init_config->tim_type->CR1), (init_config->dir << 4));      //设置计数器计数方向
    SET_BIT((init_config->tim_type->CR1), (init_config->uids << 1));     //设置是否允许UEV事件
    SET_BIT((init_config->tim_type->CR1), (init_config->opm) << 3);      //设置是否开启单脉冲模式
    SET_BIT((init_config->tim_type->CR1), (init_config->apre << 7));     //设置自动重装载预装载
    SET_BIT((init_config->tim_type->CR1), (init_config->urs << 2));      //设置更新源
    SET_BIT((init_config->tim_type->DIER), (init_config->tde << 8));     //设置是否更新的DMA请求
    SET_BIT((init_config->tim_type->DIER), (init_config->uie << 0));     //设置是否允许更新中断
    
    //设置输出模式，设置TIMx_CCR1寄存器预装载功能
    if (init_config->channel_num == TIM_CH1 || init_config->channel_num == TIM_CH2)
    {
        CLEAN_BIT((init_config->tim_type->CCMR1), (0x7 << ((init_config->channel_num - 1) * 8 + 4)));
        SET_BIT((init_config->tim_type->CCMR1), (init_config->ocm << ((init_config->channel_num - 1) * 8 + 4)));  
        
        SET_BIT((init_config->tim_type->CCMR1), (init_config->ocpe << ((init_config->channel_num - 1) * 8 + 3))); 
    }
    if (init_config->channel_num == TIM_CH3 || init_config->channel_num == TIM_CH4)
    {
        CLEAN_BIT((init_config->tim_type->CCMR2), (0x7 << ((init_config->channel_num - 3) * 8 + 4)));
        SET_BIT((init_config->tim_type->CCMR2), (init_config->ocm << ((init_config->channel_num - 3) * 8 + 4)));  
        
        SET_BIT((init_config->tim_type->CCMR2), (init_config->ocpe << ((init_config->channel_num - 3) * 8 + 3))); 
    }
    
    //产生更新事件
    SET_BIT((init_config->tim_type->EGR), (1 << 0));                                                              
}

//动态参数初始化 
void set_tim(volatile struct TIM *tim_type,unsigned char channel_num, unsigned char psc, unsigned int arr, unsigned char ccr, unsigned char mode)
{
    tim_type->PSC = psc;
    tim_type->ARR = arr;  
    
    switch(channel_num)
    {
        case 1: tim_type->CCR1 = ccr; break;
        case 2: tim_type->CCR2 = ccr; break;
        case 3: tim_type->CCR3 = ccr; break;
        case 4: tim_type->CCR4 = ccr; break;
    }
    
    if (mode == HIGH)
    {
        CLEAN_BIT((tim_type->CCER), (1 << ((channel_num - 1) * 4 + 1)));
    }
    if (mode == LOW)
    {
        SET_BIT((tim_type->CCER), (1 << ((channel_num - 1) * 4 + 1)));
    }
    
    SET_BIT((tim_type->CCER), (1 << (channel_num - 1) * 4)); //输出使能
    SET_BIT((tim_type->CR1), (1 << 0));                      //计数器使能    
    SET_BIT((tim_type->EGR), (1 << 0));                      //产生更新事件
}