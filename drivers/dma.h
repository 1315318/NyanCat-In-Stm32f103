#ifndef DMA_H
#define DMA_H

//DMA寄存器通道配置寄存器
struct DMA_CHANNEL
{
    volatile unsigned int CCR;
    volatile unsigned int CNDTR;
    volatile unsigned int CPAR;
    volatile unsigned int CMAR;
    volatile unsigned int RESERVED; //保留
};

//DMA寄存器
struct DMA
{
    volatile unsigned int ISR;
    volatile unsigned int IFCR;
    struct   DMA_CHANNEL  dma_channel[7]; //DMA1有7个通道
};

//DMA初地址
#define DMA ((volatile struct DMA *) 0x40020000) 

//DMA通道
#define DMA_CH1 0
#define DMA_CH2 1
#define DMA_CH3 2
#define DMA_CH4 3
#define DMA_CH5 4
#define DMA_CH6 5
#define DMA_CH7 6

//通道优先级
#define DMA_LOW    0 //低
#define DMA_MEDIUM 1 //中
#define DMA_HIGH   2 //高
#define DMA_ULTRA  3 //最高

//存储器数据宽度
#define MSIZE_8BIT  0 //8位
#define MSIZE_16BIT 1 //16位
#define MSIZE_32BIT 2 //32位

//外设数据宽度
#define PSIZE_8BIT  0 //8位
#define PSIZE_16BIT 1 //16位
#define PSIZE_32BIT 2 //32位

//存储器地址增量模式开关
#define MINC_OFF 0 //不执行存储器地址增量操作
#define MINC_ON  1 //执行存储器地址增量操作

//循环模式开关
#define CIRC_OFF 0 //不执行循环操作
#define CIRC_ON  1 //执行循环操作

//数据传输方向
#define DIR_PSI 0 //从外设读
#define DIR_MSI 1 //从存储器读

//RCC对应时钟使能
void enr_dma(void);

//静态参数初始化
void init_dma(unsigned char channel_num, unsigned char priority_level, unsigned char msize, 
              unsigned char psize, unsigned char minc, unsigned char circ, unsigned char dir);

//根据宏定义，传入的target_address是一个结构体指针，传参时需要做强制类型转换(unsigned int)
void set_dma(unsigned char channel_num, unsigned int data_size, unsigned int target_address, 
             unsigned int data_address);

#endif