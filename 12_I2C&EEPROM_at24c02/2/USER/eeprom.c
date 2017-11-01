#include "eeprom.h"

void EEP_Write(unsigned char addr,unsigned char dat)
{
	I2C_Start();
	I2C_SendByte(0xa0, 1);//发送写器件命令，1代表从机需要应答响应
	I2C_SendByte(addr, 1);//发送要写入内存地址
	I2C_SendByte(dat, 0);	//发送数据，0代表从机不需要应答响应
	I2C_Stop();
	delay10ms();
}

unsigned char EEP_Read(unsigned char addr)
{
	unsigned char num;
	I2C_Start();
	I2C_SendByte(0xa0, 1); //发送写器件地址
	I2C_SendByte(addr, 1); //发送要读取的地址
	I2C_Start();
	I2C_SendByte(0xa1, 1); //发送读器件地址
	num=I2C_ReadByte(); //读取数据
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

