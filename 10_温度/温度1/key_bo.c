void key_8()
{
//关闭警报
		delay10ms();//消抖
		if(key8!=0) return;		
		inf_vo=(inf_vo+1)%2;
		light1_red=0;light2_red=0;//红灯亮起 表示未在监控状态
		if(inf_vo==0){temper_alarm(1);temper_alarm(1);}
		if(inf_vo==1)	{light1_red=0;light2_red=0;temper_alarm(7);	}
		delay300ms();
}


void key_board()
{
    key_8();
}
