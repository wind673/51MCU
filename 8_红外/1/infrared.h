//红外线
#ifndef uchar
#define uchar unsigned char 
#endif

#ifndef uint
#define uint unsigned int
#endif

void delay1ms();
void delay500us();
void delay6ms();

sbit inf=P3^2; 

void inter_init();






void inter_init()
{
 EX0=1;
 IT0=1;
 EA=1;
  
}

void infrared()interrupt 0
{ 
 uchar AGC=0,STA=0;
  uint i,j,k,a=0;
   delay6ms();
   if(inf==0) AGC=1;
   delay6ms();
   if(inf==1) STA=1;
   if(AGC==1&&STA==1)
   {
    while(inf==1&&a<1000) a++;//检测数据是否数据位，a用来防止死机
	if(a==1000) return ;
	
   
   }
  
  
}


void delay6ms()
{
    unsigned char a,b;
    for(b=40;b>0;b--)
        for(a=73;a>0;a--);
}




void delay1ms()
{
   uchar a,b;
    for(b=198;b>0;b--)
       for(a=1;a>0;a--);
}


void delay500us() 
{
    uchar a,b;
    for(b=29;b>0;b--)
        for(a=7;a>0;a--);
}



