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
//void lcd_custom(uchar num,uchar *word);//numΪ��num����
void lcd_wdat(uchar dat);//д����
void lcd_wdir(uchar dir);//д����
void lcd_posi(uchar line,uchar x);//ѡ����
void lcd_str(char *ch);//����ַ���







#endif

