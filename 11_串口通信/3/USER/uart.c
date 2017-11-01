#include "uart.h"

unsigned char uart_tag; 
unsigned char receiveData[20];
	 
	 
void Usart_init()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=0xF3;				//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XF3;
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					//�򿪼�����
   
}


void uart_send(unsigned char ch)
{

	SBUF=ch;//�����յ������ݷ��뵽���ͼĴ���
    while(!TI);			 //�ȴ������������
	TI=0;	    	 //���������ɱ�־λ
	
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
	
    RI = 0;//��������жϱ�־λ
	receiveData[uart_tag++]=SBUF;//��ȥ���յ�������

}




