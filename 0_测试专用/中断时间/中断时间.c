#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
unsigned char code nnum[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char code places[8]={0xfe,0xfd,0xfc,0xf7,0xef,0xdf,0xcf,0x7f};
void itrpt();
void ddisplay(unsigned int pl,unsigned int nu);
uint t=0,sw=0;
 sbit p3=P3^3;

uint pls=0,dnus[8]={0};
void main()
{

  itrpt();
  while(1)
  {
   p3=1;
   p3=0;
  
  
   ddisplay(0,3);
   
   /*
   t++;
   if(sw==1)
   while(1)
   for(pls=0;pls<8;pls++)
   {
   ddisplay(pls,dnus[pls]);
   }
   */
  }
   
   
   }
void itrpt()
{
 IT1=1;
 EX1=1;
 EA=1;
 PX1=1;
 
}
void inter1()interrupt 2
{
    int m=500;
	while(m--)
    ddisplay(7,8);
	
  
 /*int i,nus[8];
 if(sw==0)
 {
   sw=1;
   for(i=0;i<8;i++)
   {
    nus[i]=t%10;
    t=t/10;
   }
   for(i=7;i>=0;i--)
   {
    dnus[pls]=nus[i];
    pls++;
   }
   
 }
 */
  
  
}

 void ddisplay(unsigned int pl,unsigned int nu)//动态显示dynamic
{
    unsigned int tus;
	P2=places[pl];
	P0=nnum[nu];
   	tus=100;
	while(tus--);//延时100us
	P0=0;//消隐
}





