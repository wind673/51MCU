#include<reg51.h>
#define uint unsigned int
unsigned char code nnum[10]={0x3f,0x06,0x5b,0x4f,0x66,
							 0x6d,0x7d,0x07,0x7f,0x6f};//������
unsigned char code po[8]={0xfe,0xfd,0xfb,0xf7,
						  0xef,0xdf,0xbf,0x7f};//ѡλ
void ddisplay(uint i,uint s);
void delayus(uint tus);

void main()
{
unsigned char i,rise=0,ir=0;
unsigned int s[8],k=0;

 while(1)
 {
  k++;
  if(k==9000000) k=0;
  for(i=0;i<8;i++)
  {
   ir=(i+rise)%8;
   s[ir]=i+1;
  }
  if((k%50)==0) rise++;
  if(rise==8) rise=0;
  
  for(i=0;i<8;i++)
  {
  ddisplay(i,s[i]);
  }
 
 
 }


}

void ddisplay(uint i,uint s)//��̬��ʾdynamic
{
	P1=po[i];//ѡλ
	P0=nnum[s];//����
	delayus(100);//��ʱ100us
	P0=0;//����
}
void delayus(uint tus)
{
while(tus--);
}

