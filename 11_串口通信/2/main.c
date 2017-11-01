#include "main.h"



int main()
{
	lcd_init();
	UsartConfiguration();
	while(1)
	{
	posi(1,1);
	wdat(receiveData);
	
	}
}


