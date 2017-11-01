
/**延时函数*/			 
 void delay(uint z)
 {
 	uint x=0,y=0;
	for(x=z;x>0;x--)
	  for(y=110;y>0;y--);
 }
/****微秒级延时函数;*****
******延时时间为：t=15(n+1)****/
 void delayus(uint n)			
{
	for(n;n>0;n--)
	{
		_nop_();_nop_();_nop_();_nop_();//_nop_()是延时一个机器周期的意思
	}
	_nop_();
	_nop_();
}   
 /***初始化函数*********/    
uchar  init()
{
	uchar i=0;
	triffic=0;			 //将总线拉低480us~960us
	delayus(45);
	triffic=1;			//然后拉高总线，如果DS18B20做出反应会将在15us~60us后总线拉低
	while(triffic)	//等待DS18B20拉低总线
	{
		delay(1);
		i++;
		if(i>5)//等待>5MS
		{
			return 0;//初始化失败
		}	
	}
	return 1;//初始化成功 
}
/***写指令函数****/	 	 
void writecom(uchar z)
{
 	uchar i=0,k=0;
	while(k<8)
	{	
		triffic=0;
		i++;
		triffic=z&0x01;	 //向总线送数据
		delayus(5);		//延时60微秒IO口采集数据
		triffic=1;		//为下次送数据做准备
		z=z>>1;
		k++;
	}
}
/*****读取暂存器中的补码值的函数*****/	   
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
/****温度转换函数******/ 	
void change()
{
	init();	
	writecom(0xcc);		//跳过ROM操作命		 
	writecom(0x44);
	delay(100);	   
}
/********读取温度函数******/ 	
float readtemp()
{
	int temp=0,tl=0,th=0;
	change();
	init();						   
	writecom(0xcc);
	delay(1);
	writecom(0xbe);  //读暂存器指令
	tl=readbyte();
	th=readbyte();
	temp=temp|th;
	temp=temp<<8;
	temp=temp|tl;
	return (float)temp;	  //强制类型转换只是将只传给中间变量
}

/*******接受温度数据函数并显示温度/***/
void catch_display()
{
	float temp=0; 
	int tp;
	
		tp=(int)readtemp();		
		if(tp<0)
		{		 	
			temp=(float)(~tp+1);	
			temp=temp*0.0625;
			 fu=0x40;
			 bai = (int)temp%100%10%1;
	  		shi =(int)temp % 100 / 10;
	  		ge =(int)temp % 100 % 10/1; 
		}
		else
		{
			temp=(float)tp;
			temp=temp*0.0625;
			fu=0;
			bai = temp / 100;
	  		shi = (int)temp % 100 / 10;
	  		ge = (int)temp % 10 / 1; 
		}
	
}
 



