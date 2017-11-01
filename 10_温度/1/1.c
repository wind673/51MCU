#include"com.h"



int main()
{
	//初始化红外线及LCD
  inf_init();
	lcd_init();	 
	//存入自定义字符				
  lcd_custom(0,zi_circle);lcd_custom(1,zi_1);
	lcd_custom(2,zi_2);lcd_custom(3,zi_up);
	lcd_custom(4,zi_down);lcd_custom(5,zi_all);
	
	
	
while(1)
{
  temper_simu();
	
	ds_lcd();//显示实时时间

	 ds_lcd();//显示实时时间
	 ds_lcd01();//显示模式一的符号
	 ds_lcd_temper1();//显示实时温度

	
	
	
}	
}
