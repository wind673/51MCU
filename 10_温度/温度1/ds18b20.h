/***��ʼ������*********/
uchar  ds18b20_init()
{
	uchar i=0;

	triffic=0;			 //����������480us~960us
	delay700us();
	triffic=1;			//Ȼ���������ߣ����DS18B20������Ӧ�Ὣ��15us~60us����������

	while(triffic)	//�ȴ�DS18B20��������
	{
		delay1ms();
		i++;
		if(i>5)return 0;//�ȴ�>5MS
	}
	return 1;//��ʼ���ɹ� 
}

/***ds18b20дָ���****/
	 	 
void writecom(uchar z)
{
 	uchar i=0,k=0;

	while(k<8)
	{	
		triffic=0;
		i++;
		triffic=z&0x01;	 //������������
		delay60us();		//��ʱ60΢��IO�ڲɼ�����
		triffic=1;		//Ϊ�´���������׼��
		z=z>>1;
		k++;
	}
}

/*****ds18b20��ȡ�ݴ����еĲ���ֵ�ĺ���*****/
	   
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

/****ds18b20ת���¶�1����******/ 
	
void change_1()
{
	uchar i=0;

	ds18b20_init();	
	writecom(0x55);		//ds18b20ƥ��1
	for(i=0;i<8;i++)
		{
			writecom(xu_1[i]);
		}
				 
	writecom(0x44);	  //�����¶�ת��1
	delay100ms();
}

/****ds18b20ת���¶�2����*************/
	   
void change_2()
{
	uchar i=0;

	ds18b20_init();	
	writecom(0x55);		//ds18b20ƥ��2
	for(i=0;i<8;i++)
		{
			writecom(xu_2[i]);
		}
				 
	writecom(0x44);		   //�����¶�ת��2
	delay100ms();	   
}

/********ds18b20��ȡ�¶Ⱥ���******/
 	
void readtemp()
{
	uchar i=0;
	int temp=0,tl=0,th=0;

/********���¶�1*************/

	change_1();	
	ds18b20_init();						   
	delay1ms();

	writecom(0x55);		//ds18b20ƥ��1
	for(i=0;i<8;i++)
		{
			writecom(xu_1[i]);
		}
		 
	writecom(0xbe);  //���ݴ���ָ��
	tl=readbyte();
	th=readbyte();

	temp=temp|th;
	temp=temp<<8;
	temp=temp|tl;

	temp1=temp;			  //�����¶�1
	tl=0;th=0;

/*****���¶�2*********/
		  
	change_2();
	ds18b20_init();
	delay1ms();

	writecom(0x55);		//ds18b20ƥ��2
	for(i=0;i<8;i++)
		{
			writecom(xu_2[i]);
		}
				 						   
	writecom(0xbe);  //���ݴ���ָ��
	tl=readbyte();
	th=readbyte();
	temp=0;

	temp=temp|th;
	temp=temp<<8;
	temp=temp|tl;

	temp2=temp;	  	 //�����¶�2
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