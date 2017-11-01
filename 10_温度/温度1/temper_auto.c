
void temper_auto()
{
  if(inf_vo==1) return;//手动模式；
	if(warn_sw1==1||warn_sw2==1)//警报时自动记录
	{
		if(temper1_h>7&&start_error1==0) return;//舍弃开机时的不稳定数据
		if(temper2_h>7&&start_error2==0) return;
		
		if(temper_auto_n==0)
		inf_star();
		temper_auto_n++;
	}
	
	if(warn_sw1==0&&warn_sw2==0)	temper_auto_n=0;//防止多次记录同一组数据
	if((dsdat[0]%16)%4==0)	temper_auto_n=0;//每4秒记录一次
	
	if(((dsdat[0]/16)%2==0)&&((dsdat[0]%16)%10==0))//每20秒自动记录一次
	{ 
	if(temper_auto_x==0)//防止多次记录同一组数据
	{temper_auto_x++;inf_star();}
	}
	if((dsdat[1]/16)%2>0) temper_auto_x=0;
	
}


void error_start()//避开  开机时数据不稳定造成的影响
{
	 if((temper1_0l!=0||temper1_0h!=0)&&start_error1==0)start_error1++;
	 if((temper2_0l!=0||temper2_0h!=0)&&start_error2==0)start_error2++;
	 
	 if(temper1_h>7&&start_error1==0)
	 {temper1_h=2;temper1_l=5;}
	 if(temper2_h>7&&start_error2==0)
	 {temper2_h=2;temper2_l=5;}
	 
}

void temper_save(uchar gr)//数据存储
{
		uchar i,j;
		
	if(gr==12)//若超范围，则舍弃第一组数据
	{
		for(i=1;i<GROUP_MAX;i++)
		{
	 	temper_dat[i][0]=temper_dat[i+1][0];
	 	temper_dat[i][1]=temper_dat[i+1][1];
	 	for(j=0;j<12;j++) 
		temper_tim[i][j]=temper_tim[i+1][j];
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
