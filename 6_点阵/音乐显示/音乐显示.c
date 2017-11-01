#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
sbit sck=P3^6;
sbit lck=P3^5;
sbit sdi=P3^4;
void send(int dat0,int dat1,int dat2,int dat3);
void senddate();
unsigned char code hang[16][2]={{0x80,0x00},{0x40,0x00},{0x20,0x00},{0x10,0x00},{0x08,0x00},{0x04,0x00},{0x02,0x00},{0x01,0x00},
							   {0x00,0x80},{0x00,0x40},{0x00,0x20},{0x00,0x10},{0x00,0x08},{0x00,0x04},{0x00,0x02},{0x00,0x01}};
							 //{0高位(上面的),1低位(下面的)}
uchar date[32]={0};


void main()
{
  while(1)
  {
   
  
  
  
  senddate();
 }
}

void senddate()
{
  for(i=0;i<16;i++)
  send(~hang[i][1],~hang[i][0],date[i*2+1],date[i*2]);
  
}

void send(int dat0,int dat1,int dat2,int dat3)
{

  unsigned char i;
  sck=1;//上升沿 移位
  lck=1;//上升沿 输出
  //第一段数据
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat0&0x01;
	dat0>>=1;
	
	sck=1; 	
  
  }
 
  //第二段数据
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat1&0x01;
	dat1>>=1;
	 
	sck=1;	

  }
   
   //第三段数据
  for(i=0;i<8;i++)
  { 
    sck=0;
    sdi=dat2&0x01;
	dat2>>=1;
   
	sck=1;	

  }
     
   //第四段数据
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat3&0x01;
	dat3>>=1;
	
	sck=1;	
  }

  //并口输出
   lck=0;
   lck=1;
    

}