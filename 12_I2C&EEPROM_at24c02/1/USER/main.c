#include "main.h"
//全局变量区
extern unsigned char receiveData;//usart received datas





//主函数区
int main()
{
	unsigned char *str="Ha ha ha ha";
	lcd_init();
	
	lcd_posi(1,1);
	lcd_str("Loading...");
	while(1)
	{
	  EEP_Wstr(0x00,str);
	  EEP_Rstr(0x00,str);
	  
	lcd_posi(2,1);
	lcd_str(str);
	
	lcd_posi(1,1);
	lcd_str("JUST OK!!!");
	
	
	}
}



