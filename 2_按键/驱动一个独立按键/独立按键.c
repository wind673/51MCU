#include<reg51.h>
#include<intrins.h>
#define uint unsigned int
sbit  k1=P2^0;
void sleepms(uint s);
void main()
{
int j=0x01;
P0=0X01;
while(1)
{
     //P0=j;
	 
	 if(k1==0)
	 {
	  sleepms(10);//�ӳ�10ms,�ж��Ƿ���İ���
	  if(k1==0)
	   P0=_cror_(P0,1);
	  sleepms(500);

      } 
	 
}    
}
void sleepms(uint s)
{
s*=2000;
while(s--);
}