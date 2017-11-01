#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
unsigned char code nnum[10]={0x3f,0x06,0x5b,0x4f,0x66,
                             0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char code pnum[10]={0xc0,0xf9,0xa4,0xb0,0x99,
                             0x92,0x82,0xf8,0x80,0x90};  

sbit iterr=P3^2;						 
sbit voice=P1^4;
sbit LSA=P1^5;
sbit LSB=P1^6;
sbit LSC=P1^7;
sbit key1=P2^1;
sbit key2=P2^0;
sbit key5=P2^2;
sbit key7=P2^7;
sbit spot=P0^7;
void music(unsigned char h);
void ddisplay(unsigned int ddi,unsigned int i);
void sdisplay(unsigned int sdi);
void interrupts();
void key();
char sw=0;
char reset=0;
uint time=0;

void main()
{
   
	
	
    uint tms=0,ts=0,tm=0,th=0,td=0;//此处tms为100ms
	uint dtms=0,dts1=0,dtm1=0,dth1=0,dtd1=0;//低位
	uint dts2=0,dtm2=0,dth2=0,dtd2=0;//高位
	uint di[8],i;
	interrupts();
while(1)
{
     
	// key();
	 if(reset==1)//复位
	 {
	 reset=0;
	 tms=0,ts=0,tm=0,th=0,td=0;//复位时间
	 di[1]=0;di[0]=0;//复位显示
	 di[3]=0;di[2]=0;
	 di[5]=0;di[4]=0;
	 di[7]=0;di[6]=0;dtms=0;
	 }
	 //时间模拟
	 if(sw==1)
	 {
	 tms++;
	 if(tms==5) ts++,tms=0;
	 if(ts==60) tm++,ts=0;
	 if(tm==60) th++,tm=0;
	 if(th==24) td++,th=0;
	 }
	 //数据处理
	 /*低位处理*/
	 dts1=ts%10;
	 dtm1=tm%10;
	 dth1=th%10;
	 dtd1=td%10;
	 /*高位处理*/
	 dts2=ts/10;
	 dtm2=tm/10;
	 dth2=th/10;
	 dtd2=td/10;
	 dtms=tms/20;
	//数据传递 
	 di[1]=dtd1;di[0]=dtd2;
	 di[3]=dth1;di[2]=dth2;
	 di[5]=dtm1;di[4]=dtm2;
	 di[7]=dts1;di[6]=dts2;	 
	//显示输出
	for(i=0;i<8;i++)//动态	
	ddisplay(di[i],i);
	
}
}    
	
	
void interrupts()
{
 TMOD=0X01;
 TH0=(65536-50000)/256;
 TL0=(65536-50000)%256;//11.915Mhz的粗略50ms
 IT0=1;
 EX0=1;
 ET0=1;
 EA=1;
 TR0=1;
 
}

void interrupt0()interrupt 0
{
  uint i;
  while(iterr==0)
  for(i=0;i<8;i++)
    {
	
	switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(3):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(4):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(5):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(6):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(7):
				LSA=1;LSB=1;LSC=1; break;//显示第7位	
		 		
		}
		P0=0XFF;
	  }
  
  sw=0;
  reset=1;
}

void wdog()interrupt 1//自制看门狗
{
  time++;
  if(time>120)
  { 
    sw=0;
    reset=1;
	time=0;
  }
  TH0=(65536-50000)/256;
  TL0=(65536-50000)%256;
}



void ddisplay(unsigned int ddi,unsigned int i)//动态显示dynamic
{

	unsigned int j;
	
	
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(3):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(4):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(5):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(6):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(7):
				LSA=1;LSB=1;LSC=1; break;//显示第7位	
		}
	
		if((i==1||i==3||i==5||i==7)||(ddi!=0))
		{
		P0=nnum[ddi];//发送段码
		}
		if(i==1||i==3||i==5||i==7)
		spot=1;
		j=100;						 //扫描间隔时间设定
		while(j--);	
		P0=0x00;//消隐
	

}
void key()//按键
{
   uint re,mu,mus;
//复位
   if(key5==0)
   {
   re=100;
   while(re--);
    if(key5==0)
    {
	sw=0;
    reset=1;
	for(mus=0;mus<2;mus++)
	for(mu=7+mus;mu<9+mus;mu++)	
	music(mu); 
  
    }
  
   }
//开始 
   if(sw==0)
   if(key1==0)
   {  
       re=100;
       while(re--);
	   
       if(key1==0)
	   {
	   music(4);
	   music(5);
	   sw=1;
	    
	   }
   }
 
//结束
   if(sw==1)
   if(key2==0)
   {  
       re=100;
       while(re--);
       if(key2==0)
	   {
	   sw=0;
	   music(6);
	   music(7);
	   music(6);
	  
	   }
   }
   
   if(key7==0)
   {
    re=100;
    while(re--);
    time=0;
   }
}
	


void music(unsigned char h)
 {
 int mu,del;
 for(mu=0;mu<80;mu++)
   {
   del=35*h;
    while(del--);
   voice=0;
    del=4*h;
    while(del--);
   voice=1; 
   }  
 }

