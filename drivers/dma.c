#include "dma.h"
#include "base_define.h"
#include "rcc.h"

//RCC对应时钟使能
void enr_dma(void)
{
    SET_BIT((RCC->AHBENR), (1 << 0));
}

//静态参数初始化
void init_dma(unsigned char channel_num, unsigned char priority_level, unsigned char msize, 
    unsigned char psize, unsigned char minc, unsigned char circ, unsigned char dir)
{
    CLEAN_BIT((DMA->dma_channel[channel_num].CCR), (0x3 << 12));
    SET_BIT((DMA->dma_channel[channel_num].CCR), (priority_level << 12)); //设置通道优先级
    CLEAN_BIT((DMA->dma_channel[channel_num].CCR), (0x3 << 10)); 
    SET_BIT((DMA->dma_channel[channel_num].CCR), (msize << 10));          //设置存储器数据宽度
    CLEAN_BIT((DMA->dma_channel[channel_num].CCR), (0x3 << 8));
    SET_BIT((DMA->dma_channel[channel_num].CCR), (psize << 8));           //设置外设数据宽度
    SET_BIT((DMA->dma_channel[channel_num].CCR), (minc << 7));            //设置存储器地址增量模式
    SET_BIT((DMA->dma_channel[channel_num].CCR), (dir << 4));             //设置数据传输方向
    SET_BIT((DMA->dma_channel[channel_num].CCR), (circ << 5));            //设置循环模式
}

//根据宏定义，传入的target_address是一个结构体指针，传参时需要做强制类型转换(unsigned int)
void set_dma(unsigned char channel_num, unsigned int data_size, unsigned int target_address, unsigned int data_address) 
{
    DMA->dma_channel[channel_num].CNDTR = data_size;        //数据传输数量，范围为0～65535
    DMA->dma_channel[channel_num].CPAR  = target_address;   //外设数据寄存器的基地址，作为数据传输的源或目标 
    DMA->dma_channel[channel_num].CMAR  = data_address;     //存储器地址，作为数据传输的源或目标
    SET_BIT((DMA->dma_channel[channel_num].CCR), (1 << 0)); //通道使能
}
