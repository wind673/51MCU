




void key_1()
{
//开关
		if(inf_tag==1) return;//用来防止多次写入
    if(key1!=0) return;
		delay10ms();//消抖
		if(key1!=0) return;
		
   	if(inf_sw==0) inf_sw=2;
   	if(inf_sw==1) inf_sw=0;
   	if(inf_sw==0) {wdir(0x08);}
   	if(inf_sw==2){ wdir(0x0c); inf_sw=1;}
	 	
	  inf_tag=1;delay300ms();
}

void key_2()
{
//上
		uchar i,j;
		if(inf_tag==1) return;//用来防止多次写入
		
    if(key2!=0) return;
		delay10ms();//消抖
		if(key2!=0) return;
		
		if(temper_mode==2)
		{
	 	temper_group--;
	 	if(temper_group<1) temper_group=1;
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
		inf_tag=1;delay300ms();
}

void key_3()
{
//模式选择
    if(inf_tag==1) return;//用来防止多次写入
    if(key3!=0) return;
		delay10ms();//消抖
		if(key3!=0) return;
	 	temper_mode++;
	 	temper_posi=3;//复位选项的位置
	 	wdir(0x01);//换模式之前清屏
	 	if(temper_mode==4) temper_mode=1,inf_vo=0;//共3项功能
    inf_tag=1;delay300ms();
}


void key_4()
{
//关闭警报
    if(inf_tag==1) return;//用来防止多次写入
    if(key4!=0) return;
		delay10ms();//消抖
		if(key4!=0) return;		
		warn_sw1=0;
		warn_sw2=0;
		inf_vo=(inf_vo+1)%2;
		inf_tag=1;delay300ms();
}

void key_5()
{
//左
    if(inf_tag==1) return;//用来防止多次写入
    if(key5!=0) return;
		delay10ms();//消抖
		if(key5!=0) return;
	
		if(temper_mode==3)
		{
		if(temper_posi==4||temper_posi==7||temper_posi==11||temper_posi==14)
		temper_posi--;

		else if(temper_posi==6||temper_posi==13)	temper_posi-=2;
	
		else if(temper_posi==10)	temper_posi=7;
		else if (temper_posi==3)	temper_posi=14;
		else;
  	}
		inf_tag=1;delay300ms();
}

void key_6()
{
//下
    uchar i,j;
    if(inf_tag==1) return;//用来防止多次写入
		
    if(key6!=0) return;
		delay10ms();//消抖
		if(key6!=0) return;
		
		
		if(temper_mode==2)
		{
	 temper_group++;
	 if(temper_group>12) temper_group=12;
		}
	
	
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
		inf_tag=1;
		delay300ms();
}

void key_7()
{
//右
    if(inf_tag==1) return;//用来防止多次写入
    if(key7!=0) return;
		delay10ms();//消抖
		if(key7!=0) return;
		
		if(temper_mode==3)
		{
		if(temper_posi==3||temper_posi==6||temper_posi==10||temper_posi==13)
		temper_posi++;
		else if(temper_posi==4||temper_posi==11)	temper_posi+=2;
	
		else if(temper_posi==7)	temper_posi=10;
		else if (temper_posi==14)	temper_posi=3;
		else;
		}
		inf_tag=1;delay300ms();
}

void key_8()
{
//存储数据
    if(inf_tag==1) return;//用来防止多次写入
    if(key8!=0) return;
		delay10ms();//消抖
		
		if(key8!=0) return;
		
		temper_save(temper_star);
		if(temper_star<12) temper_star++;
		inf_tag=1;delay300ms();
		delay300ms();
}






void key_board()
{
  if(P0!=0xff) 
	{
	key_1();key_2();key_3();key_4();
	key_5();key_6();key_7();key_8();
	}
	
	

}
