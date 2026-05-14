#include "adc_conversion.h"
#include "register_option.h"
#include "adc.h"
#include "timx.h"
#include "nvic.h"
#include "usart.h"
#include "serial_communication.h"
#include "gpio.h"
#include "rcc.h"
#include "delay.h"

void Hardcore_Init_All(void) 
{
    RCC->APB2ENR |= (1 << 2) | (1 << 9) | (1 << 14); 
    RCC->APB1ENR |= (1 << 0) | (1 << 1);             
    RCC->CFGR &= ~(0x3 << 14); 
    RCC->CFGR |=  (0x2 << 14); 

    // PA1(ADC_IN1):模拟输入
    // PA2(TIM2_CH3):复用推挽输出50MHz
    GPIOA->CRL &= ~((0xF << 4) | (0xF << 8)); 
    GPIOA->CRL |=  ((0x0 << 4) | (0xB << 8)); 
    GPIOA->CRH &= ~(0xF << 4);
    GPIOA->CRH |=  (0xB << 4);

    //115200波特率
    USART1->BRR = 0x271; 
    USART1->CR1 = (1 << 13) | (1 << 3) | (1 << 2); 
    
    //TIM2配置:PA2输出1kHz,50%占空比的PWM，用于提供测试信号
    TIM2->PSC = 71;
    TIM2->ARR = 999;
    TIM2->CCMR2 &= ~(0x7 << 4);
    TIM2->CCMR2 |=  (0x6 << 4);  //PWM模式1
    TIM2->CCER  |=  (1 << 8);    //开启通道3输出
    TIM2->CCR3   =  500;         //50%占空比
    TIM2->CR1   |=  (1 << 0);    //启动TIM2

    NVIC->ISER[0] |= (1 << 18); 

    ADC1->CR1 &= ~(0xF << 16);              
    ADC1->CR1 |=  (1 << 5);                 //EOCIE = 1 (开启转换结束中断)
    ADC1->CR2 &= ~((0x7 << 17) | (1 << 1)); //清除之前的触发选择和连续转换位
    ADC1->CR2 |= (0x4 << 17) | (1 << 20) | (1 << 0);
    ADC1->SQR1 = (0 << 20);                 
    ADC1->SQR3 = 1;                         
    ADC1->SMPR2 |= (0x7 << 3);              

    delay_ms(5);                 //延迟，等待 ADC 内部上电稳定
    ADC1->CR2 |= (1 << 0);       //再次 ADON 唤醒
    ADC1->CR2 |= (1 << 2);       //RSTCAL 开启
    while(ADC1->CR2 & (1 << 2)); //阻塞等待复位完成
    ADC1->CR2 |= (1 << 3);       //CAL 开启
    while(ADC1->CR2 & (1 << 3)); //阻塞等待校准完成

    
    //TIM3配置:10kHz，触发ADC
    TIM3->PSC = 71;
    TIM3->ARR = 99;
    TIM3->CR2 &= ~(0x7 << 4);
    TIM3->CR2 |=  (0x2 << 4);    
    TIM3->CR1 |=  (1 << 0);      
}

void ADC1_2_IRQHandler(void) 
{
    //检查是否是转换结束(EOC)产生的中断
    if (ADC1->SR & (1 << 1)) { 
        //读取DR寄存器会自动清除EOC标志位
        unsigned short data = ADC1->DR & 0xFFF; 

        //串口发送高8位
        while (!(USART1->SR & (1 << 7))); 
        USART1->DR = (data >> 8) & 0xFF;

        //串口发送低8位
        while (!(USART1->SR & (1 << 7))); 
        USART1->DR = data & 0xFF;
    }
}