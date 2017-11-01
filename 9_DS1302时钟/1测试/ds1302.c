//DS1302时钟模块


sbit ds_io=P3^4;
sbit ds_ce=P3^5;
sbit ds_sclk=P3^6;

uchar dsdat[7]={0};





 




void ds_write(uchar ds_dir,uchar ds_dat)
{
  uchar i,ds_bit;
  
  ds_ce=0;//初始化CE
  ds_sclk=0;//拉低SCLK为上升沿做准备
  ds_ce=1;//拉高CE 准备写入数据
 
    ds_bit=0x01;
    for(i=0;i<8;i++)//传输命令
  	{
	
	 ds_io=ds_dir&ds_bit;
	 ds_sclk=1;//拉高SCLK，存入数据
     ds_bit<<=1;//选位，顺便让1302稍微延时一下，防止掉数据
	 ds_sclk=0;//为下次存入做准备
  	}
	
	
	ds_bit=0x01;
    for(i=0;i<8;i++)//传输数据
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
	ds_io=1;//打开侦测io口
	ds_bit=0;
    for(i=0;i<8;i++)
  	{
	 ds_bit=0x00;
	 ds_sclk=0;//制造下降沿 
	 if(ds_io==1) ds_bit=0x80;
	 ds_rdat=ds_rdat|ds_bit; 
	 ds_sclk=1;
	 if(i<7) ds_rdat>>=1;//右移7次
  	}
	ds_io=0;//关闭侦测io口，停止接收数据
	return ds_rdat;
  
}


void ds_write_main()
{

  ds_write(0x8e,0x00);//关闭保护位，允许操作
  
  ds_write(0x80,0x30);//写秒
  ds_write(0x82,0x50);//写分
  ds_write(0x84,0x10);//写时
  ds_write(0x86,0x29);//写日
  ds_write(0x88,0x03);//写月
  ds_write(0x8a,0x07);//写星期
  ds_write(0x8c,0x15);//写年
  
  ds_write(0x8e,0x80);//打开保护位，禁止任何操作

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

//调用LCD模块

void ds_lcd01()//年月日符号显示
{
  posi(1,7);
  wdat('D');wdat('A');wdat('T');wdat('E');
  posi(2,6);
  wdat(0);//年
  posi(2,9);
  wdat(1);//月
  posi(2,12);
  wdat(2);//日
}

void ds_lcd02()//时间符号显示
{
  posi(1,7);
  wdat('T');wdat('I');wdat('M');wdat('E');
  posi(2,7);
  wdat(':');
  posi(2,10);
  wdat(':');
  posi(2,13);
 
  
}

void ds_lcd1()//时间显示
{  
   uchar temph,templ;
   
   //显示年
   temph='0'+dsdat[6]/16;
   templ='0'+dsdat[6]%16;
   posi(2,2);
   wdat(0x30+2);
   wdat(0x30+0);
   wdat(temph);
   wdat(templ);
   
   //显示月
  
   posi(2,7);
   temph=0x30+dsdat[4]/16;
   templ=0x30+dsdat[4]%16;
   if(temph==0x31) wdat(0x30+1);
   else wdat(' ');
   wdat(templ);
   //显示日
   
   posi(2,10);
   temph=0x30+dsdat[3]/16;
   templ=0x30+dsdat[3]%16;
   if(temph==0x30) wdat(' ');
   else wdat(temph);
   wdat(templ);
   
   //显示周
   posi(2,15);
   templ=0x30+dsdat[5]%16;
   wdat(templ);
   
   
} 

void ds_lcd2()//时间显示
{  
   uchar temph,templ;
   
   //显示时，24h的显示方式
   temph=0x30+dsdat[2]/16;
   templ=0x30+dsdat[2]%16;
   posi(2,5);
   if(temph==0x30+1) wdat(0x30+1);
   else if(temph==0x30+2) wdat(0x30+2);
   else wdat(' ');
   templ=0x30+dsdat[2]%16;
   wdat(templ);
   
   //显示分
   posi(2,8);
   temph=0x30+dsdat[1]/16;
   templ=0x30+dsdat[1]%16;
   if(temph==0x30) wdat(' ');
   else wdat(temph);
   wdat(templ);
   
   //显示秒
   posi(2,11);
   temph=0x30+dsdat[0]/16;
   templ=0x30+dsdat[0]%16;
   if(temph==0x30) ;
   else wdat(temph);
   wdat(templ);
   
   
   
} 

