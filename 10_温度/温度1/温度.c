#include"com.h"

void main()
{

	//ds_write_main(); //��ʱ��

	//��ʼ�������ߡ�LCD�������Գ۵ĳ���
	zhaochi_main(); 
  inf_init();//�����ߵĳ�ʼ��	 
	lcd_init();	//LCD�ĳ�ʼ��	 
	
	//�����Զ����ַ�				
  lcd_custom(0,zi_circle);lcd_custom(1,zi_1);
	lcd_custom(2,zi_2);lcd_custom(3,zi_up);
	lcd_custom(4,zi_down);lcd_custom(5,zi_all);
	lcd_custom(7,zi_10);//��λ
	
	//��������
	temper_alarm(3);
	temper_alarm(1);
	temper_alarm(2);
	
while(1)
{
	 zhaochi_main();//�����¶�ģ�� 
	 key_board();//���� 
     light();//�ƹ�ϵͳ 
	 error_start();//�жϿ���ʱ�Ĳ��ȶ��¼������ָ����ɽ��ܷ�Χ
	 ds_read_main();//��ȡʵʱʱ��
	 key_board();
	 temper_warn();//����ϵͳ
	 inf_tag=0;//���ñ�־
	 key_board();
	 
	 
   if(temper_mode==1)//��ʾģʽ1 
   {
	 inf_tag=0;//���ñ�־����ֹ��ζ��� 
	 ds_lcd();//��ʾʵʱʱ��
	 key_board();
	 ds_lcd01();//��ʾģʽһ�ķ���
	 key_board();
	 ds_lcd_temper1();//��ʾʵʱ�¶�
	
	 }
	 
	 key_board();
	 if(temper_mode==2)//��ʾģʽ2 
	 {
	  inf_tag=0;
	 	ds_lcd02();
		key_board();
	  ds_lcd_temper2();
		key_board();
	
	 }
	key_board();
	 if(temper_mode==3)//��ʾģʽ3
	 {
	  inf_tag=0;
	  ds_lcd03();
		key_board();
		posi(2,temper_posi);wdat(' ');
	
	 }
	 key_board();
	 if(temper_auto_n==3) temper_auto_n=0;//��ֹ�ظ�д��ͬһ������
	 temper_auto();//�Զ��洢ϵͳ
	 key_board();
	
	
}	
}
