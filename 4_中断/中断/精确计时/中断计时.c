#include<reg51.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uint time=0;
void timer();

void main()
{
 uint led=0x01;
  timer();
  while(1)
  {
  P0=led;
  if(time==20) {time=0;led=_crol_(led,1);}//1s
  }
}
void timer()//ÖÐ¶Ï Ê±¼ä50ms
{
 TMOD=0X01;
 TH0=0x3D;
 TL0=0x0F8;
 ET0=1;
 EA=1;
 TR0=1;
}
void timer0()interrupt 1
{
 time++;
  TH0=0x3D;
 TL0=0x0F8;
}




