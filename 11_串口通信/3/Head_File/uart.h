#ifndef __UART_H
#define  __UART_H

#include <reg51.h>
#include "lcd.h"

#ifndef  __uchar
#define  __uchar
#define uchar unsigned char 
#define uint unsigned int
#endif


#define GPIO_DIG P0

extern unsigned char receiveData[20];	
extern unsigned char uart_tag; 

void Usart_init();

void uart_send(unsigned char ch);
void uart_send_str(unsigned char *str);














#endif

