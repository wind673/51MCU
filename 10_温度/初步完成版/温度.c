#include"com.h"



void main()
{
	//初始化红外线及LCD
	
  inf_init();
	lcd_init();	
	zhaochi_main();	 
	//存入自定义字符				
  lcd_custom(0,zi_circle);lcd_custom(1,zi_1);
	lcd_custom(2,zi_2);lcd_custom(3,zi_up);
	lcd_custom(4,zi_down);lcd_custom(5,zi_all);
	
	
	
while(1)
{
   temper_simu();
	 catch_display();	
	 temper_warn();
	 inf_tag=0;//重置标志
	 
	 
   if(temper_mode==1)
   {
	 inf_tag=0;//重置标志
	 ds_read_main();//读取实时温度
	 ds_lcd();//显示实时时间
	 ds_lcd01();//显示模式一的符号
	 ds_lcd_temper1();//显示实时温度
	 }
	 
	 if(temper_mode==2)
	 {
	  inf_tag=0;
	 	ds_lcd02();
	  ds_lcd_temper2();
		
	 }
	 
	if(temper_mode==3)
	 {
	  inf_tag=0;
		
	  
	  ds_lcd03();
		delay100ms();
		posi(2,temper_posi);wdat(' ');
	  
	 }

	
	
	
	
	
	
	
	
	
	
	
}	
}
