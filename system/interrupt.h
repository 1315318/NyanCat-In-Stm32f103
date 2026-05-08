#ifndef INTERRUPT_H
#define INTERRUPT_H

//定义中断触发方式
#define RAS_EDG 1 //上升沿触发
#define FAL_EDG 2 //下降沿触发

struct INTERRUPT_CONFIG
{
    volatile struct NVIC_REG*  nvic;
    volatile struct EXTI_REG*  exti;
    volatile struct AFIO_REG*  afio;
    volatile struct GPIOx*     gpio_type;
    unsigned char interrupts_location;
    unsigned char interrupts;  
    unsigned char pri_num;
    unsigned char exti_num;
    unsigned char port_type;
    unsigned char trig_method;
    unsigned char pin_num;
    unsigned char mode;
    unsigned char level;
};

//配置外部中断
void set_interrupt(struct INTERRUPT_CONFIG* interrupt_config);

#endif