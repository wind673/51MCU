#include<reg51.h>
#define uint unsigned int 
#define uchar unsigned char 
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;
void delayus(uint tus);
void wdir(int dir);
void wdat(int dat);
int busy();
void ini();
//void line(char li);
void posi(int line,int poc);
char wang[8]={0x1f,0x05,0x04,0x1F,0x04,0x04,0x04,0x00};//王 字
uchar bug_head[8]={0x1B,0x0A,0x0E,0x11,0x1B,0x11,0x15,0x00};//只能用IcharI存
char kong[8]={0};


void incgram(uchar chp,char *cust);
void main()
{
  int i;
 ini();
 
 for(i=0;i<3;i++)
 {
 wdat(0x30+i);
 wdat('h');
 
 delayus(50000000);
 
 }
 incgram(0,kong);
 incgram(0,bug_head);
 delayus(50000000);
 posi(1,2);
 wdat(0);
 
 
 while(1);
}


void delayus(uint tus)
{
 while(tus--);
}

void wdir(int dir)//directive 命令
{//写指令
 //en=0;//关闭使能，输入数据
 rw=0;//5号引脚：0写入，1读取
 rs=0;//4号引脚：0指令，1数据
 P0=dir;//传递指令
 delayus(10);
 en=1;//打开使能，建立数据
 en=0;//下降沿，保存数据
 delayus(100);//没有这个延时，将什么也输不出来
}
void wdat(int dat)//date 数据
{//写数据
rs=1;
rw=0;
 P0=dat;
 delayus(10);
 en=1;
 en=0;
 delayus(100);//没有这个延时，什么也输不出来
}



void ini()//initialize 重置
{
  wdir(0x01);//清屏
  wdir(0x38);//设置16x2显示，5x7点阵，8位数据接口
  wdir(0x0f);//开显示，显示光标，光标闪烁
  wdir(0x06);//移动
 
  posi(0,0);//初始化光标位置
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

void posi(int line,int poc)//光标位置
{
 if(line==0)
 wdir(0x80+poc);
 if(line==1)
 wdir(0xc0+poc);
 
}

int busy()
{
 unsigned char bu=P2&0x80;  
 return bu;
}




