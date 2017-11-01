//红外遥控



	void inf_star()
{
		if(warn_sw1==0&&warn_sw2==0)temper_alarm(1);//不处于警告状态则存储时发出声音信号
		if(inf_tag==1) return;//用来防止多次写入
		
		temper_save(temper_star);
		if(temper_star<12) temper_star++;
		inf_tag=1;    //表示程序已进
	  delay100ms();
		
}


void inf_switch()
{
    
   if(inf_tag==1) return;//用来防止多次写入
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   if(inf_sw==0) {wdir(0x08);}
   if(inf_sw==2){ wdir(0x0c); inf_sw=1;}
	 inf_tag=1;//表示程序已进
	 delay300ms();  
}

void inf_mode()
{
   
   if(inf_tag==1) return;//用来防止多次写入
	 temper_mode++;
	 temper_posi=3;//复位选项的位置
	 wdir(0x01);//换模式之前清屏
	 if(temper_mode==4) temper_mode=1;//共3项功能
   inf_tag=1;    //表示程序已进
	 delay300ms();  
	 
}


void inf_left()
{
	if(inf_tag==1) return;//用来防止多次写入
	
	if(temper_mode==3)
	{
	if(temper_posi==4||temper_posi==7||temper_posi==11||temper_posi==14)
	temper_posi--;

	else if(temper_posi==6||temper_posi==13)	temper_posi-=2;
	
	else if(temper_posi==10)	temper_posi=7;
	else if (temper_posi==3)	temper_posi=14;
	else;
  }
		inf_tag=1;    //表示程序已进
  delay100ms(); 
}



void inf_right()
{
	if(inf_tag==1) return;//用来防止多次写入
	
	if(temper_mode==2)
	{
	 temper_group--;
	 if(temper_group<1) temper_group=1;
	}
	
	if(temper_mode==3)
	{
	if(temper_posi==3||temper_posi==6||temper_posi==10||temper_posi==13)
	temper_posi++;
	else if(temper_posi==4||temper_posi==11)	temper_posi+=2;
	
	else if(temper_posi==7)	temper_posi=10;
	else if (temper_posi==14)	temper_posi=3;
	else;
	}
	
	
	inf_tag=1;    //表示程序已进
	delay100ms();
}



void inf_up()
{
  uchar i,j;
	if(inf_tag==1) return;//用来防止多次写入
	
	if(temper_mode==2)
	{
	 temper_group++;
	 if(temper_group>12) temper_group=12;
	}
	
	if(temper_mode==3) 
	{
	  if(temper_posi==3) temper_limit[0][0]++;
		if(temper_posi==4) temper_limit[0][1]++;
		if(temper_posi==6) temper_limit[0][2]++;
		if(temper_posi==7) temper_limit[0][3]++;
		if(temper_posi==10) temper_limit[1][0]++;
		if(temper_posi==11) temper_limit[1][1]++;
		if(temper_posi==13) temper_limit[1][2]++;
		if(temper_posi==14) temper_limit[1][3]++;
		for(i=0;i<2;i++)
		for(j=0;j<4;j++)
		if(temper_limit[i][j]>9)
		temper_limit[i][j]=0;
	
	}
	inf_tag=1;
	 
	delay100ms();
	
	
	 
}

void inf_down()
{
  uchar i,j;
	if(inf_tag==1) return;//用来防止多次写入
	if(temper_mode==3) 
	{
	  if(temper_posi==3) temper_limit[0][0]--;
		if(temper_posi==4) temper_limit[0][1]--;
		if(temper_posi==6) temper_limit[0][2]--;
		if(temper_posi==7) temper_limit[0][3]--;
		if(temper_posi==10) temper_limit[1][0]--;
		if(temper_posi==11) temper_limit[1][1]--;
		if(temper_posi==13) temper_limit[1][2]--;
		if(temper_posi==14) temper_limit[1][3]--;
		
		for(i=0;i<2;i++)
		for(j=0;j<4;j++)
		if(temper_limit[i][j]<0)
		temper_limit[i][j]=9;
		delay100ms();
	}
	

	
	
	inf_tag=1;    //表示程序已进
}







void inf_voice()
{
		
		if(inf_tag==1) return;//用来防止多次写入
		inf_vo=(inf_vo+1)%2;
		if(inf_vo==0)
		{
		
		temper_alarm(1);temper_alarm(1);
		}
		
		if(inf_vo==1)
		{
		light1_red=0;light2_red=0;
		temper_alarm(7);
		}
		
		inf_tag=1;    //表示程序已进
	  delay300ms();
}

void inf_first()
{
	if(inf_tag==1) return;//用来防止多次写入
		
	temper_group=1;//跳入第一组数据
	
	inf_tag=1;//表示程序已进
	delay300ms();
	
}


void inf_last()
{
	if(inf_tag==1) return;//用来防止多次写入
		
	temper_group=GROUP_MAX;//跳入最后一组数据
	
	inf_tag=1;//表示程序已进
	delay300ms();
	
}



void inf_function()
{
	  if(inf_sure==0xa2) inf_switch();//显示屏开关
    if(inf_sure==0x62) inf_mode();//模式选择
		if(inf_sure==0x02) inf_left();//以下是上下左右键
		if(inf_sure==0xc2) inf_right();//
		if(inf_sure==0x90) inf_up();//
		if(inf_sure==0xa8) inf_down();//
		if(inf_sure==0x22) inf_star();//记录数据
		if(inf_sure==0xe2) inf_voice();//自动报警开关
		if(inf_sure==0x98) inf_first();//跳到第一组数据
		if(inf_sure==0xb0) inf_last();//跳到最后一组数据
		
}
