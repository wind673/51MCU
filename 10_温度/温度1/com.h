//����
#include<reg51.h>
#define uchar unsigned char 
#define uint unsigned int
#define GROUP_MAX 12

//////////////////////////////////////////////////////////////////
//���Ŷ�����
//LCD
sbit en=P2^7;
sbit rs=P2^6;
sbit rw=P2^5;

//ʱ��
sbit ds_io=P3^4;
sbit ds_ce=P3^5;
sbit ds_sclk=P3^6;

//������
sbit inf=P3^2;

//�¶ȱ���ϵͳ
sbit voice=P3^0;
sbit light1_gre=P2^2;//��1
sbit light1_red=P2^3;//��1
sbit light2_gre=P2^0;//��2
sbit light2_red=P2^1;//��2

//�����Գ۵��¶�Դ����
sbit triffic=P3^7;	//���嵥����

//����
//sbit key1=P1^0;sbit key2=P1^1;sbit key3=P1^2;sbit key4=P1^3;
//sbit key5=P1^4;sbit key6=P1^5;sbit key7=P1^6;
sbit key8=P2^4;//��ʱֻ��һ��



//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
//LCDȫ��
void wdat(uchar dat);
void wdir(uchar dir);
void lcd_init();

//////////////////////////////////////////////////////////////////

//ʱ��ȫ�ֱ���
uchar dsdat[7]={0};

//////////////////////////////////////////////////////////////////
//������ȫ�ֱ���
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
char temper_limit[2][4]={{3,0,0,0},{1,5,0,0}};//��ʼ���¶�����22.00��//��ʼ���¶�����10.00��

//ģ���¶����
char temper1_h=2,temper1_l=5,temper1_0h=0,temper1_0l=0,hundred1=0; 
char temper2_h=2,temper2_l=1,temper2_0h=6,temper2_0l=7,hundred2=0;	
																						
//����ϵͳ
uchar warn_sw1=0,warn_sw2=0;																						

///////////////////////////////////////////////////////////////////
//�¶��Զ��洢
uchar temper_auto_n=0;
uchar temper_auto_x=0;
void temper_save(uchar gr);

																						
//////////////////////////////////////////////////////////////////
//�����Գ۵��¶�Դ����
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

//����Դ����
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