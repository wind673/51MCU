//ÑÓÊ±

void delay1ms();
void delay500us();
void delay6ms();
void delay100us();
void delay10ms();


void delay6ms()
{
    uchar a,b;
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

void delay100us()
{
    unsigned char a;
    for(a=48;a>0;a--);
}

void delay10ms()
{
    unsigned char a,b,c;
    for(c=2;c>0;c--)
        for(b=160;b>0;b--)
            for(a=14;a>0;a--);
}
