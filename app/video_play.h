#ifndef VIDEO_PLAY_H
#define VIDEO_PLAY_H

//清屏
void oled_clean(void);

//OLED屏幕初始化
void oled_init(void);

//OLED显示
void oled_display(const unsigned char *display_num);

#endif