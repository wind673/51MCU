//调用LCD模块显示温度和时间




void ds_lcd_temper1()
{
	posi(2,4);wdat(0x30+temper1_h);wdat(0x30+temper1_l);
	posi(2,7);wdat(0x30+temper1_0h);wdat(0x30+temper1_0l);
	posi(2,10);wdat(0x30+temper2_h);wdat(0x30+temper2_l);
	posi(2,13);wdat(0x30+temper2_0h);wdat(0x30+temper2_0l);
	

}


void ds_lcd_temper2()
{	
	uint temp;
   //显示年

	 posi(1,2);
	 temp=0x30+temper_tim[temper_group][0];
	 wdat(temp);
	 temp=0x30+temper_tim[temper_group][1];
	 wdat(temp);
   //显示月
   temp=0x30+temper_tim[temper_group][2];
	 wdat(temp);
	 temp=0x30+temper_tim[temper_group][3];
	 wdat(temp);
     //显示日
   temp=0x30+temper_tim[temper_group][4];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][5];
	 wdat(temp);
 //显示时，24h的显示方式
   temp=0x30+temper_tim[temper_group][6];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][7];
   wdat(temp);
   //显示分
    temp=0x30+temper_tim[temper_group][8];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][9];
   wdat(temp);
   
   //显示秒

   temp=0x30+temper_tim[temper_group][10];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][11];
   wdat(temp);
 
	
	 //温度1数据  
	 posi(2,4);
	 wdat(0x30+temper_dat[temper_group][0][0]);
	 wdat(0x30+temper_dat[temper_group][0][1]);
 	 posi(2,7);
	 wdat(0x30+temper_dat[temper_group][0][2]);
	 wdat(0x30+temper_dat[temper_group][0][3]);
	 
	 //温度2数据  
	 posi(2,10);
	 wdat(0x30+temper_dat[temper_group][1][0]);
	 wdat(0x30+temper_dat[temper_group][1][1]);
	 posi(2,13);
	 wdat(0x30+temper_dat[temper_group][1][2]);
	 wdat(0x30+temper_dat[temper_group][1][3]);
	

}


	
	
void ds_lcd01()//1模式符号显示
{
  posi(1,1);
  wdat(0);//显示字符◎
  posi(1,8);wdat(' ');posi(1,11);wdat(':');posi(1,14);wdat(':');
  posi(2,1);wdat(' ');wdat(' ');
  posi(2,3);wdat(1);posi(2,9);wdat(2);
  posi(2,16);wdat(' ');
  posi(2,4);            //温度1.0显示
  posi(2,6);wdat('.');  //小数点
  posi(2,7);            //温度0.1显示
  
  posi(2,10);			//温度2.0显示
  posi(2,12);wdat('.');  //小数点
  posi(2,13);			//温度0.2显示
  
  posi(2,15);wdat(' ');
  
  
}

void ds_lcd02()//2模式符号显示
{
 posi(1,1);
  wdat(' ');
  posi(1,8);wdat(' ');posi(1,11);wdat(':');posi(1,14);wdat(':');
  posi(2,1);wdat('G');wdat(0x30+temper_group);
  posi(2,3);wdat(1);posi(2,9);wdat(2);
  posi(2,16);wdat(3+temper_arrow);//显示上下箭头
  posi(2,4);            //温度1.0显示
  posi(2,6);wdat('.');  //小数点
  posi(2,7);            //温度0.1显示
  
  posi(2,10);			//温度2.0显示
  posi(2,12);wdat('.');  //小数点
  posi(2,13);			//温度0.2显示
  
  posi(2,15);wdat(' ');
  
  
  
}

