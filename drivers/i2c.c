#include "base_define.h"
#include "gpio.h"
#include "delay.h"
#include "i2c.h"

//开始信号
void i2c_start(void)
{
    SDA_UP;                 
    SCK_UP;                 
    delay_us(delay_normal);
    SDA_DOWN;
    delay_us(delay_normal);
    SCK_DOWN;
    delay_us(delay_normal);
}

//结束信号
void i2c_over(void)
{
    SDA_DOWN; 
    delay_us(delay_normal);
    SCK_UP; 
    delay_us(delay_normal);
    SDA_UP;
    delay_us(delay_normal);
}

//发送逻辑
void i2c_send (unsigned char send_num)
{
    for(int i = 7; i >= 0; i--) {
        SCK_DOWN;
        delay_us(delay_normal);
        if (READ_BIT((send_num), (1 << i))) 
        {
            SDA_UP; 
        }
        else 
        {
            SDA_DOWN;
        }
        delay_us(delay_normal);
        SCK_UP;   
        delay_us(delay_normal);
    }
    SCK_DOWN;
    delay_us(delay_normal);
    SDA_UP; 
    delay_us(delay_normal);
    SCK_UP;   
    delay_us(delay_normal); //ACK应答周期
    SCK_DOWN;
    delay_us(delay_normal);
}

//发送单字节命令
void cmd_write(unsigned char cmd)
{
    i2c_start();
    unsigned char slave_address = 0x78;
    i2c_send(slave_address);
    unsigned char control_byte = 0x00;
    i2c_send(control_byte);
    i2c_send(cmd);
    i2c_over();
}

//发送双字节命令
void double_cmd_write(unsigned char cmd_1, unsigned char cmd_2)
{
    i2c_start();
    unsigned char slave_address = 0x78;
    i2c_send(slave_address);
    unsigned char control_byte = 0x00;
    i2c_send(control_byte);
    i2c_send(cmd_1);
    i2c_send(cmd_2);
    i2c_over();
}

//发送单字节数据
void data_write(unsigned char data)
{
    i2c_start();
    unsigned int slave_address = 0x78;
    i2c_send(slave_address);
    unsigned int control_byte = 0x40;
    i2c_send(control_byte);
    i2c_send(data);
    i2c_over();
}