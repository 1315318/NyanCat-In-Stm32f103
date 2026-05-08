#include "change_picture.h"
#include "base_define.h"
#include "interrupt.h"
#include "nvic.h"
#include "exti.h"
#include "afio.h"
#include "gpio.h"
#include "delay.h"

volatile unsigned nyan_flag = 0;

void change_interrupt()
{
    struct INTERRUPT_CONFIG interrupt_config = {
        .nvic                = NVIC,
        .exti                = EXTI,
        .afio                = AFIO,
        .gpio_type           = GPIOB,
        .interrupts_location = INTERRUPTS_L,
        .interrupts          = 23,
        .pri_num             = 30,
        .exti_num            = 8,
        .port_type           = PB,
        .trig_method         = FAL_EDG,
        .pin_num             = GPIO_CH8,
        .mode                = GPIO_MODE_DRINPUT,
        .level               = HIGH,
    };
    set_interrupt(&interrupt_config);
}

void EXTI9_5_IRQHandler(void)
{
    delay_ms(5);
    nyan_flag = 1;
    pr_exti(EXTI, 8);
}