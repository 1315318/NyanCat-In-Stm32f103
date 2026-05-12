#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

//串口初始化
void serial_init(volatile struct USART_REG *usart, unsigned char option_type, unsigned int mant, 
                 unsigned char frac);

//串口接收
char serial_receive(volatile struct USART_REG *usart);

//串口发送
void serial_send(volatile struct USART_REG *usart, unsigned char data);

#endif