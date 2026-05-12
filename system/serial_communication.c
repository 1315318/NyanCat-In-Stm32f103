#include "usart.h"
#include "serial_communication.h"

//串口初始化
void serial_init(volatile struct USART_REG *usart, unsigned char option_type, unsigned int mant, 
                 unsigned char frac)
{
    cr1_usart(usart, ON, UE);
    cr1_usart(usart, option_type, WL);
    cr2_usart(usart, STBITS_ONE, STBITS);
    brr_usart(usart, mant, frac);
    cr1_usart(usart, ON, RE);
    cr1_usart(usart, ON, TE);
    cr1_usart(usart, ON, RXNEIE);
}

//串口接收
char serial_receive(volatile struct USART_REG *usart)
{
    while (!(usart->SR & (1 << 5)));
    return (char)(usart->DR & 0xFF);
}

//串口发送
void serial_send(volatile struct USART_REG *usart, unsigned char data)
{
    while (!(usart->SR & (1 << 7)));
    dr_usart(usart, data);
}