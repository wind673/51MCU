//红外遥控

void temper_save(uchar gr)
{
		uchar i,j;
		
	if(gr==12)//若超范围，则舍弃第一组数据
	{
		for(i=1;i<GROUP_MAX;i++)
		{
	 	temper_dat[i][0]=temper_dat[i+1][0];
	 	temper_dat[i][1]=temper_dat[i+1][1];
	 	for(j=0;j<12;j++) temper_tim[i][j]=temper_tim[i+1][j];
		}
	}
	
	
//以四位整数存储温度数据
	temper_dat[gr][0]=temper1_h*1000+temper1_l*100+temper1_0h*10+temper1_0l;
	temper_dat[gr][1]=temper2_h*1000+temper2_l*100+temper2_0h*10+temper2_0l;
//存储时间
	temper_tim[gr][0]=dsdat[6]/16;	temper_tim[gr][1]=dsdat[6]%16;
	temper_tim[gr][2]=dsdat[4]/16;	temper_tim[gr][3]=dsdat[4]%16;
	temper_tim[gr][4]=dsdat[3]/16;	temper_tim[gr][5]=dsdat[3]%16;
	temper_tim[gr][6]=dsdat[2]/16;	temper_tim[gr][7]=dsdat[2]%16;
	temper_tim[gr][8]=dsdat[1]/16;	temper_tim[gr][9]=dsdat[1]%16;
	temper_tim[gr][10]=dsdat[0]/16; temper_tim[gr][11]=dsdat[0]%16;
	

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
	 if(temper_mode==4) temper_mode=1,inf_vo=0;//共3项功能
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
	
	 
	
	
	inf_tag=1;    //表示程序已进
	delay300ms();  
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
		
	}
	

	
	
	inf_tag=1;    //表示程序已进
	delay300ms();  
}


void inf_star()
{
		
		if(inf_tag==1) return;//用来防止多次写入
		
		temper_save(temper_star);
		if(temper_star<12) temper_star++;
		inf_tag=1;    //表示程序已进
	  delay300ms();
}




void inf_voice()
{
		
		if(inf_tag==1) return;//用来防止多次写入
		
		warn_sw1=0;
		warn_sw2=0;
		inf_vo=(inf_vo+1)%2;
		inf_tag=1;    //表示程序已进
	  delay300ms();
}

void inf_function()
{
	  if(inf_sure==0xa2) inf_switch();
    if(inf_sure==0x62) inf_mode();
		if(inf_sure==0x02) inf_left();
		if(inf_sure==0xc2) inf_right();
		if(inf_sure==0x90) inf_up();
		if(inf_sure==0xa8) inf_down();
		if(inf_sure==0x22) inf_star();
		if(inf_sure==0xe2) inf_voice();
}
