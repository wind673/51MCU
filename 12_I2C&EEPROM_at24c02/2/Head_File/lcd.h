#ifndef __LED_H
#define  __LED_H
#include<reg51.h>
#include "delay.h"


#ifndef  __uchar
#define  __uchar
#define uchar unsigned char 
#define uint unsigned int
#endif

sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;



void lcd_init();
//void lcd_custom(uchar num,uchar *word);//num为第num个字
void lcd_wdat(uchar dat);//写数据
void lcd_wdir(uchar dir);//写命令
void lcd_posi(uchar line,uchar x);//选坐标
void lcd_str(char *ch);//输出字符串







#endif

