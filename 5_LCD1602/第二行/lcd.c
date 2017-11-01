//LCDœ‘ æ


sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;
void wdat(uchar dat);
void wdir(uchar dir);
void lcd_init();

void lcd_init()
{
  wdir(0x38);
  wdir(0x0c);
  wdir(0x01);
  wdir(0x06);
  wdir(0x80);
}

void wdat(uchar dat)
{
  en=0;
  rw=0;
  rs=1;
  P0=dat;
  en=1;
  delay10ms();
  en=0;
  
}

void wdir(uchar dir)
{
  en=0;
  rw=0;
  rs=0;
  P0=dir;
  en=1;
  delay10ms();
  en=0;
  
}

void posi(uint line,uint x)
{ 
  x--;
  if(line==1) wdir(0x80+x);
  if(line==2) wdir(0xc0+x);
  
}

