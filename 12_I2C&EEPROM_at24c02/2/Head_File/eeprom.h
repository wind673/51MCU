#ifndef __EEPROM_H
#define __EEPROM_H


#include<reg51.h>
#include "i2c.h"
#include "delay.h"

//--声明全局函数--//


void EEP_Write(unsigned char addr,unsigned char dat);
unsigned char EEP_Read(unsigned char addr);
void EEP_Wstr(unsigned char addr,unsigned char *str);
void EEP_Rstr(unsigned char addr,unsigned char *str);

#endif