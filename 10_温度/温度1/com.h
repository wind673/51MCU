//公用
#include<reg51.h>
#define uchar unsigned char 
#define uint unsigned int
#define GROUP_MAX 12

//////////////////////////////////////////////////////////////////
//引脚定义区
//LCD
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;

//时钟
sbit ds_io=P3^4;
sbit ds_ce=P3^5;
sbit ds_sclk=P3^6;

//红外线
sbit inf=P3^2;

//温度报警系统
sbit voice=P3^0;
sbit light1_gre=P2^2;//绿1
sbit light1_red=P2^3;//红1
sbit light2_gre=P2^0;//绿2
sbit light2_red=P2^1;//红2

//兼容赵驰的温度源程序
sbit triffic=P3^7;	//定义单总线

//按键
//sbit key1=P1^0;sbit key2=P1^1;sbit key3=P1^2;sbit key4=P1^3;
//sbit key5=P1^4;sbit key6=P1^5;sbit key7=P1^6;
sbit key8=P2^4;//暂时只用一个



//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
//LCD全局
void wdat(uchar dat);
void wdir(uchar dir);
void lcd_init();

//////////////////////////////////////////////////////////////////

//时钟全局变量
uchar dsdat[7]={0};

//////////////////////////////////////////////////////////////////
//红外线全局变量
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
char temper_limit[2][4]={{3,0,0,0},{1,5,0,0}};//初始化温度上限22.00℃//初始化温度下限10.00℃

//模拟温度输出
char temper1_h=2,temper1_l=5,temper1_0h=0,temper1_0l=0,hundred1=0; 
char temper2_h=2,temper2_l=1,temper2_0h=6,temper2_0l=7,hundred2=0;	
																						
//报警系统
uchar warn_sw1=0,warn_sw2=0;																						

///////////////////////////////////////////////////////////////////
//温度自动存储
uchar temper_auto_n=0;
uchar temper_auto_x=0;
void temper_save(uchar gr);

																						
//////////////////////////////////////////////////////////////////
//兼容赵驰的温度源程序
#define shi temper1_h
#define ge temper1_l
#define xi_1  temper1_0h
#define xi_2  temper1_0l

#define sh temper2_h
#define g temper2_l
#define x_1  temper2_0h
#define x_2  temper2_0l  
uchar fu=0,hold=0,ma=0;
uchar start_error1=0,start_error2=0;
int temp1=0,temp2=0;

uchar  a[5];

uchar code xu_1[]={0x28,0xe9,0x4f,0x9b,0x06,0x00,0x00,0x83};
uchar code xu_2[]={0x28,0xff,0xd5,0x4b,0x73,0x04,0x00,0x80};






//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//汇总源程序
#include"delay.c"
#include"wendu.c"		
#include"zi.h"
#include"lcd.c"
#include"ds1302.c"
#include"temper_fun.c"
#include"inf_fun.c"
#include"infrared.c"
#include"temper_show.c"
#include"key_bo.c"
#include"temper_auto.c"



//////////////////////////////////////////////////////////////////