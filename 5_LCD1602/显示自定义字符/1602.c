#include<reg51.h>
#define uint unsigned int 
#define uchar unsigned char 
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;
void delayus(uint tus);
void wdir(int dir);
void wdat(int dat);
void ini();
void line(char li);
char wang[8]={0x1f,0x05,0x04,0x1F,0x04,0x04,0x04,0x1F};//王 字
char bug_head[8]={0x1B,0x0A,0x0E,0x11,0x1B,0x11,0x15,0x0E};//只能用IcharI存
void incgram(uchar chp,char *cust);
void main()
{
 int i,m=0x40;
 
 ini();
 incgram(0,wang);
 incgram(1,bug_head);
 
 wdir(0x84);
 wdat(0);
 wdat(1);
 wdat(0x39);//显示数字9
 while(1);
}


void delayus(uint tus)
{
 while(tus--);
}

void wdir(int dir)//directive 命令
{//写指令
 en=0;//关闭使能，输入数据
 rw=0;//5号引脚：0写入，1读取
 rs=0;//4号引脚：0指令，1数据
 P0=dir;//传递指令
 en=1;//打开使能，建立数据
 en=0;//下降沿，保存数据
 delayus(100);//没有这个延时，将什么也输不出来
}
void wdat(int dat)//date 数据
{//写数据
 en=0;
 rw=0;
 rs=1;
 P0=dat;
 en=1;
 en=0;
 delayus(100);//没有这个延时，什么也输不出来
}
void ini()//initialize 重置
{
 /*wdir(0x38);
 wdir(0x0c);
 wdir(0x06);
 wdir(0x01);
 
 delayus(100);*/
  wdir(0x38);//设置16x2显示，5x7点阵，8位数据接口
  wdir(0x0f);//开显示，显示光标，光标闪烁
  wdir(0x05);//整屏右移
  wdir(0x01);//清屏
  line(1); //posi(0,0);//初始化光标位置
}
void line(char li)//选择 位置（行）
{
  if(li==1) wdir(0x80);
  if(li==2) wdir(0xc0);
  
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








