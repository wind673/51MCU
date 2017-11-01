#include"com.h"
uchar unlcd=1;

void main()
{
   //ds_write_main();
   lcd_init();
   inf_init();
   lcd_custom(0,nian);
   lcd_custom(1,yue);
   lcd_custom(2,ri);
   
  
   
while(1)
{ 
   //Ñ¡ÔñÄ£Ê½
   if(fcmode==1)
   {
   if(unlcd==1)
   {lcd_init();ds_lcd01();unlcd=2;}
   ds_read_main();
   ds_lcd1(); 
   }
  
   if(fcmode==2)
   {
   if(unlcd==2)
     {lcd_init();ds_lcd02();unlcd=1;}
      ds_read_main();
      ds_lcd2();
   }
   
}

}



