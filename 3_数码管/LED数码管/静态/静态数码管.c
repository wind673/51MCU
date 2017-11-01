#include<reg51.h>
#define uint unsigned int
char code num[10]={0xc0,0xf9,0xa4,0xb0,0x99,
                   0x92,0x82,0xf8,0x80,0x90};
void delays(uint s);


int main() 
{
  uint i=0;
  while(1)
  {
  P0=num[i];
  if(i==0) delays(3);
  delays(1);//´ÖÂÔÑÓ³Ù1s
  i++;
  if(i==10) i=0;
  
  }
}



  void delays(uint s)  
{
    unsigned char a,b,c;
	while(s--)
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
}

