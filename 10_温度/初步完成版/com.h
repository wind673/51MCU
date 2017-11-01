//公用
#include<reg51.h>
#define uchar unsigned char 
#define uint unsigned int
#define GROUP_MAX 12


//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//LCD全局变量
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;

void wdat(uchar dat);
void wdir(uchar dir);
void lcd_init();





//////////////////////////////////////////////////////////////////

//时钟全局变量
sbit ds_io=P3^4;
sbit ds_ce=P3^5;
sbit ds_sclk=P3^6;
uchar dsdat[7]={0};




//////////////////////////////////////////////////////////////////
//红外线全局变量

sbit inf=P3^2;
uchar inf_sw=1; 
uchar inf_sure=0;
uchar inf_tag=0;
uchar inf_vo=0;
uchar inf_dat[4]={0};
//uchar sure=0;
//uchar ero[3]={0};


//////////////////////////////////////////////////////////////////
//温度全局变量

uchar temper_group=1;
uchar temper_arrow=0;
uchar temper_posi=3;
uchar temper_mode=1;
uchar temper_star=1;
int temper_dat[GROUP_MAX+1][2]={0};
char temper_tim[GROUP_MAX+1][12]={0};
char temper_limit[2][4]={{2,7,0,0},{2,0,0,0}};//初始化温度上限22.00℃//初始化温度下限10.00℃

//模拟温度输出
char temper1_h=1,temper1_l=7,temper1_0h=2,temper1_0l=1; 
char temper2_h=2,temper2_l=1,temper2_0h=6,temper2_0l=7;	
																						
//报警系统
sbit voice=P3^0;
sbit light1_gre=P2^2;//绿1
sbit light1_red=P2^3;//红1

sbit light2_gre=P2^0;//绿2
sbit light2_red=P2^1;//红2
uchar warn_sw1=0,warn_sw2=0;																						
																						
//////////////////////////////////////////////////////////////////
//兼容赵驰的温度源程序
#define shi temper1_h
#define ge	temper1_l
#define xi  temper1_0h
# include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};    
sbit triffic=P3^7;	    //定义单总线
uchar fu=0,hold=0,ma=0;
//uint ge=0,shi=0,bai=0,xi=0;	
uint bai=0;









//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//汇总源程序
#include"simulate.c"
# include"ds18b20.h" 	
#include"wendu.c"		
#include"zi.h"
#include"delay.c"
#include"lcd.c"
#include"ds1302.c"
#include"inf_fun.c"
#include"infrared.c"
#include"temper_fun.c"
#include"temper_show.c"



//////////////////////////////////////////////////////////////////