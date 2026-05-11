#ifndef TIMX_H
#define TIMX_H

//通用定时器寄存器
struct TIM
{
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int SMCR;
    volatile unsigned int DIER;
    volatile unsigned int SR;
    volatile unsigned int EGR;
    volatile unsigned int CCMR1;
    volatile unsigned int CCMR2;
    volatile unsigned int CCER;
    volatile unsigned int CNT;
    volatile unsigned int PSC;
    volatile unsigned int ARR;
    volatile unsigned int RESERVED; //保留
    volatile unsigned int CCR1;
    volatile unsigned int CCR2;
    volatile unsigned int CCR3;
    volatile unsigned int CCR4;
    volatile unsigned int DCR;
    volatile unsigned int DMAR;
};

//通用定时寄存器初地址
#define TIM2 ((volatile struct TIM *) 0x40000000)
#define TIM3 ((volatile struct TIM *) 0x40000400)
#define TIM4 ((volatile struct TIM *) 0x40000800)

//TIM通道
#define TIM_CH1 1
#define TIM_CH2 2
#define TIM_CH3 3
#define TIM_CH4 4

//自动重装载预装载
#define ARPE_OFF 0
#define APRE_ON  1

//中央对齐模式
#define EDGE_ALI    0 //边沿对齐模式
#define CENTER_ALI1 1 //中央对齐模式1
#define CENTER_ALI2 2 //中央对齐模式2
#define CENTER_ALI3 4 //中央对齐模式3

//计数器计数方向
#define DIR_UP   0 //计数器向上计数
#define DIR_DOWN 1 //计数器向下计数

//单脉冲模式
#define OPM_OFF  0 //在发生更新事件时，计数器不停止
#define OPM_DOWN 1 //在发生下一次更新事件(清除CEN位)时，计数器停止

//更新请求源
#define URS_MULTI 0 //多个事件产生更新中断或DMA请求
#define URS_SINGL 1 //只有计数器溢出/下溢才产生更新中断或DMA请求

//触发DMA请求
#define TDE_OFF 0 //禁止触发DMA请求
#define TDE_ON  1 //允许触发DMA请求

//更新中断
#define UIE_OFF 0 //禁止更新中断
#define UIE_ON  1 //允许更新中断

//更新事件的产生
#define UG_OFF 0 //无动作
#define UG_ON  1 //重新初始化计数器，并产生一个更新事件

//输出比较模式
#define OCM_FRZE 0   //冻结模式
#define OCM_PWM1 0x6 //PWM模式1
#define OCM_PWM2 0x7 //PWM模式2

//输出比较预装载
#define OCPE_OFF 0 //禁止TIMx_CCR1寄存器的预装载功能，可随时写入TIMx_CCR1寄存器
#define OCPE_ON  1 //开启TIMx_CCR1寄存器的预装载功能，读写操作仅对预装载寄存器操作

//init_pwm配置
struct INIT_CONFIG
{
    volatile struct TIM *tim_type;
    unsigned char channel_num;
    unsigned char apre;
    unsigned char ali_type;
    unsigned char dir;
    unsigned char opm;
    unsigned char urs;
    unsigned char uids;
    unsigned char tde;
    unsigned char uie;
    unsigned char ug;
    unsigned char ocm;
    unsigned char ocpe;
};

//RCC对应时钟使能
void enr_tim(volatile struct TIM *tim_type);

//静态参数初始化
void init_tim(struct INIT_CONFIG *init_config);

//动态参数初始化
void set_tim(volatile struct TIM *tim_type,unsigned char channel_num, unsigned char psc, 
             unsigned int arr, unsigned char ccr, unsigned char mode);

#endif