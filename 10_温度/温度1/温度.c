#include"com.h"

void main()
{

	//ds_write_main(); //调时间

	//初始化红外线、LCD及兼容赵驰的程序
	zhaochi_main(); 
  inf_init();//红外线的初始化	 
	lcd_init();	//LCD的初始化	 
	
	//存入自定义字符				
  lcd_custom(0,zi_circle);lcd_custom(1,zi_1);
	lcd_custom(2,zi_2);lcd_custom(3,zi_up);
	lcd_custom(4,zi_down);lcd_custom(5,zi_all);
	lcd_custom(7,zi_10);//百位
	
	//开机音乐
	temper_alarm(3);
	temper_alarm(1);
	temper_alarm(2);
	
while(1)
{
	 zhaochi_main();//兼容温度模块 
	 key_board();//键盘 
     light();//灯光系统 
	 error_start();//判断开机时的不稳定事件，并恢复至可接受范围
	 ds_read_main();//读取实时时间
	 key_board();
	 temper_warn();//警报系统
	 inf_tag=0;//重置标志
	 key_board();
	 
	 
   if(temper_mode==1)//显示模式1 
   {
	 inf_tag=0;//重置标志，防止多次读入 
	 ds_lcd();//显示实时时间
	 key_board();
	 ds_lcd01();//显示模式一的符号
	 key_board();
	 ds_lcd_temper1();//显示实时温度
	
	 }
	 
	 key_board();
	 if(temper_mode==2)//显示模式2 
	 {
	  inf_tag=0;
	 	ds_lcd02();
		key_board();
	  ds_lcd_temper2();
		key_board();
	
	 }
	key_board();
	 if(temper_mode==3)//显示模式3
	 {
	  inf_tag=0;
	  ds_lcd03();
		key_board();
		posi(2,temper_posi);wdat(' ');
	
	 }
	 key_board();
	 if(temper_auto_n==3) temper_auto_n=0;//防止重复写入同一组数据
	 temper_auto();//自动存储系统
	 key_board();
	
	
}	
}
