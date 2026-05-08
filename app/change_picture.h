#ifndef CHANGE_PICTURE_H
#define CHANGE_PICTURE_H

extern volatile unsigned nyan_flag;

void change_interrupt();

void EXTI9_5_IRQHandler(void);

#endif