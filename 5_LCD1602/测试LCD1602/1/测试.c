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


void main()
{
 
   
  init();
  wdat(0x30);
  wdat(0x31);
  wdat(0x32);
  incgram(0,bug_head);//���Զ����ַ�bug_head�����0��CGRAM����
  wdat(0);//��ʾ�Զ���0������
  wdat(0x32);
  wdat(0x32);
  while(1);
  
}

void wdir(int dir)//дָ��		
{
 en=0;
 rw=0;
 rs=0;
 P0=dir;
 en=1;
 en=0;
 delayus(100);
}

void wdat(int dat)//д����
{
 en=0;
 rw=0;
 rs=1;
 P0=dat;
 en=1;
 en=0;
 delayus(100);
}

void posi(int line,int poc)//���λ��
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

void init()//��ʼ��
{
  wdir(0x38);//����16x2��ʾ��5x7����8λ���ݽӿ�
  wdir(0x0f);//����ʾ����ʾ��꣬�����˸
  wdir(0x05);//������������������ƶ�
  wdir(0x01);//����
  posi(0,0);//��ʼ�����λ��
  delayus(100);
  
}
void incgram(uchar chp,char *cust)//���Զ����ַ�д��CGRAM
{
 
 int i,temp;
 for(i=0;i<8;i++)
  {
  
  temp=0x40+i+8*chp;
  wdir(temp);//��CGRAMд�Զ����ַ���ѡ���chp���ֵĵ�i��
  wdat(cust[i]);
  
  
  }
}
