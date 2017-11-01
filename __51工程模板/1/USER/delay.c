#include "delay.h"



//LCD延时所用
void delay10ms() 
{
    unsigned char a,b,c;
    for(c=2;c>0;c--)
        for(b=160;b>0;b--)
            for(a=14;a>0;a--);
}

void delay700us()  
{
    unsigned char a,b;
    for(b=4;b>0;b--)
        for(a=85;a>0;a--);
}


//I2C延时所用
void delay10us()
{
	unsigned char a, b;
	for(b=1; b>0; b--)
	{
		for(a=2; a>0; a--);
	}
}


