#include "eeprom.h"

void EEP_Write(unsigned char addr,unsigned char dat)
{
	I2C_Start();
	I2C_SendByte(0xa0, 1);//����д�������1����ӻ���ҪӦ����Ӧ
	I2C_SendByte(addr, 1);//����Ҫд���ڴ��ַ
	I2C_SendByte(dat, 0);	//�������ݣ�0����ӻ�����ҪӦ����Ӧ
	I2C_Stop();
	delay10ms();
}

unsigned char EEP_Read(unsigned char addr)
{
	unsigned char num;
	I2C_Start();
	I2C_SendByte(0xa0, 1); //����д������ַ
	I2C_SendByte(addr, 1); //����Ҫ��ȡ�ĵ�ַ
	I2C_Start();
	I2C_SendByte(0xa1, 1); //���Ͷ�������ַ
	num=I2C_ReadByte(); //��ȡ����
	I2C_Stop();
	delay10ms();
	return num;	
	
}

void EEP_Wstr(unsigned char addr,unsigned char *str)
{
	while(*str)
	{
	
		EEP_Write(addr++,*str);
		str++;
	
	}
	

}

void EEP_Rstr(unsigned char addr,unsigned char *str)
{

	while(*str)
	{
		
		*str=EEP_Read(addr++);
		 str++;
	}
	
	
	
}

