#include<com.h>

void main()
{
   
   
   lcd_init();
    posi(1,5);
   wdat(0x35);
    posi(2,7);
   wdat(0x37);
   while(1);
}