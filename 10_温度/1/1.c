#include"com.h"



int main()
{
	//��ʼ�������߼�LCD
  inf_init();
	lcd_init();	 
	//�����Զ����ַ�				
  lcd_custom(0,zi_circle);lcd_custom(1,zi_1);
	lcd_custom(2,zi_2);lcd_custom(3,zi_up);
	lcd_custom(4,zi_down);lcd_custom(5,zi_all);
	
	
	
while(1)
{
  temper_simu();
	
	ds_lcd();//��ʾʵʱʱ��

	 ds_lcd();//��ʾʵʱʱ��
	 ds_lcd01();//��ʾģʽһ�ķ���
	 ds_lcd_temper1();//��ʾʵʱ�¶�

	
	
	
}	
}
