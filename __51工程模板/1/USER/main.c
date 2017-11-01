#include "main.h"
//全局变量区
extern unsigned char receiveData;





//主函数区
int main()
{
	 unsigned char *str;
	lcd_init();
	while(1)
	{
	EEP_Wstr(0X00,"Hello Word!");
	
	lcd_posi(1,1);
 	
	}
	
}



