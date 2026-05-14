#ifndef ADC_H
#define ADC_H

//ADC寄存器
struct ADC_REG
{
    volatile unsigned int SR;
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int SMPR1;
    volatile unsigned int SMPR2;
    volatile unsigned int JOFR1;
    volatile unsigned int JOFR2;
    volatile unsigned int JOFR3;
    volatile unsigned int JOFR4;
    volatile unsigned int HTR;
    volatile unsigned int LTR;
    volatile unsigned int SQR1;
    volatile unsigned int SQR2;
    volatile unsigned int SQR3;
    volatile unsigned int JSQR;
    volatile unsigned int JDR1;
    volatile unsigned int JDR2;
    volatile unsigned int JDR3;
    volatile unsigned int JDR4;
    volatile unsigned int DR;
};

//ADC初地址
#define ADC1 ((volatile struct ADC_REG *) 0x40012400)
#define ADC2 ((volatile struct ADC_REG *) 0x40012800)
#define ADC3 ((volatile struct ADC_REG *) 0x40013C00)

//RCC对应时钟使能
#define ADC_RCC(rcc) reg_write(&(rcc->APB2ENR), (1 << 9), (1 << 9))

//转换结束后产生中断
#define EOCIE(adc) reg_write(&(adc->CR1), (1 << 5), (1 << 5))

//开启ADC
#define ADC_ON(adc) reg_write(&(adc->CR2), (1 << 0), (1 << 0))

//外部触发转换
#define EXTTRIG(adc) reg_write(&(adc->CR2), (1 << 20), (1 << 20))

//定时器3TRGO事件
#define TIM3_TRGO(adc) reg_write(&(adc->CR2), (7 << 17), (4 << 17))

//设置通道1为第一个中断
#define CONV1(adc) reg_write(&(adc->SQR3), (0x1F << 0), (1 << 0))

//设置通道1采样时间，确保信号稳定(55.5周期)
#define SET_SMP1(adc) reg_write(&(adc->SMPR2), (7 << 3), (5 << 3))

//设置通道1为转换序列第一位
#define CONV1(adc) reg_write(&(adc->SQR3), (0x1F << 0), (1 << 0))

//ADC初始化
void adc_init(volatile struct ADC_REG *adc);

#endif