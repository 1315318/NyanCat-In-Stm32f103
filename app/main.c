/*PA13 (JTMS / SWDIO)：SWD 模式的数据线
PA14 (JTCK / SWCLK)：SWD 模式的时钟线
PA15 (JTDI)：JTAG 专用
PB3 (JTDO)：JTAG 专用
PB4 (NJTRST)：JTAG 专用*/

#include "base_define.h"   //位操作及高低电平宏的定义
#include "nyancat_video.h" //图像数组
#include "nyancat_audio.h" //音频数组
#include "gpio.h"          //GPIO寄存器及初地址相关定义和GPIO端口初始化与设置函数
#include "video_play.h"    //视频播放函数
#include "audio_play.h"    //音频播放函数
#include "delay.h"         //延时函数

//PC13
#define RCC_APB2ENR     (*(volatile unsigned int*) 0x40021018) 
#define GPIOC_CRH       (*(volatile unsigned int*) 0x40011004)
#define GPIOC_ODR       (*(volatile unsigned int*) 0x4001100C)

#define delay_change    ((unsigned char) 1000) //切换延时
#define delay_animation ((unsigned char) 10)   //动画延时

int main(void) 
{
    //PC13
    SET_BIT((RCC_APB2ENR), (1 << 4));
    CLEAN_BIT((GPIOC_CRH), (0xF << 20));
    SET_BIT((GPIOC_CRH), (0x3 << 20));
    //GPIO端口初始化
    enr_gpio(GPIOA);
    init_gpio(GPIOA, GPIO_CH5, GPIO_MODE_OL);  //PA5作为SCK，通用开漏输出模式，50MHZ
    init_gpio(GPIOA, GPIO_CH10, GPIO_MODE_OL); //PA10作为SDA，通用开漏输出模式，50MHZ
    set_gpio(GPIOA, GPIO_CH5, HIGH);
    set_gpio(GPIOA, GPIO_CH10, HIGH); 
    //OLED初始化
    oled_init();
    oled_display(nyan_cat);
    delay_ms(delay_change);
    //音频播放函数调用
    audio_play();
    //主循环
    while (1)
    {
        for (int i = 0; i < 24; i++)
        {
            oled_display(nyancats[i]);
            delay_ms(delay_animation);
        }
    }
}