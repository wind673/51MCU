#include<reg51.h>
#define uint unsigned int 
#define uchar unsigned char
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;
void wdir(int dir);
void wdat(int dat);
void posi(int line,int poc);
void delayus(uint tus);
void init();
void incgram(uchar chp,char *cust);

char bug_head[8]={0x1B,0x0A,0x0E,0x11,0x1B,0x11,0x15,0x0E};
uchar hi[6]="Hello!";

void main()
{
 int i;
   
  init();
  for(i=0;i<6;i++)
  wdat(hi[i]);
  incgram(1,bug_head);
  incgram(2,bug_head);
  posi(1,5);
  wdat(1);wdat(2);
  while(1);
  
}

void wdir(int dir)//写指令		
{
 en=0;
 rw=0;
 rs=0;
 P0=dir;
 en=1;
 en=0;
 delayus(100);
}

void wdat(int dat)//写数据
{
 en=0;
 rw=0;
 rs=1;
 P0=dat;
 en=1;
 en=0;
 delayus(100);
}

void posi(int line,int poc)//光标位置
{
 if(line==0)
 wdir(0x80+poc);
 if(line==1)
 wdir(0xc0+poc);
 
}

void delayus(uint tus)
{
  while(tus--);
}

void init()//初始化
{
  wdir(0x01);
  wdir(0x38);//设置16x2显示，5x7点阵，8位数据接口
  wdir(0x0f);//开显示，显示光标，光标闪烁
  wdir(0x06);
  //清屏
  posi(0,0);//初始化光标位置
  delayus(100);
  
}
void incgram(uchar chp,char *cust)//将自定义字符写入CGRAM
{
 
 int i,temp;
 for(i=0;i<8;i++)
  {
  
  temp=0x40+i+8*chp;
  wdir(temp);//往CGRAM写自定义字符，选择第chp个字的第i行
  wdat(cust[i]);
  
  
  }
}
