//����

sbit inf=P3^2;
//uchar sure=0;
//uchar ero[3]={0};



void inf_init()
{

 EX0=1;
 IT0=1;
 EA=1;
 inf=1;
  
}





void infrared() interrupt 0
{ 
   uchar i,n=0;
   uint a,temp,tag;
   if(inf==0)
   {
      a=0;
      while(inf==0&&a<1000){a++;}//�ȴ�9ms��ȥ
	  a=0;
      while(inf==1&&a<500){a++;}//�ȴ�4.5ms�ĸߵ�ƽ��ȥ
	  //ero[0]=1;//���������Ҵ�
	  for(n=0;n<4;n++)
	  {    
	     for(i=0;i<8;i++)
	 	{
		  a=0;
		  if(inf==1) return;//��ֹ�ⲿ���أ�ʹ��������
		  while(inf==0&&a<50){a++;}
	      tag=0;
	      //ero[1]=a;//���������Ҵ�
	      delay700us();//�ӳ���1.125mm���棬�ж���ֵ
		  temp<<=1;
		  if(inf==1) 
		  {
		  a=0;
		  while(inf==1&&a<200){a++;}//��0ֵͬ�����͵�ƽ
		   tag=1;
		  }
	  	temp=temp|tag;//��ֵ
	  	}
		inf_dat[n]=temp;
      }
		//ero[2]=1;
		
  }
   
  //sure=0;
  if(inf_dat[2]==~inf_dat[3])
  { //sure=1;
  inf_sure=inf_dat[2];
  }
  inf_function();
  
   
}




