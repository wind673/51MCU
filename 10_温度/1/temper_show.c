//����LCDģ����ʾ�¶Ⱥ�ʱ��




void ds_lcd_temper1()
{
	posi(2,4);wdat(0x30+temper1_h);wdat(0x30+temper1_l);
	posi(2,7);wdat(0x30+temper1_0h);wdat(0x30+temper1_0l);
	posi(2,10);wdat(0x30+temper2_h);wdat(0x30+temper2_l);
	posi(2,13);wdat(0x30+temper2_0h);wdat(0x30+temper2_0l);
	

}


void ds_lcd_temper2()
{	
	uint temp;
   //��ʾ��

	 posi(1,2);
	 temp=0x30+temper_tim[temper_group][0];
	 wdat(temp);
	 temp=0x30+temper_tim[temper_group][1];
	 wdat(temp);
   //��ʾ��
   temp=0x30+temper_tim[temper_group][2];
	 wdat(temp);
	 temp=0x30+temper_tim[temper_group][3];
	 wdat(temp);
     //��ʾ��
   temp=0x30+temper_tim[temper_group][4];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][5];
	 wdat(temp);
 //��ʾʱ��24h����ʾ��ʽ
   temp=0x30+temper_tim[temper_group][6];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][7];
   wdat(temp);
   //��ʾ��
    temp=0x30+temper_tim[temper_group][8];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][9];
   wdat(temp);
   
   //��ʾ��

   temp=0x30+temper_tim[temper_group][10];
   wdat(temp);
	 temp=0x30+temper_tim[temper_group][11];
   wdat(temp);
 
	
	 //�¶�1����  
	 posi(2,4);
	 wdat(0x30+temper_dat[temper_group][0][0]);
	 wdat(0x30+temper_dat[temper_group][0][1]);
 	 posi(2,7);
	 wdat(0x30+temper_dat[temper_group][0][2]);
	 wdat(0x30+temper_dat[temper_group][0][3]);
	 
	 //�¶�2����  
	 posi(2,10);
	 wdat(0x30+temper_dat[temper_group][1][0]);
	 wdat(0x30+temper_dat[temper_group][1][1]);
	 posi(2,13);
	 wdat(0x30+temper_dat[temper_group][1][2]);
	 wdat(0x30+temper_dat[temper_group][1][3]);
	

}


	
	
void ds_lcd01()//1ģʽ������ʾ
{
  posi(1,1);
  wdat(0);//��ʾ�ַ���
  posi(1,8);wdat(' ');posi(1,11);wdat(':');posi(1,14);wdat(':');
  posi(2,1);wdat(' ');wdat(' ');
  posi(2,3);wdat(1);posi(2,9);wdat(2);
  posi(2,16);wdat(' ');
  posi(2,4);            //�¶�1.0��ʾ
  posi(2,6);wdat('.');  //С����
  posi(2,7);            //�¶�0.1��ʾ
  
  posi(2,10);			//�¶�2.0��ʾ
  posi(2,12);wdat('.');  //С����
  posi(2,13);			//�¶�0.2��ʾ
  
  posi(2,15);wdat(' ');
  
  
}

void ds_lcd02()//2ģʽ������ʾ
{
 posi(1,1);
  wdat(' ');
  posi(1,8);wdat(' ');posi(1,11);wdat(':');posi(1,14);wdat(':');
  posi(2,1);wdat('G');wdat(0x30+temper_group);
  posi(2,3);wdat(1);posi(2,9);wdat(2);
  posi(2,16);wdat(3+temper_arrow);//��ʾ���¼�ͷ
  posi(2,4);            //�¶�1.0��ʾ
  posi(2,6);wdat('.');  //С����
  posi(2,7);            //�¶�0.1��ʾ
  
  posi(2,10);			//�¶�2.0��ʾ
  posi(2,12);wdat('.');  //С����
  posi(2,13);			//�¶�0.2��ʾ
  
  posi(2,15);wdat(' ');
  
  
  
}

