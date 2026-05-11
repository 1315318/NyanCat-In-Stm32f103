#include "video_play.h"
#include "i2c.h"
#include "delay.h"

//清屏
void oled_clean(void)
{
    double_cmd_write(0x21,0x00); //Column Start 0
    cmd_write(0x7F);             //Column End 127
    double_cmd_write(0x22,0x00); //Page Start 0
    cmd_write(0x07);             //Page End 7   
    
    i2c_start();
    i2c_send(0x78);       
    i2c_send(0x40);
    for(int i = 0; i < 1024; i++)
    {
        i2c_send(0x00); 
    }
    
    i2c_over();
}

//OLED屏幕初始化
void oled_init(void)
{
    delay_ms(delay_init);
    
    cmd_write(0xAE);              //关闭屏幕
    double_cmd_write(0xA8, 0x3F); //Set MUX Ratio
    double_cmd_write(0xD3, 0x00); //Set Display Offset
    cmd_write(0x40);              //Set Display Start Line
    double_cmd_write(0x20, 0x00); //设置垂直寻址
    cmd_write(0xA1);              //Set Segment re-map 
    cmd_write(0xC8);              //Set COM Output Scan Direction 
    double_cmd_write(0xDA, 0x12); //Set COM Pins hardware cofiguration
    double_cmd_write(0x81, 0x7F); //Set Contrast Control
    cmd_write(0xA4);              //Disable Entire Display on 
    cmd_write(0xA6);              //Set Normal Display
    double_cmd_write(0xD5, 0x80); //Set Osc Frequency
    double_cmd_write(0xD9, 0xF1); //Set Pre-charge Period
    double_cmd_write(0xDB, 0x30); //Set VCOMH Deselete Level
    double_cmd_write(0x8D, 0x14); //Enable Charge Pump Regulato
    
    oled_clean();
    cmd_write(0xAF);              //Display On
}

//OLED显示
void oled_display(const unsigned char *display_num)
{
    double_cmd_write(0x21, 0x00); //Column Start 0
    cmd_write(0x7F);              //Column End 127
    double_cmd_write(0x22, 0x00); //Page Start 0
    cmd_write(0x07);              //Page End 7   
    
    i2c_start();
    i2c_send(0x78);       
    i2c_send(0x40);
    for(int i = 0; i < 1024; i++)
    {
        i2c_send(display_num[i]); 
    }
    
    i2c_over();
}