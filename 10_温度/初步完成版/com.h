//����
#include<reg51.h>
#define uchar unsigned char 
#define uint unsigned int
#define GROUP_MAX 12


//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//LCDȫ�ֱ���
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;

void wdat(uchar dat);
void wdir(uchar dir);
void lcd_init();





//////////////////////////////////////////////////////////////////

//ʱ��ȫ�ֱ���
sbit ds_io=P3^4;
sbit ds_ce=P3^5;
sbit ds_sclk=P3^6;
uchar dsdat[7]={0};




//////////////////////////////////////////////////////////////////
//������ȫ�ֱ���

sbit inf=P3^2;
uchar inf_sw=1; 
uchar inf_sure=0;
uchar inf_tag=0;
uchar inf_vo=0;
uchar inf_dat[4]={0};
//uchar sure=0;
//uchar ero[3]={0};


//////////////////////////////////////////////////////////////////
//�¶�ȫ�ֱ���

uchar temper_group=1;
uchar temper_arrow=0;
uchar temper_posi=3;
uchar temper_mode=1;
uchar temper_star=1;
int temper_dat[GROUP_MAX+1][2]={0};
char temper_tim[GROUP_MAX+1][12]={0};
char temper_limit[2][4]={{2,7,0,0},{2,0,0,0}};//��ʼ���¶�����22.00��//��ʼ���¶�����10.00��

//ģ���¶����
char temper1_h=1,temper1_l=7,temper1_0h=2,temper1_0l=1; 
char temper2_h=2,temper2_l=1,temper2_0h=6,temper2_0l=7;	
																						
//����ϵͳ
sbit voice=P3^0;
sbit light1_gre=P2^2;//��1
sbit light1_red=P2^3;//��1

sbit light2_gre=P2^0;//��2
sbit light2_red=P2^1;//��2
uchar warn_sw1=0,warn_sw2=0;																						
																						
//////////////////////////////////////////////////////////////////
//�����Գ۵��¶�Դ����
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
sbit triffic=P3^7;	    //���嵥����
uchar fu=0,hold=0,ma=0;
//uint ge=0,shi=0,bai=0,xi=0;	
uint bai=0;









//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//����Դ����
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