#ifndef GPIO_H
#define GPIO_H

//GPIO端口寄存器
struct GPIOx
{
    volatile unsigned int CRL;
    volatile unsigned int CRH;
    volatile unsigned int IDR;
    volatile unsigned int ODR;
    volatile unsigned int BSRR;
    volatile unsigned int BRR;
    volatile unsigned int LCKR;
};

//GPIO端口初地址
#define GPIOA ((volatile struct GPIOx *) 0x40010800)
#define GPIOB ((volatile struct GPIOx *) 0x40010C00)
#define GPIOC ((volatile struct GPIOx *) 0x40011000)

//BSRR操作
#define BSRR_SET(REG,BIT)   ((REG) = (BIT))
#define BSRR_CLEAN(REG,BIT) ((REG) = ((BIT) << 16))

//引脚模式
#define GPIO_MODE_PP      0x3 //通用推挽输出模式，50MHZ
#define GPIO_MODE_OL      0x7 //通用开漏输出模式，50MHZ
#define GPIO_MODE_AFPP    0xB //复用推挽输出模式，50MHZ
#define GPIO_MODE_DRINPUT 0x8 //上拉下拉输入模式

//引脚号
#define GPIO_CH0  0   
#define GPIO_CH1  1   
#define GPIO_CH2  2   
#define GPIO_CH3  3
#define GPIO_CH4  4   
#define GPIO_CH5  5   
#define GPIO_CH6  6   
#define GPIO_CH7  7
#define GPIO_CH8  8   
#define GPIO_CH9  9   
#define GPIO_CH10 10 
#define GPIO_CH11 11
#define GPIO_CH12 12 
#define GPIO_CH13 13 
#define GPIO_CH14 14 
#define GPIO_CH15 15

//RCC对应时钟使能
void enr_gpio(volatile struct GPIOx *gpio_type);

//gpio_type为引脚类型，pin_num为引脚号，范围0～15，mode为输出模式
void init_gpio(volatile struct GPIOx *gpio_type, unsigned char pin_num, unsigned char mode);

//gpio_type为引脚类型，pin_num为引脚号，范围0～15
void set_gpio(volatile struct GPIOx *gpio_type, unsigned char pin_num, unsigned char level);

#endif