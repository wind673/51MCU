
/**��ʱ����*/			 
 void delay(uint z)
 {
 	uint x=0,y=0;
	for(x=z;x>0;x--)
	  for(y=110;y>0;y--);
 }
/****΢�뼶��ʱ����;*****
******��ʱʱ��Ϊ��t=15(n+1)****/
 void delayus(uint n)			
{
	for(n;n>0;n--)
	{
		_nop_();_nop_();_nop_();_nop_();//_nop_()����ʱһ���������ڵ���˼
	}
	_nop_();
	_nop_();
}   
 /***��ʼ������*********/    
uchar  init()
{
	uchar i=0;
	triffic=0;			 //����������480us~960us
	delayus(45);
	triffic=1;			//Ȼ���������ߣ����DS18B20������Ӧ�Ὣ��15us~60us����������
	while(triffic)	//�ȴ�DS18B20��������
	{
		delay(1);
		i++;
		if(i>5)//�ȴ�>5MS
		{
			return 0;//��ʼ��ʧ��
		}	
	}
	return 1;//��ʼ���ɹ� 
}
/***дָ���****/	 	 
void writecom(uchar z)
{
 	uchar i=0,k=0;
	while(k<8)
	{	
		triffic=0;
		i++;
		triffic=z&0x01;	 //������������
		delayus(5);		//��ʱ60΢��IO�ڲɼ�����
		triffic=1;		//Ϊ�´���������׼��
		z=z>>1;
		k++;
	}
}
/*****��ȡ�ݴ����еĲ���ֵ�ĺ���*****/	   
uchar readbyte()
{	
	uchar temp=0,lei=0;
	uint i=0,k=1;
	for(k=8;k>0;k--)
	{	 
		triffic=0;
		i++;		//�ȶ�����
		triffic=1;	 
		i++;
		i++;		   //  ��ʱ8us
		lei=triffic;	//��������
		temp=(temp>>1)|(lei<<7);
		i = 4;		//��ȡ��֮��ȴ�48us�ٽ��Ŷ�ȡ��һ����
		while(i--);		
	}
	return temp;
}
/****�¶�ת������******/ 	
void change()
{
	init();	
	writecom(0xcc);		//����ROM������		 
	writecom(0x44);
	delay(100);	   
}
/********��ȡ�¶Ⱥ���******/ 	
float readtemp()
{
	int temp=0,tl=0,th=0;
	change();
	init();						   
	writecom(0xcc);
	delay(1);
	writecom(0xbe);  //���ݴ���ָ��
	tl=readbyte();
	th=readbyte();
	temp=temp|th;
	temp=temp<<8;
	temp=temp|tl;
	return (float)temp;	  //ǿ������ת��ֻ�ǽ�ֻ�����м����
}

/*******�����¶����ݺ�������ʾ�¶�/***/
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
 



