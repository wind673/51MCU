//红外

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
      while(inf==0&&a<1000){a++;}//等待9ms过去
	  a=0;
      while(inf==1&&a<500){a++;}//等待4.5ms的高电平过去
	  //ero[0]=1;//用来调试找错
	  for(n=0;n<4;n++)
	  {    
	     for(i=0;i<8;i++)
	 	{
		  a=0;
		  if(inf==1) return;//防止外部因素，使程序乱码
		  while(inf==0&&a<50){a++;}
	      tag=0;
	      //ero[1]=a;//用来调试找错
	      delay700us();//延迟至1.125mm后面，判断真值
		  temp<<=1;
		  if(inf==1) 
		  {
		  a=0;
		  while(inf==1&&a<200){a++;}//与0值同步至低电平
		   tag=1;
		  }
	  	temp=temp|tag;//赋值
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




