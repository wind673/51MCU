#include "delay.h"



//LCDÑÓÊ±ËùÓÃ
void delay10ms() 
{
    unsigned char a,b,c;
    for(c=2;c>0;c--)
        for(b=160;b>0;b--)
            for(a=14;a>0;a--);
}




