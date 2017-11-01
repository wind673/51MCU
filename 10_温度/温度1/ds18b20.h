/***初始化函数*********/
uchar  ds18b20_init()
{
	uchar i=0;

	triffic=0;			 //将总线拉低480us~960us
	delay700us();
	triffic=1;			//然后拉高总线，如果DS18B20做出反应会将在15us~60us后总线拉低

	while(triffic)	//等待DS18B20拉低总线
	{
		delay1ms();
		i++;
		if(i>5)return 0;//等待>5MS
	}
	return 1;//初始化成功 
}

/***ds18b20写指令函数****/
	 	 
void writecom(uchar z)
{
 	uchar i=0,k=0;

	while(k<8)
	{	
		triffic=0;
		i++;
		triffic=z&0x01;	 //向总线送数据
		delay60us();		//延时60微秒IO口采集数据
		triffic=1;		//为下次送数据做准备
		z=z>>1;
		k++;
	}
}

/*****ds18b20读取暂存器中的补码值的函数*****/
	   
uchar readbyte()
{	
	uchar temp=0,lei=0;
	uint i=0,k=1;

	for(k=8;k>0;k--)
	{	 
		triffic=0;
		i++;		//稳定数据
		triffic=1;	 
		i++;
		i++;		   //  延时8us
		lei=triffic;	//接收数据
		temp=(temp>>1)|(lei<<7);
		i = 4;		//读取完之后等待48us再接着读取下一个数
		while(i--);		
	}

	return temp;
}

/****ds18b20转换温度1函数******/ 
	
void change_1()
{
	uchar i=0;

	ds18b20_init();	
	writecom(0x55);		//ds18b20匹配1
	for(i=0;i<8;i++)
		{
			writecom(xu_1[i]);
		}
				 
	writecom(0x44);	  //开启温度转化1
	delay100ms();
}

/****ds18b20转化温度2函数*************/
	   
void change_2()
{
	uchar i=0;

	ds18b20_init();	
	writecom(0x55);		//ds18b20匹配2
	for(i=0;i<8;i++)
		{
			writecom(xu_2[i]);
		}
				 
	writecom(0x44);		   //开启温度转化2
	delay100ms();	   
}

/********ds18b20读取温度函数******/
 	
void readtemp()
{
	uchar i=0;
	int temp=0,tl=0,th=0;

/********读温度1*************/

	change_1();	
	ds18b20_init();						   
	delay1ms();

	writecom(0x55);		//ds18b20匹配1
	for(i=0;i<8;i++)
		{
			writecom(xu_1[i]);
		}
		 
	writecom(0xbe);  //读暂存器指令
	tl=readbyte();
	th=readbyte();

	temp=temp|th;
	temp=temp<<8;
	temp=temp|tl;

	temp1=temp;			  //捕获温度1
	tl=0;th=0;

/*****读温度2*********/
		  
	change_2();
	ds18b20_init();
	delay1ms();

	writecom(0x55);		//ds18b20匹配2
	for(i=0;i<8;i++)
		{
			writecom(xu_2[i]);
		}
				 						   
	writecom(0xbe);  //读暂存器指令
	tl=readbyte();
	th=readbyte();
	temp=0;

	temp=temp|th;
	temp=temp<<8;
	temp=temp|tl;

	temp2=temp;	  	 //捕获温度2
}


void catch_temp1()
{

	uint tp=0;
	tp=temp1; 		
	temp1=temp1>>4;

	tp=tp<<12;
	tp=tp>>12;
	tp=tp*625;
	//temp1--;
	xi_1=(tp/1000)%10;
	xi_2=(tp/100)%10;
	hundred1=(temp1/100)%10;
	shi = (temp1/10)%10;
	ge = temp1%10;

}

void catch_temp2()
{
	
	uint tp=0;
	tp=temp2; 		
	temp2=temp2>>4;

	tp=tp<<12;
	tp=tp>>12;
	tp=tp*625;
	//temp2++;
	x_1=(tp/1000)%10;
	x_2=(tp/100)%10;
	hundred2=(temp2/100)%10;
	sh=(temp2/10)%10;
	g=temp2%10;
  

				 
} 