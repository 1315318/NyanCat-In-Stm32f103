#ifndef REGISTER_OPTION_H
#define REGISTER_OPTION_H

//通用寄存器写操作
static inline void reg_write(volatile unsigned int *reg, unsigned int mask, unsigned int value)
{
    *reg = (*reg & ~mask) | (value & mask);
}

#endif