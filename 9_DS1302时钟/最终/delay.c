//��ʱ

void delay300ms()  
{
    unsigned char a,b,c;
    for(c=177;c>0;c--)
        for(b=240;b>0;b--)
            for(a=2;a>0;a--);
}








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