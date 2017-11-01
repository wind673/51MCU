//公用
#include<reg51.h>
#define uchar unsigned char 
#define uint unsigned int

//////////////////////////////////////////////////////////////////

//时钟全局变量
sbit ds_io=P3^4;
sbit ds_ce=P3^5;
sbit ds_sclk=P3^6;
uchar dsdat[7]={0};




//////////////////////////////////////////////////////////////////

//温度全局变量
uchar temper_mode=1;
uchar temper_group=1;
uchar temper_arrow=0;

uchar temper1_h=1,temper1_l=1,temper1_0h=1,temper1_0l=1;
uchar temper2_h=1,temper2_l=1,temper2_0h=1,temper2_0l=1;

uchar temper_dat[10][2][4],temper_tim[10][12];

//////////////////////////////////////////////////////////////////



//红外线全局变量
sbit inf=P3^2;
//uchar sure=0;
//uchar ero[3]={0};
uchar inf_dat[4]={0};
uchar inf_sure=0;
uchar fcmode=0;
uchar inf_sw=1; 
uchar inf_t=1;




//////////////////////////////////////////////////////////////////


//LCD全局变量
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;

void wdat(uchar dat);
void wdir(uchar dir);
void lcd_init();





//////////////////////////////////////////////////////////////////








//汇总源程序
#include"simulate.c"	
#include"zi.h"
#include"delay.c"
#include"lcd.c"
#include"ds1302.c"
#include"inf_fun.c"
#include"infrared.c"
#include"temper_show.c"


