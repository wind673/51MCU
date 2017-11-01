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
							 //{0��λ(�����),1��λ(�����)}
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
  sck=1;//������ ��λ
  lck=1;//������ ���
  //��һ������
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat0&0x01;
	dat0>>=1;
	
	sck=1; 	
  
  }
 
  //�ڶ�������
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat1&0x01;
	dat1>>=1;
	 
	sck=1;	

  }
   
   //����������
  for(i=0;i<8;i++)
  { 
    sck=0;
    sdi=dat2&0x01;
	dat2>>=1;
   
	sck=1;	

  }
     
   //���Ķ�����
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat3&0x01;
	dat3>>=1;
	
	sck=1;	
  }

  //�������
   lck=0;
   lck=1;
    

}