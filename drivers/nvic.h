#ifndef INTERRUPT_H
#define INTERRUPT_H

//定义NVIC寄存器
struct NVIC
{
    volatile unsigned int  ISER[3];        //中断使能寄存器
    volatile unsigned int  RESERVED0[29];  //保留
    volatile unsigned int  ICER[3];        //中断除能寄存器
    volatile unsigned int  RESERVED1[29];  //保留
    volatile unsigned int  ISPR[3];        //中断悬起寄存器
    volatile unsigned int  RESERVED2[29];  //保留
    volatile unsigned int  CPR[3];         //中断解悬寄存器
    volatile unsigned int  RESERVED3[29];  //保留
    volatile unsigned int  IABR[3];        //中断活动状态寄存器
    volatile unsigned int  RESERVED4[61];  //保留
    volatile unsigned char IPR[84];        //中断优先级寄存器
    volatile unsigned int  RESERVED5[695]; //保留
    volatile unsigned char STIR;           //软件触发中断寄存器
};

//定义NVIC初地址
#define NVIC ((volatile struct NVIC*) 0xE000E100)

//划分中断位置
#define INTERRUPTS_L 1 //前32个中断号
#define INTERRUPTS_H 2 //后28个中断号

//定义中断活动状态
#define INTERRUPT_ACT  1 //中断活动状态
#define INTERRUPT_NACT 0 //中断非活动状态

//中断使能
void senr_nvic(volatile struct NVIC* nvic, unsigned char interrupts_location, unsigned char interrupts)

//中断除能
void cenr_nvic(volatile struct NVIC* nvic, unsigned char interrupts_location, unsigned char interrupts)

//中断悬起
void spr_nvic(volatile struct NVIC* nvic, unsigned char interrupts_location, unsigned char interrupts)

//中断解悬
void cpr_nvic(volatile struct NVIC* nvic, unsigned char interrupts_location, unsigned char interrupts)

//查询中断活动状态
unsigned char act_state(volatile struct NVIC* nvic, unsigned char interrupts_location, unsigned char interrupts) 

//设置中断优先级，由于IPR寄存器只实现了高4位，所以支持的优先级为0~15
void pri_nvic(volatile struct NVIC* nvic, unsigned char interrupts, unsigned char pri_num)

#endif