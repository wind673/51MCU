#include<reg51.h>
#define uint unsigned int
sbit n0=P1^0;sbit n1=P1^1;sbit n2=P1^2;sbit n3=P1^3;
sbit n4=P1^4;sbit n5=P1^5;sbit n6=P1^6;sbit n7=P1^7;
int a[8]={0},i;
int delay(int j);
void main()
{
  int k=0;
  while(1)
  {
   
   
   for(i=0;i<8;i++)
   {
     a[i]=0;  
   }
   a[k]=1;
   delay(5);
   n0=a[0]; n1=a[1]; n2=a[2]; n3=a[3];
   n4=a[4]; n5=a[5]; n6=a[6]; n7=a[7];
   k++;
   if(k==8)
   k=0;
  }
}

int delay(int j)
{
 int s=j*10000;
 while(s--);
}