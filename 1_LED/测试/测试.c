#include<reg51.h>
unsigned char code num[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char code np[8]={0x00,0x20,0x40,0x60,0x80,0xa0,0xc0,0xe0};
void main()
{
unsigned int i;
int sj=0;
int jj=0;
int k;

while(1)
{   
	jj++; 
	if(jj>=600)
	 sj++;
	 if(sj==10) sj=0;
    for(i=0;i<8;i++)//ÏÔÊýÑ­»·
    {
	P1=np[i];
	if(i==2)
    P0=num[sj];
	if(sj>3) 
	sj=sj+1;
	if(i==6)
	P0=num[6];
	k=100;
	while(k--);
	P0=0x00;
	}
}
}
