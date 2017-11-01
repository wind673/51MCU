#include<reg51.h>
unsigned char  num[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char  np[8]={0x00,0x20,0x40,0x60,0x80,0xa0,0xc0,0xe0};
void main()
{
unsigned int i;
int j=0;
int  k;
int su=0;
int s=0,ss=0;

while(1)
{   
	j++;
	s++;
	if(s==100)
	s=0,ss++;
	
	if(j==200)
      su++,j=0;
	 if(su==10)
	    su=0;
		 if(ss==10)
	    ss=0;
    for(i=0;i<8;i++)//ÏÔÊýÑ­»·
    {
	P1=np[i];
	if(i==2)
	{
	P0=num[su];
	}
	if(i==6)
	P0=num[ss];
	k=100;
	while(k--);
	P0=0x00;
	}
}
}
