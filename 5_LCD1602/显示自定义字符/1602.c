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
char wang[8]={0x1f,0x05,0x04,0x1F,0x04,0x04,0x04,0x1F};//�� ��
char bug_head[8]={0x1B,0x0A,0x0E,0x11,0x1B,0x11,0x15,0x0E};//ֻ����IcharI��
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
 wdat(0x39);//��ʾ����9
 while(1);
}


void delayus(uint tus)
{
 while(tus--);
}

void wdir(int dir)//directive ����
{//дָ��
 en=0;//�ر�ʹ�ܣ���������
 rw=0;//5�����ţ�0д�룬1��ȡ
 rs=0;//4�����ţ�0ָ�1����
 P0=dir;//����ָ��
 en=1;//��ʹ�ܣ���������
 en=0;//�½��أ���������
 delayus(100);//û�������ʱ����ʲôҲ�䲻����
}
void wdat(int dat)//date ����
{//д����
 en=0;
 rw=0;
 rs=1;
 P0=dat;
 en=1;
 en=0;
 delayus(100);//û�������ʱ��ʲôҲ�䲻����
}
void ini()//initialize ����
{
 /*wdir(0x38);
 wdir(0x0c);
 wdir(0x06);
 wdir(0x01);
 
 delayus(100);*/
  wdir(0x38);//����16x2��ʾ��5x7����8λ���ݽӿ�
  wdir(0x0f);//����ʾ����ʾ��꣬�����˸
  wdir(0x05);//��������
  wdir(0x01);//����
  line(1); //posi(0,0);//��ʼ�����λ��
}
void line(char li)//ѡ�� λ�ã��У�
{
  if(li==1) wdir(0x80);
  if(li==2) wdir(0xc0);
  
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








