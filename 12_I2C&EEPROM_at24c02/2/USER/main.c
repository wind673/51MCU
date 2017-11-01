#include "main.h"
#define EEPROM_DATA "Data:Hello!!"
//全局变量区
extern unsigned char receiveData;//usart received datas





//主函数区
int main()
{
	unsigned char *str=NULL;
	lcd_init();
	
	lcd_posi(1,1);
	lcd_str("Loading..."); 
	EEP_Wstr(0x00,EEPROM_DATA);
	while(1)
	{
	  
		EEP_Rstr(0x00,str);
		  
		lcd_posi(2,1);
		lcd_str(str);
		
		lcd_posi(1,1);
		lcd_str("JUST OK!!!");
	
	
	}
}



