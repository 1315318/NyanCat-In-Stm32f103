#include "base_define.h"    
#include "nyancat_video.h"  
#include "nyancat_audio.h"  
#include "gpio.h"           
#include "video_play.h"     
#include "audio_play.h"     
#include "change_picture.h" 
#include "delay.h"          

//PC13
#define RCC_APB2ENR     (*(volatile unsigned int *) 0x40021018) 
#define GPIOC_CRH       (*(volatile unsigned int *) 0x40011004)
#define GPIOC_ODR       (*(volatile unsigned int *) 0x4001100C)

//切换延时
#define delay_change    ((unsigned char) 1000) 
//动画延时
#define delay_animation ((unsigned char) 10)   

int main(void) 
{
    //PC13
    SET_BIT((RCC_APB2ENR), (1 << 4));
    CLEAN_BIT((GPIOC_CRH), (0xF << 20));
    SET_BIT((GPIOC_CRH), (0x3 << 20));
    
    //GPIO端口初始化
    enr_gpio(GPIOA);
    enr_gpio(GPIOB);

    //PA5作为SCK，通用开漏输出模式，50MHZ，PB5作为SDA，通用开漏输出模式，50MHZ
    init_gpio(GPIOA, GPIO_CH5, GPIO_MODE_OL); 
    init_gpio(GPIOB, GPIO_CH5, GPIO_MODE_OL); 
    set_gpio(GPIOA, GPIO_CH5, HIGH);
    set_gpio(GPIOB, GPIO_CH5, HIGH); 
    
    //画面切换中断初始化
    change_interrupt();
    
    //OLED初始化
    oled_init();
    oled_display(nyan_cat);
    delay_ms(delay_change);
    
    //音频播放函数调用
    audio_play();
    
    //主循环
    while (1)
    {
        if (nyan_flag == 1) 
        {
            oled_init(); 
            oled_display(nyan_cat);
            delay_ms(500);
            nyan_flag = 0; 
        }
        for (int i = 0; i < 24; i++)
        {
            oled_display(nyancats[i]);
            delay_ms(delay_animation);
        }
    }
}