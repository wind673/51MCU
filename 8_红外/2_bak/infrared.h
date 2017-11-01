//红外线
#include<com.h>
#include<lcd.h>
sbit inf=P3^2; 
uchar sure=0;
void inter_init();
uchar inf_dat[4];





void inter_init()
{
 EX0=1;
 IT0=1;
 EA=1;
  
}

void infrared()interrupt 0
{ 
 uchar AGC=0,STA=0,i,n=0;
  uint a=0,temp,tag;
   delay6ms();
   if(inf==0) AGC=1;
   delay6ms();
   if(inf==1) STA=1;
   if(AGC==1&&STA==1)
   {
     while(1)
     {
      while(inf==1&&a<1000)
	  { a++;delay1ms();}//检测数据是否数据位，a用来防止死机
      delay1ms();
	  delay500us();
	 	 if(inf==1) tag=1;
		 if(inf==0) tag=0; 
	 	 for(n=0;n<4;n++)
	  	 {
	  		for(i=0;i<8;i++)
	 		{
	  		temp<<=1;
	  		temp=temp|tag;
	  		}
			inf_dat[n]=temp;
      	 }
	 }
   }
  sure=0;
  if(inf_dat[2]==inf_dat[3]) sure=1;
  
  
  
}




