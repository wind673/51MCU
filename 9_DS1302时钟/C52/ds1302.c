//DS1302ʱ��ģ��


sbit ds_io=P3^4;
sbit ds_ce=P3^5;
sbit ds_sclk=P3^6;

uchar dsdat[7]={0};





 




void ds_write(uchar ds_dir,uchar ds_dat)
{
  uchar i,ds_bit;
  
  ds_ce=0;//��ʼ��CE
  ds_sclk=0;//����SCLKΪ��������׼��
  ds_ce=1;//����CE ׼��д������
 
    ds_bit=0x01;
    for(i=0;i<8;i++)//��������
  	{
	
	 ds_io=ds_dir&ds_bit;
	 ds_sclk=1;//����SCLK����������
     ds_bit<<=1;//ѡλ��˳����1302��΢��ʱһ�£���ֹ������
	 ds_sclk=0;//Ϊ�´δ�����׼��
  	}
	
	
	ds_bit=0x01;
    for(i=0;i<8;i++)//��������
  	{
	 ds_io=ds_dat&ds_bit;
	 ds_bit<<=1;
 	 ds_sclk=1;
	 ds_sclk=0;
  	}
	 
  

}



unsigned char ds_read(uchar ds_address)
{
  	uchar i,ds_bit,ds_rdat=0;
    ds_ce=0;
 	ds_sclk=0;
  	ds_ce=1;
	ds_bit=0x01;
    for(i=0;i<8;i++)
  	{
	 ds_sclk=0;
	 ds_io=ds_address&ds_bit;
	 ds_sclk=1;
     ds_bit<<=1;
  	}
	ds_io=1;//�����io��
	ds_bit=0;
    for(i=0;i<8;i++)
  	{
	 ds_bit=0x00;
	 ds_sclk=0;//�����½��� 
	 if(ds_io==1) ds_bit=0x80;
	 ds_rdat=ds_rdat|ds_bit; 
	 ds_sclk=1;
	 if(i<7) ds_rdat>>=1;//����7��
  	}
	ds_io=0;//�ر����io�ڣ�ֹͣ��������
	return ds_rdat;
  
}


void ds_write_main()
{

  ds_write(0x8e,0x00);//�رձ���λ���������
  
  ds_write(0x80,0x30);//д��
  ds_write(0x82,0x50);//д��
  ds_write(0x84,0x10);//дʱ
  ds_write(0x86,0x29);//д��
  ds_write(0x88,0x03);//д��
  ds_write(0x8a,0x07);//д����
  ds_write(0x8c,0x15);//д��
  
  ds_write(0x8e,0x80);//�򿪱���λ����ֹ�κβ���

}


void ds_read_main()
{

  uchar i,temp=0x81;
  ds_write(0x8e,0x00);
  for(i=0;i<7;i++)
  {
  dsdat[i]=ds_read(temp);
  temp+=2;
  }
  ds_write(0x8e,0x80);
}

//����LCDģ��

void ds_lcd01()//�����շ�����ʾ
{
  posi(1,7);
  wdat('D');wdat('A');wdat('T');wdat('E');
  posi(2,6);
  wdat(0);//��
  posi(2,9);
  wdat(1);//��
  posi(2,12);
  wdat(2);//��
}

void ds_lcd02()//ʱ�������ʾ
{
  posi(1,7);
  wdat('T');wdat('I');wdat('M');wdat('E');
  posi(2,7);
  wdat(':');
  posi(2,10);
  wdat(':');
  posi(2,13);
 
  
}

void ds_lcd1()//ʱ����ʾ
{  
   uchar temph,templ;
   
   //��ʾ��
   temph='0'+dsdat[6]/16;
   templ='0'+dsdat[6]%16;
   posi(2,2);
   wdat(0x30+2);
   wdat(0x30+0);
   wdat(temph);
   wdat(templ);
   
   //��ʾ��
  
   posi(2,7);
   temph=0x30+dsdat[4]/16;
   templ=0x30+dsdat[4]%16;
   if(temph==0x31) wdat(0x30+1);
   else wdat(' ');
   wdat(templ);
   //��ʾ��
   
   posi(2,10);
   temph=0x30+dsdat[3]/16;
   templ=0x30+dsdat[3]%16;
   if(temph==0x30) wdat(' ');
   else wdat(temph);
   wdat(templ);
   
   //��ʾ��
   posi(2,15);
   templ=0x30+dsdat[5]%16;
   wdat(templ);
   
   
} 

void ds_lcd2()//ʱ����ʾ
{  
   uchar temph,templ;
   
   //��ʾʱ��24h����ʾ��ʽ
   temph=0x30+dsdat[2]/16;
   templ=0x30+dsdat[2]%16;
   posi(2,5);
   if(temph==0x30+1) wdat(0x30+1);
   else if(temph==0x30+2) wdat(0x30+2);
   else wdat(' ');
   templ=0x30+dsdat[2]%16;
   wdat(templ);
   
   //��ʾ��
   posi(2,8);
   temph=0x30+dsdat[1]/16;
   templ=0x30+dsdat[1]%16;
   if(temph==0x30) wdat(' ');
   else wdat(temph);
   wdat(templ);
   
   //��ʾ��
   posi(2,11);
   temph=0x30+dsdat[0]/16;
   templ=0x30+dsdat[0]%16;
   if(temph==0x30) ;
   else wdat(temph);
   wdat(templ);
   
   
   
} 

