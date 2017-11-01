#include "main.h"


	 



int main()
{
	Usart_init();uart_tag=0;
	lcd_init();
	posi(1,1);
	lcd_str("Linking...");
  	uart_send_str("Linking...");
	while(1)
	{
	
	//«Â∆¡÷∏¡Ó  :CLS
	if(receiveData[0]==':'&&receiveData[1]=='C'&&receiveData[2]=='L'&&receiveData[3]=='S')
	{
	posi(2,1); 
	lcd_str("                     ");
	uart_tag=0;  
	receiveData[0]=';';
	uart_tag=0;
	}	
	else
	{
	posi(2,1);
    lcd_str(receiveData);
	uart_tag=0;
	}


	
	
	}
	
}



