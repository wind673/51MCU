//LCD显示


sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;
void wdat(uchar dat);
void wdir(uchar dir);
void lcd_init();

void lcd_init()
{
  wdir(0x38);//显示模式
  wdir(0x0f);//显示开关及光标
  wdir(0x01);//清屏
  wdir(0x06);//光标屏幕是否移动
  wdir(0x80);//初始光标化位置
}

void wdat(uchar dat)//写数据
{
  en=0;
  rw=0;
  rs=1;
  P0=dat;
  en=1;
  delay10ms();
  en=0;
  
}

void wdir(uchar dir)//写命令
{
  en=0;
  rw=0;
  rs=0;
  P0=dir;
  en=1;
  delay10ms();
  en=0;
  
}

void posi(uchar line,uchar x)//选坐标
{ 
  x--;
  if(line==1) wdir(0x80+x);
  if(line==2) wdir(0xc0+x);
  
}

