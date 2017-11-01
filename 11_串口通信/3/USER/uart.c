#include "uart.h"

unsigned char uart_tag; 
unsigned char receiveData[20];
	 
	 
void Usart_init()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0xF3;				//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
   
}


void uart_send(unsigned char ch)
{

	SBUF=ch;//将接收到的数据放入到发送寄存器
    while(!TI);			 //等待发送数据完成
	TI=0;	    	 //清除发送完成标志位
	
}

void uart_send_str(unsigned char *str)
{
	while(*str)	
	{

	uart_send(*(str++));
	
	}
	
}



void Usart() interrupt 4
{
	
    RI = 0;//清除接收中断标志位
	receiveData[uart_tag++]=SBUF;//出去接收到的数据

}




