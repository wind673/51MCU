#include "main.h"
//ȫ�ֱ�����
extern unsigned char receiveData;





//��������
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



