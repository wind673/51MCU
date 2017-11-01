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
char wang[8]={0x1f,0x05,0x04,0x1F,0x04,0x04,0x04,0x00};//�� ��
uchar bug_head[8]={0x1B,0x0A,0x0E,0x11,0x1B,0x11,0x15,0x00};//ֻ����IcharI��
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

void wdir(int dir)//directive ����
{//дָ��
 //en=0;//�ر�ʹ�ܣ���������
 rw=0;//5�����ţ�0д�룬1��ȡ
 rs=0;//4�����ţ�0ָ�1����
 P0=dir;//����ָ��
 delayus(10);
 en=1;//��ʹ�ܣ���������
 en=0;//�½��أ���������
 delayus(100);//û�������ʱ����ʲôҲ�䲻����
}
void wdat(int dat)//date ����
{//д����
rs=1;
rw=0;
 P0=dat;
 delayus(10);
 en=1;
 en=0;
 delayus(100);//û�������ʱ��ʲôҲ�䲻����
}



void ini()//initialize ����
{
  wdir(0x01);//����
  wdir(0x38);//����16x2��ʾ��5x7����8λ���ݽӿ�
  wdir(0x0f);//����ʾ����ʾ��꣬�����˸
  wdir(0x06);//�ƶ�
 
  posi(0,0);//��ʼ�����λ��
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

void posi(int line,int poc)//���λ��
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




