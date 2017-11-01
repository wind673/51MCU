//DS1302时钟模块


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

                                   /*
void ds_write_main()
{

  ds_write(0x8e,0x00);//关闭保护位，允许操作
  
  ds_write(0x80,0x00);//写秒
  ds_write(0x82,0x18);//写分
  ds_write(0x84,0x14);//写时
  ds_write(0x86,0x09);//写日
  ds_write(0x88,0x05);//写月
  ds_write(0x8a,0x06);//写星期
  ds_write(0x8c,0x15);//写年
  
  ds_write(0x8e,0x80);//打开保护位，禁止任何操作

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



