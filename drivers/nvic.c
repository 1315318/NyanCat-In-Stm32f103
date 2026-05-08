#include "nvic.h"
#include "base_define.h"

//中断使能
void senr_nvic(volatile struct NVIC_REG* nvic, unsigned char interrupts_location, unsigned char interrupts)
{
    if (interrupts == INTERRUPTS_L)
    {
        SET_BIT((nvic->ISER[0]), (1 << interrupts));
    }
    if (interrupts == INTERRUPTS_H)
    {
        SET_BIT((nvic->ISER[1]), (1 << interrupts));
    }
}

//中断除能
void cenr_nvic(volatile struct NVIC_REG* nvic, unsigned char interrupts_location, unsigned char interrupts)
{
    if (interrupts == INTERRUPTS_L)
    {
        SET_BIT((nvic->ICER[0]), (1 << interrupts));
    }
    if (interrupts == INTERRUPTS_H)
    {
        SET_BIT((nvic->ICER[1]), (1 << interrupts));
    }
}

//中断悬起
void spr_nvic(volatile struct NVIC_REG* nvic, unsigned char interrupts_location, unsigned char interrupts)
{
    if (interrupts == INTERRUPTS_L)
    {
        SET_BIT((nvic->ISPR[0]), (1 << interrupts));
    }
    if (interrupts == INTERRUPTS_H)
    {
        SET_BIT((nvic->ISPR[1]), (1 << interrupts));
    }
}

//中断解悬
void cpr_nvic(volatile struct NVIC_REG* nvic, unsigned char interrupts_location, unsigned char interrupts)
{
    if (interrupts == INTERRUPTS_L)
    {
        SET_BIT((nvic->CPR[0]), (1 << interrupts));
    }
    if (interrupts == INTERRUPTS_H)
    {
        SET_BIT((nvic->CPR[1]), (1 << interrupts));
    }
}

//查询中断活动状态
unsigned char act_state(volatile struct NVIC_REG* nvic, unsigned char interrupts_location, unsigned char interrupts) 
{
    unsigned char act_statue_flag;
    if (interrupts == INTERRUPTS_L)
    {
        act_statue_flag = READ_BIT((nvic->IABR[0]), (1 << interrupts));
    }
    if (interrupts == INTERRUPTS_H)
    {
        act_statue_flag = SET_BIT((nvic->IABR[1]), (1 << interrupts));
    }
    return act_statue_flag;
}

//设置中断优先级，由于IPR寄存器只实现了高4位，所以支持的优先级为0~15
void pri_nvic(volatile struct NVIC_REG* nvic, unsigned char interrupts, unsigned char pri_num)
{
    CLEAN_BIT((nvic->IPR[interrupts >> 2]), (0xF << (interrupts % 4) * 8));                  //interrupts右移2位相当于处以4
    SET_BIT((nvic->IPR[interrupts >> 2]), (((pri_num & 0xF) << 4) << (interrupts % 4) * 8)); //pri_num与0xF作运算防止传入超过15的数时污染相邻的中断位
}