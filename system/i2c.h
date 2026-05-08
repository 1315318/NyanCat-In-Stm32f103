#ifndef I2C_H
#define I2C_H

//定义设置高低电平
#define SCK_UP       BSRR_SET((GPIOA->BSRR), (1 << 5))
#define SCK_DOWN     BSRR_CLEAN((GPIOA->BSRR), (1 << 5))
#define SDA_UP       BSRR_SET((GPIOA->BSRR), (1 << 10))
#define SDA_DOWN     BSRR_CLEAN((GPIOA->BSRR), (1 << 10))

//定义延时宏对应不同延时需求
#define delay_normal ((unsigned char) 1)
#define delay_init   ((unsigned char) 100)

//开始信号
void i2c_start(void);

//结束信号
void i2c_over(void);

//发送逻辑
void i2c_send (unsigned char send_num);

//发送单字节命令
void cmd_write(unsigned char cmd);

//发送双字节命令
void double_cmd_write(unsigned char cmd_1, unsigned char cmd_2);

//发送单字节数据
void data_write(unsigned char data);

#endif