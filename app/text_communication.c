#include "text_communication.h"
#include "base_define.h"
#include "usart.h"
#include "serial_communication.h"
#include "nvic.h"
#include "gpio.h"
#include "rcc.h"

//波特率115200bps
void text_communication()
{
    cpr_nvic(NVIC, INTERRUPTS_H, 37);
    pri_nvic(NVIC, 37, 0);
    senr_nvic(NVIC, INTERRUPTS_H, 37);
    enr_gpio(GPIOA);
    init_gpio(GPIOA, GPIO_CH9, GPIO_MODE_AFPP);
    init_gpio(GPIOA, GPIO_CH10, GPIO_MODE_DRINPUT);
    set_gpio(GPIOA, GPIO_CH10, HIGH);
    enr_usart(USART1);
    serial_init(USART1, OFF, 0x27, 1);
    serial_receive(USART1);
}

//中断服务函数
void USART1_IRQHandler()
{
    if (USART1->SR & (1 << 5)) 
    { 
        char data = serial_receive(USART1);  
        serial_send(USART1, data); 
    }
}