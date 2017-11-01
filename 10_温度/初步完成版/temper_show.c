//调用LCD模块显示温度和时间




void ds_lcd_temper1()//显示实时温度
{
	posi(2,4);wdat(0x30+temper1_h);wdat(0x30+temper1_l);
	posi(2,7);wdat(0x30+temper1_0h);wdat(0x30+temper1_0l);
	posi(2,10);wdat(0x30+temper2_h);wdat(0x30+temper2_l);
	posi(2,13);wdat(0x30+temper2_0h);wdat(0x30+temper2_0l);
	

}


	
void ds_lcd01()//1模式符号显示
{
  posi(1,1);
  wdat(0);//显示字符◎
  posi(1,8);wdat(' ');posi(1,11);wdat(':');posi(1,14);wdat(':');
  posi(2,1);wdat(' ');wdat(' ');
  posi(2,3);wdat(1);posi(2,9);wdat(2);
  posi(2,6);wdat('.');  //小数点
  posi(2,12);wdat('.');  //小数点

  
  
}


void ds_lcd()//时间显示
{  
   uchar temph,templ;
   
   //显示年
   temph='0'+dsdat[6]/16;
   templ='0'+dsdat[6]%16;
   posi(1,2);
   wdat(temph);
   wdat(templ);
   
   //显示月
  
   posi(1,4);
   temph=0x30+dsdat[4]/16;
   templ=0x30+dsdat[4]%16;
   wdat(temph);
   wdat(templ);
   //显示日
   
   posi(1,6);
   temph=0x30+dsdat[3]/16;
   templ=0x30+dsdat[3]%16;
	 wdat(temph);
   wdat(templ);
   
   
    //显示时，24h的显示方式
   temph=0x30+dsdat[2]/16;
   templ=0x30+dsdat[2]%16;
   posi(1,9);
   if(temph==0x30+1) wdat(0x30+1);
   else if(temph==0x30+2) wdat(0x30+2);
   else wdat(' ');
   templ=0x30+dsdat[2]%16;
   wdat(templ);
   
   //显示分
   posi(1,12);
   temph=0x30+dsdat[1]/16;
   templ=0x30+dsdat[1]%16;
	 wdat(temph);
   wdat(templ);
   
   //显示秒
   posi(1,15);
   temph=0x30+dsdat[0]/16;
   templ=0x30+dsdat[0]%16;
   if(temph==0x30) ;
   else wdat(temph);
   wdat(templ);
   
} 


void ds_lcd02()//2模式符号显示
{
  uchar temph,templ;
	temph=temper_group/10;
	templ=temper_group%10;
  if(temper_group==1) temper_arrow=4;
	else if(temper_group==GROUP_MAX) temper_arrow=3;
	else temper_arrow=5;
  posi(1,1);
  wdat(' ');
  posi(1,8);wdat(' ');posi(1,11);wdat(':');posi(1,14);wdat(':');
  posi(2,1);wdat('G');
	wdat(0x30+temph);wdat(0x30+templ);
  posi(2,4);wdat(1);posi(2,10);wdat(2);
  posi(2,16);wdat(temper_arrow);//显示上下箭头
  posi(2,7);wdat('.');  //小数点
  posi(2,13);wdat('.');  //小数点

  
  
  
}


void ds_lcd_temper2()//显示存储的时间及温度
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
   posi(1,9);
   temp=0x30+temper_tim[temper_group][6];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][7];
   wdat(temp);
   //显示分
	 posi(1,12);
    temp=0x30+temper_tim[temper_group][8];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][9];
   wdat(temp);
   
   //显示秒
	 posi(1,15);
   temp=0x30+temper_tim[temper_group][10];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][11];
   wdat(temp);
 
	
	 //温度1数据  
	 posi(2,5);
	 temp=0x30+((temper_dat[temper_group][0])/1000)%10;
	 wdat(temp);
	 temp=0x30+((temper_dat[temper_group][0])/100)%10;
	 wdat(temp);
 	 posi(2,8);
	 temp=0x30+((temper_dat[temper_group][0])/10)%10;
	 wdat(temp);
	 temp=0x30+temper_dat[temper_group][0]%10;
	 wdat(temp);
	 
	 //温度2数据  
	 posi(2,11);
	 temp=0x30+((temper_dat[temper_group][1])/1000)%10;
	 wdat(temp);
	 temp=0x30+((temper_dat[temper_group][1])/100)%10;
	 wdat(temp);
	 posi(2,14);
	 temp=0x30+((temper_dat[temper_group][1])/10)%10;
	 wdat(temp);
	 temp=0x30+temper_dat[temper_group][1]%10;
	 wdat(temp);
	

}


void ds_lcd03()//模式3显示
{
	posi(1,1);wdat(' ');wdat(' ');wdat(' ');
	posi(1,4);wdat('M');wdat('A');wdat('X');
	wdat(' ');wdat(' ');wdat(' ');wdat(' ');
	posi(1,11);wdat('M');wdat('I');wdat('N');
	wdat(' ');wdat(' ');wdat(' ');wdat(' ');
	posi(2,5);wdat('.');posi(2,12);wdat('.');
	//显示最大值
	posi(2,1);wdat(' ');wdat(' ');
	posi(2,3);
	wdat(0x030+temper_limit[0][0]);
	wdat(0x030+temper_limit[0][1]);
	posi(2,6);
	wdat(0x030+temper_limit[0][2]);
	wdat(0x030+temper_limit[0][3]);
	posi(2,8);wdat(' ');wdat(' ');
	//显示最小值
	posi(2,10);
	wdat(0x030+temper_limit[1][0]);
	wdat(0x030+temper_limit[1][1]);
	posi(2,13);
	wdat(0x030+temper_limit[1][2]);
	wdat(0x030+temper_limit[1][3]);
	posi(2,15);wdat(' ');wdat(' ');
	
	
}