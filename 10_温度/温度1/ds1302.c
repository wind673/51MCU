//DS1302ʱ��ģ��


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

                                   /*
void ds_write_main()
{

  ds_write(0x8e,0x00);//�رձ���λ���������
  
  ds_write(0x80,0x00);//д��
  ds_write(0x82,0x18);//д��
  ds_write(0x84,0x14);//дʱ
  ds_write(0x86,0x09);//д��
  ds_write(0x88,0x05);//д��
  ds_write(0x8a,0x06);//д����
  ds_write(0x8c,0x15);//д��
  
  ds_write(0x8e,0x80);//�򿪱���λ����ֹ�κβ���

}

                                   */

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



