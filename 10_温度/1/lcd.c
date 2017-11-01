//LCD��ʾ



void lcd_init()
{
  wdir(0x38);//��ʾģʽ
  wdir(0x0c);//��ʾ���ؼ����
  wdir(0x01);//����
  wdir(0x06);//�����Ļ�Ƿ��ƶ�
  wdir(0x80);//��ʼ��껯λ��
}

void lcd_custom(uchar num,uchar *word)//numΪ��num����
{
   uchar i,temp;
   num=num*8;
   for(i=0;i<8;i++)
   {
   temp=0x40+i+num;
   wdir(temp);
   wdat(word[i]);
   }
}

void wdat(uchar dat)//д����
{
  en=0;
  rw=0;
  rs=1;
  P0=dat;
  en=1;
  delay10ms();
  en=0;
  
}

void wdir(uchar dir)//д����
{
  en=0;
  rw=0;
  rs=0;
  P0=dir;
  en=1;
  delay10ms();
  en=0;
  
}

void posi(uchar line,uchar x)//ѡ����
{ 
  x--;
  if(line==1) wdir(0x80+x);
  if(line==2) wdir(0xc0+x);
  
}

