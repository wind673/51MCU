#ifndef __UART_H
#define  __UART_H
#include<reg51.h>

#ifndef  __uchar
#define  __uchar
#define uchar unsigned char 
#define uint unsigned int
#endif


#define GPIO_DIG P0

extern unsigned char receiveData;	




void Usart_init();















#endif

