#ifndef ADC_H
#define ADC_h

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

//开启ADC
#define AD_ON(adc) reg_write(&(adc->CR2), (1 << 0), (1 << 0))

#endif