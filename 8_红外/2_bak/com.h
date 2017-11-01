//公用程序
#ifndef uchar
#define uchar unsigned char 
#endif
#ifndef uint
#define uint unsigned int
#endif
//延时
void delay1ms();
void delay500us();
void delay6ms();

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

