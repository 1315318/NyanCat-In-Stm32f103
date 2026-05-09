#ifndef CHANGE_PICTURE_H
#define CHANGE_PICTURE_H

extern volatile unsigned nyan_flag;

//画面切换函数
void change_interrupt(void);

//中断服务函数
void EXTI9_5_IRQHandler(void);

#endif