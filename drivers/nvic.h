#ifndef NVIC_H
#define NVIC_H

//NVIC寄存器
struct NVIC_REG
{
    volatile unsigned int  ISER[3];        
    volatile unsigned int  RESERVED0[29];  
    volatile unsigned int  ICER[3];        
    volatile unsigned int  RESERVED1[29];  
    volatile unsigned int  ISPR[3];        
    volatile unsigned int  RESERVED2[29];  
    volatile unsigned int  CPR[3];         
    volatile unsigned int  RESERVED3[29];  
    volatile unsigned int  IABR[3];        
    volatile unsigned int  RESERVED4[61];  
    volatile unsigned char IPR[84];        
    volatile unsigned int  RESERVED5[695]; 
    volatile unsigned char STIR;           
};

//NVIC初地址
#define NVIC ((volatile struct NVIC_REG *) 0xE000E100)

//划分中断位置
#define INTERRUPTS_L ((unsigned char) 1) //前32个中断号
#define INTERRUPTS_H ((unsigned char) 2) //后28个中断号

//中断活动状态
#define INTERRUPT_ACT  ((unsigned char) 1) //中断活动状态
#define INTERRUPT_NACT ((unsigned char) 0) //中断非活动状态

//中断使能
void senr_nvic(volatile struct NVIC_REG *nvic, unsigned char interrupts_location, unsigned char interrupts);

//中断除能
void cenr_nvic(volatile struct NVIC_REG *nvic, unsigned char interrupts_location, unsigned char interrupts);

//中断悬起
void spr_nvic(volatile struct NVIC_REG *nvic, unsigned char interrupts_location, unsigned char interrupts);

//中断解悬
void cpr_nvic(volatile struct NVIC_REG *nvic, unsigned char interrupts_location, unsigned char interrupts);

//查询中断活动状态
unsigned char act_state(volatile struct NVIC_REG *nvic, unsigned char interrupts_location, unsigned char interrupts); 

//设置中断优先级，由于IPR寄存器只实现了高4位，所以支持的优先级为0~15
void pri_nvic(volatile struct NVIC_REG *nvic, unsigned char interrupts, unsigned char pri_num);

#endif