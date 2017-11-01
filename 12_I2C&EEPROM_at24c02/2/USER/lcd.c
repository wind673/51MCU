#include "lcd.h"



void lcd_init()
{
  lcd_wdir(0x38);//显示模式
  lcd_wdir(0x0c);//显示开关及光标
  lcd_wdir(0x01);//清屏
  lcd_wdir(0x06);//光标屏幕是否移动
  lcd_wdir(0x80);//初始光标化位置
}

void lcd_custom(uchar num,uchar *word)//显示自定义字   word为第num个字
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

void lcd_wdat(uchar dat)//写数据
{
  en=0;
  rw=0;
  rs=1;
  P0=dat;
  en=1;
  delay10ms();
  en=0;
  
}

void lcd_wdir(uchar dir)//写命令
{
  en=0;
  rw=0;
  rs=0;
  P0=dir;
  en=1;
  delay10ms();
  en=0;
  
}

void lcd_posi(uchar line,uchar x)//选坐标
{ 
  x--;
  if(line==1) lcd_wdir(0x80+x);
  if(line==2) lcd_wdir(0xc0+x);
  
}

void lcd_str(unsigned char *ch)
{
while(*ch)	 lcd_wdat(*(ch++));
}

