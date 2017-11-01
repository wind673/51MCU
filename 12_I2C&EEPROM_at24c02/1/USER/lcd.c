#include "lcd.h"



void lcd_init()
{
  lcd_wdir(0x38);//��ʾģʽ
  lcd_wdir(0x0c);//��ʾ���ؼ����
  lcd_wdir(0x01);//����
  lcd_wdir(0x06);//�����Ļ�Ƿ��ƶ�
  lcd_wdir(0x80);//��ʼ��껯λ��
}

void lcd_custom(uchar num,uchar *word)//��ʾ�Զ�����   wordΪ��num����
{
   uchar i,temp;
   num=num*8;
   for(i=0;i<8;i++)
   {
   temp=0x40+i+num;
   lcd_wdir(temp);
   lcd_wdat(word[i]);
	 
   }
}

void lcd_wdat(uchar dat)//д����
{
  en=0;
  rw=0;
  rs=1;
  P0=dat;
  en=1;
  delay10ms();
  en=0;
  
}

void lcd_wdir(uchar dir)//д����
{
  en=0;
  rw=0;
  rs=0;
  P0=dir;
  en=1;
  delay10ms();
  en=0;
  
}

void lcd_posi(uchar line,uchar x)//ѡ����
{ 
  x--;
  if(line==1) lcd_wdir(0x80+x);
  if(line==2) lcd_wdir(0xc0+x);
  
}

void lcd_str(unsigned char *ch)
{
while(*ch)	 lcd_wdat(*(ch++));
}

