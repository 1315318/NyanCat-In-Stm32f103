#ifndef GPIO_H
#define GPIO_H

//定义GPIO端口寄存器
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

//定义GPIO端口初地址
#define GPIOA               ((volatile struct GPIOx*) 0x40010800)
#define GPIOB               ((volatile struct GPIOx*) 0x40010C00)
#define GPIOC               ((volatile struct GPIOx*) 0x40011000)

//定义BSRR操作
#define BSRR_SET(REG,BIT)   ((REG) = (BIT))
#define BSRR_CLEAN(REG,BIT) ((REG) = ((BIT) << 16))

//定义输出模式
#define GPIO_MODE_PP        ((unsigned char) 0x3) //通用推挽输出模式，50MHZ
#define GPIO_MODE_OL        ((unsigned char) 0x7) //通用开漏输出模式，50MHZ
#define GPIO_MODE_AFPP      ((unsigned char) 0xB) //复用推挽输出模式，50MHZ

//定义引脚号
#define GPIO_CH0            ((unsigned char) 0)   
#define GPIO_CH1            ((unsigned char) 1)   
#define GPIO_CH2            ((unsigned char) 2)   
#define GPIO_CH3            ((unsigned char) 3)
#define GPIO_CH4            ((unsigned char) 4)   
#define GPIO_CH5            ((unsigned char) 5)   
#define GPIO_CH6            ((unsigned char) 6)   
#define GPIO_CH7            ((unsigned char) 7)
#define GPIO_CH8            ((unsigned char) 8)   
#define GPIO_CH9            ((unsigned char) 9)   
#define GPIO_CH10           ((unsigned char) 10) 
#define GPIO_CH11           ((unsigned char) 11)
#define GPIO_CH12           ((unsigned char) 12) 
#define GPIO_CH13           ((unsigned char) 13) 
#define GPIO_CH14           ((unsigned char) 14) 
#define GPIO_CH15           ((unsigned char) 15)

//RCC对应时钟使能
void enr_gpio(volatile struct GPIOx* gpio_type);

//gpio_type为引脚类型，pin_num为引脚号，范围0～15，mode为输出模式
void init_gpio(volatile struct GPIOx* gpio_type, unsigned char pin_num, unsigned char mode);

//gpio_type为引脚类型，pin_num为引脚号，范围0～15
void set_gpio(volatile struct GPIOx* gpio_type, unsigned char pin_num, unsigned char level);

#endif