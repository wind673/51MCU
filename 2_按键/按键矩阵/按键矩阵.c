#include<reg51.h>
#define uint unsigned int 
#define uchar unsigned char 
 uchar keyr=0,keyc=0;
 unsigned char code pnum[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
 void key();
 void delayus(uint tus);
 void main()
 {
  int i;
  P0=0xc0;
  while(1)
  {
  P2=0xf0;
  key();
  i=(keyr+keyc)%10;
  P0=pnum[i];				
  }
 }
 
 void key()
 { 
   
   if(P2!=0Xf0)
   {
   //delayus(10000);//10ms
   if(P2!=0Xf0)
    {
	P2=0x0f;//检查行
	if(P2==0x07) keyr=1;
	if(P2==0X0b) keyr=2;
	if(P2==0x0d) keyr=3;
	if(P2==0X0e) keyr=4;
	P2=0xf0;//检查列
	if(P2==0x70) keyc=1;
	if(P2==0Xb0) keyc=2;
	if(P2==0xd0) keyc=3;
	if(P2==0Xe0) keyc=4;
	//delayus(500000);
	}
   
   }
   
   
 }
 void delayus(uint tus)
 {
 while(tus--);
 }