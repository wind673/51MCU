#include"com.h"



void main()
{
	//��ʼ�������߼�LCD
	
  inf_init();
	lcd_init();	
	zhaochi_main();	 
	//�����Զ����ַ�				
  lcd_custom(0,zi_circle);lcd_custom(1,zi_1);
	lcd_custom(2,zi_2);lcd_custom(3,zi_up);
	lcd_custom(4,zi_down);lcd_custom(5,zi_all);
	
	
	
while(1)
{
   temper_simu();
	 catch_display();	
	 temper_warn();
	 inf_tag=0;//���ñ�־
	 
	 
   if(temper_mode==1)
   {
	 inf_tag=0;//���ñ�־
	 ds_read_main();//��ȡʵʱ�¶�
	 ds_lcd();//��ʾʵʱʱ��
	 ds_lcd01();//��ʾģʽһ�ķ���
	 ds_lcd_temper1();//��ʾʵʱ�¶�
	 }
	 
	 if(temper_mode==2)
	 {
	  inf_tag=0;
	 	ds_lcd02();
	  ds_lcd_temper2();
		
	 }
	 
	if(temper_mode==3)
	 {
	  inf_tag=0;
		
	  
	  ds_lcd03();
		delay100ms();
		posi(2,temper_posi);wdat(' ');
	  
	 }

	
	
	
	
	
	
	
	
	
	
	
}	
}
